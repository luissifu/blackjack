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
		return 1;
	else
		return 11;
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

void drawText(int x, int y, std::string text, void* font, int r, int g, int b) {
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
	text += v;
	int r = 0;

	if (s == 'H' || s == 'D')
		r = 255;

	drawText(x+5, y+20, text, GLUT_BITMAP_HELVETICA_18, r,0,0);
	drawBackground(x + 10, x + 40, y + 50, y + 80);
}
