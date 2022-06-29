#include <iostream>
#include <string>
using namespace std;
int countBinarySubstrings(string s) {
        int curr=1,prev=0,res=0;
        for(int i=1;i<s.length();i++)
        {
            //no. of consecutive 1s/0s in current cluster (001100111)
            if(s[i]==s[i-1])
                curr++;
            else
            {
                //add min of current cluster and previous cluster
                //for any possible substrings with 1 and 0 grouped consecutively,
                //the number of valid substring will be the minimum number of 0 and 1(curr and prev)
                res+=min(curr,prev);
                //now prev is curr
                prev=curr;
                //curr is 1
                curr=1;
            }
        }
        return res+min(curr,prev);
    }
int main()
{
    cout<<countBinarySubstrings("001100111");
    return 0;

}