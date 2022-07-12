// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool isSafe(int x, int y, vector<vector<char>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(x<n&&y<m&&x>=0&&y>=0&&grid[x][y]=='1')
            return true;
        return false;
    }
    void dfs(int i, int j,vector<vector<char>>& grid, vector<vector<bool>> &visited)
    {
        visited[i][j]=true;
        static vector<int> dx={1,-1,1,-1,0,0,-1,1};
        static vector<int> dy={-1,1,1,-1,1,-1,0,0};
        for(int k=0;k<8;k++)
        {
            int x=i+dx[k];
            int y=j+dy[k];
            if(isSafe(x,y,grid)&&!visited[x][y])
                dfs(x,y,grid,visited);
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]=='1' && !visited[i][j])
                {
                    dfs(i,j,grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends