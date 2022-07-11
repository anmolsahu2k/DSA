#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isPossible(int X[],int curr_min,int N, int C)
{
    int cow_acc=1;
    int temp=X[0];
    for(int i=1;i<N;i++)
    {
        if(X[i]-temp>=curr_min)
        {
            temp=X[i];
            cow_acc++;
        }
    }
    if(cow_acc<C)
        return false;
    return true;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N,C;
        cin>>N>>C;
        int X[N];
        for(int i=0;i<N;i++)
            cin>>X[i];
        sort(X,X+N);
        int l=1,h=X[N-1]-X[0],mid;
        int result;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(isPossible(X,mid,N,C))
            {
                result=mid;
                l=mid+1;
            }
            else
                h=mid-1;
        }
        cout<<result<<endl;
    }
    return 0;
}