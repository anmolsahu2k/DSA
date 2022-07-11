// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum sum
int findMaxSum(vector<int> arr, int N)
{
	// Declare dp array
	int dp[N][2];
	if (N == 1) {
		return arr[0];
	}

	// Initialize the values in dp array
  	//arr[0] excluded
	dp[0][0] = 0;
  	//arr[0] included->sum(dp[0][1]=arr[0])
	dp[0][1] = arr[0];

	// Loop to find the maximum possible sum
	for (int i = 1; i < N; i++) {
      	//arr[i-1] is excluded and arr[i] included
		dp[i][1] = dp[i - 1][0] + arr[i];
      	//arr[i] excluded and maximum of sum when arr[i-1]
     	// incuded and excluded
		dp[i][0] = max(dp[i - 1][1],
					dp[i - 1][0]);
	}
	// Return the maximum sum
	return max(dp[N - 1][0], dp[N - 1][1]);
}
// int FindMaxSum(vector<int> arr, int n)
// {
//  //initially	
// 	int incl = arr[0];
//  int excl = 0;
// 	int excl_new;
// 	int i;

// 	for (i = 1; i < n; i++) {
// 		// Current max of arr[i-1] included and excluded,
//     	// excluding arr[i]
// 		excl_new = max(incl, excl);
// 		// incl->including i and exluding previous(i-1)
// 		incl = excl + arr[i];
//     	//excl->excluding i and including previous(i-1)
// 		excl = excl_new;
// 	}

// 	// Return max of incl->including arr[n-1] 
//  //and excl->excluding arr[n-1]
// 	return max(incl, excl);
// }

// Driver Code
int main()
{
	// Creating the array
	vector<int> arr = { 5, 5, 10, 100, 10, 5 };
	int N = arr.size();

	// Function call
	cout << findMaxSum(arr, N) << endl;
	return 0;
}
