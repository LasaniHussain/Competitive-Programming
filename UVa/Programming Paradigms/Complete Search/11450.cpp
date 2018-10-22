#include<bits/stdc++.h>
using namespace std;
int t,M,C,ans,sol;
vector<int> price[20];
int shop(int money,int g)
{	if(money<0)
	return -9999;
	if(g==C)
	{	//cout<<"Solution : "<<sol++<<" "<<M-money<<"\n";
		/*if(ans==-1)
		ans=money;
		else
		{
			ans=min(ans,money);
			cout<<"Solution : "<<sol++<<" "<<ans<<"\n";
		}
		return;*/
		return M-money;
	}
	//{
		int ma=-1;
		for(int i=0;i<price[g].size();i++)
		{	
			if(price[g][i]<=money)
			{	/*cout<<"selected "<<price[g][i]<<"\n";
				shop(money-price[g][i],g+1);
				cout<<"not selected "<<price[g][i]<<"\n";
				shop(money,g+1);*/
				ma=max(shop(money-price[g][i],g+1),ma);
				//return ma;
			}
		}
		return ma;
	//}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>M>>C;
		memset(price,0,sizeof(price));
		for(int i=0;i<C;i++)
		{
			int K;
			cin>>K;
			for(int j=0;j<K;j++)
			{
				int x;
				cin>>x;
				price[i].push_back(x);
			}
		}
		/*for(int i=0;i<C;i++)
		{
			for(int j=0;j<price[i].size();j++)
			cout<<price[i][j]<<" ";
			cout<<"\n";
		}*/
		sol=1;
		ans=-1;
		ans=shop(M,0);
		if(ans==-1)
		cout<<"no solution";
		else
		cout<<ans;
		if(t)
		cout<<"\n";
	}
	return 0;
}
