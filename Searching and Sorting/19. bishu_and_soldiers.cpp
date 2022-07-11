#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;
//use prefix sum
int main() {
	ll N;
	cin>>N;
	ll S[N];
	for(ll i=0;i<N;i++)
		cin>>S[i];
	ll Q;
	cin>>Q;
	ll B[Q];
	for(ll i=0;i<Q;i++)
	{
		cin>>B[i];
	}
	ll beaten;
	ll cumStrength;
	sort(S,S+N);
	for(ll i=0;i<Q;i++)
	{
		beaten=0;
		cumStrength=0;
		for(ll j=0;j<N;j++)
		{
			if(B[i]>=S[j])
			{
				beaten++;
				cumStrength+=S[j];
			}
			if(B[i]<S[j] || j==N-1)
			{
				cout<<beaten<<" "<<cumStrength<<endl;
				break;
			}
		}
	}
	return 0;
}
	