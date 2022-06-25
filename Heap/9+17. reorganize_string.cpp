// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

 // } Driver Code Ends
class Solution
{
    public:
    struct Key{
        int freq;
        char ch;
        bool operator<(const Key &k) const{
            return freq<k.freq;
        }
    };
    string rearrangeString(string str)
    {
        map<char, int> mp;
        priority_queue<Key>pq;
        string res="";
        for(int i=0;i<str.length();i++)
            mp[str[i]]++;
        for(auto itr=mp.begin();itr!=mp.end();itr++)
            pq.push(Key{itr->second,itr->first});
        Key prev{-1,'#'};
        while(!pq.empty())
        {
            Key x=pq.top();
            pq.pop();
            res+=x.ch;
            x.freq--;
            if(prev.freq>0)
                pq.push(prev);
            prev=x;
        }
        if(res.length()==str.length())
            return res;
        else
            return "-1";
    }
    
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}  // } Driver Code Ends