#include <atcoder/all>
using namespace atcoder;
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double pi = 3.14159265359;
const ll INF = 1LL << 60;

int grundy[55][1400];

void calc_grundy()
{
  grundy[0][0] = grundy[0][1] = 0;

  for (int i = 0; i <= 50; i++){
    for (int j = 0; j <= 1325; j++){
      int mex[1400] = {0};
      if (i >= 1){
	mex[grundy[i-1][j+i]] = 1;
      }
      if (j >= 2){
	for (int k = 1; k <= (j / 2); k++) mex[grundy[i][j - k]] = 1;
      }
      for (int k = 0; k < 1400; k++){
	if (mex[k] == 0){ grundy[i][j] = k; break;}
      }
    }
  }
}


int main()
{
  int n;
  cin >> n;
  vector<int> w(n);
  vector<int> b(n);
  for (int &t : w) cin >> t;
  for (int &t : b) cin >> t;

  calc_grundy();

  int s = 0;
  for (int i = 0; i < n; i++){
    s ^= grundy[w[i]][b[i]];
  }

  cout << (s == 0 ? "Second" : "First") << endl;
  return 0;
}
