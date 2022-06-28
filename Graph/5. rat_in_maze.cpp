// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isValid(int row,int col,vector<vector<int>> m, int n)
    {
        if(row<n&&col<n&&row>=0&&col>=0&&m[row][col]==1)
            return true;
        return false;
    }
    void getAllPaths(int x,int y,vector<vector<int>> m, int n,vector<int> dx, 
    vector<int> dy,string currPath, vector<string> &allPaths)
    {
        if(x==n-1&&y==n-1)
        {
            allPaths.push_back(currPath);
            return;
        }
        string dir="DLRU";
        for(int i=0;i<4;i++)
        {
            int row=x+dx[i];
            int col=y+dy[i];
            if(isValid(row,col,m,n))
            {
                m[row][col]=2;
                getAllPaths(row,col,m,n,dx,dy,currPath+dir[i],allPaths);
                m[row][col]=1;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<int> dx={1,0,0,-1};
        vector<int> dy={0,-1,1,0};
        string currPath="";
        vector<string> allPaths;
        if(m[0][0]==1)
        {
            m[0][0]=2;
            getAllPaths(0,0,m,n,dx,dy,currPath,allPaths);
        }
        return allPaths;
    }
    //EXTRA SPACE(O(N^2))
    // bool isSafe(int row, int col,vector<vector<int>> &mat,int n, vector<vector<bool>> visited)
    // {
    //     if(row==-1||col==-1||row==n||col==n||visited[row][col]==true||mat[row][col]==0)
    //         return false;
    //     return true;
    // }
    // void getAllPaths(int row, int col,vector<vector<int>> &mat,int n,vector<vector<bool>> &visited,
    //                                                         string &currPath,vector<string> &allPaths)
    // {
    //     if(mat[row][col]==0)
    //         return;
    //     if(row==n-1&&col==n-1)
    //     {
    //         allPaths.push_back(currPath);
    //         return ;
    //     }
    //     visited[row][col]=true;
    //     if(isSafe(row+1,col,mat, n, visited))
    //     {
    //         currPath.push_back('D');
    //         getAllPaths(row+1,col,mat,n,visited,currPath,allPaths);
    //         currPath.pop_back();
    //     }
    //     if(isSafe(row,col-1,mat, n, visited))
    //     {
    //         currPath.push_back('L');
    //         getAllPaths(row,col-1,mat,n,visited,currPath,allPaths);
    //         currPath.pop_back();
    //     }
    //     if(isSafe(row,col+1,mat, n, visited))
    //     {
    //         currPath.push_back('R');
    //         getAllPaths(row,col+1,mat,n,visited,currPath,allPaths);
    //         currPath.pop_back();
    //     }
    //     if(isSafe(row-1,col,mat, n, visited))
    //     {
    //         currPath.push_back('U');
    //         getAllPaths(row-1,col,mat,n,visited,currPath,allPaths);
    //         currPath.pop_back();
    //     }
    //     visited[row][col]=false;
    // }
    // vector<string> findPath(vector<vector<int>> &m, int n) {
    //     vector<string> allPaths;
    //     vector<vector<bool>> visited(n, vector<bool>(n,false));
    //     string currPath="";
    //     getAllPaths(0,0,m,n,visited,currPath,allPaths);
    //     return allPaths;
    // }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends