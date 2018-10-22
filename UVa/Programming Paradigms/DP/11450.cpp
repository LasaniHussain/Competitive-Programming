#include<bits/stdc++.h>
using namespace std;
int t,M,C,ans,sol;
vector<int> price[20];
int memo[210][25];
int shop(int money,int g)
{	if(money<0)
	return -99999;
	if(g==C)
	return M-money;
	int &ma=memo[money][g];
	if(ma!=-1)
	return ma;
	for(int i=0;i<price[g].size();i++)
	ma=max(shop(money-price[g][i],g+1),ma);
	return ma;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>M>>C;
		memset(memo,-1,sizeof(memo));
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
		sol=1;
		ans=shop(M,0);
		if(ans<0)
		cout<<"no solution";
		else
		cout<<ans;
		if(t)
		cout<<"\n";
	}
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
int M, C, price[25][25];
// price[g (<= 20)][model (<= 20)]
int memo[210][25];
// TOP-DOWN: dp table memo[money (<= 200)][g (<= 20)]
int shop(int money, int g) {
if (money < 0) return -1000000000;
// fail, return a large -ve number
if (g == C) return M - money;
// we have bought last garment, done
// if the line below is commented, top-down DP will become backtracking!!
if (memo[money][g] != -1) return memo[money][g]; // TOP-DOWN: memoization
int ans = -1;
// start with a -ve number as all prices are non negative
for (int model = 1; model <= price[g][0]; model++)
// try all models
ans = max(ans, shop(money - price[g][model], g + 1));
return memo[money][g] = ans; }
// TOP-DOWN: memoize ans and return it
int main() {
// easy to code if you are already familiar with it
int i, j, TC, score;
scanf("%d", &TC);
while (TC--) {
scanf("%d %d", &M, &C);
for (i = 0; i < C; i++) {
scanf("%d", &price[i][0]);
// store K in price[i][0]
for (j = 1; j <= price[i][0]; j++) scanf("%d", &price[i][j]);
}
memset(memo, -1, sizeof memo);
// TOP-DOWN: initialize DP memo table
score = shop(M, 0);
// start the top-down DP
if (score < 0) printf("no solution\n");
else
printf("%d\n", score);
} } // return 0;*/
