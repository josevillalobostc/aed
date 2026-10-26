#include <bits/stdc++.h>
#include <utility>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
  map<pair<int, int>, int> freqs;
  while (m--) {
    int u, v;
    cin >> u >> v;
    if (u > v)
      swap(u, v);
    ++freqs[make_pair(u, v)];
  }
  while (q--) {
    int u, v;
    cin >> u >> v;
    if (u > v)
      swap(u, v);
    cout << (freqs.count(make_pair(u, v)) ? freqs[make_pair(u, v)] : 0) << '\n';
  }
}
