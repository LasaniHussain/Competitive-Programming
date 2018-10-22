#include<bits/stdc++.h>
using namespace std;
int main()
{	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	string s;
	while(true)
	{
		cin>>s;
		if(s[0]=='#')
		break;
		if(next_permutation(s.begin(),s.end()))
		cout<<s<<"\n";
		else
		cout<<"No Successor\n";
	}
	return 0;
}
