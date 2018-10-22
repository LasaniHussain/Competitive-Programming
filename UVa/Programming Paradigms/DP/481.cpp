#include<bits/stdc++.h>
using namespace std;
int arr[100000];
int main()
{
	int i=0,n;
	while(cin>>n)
	arr[i++]=n;
	int len=i;
	//vector<int> lis(len,1);
	/*cout<<"\n";
	for(i=0;i<len;i++)
	cout<<lis[i]<<" ";
	cout<<"\n";*/
	/*for(i=1;i<len;i++)
	{
		for(int j=0;j<i;j++)
		if(arr[j]<arr[i])
		lis[i]=max(lis[i],lis[j]+1);
	}*/
	int lmax=0;
	vector<vector<int> > interim;
	vector<int> ending;
	int lpos=0;
	interim.push_back(vector<int> (0));
	interim[0].push_back(arr[0]);
	ending.push_back(arr[0]);
	for(i=1;i<len;i++)
	{
		if(arr[i]<ending[0])
		{	//cout<<arr[i]<<" Case 1\n";
			ending[0]=arr[i];
			interim[0][0]=arr[i];
		}
		else if(arr[i]>ending.back())
		{	//cout<<arr[i]<<" Case 2\n";
			interim.push_back(interim.back());
			//interim[lpos+1]=interim[lpos];
			//lpos++;
			interim.back().push_back(arr[i]);
			ending.push_back(arr[i]);
		}
		else 
		{	if(arr[i]!=ending.back())
			{
				//cout<<arr[i]<<" Case 3\n";
				int pos=lower_bound(ending.begin(),ending.end(),arr[i])-ending.begin();
				//pos--;
				vector<int> tmp=interim[pos-1];
				tmp.push_back(arr[i]);
				interim[pos]=tmp;
				ending[pos]=arr[i];				
			}
		}
	}
	for(auto c:interim)
	{
		for(auto e:c)
		cout<<e<<" ";
		cout<<"\n";
	}
	cout<<interim.back().size()<<"\n-\n";
	for(i=0;i<interim.back().size();i++)
	{	cout<<(interim.back())[i];
		//if(i!=interim.back().size()-1)
		cout<<"\n";
	}	
	return 0;
}
