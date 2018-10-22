#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(true)
	{
		cin>>n;
		if(n==0)
		break;
		int *arr=new int[n],s=0,ma=0;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			s+=arr[i];
			ma=max(ma,s);
			if(s<0)
			s=0;
		}
		if(ma!=0)
		cout<<"The maximum winning streak is "<<ma<<".\n";
		else
		cout<<"Losing streak.\n";
	}
	return 0;
}
