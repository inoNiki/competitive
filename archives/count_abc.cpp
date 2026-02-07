#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;

  cin >> N >> S;
  int count = 0;
  for (int i = 0; i < N + 1; i++) {

    if (i + 2 < N + 1) {
      if (S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C') {
        count++;
      }
    } else {
      break;
    }
  }

  cout << count << endl;
}
