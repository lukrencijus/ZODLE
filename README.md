# ZODLE

ZODLE is a Lithuanian version of the popular word puzzle game Wordle, developed by first-year students Lukas Šerelis and Karolis Zabulis from Vilnius University for the course "Basics of Programming and IT". The game is written in the C programming language.

## Game Overview

In ZODLE, the objective is to guess a hidden Lithuanian word within a limited number of tries, similar to the original Wordle game. Players receive feedback after each guess, showing which letters are correct and in the correct position, as well as which letters are part of the word but in the wrong position.

## Features

- **Multiple Difficulty Levels**: 
  - **Lengvas (Easy)** 
  - **Vidutinis (Medium)** 
  - **Sunkus (Hard)**
  
- **Leaderboards**: Track your best scores and challenge yourself to improve.

## Files

- `Info.txt`: General game information.
- `Lengvas.txt`: List of words for the Easy difficulty level.
- `Vidutinis.txt`: List of words for the Medium difficulty level.
- `Sunkus.txt`: List of words for the Hard difficulty level.
- `Lyderiai.txt`: Stores leaderboard data.
- `main.c`: Main source file containing the core game logic.
- `main.h`: Header file with function declarations.
- `realizacija.c`: Additional implementation details for the game mechanics.
- `main.exe`: Compiled executable for the game.

## How to Play

1. Clone the repository to your local machine.
2. Compile the game using a C compiler (e.g., `gcc main.c realizacija.c -o zodle`).
3. Run the executable (`./zodle` on Unix-like systems or `zodle.exe` on Windows).
4. Select a difficulty level and start guessing words.

## Requirements

- A C compiler (GCC or similar) to compile the source code.

## Authors

- **Lukas Šerelis** [@lukrencijus](https://github.com/lukrencijus)
- **Karolis Zabulis** [@Zabuelis](https://github.com/Zabuelis)

This project was developed as part of the course "Basics of Programming and IT" at Vilnius University.
