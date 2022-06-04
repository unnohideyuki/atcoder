#include <atcoder/all>
using namespace atcoder;
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double pi = 3.14159265359;
const ll INF = 1LL << 60;

int lut['z'-'a'+1][100001];

int main()
{
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  for (char c = 'a'; c <= 'z'; c++){
    int j = 200000;
    for (int i = s.length() - 1; i >= 0; i--){
      if (s[i] == c) j = i;
      lut[c-'a'][i] = j;
    }
  }
  
  string ans = "";
  int l = 0;
  for (int i = 0; i < k; i++){
    int r = n - k + 1 + i;
    for (char c = 'a'; c <= 'z'; c++){
      if (lut[c-'a'][l] < r){
	ans += c;
	l = lut[c-'a'][l] + 1;
	break;
      }
    }
  }
  
  cout << ans << endl;
  return 0;
}
