#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,q,arr[201],d,m,test=1,dp[201][11][21];
ll func(ll idx,ll cnt,ll sum)
{
	if(cnt==m)
	{
		if(sum==0)
		return 1;
		return 0;
	}
	if(idx>=n)
	return 0;
	if(dp[idx][cnt][sum]!=-1)
	return dp[idx][cnt][sum];
	ll tmp=sum+arr[idx];
	tmp%=d;
	if(tmp<0)
	tmp+=d;
	return dp[idx][cnt][sum]=func(idx+1,cnt+1,tmp)+func(idx+1,cnt,sum%d);
}	
int main()
{	test=1;
	while(scanf("%lld %lld",&n,&q)&&n!=0&&q!=0)
	{	//cout<<" n = "<<n<<" q = "<<q<<"\n";
		
		for(int i=0;i<n;i++)
		cin>>arr[i];
		/*cout<<"array :\n";
		for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
		cout<<"\n";*/
		cout<<"SET "<<test<<":\n";
		for(int query=1;query<=q;query++)
		{	cin>>d>>m;
			memset(dp,-1,sizeof(dp));
			cout<<"QUERY "<<query<<": ";
			cout<<func(0,0,0)<<"\n";
		}
		//cout<<"input "<<test<<" scanned\n";
		test++;
	}
	return 0;
}
