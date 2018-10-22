#include<bits/stdc++.h>
using namespace std;
int main()
{	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t,m,n,x,y;
	while(cin>>t)
	{	if(t!=0)
		cin>>n>>m;
		while(t--)
		{	
				int x,y;
				cin>>x>>y;
				if(x==n||y==m)
				cout<<"divisa";
				else if(x>n&&y>m)
				cout<<"NE";
				else if(x<n&&y>m)
				cout<<"NO";
				else if(x>n&&y<m)
				cout<<"SE";
				else
				cout<<"SO";
				cout<<"\n";
		}		
	}
	return 0;
}
