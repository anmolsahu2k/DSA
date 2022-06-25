// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        sort(arr,arr+n);
        vector<int> v1;
        vector<int> v2;
        string res;
        int i,sum,carry=0;
        for(i=0;i<n;i+=2)
            v1.push_back(arr[i]);
        for(i=1;i<n;i+=2)
            v2.push_back(arr[i]);
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        i=0;
        while(i<v1.size()&&i<v2.size())
        {
            sum=v1[i]+v2[i]+carry;
            res.push_back('0'+sum%10);
            carry=sum/10;
            i++;
        }
        while(i<v1.size())
        {
            sum=v1[i]+carry;
            res.push_back('0'+sum%10);
            carry=sum/10;
            i++;
        }
        while(i<v2.size())
        {
            sum=v2[i]+carry;
            res.push_back('0'+sum%10);
            carry=sum/10;
            i++;
        }
        if(carry!=0)
            res.push_back('0'+carry);
        while(res.back()=='0')
            res.pop_back();
        reverse(res.begin(),res.end());
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends