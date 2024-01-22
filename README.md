# Project Euler:

This repository contains my solutions to problems from Project Euler.
All solutions are written in C++.

If you find any issues in any of the solutions, feel free to open an issue or put a pull request.

## Approach to certain problems:
I found certain problems fascinating and have written down my approach to solve those problems. These are not the most optimal appoaches, but certainly better than bruteforcing.

### Problem 41 (Champernowne's Constant):
The bruteforce approach to solve this would be to iterate from 0 till 1000000 and store the numbers in a string. Then lookup the index value from string like 1, 10, 100 etc and multiply those values to get the result. This approach is simple but takes up too much time to generate the string, also consuming more memory.

The general idea is to eliminate the need of a lookup string, given that Champernowne's constant has the unique property that it comprises of natural numbers written in concatenation, one can simply count what digit a certain index would point to.

1 digit numbers: 9 (1-9)
2 digit numbers: 90 (10-99)
3 digit numbers: 900 (100-999)

Likewise, we know number of n-digit numbers. Based on this information, it is easy to calculate the number of digits the index would point to.
```
For example D(100):
100 > 9 (not over 1 digits)

100 < (90*2 + 9) (there are 180 (90*2) two digits and 9 one digits)

Based on the above statement, we know 100th index would point to a 2 digit number.
```

Once the n of "n-digit" is figured out, we know the starting of the n digit number.
```
We know that 10 is the first 2 digit number.
Call this modified origin.
```

Then we shift the index to start from n-digit source rather than from 1.
```
Since two digit numbers start from 10, we have to eliminate all smaller length digits.
100 - 9*1(one digit number count) = 91.

Now we need to find 91st index of the series starting from 10.
Call this modified index; 
```

Number of digits passed in that range: `modified origin  + (modified index / n)`, where n is the number of digits in modified origin.
```
10 + (91 / 2)
10 + 45 = 55
```

The value at `(modified_index % n) - 1` index of the above result would be the value at original index.
```
91 % 2 - 1 = 1 - 1 = 0
At index 0, value = 5
```

Another example of D(1000):
```
1000 > 9 (one digit numbers)
1000 > (90*2 + 9) (two digit numbers)
1000 < (900*3 + 90*2 + 9) (three digit numbers)

1000th index lies over a three digit number.

modified origin = 100 (first three digit number)
modified index = 1000 - (9*1) - (90*2) = 811

modified origin  + (modified index / n)
100 + (811 / 3)
100 + 270
370

index: (modified_index % n) - 1
index: (811 / 3) - 1
index: 0

0th index of 370: 3

1000th index of Champernowne's Constant : 3
```
