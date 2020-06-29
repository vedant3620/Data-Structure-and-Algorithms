#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
#define endl "\n"
#define test() \
    ll t;      \
    cin >> t;  \
    while (t--)
#define sd(val) scanf("%d", &val)
#define ss(val) scanf("%s", &val)
#define sl(val) scanf("%lld", &val)
#define debug(val) printf("check%d\n", val)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
#define clr(val) memset(val, 0, sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

/*------------------------------------------------------------------------*/

void solve()
{
    ll c, n, m;
    cin >> c >> n >> m;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll d[m];
    for (ll i = 0; i < m; i++)
    {
        cin >> d[i];
    }
    ll last = *max_element(d, d + m);
    ll dp[last + 1][n];
    for (ll i = 0; i <= last; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (i == 0)
                dp[i][j] = 1;
            else
            {
                if (arr[j] > c / 2)
                {
                    dp[i][j] = 2 * dp[i - 1][j];
                }
                else
                {
                    arr[j] = 2 * arr[j];
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    for (ll i = 0; i < m; i++)
    {
        ll ans = 0;
        for (ll j = 0; j < n; j++)
        {
            ans += dp[d[i]][j];
        }
        cout << ans << endl;
    }
}

int main()
{
    SPEED;
    OJ;
    //code from here
    solve();
    return 0;
}