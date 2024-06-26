// check for pattern in String, if matched return index else -1;
public class Main
{
    public static int[] genPattern(String s)
    {
		int[] arr= new int[s.length()];
		int len=0;
		arr[0]=0;
		for(int i=1;i<s.length();)
		{
		    if(s.charAt(i)==s.charAt(len))
		    {
		        arr[i]=++len;
		        i++;
		    }
		    else
		    {
		        if(len!=0)
		        {
		            len=arr[len-1];
		        }
		        else
		        {
		            arr[i]=0;
		            i++;
		        }
		        
		    }
		}
// 		for(int a:arr)
// 		{
// 		    System.out.println(a);
// 		}
		return arr;
    }
	public static void main(String[] args) {
		
        String pattern="abcdabc";
        String text = "abcababcdabceab";
        // a b c a b a b c d  a  b  c  e  a  b
        // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
        int[] arr = genPattern(pattern);
        int j=0,i;
        for(i=0;i<text.length();i++)
        {
            if(text.charAt(i)==pattern.charAt(j))
            {
                j+=1;
                if(j==pattern.length()) break;
            }
            else
            {
                if(j!=0)
                    j=arr[--j];
            }
        }
        System.out.println((i==text.length()?-1:i-pattern.length()+1));
	}
}
