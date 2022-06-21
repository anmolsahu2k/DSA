// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        stack<vector<int>> st;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++)
        {
            if(st.empty())
                st.push(intervals[i]);
            else
            {
                if(intervals[i][0]>st.top()[1])
                    st.push(intervals[i]);
                else if(st.top()[1]<intervals[i][1])
                    st.top()[1]=intervals[i][1];
            }
        }
        intervals.clear();
        while(!st.empty())
        {
            intervals.push_back(st.top());
            st.pop();
        }
        reverse(intervals.begin(),intervals.end());
        return intervals;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends