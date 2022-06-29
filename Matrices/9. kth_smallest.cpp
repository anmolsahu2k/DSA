// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends

int partition(int mat[MAX][MAX],int n, int l, int h)
{
    int pivot=mat[h/n][h%n];
    int i=l;
    for(int j=l;j<h;j++)
    {
        if(pivot>=mat[j/n][j%n])
        {
            // cout<<i<<" "<<j<<" "<<mat[j/n][j%n]<<endl;
            swap(mat[i/n][i%n],mat[j/n][j%n]);
            i++;
        }
    }
    swap(mat[i/n][i%n], mat[h/n][h%n]);
    cout<<i<<endl;
    return i;
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  int l=0,h=n*n-1,m;
  k=k-1;
  while(l<=h && k>=l &&k<=h)
  {
    m=partition(mat,n, l, h);
    cout<<" "<<m<<endl;
    if(m==k)
    {
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    cout<<mat[i][j];

            cout<<endl;
            }
        return mat[k/n][k%n];
    }
    else if(m<k)
        l=m+1;
    else
        h=m-1;
  }
  
}
