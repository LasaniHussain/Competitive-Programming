#include<bits/stdc++.h>
using namespace std;
int killed[1025][1025];
int main()
{	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{	//cout<<"inside while\n";
		memset(killed,0,sizeof(killed));
		int d,n,x,y,size,i,j;
		cin>>d>>n;
		while(n--)
		{
			scanf("%d %d %d",&x,&y,&size);
			for(i=max(x-d,0);i<=min(x+d,1024);i++)
			{
				for(j=max(y-d,0);j<=min(y+d,1024);j++)
				killed[i][j]+=size;
			}
		}
		int ma=-1;
		for(i=0;i<1025;i++)
		{
			for(j=0;j<1025;j++)
			{
				if(killed[i][j]>ma)
				{
					ma=killed[i][j];x=i;y=j;
				}
			}
		}
		cout<<x<<" "<<y<<" "<<ma<<"\n";
	}
	return 0;
}

