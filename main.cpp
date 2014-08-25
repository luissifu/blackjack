#include <windows.h>
#include "includeGL.h"
#include <iostream>
#include "Card.h"
#include "Hand.h"
#include "Deck.h"

using namespace std;

const int winWidth = 500;
const int winHeight = 500;
//bool bandera; que hace esto?
bool gameOver;

Deck deck;
Hand player;
Hand dealer;

void init()
{
    glClearColor(0.011, 0.75, 0.23, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 500, 0);
}

void gameInit()
{
    deck.shuffle();
    player.clear();
    dealer.clear();
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
	gameOver = false;
}

void onGameOver() {
	gameOver = true;
	//implemeenta esta funcion
	//aqui decide quien gano
}

void hit()
{
	if (player.getValue() <= 21) 
	{
		player.addCard(deck.dealCard());
    }
	else
	{
		onGameOver();
	}
}

void stand()
{
	while(dealer.getValue()<=17){
		dealer.addCard(deck.dealCard());
    }
	onGameOver();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    dealer.draw(20, 100);
    player.draw(20, 300);

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
		/*case 27:
			glutDestroyWindow(win);
			  exit (0);

		break;*/

		case 'd':
		case 'D':
			gameInit();
			break;

		case 'h':
		case 'H':
			if (!gameOver)
				hit();
			break;

		case 's':
		case 'S':
			if (!gameOver)
				stand();
			break;

		default:
			break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    char choice;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(winWidth, winHeight);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("BlackJack");
    init();
    glutKeyboardFunc(keyboard);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
