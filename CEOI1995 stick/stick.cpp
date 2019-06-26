#include <bits/stdc++.h>
using namespace std;

const int MAXN = 65;
int n;
int a[MAXN], sum;
int all;
bool Visit[MAXN];

bool cmp(int x, int y) { return x > y; }

bool dfs(int last, int left, int depth)
{
	if (depth == 0 && left == 0) return true;
	if (depth == 0 && left != 0) return false;
	if (left == 0) left = all, last = 1;
	for (int i = last; i <= n; i++) if (a[i] <= left)
	{
		if (Visit[i]) continue;
		if (i > 1 && !Visit[i - 1] && a[i] == a[i - 1]) continue;
		Visit[i] = true;
		if (dfs(i, left - a[i], depth - 1)) return true;
		Visit[i] = false;
		if (a[i] == left || left == all) return false;
	}
	return false;
}

int main()
{
	freopen("stick1.in", "r", stdin); freopen("stick.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
	sort(a + 1, a + n + 1, cmp);
	for (int i = a[1]; i <= sum / 2; i++) if(sum % i == 0)
	{ all = i; if (dfs(1, i, n)) { cout << i << endl; return 0; } }
	cout << sum << endl;
	return 0;
} 
