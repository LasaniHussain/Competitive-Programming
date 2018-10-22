#include<bits/stdc++.h>
using namespace std;
int V[1001],W[1001],t,g,n,mw,ans,memo[1001][31];
int value(int index,int w)
{
	if(index==n||w==0)
	return 0;
	if(memo[index][w]!=-1)
	return memo[index][w];
	if(W[index]>w)
	return memo[index][w]=value(index+1,w);
	else
	return memo[index][w]=max(value(index+1,w),V[index]+value(index+1,w-W[index]));
} 
int main()
{	cin>>t;
	while(t--)
	{	memset(memo,-1,sizeof(memo));
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>V[i]>>W[i];
		cin>>g;
		ans=0;
		while(g--)
		{
			cin>>mw;
			ans+=value(0,mw);
		}
		cout<<ans;
		//if(t)
		cout<<"\n";
	}
	return 0;
}
	
