#include<bits/stdc++.h>
using namespace std;
int main()
{	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n;	
	while(scanf("%d",&n)!=EOF)
	{
		vector<int> books(n);int m,i,x,y,ans=INT_MAX,j,dst,res1=0,res2=0;	
		for(i=0;i<n;i++)
		cin>>books[i];
		cin>>m;
		sort(books.begin(),books.end());
		for(i=n-1;i>=0;i--)
		{	if(books[i]<m)
			{	
				if(binary_search(books.begin(),books.end(),m-books[i]))
				{
					x=m-books[i];
					y=books[i];
					dst=abs(x-y);
				}
			}
			if(dst<ans)
			{
				ans=dst;
				res1=x;
				res2=y;
			}		
		}
		cout<<"Peter should buy books whose prices are "<<res1<<" and "<<res2<<".\n\n";
	}
	return 0;
}
		
	
