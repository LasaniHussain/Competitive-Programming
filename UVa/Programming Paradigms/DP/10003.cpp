#include<bits/stdc++.h>
using namespace std;
int l,A[52],memo[52][52],n;
int cuts(int left,int right)
{
	if(left+1==right)
	return 0;
	if(memo[left][right]!=-1)
	return memo[left][right];
	int ans=INT_MAX;
	for(int i=left+1;i<right;i++)
		ans=min(ans,cuts(left,i)+cuts(i,right)+A[right]-A[left]);
	return memo[left][right]=ans;
}
int main()
{
	while(cin>>l&&l!=0)
	{	//cout<<l<<"\n";
		cin>>n;
		A[0]=0;
		int i;
		for(i=1;i<=n;i++)
		cin>>A[i];
		A[i]=l;
		for(i=0;i<n+2;i++)
		//cout<<A[i]<<" ";
		memset(memo,-1,sizeof(memo));
		cout<<"The minimum cutting is "<<cuts(0,n+1)<<".\n";
	}
	return 0;
}
