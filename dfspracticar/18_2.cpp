#include <bits/stdc++.h>
#include <limits>
using namespace std;

const int N = 2 * 100000 + 5;
const int INF = numeric_limits<int>::max();
vector<vector<int>> nodes(N);
vector<bool> visitados(N, false);

int n;
int sup, inf;
void dfs(int u, vector<int> &orden) {
  visitados[u] = true;
  for (auto &v : nodes[u]) {
    if (visitados[v])
      continue;
    dfs(v, orden);
  }
  orden.push_back(u);
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    sup = 2;
    inf = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      nodes[i].clear();
      visitados[i] = false;
    }
    vector<int> orden;

    for (int i = 0; i < n - 1; ++i) {
      int u, v, x, y;
      cin >> u >> v >> x >> y;
      if (x > y) {
        nodes[u].push_back(v);
      } else {
        nodes[v].push_back(u);
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (visitados[i])
        continue;
      dfs(i, orden);
    }
    for (auto &val : orden) {
      cout << val << " ";
    }
    cout << '\n';
  }
}
