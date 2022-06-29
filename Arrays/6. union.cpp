#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    //can use set also
    vector<int> A{7, 1, 5, 2, 3, 6};
    vector<int> B{3, 8, 6, 20, 7};
    map<int, int> m;
    for (int i = 0; i < A.size(); i++)
    {
        m.insert({A[i],i});
    }
    for (int j = 0; j < B.size(); j++)
    {
        m.insert({B[j],j});
    }
    cout<<m.size();
    return m.size();
}