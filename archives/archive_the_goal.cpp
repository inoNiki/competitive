#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  int K;
  int M;

  cin >> N >> K >> M;

  int total = 0;
  for (int i = 0; i < N - 1; i++) {
    int A = 0;
    cin >> A;
    total += A;
  }

  int result = 0;
  for (int i = 0; i < K + 1; i++) {
    if ((total + i) / N >= M) {
      result = i;
      break;
    } else {
      result = -1;
    }
  }

  cout << result << endl;
}
