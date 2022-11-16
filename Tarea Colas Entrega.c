#include <stdlib.h> 
#include <stdio.h> 
 
typedef struct _nodo { 
   int valor; 
   struct _nodo *siguiente; 
} tipoNodo; 
 
typedef tipoNodo *pNodo; 
 
//Funciones con colas: 
void Anadir(pNodo *primero, pNodo *ultimo, int v); 
int Leer(pNodo *primero, pNodo *ultimo); 
 
int main() 
{ 
   pNodo primero = NULL, ultimo = NULL; 
 
   Anadir(&primero, &ultimo, 20); 
   printf("Agregar (20)\n");
    
   Anadir(&primero, &ultimo, 10); 
   printf("Agregar (10)\n"); 
   printf("Ultimo: %d\n\n", Leer(&primero, &ultimo));
    
   Anadir(&primero, &ultimo, 40); 
   printf("Aniadir(40)\n");
    
   Anadir(&primero, &ultimo, 30); 
   printf("Aniadir(30)\n"); 
   printf("Anterior: %d\n", Leer(&primero, &ultimo)); 
   printf("Ultimo: %d\n\n", Leer(&primero, &ultimo));
    
   Anadir(&primero, &ultimo, 90); 
   printf("Aniadir(90)\n"); 
   printf("Anterior: %d\n", Leer(&primero, &ultimo)); 
   printf("Ultimo: %d\n\n", Leer(&primero, &ultimo)); 
 
   system("PAUSE"); 
   return 0; 
} 
 
void Anadir(pNodo *primero, pNodo *ultimo, int v) 
{ 
   pNodo nuevo; 
 
   /* Crear un nodo nuevo */ 
   nuevo = (pNodo)malloc(sizeof(tipoNodo)); 
   nuevo->valor = v; 
   
   /* Este ser� el �ltimo nodo, no debe tener siguiente */ 
   nuevo->siguiente = NULL; 
   
   /* Si la cola no estaba vac�a, a�adimos el nuevo a continuaci�n de ultimo */ 
   if(*ultimo) (*ultimo)->siguiente = nuevo; 
   
   /* Ahora, el �ltimo elemento de la cola es el nuevo nodo */ 
   *ultimo = nuevo; 
   
   /* Si primero es NULL, la cola estaba vac�a, ahora primero apuntar� tambi�n al nuevo nodo */ 
   if(!*primero) *primero = nuevo; 
} 
 
 
int Leer(pNodo *primero, pNodo *ultimo) 
{ 
   pNodo nodo; /* variable auxiliar para manipular nodo */ 
   int v;      /* variable auxiliar para retorno */ 
    
   /* Nodo apunta al primer elemento de la pila */ 
   nodo = *primero; 
   
   if(!nodo) return 0; /* Si no hay nodos en la pila retornamos 0 */ 
   /* Asignamos a primero la direcci�n del segundo nodo */ 
   
   *primero = nodo->siguiente; 
   /* Guardamos el valor de retorno */ 
   
   v = nodo->valor;  
   /* Borrar el nodo */ 
   
   free(nodo); 
   /* Si la cola qued� vac�a, ultimo debe ser NULL tambi�n*/ 
   
   if(!*primero) *ultimo = NULL; 
   return v; 
}
