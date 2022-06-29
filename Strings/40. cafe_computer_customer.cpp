#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    string S="ABCBCA";
    int n=1;
    //customers present in the cafe
    int k=0;
    int c=0;
    unordered_map<char,int> mp;
    for(int i=0;i<S.length();i++)
    {
        //if customer found decrement customers present in cafe
        if(mp.find(S[i])!=mp.end())
        {
            mp[S[i]]--;
            k--;
        }
        else
        {
            mp.insert({S[i],1});
            k++;
            //customers who enter and don't have computers available should be counted
            if(k>n)
                c++;
        }
    }
    cout<<c;
    return 0;
}