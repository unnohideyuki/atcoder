#include <atcoder/all>
using namespace atcoder;
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double pi = 3.14159265359;
const ll INF = 1LL << 60;

vector<vector<pair<int, int>>> edges; // (dst, cost)
vector<ll> dist;
vector<int> par;

void
dijkstra(int n, int s)
{
  for (int i = 0; i < n; i++){
    dist[i] = INF;
  }

  priority_queue<
    tuple<ll, int, int>, // (d, next, par)
    vector<tuple<ll, int, int>>,
    greater<tuple<ll, int, int>>
    > que;

  dist[s] = 0;
  que.push(tuple(0, s, -1));

  while (que.size() > 0){
    auto [d, i, p] = que.top();
    que.pop();

    if (d > dist[i]) continue;
    dist[i] = d;
    par[i] = p;

    for (auto t : edges[i]){
      auto [j, c] = t;
      if (dist[j] > d + c){
	dist[j] = d + c;
	que.push(make_tuple(d + c, j, i));
      }
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;

  edges.resize(n);
  dist.resize(n);
  par.resize(n);

  vector<int> a(m);
  vector<int> b(m);
  vector<int> c(m);

  for (int i = 0; i < m; i++){
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
    edges[a[i]].push_back(make_pair(b[i], c[i]));
    edges[b[i]].push_back(make_pair(a[i], c[i]));
  }

  set<pair<int, int>> s;

  for (int i = 0; i < n; i++){
    dijkstra(n, i);
    for (int j = 0; j < n; j++){
      int a = j;
      int b = par[j];
      if (a > b) swap(a, b);
      if (s.count(make_pair(a, b)) == 0){
	s.insert(make_pair(a, b));
      }
    }
  }
  
  int ans = 0;
  for (int i = 0; i < m; i++){
    int x = a[i];
    int y = b[i];
    if (x > y) swap(x, y);
    if (s.count(make_pair(x, y)) == 0){
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
