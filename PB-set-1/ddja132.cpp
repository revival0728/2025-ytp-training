// tag: Divide anc Conquer

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mxN = 1e6;
ll ans = 0;
int n, A[mxN], tmp[mxN];

void dc(int l, int r) {
  if(l == r) return;
  int m = (l + r) / 2;
  dc(l, m), dc(m + 1, r);
  int lt = l, rt = m + 1, ts = 0;
  while(lt <= m && rt <= r) {
    if(A[lt] > A[rt]) {
      ans += r - rt + 1;
      tmp[ts++] = A[lt++];
    } else {
      tmp[ts++] = A[rt++];
    }
  }
  while(lt <= m) tmp[ts++] = A[lt++];
  while(rt <= r) tmp[ts++] = A[rt++];
  memcpy(A + l, tmp, ts * sizeof(int));
}

void solve() {
  ans = 0;
  cin >> n;
  for(int i = 0; i < n; ++i)
    cin >> A[i];
  dc(0, n - 1);
  cout << ans << '\n';
}

int main() {
  cin.tie(0), ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  while(T--)
    solve();
}