// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        //find number of 0's in the factorial of mid
        bool check(int mid, int n)
        {
            int cnt=0;
            for(int i=5;i<=mid;i*=5)
                cnt+=mid/i;
            return (cnt>=n);
        }
        int findNum(int n)
        {
            int l=0,h=5*n,mid;
            while(l<h)
            {
                mid=(l+h)/2;
                //if number found with n 0's, again check in the left to ensure minimum number 
                if(check(mid,n))
                    h=mid;
                else
                    l=mid+1;
            }
            return l;
        }
    // int findNum(int n)
    // {
    //     int i=0;
    //     int c=5;
    //     int ans=0;
    //     int k;
    //     while(i<n)
    //     {
    //         ans+=5;
    //         if(ans==5*c && i<n)
    //         {
    //             c+=5;
    //             k=1;
    //             while(ans%(5*k)==0)
    //             {
    //                 i++;
    //                 k*=5;
    //             }
    //         }
    //         else
    //             i++;
    //     }
    //     return ans;
    // }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends

