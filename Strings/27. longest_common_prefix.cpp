#include <iostream>
#include <vector>
#include <string>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    int n=strs[0].length();
    int m=strs.size();
    int maxSame=-1;
    int flag=0;
    if(strs.size()==1)
        return strs[0];
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<m-1;i++)
        {
            if(j>strs[i].length() || j>strs[i+1].length() || strs[i][j]!=strs[i+1][j])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            return strs[0].substr(0,maxSame+1);
        else
            maxSame=j;
    }
    return strs[0].substr(0,maxSame+1);
}
int main()
{
    vector<string> strs={"flower","flow","fly"};
    cout<<longestCommonPrefix(strs);
    return 0;
}