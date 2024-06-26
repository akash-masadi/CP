/*
 * Generate armstrong numbers in a given range
 * Sum of digitd raised to the power of number of digitd in itself 
 *  Approach 1:
 *  using log10() and pow() at a cost of more run time
 * approach 2:
 * using Functions for calculating number of digits() and ownPower()
 * Approach 3:
 * maintaing the Matrix of powers of each number from 0 to 9 
 * and updating it with number of digits increased
 * 
 */

public class gen_arms_range { 
    static int[] matrix=new int[10];
    public static int myPow(int power,int num)
    {
        int res=1;
        while(power!=0) {
            res*=num;
            power-=1;
        }
        return res;
    }
    public static void update()
    {
        for(int i=0;i<10;i++)
        {
            matrix[i]*=i;
        }
    }
    public static void main(String[] args) {
        int num;
        int sum;
        //Number is digits is not neccesary in this algo
        // we have to maintain the matrix correctly according to the number of digits
        // int nod;
        int remainder;
        int copy;
        long start_milli=System.currentTimeMillis();
        long start_nano=System.nanoTime();
        long end_milli;
        long end_nano;
        for(int i=0;i<10;i++)
        {
            matrix[i]=i*i*i;
        }
        int limit=1000;
        // nod=3;
        for(num=100;num<100000000;num++)
        {
            copy=num;
            sum=0;
            while(num!=0)
            {
                remainder=num%10;
                sum+=matrix[remainder];
                if(sum>copy) break;
                num/=10;
            }
            num=copy;
            if(sum==copy)
            System.out.println(num);
            if(num==limit)
            {
                // nod+=1;
                limit*=10;
                update();
            }
        }
        end_milli=System.currentTimeMillis();
        end_nano=System.nanoTime();
        System.out.println((end_milli-start_milli)/1000);
        System.out.println(end_nano-start_nano);
    }
}
