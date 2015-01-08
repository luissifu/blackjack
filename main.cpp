//Luis Eduardo Sifuentes Infante a01138688
//Jose Luis Padilla Gonzalez a01136406
#include <iostream>
#include <cstdlib>
#include <sstream>
#include "includeGL.h"
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
bool flagexit=false;
int scoreDealer=0;
int scorePlayer=0;
bool showdealer=true;
bool valor1=true;
string dealertemp;
bool flaglastW=false;
bool flaglastL=false;
bool surrender=false;
bool lsurrend=false;

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
    gluOrtho2D(0, 500, 600, 0);

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
	surrender=false;
}

void onGameOver() {
	gameOver = true;
	if(surrender || player.getValue() == dealer.getValue() || ( dealer.getValue() > player.getValue() && dealer.getValue() <= 21 ) || player.getValue() > 21)
    {
        flagl = true;
        scoreDealer++;
        flaglastL=true;
        flaglastW=false;
        lsurrend=surrender;
    }
    else
	{
        flagw = true;
        scorePlayer++;
        flaglastW=true;
        flaglastL=false;
        lsurrend=false;

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

    dealer.draw(20, 200);
    player.draw(20, 400);

    if(showdealer and !flagw and !flagl){

    glColor3ub(255,0,0);
    glBegin(GL_POLYGON);
		glVertex2d( 83,203);
		glVertex2d( 83,297 );
		glVertex2d( 127,297);
		glVertex2d( 127,203);
	glEnd();
    }
    drawText(200, 50, "Black Jack", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
    drawText(150, 100, "Last Game: ", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
    if(flaglastL && !lsurrend)
    drawText(250, 100, "You Lost", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
    if(flaglastW)
    drawText(250, 100, "You Won", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
    if(lsurrend)
    drawText(250, 100, "You surrended", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);

	drawText(20, 190, "DEALER -", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
	drawText(20, 390, "PLAYER -", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
	drawText(100, 520, "D-Deal", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
	drawText(200, 520, "H-Hit", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
	drawText(300, 520, "S-Stand", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
    drawText(20, 560, "Luis Eduardo Sifuentes a01138688", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
    drawText(20, 580, "Jose Luis Padilla a01136406", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);

	drawText(20, 140, "Score", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
    drawText(80, 140, "DEALER :", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
	drawText(230, 140, "PLAYER :", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
    drawText(180, 140, toString(scoreDealer), GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
    drawText(340, 140, toString(scorePlayer), GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
    if(!showdealer or flagw)
	drawText(120, 190, toString(dealer.getValue()), GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
	drawText(120, 390, toString(player.getValue()), GLUT_BITMAP_HELVETICA_18, 255, 255, 255);

	if (flagl)
	{
		drawText(200, 190, "YOU LOSE", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
	}
	else if (flagw)
	{
		drawText(200, 190, "YOU WIN", GLUT_BITMAP_HELVETICA_18, 255, 255, 255);
	}

    glFlush();
}


void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
		case 27:

		   exit(0);
		break;

		case 'd':
		case 'D':
		    if(!gameOver){
                surrender=true;
                onGameOver();}
			gameInit();
			showdealer=true;
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
				showdealer=false;
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
