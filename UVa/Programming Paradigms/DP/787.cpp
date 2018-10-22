//Not yet accepted
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll arr[101];
int main()
{
	int x;
	while(scanf("%lld",&arr[0])==1)
	{
		int n=1;
		while(true)
		{
			cin>>arr[n];
			if(arr[n]==-999999)
			break;
			n++;
		}
		ll ma=-999999,r;
		for(ll i=0;i<n;i++)
		{	r=1;
			for(ll j=i;j<n;j++)
			{
				r*=arr[j];
				ma=max(ma,r);
			}
		}
		cout<<ma<<"\n";
	}
	return 0;
}
