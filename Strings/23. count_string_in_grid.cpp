// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
	int countString(vector<vector<char>>grid, string word){
	    int c=0;
		//to check in all  directions
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
                            c++;
                        }
	                }
	            }
	        }
	    }
	    return c;
	}

// { Driver Code Starts.
int main(){
	vector<vector<char>>a ={
            {'c','b','c','e','b','a','e','a','c'},
            {'a','c','d','d','d','a','e','d','a'},
            {'b','c','c','e','d','d','a','b','a'},
            {'b','b','d','d','e','a','c','d','c'},
            {'e','d','b','e','b','b','c','e','b'}
           };
    string str= "cda";
    cout<<countString(a,str);

	return 0;
}  // } Driver Code Ends