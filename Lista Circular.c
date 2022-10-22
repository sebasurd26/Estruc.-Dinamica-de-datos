#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	
	int dato;
	struct nodo* siguiente;
	
} Nodo;

Nodo* inicio = NULL;
Nodo* ultimo = NULL;

	//Creamos el nodo.
void crearNodo();

	//Visualizar la lista.
void verLista();

	//Vaciar lista.
void vaciarNodo();


int main(){
int d, opc;
	
	printf ("\n\tLISTAS CIRCULARES\n");
	printf ("\nIndique la cantidad de datos que desea ingresar: "); scanf("%d",&d);
	
	for(int i=0; i<d; i++)
	{
		crearNodo();
	}
	
	do
	{
		printf ("\n1) Ingresar mas datos a la lista.\n2) Visualizar lista.\n3) Vaciar lista.\n4) Finalizar.");
		printf ("\n\n\t4Indique la opcion: "); scanf ("%d", &opc);
		
		switch (opc){
			
			case 1:	printf("\n\tDigite la cantidad de datos que desea ingresar: ");
					scanf("%d", &d);
				
					for(int i=0; i<d; i++)
					{
						crearNodo();
					} break;
		
			case 2:	printf ("\n\tLista:  ");
					verLista();
					printf ("\n"); 		
					break;
					
			case 3:	while(inicio != NULL)
					{
						vaciarNodo();
						printf("\n\tLista: ");
						verLista();
						printf ("\n");
					} break;
		
			case 4: break;
		}
	
	} while (opc!=4);

	
system ("pause");	
return 0;
}


	//Funciones: 
void crearNodo()
{
	Nodo* nuevo = (Nodo*) malloc (sizeof(Nodo));
	
	printf ("\nIngrese un dato: "); scanf ("%d", &nuevo->dato); 
	
	if(inicio == NULL){
		inicio = nuevo;
		inicio->siguiente = inicio;
		ultimo = inicio;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = inicio;
		ultimo = nuevo;
	}
}


void verLista()
{
	Nodo* actual = (Nodo*) malloc (sizeof(Nodo));
	
	actual = inicio;
	
	if(inicio == NULL){
		printf("\nLa lista esta vacia...\n");
	}else{
		do{
			printf("\n%d ", actual->dato);
			actual = actual->siguiente;
		}while (actual != inicio);
	}
}


void vaciarNodo()
{	
	Nodo *actual = (Nodo*) malloc (sizeof(Nodo));
	actual = inicio;
	Nodo* anterior = (Nodo*) malloc (sizeof(Nodo));
	anterior = NULL;
	
	int NodoBuscado=0, ubicado=0;
	printf ("\nNodo a eliminar: "); scanf ("%d", &NodoBuscado);
	
	if(inicio != NULL)
	{
		while (actual != NULL && ubicado != 1)
		{
			if (actual->dato == NodoBuscado)
			{
				if(actual == inicio)
				{
					inicio = inicio->siguiente;
				}
				else if (actual == ultimo)
				{
					anterior->siguiente = NULL;
					ultimo = anterior;
				} else 
				{
					anterior->siguiente = actual->siguiente;
				}
				
				printf("\n\tNODO ELIMINADO!");
				ubicado = 1;
			}	
			anterior = actual;
			actual = actual->siguiente;		
		}
		if (ubicado == 0)
		{
			printf("\n\tNODO NO ENCONTRADO!");
		} else {
			free(anterior);
		}	
	} else {
		printf("\n\tLISTA VACIA!");
	}	
}
