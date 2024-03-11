# Explanation of the solution

    In this problem constraints are quite high and it is mandatory to implement an efficient solution. Note that `1 < |s| < 1e5`. Same goes for number of queries we will be asked.

**Some things you should notice**
Every palindrome is symetric.

- That means that if the length of the string is even then each character occuring in that string have an even number of characters otherwise it can't be a palindrome.
- If the length of the string is odd then the character in middle of the string have an odd number of occuring since its symetric is himself

**Important**
Were are also allowed to reorder the letters of the string after the substitution this is the points that

With those remarks if the length of a string is `even` then all we need to have a palindrome is to make sure that every letter occuring in the string have an even number of occurence. In the other hand if the length of the string is odd then we need to make sure that every letter occuring in the string have an even number of occurence letters and there is exactly one letter with odd number of occurence (that letter will be the one in the middle of the string after reordering).

Using those conditions we can always create a palindrome with the set of letters we have

**Classic approach of the problem**
For every given query of the form [l, r] loop over all that substring and count the number of occurences of each character either using map or hashmap or whatever you want. Now we have two case :

    - The length of that substring is even
        In this case all characters occuring and even number time ne don't need to care abou them since we can pair them synmetricically to have a palindrome. Now with the character with odds number of occurence we need to transform some of them to other so we can keep all occurence even. Here `a greedy` approch which is the optimal one is to always chose two characters with odds numbers substitut one by the other one then both of them will have even number of occurences. You can see that with 1 move we can fix two characters so the minimum number of substitutions need to fix that substring wil be the number of characters having odd number of occurences divided by 2 (that number is always even why ? Try to demontrate it. It is pretty easy)
    - The substring of that substring is odd
        The same algorithm describe for the previous case is also valid here only note that here the number of characters in the substring having odd number of occurences is odd (try to prove it too). The answer is now cnt (where cnt is the number of character in the substring having odd number of occurences) divided by 2 rounded down (cnt = 9 ans = 4)

With all that the only thing you need is to check weither this minimum number of subsitution is less or equal to the given trie. If yes then the answer would be '1' otherwise '0' since we cannot make it a palindrom.

The problem in this approach is that the time complexity is really bad `O(N * Q)` where N is the length of the string and Q is the number of queries. Technically this would take around 90 seconds to finish if the testcases are strong

**Prefix sum approach**
The question is how to caclulate for each substring the number of occuring of each character fast ? This can be done with prefix sum. This helps us compute the sum over a substring in O(1) for each chracter with a precompute of O(n). Since the number of characters or letters here is **26** then the time complexity will be multipled by 26 which is still good to pass the testcase. Now our time complexity `O(26 * Q) around O(Q * log(Q))` This is fast enough to pass all test under 1 seconds in (c++)

If you are not awared of **prefix sum** then check on wikipedia or youtube ....
