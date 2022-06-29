#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<vector<int>> v = {{1,5,3},{2,8,7},{4,6,9}};
    for(int i=0;i<v.size();i++)
        sort(v[i].begin(),v[i].end());
    vector<vector<int>> arr;
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[0].size();j++)
        {
            cout<<v[i][j];
        }
        cout<<endl;
    }
    return 0;
}