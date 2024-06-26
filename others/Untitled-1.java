// Euler's Method 
import java.lang.Math;
public class IntSqrt
{
	public static void main(String[] args) {
    long start_milli;
    long start_nano;
    long end_milli;
    long end_nano;

    start_milli=System.currentTimeMillis();
    start_nano=System.nanoTime();
    //Math.sqrt()
    System.out.println((int)Math.sqrt(10000000));


    end_milli=System.currentTimeMillis();
    end_nano=System.nanoTime();
    System.out.println("Time : "+(end_milli-start_milli)/1000.0);
    System.out.println((end_nano-start_nano));

    // my sqrt()
    start_milli=System.currentTimeMillis();
    start_nano=System.nanoTime();

    System.out.println(sqrt(10000000));

    end_milli=System.currentTimeMillis();
    end_nano=System.nanoTime();
    System.out.println("Time : "+(end_milli-start_milli)/1000.0);
    System.out.println((end_nano-start_nano));
    }
	public static int sqrt(int num)
	{
		int n1 = num /2 ;
		int n2 = (n1+num/n1)/2;
		while(n2<n1)
		{
			n1=n2;
			n2 = (n1+num/n1)/2;
		}
		return n2;
	}
}