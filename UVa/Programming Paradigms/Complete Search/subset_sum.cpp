#include<bits/stdc++.h>
using namespace std;
int N,cd[21],tracks,max_sum;
vector<int> ans;
vector<int> container;
int backtrack(int pos,int sum)
{	//cout<<"backtrack("<<n<<","<<i<<")"<<"\n";
	/*if(sum>max_sum)
	{	max_sum=sum;
		//ans=container;
	}	*/
	
	if(pos>=tracks||sum<0)
	return 0;
	
	//for(int i=pos;i<tracks;i++)
	//{

			if(cd[pos]<=sum)
			return max(backtrack(pos+1,sum),cd[pos]+backtrack(pos+1,sum-cd[pos]));
			else
			return 0;
	//}
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
		//sort(cd,cd+tracks);
		cout<<"sum:"<<backtrack(0,N)<<"\n";
	}
	return 0;
}
