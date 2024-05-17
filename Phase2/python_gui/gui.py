import tkinter as tk
from tkinter import messagebox, scrolledtext
import subprocess


def run_exe():
    try:
        # Get input from the text field
        input_data = input_text.get("1.0", tk.END).strip()

        # Run the executable with the input data
        result = subprocess.run(
            ['./compiler.exe'], input=input_data, capture_output=True, text=True)

        # Get the output from the executable
        output = result.stdout
        # print(output)

        # Display the output in the text box
        output_box.delete('1.0', tk.END)  # Clear previous output
        output_box.insert(tk.END, output)  # Insert new output

        if result.stderr:  # If there's an error, display it too
            output_box.insert(tk.END, "\nError:\n" + result.stderr)

    except Exception as e:
        messagebox.showerror("Error", str(e))


# Initialize the main window
root = tk.Tk()
root.title("Compiler GUI")

# Set window size to full screen
root.state('zoomed')

# Input field
input_label = tk.Label(root, text="Input:")
input_label.pack(pady=5)

input_text = tk.Text(root, wrap=tk.WORD, width=60, height=5)
input_text.pack(pady=10)

# Scrollable output display
output_label = tk.Label(root, text="Output:")
output_label.pack(pady=5)

output_box = scrolledtext.ScrolledText(root, wrap=tk.WORD, width=60, height=15)
output_box.pack(pady=10)

# Run button
run_button = tk.Button(root, text="Run Compiler", command=run_exe)
run_button.pack(pady=10)

# Start the GUI loop
root.mainloop()
