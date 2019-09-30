#include <iostream> 
#include<algorithm>
#include <cstring> 
#define MAXN 1000 
using namespace std; 
int dp[MAXN]; 
int w[MAXN] = {0, 3, 4, 2}; 
int v[MAXN] = {0, 4, 5, 3}; 
int W = 7, n = 3; 
int solve(int n, int W) 
{ 
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) 
	{ 
		for (int j = 0; j <= W; j++) 
		{ 
			if (j < w[i]) 
			{ 
				dp[j] = dp[j]; 
			} 
			else 
			{ 
				dp[j] = max(dp[j], dp[j-w[i]] + v[i]); 
			} 
		}
	} 
	return dp[W]; 
} 

int main() 
{ 
	cout << solve(n, W) << endl; // 10 
	return 0; 
}
