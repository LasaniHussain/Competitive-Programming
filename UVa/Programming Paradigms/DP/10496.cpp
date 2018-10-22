#include<bits/stdc++.h>
using namespace std;
int t,n,xlen,ylen,x[11],y[11],dist[11][11],memo[11][1<<11];
int tsp(int pos,int mask)
{
	if(mask==(1<<(n+1))-1)
	return dist[pos][0];
	if(memo[pos][mask]!=-1)
	return memo[pos][mask];
	int res=INT_MAX;
	for(int next=0;next<=n;next++)
		if(next!=pos&&!(mask&(1<<next)))
			res=min(res,dist[pos][next]+tsp(next,mask|(1<<next)));
	return memo[pos][mask]=res;
}
int main()
{
	cin>>t;
	while(t--)
	{	cin>>xlen>>ylen;
		cin>>x[0]>>y[0];
		cin>>n;
		for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				dist[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]);
		memset(memo,-1,sizeof(memo));
		int ans=tsp(0,1);
		cout<<"The shortest path has length "<<ans<<"\n";
		for(int i=0;i<=n;i++)
		{	for(int j=0;j<=(1<<(n+1)-1);j++)
			cout<<memo[i][j]<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
