/*
Return the mejority element greater than give (array.lenght)/3
 * Boyce-Moore's Majority Voting Algorithm
 * Given :- 5 6 6 7 7 9 6 7 
 *  return [6,7]as 7 is present 4 > (n/3)
 */

import java.util.ArrayList;

public class majority_n3 {
    public static void main(String[] args) {
        int[] arr = { 6 ,5 ,9 ,7,7,6,6,7};
            int len = arr.length;
            int majority1 = 0 ;
            int majority2 = 0;
            int counter1 = 0;
            int counter2 = 0;
            for(int currentNum : arr)
            {
                if(counter1 == 0 && currentNum != majority2 )
                {
                    counter1 = 1;
                    majority1 = currentNum;
                }
                else if(counter2 == 0 && currentNum != majority1)
                {
                    counter2 = 1;
                    majority2 = currentNum;
                }
                else if(majority1 == currentNum)
                {
                    counter1++;
                }
                else if( majority2 == currentNum)
                {
                    counter2++;
                }
                else 
                {
                    counter1--;
                    counter2--;
                }
            }
            counter1=0;
            counter2=0;
            for(int a: arr)
            {
                if(a==majority1)
                {
                    counter1+=1;
                } else if(a==majority2)
                {
                    counter2+=1;
                }
            }
            if(counter1>len/3)
            {
                System.out.println(majority1);
            }
            if(counter2>len/3)
            {
                System.out.println(majority2);
            }
    }
}
