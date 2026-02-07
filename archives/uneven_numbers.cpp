#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin >> N;

  int count = 0;
  for (int i = N; i > 0; i--) {

    int keta = 0;
    int temp = i;
    while (temp != 0) {
      temp /= 10;
      keta++;
    }

    if (keta % 2 != 0) {
      count++;
    }
  }

  cout << count << endl;
}
