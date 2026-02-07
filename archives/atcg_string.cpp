#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  int ans = 0;
  for (int i = 0; i < S.length(); i++) {
    int count = 0;
    if (S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T') {

      for (int j = i; j < S.length(); j++) {

        if (S[j] != 'A' && S[j] != 'C' && S[j] != 'G' && S[j] != 'T') {
          break;
        }

        count++;
      }
    }

    ans = max(ans, count);
  }

  cout << ans << endl;
}
