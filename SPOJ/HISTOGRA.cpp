#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{	//freopen("in.txt","r",stdin);
	ll n;
	while(scanf("%lld",&n)&&n)
	{
		ll *arr=new ll[n],i;
		for(i=0;i<n;i++)
		cin>>arr[i];
		ll ma=0;
		i=0;
		stack<ll> st;
		while(i<n)
		{	
			if(st.empty()||arr[st.top()]<=arr[i])
			st.push(i++);
			else
			{
				ll v=st.top();
				st.pop();
				ll ar=arr[v]*(st.empty()?i:i-st.top()-1);
				//cout<<ar<<"\n";
				ma=max(ma,ar);
			}
		}
		while(!st.empty())
		{
			
				ll v=st.top();
				st.pop();
				ll ar=arr[v]*(st.empty()?i:i-st.top()-1);
				ma=max(ma,ar);
		}
		cout<<ma<<"\n";
	}
	return 0;
}
		
