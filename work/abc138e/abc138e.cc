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

  int n = s.length();
  vector<vector<int>> d('z'-'a'+1);

  for (int i = 0; i < n*2; i++){
    char c = s[i%n];
    d[c - 'a'].push_back(i);
  }

  ll pos = -1;
  for (int i = 0; i < t.length(); i++){
    char c = t[i];
    vector<int> &v = d[c-'a'];

    if (v.size() == 0){
      cout << -1 << endl;
      return 0;
    }

    auto it = upper_bound(v.begin(), v.end(), pos % n);
    pos += *it - (pos % n);
  }

  cout << pos + 1 << endl;
  return 0;
}
