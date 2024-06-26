/*

---------------------------------------------------

LeetCode 342 Integer Break

----------------------------------------------------
 * Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

 

Example 1:

Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.
Example 2:

Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
****************************************************************************
Approach :
For convenience, say n is sufficiently large and can be broken into any smaller real positive numbers. We now try to calculate which real number generates the largest product.
Assume we break n into (n / x) x's, then the product will be xn/x, and we want to maximize it.

Taking its derivative gives us n * xn/x-2 * (1 - ln(x)).
The derivative is positive when 0 < x < e, and equal to 0 when x = e, then becomes negative when x > e,
which indicates that the product increases as x increases, then reaches its maximum when x = e, then starts dropping.

This reveals the fact that if n is sufficiently large and we are allowed to break n into real numbers,
the best idea is to break it into nearly all e's.
On the other hand, if n is sufficiently large and we can only break n into integers, we should choose integers that are closer to e.
The only potential candidates are 2 and 3 since 2 < e < 3, but we will generally prefer 3 to 2. Why?

Of course, one can prove it based on the formula above, but there is a more natural way shown as follows.

6 = 2 + 2 + 2 = 3 + 3. But 2 * 2 * 2 < 3 * 3.
Therefore, if there are three 2's in the decomposition, we can replace them by two 3's to gain a larger product.

All the analysis above assumes n is significantly large. When n is small (say n <= 10), it may contain flaws.
For instance, when n = 4, we have 2 * 2 > 3 * 1.
To fix it, we keep breaking n into 3's until n gets smaller than 10, then solve the problem by brute-force.
 */

import java.util.Scanner;

public class integerBreaker {
    public static int integerBreak(int n)
    {
        if(n<=6)
        {
            if(n%2 == 0)
            {
                return (n/2)*(n/2);
            }
            else
            {
                return (n/2)*(n/2+1);
            }
        }
        else
        {
            int result=1;
            while(n>6)
            {
                result*=3;
                n-=3;
            }
            return result * integerBreak(n);
        }
    } 
    public static void main(String[] args) {
        Scanner kbc = new Scanner(System.in);
        int n = kbc.nextInt();
        System.out.println(integerBreak(n));
        
    }
}
