#include <windows.h>
#include "includeGL.h"
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "Card.h"
#include "Hand.h"
#include "Deck.h"


using namespace std;

const int winWidth = 500;
const int winHeight = 500;
//bool bandera; que hace esto?
bool gameOver;
bool flagw;
bool flagl;
int scoreDealer=0;
int scorePlayer=0;

Deck deck;
Hand player;
Hand dealer;

string toString(int value) {
	stringstream ss;
	ss << value;
	return ss.str();
}

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
	flagw = false;
	flagl = false;
}

void onGameOver() {
	gameOver = true;
	if( player.getValue() == dealer.getValue() || ( dealer.getValue() > player.getValue() && dealer.getValue() <= 21 ) || player.getValue() > 21)
    {
        flagl = true;
        scoreDealer++;
    }
    else
	{
        flagw = true;
        scorePlayer++;
    }
}

void stand()
{
	while (dealer.getValue() <= 17 && dealer.getValue() < player.getValue()){
		dealer.addCard(deck.dealCard());
	}

	onGameOver();
}

void hit()
{
	player.addCard(deck.dealCard());
	if (player.getValue() >= 21)
	{
		if (player.getValue() == 21)
			stand();
		onGameOver();
	}
}


void drawText(int x, int y, std::string text, void* font, int r, int g, int b) {
	glColor3ub(r, g, b);
	glRasterPos2i(x, y);

	for (string::iterator i = text.begin(); i != text.end(); ++i)
	{
		char c = *i;
		glutBitmapCharacter(font, c);
	}
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    dealer.draw(20, 100);
    player.draw(20, 300);

	drawText(20, 90, "DEALER -", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
	drawText(20, 290, "PLAYER -", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
	drawText(100, 420, "D-Deal", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
	drawText(200, 420, "H-Hit", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
	drawText(300, 420, "S-Stand", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
    drawText(20, 460, "Luis Eduardo Sifuentes a01138688", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
    drawText(20, 480, "Jose Luis Padilla a01136406", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);

	drawText(20, 40, "Score", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
    drawText(80, 40, "DEALER :", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
	drawText(230, 40, "PLAYER :", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
    drawText(180, 40, toString(scoreDealer), GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
    drawText(340, 40, toString(scorePlayer), GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
	drawText(120, 90, toString(dealer.getValue()), GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
	drawText(120, 290, toString(player.getValue()), GLUT_BITMAP_HELVETICA_18, 255, 255, 255);

	if (flagl)
	{
		drawText(200, 90, "YOU LOSE", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
	}
	else if (flagw)
	{
		drawText(200, 90, "YOU WIN", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
	}

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
	gameInit();
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
