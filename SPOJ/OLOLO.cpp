#include<bits/stdc++.h>
using namespace std;
int main()
{	freopen("in.txt","r",stdin);
	int t,ans=0;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ans^=n;
	}
	cout<<ans;
}
