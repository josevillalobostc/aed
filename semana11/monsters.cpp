#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  cin >> n >> m;
  vector<string> mat(n);
  queue<tuple<int, int, int>> Q;
  vector<int> dx = {1, -1, 0, 0};
  vector<int> dy = {0, 0, 1, -1};
  for (int i = 0; i < n; ++i) {
    cin >> mat[i];
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == 'M') {
        Q.push({i, j, 0});
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mat[i][j] == 'A') {
        Q.push({i, j, 0});
      }
    }
  }
  while (!Q.empty()) {
    int cx, cy, d;
    tie(cx, cy, d) = Q.front();
    Q.pop();
    if (cx == 0 || cy == 0 || cx == n - 1 || cy == m - 1) {
      if (mat[cx][cy] == 'A') {
        cout << d;
        return 0;
      }
    }
    for (int k = 0; k < 4; ++k) {
      int vx = cx + dx[k];
      int vy = cy + dy[k];
      if (vx < 0 || vy < 0 || vx >= n || vy >= m)
        continue;
      if (mat[vx][vy] != '.')
        continue;
      mat[vx][vy] = mat[cx][cy];
      Q.push({vx, vy, d + 1});
    }
  }
  cout << -1;
}
