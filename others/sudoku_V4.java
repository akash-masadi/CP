import java.util.Random;

public class sudoku_V4 {
    public static Random ran;
    
    public static boolean isPossible(int[][] board, int size, int row, int col, int num) {
        for (int x = 0; x < size; x++) {
            if (board[x][col] == num || board[row][x] == num) {
                return false;
            }
        }

        int boxRowStart = row - row % 3;
        int boxColStart = col - col % 3;

        for (int i = boxRowStart; i < boxRowStart + 3; i++) {
            for (int j = boxColStart; j < boxColStart + 3; j++) {
                if (board[i][j] == num) {
                    return false;
                }
            }
        }

        return true;
    }

    public static boolean solveSudoku(int[][] board, int size) {
        for (int row = 0; row < size; row++) {
            for (int col = 0; col < size; col++) {
                if (board[row][col] == 0) {
                    ran = new Random(System.nanoTime()%100000);
                    int randomVal=0;
                    while(randomVal==0)
                    {
                        randomVal= ran.nextInt(size+1);
                    } 
                    for(int num=randomVal,count=0;count<size;num=((num%size)+1),count++)
                    {
                        if (isPossible(board, size, row, col, num)) {
                            board[row][col] = num;
                            if (solveSudoku(board, size)) {
                                return true;
                            } else {
                                board[row][col] = 0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    public static void printSudoku(int[][] board, int size) {
        for (int row = 0; row < size; row++) 
        {
            for (int col = 0; col < size; col++) 
            {
                System.out.print(" "+board[row][col] + " ");
                if(col!=size-1 && (col+1)%3==0) System.out.print(" | ");
            }
            System.out.println();
            for (int col = 0; col < size; col++)
            if((row)!=size-1 && (row+1)%3==0) System.out.print("  "+((char)45)+" ");
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int size = 9;
        int[][] board = new int[size][size];
        if (solveSudoku(board, size)) {
            System.out.println("Sudoku solution:");
            printSudoku(board, size);
        } else {
            System.out.println("No solution exists.");
        }
    }
}
