#include <stdio.h>
#include <stdlib.h>

#include <math.h>



int zjednotenie (int mnozina1[], int mnozina2[], int mnozina3[], int pocet1, int pocet2) {

	int i;

	for (i=0; i<pocet1; i++) {
		mnozina3[i]=mnozina1[i];
	}
	for (i=pocet1; i<pocet1+pocet2; i++) {
		mnozina3[i]=mnozina2[i-pocet1];
	}

	return pocet1+pocet2;
}





main () {

	int mnozina1[]= {7,5,8,4,4,1,2};
	int mnozina2[]= {4,1,2,0,9,7};

	//velkost vystupneho pola, do kt. sa uklada vysledok musi byt rovna minimalna minimalne suctu velkosti poli mnozina1 a mnozina2
	int mnozina3[13];

	int pocet=zjednotenie (mnozina1,mnozina2,mnozina3,7,6);

	int i;

	for (i=0; i<pocet; i++) {
		printf ("%d ", mnozina3[i]);
	}

	printf ("\n");


}
