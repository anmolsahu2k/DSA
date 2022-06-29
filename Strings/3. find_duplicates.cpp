#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int main()
{
    //also using Hashing
    string S = "geeksforgeeks";
    map<char, int> M;
    for (int i = 0; i < S.length(); i++)
    {
        if (M.count(S[i]))
            M[S[i]]++;
        else
            M[S[i]] = 1;
    }
    cout << "\nThe map M is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (auto itr = M.begin(); itr != M.end(); ++itr)
    {
        if ((itr->second) > 1)
            cout << '\t' << itr->first
                 << '\t' << itr->second << '\n';
    }
    return 0;
}