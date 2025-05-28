// tag: DFS

#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 13;
int n, ans, qt, valid_x, valid_y, valid_o, valid_ro, full_valid;
bool grid[mxN][mxN];

void dfs(int x) {
  if(x == n || qt == n) {
    if(qt != n) return;
    if(ans > 0) cout << '\n';
    ++ans;
    string og;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        og.push_back(grid[i][j] ? 'Q' : '_');
      }
      og.push_back('\n');
    }
    cout << og;
    return;
  }
  assert(0 <= x && x < n);
  if(valid_x & (1 << x)) {
    dfs(x + 1);
    return;
  }
  int y = 0;
  int valid = valid_y;
  valid |= valid_o >> x;
  valid |= valid_ro >> n - x - 1;
  valid = ~valid & full_valid;
  for(; valid; valid >>= 1, ++y) {
    if(valid & 1) {
      int o = x + y, ro = n - x + y - 1;
      grid[x][y] = 1;
      valid_x ^= 1 << x;
      valid_y ^= 1 << y;
      valid_o ^= 1 << o;
      valid_ro ^= 1 << ro;
      ++qt;
      dfs(x + 1);
      grid[x][y] = 0;
      valid_x ^= 1 << x;
      valid_y ^= 1 << y;
      valid_o ^= 1 << o;
      valid_ro ^= 1 << ro;
      --qt;
    }
  }
}

void solve() {
  ans = 0;
  qt = 0;
  cin >> n;
  full_valid = (1 << n) - 1;
  dfs(0);
  cout << ans << '\n';
}

int main() {
  cin.tie(0), ios_base::sync_with_stdio(0), cout.tie(0);

  int T;
  cin >> T;
  while(T--)
    solve();
}