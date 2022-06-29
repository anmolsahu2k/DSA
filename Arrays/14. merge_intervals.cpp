#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
        vector<vector<int>> intervals={{1,3},{2,6},{8,10},{15,18}};
        vector<vector<int>> merged;
        sort(intervals.begin(),intervals.end());
        merged.push_back(intervals[0]);
        for(int i=0;i<intervals.size();i++)
        {
            
            if(intervals[i][0]<=merged.back()[1])
            {
                merged.back()[1]=max(merged.back()[1],intervals[i][1]);
            }
            else
            {
                merged.push_back(intervals[i]);
            }
        }
        for (vector<int> vect1D : merged)
        {
            for (int x : vect1D)
            {
                cout << x << " ";
            }   
            cout << endl;
        }
        return 0;
}