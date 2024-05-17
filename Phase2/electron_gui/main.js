const { app, BrowserWindow, ipcMain } = require("electron");
const path = require("path");
const { exec } = require("child_process");

function createWindow() {
  const win = new BrowserWindow({
    // width: 800,
    // height: 600,
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
    const command = `echo "${input}" | .\\compiler.exe`; // Adjust the command for Windows
    console.log(command);
    exec(command, (error, stdout, stderr) => {
      if (error) {
        reject(new Error(stderr));
      } else {
        resolve(stdout);
      }
    });
  });
});
