/* Here in the .cpp you should define and implement everything declared
    in the .h file
 */

#include "maze.h"

void get_identity(string &my_id)
{
    my_id = "djtpfr";
}

string * build_matrix(int rows)
{
    string * matrix = new string [rows];
    return matrix;
}

void fill_matrix(string *matrix, int rows)
{
    string row_vals;
    cin.ignore();
    for (int i = 0; i < rows; i++)
    {
        getline(cin, row_vals);
        matrix[i] = row_vals;
    }
}

void print_matrix(string *matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        cout << matrix[i];
        cout << endl;
    }
    cout << endl;
}

void delete_matrix(string *&matrix)
{
    delete[] matrix;
}

void find_start(string *matrix, int rows, int &row, int &col)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < static_cast<int>(matrix[i].size()); j++) // the static cast fixes a warning stating that there was a comparison between signed and unsigned ints
        {
            if (matrix[i][j] == 'N')
            {
                row = i;
                col = j;
            }
        }
    }
}

bool find_exit(string *matrix, int row, int col)
{
    bool exit_found;
    if (at_end(matrix, row, col) == true)
    {
        exit_found = true;
        return exit_found;
    }
    if (valid_move(matrix, row, col, "NORTH") == true)
    {
        if (matrix[row][col] != 'N')
        {
            matrix[row][col] = '@';
        }
        if (find_exit(matrix, row - 1, col) == true)
        {
            exit_found = true;
            return exit_found;
        }
        if (matrix[row][col] != 'N')
        {
            matrix[row][col] = ' ';
        }
    }
    if (valid_move(matrix, row, col, "EAST") == true)
    {
        if (matrix[row][col] != 'N')
        {
            matrix[row][col] = '@';
        }
        if (find_exit(matrix, row, col + 1) == true)
        {
            exit_found = true;
            return exit_found;
        }
        if (matrix[row][col] != 'N')
        {
            matrix[row][col] = ' ';
        }
    }
    if (valid_move(matrix, row, col, "SOUTH") == true)
    {
        if (matrix[row][col] != 'N')
        {
            matrix[row][col] = '@';
        }
        if (find_exit(matrix, row + 1, col) == true)
        {
            exit_found = true;
            return exit_found;
        }
        if (matrix[row][col] != 'N')
        {
            matrix[row][col] = ' ';
        }
    }
    if (valid_move(matrix, row, col, "WEST") == true)
    {
        if (matrix[row][col] != 'N')
        {
            matrix[row][col] = '@';
        }
        if (find_exit(matrix, row, col - 1) == true)
        {
            exit_found = true;
            return exit_found;
        }
        if (matrix[row][col] != 'N')
        {
            matrix[row][col] = ' ';
        }
    }
    exit_found = false;
    return exit_found;
}

bool at_end(string *matrix, int row, int col)
{
    bool ending;
    if (matrix[row][col] == 'E')
    {
        ending = true;
        return ending;
    }
    else
    {
        ending = false;
        return ending;
    }
}

bool valid_move(string *matrix, int row, int col, string direction)
{
    bool valid;
    if (direction == "NORTH")
    {
        row -= 1;
    }
    if (direction == "EAST")
    {
        col += 1;
    }
    if (direction == "SOUTH")
    {
        row += 1;
    }
    if (direction == "WEST")
    {
        col -= 1;
    }
    if ((matrix[row][col] == ' ') || (matrix[row][col] == 'E'))
    {
        valid = true;
        return valid;
    }
    else
    {
        valid = false;
        return valid;
    }
}
