### step1
累積和の差がkになる部分をカウントすればいいところまでは思いついたが、うまく実装できなかったのでChatGPTに聞いてsumを管理しながらそれまでの累積和からsum - kをカウントする方法で実装。

### step2
unordered_mapの名前をmpからprefixSumCountに変更。

### step3
3回通すまで書き直し。