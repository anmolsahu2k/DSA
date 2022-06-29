// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int t=0,b=r-1,l=0,R=c-1;
        int i;
        vector<int> arr;
        while(t<=b && l<=R)
        {
            //from left to right along top
            if(t<=b && l<=R)
            {   
                i=l;
                while(i<=R)
                {
                    arr.push_back(matrix[t][i]);
                    i++;
                }
                t++;
            }
            //from top to bottom along right
            if(t<=b && l<=R)
            {  
                i=t;
                while(i<=b)
                {
                    arr.push_back(matrix[i][R]);
                    i++;
                }
                R--;
            }
            //from right to left along bottom
            if(t<=b && l<=R)
            {  
                i=R;
                while(i>=l)
                {
                    arr.push_back(matrix[b][i]);
                    i--;
                }
                b--;
            }
            //from bottom to top along left
            if(t<=b && l<=R)
            {  
                i=b;
                while(i>=t)
                {
                    arr.push_back(matrix[i][l]);
                    i--;
                }
                l++;
            }
        }
        return arr;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends