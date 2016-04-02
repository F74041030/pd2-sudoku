#include<iostream>
using namespace std;
class Sudoku
{
	public:
		int board[9][9];
		void giveQuestion();
		void readIn();
		void solve();
		void changeNum(int a,int b);
		void changeRow(int a,int b);
		void changeCol(int a,int b);
		void rotate(int n);
		void flip (int n);
		void transform();
};
