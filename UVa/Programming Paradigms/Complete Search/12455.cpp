#include<bits/stdc++.h>
using namespace std;
int main()
{	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{	//cout<<"\ninside while";
		int n,p,*bars,i,j;bool f=false;	
		cin>>n>>p;
		bars=new int[p];
		for(i=0;i<p;i++)
		cin>>bars[i];
		if(n==0)
		cout<<"YES";
		else
		{	for(i=0;i<(1<<p);i++)
			{
				int sum=0;
				for(j=0;j<p;j++)
					if(i&(1<<j))
					sum+=bars[j];		
				if(sum==n)
				{	f=true;
					break;
				}
			}
			if(f)
			cout<<"YES";
			else
			cout<<"NO";
		}
		cout<<"\n";
	}
	return 0;
}
			
			
