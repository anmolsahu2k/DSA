#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int t;
	cin>>t;
	int N,Q,A,B,K;
	while(t--)
	{
		cin>>N>>Q;
        vector<vector<int>> arr(N,vector<int>(2));
        vector<vector<int>> merged;
		for(int i=0;i<N;i++)
		{
			cin>>arr[i][0]>>arr[i][1];
		}		
		vector<int> K(Q);
		for(int i=0;i<Q;i++)
		{
			cin>>K[i];
		}
		sort(arr.begin(),arr.end());
        for(int i=0;i<N;i++)
        {
            if(merged.empty() || merged.back()[1]<arr[i][0])
                merged.push_back(arr[i]);
            else    
                merged.back()[1]=arr[i][1];
        }
        sort(K.begin(),K.end());
        int j=0;
        int effectiveQuery=K[j];
        int flag=0;
        for(int i=0;i<Q;i++)
        {
			flag=0;
            for(int j=0;j<merged.size();j++)
            {
                if (K[i] <= (merged[j][1]- merged[j][0] + 1))
                {
                    cout<<(merged[j][0] + K[i] - 1)<<endl;
					flag=1;
                    break;
                }
                K[i] = K[i] - (merged[j][1]- merged[j][0] + 1);
            }
            if (flag==0)
                cout<<-1<<endl;
        }
	}
	return 0;
}