// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    vector<vector<int>> coordinates;
	    vector<int> X={-1,1,0,0,1,-1,1,-1};
	    vector<int> Y={0,0,1,-1,1,-1,-1,1};
	    int n=grid.size();
	    int m=grid[0].size();
	    int rd,cd,k;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==word[0])
                {
	                for(int dir=0;dir<=7;dir++)
	                {
	                    rd=i+X[dir];
	                    cd=j+Y[dir];
	                    k=1;
                        while(rd>=0 && cd>=0 && rd<n && cd<m && k<word.length() && grid[rd][cd]==word[k])
                        {
                            rd+=X[dir];
                            cd+=Y[dir];
                            k++;
                        }
                        if(k==word.length())
                        {
                            coordinates.push_back({i,j});
                            break;
                        }
	                }
	            }
	        }
	    }
	    return coordinates;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}  // } Driver Code Ends