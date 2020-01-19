// Datenstrukturen

// Das Spielfeld
typedef struct{
	_Bool field[8][8];	// das ist noch doof mit dem int
} field;

typedef struct {
	unsigned int i: 6;
} pos;

typedef struct {
	unsigned int x: 3;
	unsigned int y: 3;
} coordinates;

// Funktionen

// Initialisierungsfunktionen

// initialisiere das Spielfeld
field initializeField(field f);

// Getter Functions

// Ermittelt kartesische Koordinaten aus der Nummer eines Feldes
coordinates getCoordinates(pos p);

// Setter Functions

// Setzt eine Dame auf das p-te Feld
field setFigure(pos p, field f);

// Setzt eine Dame auf die gegebenen kartesischen Koordinaten
field setCartFigure(coordinates coords, field f);

// Helper Functions

// Hilfsfunktion für das Minimum zweier Zahlen
int min(int x, int y);

// Hilfsfunktion für das Maximum zweier Zahlen
int max(int x, int y);

// Swap-Funktion
void swap(int *x, int *y);

// Output

// Drucke ein Array vom Typ int
void print_array(int *array, int length);

// Drucke ein Spielfeld
void printField(field f);

// Main Functions

// Überprüft ob die Stellung zulässig ist
int test(field f, int *a, int length);

// Die Hauptfunktion (modifizierte permutate() Funktion)
int simulate(int *a, int i, int n, int length, field f);



