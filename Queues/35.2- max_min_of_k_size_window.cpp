// C++ program to find sum of all minimum and maximum
// elements Of Sub-array Size k.
#include<bits/stdc++.h>
using namespace std;

// Returns sum of min and max element of all subarrays
// of size k
int SumOfKsubArray(int arr[] , int n , int k)
{
	deque<int> S,G;
    int sum=0;
    for(int i=0;i<k;i++)
    {
        while(!S.empty()&&arr[S.back()]>=arr[i])
            S.pop_back();
        S.push_back(i);
        while(!G.empty()&&arr[G.back()]<=arr[i])
            G.pop_back();
        G.push_back(i);
    }
    for(int i=k;i<n;i++)
    {
        sum+=arr[G.front()]+arr[S.front()];
        if(S.front()<i+1-k)
            S.pop_front();
        if(G.front()<i+1-k)
            G.pop_front();
        while(!S.empty()&&arr[S.back()]>=arr[i])
            S.pop_back();    
        S.push_back(i);
        while(!G.empty()&&arr[G.back()]<=arr[i])
            G.pop_back();
        G.push_back(i);    
    }
    sum+=arr[G.front()]+arr[S.front()];
    return sum;
}

// Driver program to test above functions
int main()
{
	int arr[] = {2, 5, -1, 7, -3, -1, -2} ;
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	cout << SumOfKsubArray(arr, n, k) ;
	return 0;
}
