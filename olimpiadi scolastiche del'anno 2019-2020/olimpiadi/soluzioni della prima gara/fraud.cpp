#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r)
{
	return uniform_int_distribution<int>(l, r)(rng);
}

ll rec(vector<int> &v, int original_n, int l, int r)
{
	unordered_map<int, int> f;
	for (int i = l; i <= r; ++i)
		++f[v[i]];
	int mn = original_n, mx = 0;
	for (int i = l; i <= r; ++i){
		mn = min(mn, f[v[i]]);
		mx = max(mx, f[v[i]]);
	}
	ll ans = 1ll*mn*mx;
	int first = -1;
	vector<pair<int, int>> subintervals;
	for (int i = l; i <= r; ++i)
		if (f[v[i]] != mn) {
			if (first == -1)
				first = i;
		}else {
			if (first != -1) {
				subintervals.push_back(make_pair(first, i-1));
				first = -1;
			}
		}
	if (first != -1)
		subintervals.push_back(make_pair(first, r));
	f.clear(); //if we don't clear f then memory can wind up to nsqrtn and we don't want that
	for (auto x : subintervals)
		ans = max(ans, rec(v, original_n, x.first, x.second));
	return ans;
}

ll solve(vector<int> &v)
{
	return rec(v, v.size(), 0, v.size()-1);
}

ll brute(vector<int> &v)
{
	int n = v.size();
	unordered_map<int, int> f;
	multiset<int> ms;
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		f.clear();
		int mx = 0;
		ms.clear();
		for (int j = i; j < n; ++j) {
			if (f[v[j]] != 0)
				ms.erase(ms.find(f[v[j]]));
			++f[v[j]];
			ms.insert(f[v[j]]);
			mx = max(mx, f[v[j]]);
			ans = max(ans, 1ll * (*ms.begin())*mx);
		}
	}
	return ans;
}

vector<int> nsqrtn(int n)
{
	vector<int> v(n);
	int p = 0;
	for (int i = 1; i <= n && p < n; ++i) {
		for (int j = 1; j <= i && p < n; ++j)
			v[p++] = i;
	}
	return v;
}

void gen_test()
{
	for (int t = 1; t <= 100000; ++t) {
		int n = 100000;
		vector<int> v = nsqrtn(n);
		int p = 0;
		for (int i = 1; i <= n && p < n; ++i) {
			for (int j = 1; j <= i && p < n; ++j)
				v[p++] = i;
		}
		ll ans1 = solve(v);
		ll ans2 = solve(v);
		if (ans1 != ans2) {
			cout << n << "\n";
			for (auto x : v)
				cout << x << " ";
			cout << "\n";
			cout << ans1 << " " << ans2 << "\n";
			return;
		}else cout << "Passed at test " << t << " with values " << ans1 << " " << ans2 << "\n";
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	cout << solve(v) << "\n";
	// gen_test();
	return 0;
}
