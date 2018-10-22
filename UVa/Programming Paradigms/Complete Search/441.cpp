#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	bool blank=false;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(scanf("%d",&n)&&n)
	{	//cout<<"          "<<n<<"            ";
		if(blank)
		cout<<"\n";
		blank=true;		
		int *arr=new int[n];
		int i,j,k,l,m,o;
		for(i=0;i<n;i++)
		cin>>arr[i];
		for(i=0;i<n-5;i++)
		{
			for(j=i+1;j<n-4;j++)
			{
				for(k=j+1;k<n-3;k++)
				{
					for(l=k+1;l<n-2;l++)
					{
						for(m=l+1;m<n-1;m++)
						{
							for(o=m+1;o<n;o++)
							cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<" "<<arr[l]<<" "<<arr[m]<<" "<<arr[o]<<"\n";
						}
					}
				}
			}
		}
	}
	return 0;
}
