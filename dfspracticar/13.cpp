#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 100000 + 5;
int n, m;
vector<vector<int>> nodes(N);
vector<bool> visitados(N, false);

void dfs(int u) {
  visitados[u] = true;
  for (int v : nodes[u]) {
    if (visitados[v])
      continue;
    dfs(v);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> n >> m;
  if (m < n - 1) {
    cout << -1 << '\n';
    return 0;
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    nodes[u].push_back(v);
    nodes[v].push_back(u);
  }
  int conex = -1;
  for (int i = 0; i < n; ++i) {
    if (visitados[i])
      continue;
    conex++;
    dfs(i);
  }
  cout << conex << '\n';
}
