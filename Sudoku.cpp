#include<iostream>
#include"Sudoku.h"
#define UNASSIGNED 0
#define N 9
 using namespace std;

 void Sudoku::giveQuestion()
	 {
		       int i=0;
			         int j=0;
					       int board[9][9];
						         for(i=0;i<=8;i++)
									       {
											             for(j=0;j<=8;j++)
															           {
																		               board[i][j]=0;
																					             }
														       }
								       board[0][1]=4;board[0][3]=2;board[0][4]=5;board[0][8]=8;
									         board[1][1]=3;board[1][3]=4;board[1][5]=9;board[1][6]=1;board[1][7]=7;
											       board[2][4]=8;board[2][5]=1;board[2][6]=2;
												         board[3][2]=6;board[3][6]=7;board[3][7]=2;
														       board[4][3]=6;board[4][5]=4;
															         board[5][1]=1;board[5][2]=2;board[5][6]=3;
																	       board[6][2]=3;board[6][3]=8;board[6][4]=1;
																		         board[7][1]=6;board[7][2]=4;board[7][3]=9;board[7][5]=2;board[7][7]=1;
																				       board[8][0]=7;board[8][4]=4;board[8][5]=5;board[8][7]=9;
																					         for(i=0;i<=8;i++)
																								       {
																										           for(j=0;j<=8;j++)                                                                
																													   		{    if ((j+1)%9!=0)
																																cout<<board[i][j]<<" ";    
																																else                                                                                
																																	cout<<board[i][j]<<"\n";       }
																												         }
																							  
																							   }


void Sudoku::readIn()
{
		int i;
			int j;
				for(i=0;i<=8;i++)
						for(j=0;j<=8;j++)
								{
											cin>>board[i][j];
												}
}
 int ans=0;
  int solution[9][9];
   

  bool FindUnassignedLocation(int board[N][N], int &row, int &col);
   

  bool isSafe(int board[N][N], int row, int col, int num);
   

  int SolveSudoku(int board[N][N])
{
	int row, col;
	 

	if (!FindUnassignedLocation(board, row, col))
	{
		ans++;
		if(ans==1)
		{
			int i;int j;
			for(i=0;i<9;i++)
				for(j=0;j<9;j++)
				{
					solution[i][j]=board[i][j];
				}
			return 0;
		}
		if(ans==2)
			return 1;
	}
	       

	for (int num = 1; num <= 9; num++)
	{

		if (isSafe(board, row, col, num))
		{

			board[row][col] = num;
			 

			if (SolveSudoku(board))
				return 1;
			 

			board[row][col] = UNASSIGNED;
		}
	}
	return 0; 
}
 
bool checkrow(int board[9][9],int row,int n)
{ int check=0;
	  int j;
	       	for(j=0;j<9;j++)
				     	{
							     		if(board[row][j]==n)
											     		check++;
										     		
												 }
			  if(check>1)
				       		return false;
			       		else
							     		return true;
}
bool checkcol(int board[9][9],int col,int n)
{ int check=0;
	  int i;
	       	for(i=0;i<9;i++)
				     	{
							     		if(board[i][col]==n)
											     		check++;
										     	
												 }
			  	if(check>1)
					     		return false;
				     		else
								            return true;
}
bool check(int board[9][9])
{   int c;
	    int cbox;
		    int n;
				for(c=0;c<9;c++)
							for(n=1;n<=9;n++)
								    		if(checkrow(board,c,n)==false)
												    			{return false;}
				    for(c=0;c<9;c++)
						    	for(n=1;n<=9;n++)
									    		if(checkcol(board,c,n)==false)
													    			{return false;}
					    
					    return true;
}
bool FindUnassignedLocation(int board[N][N], int &row, int &col)
{
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (board[row][col] == UNASSIGNED)
				return true;
	return false;
}
 

bool UsedInRow(int board[N][N], int row, int num)
{
	for (int col = 0; col < N; col++)
		if (board[row][col] == num)
			return true;
	return false;
}
 

bool UsedInCol(int board[N][N], int col, int num)
{
	for (int row = 0; row < N; row++)
		if (board[row][col] == num)
			return true;
	return false;
}
 

bool UsedInBox(int board[N][N], int boxStartRow, int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (board[row+boxStartRow][col+boxStartCol] == num)
				return true;
	return false;
}
 

bool isSafe(int board[N][N], int row, int col, int num)
{

	return !UsedInRow(board, row, num) &&
		!UsedInCol(board, col, num) &&
		!UsedInBox(board, row - row%3 , col - col%3, num);
}
 

void printBoard(int board[N][N])
{
	cout<<"1\n";
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
			cout<<board[row][col]<<" ";
		cout<<"\n";
	}
}
 

void Sudoku::solve()
{
	readIn();
	if(check(board)==false)
	{cout<<"0";
	}
	if(check(board)==true)
	{
		SolveSudoku(board);			 
		if (ans == 1)
		{printBoard(solution);}
		else if (ans == 2)
		{cout<<"2";}
		else
			cout<<"0";
	} 
	    
}
 
void Sudoku::changeRow(int a, int b)
{

	int d[3][9];
	int i;
	int j;
	if(a==0&&b==1)
	{
		for(i=0;i<=2;i++)
		{
			for(j=0;j<=8;j++)
			{
				d[i][j]=board[i][j];
			}
		}
		for(i=0;i<=2;i++)
		{
			for(j=0;j<=8;j++)
			{
				board[i][j]=board[i+3][j];
			}
		}
		for(i=0;i<=2;i++)
		{
			for(j=0;j<=8;j++)
			{
				board[i+3][j]=d[i][j];
			}
		}
	}
	if(a==1&&b==0)
	{
		for(i=0;i<=2;i++)
		{
			for(j=0;j<=8;j++)
			{
				d[i][j]=board[i][j];
			}
		}
		for(i=0;i<=2;i++)
		{
			for(j=0;j<=8;j++)
			{
				board[i][j]=board[i+3][j];
			}
		}
		for(i=0;i<=2;i++)
		{
			for(j=0;j<=8;j++)
			{
				board[i+3][j]=d[i][j];
			}
		}
	}
	if(a==1&&b==2)
	{
		for(i=0;i<=2;i++)
		{
			for(j=0;j<=8;j++)
			{
				d[i][j]=board[i+3][j];
			}
		}
		for(i=0;i<=2;i++)
		{
			for(j=0;j<=8;j++)
			{
				board[i+3][j]=board[i+6][j];
			}
		}
		for(i=0;i<=2;i++)
		{
			for(j=0;j<=8;j++)
			{
				board[i+6][j]=d[i][j];
			}
		}
	}
	if(a==2&&b==1)
	{
		for(i=0;i<=2;i++)
		{
			for(j=0;j<=8;j++)
			{
				d[i][j]=board[i+3][j];
			}
		}
		for(i=0;i<=2;i++)
		{
			for(j=0;j<=8;j++)
			{
				board[i+3][j]=board[i+6][j];
			}
		}
		for(i=0;i<=2;i++)
		{
			for(j=0;j<=8;j++)
			{
				board[i+6][j]=d[i][j];
			}
		}
	}
	if(a==0&&b==2)
	{
		for(i=0;i<=2;i++)
		{
			for(j=0;j<=8;j++)
			{
				d[i][j]=board[i][j];
			}
		}
		for(i=0;i<=2;i++)
		{
			for(j=0;j<=8;j++)
			{
				board[i][j]=board[i+6][j];
			}
		}
		for(i=0;i<=2;i++)
		{
			for(j=0;j<=8;j++)
			{
				board[i+6][j]=d[i][j];
			}
		}
	}
	if(a==2&&b==0)
	{
		for(i=0;i<=2;i++)
		{
			for(j=0;j<=8;j++)
			{
				d[i][j]=board[i][j];
			}
		}
		for(i=0;i<=2;i++)
		{
			for(j=0;j<=8;j++)
			{
				board[i][j]=board[i+6][j];
			}
		}
		for(i=0;i<=2;i++)
		{
			for(j=0;j<=8;j++)
			{
				board[i+6][j]=d[i][j];
			}
		}
	}
}
void Sudoku::changeNum(int a,int b)
{
	int i;
	int j;
	for(i=0;i<=8;i++)
	{
		for(j=0;j<=8;j++)   
		{
			if(board[i][j]==a)
			{
				board[i][j]=b;
			}
			else if(board[i][j]==b)
			{
				board[i][j]=a;
			}
		}   
	}
		
}

