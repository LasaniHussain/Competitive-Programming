#include<bits/stdc++.h>
using namespace std;
int n;
int arr[1001];
int main()
{	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(scanf("%d",&n)&&n)
	{
			int i,j=0;
			for(i=0;i<n;i++)
			{	int x;
				cin>>x;
				if(x)
				arr[j++]=x;
			}
			for(i=0;i<j;i++)
			{	cout<<arr[i];
				if(i!=j-1)
				cout<<" ";
			}
			if(!j)
			cout<<"0";
			cout<<"\n";
	}
	return 0;
}
