// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Similar to Dijkstra
class Solution
{
	public:
	int minKey(vector<int> key,vector<bool> mstSet)
	{
	    int min=INT_MAX;
	    int minVertex;
	    for(int i=0;i<mstSet.size();i++)
	    {
	        if(mstSet[i]==false && key[i]<min)
	        {
	            min=key[i];
	            minVertex=i;
	        }
	    }
	    return minVertex;
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> key(V,INT_MAX);
        vector<bool> mstSet(V,false);
        key[0]=0;
        int ans=0;
        for(int count=0;count<V-1;count++)
        {
            int v=minKey(key,mstSet);
            mstSet[v]=true;
            vector<vector<int>> a=adj[v];
            for(int i=0;i<a.size();i++)
            {
                if(mstSet[a[i][0]]==false && a[i][1]<key[a[i][0]])
                    key[a[i][0]]=a[i][1];
            }
        }
        for(int i=0;i<V;i++)
            if(key[i]!=INT_MAX)
                ans+=key[i];
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends