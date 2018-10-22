#include<bits/stdc++.h>
using namespace std;
#define ll long long int
priority_queue<ll> max_hl;
priority_queue<ll,vector<ll>,greater<ll> > min_hr;
void calc(ll x,ll &med)
{
	if(max_hl.size()>min_hr.size())
	{
		if(x<med)
		{
			min_hr.push(max_hl.top());
			max_hl.pop();
			max_hl.push(x);
		}
		else
		min_hr.push(x);
		med=(max_hl.top()+min_hr.top())/2;
	}
	else if(max_hl.size()==min_hr.size())
	{
		if(x<med)
		{
			max_hl.push(x);
			med=max_hl.top();
		}
		else
		{
			min_hr.push(x);
			med=min_hr.top();
		}
	}
	else
	{
		if(x<med)
		max_hl.push(x);
		else
		{
			max_hl.push(min_hr.top());
			min_hr.pop();
			min_hr.push(x);
		}
		med=(max_hl.top()+min_hr.top())/2;
	}
}
int main()
{	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ll n,med=0;
	while(cin>>n)
	{
		calc(n,med);
		cout<<med<<"\n";
	}
	return 0;
}
