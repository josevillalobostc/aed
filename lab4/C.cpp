#include <bits/stdc++.h>
using namespace std;

void foo(vector<vector<int>> &mat, int &n, int &m, int i, int j, int &cant) {
  if (i >= n || j >= m || i < 0 || j < 0 || mat[i][j] != 0) {
    return;
  } else if (i == n - 1 && j == m - 1) {
    cant++;
    return;
  } else {
    mat[i][j] = 2;
    foo(mat, n, m, i + 1, j, cant);
    foo(mat, n, m, i - 1, j, cant);
    foo(mat, n, m, i, j + 1, cant);
    foo(mat, n, m, i, j - 1, cant);
    mat[i][j] = 0;
    return;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat;
  for (int i = 0; i < n; i++) {
    mat.push_back(vector<int>(m));
  }
  for (int i = 0; i < n; i++) {
    string cad;
    cin >> cad;
    for (int j = 0; j < m; j++) {
      if (cad[j] == '.') {
        mat[i][j] = 0;
      } else {
        mat[i][j] = 1;
      }
    }
  }
  int cant = 0;
  foo(mat, n, m, 0, 0, cant);
  cout << cant;
}
