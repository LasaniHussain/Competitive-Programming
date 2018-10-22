#include<bits/stdc++.h>
using namespace std;
int main()
{	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int f,r,*fr,*rr,i,j;
	while(scanf("%d",&f)&&f)
	{
		cin>>r;
		double ans=0,cur,prev;
		fr=new int[f];
		rr=new int[r];
		for(i=0;i<f;i++)
		cin>>fr[i];
		for(i=0;i<r;i++)
		cin>>rr[i];
		vector<double> sol;
		for(i=0;i<f;i++)
		{
			for(j=0;j<r;j++)
			sol.push_back(double(rr[j])/double(fr[i]));
		}
		sort(sol.begin(),sol.end());
		for(i=0;i<sol.size();i++)
		{
			if(i!=0)
			{
				if(sol[i]/sol[i-1]>ans)
				ans=sol[i]/sol[i-1];
			}
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}				
