import Editor from "@monaco-editor/react";
import React, { useEffect, useState } from "react";
import { FaPlay } from "react-icons/fa";
import "./App.css";

function App() {
  const [input, setInput] = useState("");
  const [output, setOutput] = useState("");

  useEffect(() => {
    console.log("ipcRenderer:", window.ipcRenderer);
  }, []);

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
      <div className="editor-header">
        <h3
          style={{
            direction: "rtl",
          }}
        >
          يا C كومبايلر
        </h3>
        <FaPlay onClick={runCompiler} className="run-compiler" />
      </div>
      <div
        style={{
          display: "flex",
          justifyContent: "space-between",
          gap: "20px",
        }}
      >
        <Editor
          height="50vh"
          width={"48vw"}
          language="c"
          theme="vs-dark"
          value={input}
          // className="editor"
          padding={10}
        />
        <textarea
          readOnly
          className="output"
          style={{
            height: "50vh",
            width: "48vw",
          }}
        ></textarea>
      </div>
      <br />
      <h3
        style={{
          marginBottom: 0,
        }}
      >
        Output
      </h3>
      <textarea
        id="output"
        value={output}
        readOnly
        className="output"
      ></textarea>
    </div>
  );
}

export default App;
