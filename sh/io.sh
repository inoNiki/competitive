#!/bin/bash

cd ~/dev/competitive/

if [ "$1" == "test" ]; then
  # --- 区切りで複数テストケースを分割実行し、期待出力と比較
  # 使い方: io.sh test [expected.json]
  case_num=0
  tmpfile=$(mktemp)

  while IFS= read -r line; do
    if [ "$line" == "---" ]; then
      case_num=$((case_num + 1))
      echo "=== Case $case_num ==="
      ./a.out < "$tmpfile"
      echo ""
      > "$tmpfile"
    else
      echo "$line" >> "$tmpfile"
    fi
  done < in.txt

  # 最後のケースを実行
  if [ -s "$tmpfile" ]; then
    case_num=$((case_num + 1))
    echo "=== Case $case_num ==="
    ./a.out < "$tmpfile"
    echo ""
  fi
  rm "$tmpfile"

elif [ $# -eq 0 ]; then
  # デフォルト: --- 区切りがあれば分割実行、なければ従来通り
  if grep -q "^---$" in.txt 2>/dev/null; then
    # --- が含まれている場合: 分割実行し out.txt に全出力
    tmpfile=$(mktemp)
    > out.txt
    case_num=0

    while IFS= read -r line; do
      if [ "$line" == "---" ]; then
        case_num=$((case_num + 1))
        echo "--- Case $case_num ---" >> out.txt
        ./a.out < "$tmpfile" >> out.txt
        echo "" >> out.txt
        > "$tmpfile"
      else
        echo "$line" >> "$tmpfile"
      fi
    done < in.txt

    if [ -s "$tmpfile" ]; then
      case_num=$((case_num + 1))
      echo "--- Case $case_num ---" >> out.txt
      ./a.out < "$tmpfile" >> out.txt
      echo "" >> out.txt
    fi
    rm "$tmpfile"
  else
    # --- がない場合: 従来通り
    ./a.out <in.txt >out.txt
  fi

elif [ "$1" == "term" ]; then
  ./a.out <in.txt
else
  ./a.out <in.txt >"$1.txt"
fi
