Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A2

*Description

This program simulates a simplified version of the classic Super Mario game. 
It includes three main classes: `Game`, `Mario`, and `World`, which collectively 
create a game where Mario navigates through different levels, collects coins, defeats 
enemies, and aims to rescue the princess.

*Program Components

*Game Class

- The game class is responsible for initializing the game and managing the game loop.
- It reads input from a text file to set up the game's initial parameters (e.g., number of levels, grid size, item distribution percentages).
- The game loop runs as long as Mario is alive and hasn't rescued the princess.
- During each iteration of the game loop, Mario takes actions, and the game state is updated and displayed.

*Mario Class

- The mario class represents the main character of the game.
- Mario has attributes such as the number of lives, power level, and position on the grid.
- Mario can move, collect coins, defeat enemies (Goombas and Koopas), and interact with items (coins, mushrooms).
- Mario's objective is sto rescue the princess and advance through the levels.
- Mario's actions are determined based on the game's logic and random events.

*World Class

- The world class represents the game world, including multiple levels and a grid.
- It generates random distributions of items (coins, mushrooms, enemies) on each level's grid.
- The grid size and item distribution percentages are specified during the game setup.
- Levels may contain warp points, boss fights, and unique challenges.


https://www.geeksforgeeks.org/stdstoi-function-in-cpp/
    - used to convert string to int from input file

g++ *.cpp -o mario 
./mario input.txt output.txt

