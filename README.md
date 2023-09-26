# Homework #3

This was the third coding assignment for the Fall 2020 CS1575 (Data Structures) course. The purpose of this code was designed around recursive maze navigation.

# Information From Assignment README

Help Niobe navigate through the matrix of service tunnels (1-wide gaps) outside the matrix by creating a navigation system to find a path through this maze.
Your job is to write a program that finds, for every map, a path from wherever you are to the exit.
You can move in any of the four cardinal directions (North, East, West and South). *No diagonal moves are possible.*
You must use **recursive backtracking** to solve the maze to get credit. Other pathfinding algorithms, such as Dijkstra's and A*, cannot be used.

You will also be printing out each map with a path from the "Start" point to the "Exit".
Mark the path using a trail of the character '@'.
<ins>Follow the format as in the sample output.</ins>
Mazes may or may not have a solution, and there may be loops or islands in the maze, though all that are inputted will be *valid enclosed mazes*, and Niobe will *always exist once* in each maze.

<There will be no rooms but only tunnels>

See the hints below! 'N' is Niobe, and 'E' is exit.

## Input/Output
These are both specified in the sample_*.txt files provided in your repository.

* Input is all via C++ std::cin. Even though sample_input.txt is a file, input is not via fstream or file input; we re-direct via **standard input**: https://en.wikipedia.org/wiki/Standard_streams.
```
./yourprogram < sample_input.txt
```
* The general form of input is:
```
    <number of rows>
    <maze>
    <number of rows>
    <maze>
    0
```
  **Note**: a row of 0 should terminate your program.

* **Hint**: reading lines with white-space
  - In this assignment, you are required to read lines with white spaces. You might attempt to use something like:
```
    cin >> maze[i][j];
```
But that would NOT work well, since the extraction operator>> *ignores* white spaces.
  - Instead, read input with getline and std::string (you may need to re-discover how to discard newlines to do this correctly):
    - http://www.cplusplus.com/reference/string/string/getline/
