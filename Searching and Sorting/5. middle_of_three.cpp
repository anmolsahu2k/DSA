// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int middle(int A, int B, int C){
        if(A<B)
        {
            if(B<C)
                return B;
            else
            {
                return max(A,C);
            }
                
        }
        else
        {
            if(B>C)
                return B;
            else
            {
                return min(A,C);
            }
        }
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A,B,C) <<"\n";
    }
    return 0;
}  // } Driver Code Ends