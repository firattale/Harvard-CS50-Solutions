Q:Implement a program that determines whether a provided credit card number is valid according to Luhn’s algorithm.

So what’s the secret formula? Well, most cards use an algorithm invented by Hans Peter Luhn, a nice fellow from IBM. According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:

Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products' digits together.

Add the sum to the sum of the digits that weren’t multiplied by 2.

If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

That’s kind of confusing, so let’s try an example with my AmEx: 378282246310005.

For the sake of discussion, let’s first underline every other digit, starting with the number’s second-to-last digit:

378282246310005

Okay, let’s multiply each of the underlined digits by 2:

7•2 + 2•2 + 2•2 + 4•2 + 3•2 + 0•2 + 0•2

That gives us:

14 + 4 + 4 + 8 + 6 + 0 + 0

Now let’s add those products' digits (i.e., not the products themselves) together:

1 + 4 + 4 + 4 + 8 + 6 + 0 + 0 = 27

Now let’s add that sum (27) to the sum of the digits that weren’t multiplied by 2:

27 + 3 + 8 + 8 + 2 + 6 + 1 + 0 + 5 = 60

Yup, the last digit in that sum (60) is a 0, so my card is legit!

So, validating credit card numbers isn’t hard, but it does get a bit tedious by hand.

Done By C language.

