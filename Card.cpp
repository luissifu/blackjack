#include "Card.h"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

Card:: Card(char ss, char vv)
{
	s = ss;
	v = vv;
}

// metodos modificadores
void Card::setSuit(char ss)
{
	s=ss;
}
void Card::setValue(char vv)
{
	v=vv;
}


char Card::getSuit()
{
	return s;
}

char Card::getValue()
{
	return v;
}

int Card::getRealValue() {
	if (v >= '0' && v <= '9')
		return v - '0';
	else if (v == 'A')
		return 11;
	else
		return 10;
}


void Card::muestra()
{
	cout << s << ":" << v << endl;
}


void Card::drawBackground(int xMin, int xMax, int yMin, int yMax) {
	//glColor3ub(255,255,255);
	glBegin(GL_POLYGON);
		glVertex2d( xMin,yMin);
		glVertex2d( xMax,yMin );
		glVertex2d( xMax,yMax);
		glVertex2d( xMin,yMax);
	glEnd();
}

void Card::drawText(int x, int y, std::string text, void* font, int r, int g, int b) {
	glColor3ub(r, g, b);
	glRasterPos2i(x, y);

	for (string::iterator i = text.begin(); i != text.end(); ++i)
	{
		char c = *i;
		glutBitmapCharacter(font, c);
	}
}

void Card::draw(int x, int y) {
	glColor3ub(255,255,255);
	drawBackground(x, x + 50, y, y + 100);
	std::string text = "";
	
	if (v == 'T')
		text = "10";
	else
		text += v;
	
	int r = 0;

	if (s == 'H' || s == 'D')
		r = 255;

	drawText(x+5, y+20, text, GLUT_BITMAP_HELVETICA_18, r,0,0);

	switch(s) {
		case 'H':
			drawHeart(x + 10, y + 50);
		break;
		case 'D':
			drawDiamond(x + 10, y + 50);
		break;
		case 'S':
			drawSpade(x + 10, y + 50);
		break;
		case 'C':
			drawClub(x + 10, y + 50);
		break;
		default:
		break;
	}
}

void Card::drawHeart(int x, int y) {
	glBegin(GL_POLYGON);
		glVertex2d(x+15,y+30);
		glVertex2d(x,y+15);
		glVertex2d(x,y+5);
		glVertex2d(x+5,y);
		glVertex2d(x+10,y);
		glVertex2d(x+15,y+5);
		glVertex2d(x+20,y);
		glVertex2d(x+25,y);
		glVertex2d(x+30,y+5);
		glVertex2d(x+30,y+15);
	glEnd();
}

void Card::drawSpade(int x, int y) {
	glBegin(GL_POLYGON);
		glVertex2d(x + 15, y);
		glVertex2d(x+3, y + 10);
		glVertex2d(x+3, y + 20);
		glVertex2d(x + 12, y + 25);
		glVertex2d(x + 18, y + 25);
		glVertex2d(x+27, y + 20);
		glVertex2d(x+27, y + 10);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2d(x + 11, y + 30);
		glVertex2d(x + 15, y + 22);
		glVertex2d(x + 19, y + 30);
	glEnd();
}

void Card::drawClub(int x, int y) {
	glBegin(GL_POLYGON);
		glVertex2d(x+8, y+11);
		glVertex2d(x, y+19);
		glVertex2d(x+8, y+27);
		glVertex2d(x+16, y+19);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2d(x + 22, y + 11);
		glVertex2d(x + 30, y + 19);
		glVertex2d(x + 22, y + 27);
		glVertex2d(x + 14, y + 19);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2d(x + 15, y);
		glVertex2d(x + 7, y + 8);
		glVertex2d(x + 15, y + 16);
		glVertex2d(x + 23, y + 8);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2d(x+11, y+30);
		glVertex2d(x+15, y+22);
		glVertex2d(x+19, y+30);
	glEnd();
}

void Card::drawDiamond(int x, int y) {
	glBegin(GL_POLYGON);
		glVertex2d(x+15, y);
		glVertex2d(x+3, y+15);
		glVertex2d(x+15, y+30);
		glVertex2d(x+27, y+15);
	glEnd();
}