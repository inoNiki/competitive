#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  rep(i, 0, N) cin >> A.at(i);

  int minimum = 0, maximum = 0;
  rep(i, 0, N) {
    if (i == 0) {
      minimum = A.at(i);
      maximum = A.at(i);
      continue;
    }

    minimum = min(A.at(i), minimum);
    maximum = max(A.at(i), maximum);
  }

  cout << maximum - minimum << endl;
}