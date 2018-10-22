#include<bits/stdc++.h>
using namespace std;
int main()
{	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,m;
	while(scanf("%d %d",&n,&m)&&n&&m)
	{
		int *head=new int[n];
		int *knight=new int[m];
		int i;
		for(i=0;i<n;i++)
		cin>>head[i];
		for(i=0;i<m;i++)
		cin>>knight[i];
		if(m<n)
		cout<<"Loowater is doomed!";
		else
		{	
			int cost=0,d=0,k=0;
			sort(knight,knight+m);
			sort(head,head+n);
			while(d<n&&k<m)
			{
				while(head[d]>knight[k]&&k<m)
				k++;
				if(k==m)
				break;
				cost+=knight[k];
				k++;
				d++;
			}
			if(d==n)
			cout<<cost;
			else
			cout<<"Loowater is doomed!";
		}
		cout<<"\n";
	}
	return 0;
}
