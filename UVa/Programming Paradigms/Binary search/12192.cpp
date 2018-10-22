#include<bits/stdc++.h>
using namespace std;
int main()
{	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,m;
	while(scanf("%d %d",&n,&m)&&n&&m)
	{
		vector<vector<int> >  v(n,vector<int> (m));
		int i,j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			cin>>v[i][j];
		}
		int q;
		cin>>q;
		while(q--)
		{
			int l,u,b_s=0,size;
			cin>>l>>u;
			for(i=0;i<n;i++)
			{
				vector<int>::iterator it=lower_bound(v[i].begin(),v[i].end(),l);
				if(it!=v[i].end())
				{	int col=it-v[i].begin();
					for(size=b_s;size<n;size++)
					{
						int end_row=i+size;
						int end_col=col+size;
						if(end_row>=n||end_col>=m||v[end_row][end_col]>u)
						break;
						if(size+1>b_s)
						b_s=size+1;
					}
				}
			}
			cout<<b_s<<"\n";
		}
		cout<<"-\n";
	}
	return 0;
}
