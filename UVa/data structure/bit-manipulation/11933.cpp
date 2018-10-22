#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	ll n;
	while(cin>>n)
	{
		if(n==0)
		break;
		bitset<31> bt(n);
		bitset<31> odd(0);
		bitset<31> even(0);
		int alt=1;
		for(int i=0;i<31;i++)
		{
			if(bt.test(i))
			{
				if(alt>0)
					odd.set(i);
				else
					even.set(i);
				alt*=-1;
			}
		}
		cout<<odd.to_ulong()<<" "<<even.to_ulong()<<"\n";
	}
}
