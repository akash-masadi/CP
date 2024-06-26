public class additionVsMulti {
 public static void main(String[] args) {
    long start_milli;
    long start_nano;
    long end_milli;
    long end_nano;
    int a=9999;
    int b = 9999;
    start_milli=System.currentTimeMillis();
    start_nano=System.nanoTime();

    int c=a+b;

    end_milli=System.currentTimeMillis();
    end_nano=System.nanoTime();
    System.out.println(end_milli-start_milli);
    System.out.println(end_nano-start_nano);


    start_milli=System.currentTimeMillis();
    start_nano=System.nanoTime();

    int d=a*b;

    end_milli=System.currentTimeMillis();
    end_nano=System.nanoTime();
    System.out.println(end_milli-start_milli);
    System.out.println(end_nano-start_nano);
    

 }   
}
