#include<bits/stdc++.h>
using namespace std;
int n,k,memo[101][101];
#define mod 1000000
int ways(int n,int k)
{
	if(k==1)
	return 1;
	if(memo[n][k]!=-1)
	return memo[n][k];
	int res=0;
	for(int i=0;i<=n;i++)
	res=(res+ways(n-i,k-1))%mod;
	return memo[n][k]=res;
}
int main()
{	memset(memo,-1,sizeof(memo));
	while(cin>>n>>k&&n&&k)
		cout<<ways(n,k)<<"\n";
	return 0;
}
