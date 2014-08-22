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
		return 10;
}


void Card::muestra()
{
	cout << s << ":" << v << endl;
}


void Card::drawBackground(int xMin, int xMax, int yMin, int yMax)
{
	glColor3ub(255,255,255);
	glBegin(GL_POLYGON);
		glVertex2d( xMin,yMin);
		glVertex2d( xMax,yMin );
		glVertex2d( xMax,yMax);
		glVertex2d( xMin,yMax);
	glEnd();
}
void Card::draw(int x, int y)
{
	drawBackground(x, x + 50, y, y + 100);
}