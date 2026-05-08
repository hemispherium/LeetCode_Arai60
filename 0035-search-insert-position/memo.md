### step1

findとlower_boundを使ってit != nums.end()のときはそのイテレータ、そうでない場合は配列のサイズを返すようにした。

### step2

他の方のコード（https://github.com/5ky7/arai60/pull/41/changes#diff-0c860cd754249868513e4f9054206317fa33d0f548fc3896ac2b3e11822fd852R19）を見てみると、lower_bound自体を実装していたので自分も実装してみた。

### step3

step2を3回通すまで書き直し。
