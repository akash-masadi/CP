/*
Return the mejority element greater than give (array.lenght)/2
 * Boyce-Moore's Majority Voting Algorithm
 * Given :- 5 6 6 7 6 9 6
 *  return 6 as 6 is present 4 > (n/2)
 */
public class majority_n2 {
    public static void main(String[] args) {
        // int[] arr = { 5,7,6,8,9,6,6,7,6,6,8,6,9,6};
        //cou         1 1 1 1 1 1 2 1 2 3 2 3 2 3
        // major      5 7 6 8 9 6 6 6 6 6 6 6 6 6
        // int[] arr = { 7,2,7,3,7,2,7,7};
        int[] arr = { 7,7,5,7,5,1,7,5,7,5,5,5,7,5};
        // int len = arr.length;
        int majority = arr[0];
        int count = 0;
        for(int currentNum : arr)
        {
            if(majority != currentNum)
            {
                count--;
            }
            else 
            {
                count++;
            }
            if(count == 0)
            {
                count=1;
                majority = currentNum;
            }
        }
        if(count>0)
        {
            System.out.println(majority);
        }
        else
        {
            System.out.println("No majority");
        }

    }
}
