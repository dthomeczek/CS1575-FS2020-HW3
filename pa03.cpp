/* The duty of main here is to interact with the user, take in input, and manage
    wrapping output and runtime.
 * Declar any NON-REQUIRED functions above main if needed (it is not likely that
    you'll need to)
 */

#include "maze.h"

int main()
{
    int rows; // number of rows in the matrix
    int row; // amount of rows for two-dimensional use
    int col; // amount of columns
    int i = 0; // used for printing the number of the matrix
    string * matrix; // declaring the matrix
    cin >> rows;
    while (rows > 0)
    {
        matrix = build_matrix(rows); // creating the matrix
        fill_matrix(matrix, rows); // filling the matrix with the structure of the matrix
        find_start(matrix, rows, row, col); // finds the starting point "N" in the matrix
        if (find_exit(matrix, row, col) == true) // prints the route for the matrix if there is one
        {
            cout << "Map " <<  i <<  " -- Solution found:" << endl;
            print_matrix(matrix, rows);
        }
        else // prints the empty maze if there is no solution in the matrix
        {
            cout << "Map " << i << " -- No solution found:" << endl;
            print_matrix(matrix, rows);
        }
        delete_matrix(matrix); // clears the matrix
        cin >> rows; // takes in the next number of rows for the next maze
        i++;
    }
    return 0;
}
