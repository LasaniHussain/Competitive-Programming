#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll memo[5][30001],val,V[5]={1,5,10,25,50},N=5;
ll ways(ll ind,ll v)
{	//cout<<"ways("<<ind<<","<<v<<")\n";	
	if(v==0)
	{	//cout<<"1 returned for val=0 ind= "<<ind<<"\n";
		return 1;
	}
	if(v<0||ind==N)
	return 0;
	if(memo[ind][v]!=-1)
	return memo[ind][v];
	return memo[ind][v]=ways(ind+1,v)+ways(ind,v-V[ind]);
}
int main()
{	memset(memo,-1,sizeof memo);
	while(scanf("%lld", &val) != EOF)
	{	//cout<<val<<"\t";
		ll ans=ways(0,val);
		if(ans==1)
		cout<<"There is only 1 way to produce "<<val<<" cents change.\n";
		else
		cout<<"There are "<<ans<<" ways to produce "<<val<<" cents change.\n";
	}
	return 0;
}	
