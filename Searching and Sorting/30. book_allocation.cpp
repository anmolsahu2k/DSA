// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool isPossible(int A[], int curr_max, int N, int M)
    {

        int std_required=1,curr_sum=0;
        for(int i=0;i<N;i++)
        {
            //if any book has more pages than the capacity
            if(curr_max<A[i])
                return false;
            //for a student if total pages becomes more than capacity, add one more student
            if(curr_sum+A[i]>curr_max)
            {
                std_required++;
                curr_sum=A[i];
                if(std_required>M)
                    return false;
            }
            //for a student if total pages is less than the capacity, keep adding pages
            else
                curr_sum+=A[i];
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //A[]={10,20,30,40}
        //sort for binary search
        sort(A,A+N);
        int sum=0,result;
        if(M>N)
            return -1;
        for(int i=0;i<N;i++)
            sum+=A[i];
        int l=0,h=sum,mid;
        //range->0---------------100
        while(l<=h)
        {
            //assume maximum pages that any student can read =mid
            mid=(l+h)/2;
            //check if this configuration is possible with the given number of students
            //(each student can read maximum of 'mid' pages)->all the pages should be allotted to not more than 'm' students
            if(isPossible(A,mid,N,M))
            {
                //if possible, decrease mid(check in the left side) to get the minimum maximum capacity
                result=mid;
                h=mid-1;
            }
            else
                //if more capacity needed to accomodate m students, increase mid 
                l=mid+1;
        }
        return result;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends