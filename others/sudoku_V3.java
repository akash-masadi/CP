import java.util.Random;
public class sudoku_V3
{

    public static Random ran;
    public static int count=0;
    public static boolean isPossible(int[][] board,int size,int row,int col,int i )
    {
        int x,y;
        System.out.println("Row: "+row+" Col : "+col);
        //up
        for( x = row-1,y=col;x>0;x--)
        {
            if(board[x][y]==i) return false;
        }
        //down
        for( x = row+1,y=col;x<=size;x++)
        {
            if(board[x][y]==i) return false;
        }
        //left
        for( x = row,y=col-1;y>0;y--)
        {
            if(board[x][y]==i) return false;
        }
        //right
        for( x = row,y=col+1;y<=size;y++)
        {
            if(board[x][y]==i) return false;
        }
        return true;
    }
    // public static printSudoku()
    // {

    // }
    public static void helper(int[][] board, int size,int row,int col)
    {
        int i;
        int j;
        int count; 
        ran = new Random(System.nanoTime()%100000);
        int randomVal = ran.nextInt(size+1);
        for(i=randomVal,count=0;count<=size;i=((i%size)+1),count++)
        {
            if(isPossible(board,size,row,col,i));
            {   
                board[row][col] = i;
                col++;
                if(col==size+1)
                {
                    row++;
                    col=1;
                }
                if(row==size && col == size+1)
                {
                    
                }
                else{

                    helper(board, size, row, col);
                }
            }
        }
        col--;
            board[row][col]=0;
            row--;
            col=size;
    }
    public static void solve(int size)
    {
        int[][] board = new int[size+1][size+1];
        helper(board,size,1,1);
    }
    public static void main(String[] args) {
        solve(4);
        System.out.println(count);
        
    }
}