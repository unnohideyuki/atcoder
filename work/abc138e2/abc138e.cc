#include <atcoder/all>
using namespace atcoder;
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double pi = 3.14159265359;
const ll INF = 1LL << 60;

int main()
{
  string s, t;
  cin >> s >> t;

  int n = 'z' - 'a' + 1;

  vector<vector<int>> lut(n);

  for (char c : t){
    if (lut[c - 'a'].size() > 0) continue;
    lut[c - 'a'].resize(s.length() * 2);

    int pos = -1;
    for (int j = s.length() * 2 - 1; j >= 0; j--){
      if (s[j % s.length()] == c){
	pos = j;
      }
      lut[c - 'a'][j] = pos >= 0 ? pos - j : -1;
    }

    if (pos < 0){
      cout << -1 << endl;
      return 0;
    }
  }

  ll pos = 0;
  for (char c : t){
    int k = lut[c-'a'][pos % s.length()];
    pos += k + 1;
  }

  cout << pos << endl;
  return 0;
}
