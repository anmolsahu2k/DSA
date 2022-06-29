// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        int maxLength=1;
        int k,j,start,end,flag=0;
        //assuming odd palin
        for(int i=1;i<S.length();i++)
        {
            j=i-1;
            k=i+1;
            while(j>=0 && k<S.length() && S[j]==S[k])
            {
                j--;
                k++;
            }
            j++;
            k--;
            if(maxLength<k-j+1)
            {
                maxLength=k-j+1;
                start=j;
                end=k;
            }
        }
        //assuming even palin
        for(int i=0;i<S.length();i++)
        {
            j=i;
            k=i+1;
            while(j>=0 && k<S.length() && S[j]==S[k])
            {
                j--;
                k++;
            }
            j++;
            k--;
            if(maxLength<k-j+1)
            {
                maxLength=k-j+1;
                start=j;
                end=k;
            }
        }
        if(maxLength==1)
            return S.substr(0,1);
        return S.substr(start,end-start+1);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
  // } Driver Code Ends