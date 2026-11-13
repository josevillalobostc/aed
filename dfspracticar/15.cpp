#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 100000 + 5;
int n, m;
vector<vector<int>> nodes(N);
vector<bool> visitados(N, false);

vector<int> nodoss;
void dfs(int u) {
  nodoss.push_back(u);
  visitados[u] = true;
  for (int v : nodes[u]) {
    if (visitados[v])
      continue;
    dfs(v);
  }
}

bool simple_cycle(int u) {
  nodoss.clear();
  dfs(u);
  for (auto &v : nodoss) {
    if (nodes[v].size() != 2) {
      return false;
    }
  }
  return true;
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
  int rpta = 0;
  for (int i = 1; i <= n; ++i) {
    if (visitados[i])
      continue;
    if (simple_cycle(i)) {
      rpta++;
    }
  }
  cout << rpta << '\n';
  return 0;
}
