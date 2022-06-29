//https://www.youtube.com/watch?v=qQ8vS2btsxI
#include <string>
#include <iostream>
#include <cmath>
using namespace std;
//sliding window of size pattern length
int main()
{
    string txt = "AABAACAADAABAABA";
    string pat = "AABA";
    //for all ascii characters
    int d=256;
    int t=0;
    int p=0;
    //to avoid overflow of int datatype
    int q=101;
    //h=(256³)%101(used to remove first char of current window(txt[i]*256³))
    int h=pow(d,pat.length()-1);
    h=h%q;
    for(int i=0;i<pat.length();i++)
    {
        //hash value of pattern and text(AABA->(65x256³+65x256²+66x256¹+65x256⁰)%101)
        p=(p*d+pat[i])%q;
        t=(t*d+txt[i])%q;
    }
    
    for (int i = 0; i <= txt.length() - pat.length(); i++) {
        //if same hash value confirm by matching each character
        if(p==t)
        {   int j;
            for (j = 0; j < pat.length(); j++)
                if (txt[i + j] != pat[j])
                    break;
            if (j == pat.length())
                cout << "Pattern found at index "<< i << endl;
        }
        //else continue sliding window
        if(i<txt.length()-pat.length())
        {
            //remove first char of window and add next char
            t=(((t-txt[i]*h)*d)+txt[i+pat.length()])%q;
            if(t<0)
                t=t+q;
        }
    }
    return 0;
}