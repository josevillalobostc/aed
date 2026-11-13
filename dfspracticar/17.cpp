#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 100000 + 5;
int n;
vector<vector<int>> nodes(N);
vector<vector<int>> nodes2(N);
vector<bool> visitados(N, false);
vector<bool> visitados2(N, false);
vector<int> candidatos;
vector<int> tsort;

void dfs(int u) {
  visitados[u] = true;
  for (auto &v : nodes[u]) {
    if (visitados[v])
      continue;
    if (!visitados2[v])
      continue;
    dfs(v);
  }
  tsort.push_back(u);
}

void dfs2(int u) {
  visitados2[u] = true;
  candidatos.push_back(u);
  for (auto &v : nodes2[u]) {
    if (visitados2[v])
      continue;
    dfs2(v);
  }
  cout << u << " ";
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int c;
    cin >> c;
    for (int j = 0; j < c; ++j) {
      int u;
      cin >> u;
      nodes[u].push_back(i);
      nodes2[i].push_back(u);
    }
  }
  dfs2(1);
}
