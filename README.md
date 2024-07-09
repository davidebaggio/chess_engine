# Chess Engine

A simple and efficient chess engine written in C++. This project aims to create a functional chess engine that can play a game of chess against human opponents or other engines. The engine includes basic features like move generation, board evaluation, and a search algorithm to determine the best move.

## Features (WIP)

- **Move Generation**: Generates all possible legal moves for a given position.
- **Board Evaluation**: Evaluates the board to determine the strength of a position.
- **Search Algorithm**: Implements the Minimax algorithm with Alpha-Beta pruning to search the game tree and find the best move.
- **UCI Protocol Support**: Communicates with chess GUI programs via the Universal Chess Interface (UCI) protocol.

## Getting Started

### Prerequisites

Make sure you have the following installed on your system:

- C++ compiler (GCC, Clang, MSVC, etc.)
- CMake (optional, for building the project)

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/davidebaggio/chess_engine.git
   cd chess_engine
   ```

2. Build the project:

   - Using CMake:

     ```bash
     mkdir build
     cmake -S . -B build -G "MinGW Makefiles"
     ```

   - Without CMake:

     ```bash
     mkdir build
     g++ -I./include -o ./build/chess_engine ./src/*.cpp
     ```

3. Run the chess engine:

   ```bash
   ./build/chess_engine
   ```

## Usage (WIP)

### Command Line Interface (WIP)

### UCI Protocol (WIP)

## Contributing

Contributions are welcome! Please fork the repository and create a pull request with your changes. Ensure that your code adheres to the existing style and includes relevant tests.

## License

This project is licensed under the MIT License - see the [LICENSE](./LICENCE) file for details.

## Acknowledgements

- Thanks to the open-source chess community for their valuable resources and inspiration.
- [Chess Programming Wiki](https://www.chessprogramming.org/Main_Page) for detailed information on chess algorithms and techniques.
