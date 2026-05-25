🧩 Sudoku Solver in C++

A C++ console-based Sudoku Solver that automatically solves a 9×9 Sudoku puzzle using the Backtracking Algorithm. The program validates Sudoku rules and fills empty cells step-by-step until a solution is found.

🚀 Features
Solves any valid 9×9 Sudoku puzzle
Uses Backtracking Algorithm
Validates:
Row constraints
Column constraints
3×3 subgrid constraints
Displays Sudoku in a structured grid format
Shows final solved board or failure message if unsolvable

🧠 Algorithm Used
🔄 Backtracking

The solver tries numbers from 1 to 9 in empty cells:

If a number is valid → place it and move forward
If it leads to a dead end → backtrack and try another number

This continues until:

The puzzle is solved ✔️
Or no solution exists ❌
🛠️ Technologies Used
C++ Programming Language
Recursion
Backtracking Algorithm
2D Arrays

📂 Project Structure
Sudoku Solver
│
├── main.cpp        # Core logic of Sudoku solver
└── README.md       # Project documentation

▶️ How to Run
1. Clone the repository
git clone https://github.com/your-username/sudoku-solver.git
2. Compile the code
g++ main.cpp -o sudoku
3. Run the program
./sudoku

📌 How It Works
A predefined Sudoku board (9×9 grid) is loaded
The solver searches for empty cells (0 values)
It checks validity using:
Row check
Column check
3×3 subgrid check
Applies recursive backtracking
Prints:
Original board
Solved board (if possible)

🖥️ Sample Output
Initial Board:
4 2 0 | 5 8 6 | 9 3 3
9 1 0 | 0 0 0 | 0 0 0
...

Solved Sudoku:
4 2 7 | 5 8 6 | 9 3 1
9 1 3 | 2 7 4 | 6 8 5
...

📊 Key Functions
is_possible() → Checks if a number can be placed safely
solve() → Implements recursive backtracking
print_board() → Displays Sudoku grid in readable format

📈 Complexity
Worst Case: O(9^(n))
Highly optimized through constraint checking and pruning

💡 Future Improvements
User input Sudoku board
GUI version (Qt / SFML)
Real-time step-by-step visualization
Multiple puzzle generator
Difficulty levels (Easy, Medium, Hard)

👨‍💻 Author
Maaz Sajid
