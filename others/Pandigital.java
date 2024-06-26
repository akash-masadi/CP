/*
 * A n digits number should be divisivble by nth number
 * 3 % 1 == 0
 * 32 % 2 == 0
 * 321 % 3 == 0 
 * Etc.....
 */
public class Pandigital {
    public static void helper(int[] used, long num, int digit)
    {
        if(digit == used.length)
        {
            System.out.println(num*10);
        }
        for(int i=1; i < used.length;i++)
        {
            if( used[i] == 0 && (num*10+i)%digit ==0)
            {
                used[i]=1;
                helper(used,(num*10+i),(digit+1));
                used[i] = 0;
            }
        }
    }
    public static void genPan(int base)
    {
        int[] used = new int[base];
        for(int i =0; i< base ;i++)
        {
            used[i]=0;
        }
        helper(used, 0 , 1);

    }
    public static void main(String[] args) {
        int base;
        base = 10;
        long start_nano=System.nanoTime();
        genPan(base);
        long end_nano;
        end_nano=System.nanoTime();
        System.out.println("Nano Seconds: "+(end_nano-start_nano));
    }
}
