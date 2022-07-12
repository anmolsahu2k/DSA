// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int> indegree(N,0);
	    for(int i=0;i<prerequisites.size();i++)
	        indegree[prerequisites[i].second]++;
	    vector<int> t(N,0);
	    queue<int> q;
	    int cnt=0;
	    vector<int> adj[N];
	    for(int i=0;i<prerequisites.size();i++)
	        adj[prerequisites[i].first].push_back(prerequisites[i].second);
	    for(int i=0;i<N;i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	            t[i]=1;
	        }
	    }
	    while(!q.empty())
	    {
	        int v=q.front();
	        q.pop();
	        for(int j=0;j<adj[v].size();j++)
	        {
	            indegree[adj[v][j]]--;
	            if(indegree[adj[v][j]]==0)
	            {
	                q.push(adj[v][j]);
	                t[adj[v][j]]=t[v]+1;
	            }
	        }
	        cnt++;
	    }
        //if the graph has a cycle or it is disconnected
	    if(cnt!=N)
	        return false;
        return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends