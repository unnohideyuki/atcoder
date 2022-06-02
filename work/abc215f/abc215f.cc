#include <atcoder/all>
using namespace atcoder;
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double pi = 3.14159265359;
const ll INF = 1LL << 60;

int main()
{
  int n;
  cin >> n;

  vector<pair<ll,ll>> pos(n);
  for (int i = 0; i < n; i++){
    cin >> pos[i].first >> pos[i].second;
  }
  sort(pos.begin(), pos.end());

  ll ok = 0;
  ll ng = INF;

  while (ng - ok > 1){
    ll mid = (ng + ok) / 2;
    ll mi = INF, ma = -1;
    int j = 0;
    bool found = false;
    for (int i = 1; i < n; i++){
      auto [x, y] = pos[i];
      while (pos[j].first <= x - mid){
	auto [u, v] = pos[j++];
	mi = min(mi, v);
	ma = max(ma, v);
      }
      if (mi <= y - mid || ma >= y + mid) found = true;
    }

    if (found) ok = mid;
    else ng = mid;
  }
  
  cout << ok << endl;
  return 0;
}
