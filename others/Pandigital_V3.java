/*
 * A n digits number should be divisivble by nth number
 * 3 % 1 == 0
 * 32 % 2 == 0
 * 321 % 3 == 0 
 * Etc.....
 * 
 * 
 * 
 * Time taken :-
 * PS C:\myStuff\coding> java Pandigital.java   
    3816547290
    Nano Seconds: 1002400

    PS C:\myStuff\coding> java Pandigital_V3.java
    3816547290
    Nano Seconds: 951400

    PS C:\myStuff\coding> java Pandigital.java   
    3816547290
    Nano Seconds: 1127400
    
    PS C:\myStuff\coding> java Pandigital_V3.java
    3816547290
    Nano Seconds: 1116100
 *
 */
public class Pandigital_V3 {
    public static void helper(int[][] possible,int[] used, long num, int digit)
    {
        if(digit == used.length)
        {
            System.out.println(num*10);
        }
        for(int i=0; i < possible[digit].length;i++)
        {
            if( used[possible[digit][i]] == 0 && (num*10+possible[digit][i])%digit ==0)
            {
                used[possible[digit][i]]=1;
                helper(possible,used,(num*10+possible[digit][i]),(digit+1));
                used[possible[digit][i]] = 0;
            }
        }
    }
    public static void genPan(int base)
    {

        int[] used = new int[base];
        int possible[][] = new int[][]{
            new int[]{},
            new int[]{1,2,3,4,5,6,7,8,9},
            new int[]{2,4,6,8},
            new int[]{1,2,3,4,5,6,7,8,9},
            new int[]{2,4,6,8},
            new int[]{5},
            new int[]{2,4,6,8},
            new int[]{1,2,3,4,5,6,7,8,9},
            new int[]{2,4,6,8},
            new int[]{1,2,3,4,5,6,7,8,9},
            new int[]{}
        };
        for(int i =0; i< base ;i++)
        {
            used[i]=0;
        }
        helper(possible,used, 0 , 1);

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
