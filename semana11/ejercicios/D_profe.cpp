#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> nodos(n + 1);
  while (m--) {
    int a, b;
    cin >> a >> b;
    nodos[a].push_back(b);
    nodos[b].push_back(a);
  }
  for (int i = 0; i < n + 1; i++) {
    sort(nodos[i].begin(), nodos[i].end());
  }
  while (q--) {
    int op, u, x;
    cin >> op >> u >> x;
    if (op == 1) {
      cout << (nodos[u].size() >= x ? nodos[u][x - 1] : -1) << '\n';
    } else {
      int val =
          upper_bound(nodos[u].begin(), nodos[u].end(), x) - nodos[u].begin();
      cout << val << '\n';
    }
  }
}
