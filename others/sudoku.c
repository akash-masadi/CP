#include<stdio.h>
#include<stdlib.h>
#define DIM 9
#define SAFE 0
#define UNSAFE 1
void print(int matrix[DIM][DIM])
{
	int row;
	int col;
	for(row=0;row<DIM;row+=1,printf(" \n"))
	{
		for(col=0;col<DIM;col+=1)
		{
			printf("%d ",matrix[row][col]);
		}
	}
}
int isSafe(int spare[DIM][DIM],int r,int c,int value)
{
	int row;
	int col;
	for(col=0;col<DIM;col+=1)
	{
		if(spare[r][col]==value)
		{
			return UNSAFE;
		}
	}
	for(row=0;row<DIM;row+=1)
	{
		if(spare[row][c]==value)
		{
			return UNSAFE;
		}
	}
	row=r;
	col=c;
	int subr;
	int subc;
	subr=(row/3)*3;
	subc=(col/3)*3;
	for(row=0;row<3;row+=1)
	{
		for(col=0;col<3;col+=1)
		{
			if(spare[row+subr][col+subc]==value)
			{
				return UNSAFE;
			}
		}
	}
	return SAFE;
}
void helper(int matrix[DIM][DIM],int spare[DIM][DIM],int r,int c)
{
	int row;
	int col;
	row=r;
	col=c;
	if(col==DIM)
	{
		col=0;
		row+=1;
		if(row==DIM)
		{
			print(spare);
			return ;
		}
	}
	if(matrix[row][col]!=0)
	{
		helper(matrix,spare,row,col+1);
	}
	else
	{
		int value;
		value=0;
		for(value=1;value<=DIM;value+=1)
		{
			if(isSafe(spare,row,col,value)==SAFE)
			{
				spare[row][col]=value;
				helper(matrix,spare,row,col+1);
				spare[row][col]=0;
			}
		}
	}
}
void suduko(int matrix[DIM][DIM])
{
	int working[DIM][DIM];
	int row;
	int col;
	for(row=0;row<DIM;row+=1)
	{
		for(col=0;col<DIM;col+=1)
		{
			working[row][col]=matrix[row][col];
		}
	}
	helper(matrix,working,0,0);
}
int main()
{
	int matrix[DIM][DIM]={
                      {0,0,0,8,0,1,0,0,0},
                      {0,0,0,0,0,0,0,4,3},
                      {5,0,0,0,0,0,0,0,0},
                      {0,0,0,0,7,0,8,0,0},
                      {0,0,0,0,0,0,1,0,0},
                      {0,2,0,0,3,0,0,0,0},
                      {6,0,0,0,0,0,0,7,5},
                      {0,0,3,4,0,0,0,0,0},
                      {0,0,0,2,0,0,6,0,0}
                      };
	suduko(matrix);
	return 0;
}