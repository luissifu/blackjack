//
//  Hand.h
//  BlackJack
//
//  Luis Sifuentes A01138688
//  
//

#ifndef BlackJack_Card_h
#define BlackJack_Card_h

/*
#include <string.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
*/

using namespace std;

class Card
{
public:
	// Constructor
	 Card(char ss, char vv);
	
	// metodos modificadores
	void setSuit(char ss);
	void setValue(char vv);
	
	// metodos de acceso
	char getSuit();
	char getValue();
	int getRealValue();
	
	// otros métodos
	void muestra();
	// static void dibujaPoligono(int xMin, int xMax, int yMin, int yMax);
	// void draw(int x, int y);
	
	
private:
	// Atributos
	char s, v;
};

#endif

