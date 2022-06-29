#include <string>
#include <iostream>
using namespace std;
int main()
{

    string s = "THIS IS A TTTTT TEXT";
    string t = "TTTT";
    //USING STL FUNCTION 'find'
    // string::size_type pos = 0;
    // while ((pos = s.find(target, pos )) != string::npos) {
    //        cout<< pos<<endl;
    //        pos++;
    // }
    //--------------------------------------------------------
    // WITHOUT USING STL FUNCTION(using for loop)
    // for (int i = 0; i <= N - M; i++) {
    //     int j;
    //     for (j = 0; j < M; j++)
    //         if (txt[i + j] != pat[j])
    //             break;
    //     if (j == M)
    //         cout << "Pattern found at index "
    //              << i << endl;
    // }
    //--------------------------------------------------------
    //WITHOUT USING STL FUNCTION(using while loop)
    int i=0,j=0,temp;
    while(i<s.length() && j<t.length())
    {
        while(s[i]!=t[0])
        {
            i++;
        }
        temp=i;
        while(s[i]==t[j])
        {
            i++;
            j++;
        }
        if(j==t.length())
            cout<<temp<<endl;
        j=0;
        i=temp+1;
    }
    return 0;
}