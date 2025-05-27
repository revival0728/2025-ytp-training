// tag: Greedy

#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s, t;
  cin >> s >> t;
  int st = 0;
  for(int i = 0; i < t.size() && st < s.size(); ++i) {
    if(s[st] == t[i])
      ++st;
  }
  cout << (st == s.size() ? "Yes" : "No") << '\n';
}

int main() {
  cin.tie(0), ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  while(T--)
    solve();
}