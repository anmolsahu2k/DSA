// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        if(str1.length()!=str2.length())
            return 0;
        int arr[MAX_CHARS]={0};
        for(int i=0;i<str1.length();i++)
        {
            if(arr[int(str1[i])]!=0)
            {
                if(arr[int(str1[i])]!=int(str2[i]))
                    return 0;
            }
            else
            {
                arr[int(str1[i])]=int(str2[i]);
            }
        }
        int arr2[MAX_CHARS]={0};
        for(int i=0;i<str2.length();i++)
        {
            if(arr2[int(str2[i])]!=0)
            {
                if(arr2[int(str2[i])]!=int(str1[i]))
                    return 0;
            }
            else
            {
                arr2[int(str2[i])]=int(str1[i]);
            }
        }
        return 1;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends