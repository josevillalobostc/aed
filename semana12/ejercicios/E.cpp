#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<string> mat(n);
  for (int i = 0; i < n; ++i) {
    cin >> mat[i];
  }

  int INF = 1e9;
  vector<vector<int>> dist(n, vector<int>(m, INF));

  deque<pair<int, int>> D;
  vector<int> dx = {1, -1, 0, 0};
  vector<int> dy = {0, 0, 1, -1};

  D.push_front({0, 0});
  dist[0][0] = 0;

  while (!D.empty()) {
    int x, y;
    tie(x, y) = D.front();
    D.pop_front();

    for (int k = 0; k < 4; k++) {
      int vx = x + dx[k];
      int vy = y + dy[k];

      if (vx < 0 || vy < 0 || vx >= n || vy >= m)
        continue;

      int peso = (mat[vx][vy] == '#') ? 1 : 0;

      if (dist[x][y] + peso < dist[vx][vy]) {
        dist[vx][vy] = dist[x][y] + peso;
        if (peso == 0) {
          D.push_front({vx, vy});
        } else {
          D.push_back({vx, vy});
        }
      }
    }
  }

  cout << dist[n - 1][m - 1] << "\n";
  return 0;
}
