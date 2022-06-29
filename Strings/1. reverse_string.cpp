#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    int n = s.size();
    for (int i = 0; i < n / 2; i++)
        swap(s[i], s[n - i - 1]);
    for(char x:s)
    {
        cout << x<<" ";
    }
}