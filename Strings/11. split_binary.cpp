#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string S="0000000000";
    int z=0,o=0,c=-1;
    for(int i=0;i<S.length();i++)
    {
        if(S[i]=='0')
            z++;
        else
            o++;
        if(z==o)
            c++;
    }
    cout<<c;
    return 0;
}