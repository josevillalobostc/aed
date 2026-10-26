#include <bits/stdc++.h>
#include <string>
using namespace std;

string abc = "abcdefghijklmnopqrstuvwxyz";
vector<string> cadenas;
string pal = "";
int cont = 0;

void foo(string &n, int ind) {
  if (ind >= n.size()) {
    cont++;
    cadenas.push_back(pal);
    return;
  }
  string dig;
  dig.push_back(n[ind]);
  int a = stoi(dig);
  if (a < 7) {
    for (int i = (a - 1) * 3 - 3; i < (a - 1) * 3; i++) {
      pal.push_back(abc[i]);
      foo(n, ind + 1);
      pal.pop_back();
    }
  } else if (a == 7) {
    for (int i = 15; i < 19; i++) {
      pal.push_back(abc[i]);
      foo(n, ind + 1);
      pal.pop_back();
    }
  } else if (a == 8) {
    for (int i = 19; i < 22; i++) {
      pal.push_back(abc[i]);
      foo(n, ind + 1);
      pal.pop_back();
    }
  } else {
    for (int i = 22; i < 26; i++) {
      pal.push_back(abc[i]);
      foo(n, ind + 1);
      pal.pop_back();
    }
  }
}

int main() {
  string n;
  cin >> n;
  foo(n, 0);
  cout << cont << '\n';
  for (string pal : cadenas) {
    cout << pal << '\n';
  }
}
