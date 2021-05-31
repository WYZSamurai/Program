#include <iostream>
using namespace std;
const int MOD = 998244353;
const int MAXN = 202020;
int fac[MAXN], facinv[MAXN];

long long quickmul(int a, int b)
{
    long long ret = 1;
    for (; b; b >>= 1, a = (long long)a * a % MOD)
        if ((b & 1))
            ret = ret * a % MOD;
    return ret;
}
long long C(int n, int m)
{
    if (n < 0 || m < 0 || n < m)
        return 0;
    return (long long)fac[n] * facinv[m] % MOD * facinv[n - m] % MOD;
}
void init()
{
    fac[0] = 1;
    for (int i = 1;i <= MAXN;i++)
        fac[i] = (long long)fac[i - 1] * i % MOD;
    facinv[MAXN] = quickmul(fac[MAXN], MOD - 2);
    for (int i = MAXN;i > 0;i--)
        facinv[i - 1] = (long long)facinv[i] * (i) % MOD;
}
int main()
{
    init();
    int n, m;
    while (1)
    {
        scanf("%d %d", &n, &m);
        printf("%lld\n", C(n, m));
    }
    system("pause");
}