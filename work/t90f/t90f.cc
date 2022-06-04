#include <atcoder/all>
using namespace atcoder;
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double pi = 3.14159265359;
const ll INF = 1LL << 60;

pair<char, int> op(pair<char, int> a, pair<char, int> b)
{
  return min(a, b);
}

pair<char, int> e()
{
  return make_pair('z' + 1, 100001);
}

int main()
{
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  segtree<pair<char, int>, op, e> seg(n);
  
  for (int i = 0; i < n; i++){
    seg.set(i, make_pair(s[i], i));
  }

  string ans = "";

  int l = 0;
  for (int i = 0; i < k; i++){
    int r = n - k + 1 + i;
    auto [c, j] = seg.prod(l, r);
    ans += c;
    l = j + 1;
  }
  
  cout << ans << endl;
  return 0;
}
