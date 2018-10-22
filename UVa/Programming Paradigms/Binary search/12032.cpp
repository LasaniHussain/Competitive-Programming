#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
ll arr[100001];
bool try_k(ll k)
{
	
	for(ll i=1;i<=n;i++)
	{
		if(arr[i]-arr[i-1]>k)
		return false;
		if(arr[i]-arr[i-1]==k)
		k--;
	}
	return true;
}
ll solve()
{
	ll l=1,h=10000000,ans=0;
	while(l<=h)
		{
			ll mid=(l+h)/2;
			bool f=try_k(mid);
			if(f)
			{	ans=mid;
				h=mid-1;
			}
			else
			l=mid+1;
		}
	return ans;
}
int main()
{	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ll t,t_c=0;
	cin>>t;
	for(t_c=1;t_c<=t;t_c++)
	{	
		cin>>n;
		for(ll i=1;i<=n;i++)
		cin>>arr[i];
		arr[0]=0;
		//h=max(h,arr[0]-0);
		cout<<"Case "<<t_c<<": "<<solve();
		if(t_c!=t)
		cout<<"\n";
	}
	return 0;
}
