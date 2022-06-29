// Input:   price[] = {10, 22, 5, 75, 65, 80}
// Output:  87
// Trader earns 87 as sum of 12, 75 
// Buy at 10, sell at 22, 
// Buy at 5 and sell at 80
#include <iostream>
using namespace std;
//1d DP-> Array preprocessing
int main()
{
    int price[] = {10, 22, 5, 75, 65, 80};
    int n=6;
    int minpricesf=price[0];
    int maxprofitist=0;
    int dpl[n];
    for (int i = 0; i < n; i++)
        dpl[i] = 0;
    for(int i=1;i<n;i++)
    {
        if(price[i]<minpricesf)
            minpricesf=price[i];
        maxprofitist=price[i]-minpricesf;
        if(maxprofitist>dpl[i-1])
            dpl[i]=maxprofitist;
        else
            dpl[i]=dpl[i-1];
    }
    int maxpricesf=price[n-1];
    int maxprofitibt=0;
    int dpr[n];
    for (int i = 0; i < n; i++)
        dpr[i] = 0;
    for(int i=n-2;i>=0;i--)
    {
        if(price[i]>maxpricesf)
            maxpricesf=price[i];
        maxprofitibt=maxpricesf-price[i];
        if(maxprofitibt>dpr[i+1])
            dpr[i]=maxprofitibt;
        else
            dpr[i]=dpr[i+1];
    }
    int maxProfit=0;
    for(int i=0;i<n;i++)
        maxProfit=max(maxProfit,dpl[i]+dpr[i]);
    cout<<maxProfit;
    return 0;
}