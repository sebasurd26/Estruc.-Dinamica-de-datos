#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTAMCAD 1000
	/*Crear arbol binario por parametros y que calcule altura junto a la cantidad de hojas*/

typedef struct estruct{
	int id;
} Item;

typedef struct elemento{
	Item dato;
	struct elemento *padre, *izq, *der; 
} Nodo;

typedef struct {
	Nodo *raiz;
} Arbol;

Nodo* crearN (Item x){
	Nodo *a;
	a = malloc(sizeof(Nodo));
	
	a->dato=x;
	a->padre=NULL;
	a->izq=NULL;
	a->der=NULL;
	
	return a;
}


	/*Funciones*/
void iniciar (Arbol *arb){
	arb->raiz=NULL;
}

void mostrarN (Nodo *v){
	printf("Nodo %d ---> ", v->dato.id);
	
	if(v->padre!=NULL) printf("Padre: %d\t\n", v->padre->dato.id);
	else printf("Padre: NINGUNO!\t\n");
	
	if(v->izq!=NULL) printf("Hijo Izquierdo: %d\t\n", v->izq->dato.id);
	else printf("Hijo Izquierdo: NINGUNO!\t\n");
	
	if(v->der!=NULL) printf("Hijo Derecho: %d\t\n", v->der->dato.id);
	else printf("Hijo Derecho: NINGUNO!\t\n");	
}

void mostrarArb (Nodo *nodo, char cad[]){ 	//Mostrandolo con recursividad.
	printf ("%d\n", nodo->dato.id);
	
	/*Para el hijo izquierdo*/
	if (nodo->izq!=NULL){
		char cad2[MAXTAMCAD]; strcpy(cad2, cad);
		
		if (nodo->der!=NULL){
			printf ("%s%c%c%c%c%c", cad, 195, 196, 196, 196, 196);
			char simb = 179, aux[2];
			aux[0] = simb; aux[1]='\0'; strcat(cad2, aux);
			strcat (cad2, "   ");
			mostrarArb (nodo->izq, cad2);
		}
		else{
			printf ("%s%c%c%c%c%c", cad, 192, 196, 196, 196, 196);
			strcat (cad2, "   ");
			mostrarArb (nodo->izq, cad2);
		}
	}
	
	/*Para el hijo derecho*/
	if (nodo->der!=NULL){
		char cad3[MAXTAMCAD]; strcpy(cad3, cad);
		printf ("%s%c%c%c%c%c", cad, 192, 196, 196, 196, 196);
		strcat (cad3, "   ");
		mostrarArb (nodo->der, cad3);
	}	
}

void view_ArbBin (Arbol arb){ 		/*Permite visualizar la estructura del arbol*/
	if (arb.raiz==NULL) printf ("El arbol esta VACIO!!\n");
	else mostrarArb (arb.raiz, " ");
}

int nivelN (Nodo *v){
	int nivel=0;
	while (v->padre!=NULL){ 	//Llegamos a la raiz?
		nivel++;
		v = v->padre;
	}
	return nivel;
}

int altura (Nodo *v){
	if (v==NULL) return -1; 	//caso base.
	int altIzq = altura(v->izq), altDer = altura(v->der); 	//altura de los sub arboles
	
	//Se elige el mayor valor y se le suma 1
	if (altIzq > altDer) return altIzq+1;
	else return altDer+1;
}

int AlturaArbol (Arbol arb){
	return altura(arb.raiz);
}

int nroNodos (Nodo *v){ 	//de forma recursiva
	if (v==NULL) return 0;
	int nroIzq = nroNodos (v->izq), nroDer = nroNodos (v->der);
	return nroIzq+nroDer+1; 	//Sumamos los valores y le agregamos 1 mas (por el nodo v)
}

int nro_de_Nodos (Arbol arb){
	return nroNodos (arb.raiz);
} 


int main (){
	
	Arbol arbol;
	iniciar (&arbol);
	
	/*Construccion del arbol*/
	Item x;
	Nodo *nodo1, *nodo2, *nodo3, *nodo4, *nodo5, *nodo6, *nodo7, *nodo8, *nodo9, *nodo10, *nodo11;
	
	x.id=5; nodo1 = crearN(x); arbol.raiz = nodo1;
	x.id=100; nodo2 = crearN(x); nodo1->izq = nodo2; nodo2->padre = nodo1;
	x.id=3; nodo3 = crearN(x); nodo3->padre = nodo1; nodo1->der = nodo3;
	x.id=20; nodo4 = crearN(x); nodo4->padre = nodo2; nodo2->izq = nodo4;
	x.id=10; nodo5 = crearN(x); nodo5->padre = nodo2; nodo2->der = nodo5;
	x.id=7; nodo6 = crearN(x); nodo6->padre = nodo4; nodo4->izq = nodo6;
	x.id=4; nodo7 = crearN(x); nodo7->padre = nodo4; nodo4->der = nodo7;
	x.id=64; nodo8 = crearN(x); nodo8->padre = nodo6; nodo6->der = nodo8;
	x.id=2; nodo9 = crearN(x); nodo9->padre = nodo3; nodo3->izq = nodo9;
	x.id=34; nodo10 = crearN(x); nodo10->padre = nodo5; nodo5->izq = nodo10;
	x.id=12; nodo11 = crearN(x); nodo11->padre = nodo3; nodo3->der = nodo11;
	
	mostrarN (nodo6); 	//Mostrar la info del nodo.
	printf ("Nivel: %d\n", nivelN(nodo6));
	
	printf ("\n\tEl arbol es: \n");
	view_ArbBin (arbol);
	printf ("\n\tLa altura del arbol es: %d\n", AlturaArbol(arbol));
	printf ("\tLa cantidad de nodos en el arbol es: %d\n", nro_de_Nodos(arbol));
	
	printf ("\n\n");
	
system ("pause");
return 0;	
}
