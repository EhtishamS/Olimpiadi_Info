#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void dfs(vector<vector<int>> &v, vector<int> &c, vector<vector<ll>> &dp, int node, int prev)
{
	if (v[node].size() == 1 && node != 0) { //leaf
		dp[node][0] = c[node];
		dp[node][1] = 0;
		return;
	}
	dp[node][0] = c[node];
	dp[node][1] = -1000000000000000000ll;
	for (auto x : v[node])
		if (x != prev) {
			dfs(v, c, dp, x, node);
			ll newZero = max(dp[node][0]+dp[x][0], dp[node][1]+dp[x][1]+c[node]);
			ll newOne = max(dp[node][0]+dp[x][1]-c[node], dp[node][1]+dp[x][0]);
			dp[node][0] = newZero;
			dp[node][1] = newOne;
		}
}

ll solve(vector<vector<int>> &v, vector<int> &c)
{
	int n = v.size();
	vector<vector<ll>> dp(n, vector<ll> (2ll, 0));
	dfs(v, c, dp, 0, -1);
	return max(dp[0][1], dp[0][0]);
}

signed main()
{
	int n;
	cin >> n;
	vector<vector<int>> v(n);
	vector<int> c(n);
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < n; ++i)
		cin >> c[i];
	cout << solve(v, c) << "\n";
	return 0;
}
