#include<vector>
using namespace std;

class Solution {
public:

    //USING adjacency list(better time and space complexity)
    void dfs(int i, vector<bool> &visited, vector<int>adj[])
    {
        visited[i]=true;
        for(int j=0;j<adj[i].size();j++)
        {
            if(!visited[adj[i][j]])
                dfs(adj[i][j],visited,adj);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edgeCount=connections.size();
        if(edgeCount<n-1)
            return -1;
        int componentsCount=0;
        vector<bool> visited(n,false);
        vector<int> adj[n];
        for(int i=0;i<connections.size();i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,visited,adj);
                componentsCount++;
            }
        }
        return componentsCount-1;
        
    }
    //USING adjacency matrix(Memeory limit exceeds)
    // void dfs(int i, vector<bool> &visited, vector<vector<int>>& adj, int n)
    // {
    //     visited[i]=true;
    //     for(int j=0;j<n;j++)
    //     {
    //         if(adj[i][j]==1&&!visited[j])
    //             dfs(j,visited,adj,n);
    //     }
    // }
    // int makeConnected(int n, vector<vector<int>>& connections) {
    //     int edgeCount=connections.size();
    //     int componentsCount=0;
    //     vector<bool> visited(n,false);
    //     vector<vector<int>> adj(n,vector<int>(n,0));
    //     for(int i=0;i<connections.size();i++)
    //     {
    //         adj[connections[i][0]][connections[i][1]]=1;
    //         adj[connections[i][1]][connections[i][0]]=1;
    //     }
    //     for(int i=0;i<n;i++)
    //     {
    //         if(!visited[i])
    //         {
    //             dfs(i,visited,adj,n);
    //             componentsCount++;
    //         }
    //     }
    //     if(edgeCount>=n-1)
    //         return componentsCount-1;
    //     else
    //         return -1;
    // }
};