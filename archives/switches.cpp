#include <bits/stdc++.h>
using namespace std;

#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> A(M);

  for (int i = 0; i < M; i++) {
    int s = 0;
    cin >> s;
    for (int j = 0; j < s; j++) {
      int tmp = 0;
      cin >> tmp;
      tmp--;
      A.at(i).push_back(tmp);
    }
  }

  vector<int> P(M);
  for (int i = 0; i < M; i++)
    cin >> P.at(i);

  int ans = 0;
  for (int bit = 0; bit < (1 << N); bit++) {
    bool is_light_on = true;
    for (int i = 0; i < M; i++) {
      int onCount = 0;
      for (auto v : A.at(i)) {
        if (bit & (1 << v)) {
          onCount++;
        }
      }
      if (onCount % 2 != P.at(i)) {
        is_light_on = false;
      }
    }
    if (is_light_on) {
      ans++;
    }
  }

  cout << ans << endl;
}
