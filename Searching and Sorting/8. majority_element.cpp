// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdbool.h>


 // } Driver Code Ends
//User function Template for C

// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int a[], int size)
{
        
    int maj_index=0;
    int c=0;
    for(int i=0;i<size;i++)
    {
        if(a[maj_index]==a[i])
            c++;
        else
            c--;
        if(c==0)
        {
            maj_index=i;
            c=1;
        }
    }
    c=0;
    for(int i=0;i<size;i++)
    {
        if(a[maj_index]==a[i])
            c++;
    }
    if(c>size/2)
        return a[maj_index];
    else
        return -1;
}

// { Driver Code Starts.

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        
        for(int i = 0;i<n;i++){
            scanf("%d", &arr[i]);
        }
        printf("%d\n", majorityElement(arr, n));
    }

    return 0;
}
  // } Driver Code Ends