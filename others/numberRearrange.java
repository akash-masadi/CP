/*
David and Ross both work in the same office but in different departments. David needs to share a password
protected file with Ross. David made a minor change to the password so that file cannot be accessed by
anyone else. He interchanged a few digits of the password and shared the new password with a hint to
generate the actual password
Hint:
Reverse all the elements from point A to point B (both A and B inclusive), where point A and B are given
PASSWORD is a Positive Integer
Write an algorithm to reverse the elements of the password to get the actual password so that file can be
opened
Input
First Line  - Converted Password
The next line consists of two space separated integers - startPoint and endPoint representing two points
A and B to reverse the elements
Output
Print The Original Password
Example :
Position 123456789012
         000000000111
         345689012345
         341098652345
3 8
Output:
341098652345
10000 <= n <= 1000000000000000000

  345678
345689012345
3 8

*/
class numberRearrange
{
    public static long reverse(long num)
    {
        long rev = 0;
        while(num!=0)
        {
            rev = rev*10 + num % 10;
            num/=10;
        }
        return rev;
    }
    public static int numOfDigits (long n)
    {
        int count = 0;
        while(n!=0)
        {
            count++;
            n/=10;
            // System.out.println(n);
        }
        
        return count;
    }
    public static long generatePow(int n)
    {
        long power = 1l;
        while(n>0)
        {
            power*=10;
            n--;
            // System.out.println(n+" "+power);
        }
        return power;
    }
    public static void main(String[] args) {
        long number = 345689012345L;
        int initialIndex = 3;
        int endIndex = 8;
        int nod = numOfDigits(number);
        long leftSlicer = generatePow((nod-initialIndex+1));        
        long rightSlicer = generatePow((nod-endIndex));        
        // System.out.println((nod-initialIndex+1)+ " " + (nod-endIndex)+" "+nod);
        long leftPart = number / leftSlicer;
        long rightPart = number % rightSlicer;
        long requiredMid = (number % leftSlicer) / rightSlicer;
        requiredMid = reverse(requiredMid);
        // System.out.println(rightPart+ " " + leftPart+" "+requiredMid);
        
        long result = leftPart * leftSlicer + requiredMid * rightSlicer + rightPart;
        System.out.println(result);

    }
}