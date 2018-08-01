Q. Implement a program that encrypts messages using Vigenère’s cipher, per the below.

$ ./vigenere ABC
plaintext:  HELLO
ciphertext: HFNLP

Done By C language.

BACKGROUND
Vigenère’s cipher improves upon Caesar’s cipher by encrypting messages using a sequence of keys (or, put another way, a keyword). In other words, if p is some plaintext and k is a keyword (i.e., an alphbetical string, whereby A represents 0, B represents 1, C represents 2, …​, and Z represents 25), then each letter, ci, in the ciphertext, c, is computed as:

Ci=(Pi+kj)mod26

Note this cipher’s use of kj as opposed to just k. And if k is shorter than p, then the letters in k must be reused cyclically as many times as it takes to encrypt p.

In other words, if Vigenère himself wanted to say HELLO to someone confidentially, using a keyword of, say, ABC, he would encrypt the H with a key of 0 (i.e., A), the E with a key of 1 (i.e., B), and the first L with a key of 2 (i.e., C), at which point he’d be out of letters in the keyword, and so he’d reuse (part of) it to encrypt the second L with a key of 0 (i.e., A) again, and the O with a key of 1 (i.e., B) again. And so he’d write HELLO as HFNLP.

https://docs.cs50.net/2018/x/psets/2/vigenere/vigenere.html