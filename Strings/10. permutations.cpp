//SEE IMAGE
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void permutations(string s, int l, int r)
{
    if(l==r)
        cout<<s<<" ";
    else
        for(int i=l;i<=r;i++)
        {
            swap(s[l],s[i]);
            permutations(s,l+1,r);
            //backtrack
            swap(s[l],s[i]);
        }
}

int main()
{
    string S="ABC";
    permutations(S,0,S.length()-1);
    return 0;
}