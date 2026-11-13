#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 100000 + 5;
int n;
vector<vector<int>> nodes(N);
vector<bool> visitados(N, false);

void dfs(int u) {
  visitados[u] = true;
  cout << u << " ";
  for (int v : nodes[u]) {
    if (visitados[v])
      continue;
    dfs(v);
    cout << u << " ";
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    nodes[u].push_back(v);
    nodes[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    sort(nodes[i].begin(), nodes[i].end());
  }
  dfs(1);
  cout << '\n';
}
