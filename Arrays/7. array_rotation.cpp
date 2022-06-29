#include <iostream>
#include <vector>
using namespace std;
void left_rotate(vector<int> &A)
{
    int temp = A.front();
    int i;
    for (i = 0; i <A.size()-1;i++)
    {
        A[i] = A[i + 1];
    }
    A[i] = temp;
}
int main()
{
    vector<int> A{2, 6, 7, 10, 13, 15, 19, 28, 38, 56, 35, 91};
    int k = 5;
    for (int i = 0; i < k;i++)
        left_rotate(A);
    for (int x:A)
    {
        cout << x<<" ";
    }
        return 0;
}
