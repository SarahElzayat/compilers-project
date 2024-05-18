import Editor from "@monaco-editor/react";
import React, { useState } from "react";
import { FaPlay } from "react-icons/fa";
import "./App.css";
import DataTable from "./components/table";

function App() {
  const [input, setInput] = useState("");

  const [symbolTable, setSymbolTable] = useState([]);
  const [quadRuples, setQuadRuples] = useState([]);
  const [errors, setErrors] = useState([]);

  const runCompiler = async () => {
    try {
      const result = await window.ipcRenderer.invoke("run-compiler", input);

      // set quadruples
      setQuadRuples(result.quadruples);

      // console.log(result.quadruples);

      // set symbol table
      const symTable = result.symTable.split("\n");

      // ignore first line
      symTable.shift();

      const symTableData = symTable.map((item) => {
        // split on , and trim
        const data = item.split(",").map((x) => x.trim());
        return {
          Name: data[0],
          DataType: data[1],
          Qualifier: data[2],
          TimeStep: data[3],
          Scope: data[4],
          Initialized: data[5],
          Used: data[6],
          Function: data[7],
        };
      });
      setSymbolTable(symTableData);

      console.log(symTableData);

      // set errors
      const errors = result.errors.split("\n");
      setErrors(errors);
    } catch (error) {
      setErrors(`Error: ${error.message}`);
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
          Compiler
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
          onChange={(value) => setInput(value)}
        />
        <textarea
          readOnly
          value={quadRuples}
          className="output"
          style={{
            height: "50vh",
            width: "48vw",
          }}
        ></textarea>
      </div>
      <br />

      <div
        style={{
          display: "flex",
          justifyContent: "space-between",
          gap: "20px",
        }}
      >
        <div>
          <h3
            style={{
              marginBottom: 0,
            }}
          >
            Output
          </h3>
          <textarea
            id="output"
            value={errors}
            readOnly
            className="output"
          ></textarea>
        </div>

        <div>
          <h3>Symbol Table</h3>
          <DataTable
            data={symbolTable}
            containerStyle={{
              maxHeight: "28vh",
              marginLeft: "15px",
            }}
            headerStyle={{
              backgroundColor: "#1e1e1e",
              color: "white",
            }}
            rowStyle={{
              color: "bisque",
            }}
          />
        </div>
      </div>
    </div>
  );
}

export default App;
