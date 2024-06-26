/*
 * A n digits number should be divisivble by nth number
 * 3 % 1 == 0
 * 32 % 2 == 0
 * 321 % 3 == 0 
 * Etc.....
 */

import java.util.Scanner;

public class Pandigital_NthBase {
    public static long convert(long num,int base)
    {
        long copy=num;
        long power = 1;
        long res=0;
        while(copy!=0)
        {
            res=res+power*(copy%10);
            power*=base;
            copy/=10;
        }
        return res;
    }
    public static void helper(int[] used, int base , long num, long digit)
    {
        if(digit > used.length)
        {
            System.out.println(num);
        }
        for(int i=(digit>1?0:1); i < used.length ;i++)
        {
         
            if( used[i] == 0 && (convert(num*10+i,base))%digit ==0)
            {
                // System.out.println(convert(num*10+i)+" "+(num*10+i)+" "+digit);
                used[i]=1;
                helper(used,base,(num*10+i),(digit+1));
                used[i] = 0;
            }
        }
    }
    public static void genPan(int base)
    {
        int[] used = new int[base];
        helper(used, base, 0 , 1);

    }
    public static void main(String[] args) {
        int base;
        
        Scanner kb = new Scanner(System.in);
        System.out.println("Enter Base : ");
        
        base = kb.nextInt();
        long start_nano=System.nanoTime();
        genPan(base);

        long end_nano;
        end_nano=System.nanoTime();
        System.out.println("Nano Seconds: "+(end_nano-start_nano));
    }
}
