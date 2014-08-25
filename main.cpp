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
bool flagw;
bool flagl;
bool flagstart=false;

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
	flagw=false;
	flagl=false;
	flagstart=true;
}

void onGameOver() {
	gameOver = true;
	if(player.getValue()==dealer.getValue()or (dealer.getValue()>player.getValue()and dealer.getValue()<=21))
    {
        flagl=true;
    }
    else if(dealer.getValue()>21 and player.getValue()<=21){
        flagw=true;
    }
	//implemeenta esta funcion
	//aqui decide quien gano
}

void hit()
{   if(flagstart){
	if (player.getValue() <= 21)
	{
		player.addCard(deck.dealCard());
    }
	else
	{   flagl=true;
		onGameOver();
	}
}
}

void stand()
{
    if(flagstart){
	while(dealer.getValue()<=17){
		dealer.addCard(deck.dealCard());
    }

	onGameOver();
    }}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    dealer.draw(20, 100);
    player.draw(20, 300);

    glColor3ub(255,255,255);
	glRasterPos2i(20,250);
    char p='P';
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,p);
     glColor3ub(255,255,255);
	glRasterPos2i(40,250);
    char l='L';
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,l);
     glColor3ub(255,255,255);
	glRasterPos2i(60,250);
    char a='A';
     glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,a);
     glColor3ub(255,255,255);
	glRasterPos2i(80,250);
    char y='Y';
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,y);
     glColor3ub(255,255,255);
	glRasterPos2i(100,250);
    char e='E';
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,e);
     glColor3ub(255,255,255);
	glRasterPos2i(120,250);
    char r='R';
     glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,r);

       glColor3ub(255,255,255);
	glRasterPos2i(20,050);
    char d='D';
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,d);
     glColor3ub(255,255,255);
	glRasterPos2i(40,050);

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,e);
     glColor3ub(255,255,255);
	glRasterPos2i(60,050);
     glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,a);
     glColor3ub(255,255,255);
	glRasterPos2i(80,050);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,l);
     glColor3ub(255,255,255);
	glRasterPos2i(100,050);

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,e);
     glColor3ub(255,255,255);
	glRasterPos2i(120,050);

     glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,r);



if(flagw){
 glColor3ub(255,255,255);
	glRasterPos2i(200,250);
    char text='Y';
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text);
     glColor3ub(255,255,255);
	glRasterPos2i(220,250);
    char text1='O';
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text1);
     glColor3ub(255,255,255);
	glRasterPos2i(235,250);
    char text2='U';
     glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text2);
     glColor3ub(255,255,255);
	glRasterPos2i(260,250);
    char text3='W';
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text3);
     glColor3ub(255,255,255);
	glRasterPos2i(280,250);
    char text4='I';
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text4);
     glColor3ub(255,255,255);
	glRasterPos2i(290,250);
    char text5='N';
     glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text5);
 }

 if(flagl){
 glColor3ub(255,255,255);
	glRasterPos2i(200,250);
    char text='Y';
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text);
     glColor3ub(255,255,255);
	glRasterPos2i(220,250);
    char text1='O';
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text1);
     glColor3ub(255,255,255);
	glRasterPos2i(235,250);
    char text2='U';
     glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text2);
     glColor3ub(255,255,255);
	glRasterPos2i(260,250);
    char text3='L';
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text3);
     glColor3ub(255,255,255);
	glRasterPos2i(270,250);
    char text4='O';
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text4);
       glColor3ub(255,255,255);
	glRasterPos2i(290,250);
    char text6='S';
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text6);
     glColor3ub(255,255,255);
	glRasterPos2i(310,250);
    char text7='E';
     glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text7);
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
    glutKeyboardFunc(keyboard);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
