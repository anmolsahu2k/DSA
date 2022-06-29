//viewed solution
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<vector<int>> pattern;
    int A = 3;
    int size, temp, limit, i, j;

    size = 2 * A - 1;
    limit = size;
    temp = 0;

    vector<vector<int>> mat(size, vector<int>(size));

    while (A > 0)
    {
        for (i = temp; i < limit; i++)
        {
            for (j = temp; j < limit; j++)
            {
                mat[i][j] = A;
            }
        }
        A--;
        limit--;
        temp++;
    }
    for (int i = 0; i < mat.size();i++)
    {
        for (int j = 0; j < mat[i].size();j++)
        {
            cout << mat[i][j];
        }
        cout << endl;
    }
        return 0;
}