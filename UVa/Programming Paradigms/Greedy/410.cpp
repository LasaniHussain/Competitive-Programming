#include<bits/stdc++.h>
using namespace std;
int main()
{
	int c,s;
	while(scanf("%d %d",&c,&s)!=EOF)
	{
		vector<int> spec(2*c);
		int i,j;
		for(i=0;i<s;i++)
		cin>>spec[i];
		for(;i<2*c;i++)
		spec[i]=0;
		sort(spec.begin(),spec.end());
		for(i=0,j=c;i<2*c;i++,j++)
		
