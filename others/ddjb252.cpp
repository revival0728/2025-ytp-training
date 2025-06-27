#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

constexpr int mxP = 18;
int p, r[mxP][mxP], dp[2][mxP][1 << mxP];
uint8_t trace[mxP + 1][mxP][1 << mxP];

bool umin(int &i, int v) {
  return i > v ? i = v, 1 : 0;
}

void solve() {
  cin >> p;
  for(int i = 0; i < p; ++i)
    for(int j = 0; j < p; ++j)
      cin >> r[i][j];
  memset(dp, 0x3f3f, sizeof(dp));
  for(int i = 0; i < p; ++i) {
    dp[1][i][1 << i] = 0;
  }
  for(int i = 2; i <= p; ++i) {
    for(int vis = 0; vis < (1 << p); ++vis) {
      if(__builtin_popcount(vis) != i) continue;
      for(int k = 0; k < p; ++k) {
        // from j to k
        if(~vis & (1 << k)) continue;
        for(int j = 0; j < p; ++j) {
          if(~vis & (1 << j) || j == k) continue;
          int w = r[j][k];
          if(w == -1) continue;
          if(umin(dp[i & 1][k][vis], dp[~i & 1][j][vis ^ (1 << k)] + w)) {
            trace[i][k][vis] = j;
          }
        }
      }
    }
  }
  vector<int> order; order.reserve(p);
  int now_id, now_bit = (1 << p) - 1, ans = 1e9;
  for(int i = 0; i < p; ++i) {
    if(umin(ans, dp[p & 1][i][now_bit]))
      now_id = i;
  }
  for(int i = p; i > 0; --i) {
    order.push_back(now_id);
    int prev_bit = now_bit ^ (1 << now_id);
    now_id = trace[i][now_id][now_bit];
    now_bit = prev_bit;
  }
  for(auto it = order.cbegin(); it != order.cend(); ++it)
    cout << *it + 1 << ' ';
  cout << '\n' << ans << '\n';
}

int main() {
  cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  while(T--)
    solve();
}
