#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,m,k,memo[52][52];
ll ways(ll val,ll way)
{
	if(way==1)
	{	if(val>m)
		return 0;
		return 1;
	}
	if(memo[val][way]!=-1)
	return memo[val][way];
	ll ans=0;
	for(ll i=1;i<=m;i++)
	{	if(val-i<=0)
		break;
		ans+=ways(val-i,way-1);
	}
	return memo[val][way]=ans;
}
int main()
{	
	while(cin>>n>>k>>m)
	{	memset(memo,-1,sizeof(memo));
		cout<<ways(n,k)<<"\n";
	}
	//cout<<"\n";
	return 0;
}
