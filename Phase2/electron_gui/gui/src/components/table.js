import Table from "@mui/joy/Table";
import React from "react";

const DataTable = ({ data, containerStyle, headerStyle, rowStyle }) => {
  return (
    <div
      style={{
        overflow: "auto",

        ...containerStyle,
      }}
    >
      <Table aria-label="simple table">
        <thead
          style={{
            position: "sticky",
            top: 0,
            backgroundColor: "red",
            zIndex: 1,
            ...headerStyle,
          }}
        >
          <tr>
            <th style={{ ...headerStyle }}>Name</th>
            <th style={{ ...headerStyle }}>DataType</th>
            <th style={{ ...headerStyle }}>Qualifier</th>
            <th style={{ ...headerStyle }}>TimeStep</th>
            <th style={{ ...headerStyle }}>Scope</th>
            <th style={{ ...headerStyle }}>Initialized</th>
            <th style={{ ...headerStyle }}>Used</th>
            <th style={{ ...headerStyle }}>Function</th>
          </tr>
        </thead>
        <tbody>
          {data.map((item, index) => (
            <tr
              key={index}
              style={{
                color: "white",
                ...rowStyle,
              }}
            >
              <td>{item.Name}</td>
              <td>{item.DataType}</td>
              <td>{item.Qualifier}</td>
              <td>{item.TimeStep}</td>
              <td>{item.Scope}</td>
              <td>{item.Initialized}</td>
              <td>{item.Used}</td>
              <td>{item.Function}</td>
            </tr>
          ))}
        </tbody>
      </Table>
    </div>
  );
};

export default DataTable;
