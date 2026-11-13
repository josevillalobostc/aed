#include <bits/stdc++.h>
using namespace std;
vector<string> maze(501);
vector<vector<int>> visited(500, vector<int>(500, -1));
string snuke = "snuke";

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

int h, w;

void dfs(int x, int y, int k) {
  visited[x][y] = 1;
  for (int i = 0; i < 4; ++i) {
    int vx = x + dx[i];
    int vy = y + dy[i];
    if (vx < 0 || vy < 0 || vx >= h || vy >= w)
      continue;
    if (maze[vx][vy] != snuke[k])
      continue;
    if (visited[vx][vy] == 1)
      continue;
    dfs(vx, vy, (k + 1) % 5);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> h >> w;
  for (int i = 0; i < h; ++i) {
    cin >> maze[i];
  }
  if (maze[0][0] != 's') {
    cout << "No" << '\n';
    return 0;
  }
  dfs(0, 0, 1);
  if (visited[h - 1][w - 1] == 1) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
}
