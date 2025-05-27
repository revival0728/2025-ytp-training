// tag: Greedy

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int n;

void solve() {
  vector<int> t(n);
  ll sum = 0;
  for(auto& i : t)
    cin >> i, sum += i;
  sort(t.begin(), t.end(), greater<int>());
  ll ans = 0;
  for(auto& i : t) {
    ans += sum;
    sum -= i;
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(0), ios_base::sync_with_stdio(0);

  while(cin >> n)
    solve();
}