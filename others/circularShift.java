/*
 * only for 32 bit integers
 * 
 *  left Shift  101011 = 43
 *  101011 >> 2
 *  111010 = 58
 *   
 * Right Shift 101011 = 43
 *  101011 << 2
 *  101110 = 46
 */
public class circularShift {
    private static int maskGen(int num)
    {
        int mask = 1;
        num = (num<0)?-num:num;
        while(mask < num)
        {
            mask*=2;
        }
        return mask-1;
    }
    static int rightShift(int num,int digits, int maxBits)
    {
        int mask = maskGen(num); 
        return ((num << digits) | (num >> (maxBits-digits))) & mask;
    }
    static int leftShift(int num,int digits, int maxBits)
    {
        int mask = maskGen(num); 
        return ((num >> digits) | (num << (maxBits-digits))) & mask ;
    }
    public static void main(String[] args) {
        // System.out.println(Total_Bits(-24));
        System.out.println( "Left Shift : "+ leftShift(43,2,6));
        System.out.println("Right Shift : "+ rightShift(43,2,6));
    }
    
}
