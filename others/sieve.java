/*
 * Count of prime numbers below 10: 4
Count of prime numbers below 100: 25
Count of prime numbers below 1,000: 168
Count of prime numbers below 10,000: 1,229
Count of prime numbers below 100,000: 9,592
Count of prime numbers below 1,000,000: 78,498
Count of prime numbers below 10,000,000: 664,579
 */
public class sieve {
    public static void main(String[] args) 
    {
        int  range;
        int  multiple;
        int  count;
        int  prime;
        int inc;
        long start_milli=System.currentTimeMillis();
        range = 10000000;
        boolean arr[]=new boolean[range+1];
        arr[1]=true;
        arr[2]=true;
        arr[0]=true;
        count = 1 ;
        for(multiple = 2; multiple < range ; multiple+=2)
        {
            arr [ multiple ] = true;
            count++;
        }
        prime = 3;
        // prime * prime < range not only ( prime < range ) 
        while(prime * prime < range)
        {
            if(!arr[prime]){
                inc = prime * 2;
                for(multiple = prime * prime ; multiple < range; multiple += inc )
                {
                    if( ! arr [ multiple ]) count++;
                    arr [ multiple ] = true ;
                    
                }
            }
            prime+=2;

        }
        System.out.println(range - count); 
        long end_milli;
        end_milli=System.currentTimeMillis();
        System.out.println((end_milli-start_milli)/1000.0); 
    }
}
    
