#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		map<string,int> mp;
		string s,s1,s2,s3,s4,s5,s6;
		while(n--)
		{
			cin>>s1>>s2>>s3>>s4>>s5>>s6;
			s=s1+s2+s3+s4+s5+s6;
			mp[s]++;
		}
		for(auto c:mp)
		{	cout<<c.first[0]<<c.first[1]<<" ";
			int i,j;
			for(i=2;i<10;i++)
			cout<<c.first[i];
			cout<<" ";
			for(j=0;j<4;j++)
			{	int cnt=i+4;
				for(;i<cnt;i++)
				cout<<c.first[i];
				cout<<" ";
			}
			cout<<c.second;
			//if((it+1)!=mp.end())
			cout<<"\n";
		}
		if(t)
		cout<<"\n";
	}
	return 0;
}
