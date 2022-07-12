// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	int minDist(vector<int> dist, vector<bool> sptSet)
	{
	    int minD=INT_MAX;
	    int minIndex;
	    for(int u=0;u<dist.size();u++)
	    {
	        if(!sptSet[u]&&minD>dist[u])
	        {
	            minD=dist[u];
	            minIndex=u;
	        }
	    }
	    return minIndex;
	}
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V,INT_MAX);
        dist[S]=0;
        vector<bool> sptSet(V,false);
        //loop for V-1 vertices since src vertex distance is already known
        for(int count=1;count<V;count++)
        {
            //vertex with min dist not included in sptSet
            int u=minDist(dist,sptSet);
            sptSet[u]=true;
            //Neighbors of u and the weight of edges between u and them[0->({1,1},{2,6})]
            vector<vector<int>> neighbors=adj[u];
            for(int i=0;i<neighbors.size();i++)
            {
                if(!sptSet[neighbors[i][0]]&&dist[u]!=INT_MAX&&dist[u]+neighbors[i][1]<dist[neighbors[i][0]])
                    dist[neighbors[i][0]]=dist[u]+neighbors[i][1];
            }
        }
        return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends