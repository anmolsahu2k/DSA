#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> res{1};
    res[0]=1;
    int f = 35,x,carry,prod, i;
    for(x=1;x<=f;x++)
    {
        carry=0;
        for(i=0;i<res.size();i++)
        {
            prod=res[i]*x+carry;
            carry=prod/10;
            res[i]=prod%10;
        }
        while (carry)
        {
            res.push_back(carry%10);
            carry = carry/10;
        }
    }
    
    for(int i:res)
    {
        cout<<i<<endl;
    }
    return 0;
}
//use set for O(n) time complexity