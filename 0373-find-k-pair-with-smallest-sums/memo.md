### step1

最初nums1, nums2の組み合わせを全探索してpriority_queueに入れて、小さい順に取り出す方法を思いついてTLE思想だと思ったが、それ以外思いつかなかったのでそれで実装。Naoto Iwaseさんのコードを参考に修正。nums1はindex 0のものとnums2はk個目までの和を最初にpriority_queueに入れておいて、popするたびにnums1のindexをインクリメントしたものをpriority_queueにpushするという実装。これで時間計算量はO(nums1 * nums2)からO(k)に落ちると思う。

### step2

特に変更点なし

### step3

3回通すまで書き直し。
