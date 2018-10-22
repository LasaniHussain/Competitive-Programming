#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct stu
{
	ll conts,tp,tt;
	vector< pair<bool,ll> > v(10);
};
struct stu vs[101];
void init()
{
	ll i;
	for(i=1;i<101;i++)
	{
		vs[i].conts=i;
		vs[i].tp=0;
		vs[i].tt=0;
		for(auto c:v)
		{
			c.first=false;
			c.second=0;	
		}	
	}
}
int main()
{
	ll t;
	cin>>t;
	init();
	while(t--)
	{
		ll c,p,t;
		char stat;
		cin>>c>>p>>t>>stat;
		if(stat=='I')
			vs[c].v[p].second+=20;
		else
		{	vs[c].v[p].second+=t;
			vs[c].v[p].first=true;
			vs[c].tt=vs[c].v[p].second;
			vs[c].tp+=1;
		}
	}	
}
