#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define mod 998244353

ll exgcd(ll a, ll b, ll& x, ll& y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll res = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return res;
}

ll Inv(ll a)
{
    ll d, x, y;
    d = exgcd(a, mod, x, y);
    if (d == 1)
        return (x % mod + mod) % mod;
    return -1;
}

ll C(ll n, ll m)
{
    ll ans1 = 1, ans2 = 1;
    for (int i = n, j = 1;j <= m;j++, i--)
    {
        ans1 = ans1 * i % mod;
        ans2 = ans2 * j % mod;
    }
    return (ll)(ans1 * Inv(ans2) % mod);
}

int main() {
    ll n;
    scanf("%lld",&n);
    ll m;
    if (n % 2 == 0) {
        m = n / 2 - 1;
    }
    else {
        m = n / 2;
    }
    ll res = 0;
    for (ll i = 1;i <= m;i++) {
        ll j = n - i;
        res += C(j, i - 1) * 2;
    }
    res = res % mod;
    printf("%lld\n",res);
    system("pause");
    return 0;
}