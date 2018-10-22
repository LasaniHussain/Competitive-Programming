#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ll n;
	while(cin>>n)
	{	//cout<<"inside while\n";
		if(n==0)
		break;
		multiset<ll> mt;
		ll i,c=0,j;
		for(i=0;i<n;i++)
		{	//cout<<"inside for\n";
			ll k;
			cin>>k;
			for(j=0;j<k;j++)
			{
				ll x;
				cin>>x;
				mt.insert(x);
			}
			/*cout<<"set elements : ";
			for(auto c:mt)
			cout<<c<<" ";
			cout<<"\n";*/
			auto it=mt.end();
			it--;
			//cout<<"min : "<<*(mt.begin())<<" max : "<<*(it)<<"\n";
			c+=abs(*mt.begin()-*it);
			mt.erase(mt.begin());
			mt.erase(it);
		}
		cout<<c<<"\n";
	}
	return 0;
}
