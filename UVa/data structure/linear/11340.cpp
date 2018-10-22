#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;ll count[256]={0},cost[256]={0};
		cin>>n;
		while(n--)
		{
			char c;ll cs;
			cin>>c>>cs;
			cost[c]=cs;
		}
		ll m;
		cin>>m;
		m++;
		//cout<<m<<"\n";
		while(m--)
		{
			string s;
			getline(cin,s);
			//cout<<s<<"\n";
			for(auto c:s)
			count[c]++;
		}
		/*cout<<"     count "<<"  "<<"cost "<<"\n";
		for(ll i=0;i<256;i++)
		{
			if(count[i]!=0)
			cout<<i<<" "<<(char)i<<"  "<<count[i]<<"   "<<cost[i]<<"\n";	
		}
		cout<<"\n";*/
		double tc=0;
		for(ll i=0;i<256;i++)
		tc+=count[i]*cost[i];
		printf("%0.2lf$\n",tc/100);
	}
	return 0;
}
