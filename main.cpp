#include "includeGL.h"

#include "Card.h"
#include "Hand.h"
#include "Deck.h"

using namespace std;

const int winWidth = 500;
const int winHeight = 500;

Deck deck;
Hand player;
Hand dealer;

void init() {
	glClearColor(0.011, 0.75, 0.23, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 500, 0);
}

void gameInit() {
	deck.shuffle();
	player.addCard(deck.dealCard());
	dealer.addCard(deck.dealCard());
	player.addCard(deck.dealCard());
	dealer.addCard(deck.dealCard());
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);

	dealer.draw(20, 100);
	player.draw(20, 300);

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(winWidth, winHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("BlackJack");
	init();
	gameInit();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}