/*
 * A n digits number should be divisivble by nth number
 * 3 % 1 == 0
 * 32 % 2 == 0
 * 321 % 3 == 0 
 * Etc.....
 */

public class Pandigital_V2 {
    public static void helper(int[][] possible,int[] used, long num, int digit)
    {
        if(digit == used.length)
        {
            System.out.println(num*10);
        }
        for(int i=0; i < possible[digit].length;i++)
        {
            if( used[i] == 0 && (num*10+i)%digit ==0)
            {
                used[i]=1;
                helper(possible,used,(num*10+i),(digit+1));
                used[i] = 0;
            }
        }
    }
    public static void genPan(int base)
    {
        int[] used = new int[base];
        int[][] possible = new int[base][];
        for(int i=1; i<base ;i++)
        {
            used[i]=0;
            System.out.println(" \n");
            int starting = i;
            int mul,j;
            for(j=i,mul=2;mul<base;mul++)
            {
                if((j*mul)%base == starting) break;
            }

            int arraysize = mul;
            int[] temp = new int[arraysize];

            for(j=i,mul=0;mul<arraysize;mul++)
            {
                    temp[mul]=(j*mul)%base;
            }
            possible[i]=temp;
        }
        // helper(possible,used, 0 , 1);

    }
    public static void main(String[] args) {
        int base;
        base = 10;
        genPan(base);
        
    }
}
