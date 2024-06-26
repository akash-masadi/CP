class LcmHcf
{
    static long gcd(long num1 , long num2)
    {
        if(num2 == 1) 
        {
            return 1;
        }
        if(num2 ==0) 
        {
            return num1;
        }
        else 
        {
            return gcd (num2,num1%num2);
        }

    }
    static long lcm(long num1, long num2)
    {
        long g = gcd(num1,num2);
        return (num1 / g) * num2;
    }
    public static void main(String[] args) {
        System.out.println("GCD :"+gcd(24,gcd(90,72)));
        System.out.println("LCM :"+lcm(24,lcm(90,72)));
    }
}