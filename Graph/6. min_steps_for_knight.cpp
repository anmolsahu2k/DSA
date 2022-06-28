// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    struct cell {
        int xCoordinate;
        int yCoordinate;
        int stepCount;
        cell() {}
        cell(int x, int y, int dist) {
            xCoordinate = x;
            yCoordinate = y;
            stepCount = dist;
        }
    };
    bool isValid(int x, int y, int n) {
        if (x >= 1 && x <= n && y >= 1 && y <= n) {
            return true;
        }
        return false;
    }
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    vector<int> dx={2,-2,-2,2,1,-1,-1,1};
	    vector<int> dy={1,1,-1,-1,2,2,-2,-2};
	    queue<cell>q;
	    vector<vector<bool>>visited(N+1,vector<bool>(N+1,false));
	    q.push(cell(KnightPos[0],KnightPos[1],0));
	    visited[KnightPos[0]][KnightPos[1]]=true;
	    cell t;
	    while(!q.empty())
	    {
	        int x=q.front().xCoordinate;
	        int y=q.front().yCoordinate;
	        int dist=q.front().stepCount;
	        q.pop();
	        if(x==TargetPos[0]&&y==TargetPos[1])
	            return dist;
	        for(int i=0;i<8;i++)
	        {
	            int row=x+dx[i];
	            int col=y+dy[i];
	            if(isValid(row,col,N)&&!visited[row][col])
	            {
	                visited[row][col]=true;
	                q.push(cell(row,col,dist+1));
	            }
	        }
	    }
	    return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends