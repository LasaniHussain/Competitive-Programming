#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > v(41);
int m,s,t;
int change(int val)
{
	if(val<0)
	return 0;
	if(val<0)
	return INT_MAX;
	int res=INT_MAX;
	for(int i=0;i<m;i++)
	{
		if(v[i].first+v[i].second<=val)
		res=max(res,change(val-v[i].first-v[i].second)+1);
	}
	return res;
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>m>>s;
		cout<<m<<" "<<s<<"\n";
		for(int i=0;i<m;i++)
		cin>>v[i].first>>v[i].second;
		int ans=change(s);
		if(ans==0||ans==INT_MAX)
		cout<<"IMPOSSIBLE";
		else
		cout<<ans;
		if(t)
		cout<<"\n";
	}
	return 0;
}
		
