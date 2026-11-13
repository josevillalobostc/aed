#include <bits/stdc++.h>
#include <limits>
using namespace std;

const int N = 2 * 100000 + 5;
const int INF = numeric_limits<int>::max();
vector<vector<int>> nodes(N);
vector<bool> visitados(N, false);
vector<int> valores(N, INF);

int n;
int sup, inf;
void dfs(int u, map<pair<int, int>, pair<int, int>> &edges) {
  visitados[u] = true;
  for (auto &v : nodes[u]) {
    if (visitados[v])
      continue;
    auto [x, y] = edges[{u, v}];
    if (x < y) {
      valores[v] = sup;
      sup++;
    } else {
      valores[v] = inf;
      inf--;
    }
    dfs(v, edges);
  }
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
      valores[i] = INF;
    }
    map<pair<int, int>, pair<int, int>> edges;

    for (int i = 0; i < n - 1; ++i) {
      int u, v, x, y;
      cin >> u >> v >> x >> y;
      nodes[u].push_back(v);
      nodes[v].push_back(u);
      edges[{u, v}] = {x, y};
      edges[{v, u}] = {y, x};
    }
    valores[1] = 1;
    dfs(1, edges);
    int minimin = *min_element(valores.begin(), valores.begin() + n + 1);
    int aumento = 1 - minimin;
    for (int i = 1; i <= n; ++i) {
      cout << valores[i] + aumento << " ";
    }
    cout << '\n';
  }
}
