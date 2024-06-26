import java.util.Random;

public class sudoku {
    public static Random seedGen;
    public static Random ran;
    public static int count;
    public static boolean isPossible(int[][] board,int size,int row,int col,int i )
    {
        int x,y;
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
    public static void helper(int[][] board,int size,int row,int col)
    {
        ran= new Random(System.nanoTime()%100000);
        if(row==size && col == size)
        {
            int randomVal = ran.nextInt(size+1);
            while(randomVal==0)
            {
                randomVal = ran.nextInt(size+1);
            }
            for(int i=randomVal,count=0;count<=size;i=((i%size)+1),count++)
            {
                if(isPossible(board,size,row,col,i))
                {
                    board[row][col]=i;
                }
            }
            for(int i =1;i<=size; i++)
            {
                for(int j =1;j<=size; j++)
                    System.out.print(" "+board[i][j]);
                System.out.println("");
            }
            System.out.println("\n\n");
            count++;
            return;
        }
        
        int randomVal = ran.nextInt(size+1);
        while(randomVal==0)
        {
            randomVal = ran.nextInt(size+1);
        }
        
        for(int i=randomVal,count=0;count<=size;i=((i%size)+1),count++)
        {
            if(isPossible(board,size,row,col,i))
            {
                board[row][col]=i;
                if(col==size)
                {
                    row++;
                    col=0;
                }
                helper(board,size,row,col+1);
                if(col == 0)
                {
                    row--;
                    col=size;
                }
                // board[row][col]=0;
            }
    }
}
    
    public static void solve(int num)
    {
        int[][] board = new int[num+1][num+1];
        helper(board,num,1,1);
    }
    public static void main(String[] args) {
        solve(4);
        // int randomVal =2 ;
        // System.out.println(count);
        
        // while(randomVal==0)
        // {
        // randomVal = ran.nextInt(8+1);
        // }
        // for(int i=randomVal,count=0;count<8;i=(i%8)+1,count++)
        // {
        //     System.out.print(i+" \t");
        // }
    }
}
