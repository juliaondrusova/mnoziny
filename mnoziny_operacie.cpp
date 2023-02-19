#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0


//funkcia kontroluje ci mnozina obsahuje dany prvok alebo nie
int obsahuje(int mnozina[], int pocet, int prvok) {
	
	int i;
	
	for(i=0; i<pocet; i++) {
		if (mnozina[i]== prvok) {
			return TRUE;
		}
	}
	return FALSE;
}


int zjednotenie (int mnozina1[], int mnozina2[], int mnozina3[], int pocet1, int pocet2) {

	int i, j;
	int mnozina4[pocet1+pocet2];
	int pocet=0;

	//nacitanie vsetkych prvkov z oboch vstupnych mnozin
	for (i=0; i<pocet1; i++) {
		mnozina3[i]=mnozina1[i];
	}
	for (i=pocet1; i<pocet1+pocet2; i++) {
		mnozina3[i]=mnozina2[i-pocet1];
	}

	//kontrola, ci su niekotore prvky zhodne alebo nie
	for (i=0; i<pocet1+pocet2; i++) {
		
		//ak dany prvok mnozina neobsahuje, tak ho tam prida a zvysi pocet o 1
		if (!obsahuje(mnozina4,pocet,mnozina3[i])) {
			mnozina4[pocet]=mnozina3[i];
			pocet++;
		}
	}
	
	//priradenie uz vyslednej mnoziny do tej, ktora bola na vstupe
	for (i=0; i<pocet; i++) {
		mnozina3[i]=mnozina4[i];
	}
	
	//vracia pocet prvkov zjednotenej mnoziny
	return pocet;
}

int prienik (int mnozina1[], int mnozina2[], int mnozina3[], int pocet1, int pocet2) {
	
	int i, j;
	int pocet=0;
	int pocet_1=0;
	int mnozina4[pocet1+pocet2];
	
	for (i=0;i<pocet1; i++) {
		for (j=0;j<pocet2;j++) {
			if (mnozina1[i]==mnozina2[j]) {
				mnozina3[pocet]=mnozina1[i];
				pocet++;
				break;
			}
		}
	}
	
	//kontrola, ci su niekotore prvky zhodne alebo nie
	for (i=0; i<pocet; i++) {
		
		//ak dany prvok mnozina neobsahuje, tak ho tam prida a zvysi pocet o 1
		if (!obsahuje(mnozina4,pocet,mnozina3[i])) {
			mnozina4[pocet_1]=mnozina3[i];
			pocet_1++;
		}
	}
	
	//priradenie uz vyslednej mnoziny do tej, ktora bola na vstupe
	for (i=0; i<pocet_1; i++) {
		mnozina3[i]=mnozina4[i];
	}
	
	return pocet_1;
}



main () {

	int mnozina1[]= {7,5,8,4,4,1,2};
	int mnozina2[]= {4,1,2,0,9,7};
	int i;
	
	//velkost vystupneho pola, do kt. sa uklada operacia mnozin, musi byt rovna minimalne suctu velkosti oboch mnozin
	int zjednotena_mnozina[13];
	int prienikova_mnozina[13];
	
	
	int pocet_z=zjednotenie (mnozina1,mnozina2,zjednotena_mnozina,7,6);

	for (i=0; i<pocet_z; i++) {
		printf ("%d ", zjednotena_mnozina[i]);
	}

	printf ("\n");


	int pocet_p=prienik (mnozina1,mnozina2,prienikova_mnozina,7,6);
	
	for (i=0; i<pocet_p; i++) {
		printf ("%d ", prienikova_mnozina[i]);
	}

}
