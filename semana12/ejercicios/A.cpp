#include <bits/stdc++.h>
#include <utility>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat(n);
  for (int i = 0; i < n; ++i) {
    mat[i] = vector<int>(m);
  }
  queue<pair<int, int>> cola;
  pair<int, int> orig;
  pair<int, int> dest;
  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    for (int j = 0; j < m; ++j) {
      if (s[j] == 'S') {
        orig = make_pair(i, j);
        mat[i][j] = 0;
      } else if (s[j] == 'E') {
        dest = make_pair(i, j);
        mat[i][j] = -1;
      } else {
        mat[i][j] = s[j] == '.' ? -1 : -2;
      }
    }
  }
  cola.emplace(make_pair(orig.first, orig.second));
  vector<int> dx = {1, -1, 0, 0};
  vector<int> dy = {0, 0, 1, -1};
  while (!cola.empty()) {
    pair<int, int> curr = cola.front();
    cola.pop();
    int curx = curr.first;
    int cury = curr.second;
    int curval = mat[curx][cury];
    for (int k = 0; k < 4; ++k) {
      int vx = curx + dx[k];
      int vy = cury + dy[k];
      if (vx < 0 or vy < 0 or vx >= n or vy >= m)
        continue;
      if (mat[vx][vy] == -2)
        continue;
      if (mat[vx][vy] != -1)
        continue;
      mat[vx][vy] = curval + 1;
      cola.emplace(make_pair(vx, vy));
    }
  }
  cout << mat[dest.first][dest.second];
}
