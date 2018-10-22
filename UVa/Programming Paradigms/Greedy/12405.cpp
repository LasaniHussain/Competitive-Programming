#include<bits/stdc++.h>
using namespace std;
int main()
{	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t,t_c=1;
	cin>>t;
	while(t_c<=t)
	{
		int n,i,ans=0;
		cin>>n;
		string s;
		cin>>s;
		i=0;
		while(i<n)
		{
			if(s[i]=='.')
			{
				ans++;
				//cout<<"found at pos = "<<i<<"\n";
				i+=3;
			}
			else
			i++;
		}
		cout<<"Case "<<t_c<<": "<<ans<<"\n";
		t_c++;
	}
	return 0;
}				
