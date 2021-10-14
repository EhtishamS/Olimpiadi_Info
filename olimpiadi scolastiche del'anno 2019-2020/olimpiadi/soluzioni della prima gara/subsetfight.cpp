#include<iostream>
#define god dimasi5eks
#pragma GCC optimize("O3")
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mod 1000000007
#define dancila 3.14159265359
#define eps 1e-9

// #define fisier 1

using namespace std;

typedef long long ll;

int n, v[102];

ll cnt[102][102], dp[102][102], fact[200002], inv[200002];

int add(int a, int b)
{
    int x = a+b;
    if(x >= mod)
        x -= mod;
    if(x < 0)
        x += mod;
    return x;
}
ll mul(ll a, ll b)
{
    return (a*b) % mod;
}

ll pw(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

ll combi(int N, int K)
{
    return mul(fact[N], mul(inv[K], inv[N - K]));
}
int main()
{

    #ifdef fisier
        ifstream f("input.in");
        ofstream g("output.out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0] = inv[0] = 1;
    for(int i = 1; i <= 200000; ++i)
    {
        fact[i] = mul(fact[i-1], i);
        inv[i] = pw(fact[i], mod - 2);
    }
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        int sum = 0;
        for(int j = 0; j <= v[i]; ++j)
        {
            cnt[i][sum] = add(cnt[i][sum], combi(v[i], j));
            sum = sum + i;
            if(sum >= n)
                sum -= n;
        }
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < n; ++j)
        {
            if(!cnt[i][j])
                continue;
            for(int p = 0; p < n; ++p)
                dp[i][(j + p) % n] = add(dp[i][(j + p) % n], mul(dp[i-1][p], cnt[i][j]));
        }
    cout << dp[n][0];
    return 0;
}
