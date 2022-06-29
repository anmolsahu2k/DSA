// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        int oc=0,cc=0,s=0,imb=0;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]==']')
            {
                cc++;
                //no. of imbalanced pairs are imb
                imb=cc-oc;
            }
            else
            {
                oc++;
                if(imb>0)
                {
                    //as soon as open bracket is found, swap to balance string
                    //eg., []]]]'['[[->[]'[']]][[, to bring highlighted bracket to correct position 3(imb) swaps are required
                    //     01234 5 67->01 2 34567
                    s+=imb;
                    //now one pair is placed correctly so imb--
                    imb--;
                }
            }
        }
        return s;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends