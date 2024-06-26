/*
 * Palindrome Number Theorey :-
 * All palindromic numbers with an even number of digits are divisible by 11.
 * There are 9 palindromic numbers with two digits: {11, 22, 33, 44, 55, 66, 77, 88, 99}.
 * There are 90 palindromic numbers with three digits
 * {101, 111, 121, 131, 141, 151, 161, 171, 181, 191, …, 909, 919, 929, 939, 949, 959, 969, 979, 989, 999}
*
 */
public class LargestPalindromeProduct {
    public static int largestPalindromeProduct(int n) {
        // To get the maximum n-digit number
        int max = 0;
        for (int i = 0; i < n; i++) {
            max = max * 10 + 9;
        }

        // Next, we get the minimum n-digit number from the max
        int min = (max + 1) / 10;

        // To store the result
        int largest = -1;

        // Starting the loop from max to min
        for (int i = max; i >= min; i--) {
            // Another loop
            for (int j = max; j >= min; j--) {
                // Getting the product
                int num = i * j;

                // Reversing the number
                int numReverse = reverseNumber(num);
                
                // Checking for a palindromic number
                if (num == numReverse) {
                    // Check if it's the largest and break the loop
                    largest = Math.max(num, largest);
                    break;
                }
            }
        }

        // Returning the largest found
        return largest;
    }

    public static int reverseNumber(int num) {
        int reversed = 0;
        while (num != 0) {
            int digit = num % 10;
            reversed = reversed * 10 + digit;
            num /= 10;
        }
        return reversed;
    }

    public static void main(String[] args) {
        int n = 3; // You can change n to the desired number of digits
        int result = largestPalindromeProduct(n);
        System.out.println("Largest Palindromic Product of " + n + "-digit numbers: " + result);
    }
}

