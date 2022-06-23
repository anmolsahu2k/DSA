// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    //https://leetcode.com/problems/lru-cache/discuss/45912/Clean-Short-Standard-C%2B%2B-solution-NOT-writing-C-in-C%2B%2B-like-all-other-lengthy-ones
    //NOT WORKING ?????
    private:
        

    public:
    int maxCap;
    queue<pair<int,int>> q;
    map<int, int> mp;
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        maxCap=cap;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if(q.empty())
            return -1;
        if(mp.find(key)==mp.end())
            return -1;
        return mp[key];
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here   
        if(q.size()==maxCap)
        {
            if(mp[q.front().first]==q.front().second)
                mp[q.front().first]=-1;
            q.pop();
        }
        q.push(make_pair(key,value));
        mp[key]=value;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends