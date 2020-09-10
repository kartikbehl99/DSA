#include <iostream>
#include <vector>

using namespace std;

void helper(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int m, int n, int r, int c)
{
    for (int i = r; i < m; i++)
    {
        for (int j = c; j < n; j++)
        {
            cout << i;
            if (matrix[i][j] == 0 && !visited[i][j])
            {
                visited[i][j] = true;
                for (int k = 0; k < n; k++)
                {
                    if (matrix[i][k] == 0 && !visited[i][k])
                    {
                        helper(matrix, visited, m, n, i, k);
                    }
                    matrix[i][k] = 0;
                    visited[i][k] = true;
                }
                for (int k = 0; k < m; k++)
                {
                    if (matrix[k][j] == 0 && !visited[k][j])
                    {
                        helper(matrix, visited, m, n, k, j);
                    }
                    matrix[k][j] = 0;
                    visited[k][j] = true;
                }
            }
        }
    }
}

void setZeroes(vector<vector<int>> &matrix, vector<vector<bool>> &visited)
{
    helper(matrix, visited, matrix.size(), matrix[0].size(), 0, 0);

    for (vector<int> row : matrix)
    {
        for (int i : row)
            cout << i << " ";
        cout << "\n";
    }
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    setZeroes(matrix, visited);
}