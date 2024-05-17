import React, { useState } from "react";
import "./App.css";

function App() {
  const [input, setInput] = useState("");
  const [output, setOutput] = useState("");

  const runCompiler = async () => {
    try {
      const result = await window.ipcRenderer.invoke("run-compiler", input);
      setOutput(result);
    } catch (error) {
      setOutput(`Error: ${error.message}`);
    }
  };

  return (
    <div className="App">
      <h1>Compiler GUI</h1>
      <label htmlFor="input">Input:</label>
      <textarea
        id="input"
        value={input}
        onChange={(e) => setInput(e.target.value)}
        rows="5"
        cols="60"
      ></textarea>
      <br />
      <button onClick={runCompiler}>Run Compiler</button>
      <h2>Output:</h2>
      <textarea
        id="output"
        value={output}
        readOnly
        rows="10"
        cols="60"
      ></textarea>
    </div>
  );
}

export default App;
