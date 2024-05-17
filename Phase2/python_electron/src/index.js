const { ipcRenderer } = require("electron");

function runCompiler() {
  console.log("running");
  const input = document.getElementById("input").value;
  ipcRenderer
    .invoke("run-compiler", input)
    .then((output) => {
      document.getElementById("output").value = output;
    })
    .catch((error) => {
      document.getElementById("output").value = `Error: ${error.message}`;
    });
}
