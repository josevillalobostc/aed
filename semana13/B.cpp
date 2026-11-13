#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<pair<int, int>> t;
vector<vector<int>> nod;

void DFS(int u, int &time) {
  t[u].first = ++time;
  for (auto &v : nod[u]) {
    if (t[v].first == -1) {
      DFS(v, time);
    }
  }
  t[u].second = ++time;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> n >> q;
  t = vector<pair<int, int>>(n + 1, {-1, -1});
  nod = vector<vector<int>>(n + 1);
  int time = 0;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    nod[u].push_back(v);
    nod[v].push_back(u);
  }
  DFS(1, time);

  while (q--) {
    int u, v;
    cin >> u >> v;
    if (t[u].first <= t[v].first && t[u].second >= t[v].second) {
      cout << "SI" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }

  return 0;
}
