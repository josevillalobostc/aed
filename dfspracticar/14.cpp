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
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    nodes[u].push_back(v);
    nodes[v].push_back(u);
  }
  int conex = 0;
  dfs(1);
  vector<int> soluciones;
  for (int i = 2; i <= n; ++i) {
    if (visitados[i])
      continue;
    conex++;
    soluciones.push_back(i - 1);
    soluciones.push_back(i);
    dfs(i);
  }
  cout << conex << '\n';
  for (int i = 0; i < soluciones.size(); i += 2) {
    cout << soluciones[i] << " " << soluciones[i + 1] << '\n';
  }
}
