#include <iostream>
#include <string>
using namespace std;
    
    string count(string S)
    {
        int k=1;
        int j=0;
        string newString;
        while(j<S.length())
        {
            //counting same number together(11112->41)
            if(k<S.length() && S[k]==S[j])
            {
                k++;
            }
            else
            {
                //where series ends, insert count, then insert element counted
                newString.push_back(k-j+48);
                newString.push_back(S[j]);
                //new series starting
                j=k;
                k++;
            }
        }
        return newString;
    }
    string countAndSay(int n) {
        
        if(n==1)
        {
            return "1";
        }
        else
        {
            return count(countAndSay(n-1));
        }
        
    }
    int main()
    {
        cout<<countAndSay(2);
    }