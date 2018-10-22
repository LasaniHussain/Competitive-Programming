#include<bits/stdc++.h>
using namespace std;
int N,cd[21],tracks,max_sum;
vector<int> ans;
vector<int> container;
void backtrack(int pos,int sum)
{	//cout<<"backtrack("<<n<<","<<i<<")"<<"\n";
	if(sum>max_sum)
	{	max_sum=sum;
		ans=container;
	}	
	for(int i=pos;i<tracks;i++)
	{
		if(cd[i]+sum<=N)
		{
			sum+=cd[i];
			container.push_back(cd[i]);
			backtrack(i+1,sum);
			sum-=cd[i];
			container.pop_back();
		}
	}
}
int main()
{
	while(cin>>N)
	{
		cin>>tracks;
		for(int i=0;i<tracks;i++)
		cin>>cd[i];
		/*for(int i=0;i<tracks;i++)
		cout<<cd[i]<<" ";*/
		//cout<<"\n";
		max_sum=0;
		backtrack(0,0);
		for(auto c:ans)
		cout<<c<<" ";
		cout<<"sum:"<<max_sum<<"\n";
	}
	return 0;
}
