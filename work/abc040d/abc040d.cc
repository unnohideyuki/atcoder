#include <atcoder/all>
using namespace atcoder;
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double pi = 3.14159265359;
const ll INF = 1LL << 60;

vector<int> d;

void
init(int n)
{
  d.resize(n);
  for (int& x : d){ x = -1; }
}

int
find(int i)
{
  int par = d[i];
  if (par < 0){
    return i;
  } else {
    return d[i] = find(par);
  }
}

void
unite(int i, int j)
{
  int x = find(i);
  int y = find(j);
  if (x != y){ // 最初忘れていた
    d[x] += d[y];
    d[y] = x;
  }
}

bool
same(int i, int j)
{
  return find(i) == find(j);
}

int
size(int i)
{
  int par = find(i);
  return -d[par];
}

int main()
{
  int n, m;
  cin >> n >> m;

  vector<tuple<int, int, int>> roads(m);
  for (int i = 0; i < m; i++){
    int a, b, y;
    cin >> a >> b >> y;
    roads[i] = make_tuple(y, a - 1, b - 1);
  }
  sort(roads.begin(), roads.end(), greater<tuple<int, int, int>>{});

  int q;
  cin >> q;

  vector<tuple<int, int, int>> peoples(q);
  for (int i = 0; i < q; i++){
    int v, w;
    cin >> v >> w;
    peoples[i] = make_tuple(w, v - 1, i);
  }
  sort(peoples.begin(), peoples.end(), greater<tuple<int, int, int>>{});

  init(n);
  
  vector<int> ans(q);
  int j = 0;
  for (int i = 0; i < q; i++){
    auto [w, v, num] = peoples[i];
    auto [y, a, b] = roads[j];
    while (y > w){
      unite(a, b);
      if (++j >= m){ break; }
      auto [ty, ta, tb] = roads[j];
      y = ty; a = ta; b = tb;
    }
    ans[num] = size(v);
  }

  for (int i = 0; i < q; i++){
    cout << ans[i] << endl;
  }
  return 0;
}
