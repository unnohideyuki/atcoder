#include <atcoder/all>
using namespace atcoder;
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double pi = 3.14159265359;
const ll INF = 1LL << 60;

vector<vector<int>> edges;

void
dijkstra(vector<ll> &dist, int s)
{
  priority_queue<
    pair<ll, int>,
    vector<pair<ll, int>>,
    greater<pair<ll, int>>> que;

  que.push(make_pair(0, s));
  dist[s] = 0; // これを忘れていた
  
  while (que.size() > 0){
    auto [d, i] = que.top();
    que.pop();

    if (d > dist[i]) continue; // == のケースで continue してはダメ
    
    for (int j : edges[i]){
      if (dist[j] > d + 1){
	dist[j] = d + 1;
	que.push(make_pair(d+1, j));
      }
    }
  }
}


int main()
{
  int n;
  cin >> n;
  edges.resize(n);

  for (int i = 0; i < n-1; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  vector<ll> dist1(n, INF);
  vector<ll> distN(n, INF);

  dijkstra(dist1, 0);
  dijkstra(distN, n-1);

  int nf = 0, ns = 0;
  for (int i = 0; i < n; i++){
    if (dist1[i] <= distN[i]){
      nf++;
    } else {
      ns++;
    }
  }

  cout << (nf > ns ? "Fennec" : "Snuke") << endl;
  return 0;
}
