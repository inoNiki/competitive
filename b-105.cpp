#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  int answer = 0;
  for (int i = 1; i <= N; i++) {
    int waruCount = 0;
    if (i % 2 == 1) {
      for (int j = 1; j <= (i + 1) / 2; j += 2) {
        if (i % j == 0)
          waruCount++;
      }
      // 1 と Nの組合せを補正
      waruCount += 1;
    }

    if (waruCount == 8)
      answer++;
  }

  cout << answer << endl;
}
