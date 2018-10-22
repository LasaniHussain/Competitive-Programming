#include<bits/stdc++.h>
using namespace std;
int b,s;
int bach[10001],spins[10001];
int main()
{	int c=1;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(scanf("%d %d",&b,&s)&&b&&s)
	{
		int i,j;
		for(i=0;i<b;i++)
		cin>>bach[i];
		for(i=0;i<s;i++)
		cin>>spins[i];
		sort(bach,bach+b);
		cout<<"Case "<<c<<": ";
		if(b<=s)
		cout<<"0";
		else
		cout<<b-s<<" "<<bach[0];
		cout<<"\n";
		c++;
	}
	return 0;
}
				
