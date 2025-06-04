// tag: shortest path, floyd warshall, DP

#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 101, mxP = 1e4 + 1;
int n, k, p, a[mxP];
int dp[2][mxN][mxN], dis[mxN][mxN];

void floyd_warshall() {
  for(int i = 1; i <= n; ++i)
    dis[i][i] = 0;
  for(int l = 1; l <= n; ++l) {
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= n; ++j) {
        dis[i][j] = min(dis[i][j], dis[i][l] + dis[l][j]);
      }
    }
  }
}

int main() {
  cin.tie(0), ios_base::sync_with_stdio(0);

  memset(dis, 0x3f3f, sizeof(dis));
  memset(dp, 0x3f3f, sizeof(dp));
  cin >> n >> k;
  for(int u, v, w, i = 0; i < k; ++i) {
    cin >> u >> v >> w;
    dis[u][v] = w;
    dis[v][u] = w;
  }
  cin >> p;
  for(int i = 1; i <= p; ++i)
    cin >> a[i];
  floyd_warshall();
  dp[0][1][1] = 0;
  for(int t = 1; t <= p; ++t) {
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= n; ++j) {
        dp[t & 1][i][a[t]] = min(dp[t & 1][i][a[t]], dp[~t & 1][i][j] + dis[j][a[t]]);
        dp[t & 1][a[t]][i] = min(dp[t & 1][a[t]][i], dp[~t & 1][j][i] + dis[j][a[t]]);
      }
    }
    if(t < p)
      memset(dp[~t & 1], 0x3f3f, sizeof(dp[~t & 1]));
  }
  int ans = 1e9;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= n; ++j) {
      ans = min(ans, dp[p & 1][i][j] + dis[i][1] + dis[j][1]);
    }
  }
  cout << ans << '\n';
}