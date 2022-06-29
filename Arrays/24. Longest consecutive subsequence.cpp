// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        set<int> st;
        int c=0,maxC=0;
        for(int i=0;i<N;i++)
            st.insert(arr[i]);
        for(auto itr=st.begin();itr!=prev(st.end());itr++)
        {

                if(*next((itr))-*itr==1)
                    c++;
                else
                    c=0;
                maxC=max(maxC,c);
        }
        return maxC+1;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends