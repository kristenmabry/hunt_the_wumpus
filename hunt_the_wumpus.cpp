#include <iostream>
#include <cstdlib>	//rand
using namespace std;

int currRoom;
int wumpus;
int bat1;
int bat2;
int pit1;
int pit2;
bool gameOver;
int arrows = 5;

//Room pathway options
int rooms[20][3] = { {2, 3, 11}, {1, 5, 16}, {1, 4, 7}, {3, 5, 6}, {4, 6, 10}, {4, 8, 9}, {3, 8, 12}, {6, 7, 13}, {6, 10, 14}, {5, 9, 15}, {1, 12, 20}, {7, 11, 17}, {8, 14, 17}, {9, 13, 19}, {10, 16, 19}, {2, 15, 20}, {12, 13, 18}, {17, 19, 20}, {14, 15, 18}, {11, 16, 18} };

int randomize();
void directions();
void action();
void shoot();
void move();
void chooseRoom();
void attacked();
void enemyAlert();

int main()
{
	srand(time(NULL));
	currRoom = randomize();
	wumpus = randomize();
	bat1 = randomize();
	bat2 = randomize();
	pit1 = randomize();
	pit2 = randomize();
	while (wumpus == currRoom)
		{
		wumpus = randomize();
		}
	while (bat1 == currRoom)
		{
		bat1 = randomize();
		}
	while (bat2 == currRoom)
		{
		bat2 = randomize();
		}
	while (pit1 == currRoom)
		{
		pit1 = randomize();
		}
	while (pit2 == currRoom)
		{
		pit2 = randomize();
		}
	while (!gameOver)
		{
		//cout << "bats " << bat1 << " " << bat2 << endl
		//	<< "pits " << pit1 << " " << pit2 << endl
		//	<< "Wumpus " << wumpus << endl;
		directions();
		action();
		cout << endl << endl;
		attacked();
		}
	
}

int randomize()
{
	int room;
	for(int i = 0; i < 10; i++) 
		{
		room = (rand() % 20) + 1;
		}
	return room;
}

void directions()
{
	cout << "YOU ARE IN ROOM " << currRoom << endl;
	enemyAlert();
	cout << "TUNNELS LEAD TO " << rooms[currRoom-1][0] << " "
		<< rooms[currRoom-1][1] << " " << rooms[currRoom-1][2] << endl;
}

void action()
{
	char response;
	
	cout << "SHOOT OR MOVE (S-M)? ";
	cin >> response;

	if (response == 'S' || response == 's')
		{
		shoot();
		}
	else if (response == 'M' || response == 'm')
		{
		move();
		}
} 

void shoot()
{
	int response;

	cout << "WHERE TO? ";
	cin >> response;

	if (response == rooms[currRoom-1][0] || response == rooms[currRoom-1][1] || response == rooms[currRoom-1][2])
		{
		if (response == wumpus)
			{
			cout << "AHA! YOU GOT THE WUMPUS!" << endl
				<< "HEE HEE - THE WUMPUS'LL GETCHA NEXT TIME!!"
				<< endl;
			gameOver = true;
			}
		else
			{
			cout << "DRATS! MISSED!" << endl;
			cout << "YOU HAVE " << arrows << " ARROWS LEFT" << endl;
			int moves;
			moves = randomize();
			if (moves > 5)
				{
				wumpus = randomize();
				}
			}
		arrows--;
		}
	if (arrows == 0 && !gameOver)
		{
		gameOver = true;
		cout << "GAME OVER! YOU RAN OUT OF ARROWS!" << endl;
		}

}

void move()
{
	int response;
	cout << "WHERE TO? ";
	cin >> response;

	if (response == rooms[currRoom-1][0] || response == rooms[currRoom-1][1] || response == rooms[currRoom-1][2])
		{
		currRoom = response;
		}
}

void attacked()
{
	if (currRoom == wumpus)
		{
		gameOver = true;
		cout << "THE WUMPUS ATE YOU!" << endl;
		cout << "HA HA - YOU LOSE!" << endl << endl;
		}
	else if (currRoom == pit1 || currRoom == pit2)
		{
		gameOver = true;
		cout << "YYYIIIIEEEE . . . FELL IN PIT" << endl;
		cout << "HA HA - YOU LOSE!" << endl << endl;
		}
	else if (currRoom == bat1 || currRoom == bat2)
		{
		cout << "ZAP -- SUPER BAT SNATCH! ELSEWHEREVILLE FOR YOU!" << endl;
		currRoom = randomize();
		attacked();
		}
}

void enemyAlert()
{
	if (wumpus == rooms[currRoom-1][0] || wumpus == rooms[currRoom-1][1] || wumpus == rooms[currRoom-1][2])
		{
		cout << "I SMELL A WUMPUS" << endl;
		}

	if ((bat1 == rooms[currRoom-1][0] || bat1 == rooms[currRoom-1][1] || bat1 == rooms[currRoom-1][2]) || (bat2 == rooms[currRoom-1][0] || bat2 == rooms[currRoom-1][1] || bat2 == rooms[currRoom-1][2]))
		{	
		cout << "BATS NEARBY" << endl;
		}
		
	if ((pit1 == rooms[currRoom-1][0] || pit1 == rooms[currRoom-1][1] || pit1 == rooms[currRoom-1][2]) || (pit2 == rooms[currRoom-1][0] || pit2 == rooms[currRoom-1][1] || pit2 == rooms[currRoom-1][2]))
		{	
		cout << "I FEEL A DRAFT" << endl; 
		}
}
