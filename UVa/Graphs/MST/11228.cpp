#include<bits/stdc++.h>
using namespace std;
int arr[1001];
double dist(pair<double,double> &a,pair<double,double> &b)
{
	return (sqrt(pow((a.first-b.first),2)+pow((a.second-b.second),2)));
}
void ini()
{
	for(int i=0;i<1001;i++)
	arr[i]=i;
}
int root(int a)
{
	while(arr[a]!=a)
	{
		arr[a]=arr[arr[a]];
		a=arr[a];
	}
	return a;
}
void _union(int a,int b)
{
	if(root(a)==root(b))
	return;
	else
	arr[root(a)]=arr[root(b)];
}
int main()
{
	int t,cs=1;
	cin>>t;
	while(cs<=t)
	{	memset(arr,0,sizeof(arr));
		ini();
		int n;double r;
		cin>>n>>r;
		vector<pair<double,double> > vp(n);
		for(int i=0;i<n;i++)
		cin>>vp[i].first>>vp[i].second;
		vector<pair<double,pair<int,int> > > adj;
		int node=0;
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{	double dis=dist(vp[i],vp[j]);
				adj.push_back(make_pair(dis,make_pair(i,j)));
			}
		}
		sort(adj.begin(),adj.end());
		double cost=0,totcost=0,st=1;
		for(auto c:adj)
		{
			double cst;int x,y;
			cst=c.first;x=c.second.first;y=c.second.second;
			if(root(x)!=root(y))
			{	_union(x,y);
				if(cst<=r)
				{	cost+=cst;
					//cout<<"same city "<<x<<" to "<<y<<"cost "<<cost<<"\n";
				}
				else
				{	totcost+=cst;
					st++;
					//cout<<"different city "<<x<<" to "<<y<<"cost "<<totcost<<"\n";
				}
			}
		}
		cout<<"Case #"<<cs<<": "<<st<<" "<<round(cost)<<" "<<round(totcost);
		//if(cs!=t)
		cout<<"\n";
		cs++;
	}
	return 0;
}
