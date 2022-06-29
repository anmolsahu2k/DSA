#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v = {88, 11,3, 12, 73};
    int c=0;
    int i=0,j=v.size()-1;
    while(i<j)
    {
        if(v[i]==v[j])
        {
            i++;
            j--;
        }
        else if(v[i]<v[j])
        {
            i++;
            v[i]+=v[i-1];
            c++;
        }
        else
        {
            j--;
            v[j]+=v[j+1];
            c++;
        }
    }
    cout<<c;
    return 0;
}