#include<iostream>
#include<algorithm>
using namespace std;
bool isPossible(int X[],int curr_min,int N, int M)
{
    int wood_coll=0;
    for(int i=0;i<N;i++)
    {
        if(curr_min<=X[i])
            wood_coll+=X[i]-curr_min;
        if(wood_coll>=M)
            return true;
    }
    return false;
}
int main()
{
    int N,M;
    cin>>N>>M;
    int X[N];
    for(int i=0;i<N;i++)
        cin>>X[i];
    sort(X,X+N);
    int l=0,h=X[N-1],mid;
    int result;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(isPossible(X,mid,N,M))
        {
            result=mid;
            l=mid+1;
        }
        else
            h=mid-1;
    }
    cout<<result<<endl;
    return 0;
}