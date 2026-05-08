### step1

とりあえずmin_elementでいいんじゃないかと思ったら通ってしまった。調べたところO(log n)の計算量になっていそう。（https://cpprefjp.github.io/reference/algorithm/min_element.html）

### step2

二分探索で解くことはなんとなくわかったが回転をどう扱うかがわからなかったので、https://github.com/dxxsxsxkx/leetcode/pull/42/changes#diff-b8164221e20e16697b74cbe72c0f4afcb99f7e73d1eef967d2e3ec61628564b5R1 こちらの実装やChatGPTの力を借りて実装。
考え方としては、回転があるので区間の真ん中で分けるとソートされている側と最小値のところで大きい→小さいの切れ目がある側に分けられる。
このうち二分探索で切れ目のある側を絞り込んでいく。

### step3

3回通すまで書き直し。
