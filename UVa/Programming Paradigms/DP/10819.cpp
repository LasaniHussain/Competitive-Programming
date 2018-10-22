#include<bits/stdc++.h>
using namespace std;
int W[101],V[101],m,dp[101][10201],n;
int value(int idx,int w)
{	if(w>m&&m<1800)
	return INT_MIN;
	if(w>m+200)
	return INT_MIN;
	if(idx==n)
	{	if(w>m&&w<=2000)
		return INT_MIN;
		return 0;
	}
	if(dp[idx][w]!=-1)
	return dp[idx][w];
	//return max(sel,not_sel);
	return dp[idx][w]=max(value(idx+1,w),V[idx]+value(idx+1,w+W[idx]));
}
int main()
{
	while(cin>>m>>n)
	{	memset(dp,-1,sizeof(dp));	
		for(int i=0;i<n;i++)
		cin>>W[i]>>V[i];
		cout<<value(0,0)<<"\n";
	}
	return 0;
}				

