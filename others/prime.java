/*
 * Prime numbers :- 
 * 1......firstPrimeFactoe....sqrt(N)....PAIRS.....N/fpf..No Factor zone..(N-1)..N
 * Theorem 1 :
 * Every Composite number X has atleast One prime number factor less than or equal to sqrt(X)
 * Theorem 2 :
 * Every prime number (X>3) is of the form "(6*n+1)" or "(6*n-1)".
 */
import java.lang.Math;
public class prime {
    public static void main(String[] args) {
        long num;
        long i;
        int flag=1;
        num=10000000019l;
        long sqr = (long) Math.sqrt(num);
        long start_milli=System.currentTimeMillis();
        long start_nano=System.nanoTime();
        long end_milli;
        long end_nano;
        if(num % 2 ==0  || num % 3 == 0)flag = 1 ;
        for(i=5;(6*i-1)<sqr;i+=1)
        {
            if(num % (6*i-1)== 0 || num % (6*i+1) ==0 )
            {
                flag=0;
                break;
            }
        }
        if ( flag ==1 )    System.out.println("Prime");
        else  System.out.println("Not Prime");
        end_milli=System.currentTimeMillis();
        end_nano=System.nanoTime();
        System.out.println("Time : "+(end_milli-start_milli)/1000.0);
        System.out.println((end_nano-start_nano));
    }
    
}
