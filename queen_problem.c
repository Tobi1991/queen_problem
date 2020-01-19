#include <stdio.h>
#include "queen_problem.h"

// Programmvariablen
int count_all = 0;	// zählt alle überprüften Möglichkeiten
int count_res = 0;	// zählt die Resultate

// Initialisierungsfunktionen

// Initialisiere das Spielfeld
field initializeField(field f){
	for (int i=0; i<8; i++){
		for (int j=0; j<8; j++){
			f.field[i][j] = 0;
				}
		}
	return f;
}

// Getter Functions

// Ermittelt kartesische Koordinaten aus der Nummer eines Feldes
coordinates getCoordinates(pos p){
	int x = (p.i % 8) - 1;
	int y = (p.i - (p.i % 8)) / 8;
	if (p.i % 8 == 0) y--;		
	coordinates coords;
	coords.x = x;
	coords.y = y;
	return coords;
}

// Setter Functions

// Setzt eine Dame auf das p-te Feld
field setFigure(pos p, field f){
	
	coordinates coords = getCoordinates(p);
		
	// setzt die Felder, die durch die Turmeigenschaft angegriffen werden
	for (int i=0; i<8; i++) {
		f.field[i][coords.x] = 1;
		f.field[coords.y][i] = 1;
	}
			
// setzt die Felder, die durch die Läufereigenschaft angegriffen werden
coordinates diag1 = {coords.x - min(coords.x, coords.y), coords.y - min(coords.x, coords.y)};	// das oberste linke Diagonalfeld
coordinates diag2 = {(7 - (7 - (coords.x) - min((7 - coords.x), coords.y))), coords.y - min((7 - coords.x), coords.y)};	// das oberste rechte Diagonalfeld
	
	// setzt die erste Diagonale
	while ((diag1.x != 7) && (diag1.y != 7)) {
		f.field[diag1.y][diag1.x] = 1;
		diag1.x++;
		diag1.y++;
	}
	f.field[diag1.y][diag1.x] = 1;
	
	// setzt die zweite Diagonale
	while ((diag2.x != 0) && (diag2.y != 7)){
		f.field[diag2.y][diag2.x] = 1;
		diag2.x--;
		diag2.y++;
	}
	f.field[diag2.y][diag2.x] = 1;

	
	f.field[coords.y][coords.x] = 0;	// Reparatur
	
	return f;
}

// Setzt eine Dame auf die gegebenen kartesischen Koordinaten
field setCartFigure(coordinates coords, field f){
	
	// setzt die Felder, die durch die Turmeigenschaft angegriffen werden
	for (int i=0; i<8; i++) {
		f.field[i][coords.x] = 1;
		f.field[coords.y][i] = 1;
	}
			
// setzt die Felder, die durch die Läufereigenschaft angegriffen werden
coordinates diag1 = {coords.x - min(coords.x, coords.y), coords.y - min(coords.x, coords.y)};	// das oberste linke Diagonalfeld
coordinates diag2 = {(7 - (7 - (coords.x) - min((7 - coords.x), coords.y))), coords.y - min((7 - coords.x), coords.y)};	// das oberste rechte Diagonalfeld
	
	// setzt die erste Diagonale
	while ((diag1.x != 7) && (diag1.y != 7)) {
		
		f.field[diag1.y][diag1.x] = 1;
		diag1.x++;
		diag1.y++;
	}
	f.field[diag1.y][diag1.x] = 1;
	
	// setzt die zweite Diagonale
	while ((diag2.x != 0) && (diag2.y != 7)){
		
		f.field[diag2.y][diag2.x] = 1;
		diag2.x--;
		diag2.y++;
	}
	f.field[diag2.y][diag2.x] = 1;

	
	f.field[coords.y][coords.x] = 0;// Reparatur
	
	return f;
}

// Hilfsfunktionen

// Hilfsfunktion für das Minimum zweier Zahlen
int min(int x, int y){
	if (x <= y) return x;
return y;
}

// Hilfsfunktion für das Maximum zweier Zahlen
int max(int x, int y){
	if (x >= y) return x;
return y;
}

// Swap-Funktion
void swap(int *x, int *y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

// Output

// Drucke ein Array vom Typ int
void print_array(int *array, int length)
{
    for (int i = 0; i < length; i++) { printf("%d ", *(array + i)); }
}


// Drucke ein Spielfeld
void printField(field f){
	for (int i=0; i<8; i++) {
		printf("\n");
		for (int j=0; j<8; j++){
			printf("%d ", f.field[i][j]);
		}
	}
printf("\n\n");

}

// Die eigentliche Applikation

// Überprüft ob die Stellung zulässig ist
int test(field f, int *a, int length){

	for (int i=0; i<length; i++){
	if (f.field[*(a + i)][i] == 1) return 0;
	}
	
return 1;
}

/* 
	Function to print permutations of string
	This function takes three parameters:
	1. String
	2. Starting index of the string
	3. Ending index of the string. 
*/

// Die Hauptfunktion (modifizierte permutate() Funktion)
int simulate(int *a, int i, int n, int length, field f){
	int j;
	if (i==n){
		// Anfang Hauptteil
		int k=0;
		for (k; k<8; k++){
		coordinates coords = {k, *(a + k)};		
		if (f.field[coords.y][coords.x] == 1) {k=9; break;}	// Gehe zur nächsten Permutation über, wenn ein Feld schon angegriffen wird
		f = setCartFigure(coords, f);		

		}
		// Ende Hauptteil
		
		if ((test(f, a, length) == 1) && (k == 8)){// die for-Schleife wurde nicht unterbrochen
			count_res++;
			printField(f);
		}
			
		
		count_all++;
		if ((count_all % 2500) == 0){
		// printf("Es wurden %d Möglichkeiten untersucht\n", count_all);
		}		

	} else {

		for (j = i; j<=n; j++){
			swap((a+i), (a+j));
			f = initializeField(f);
			simulate(a, i+1, n, length, f);
			swap((a+i), (a+j));	// backtrack
				}
		}
return 0;
}

// Hauptfunktion
int main(){

	field f;
	f = initializeField(f);
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
	simulate(array, 0, 7, 8, f);
	printf("Es wurden %d Resultate gefunden\n", count_res);
	return 0;

}


