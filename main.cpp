#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)

int main() {
  int N = 8;
  int count = 0;
  for (int bit = 0; bit < (1 << N); bit++) {

    cout << "count = " << count << " : " << bitset<8>(bit) << endl;
    count++;
  }

  cout << bitset<8>(1 << 0) << endl;

  cout << "sample" << endl;
}