void Sudoku::changeCol(int a, int b)
{
	int d[9][3];
	int i;
	int j;
	if(a==0&&b==1)
	{
		for(i=0;i<=8;i++)
		{
			for(j=0;j<=2;j++)
			{
				d[i][j]=board[i][j];
			}
		}
		for(i=0;i<=8;i++)
		{
			for(j=0;j<=2;j++)
			{
				board[i][j]=board[i][j+3];
			}
		}
		for(i=0;i<=8;i++)
		{
			for(j=0;j<=2;j++)
			{
				board[i][j+3]=d[i][j];
			}
		}
	}
	if(a==1&&b==0)
	{
		for(i=0;i<=8;i++)
		{
			for(j=0;j<=2;j++)
			{
				d[i][j]=board[i][j];
			}
		}
		for(i=0;i<=8;i++)
		{
			for(j=0;j<=2;j++)
			{
				board[i][j]=board[i][j+3];
			}
		}
		for(i=0;i<=8;i++)
		{
			for(j=0;j<=2;j++)
			{
				board[i][j+3]=d[i][j];
			}
		}
	}
	if(a==1&&b==2)
	{
		for(i=0;i<=8;i++)
		{
			for(j=0;j<=2;j++)
			{
				d[i][j]=board[i][j+3];
			}
		}
		for(i=0;i<=8;i++)
		{
			for(j=0;j<=2;j++)
			{
				board[i][j+3]=board[i][j+6];
			}
		}
		for(i=0;i<=8;i++)
		{
			for(j=0;j<=2;j++)
			{
				board[i][j+6]=d[i][j];
			}
		}
	}
	if(a==2&&b==1)
	{
		for(i=0;i<=8;i++)
		{
			for(j=0;j<=2;j++)
			{
				d[i][j]=board[i][j+3];
			}
		}
		for(i=0;i<=8;i++)
		{
			for(j=0;j<=2;j++)
			{
				board[i][j+3]=board[i][j+6];
			}
		}
		for(i=0;i<=8;i++)
		{
			for(j=0;j<=2;j++)
			{
				board[i][j+6]=d[i][j];
			}
		}
	}
	if(a==0&&b==2)
	{
		for(i=0;i<=8;i++)
		{
			for(j=0;j<=2;j++)
			{
				d[i][j]=board[i][j];
			}
		}
		for(i=0;i<=8;i++)
		{
			for(j=0;j<=2;j++)
			{
				board[i][j]=board[i][j+6];
			}
		}
		for(i=0;i<=8;i++)
		{
			for(j=0;j<=2;j++)
			{
				board[i][j+6]=d[i][j];
			}
		}
	}
	if(a==2&&b==0)
	{
		for(i=0;i<=8;i++)
		{
			for(j=0;j<=2;j++)
			{
				d[i][j]=board[i][j];
			}
		}
		for(i=0;i<=8;i++)
		{
			for(j=0;j<=2;j++)
			{
				board[i][j]=board[i][j+6];
			}
		}
		for(i=0;i<=8;i++)
		{
			for(j=0;j<=2;j++)
			{
				board[i][j+6]=d[i][j];
			}
		}
	}
}
void Sudoku::rotate(int n)
{

	int d[9][9];
	int i,j,t;
	for(t=0;t<n;t++)
	{
		for(i=0;i<=8;i++)
		{
			for(j=0;j<=8;j++)
			{
				d[i][j]=board[i][j];
			}
		}
		for(i=0;i<=8;i++)
		{
			for(j=0;j<=8;j++)
			{
				board[i][j]=d[8-j][i];
			}
		}
	}
}
void Sudoku::flip(int n)
{
	int i;
	int j;
	int d[9][9];
	for(i=0;i<=8;i++)
	{
		for(j=0;j<=8;j++)
		{
			d[i][j]=board[i][j];
		}
	}
	if(n==0)
	{
		for(i=0;i<=8;i++)
		{
			for(j=0;j<=8;j++)
			{
				board[i][j]=d[8-i][j];
			}
		}
	}
	else if(n==1)
	{
		for(i=0;i<=8;i++)
		{
			for(j=0;j<=8;j++)
			{
				board[i][j]=d[i][8-j];
			}
		}
	}
}
void Sudoku::transform()
	 {
		      int i;int j;
			       readIn();
				        changeNum(3,4);
						     rotate(1);
							      for (int i = 0; i < N; i++)
									       {
											            for (int j = 0; j < N; j++)
															        cout<<board[i][j]<<" ";
														         cout<<"\n";
																      }
								   }

