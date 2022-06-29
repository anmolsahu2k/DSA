#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string s="HELLO WORLD";
    vector<string> v{
                    "2","22","222",
                    "3","33","333",
                    "4","44","444",
                    "5","55","555",
                    "6","66","666",
                    "7","77","777","7777",
                    "8","88","888",
                    "9","99","999","9999"
    };
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ')
            cout<<'0';
        else
            cout<<v[int(s[i])%65];
    }
    return 0;
}