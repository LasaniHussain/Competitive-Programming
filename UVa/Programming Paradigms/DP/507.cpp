#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,t=0;
	cin>>T;
	while(t++<T)
	{
		//t++;
		int n,i=0,s=0,l=0,h=0,j,ans=0;
		cin>>n;
		int *arr=new int[n];
		for(j=1;j<n;j++)
		cin>>arr[j];
		for(j=1;j<n;j++)
		{
			s+=arr[j];
			if(s>ans||(s==ans&&j-i>h-l))
			{	ans=s;
				l=i;
				h=j;
			}	
			if(s<0)
			{
				s=0;
				i=j;
			}
		}
		if(ans>0)
		cout<<"The nicest part of route "<<t<<" is between stops "<<l+1<<" and "<<h+1<<"\n";
		else
		cout<<"Route "<<t<<" has no nice parts\n";
	}
	return 0;
}
	
