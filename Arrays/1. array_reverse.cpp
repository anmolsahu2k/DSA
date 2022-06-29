#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1{1, 2, 3, 4, 5, 6};
    int N = v1.size();
    for (int i = 0; i < N / 2; i++)
    {
        swap(v1[i], v1[N - i - 1]);
    }
    // OR
    //  reverse(v1.begin(), v1.end());
    for (int x : v1)
        cout << x << " ";
}
