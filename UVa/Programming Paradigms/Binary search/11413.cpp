#include<bits/stdc++.h>
using namespace std;
int arr[1001],n,m;
bool try_cap(int cap)
{
	int cur=0,i,container=1;
	for(i=0;i<n;i++)
	{	if(arr[i]>cap)
		return false;
		if(cur+arr[i]>cap)
		{	cur=0;
			//if(cur==0)
			container++;
		}
		if(container>m)
		return false;
		cur+=arr[i];		
	}
	return true;
}
int main()
{	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		int i,l=1,h=0,ans;
		for(i=0;i<n;i++)
		{	scanf("%d",arr+i);
			h+=arr[i];
		}
		h+=1;
		/*for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
		cout<<"\n";*/
		while(l<=h)
		{
			int mid=(l+h)/2;
			//cout<<mid<<"\n";
			if(try_cap(mid))
			{
				ans=mid;
				h=mid-1;
			}
			else
			l=mid+1;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
			
		
