// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool checkCyclic(int i, vector<int> adj[],vector<bool> &visited, vector<bool> &recStack)
    {
        visited[i]=true;
        recStack[i]=true;
        for(int j=0;j<adj[i].size();j++)
        {
            //don't check cycle if already visited
            if(visited[adj[i][j]]==false && checkCyclic(adj[i][j],adj,visited,recStack)==true)
                return true;
            //if already visited check recursion stack
            else if(recStack[adj[i][j]]==true)
                return true;
        }
        //after coming out of recursion statement, remove from recursion stack
        recStack[i]=false;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        vector<bool> recStack(V,false);
        //for diconnected graph, loop to check for every vertex
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false&&checkCyclic(i,adj,visited,recStack)==true)
                return true;
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends