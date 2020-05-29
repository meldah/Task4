/*
n x n matrix where '#' is a wall, 'c' is a cheese and position of a mouse can be changed in main function. 
Now mouse's position is (1,1)
*/

#include <iostream>
using namespace std;

const int SIZE = 4;
char lab[][SIZE] = {
		{' ',' ',' ','#'},
		{' ',' ','#','#'},
		{'#',' ',' ',' '},
		{' ',' ','c',' '}
		
};

char* path = new char[SIZE*SIZE];
int position = 0;

void printPath(char* path, int start, int end)
{
	cout << "Found path to the cheese: ";
	for (int i = start; i <= end; i++)
	{
		cout << path[i] << " ";
	}
	cout << endl;
}
void findPath(int row, int col,char direction)
{
	if(col<0 || row<0 || col >= SIZE || row>=SIZE)
	{
		return;
	}

	path[position] = direction;
	position++;

	if (lab[row][col] == 'c')
	{
		printPath(path, 1, position - 1);
	}

	if (lab[row][col] == ' ')
	{
		lab[row][col] = 'v';

		findPath(row, col - 1,'L'); //left 
		findPath(row - 1, col,'U'); //up
		findPath(row, col + 1,'R'); //right
		findPath(row + 1, col,'D'); //down

		lab[row][col] = ' '; //if only we have a little options, bachtracking does not working when we have many options
	}

	position--;
}


int main()
{
	findPath(1,1,'S');
	delete path;
	system("pause");
}

