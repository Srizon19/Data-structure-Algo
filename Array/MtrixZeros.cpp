#include <bits/stdc++.h>

using namespace std;

// brute force solution
void markRow(vector<vector<int>> &matrix, int row, int col, int i)
{

    // set all the nonzero elemns as -1 in the row i

    for (int j = 0; j < col; j++)
    {
        if (matrix[i][j] != 0)
        {
            matrix[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>> &matrix, int row, int col, int i)
{

    // set all the nonzero elemns as -1 in the col i

    for (int j = 0; j < col; j++)
    {
        if (matrix[j][i] != 0)
        {
            matrix[j][i] = -1;
        }
    }
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                markRow(matrix, row, col, i);
                markCol(matrix, row, col, j);
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is: \n";
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}
