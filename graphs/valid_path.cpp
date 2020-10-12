#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int dirs[8][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
    {1, 1},
    {-1, -1},
    {-1, 1},
    {1, -1}};

bool isInCircle(int xc, int yc, int r, int x, int y)
{
    return (pow(x - xc, 2) + pow(y - yc, 2)) <= (r * r);
}

bool validDir(int X, int Y, int i, int j)
{
    return i >= 0 && j >= 0 && i <= X && j <= Y;
}

bool hasPath(int srcI, int srcJ, int destI, int destJ, vector<vector<bool>> &visited, vector<int> &xCoord, vector<int> &yCoord, int R, int N)
{
    if (srcI == destI && srcJ == destJ)
        return true;
    visited[srcI][srcJ] = true;
    for (int k = 0; k < 8; k++)
    {
        int I = srcI + dirs[k][0];
        int J = srcJ + dirs[k][1];

        if (validDir(destI, destJ, I, J))
        {
            if (!visited[I][J])
            {
                bool insideCircle = false;
                for (int i = 0; i < N; i++)
                {
                    insideCircle = isInCircle(xCoord[i], yCoord[i], R, I, J);
                    if (insideCircle)
                        break;
                }
                if (!insideCircle)
                {
                    if (hasPath(I, J, destI, destJ, visited, xCoord, yCoord, R, N))
                        return true;
                }
                else
                    visited[I][J] = true;
            }
        }
    }

    return false;
}

string solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F)
{
    vector<vector<bool>> visited(A + 1, vector<bool>(B + 1, false));

    if (hasPath(0, 0, A, B, visited, E, F, D, C))
    {
        return "YES";
    }
    return "NO";
}

int main()
{
    int A = 14;
    int B = 3;
    int C = 9;
    int D = 0;
    vector<int> E = {3, 3, 0, 11, 8, 11, 14, 8, 4};
    vector<int> F = {1, 0, 2, 2, 0, 2, 3, 2, 1};

    cout << solve(A, B, C, D, E, F) << endl;
}