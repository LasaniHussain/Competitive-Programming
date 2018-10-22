#include<bits/stdc++.h>
using namespace std;
int t,n,nos[13],unq;
set<vector<int> > st;
vector<int> container;
//vector<int> container;
void backtrack(int pos,int sum)
{	//cout<<"backtrack("<<n<<","<<i<<")"<<"\n";
	if(sum==t)
	{	st.insert(container);
	}	
	for(int i=pos;i<n;i++)
	{
		if(nos[i]+sum<=t)
		{
			sum+=nos[i];
			container.push_back(nos[i]);
			backtrack(i+1,sum);
			sum-=nos[i];
			container.pop_back();
		}
	}
}
int main()
{
	while(cin>>t&&t>0)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		cin>>nos[i];
		/*for(int i=0;i<tracks;i++)
		cout<<cd[i]<<" ";*/
		//cout<<"\n";
		cout<<"Sums of "<<t<<":\n";
		//unq=0;
		backtrack(0,0);
		if(st.size()==0)
		cout<<"NONE\n";
		else
		{
			for(set<vector<int> >::reverse_iterator rit=st.rbegin();rit!=st.rend();rit++)
			{
				for(int i=0;i<(*rit).size();i++)
				{	cout<<(*rit)[i];
					if(i!=(*rit).size()-1)
					cout<<"+";
				}
				cout<<"\n";
			}
		}
		st.clear();
		//cout<<"sum:"<<max_sum<<"\n";
	}
	return 0;
}
