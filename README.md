🧩 Sudoku Solver in C++
A simple console-based Sudoku solver built in C++ using recursion and backtracking.

This program not only solves a 9x9 Sudoku puzzle but also checks for input validity and points out mistakes with their coordinates if any are found.

📌 Features
✅ Solves any valid 9x9 Sudoku using backtracking.

🔍 Validates the initial puzzle input.

⚠️ Shows the coordinates of invalid inputs (row, column, and value).

🧠 Custom Node class and map<pair<int, int>, Node> to represent the grid.

🛠 How It Works
The puzzle is represented using a map of coordinate pairs to Node objects.

The StartSudoku() function initializes a sample puzzle. You can modify it to use your own input.

Before solving, the program checks the validity of the given puzzle.

If valid, it solves the puzzle using a recursive backtracking approach.

The puzzle is displayed before and after solving.

🧪 Sample Output
Sudoku Solver:
Started:

|5|3|0|0|7|0|0|0|0|
|6|0|0|1|9|5|0|0|0|
|0|9|8|0|0|0|0|6|0|
...

Completed

|5|3|4|6|7|8|9|1|2|
|6|7|2|1|9|5|3|4|8|
|1|9|8|3|4|2|5|6|7|
...
📄 How to Run
Copy the code into a .cpp file.

Compile using any C++ compiler (e.g., g++, clang).


g++ sudoku_solver.cpp -o sudoku_solver
./sudoku_solver
Modify the StartSudoku() function to test your own puzzles.

📂 File Structure
main() – Initializes grid, validates puzzle, and calls the solver.

StartSudoku() – Loads an example puzzle (you can replace it).

CheckSudoku() – Validates the puzzle and prints invalid cells.

SolveSudoku() – Recursively solves the puzzle using backtracking.

isLegal() – Checks if a number placement is valid.

Display() – Prints the current puzzle to the console.
