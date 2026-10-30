#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<set<int>> nodes(n + 1);
  vector<pair<int, int>> edges;
  while (m--) {
    int a, b;
    cin >> a >> b;
    nodes[a].insert(b);
    nodes[b].insert(a);
    edges.push_back({a, b});
  }
  int cant = 0;
  for (auto [u, v] : edges) {
    set<int> inte;
    set_intersection(nodes[u].begin(), nodes[u].end(), nodes[v].begin(),
                     nodes[v].end(), inserter(inte, inte.begin()));
    cant += inte.size();
  }
  cout << cant / 3;
}
