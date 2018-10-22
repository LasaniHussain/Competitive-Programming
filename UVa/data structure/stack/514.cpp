#include<bits/stdc++.h>
using namespace std;
int main()
{	freopen("in.txt","r",stdin);
	int n;
	while(true)
	{	cin>>n;
		if(n==0)
		break;
		int i=0,c=0;
		stack<int> stk;
		int *arr=new int[n];
		while(true)
		{	cin>>arr[0];
			if(arr[0]==0)
			{	cout<<"breaking\n";
				cout<<"\n";
				break;
			}
			for(i=1;i<n;i++)
				cin>>arr[i];
			for(i=0;i<n;i++)
			{	cout<<arr[i]<<" "<<"inside read for\n";;
				while(c<n&&c!=arr[i])
				{
					if(!stk.empty()&&stk.top()==arr[i])
					break;
					c++;
					stk.push(c);
				}
				if(stk.top()==arr[i])
				stk.pop();
			}		
			if(stk.empty())
			cout<<"Yes\n";
			else
			cout<<"No\n";	
		}
		cout<<"\n";
	}
	return 0;
}
