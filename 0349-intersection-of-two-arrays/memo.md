### step1

nums1とnums2をsetに入れて、制約である0-1000までの値の中で両方のsetに
時間計算量はnums1, nums2の長さをN,MとしてO(NlogN + MlogM + 1000 * (logN + logM))になると思います。

### step2

step1のコードをGPTにより簡潔で高速なコードに修正してもらいました。
時間計算量はO(N + M)に改善されると思います。

### step3

step2のコードを3回通すまで書き直し。