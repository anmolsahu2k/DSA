// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool checkCycle(int i, vector<int> adj[], vector<bool> visited, int parent)
    {
        visited[i]=true;
        for(int j=0;j<adj[i].size();j++)
        {
            if(!visited[adj[i][j]])
            {
                if(checkCycle(adj[i][j],adj,visited,i))
                    return true;
            }
            //if the vertex has been already visited and is not parent of current vertex 
            else if(adj[i][j]!=parent)
                return true;
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        //loop only for disconnected graph, to reach and check all vertices
        for(int i=0;i<V;i++)
            if(!visited[i]&&checkCycle(i,adj,visited,-1))
                return true;
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends