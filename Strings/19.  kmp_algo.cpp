//https://www.youtube.com/watch?v=V5-7GzOfADQ
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//Array preprocessing
int main()
{
    string s="aaaaa";
    int i=1,j=0;
    vector<int> A(s.length(),0);
    while(i<s.length())
    {
        if(s[i]==s[j])
        {
            //marking in A to move j to that index(A[j-1]) if there is a mismatch
            A[i]=j+1;
            i++;
            j++;
        }
        else
        {
            //because s[i] should match with 1st character(s[j]) 
            if(j==0)
                i++;
            else
            //so that it does not go back to the 1st character when substring is repeated, 
            //it only goes to 2nd 'a'(1) when mismatched
            // (ababd-xyzab-ababd)
            //  00120-00012-34345
                j=A[j-1];
        }
    }
    cout<<A.back();
    return 0;
}