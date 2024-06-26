/*
// The prime factors of 13195 are 5, 7, 13 and 29.
// It should return Largest Prime Factor
// Approach :
 * Lets consider a example of 245
 * start with 2
 * 245%2!=0
 * so 
 * inc 2 to 3
 * check whether it is divisible by current number if Yes 
 * Divide the Number(125) by current number
 * 125/5==25
 * now Our Given Number is 25
 * Then Inc current number 5 to 6 so...on
 * repeat this until you exceed our Number
 * 
 * 
 * 
 * Test Cases :-
 * largestPrimeFactor(2) should return a number.
    Passed:largestPrimeFactor(2) should return 2.
    Passed:largestPrimeFactor(3) should return 3.
    Passed:largestPrimeFactor(5) should return 5.
    Passed:largestPrimeFactor(7) should return 7.
    Passed:largestPrimeFactor(8) should return 2.
    Passed:largestPrimeFactor(13195) should return 29.
    Passed:largestPrimeFactor(600851475143) should return 6857.
 */
public class largestPrimeFactor{
public static void main(String[] args) {
    long number = 906609;
    long currentPrime=2;
    long max=0;
    while(currentPrime<=number)
    {
        if(number%currentPrime==0)
        {
            max=currentPrime;
            number/=currentPrime;
        }
        currentPrime++;
    }
    System.out.println("largestPrimeFactor("+number+") is :"+max);
}
}