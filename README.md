# exam05 - 42 Tokyo Practice Projects

42Tokyo Exam05 Practice Collection

## Project Structure

### Level 1: Data Structures & Object-Oriented Programming (C++)

#### 1. **bigint** - Arbitrary Precision Integer Arithmetic
Implementation of a `bigint` class that handles unsigned integers of arbitrary precision using string-based storage.
- **Key Features:**
  - Addition operation support
  - Comparison operators
  - Digit shift operations (left shift: multiply by 10^n, right shift: divide by 10^n)
  - Stream output with `<<` operator (no leading zeros)
- **Files:** `bigint.hpp`, `bigint.cpp`

#### 2. **polyset** - Set and Bag Data Structures
Implementation of searchable bag and set classes with multiple underlying data structures.
- **Components:**
  - `bag`: Abstract base class for bag data structure
  - `searchable_bag`: Abstract interface adding search capability
  - `array_bag`: Bag implementation using array storage
  - `tree_bag`: Bag implementation using binary search tree
  - `searchable_array_bag`: Searchable variant of array_bag
  - `searchable_tree_bag`: Searchable variant of tree_bag
  - `set`: Wrapper class converting a searchable_bag into a set
- **All classes follow Orthodox Canonical Form**
- **Files:** Multiple .hpp and .cpp files as specified in subject

#### 3. **vect2** - 2D Vector Mathematics
A mathematical vector class for 2D integer vectors with linear algebra operations.
- **Features:**
  - Vector addition
  - Vector subtraction
  - Scalar multiplication
  - Component access via `[]` operator (indices 0 and 1)
  - Stream output formatting: `{x, y}`
- **Files:** `vect2.hpp`, `vect2.cpp`

### Level 2: Algorithm Implementation (C)

#### 4. **bsq** - Biggest Square Search
Finds the largest square in a 2D map while avoiding obstacles using dynamic programming.
- **Input Format:**
  - First line: `<lines> <empty_char> <obstacle_char> <full_char>`
  - Map containing empty spaces and obstacles
- **Algorithm:** Dynamic programming approach to calculate maximum square size
- **Output:** Original map with the largest valid square replaced by full character
- **Tie-breaking:** Top-most, then left-most square when multiple solutions exist
- **Error Handling:** Validates map integrity and outputs "map error" for invalid maps
- **Input Methods:** File arguments or stdin
- **Files:** `*.c`, `*.h`

#### 5. **life** - Conway's Game of Life
Simulates Conway's Game of Life on a customizable board with drawing commands.
- **Usage:** `./life width height iterations`
- **Drawing Commands:**
  - `w` / `a` / `s` / `d`: Move pen up/left/down/right
  - `x`: Toggle pen (draw/erase)
- **Simulation:** Applies classic Game of Life rules for specified iterations
- **Output:** Final board state with living cells as `0` and dead cells as space
- **Boundary:** Cells outside the board are considered dead
- **Files:** `*.c`, `*.h`

---

## Requirements

- **Level 1:** C++11 or later
- **Level 2:** C99 or later
- Standard compilation tools (g++, gcc, make)

## Compilation

Each project contains a `main.c` or `main.cpp` that should compile successfully with the implemented classes/functions.

```bash
# Example for C++ projects
g++ -std=c++11 -Wall -Wextra -Werror *.cpp -o program

# Example for C projects
gcc -std=c99 -Wall -Wextra -Werror *.c -o program
```

## Learning Outcomes

- Object-oriented design and inheritance in C++
- Abstract classes and interfaces
- Dynamic data structures (arrays, trees)
- Algorithm design (dynamic programming)
- Cellular automata simulation
- File I/O and parsing
- Memory management in C
