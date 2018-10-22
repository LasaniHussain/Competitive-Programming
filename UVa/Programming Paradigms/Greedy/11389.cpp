#include<bits/stdc++.h>
using namespace std;
int main()
{	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,d,r;
	while(scanf("%d %d %d",&n,&d,&r)&&n)
	{
		int *mor=new int[n],*eve=new int[n],i,j;
		for(i=0;i<n;i++)
		cin>>mor[i];
		for(i=0;i<n;i++)
		cin>>eve[i];
		int s=0;
		sort(mor,mor+n);
		sort(eve,eve+n);
		for(i=0,j=n-1;i<n;i++,j--)
		{
			if(mor[i]+eve[j]>d)
			s+=(mor[i]+eve[j])-d;
		}
		s*=r;
		cout<<s<<"\n";
	}
	return 0;
}
