// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        int i=0;
        int start=0;
        int balance=0;
        while(i<n)
        {
            for(i=start;i<n;i++)
            {
                if(p[i].petrol>=p[i].distance)
                {
                    start=i;
                    break;
                }
            }
            for(i=start;i<n;i++)
            {
                balance+=p[i].petrol-p[i].distance;
                if(balance<0)
                {
                    start=i+1;
                    balance=0;
                }
            }
        }
        if(balance<0)
            return -1;
        for(i=0;i<start;i++)
        {
            balance+=p[i].petrol-p[i].distance;
            if(balance<0)
                return -1;
        }
        return start;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends