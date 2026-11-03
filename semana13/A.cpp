#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> mat;
vector<int> islas;
vector<bool> visitados;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int DFS(int x, int y) {
  visitados[x * n + y] = true;
  int res = 1;
  for (int k = 0; k < 4; ++k) {
    int vx = x + dx[k];
    int vy = y + dy[k];
    if (vx < 0 or vx >= n or vy < 0 or vy >= m)
      continue;
    if (visitados[vx * n + vy])
      continue;
    if (mat[vx][vy] != '#')
      continue;
    res += DFS(vx, vy);
  }
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> n >> m;
  mat = vector<string>(n);
  visitados = vector<bool>(n * m);
  for (int i = 0; i < n; ++i) {
    cin >> mat[i];
  }
  int cnt_islas = 0, max_isla = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == '.')
        continue;
      if (visitados[i * n + j])
        continue;
      max_isla = max(max_isla, DFS(i, j));
      ++cnt_islas;
    }
  }
  cout << cnt_islas << " " << max_isla << '\n';
  return 0;
}
