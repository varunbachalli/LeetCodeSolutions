#include <vector>
#include <iostream>
using namespace std;

bool isCharInVector(std::vector<char> values, char key);
bool checkbox(vector<vector<char>> &board, int row, int column);
bool checkboxs(vector<vector<char>> &board);
bool checkrows(vector<vector<char>> &board);
bool checkcolumns(vector<vector<char>> &board);

bool isValidSudoku(vector<vector<char>> &board)
{
    bool result = true;
    if (!checkboxs(board))
    {
        return false;
    }
    if (!checkrows(board))
    {
        return false;
    }
    if (!checkcolumns(board))
    {
        return false;
    }
    return result;
}

bool isCharInVector(std::vector<char> values, char key)
{
    for (auto itr = values.begin(); itr != values.end(); ++itr)
    {
        if (*itr == key)
        {
            return true;
        }
    }
    return false;
}
bool checkbox(vector<vector<char>> &board, int row, int column)
{
    std::vector<char> values;
    for (int i = 3 * row; i < 3 * row + 3; ++i)
    {
        for (int j = 3 * column; j < 3 * column + 3; ++j)
        {
            if((int)board[i][j] <= (int)'9' && (int)board[i][j] >= (int)'0')
            {
                if (isCharInVector(values, board[i][j]))
                {
                    return false;
                }
                values.push_back(board[i][j]);
            }
        }
    }
    return true;
}
bool checkboxs(vector<vector<char>> &board)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (checkbox(board, i, j) == false)
                return false;
        }
    }
    return true;
}
bool checkrows(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; ++i)
    {
        std::vector<char> values;
        for (int j = 0; j < 9; ++j)
        {
            if ((int)board[i][j] <= (int)'9' && (int)board[i][j] >= (int)'0')
            {
                if (isCharInVector(values, board[i][j]))
                {
                    return false;
                }
                values.push_back(board[i][j]);
            }
        }
    }

    return true;
}
bool checkcolumns(vector<vector<char>> &board)
{
    for (int j = 0; j < 9; ++j)
    {
        std::vector<char> values;
        for (int i = 0; i < 9; ++i)
        {
            if ((int)board[i][j] <= (int)'9' && (int)board[i][j] >= (int)'0')
            {
                if (isCharInVector(values, board[i][j]))
                {
                    return false;
                }
                values.push_back(board[i][j]);
            }
        }
    }
    return true;
}

int main()
{

    vector<vector<char>> a{{'.','.','.','.','.','.','.','.','.'},
            	           {'.','.','.','.','.','.','.','.','.'},
            	           {'.','9','.','.','.','.','.','.','1'},
            	           {'8','.','.','.','.','.','.','.','.'},
            	           {'.','9','9','3','5','7','.','.','.'},
            	           {'.','.','.','.','.','.','.','4','.'},
            	           {'.','.','.','8','.','.','.','.','.'},
            	           {'.','1','.','.','.','.','4','.','9'},
            	           {'.','.','.','5','.','4','.','.','.'}};

    std::cout << (isValidSudoku(a) ? "true" : "false");

    return 0;
}
