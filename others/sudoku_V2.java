import java.util.Random;
public class sudoku_V2 {
    public static int count=0;
    // public static boolean isPossible(int[][] board,int size,int row,int col,int i )
    // {
    //     int x,y;
    //     //up
    //     for( x = row-1,y=col;x>0;x--)
    //     {
    //         if(board[x][y]==i) return false;
    //     }
    //     //down
    //     for( x = row+1,y=col;x<=size;x++)
    //     {
    //         if(board[x][y]==i) return false;
    //     }
    //     //left
    //     for( x = row,y=col-1;y>0;y--)
    //     {
    //         if(board[x][y]==i) return false;
    //     }
    //     //right
    //     for( x = row,y=col+1;y<=size;y++)
    //     {
    //         if(board[x][y]==i) return false;
    //     }
    //     return true;
    // }
    
    // public static void solve(int num)
    // {
    //     int[][] board = new int[num+1][num+1];
        
    //     int col =1;
    //     int row =1;

    //     while(row<=num)
    //     {
    //         if(col>num)
    //         {
    //                 row++;
    //                 col=1;
    //         }
    //         int randomVal = ran.nextInt(num+1);
    //         while(randomVal==0)
    //         {
    //         randomVal = ran.nextInt(num+1);
    //         }
    //         for(int i=randomVal,count=0;count<=num;i=((i%num)+1),count++)
    //         {
    //             System.out.println(" Row :"+row+" Col:"+col+" ith val :"+i);
    //             if(isPossible(board,num,row,col,i))
    //             {
    //                 board[row][col]=i;
    //             }
    //         }
    //         col++;
    //     }
    //     for(int i =1;i<=num; i++)
    //         {
    //             for(int j =1;j<=num; j++)
    //                 System.out.print(" "+board[i][j]);
    //             System.out.println("");
    //         }
    //         System.out.println("\n\n");
    // }
    public static void main(String[] args) {
        // solve(4);
        Random seedGen = new Random(System.nanoTime()>>5);

        Random seedGen2 = new Random(seedGen.nextInt()>>seedGen.nextInt(0,9));
        Random ran= new Random(seedGen2.nextInt());
        // System.out.println(randomVal);

        int randomVal=0;
        System.out.print(randomVal);
        while(count++<9)
        {
            randomVal = ran.nextInt(9);
           System.out.print(randomVal+ " ");
        }
    }
}
