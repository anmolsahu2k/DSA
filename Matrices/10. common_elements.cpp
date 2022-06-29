#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    vector<vector<int>> mat = {{1, 2, 7, 4, 8},
                            {3, 7, 8, 5, 1},
                            {8, 7, 7, 3, 1},
                            {8, 1, 2, 7, 9},
                            };
    unordered_map<int, int> mp;
    vector<int> v;
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[0].size();j++)
        {
            if(mp.find(mat[i][j])!=mp.end() && mp[mat[i][j]]==i)
                mp[mat[i][j]]++;
            else
            {
                mp.insert({mat[i][j],1});
            }
        }
        
    }
    for(auto itr=mp.begin();itr!=mp.end();itr++)
    {
            if(itr->second==mat.size())
                v.push_back(itr->first);
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}