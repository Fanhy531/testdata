#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50 + 5;
int n, m;
int raisin[MAXN][MAXN];
int sum[MAXN][MAXN], cnt[MAXN][MAXN][MAXN][MAXN];
int memory[MAXN][MAXN][MAXN][MAXN];
int ans = INT_MAX;
int Visit_Count;

int dfs(int ldx, int ldy, int urx, int ury)
{
    if (memory[ldx][ldy][urx][ury]) return memory[ldx][ldy][urx][ury];
    if (ldx == urx && ldy == ury) return cnt[ldx][ldy][urx][ury];
    int pay, tot = INT_MAX;
    for (int flag = ldx; flag < urx; flag++)
    {
        pay = dfs(ldx, ldy, flag, ury) + dfs(flag + 1, ldy, urx, ury);
        if (tot > pay) tot = pay;
    }
    for (int flag = ldy; flag < ury; flag++)
    {
        pay = dfs(ldx, ldy, urx, flag) + dfs(ldx, flag + 1, urx, ury);
        if (tot > pay) tot = pay;
    }
    memory[ldx][ldy][urx][ury] = tot + cnt[ldx][ldy][urx][ury];
    return memory[ldx][ldy][urx][ury];
}

int main()
{
    freopen("raisins.in", "r", stdin); freopen("raisins.sol", "w", stdout);
    cin >> n >> m;
    if (n == 1 && m == 1) { cin >> raisin[1][1]; cout << 0 << endl; return 0; }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> raisin[i][j];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1]
            - sum[i - 1][j - 1] + raisin[n - j + 1][i];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= i; k++)
                for (int l = 1; l <= j; l++)
                    cnt[k][l][i][j] = sum[i][j] - sum[k - 1][j]
                        - sum[i][l - 1] + sum[k - 1][l - 1];
    ans = dfs(1, 1, m, n);
    cout << ans - cnt[1][1][m][n] << endl;
    return 0;
}
