#include <bits/stdc++.h>
using namespace std;

vector<string> cadenas;

void foo(string S, int &n, int &cant) {
  int tam = S.size();
  if (tam == n) {
    cant++;
    cadenas.push_back(S);
  } else if (S[tam - 1] == '0') {
    S.push_back('0');
    foo(S, n, cant);
    S.pop_back();
    S.push_back('1');
    foo(S, n, cant);
    S.pop_back();
  } else if (S[tam - 1] == '1') {
    S.push_back('0');
    foo(S, n, cant);
    S.pop_back();
  }
}

int main() {
  int n;
  cin >> n;
  string S = "0";
  int cant = 0;
  foo(S, n, cant);
  S.pop_back();
  S.push_back('1');
  foo(S, n, cant);
  cout << cant << '\n';
  for (auto pal : cadenas) {
    cout << pal << '\n';
  }
}
