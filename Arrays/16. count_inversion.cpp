// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long tc=0;
    void merge(long long arr[],long long l, long long mid, long long h)
    {
        long long n1=mid-l+1;
        long long n2=h-mid;
        long long L[n1],R[n2],i,j,k;
        for(i=0;i<n1;i++)
        {
            L[i]=arr[l+i];
        }
        for(i=0;i<n2;i++)
        {
            R[i]=arr[mid+i+1];
        }
        i=0,j=0,k=l;
        while(i<n1 && j<n2)
        {
            if(L[i]>R[j])
            {
                arr[k]=R[j];
                j++;
                k++;
                //L=[5,6] R=[2,3] => A=[5,6,2,3]. Now for every L[i]>R[j] there will be n1-i inversions
                //eg.,5>2, no. of inversions for 2 is n1-i(2-0=2)( because L and R are sorted, so if 5>2, then 6>2 hence 2 inversions)
                //Likewise for 5>3, there will be 2(n1)-0(i)=2 inversions. Hence, total 4 inversions 
                tc+=(n1-i);
            }
            else
            {
                arr[k]=L[i];
                i++;
                k++;
            }
        }
        while(i<n1)
        {
            arr[k]=L[i];
            k++;
            i++;
        }
        
        while(j<n2)
        {
            arr[k]=R[j];
            k++;
            j++;
        }
    }
    void mergeSort(long long arr[],long long l, long long h)
    {
        if(l<h)
        {
            long long mid = l+(h-l)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,h);
            merge(arr,l,mid,h);
        }
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        mergeSort(arr,0,N-1);
        long long int res = tc;
        tc=0;
        return res;
    }
    

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends