#include<iostream>
#include<algorithm>
using namespace std;
bool isPossible(int R[],int curr_max,int P, int L)
{
    int cnt=0;
    for(int i=0;i<L;i++)
    {
        int time=curr_max;
        int c=0;
        int perprata=R[i];
        int j=1;
        while(time>0)
        {
            time-=R[i]*j;
            if(time>=0)
            {
                c++;
                j++;
            }
        }
        cnt+=c;
        if(cnt>=P)
            return true;
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int P,L;
        cin>>P>>L;
        int R[L];
        for(int i=0;i<L;i++)
            cin>>R[i];
        sort(R,R+L);
        int l=0,h=(P*(P+1)*R[L-1])/2,mid;
        int result;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(isPossible(R,mid,P,L))
            {
                result=mid;
                h=mid-1;
            }
            else
                l=mid+1;
        }
        cout<<result<<endl;
    }
    return 0;
}