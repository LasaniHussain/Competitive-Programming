#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int test=1;test<=t;test++)
	{
		int n,i,j;
		cin>>n;
		int *ht=new int[n];
		for(i=0;i<n;i++)
		cin>>ht[i];
		vector<pair<int,int> > lis(n);
		for(i=0;i<n;i++)
		{
			cin>>lis[i].first;
			lis[i].second=lis[i].first;
		}
		vector<pair<int,int> > lds=lis;
		for(i=0;i<n;i++)
		{
			for(j=0;j<i;j++)
			{
				if(ht[j]<ht[i])
				lis[i].second=max(lis[i].second,lis[j].second+lis[i].first);
				else if(ht[j]>ht[i])
				lds[i].second=max(lds[i].second,lds[j].second+lds[i].first);
			}
		}
		int imax=0,dmax=0;
		for(i=0;i<n;i++)
		{
			imax=max(imax,lis[i].second);
			dmax=max(dmax,lds[i].second);
		}
		if(imax>=dmax)
		cout<<"Case "<<test<<". Increasing ("<<imax<<"). Decreasing ("<<dmax<<").";
		else
		cout<<"Case "<<test<<". Decreasing ("<<dmax<<"). Increasing ("<<imax<<").";
		//cout<<imax<<" "<<dmax;
		cout<<"\n";
	}
	return 0;
}
