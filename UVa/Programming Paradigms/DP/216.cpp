#include<bits/stdc++.h>
using namespace std;
int t=1,n,net=1;
double dist(pair<int,int> &a,pair<int,int> &b)
{
	return 16.0+sqrt((double)pow((a.first-b.first),2)+(double)pow((a.second-b.second),2));
}
int main()
{
	while(scanf("%d",&n)&&n!=0)
	{	vector<pair<int,int> > v;
		vector<int> index;
		for(int i=0;i<n;i++)
		{		
			int x,y;
			cin>>x>>y;
			v.push_back(make_pair(x,y));
			index.push_back(i);
		}
		double ans=DBL_MAX;
		vector<int> network;
		do
		{
			double res=0;
			for(int i=0;i<n-1;i++)
			res+=dist(v[index[i]],v[index[i+1]]);
			if(res<ans)
			{
				ans=res;
				network=index;
			}
		}while(next_permutation(index.begin(),index.end()));
		//cout<<"Distance array\n";
		cout << "**********************************************************\n";
		cout<<"Network #"<<net++<<"\n";
		for(int i=0;i<n-1;i++)
		{
			cout<<"Cable requirement to connect ("<<v[network[i]].first<<","<<v[network[i]].second<<") to (";
			cout<<v[network[i+1]].first<<","<<v[network[i+1]].second<<") is ";
			cout<<fixed<<setprecision(2)<<dist(v[network[i]],v[network[i+1]])<<" feet.";
			cout<<"\n";
		}
		cout<<"Number of feet of cable required is "<<fixed<<setprecision(2)<<ans<<".\n";
	}
	return 0;
}
