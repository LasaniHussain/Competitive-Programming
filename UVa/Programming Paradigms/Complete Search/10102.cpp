#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int m;
	while(cin>>m)
	{
		char **arr=new char*[m];int i,j,k,l,ma=INT_MIN,mi=INT_MAX;
		for(i=0;i<m;i++)
		arr[i]=new char[m];
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			cin>>arr[i][j];
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			{
				if(arr[i][j]=='1')
				{
					mi=INT_MAX;
					for(k=0;k<m;k++)
					{
						for(l=0;l<m;l++)
						{
							if(arr[k][l]=='3')
							{	int tmp=abs(i-k)+abs(j-l);
								mi=min(tmp,mi);
								//cout<<"min = "<<mi<<"\n";
							}
						}
					}
					ma=max(ma,mi);
				}
				
			}
		}
		cout<<ma<<"\n";
	}
	return 0;
}
			
