#include <bits/stdc++.h>
using namespace std;

int main() {
  int A;
  int B;
  int K;

  cin >> A >> B >> K;

  vector<int> commonDiviser(max(A, B));

  for (int i = 1; i <= A; i++) {
    if (A % i == 0 && B % i == 0) {
      commonDiviser.push_back(i);
    }
  }

  sort(commonDiviser.rbegin(), commonDiviser.rend());
  cout << commonDiviser.at(K - 1) << endl;
}
