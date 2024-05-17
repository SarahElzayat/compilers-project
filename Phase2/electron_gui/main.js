const { app, BrowserWindow, ipcMain } = require("electron");
const path = require("path");
const { exec } = require("child_process");
const fs = require("fs");

function createWindow() {
  const win = new BrowserWindow({
    icon: "./logo.png",
    webPreferences: {
      preload: path.join(__dirname, "preload.js"), // Ensure this path is correct
      contextIsolation: true,
      enableRemoteModule: false,
    },
  });

  win.loadURL("http://localhost:3000");
}

app.whenReady().then(createWindow);

app.on("window-all-closed", () => {
  if (process.platform !== "darwin") {
    app.quit();
  }
});

app.on("activate", () => {
  if (BrowserWindow.getAllWindows().length === 0) {
    createWindow();
  }
});

ipcMain.handle("run-compiler", async (event, input) => {
  return new Promise((resolve, reject) => {
    // write the input to file
    fs.writeFileSync("input.txt", input);
    // clear symbol table and errors
    fs.writeFileSync("outputs/symbolTable.txt", "");
    fs.writeFileSync("outputs/errors.txt", "");

    const command = `.\\compiler.exe < .\\input.txt`;
    console.log(command);
    exec(command, (error, stdout, stderr) => {
      if (error) {
        reject(new Error(stderr));
      } else {
        // resolve(stdout);

        // read symbolTable and errors from outputs folder
        const symTable = fs.readFileSync("outputs/symbolTable.txt", "utf-8");
        const errors = fs.readFileSync("outputs/errors.txt", "utf-8");

        console.log(symTable);
        console.log(errors);

        // return the output, symbol table and errors
        resolve({ quadruples: stdout, symTable, errors });
      }
    });
  });
});
