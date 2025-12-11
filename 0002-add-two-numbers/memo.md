### step1

素直に、新しいListNodeを作ってl1とl2の各桁の和を足していったものをvalに格納して、繰り上がりがある場合はそれを保存しておいてnextで足すのをl1, l2のどちらもがnullptrになるまでやるという方針でstep1の上に書いたコードで実装してみたのですが、下記のRuntime Errorが出てうまくいきませんでした。
GPTが修正した方と比べるとどうやらnewキーワードがあるかないかで挙動が変わってそうですが。
GPTの修正したものをみると条件分岐とかもかなりスッキリ書き直してくれたのでさすがだなと思いました。

```cpp
// ぼくの実装
ListNode temp(0);
curr->next = &temp;
curr = curr->next;

// GPT
curr->next = new ListNode(sum % 10);
```

```
Line 73: Char 28:
=================================================================
==22==ERROR: AddressSanitizer: stack-use-after-return on address 0x7f83311003a8 at pc 0x56112d93ba76 bp 0x7fffc2995bf0 sp 0x7fffc2995be8
READ of size 8 at 0x7f83311003a8 thread T0
    #0 0x56112d93ba75 in __ListNodeUtils__::hasCycle(ListNode*) (solution+0x1aaa75)
    #1 0x56112d92e945 in void _Serializer_::serialize<ListNode>(ListNode* const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>&) (solution+0x19d945)
    #2 0x56112d92fd74 in std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> _Serializer_::serialize<ListNode>(ListNode* const&) (solution+0x19ed74)
    #3 0x56112d91a225 in main solution.cpp:73:28
    #4 0x7f8332ec41c9  (/lib/x86_64-linux-gnu/libc.so.6+0x2a1c9) (BuildId: 6d64b17fbac799e68da7ebd9985ddf9b5cb375e6)
    #5 0x7f8332ec428a in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x2a28a) (BuildId: 6d64b17fbac799e68da7ebd9985ddf9b5cb375e6)
    #6 0x56112d843c94 in _start (solution+0xb2c94)
Address 0x7f83311003a8 is located in stack of thread T0 at offset 40 in frame
    #0 0x56112d91a84f in Solution::addTwoNumbers(ListNode*, ListNode*) solution.cpp:73
  This frame has 2 object(s):
    [32, 48) 'sum' (line 24) <== Memory access at offset 40 is inside this variable
    [64, 80) 'temp' (line 37)
HINT: this may be a false positive if your program uses some custom stack unwind mechanism, swapcontext or vfork
      (longjmp and C++ exceptions *are* supported)
SUMMARY: AddressSanitizer: stack-use-after-return (solution+0x1aaa75) in __ListNodeUtils__::hasCycle(ListNode*)
Shadow bytes around the buggy address:
  0x7f8331100100: f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5
  0x7f8331100180: f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5
  0x7f8331100200: f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5
  0x7f8331100280: f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5
  0x7f8331100300: f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5
=>0x7f8331100380: f5 f5 f5 f5 f5[f5]f5 f5 f5 f5 f5 f5 f5 f5 f5 f5
  0x7f8331100400: f1 f1 f1 f1 00 00 00 00 00 00 00 f3 f3 f3 f3 f3
  0x7f8331100480: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f8331100500: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f8331100580: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f8331100600: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
==22==ABORTING
```

GPTによると下記のようにスタック上のローカル変数を使っていたのが問題で、newすればよかったようです。この辺りよくわかっていないのでもう少し学習しておきます。

```
❗ 原因

あなたの元コードでは

ListNode sum(0);
return &sum;


のように スタック上のローカル変数（sum）のアドレスを返していた ため、

関数が終了した時点で sum は破棄され、そのポインタを外で参照し ASan がクラッシュを検出しています。

✅ 解決方法

heap で確保したノード（new）を返す ように修正する必要があります。

私が前回提示したコードはすでに heap を使っており、
このエラーは あなたが元のコードを実行したときのエラー です。

そこで、あなたのコード構造に忠実にしつつ、正しく動くように 最小修正したバージョン を示します。
```

### step2

特に変更点なし

### step3

3回通すまで書き直し。