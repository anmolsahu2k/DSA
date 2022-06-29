#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void remove(string S, int n, string newStr)
{
    if(n==0)
    {
        reverse(newStr.begin(),newStr.end());
        cout<<newStr;
        return;
    }
    else if(S[n]!=newStr.back())
        newStr.push_back(S[n]);
    remove(S,n-1,newStr);
}
int main()
{
    string newStr;
    string S="aabb";
    int n=S.length();
    remove(S,n, newStr);
    return 0;
}