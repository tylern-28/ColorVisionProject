# Colorblind-Safe Color Analyzer

A C++ command-line application designed to load, manage, and evaluate color palettes for colorblind accessibility. The program reads color data dynamically from an external text file, populates a vector, and performs automated evaluations to test color combinations against common color vision deficiencies (such as Protanopia, Deuteranopia, and Tritanopia).

## Features

* **File I/O Integration:** Reads color palettes dynamically from an external text file (`palette_data.txt`).
* **Fallback Handling:** Automatically initializes a default colorblind safe vector palette if the text file is missing or empty.
* **Randomized Analysis:** Automatically selects and tests two distinct colors from the loaded palette to evaluate contrast and visibility safety.
* **Modular C++ Design:** Built using clean function prototypes, pass-by-reference parameters, and vector collections.

## Project Structure

* `main.cpp`: Contains the main execution loop, file loading function, evaluation logic, and random selection routine.
* `palette_data.txt`: A plain text file containing a list of color names (one per line) used to populate the program's color palette.
* `README.md`: Project documentation and usage instructions.

## Requirements

* A C++ compiler supporting C++11 or later (e.g., `g++`, Clang).

## Getting Started & Execution

1. **Set Up the Files:**
   * Ensure `main.cpp` and `palette_data.txt` are in the same directory/workspace.
   * Add your desired color names inside `palette_data.txt`, placing each color on its own separate line.

2. **Compile and Run:**
   * Open the project in your C++ development environment.
   * Click **Compile and Run** to build and execute the program.

3. **Output Example:**
   ========================================
         COLORBLIND-SAFE COLOR ANALYZER     
   ========================================

   [File I/O Success] Loaded colors from palette_data.txt.

   --- Random Evaluation Results ---
   Comparing Jet Black and Pure White.
   Status: SAFE - High contrast and colorblind friendly.