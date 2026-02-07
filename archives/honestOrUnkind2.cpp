#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<vector<int>> X(N);
  vector<vector<int>> Y(N);
  int A = 0;
  for (int i = 0; i < N; i++) {
    cin >> A;
    for (int j = 0; j < A; j++) {
      int x, y;
      cin >> x >> y;
      X.at(i).push_back(x - 1);
      Y.at(i).push_back(y);
    }
  }

  int honest = 0;
  // bit flag が立っている場合、正直者であるとみなす
  // 正直ものN人のうちbit番にあたる人を正直者として仮定し全探索
  for (int bit = 0; bit < (1 << N); bit++) {

    // 正直者か否かを定義したbit(1 << N)に対してN人分の発言すべてを精査するため
    // 発言とbitの整合性をチェックするフラグはこの位置で宣言する
    bool flag = true;
    // N人分ループ
    // i番目の人の発言を精査する
    for (int i = 0; i < N; i++) {
      // そもそもi番目の人が嘘つきだと仮定すると発言に信憑性がなにのでスキップ
      if (!(bit & (1 << i)))
        continue;

      // i番目の人の発言を精査
      for (size_t j = 0; j < X.at(i).size(); j++) {
        int x = X.at(i).at(j);
        int y = Y.at(i).at(j);

        // x番目の人が正直者だと発言している場合
        if (y == 1) {
          // 現在のbitと比較して、bitが嘘つき(0)の場合は整合性がとれていないと判断
          if (!(bit & (1 << x)))
            flag = false;

          // x番目の人が嘘つきだと発言している場合
        } else {
          // 現在のbitと比較して、bitが正直者(1)の場合は整合性がとれていないと判断
          if (bit & (1 << x))
            flag = false;
        }
      }
    }

    // あるbitについて全員の発言と整合性が取れいていた場合に限りカウントする
    if (flag) {
      honest = max(honest, __builtin_popcount(bit));
    }
  }

  cout << honest << endl;
}