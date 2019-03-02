/*
    Nombre: Hillany Rodriguez
    Carnet: 14-10937

    PRACTICA 4: LISTAS ENLAZADAS

 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

///Declaración de Nodo y Lista.

typedef struct nodo{
    int val;
    struct nodo* sig;
}Nodo;

typedef Nodo* Lista;

///Añada los siguientes Constructores a su Proyecto.

Lista newList(){
    return NULL;
}

// Inserta en la cabeza de la lista

void inserta(int x, Lista *L){
    Nodo *p= malloc(sizeof(Nodo));
    p->val = x;
    p->sig = *L;
    *L = p;
}

///Agregue Observadores.

// retorna 1 si la lista esta vacia y 0 si no
int esVacia(Lista L){

return L== NULL;
}

// pre: L no esta vacia
int firstInList(Lista L){

return L-> val;
}

//Booleano 1 si x está, 0 si no
int estaEn(int x, Lista L){
    Nodo*p=L;

    while(p != NULL && p-> val != x) p= p->sig;

return p!=NULL;
}

// Escribe la lista L de nombre name entre dos corchetes
void writeList(Lista L, char name[]){
    printf("\n%s = [",name);
    if(L==NULL){
        printf("].");
    }
    else{
        while(L->sig!= NULL){
            printf("%d, ", L->val);
            L=L->sig;
        }

        printf("%d].", L->val);
    }
}

///Agregue Otras Funciones NO RECURSIVAS.

// inserte a x al final de la Lista L-- spend
void InsertaT(int x, Lista *L){

    Nodo *p= malloc(sizeof(Nodo));
    Nodo *q=*L;
    p->val=x;
    p->sig=NULL;
    if(*L == NULL){
        *L=p;
    }
    else{
        while(q->sig!=NULL) q=q->sig;
        (q->sig)=p;
    }

}

//Elimina la primera ocurrencia de x de la lista L
void elimina(int x, Lista *L){
    Nodo *p = *L, *q;

    if (p != NULL){

        if (p->val == x){
                *L=p->sig;
                free(p);
        }
        else {
            while (p->sig != NULL && (p->sig)->val != x) p = p->sig; //BUSQUEDA lINEAL

            if (p->sig != NULL) {
                q=p->sig;
                p->sig=q->sig;
                free(q);
            }
        }
    }
}

//Produce en *N una copia de L
void clona(Lista L, Lista *N){
    *N = NULL;
    Nodo *q;
    if (L != NULL){
        *N=L;
        q=malloc(sizeof(Nodo));
        q->val=(*N)->val;
        q->sig=(*N)->sig;
        *N=q;

        while(L->sig != NULL){
            q->sig = malloc(sizeof(Nodo));
            (q->sig)->val=(L->sig)->val;
            q=q->sig;
            L=L->sig;
        }
        q->sig = NULL; //Porque cuando el ciclo acaba la lista esta sin terminar
    }
}

//Concatena las listas L y K. L= L:K, K = NULL
void concat(Lista *L, Lista *K){
    if (*L == NULL) *L = *K;
        else {
            Nodo *p = *L;

            while(p->sig!=NULL){
                p=p->sig;
            }
            p->sig=*K;
        }
    *K = NULL;
}

///Agregue algunas Funciones Recursivas.

int sizeR(Lista L){
    if(L == NULL) return 0;
    else return 1+ sizeR(L->sig);
}

//Recursiva.
int estaEnR(int x, Lista L){
    if(L == NULL) return 0;
    else if (L->val == x) return 1;
return estaEnR(x, L->sig);
}

//Inserta a x al final de la Lista L---apend
void insertaTR(int x, Lista *L){
    if(*L == NULL) {
        Nodo *p = malloc(sizeof(Nodo));
        p->val = x;
        p->sig = NULL;
        *L = p;
    }
    else insertaTR(x, &((*L)->sig));
}

//Elimina la primera ocurrencia de x en la Lista *L
void eliminaR(int x, Lista *L){
    if (*L != NULL){
        if ((*L)->val == x) {
            Nodo *p = *L;
            *L = (*L)->sig;
            free(p);
        }
        else eliminaR(x, &((*L)->sig));
    }
}

///EJERCICIOS

///1 Mezcla de Listas.
Lista merge(const Lista L1, const Lista L2){

	Lista L3;
	Nodo *q,*p,*r;
	if(L1!=NULL && L2!= NULL){
		Nodo *q= malloc(sizeof(Nodo));
		L3=q;p=L1;r=L2;
		while(p !=NULL && r !=NULL ){
			if((p->val)<=(r->val)){
				q->val=p->val;
				if(p->sig!=NULL){
					q->sig=malloc(sizeof(Nodo));
					q=q->sig;
				}
				p=p->sig;
			}
			else{
				q->val=r->val;
				if(r->sig!=NULL){
					q->sig=malloc(sizeof(Nodo));
					q=q->sig;
				}
				r=r->sig;
			}
		}
		if(p !=NULL || r !=NULL ){
			q->sig=malloc(sizeof(Nodo));
			q=q->sig;
		}

		while(p != NULL){
			q->val=r->val;
			if(r->sig!=NULL){
				q->sig=malloc(sizeof(Nodo));
				q=q->sig;
			}
			p=p->sig;
		}
		while(r != NULL){
			q->val=r->val;
			if(r->sig!=NULL){
				q->sig=malloc(sizeof(Nodo));
				q=q->sig;
			}
			r=r->sig;
		}
		q->sig = NULL;

	}
	 free(p);free(r);
	return L3;
}



///2. Inserción Ordenada.

void insertOrd(int x, Lista *L){
    Nodo *p=malloc(sizeof(Nodo));

    if(*L==NULL||x<(*L)->val){
        p->val=x;
        p->sig=*L;
        *L=p;
    }
        else insertOrd(x,&(*L)->sig);
}

///3. Halla el máximo de una lista no vacía.

Nodo* maximo(Lista L){
    int x=0;
    Nodo *p=malloc(sizeof(Nodo));
    p=L;
    while(p!=NULL){
        if((p->val)>x){
            x=p->val;
           L=p;
        }
        p=p->sig;
    }

return L;
}

///4. Hallar la posición de un elemento x dentro de una lista.

Nodo* posicion(Lista L, int x){
    Nodo *p=malloc(sizeof(Nodo));
    p=L;

    while(p!=NULL && (p->val)!=x ){
            p=p->sig;

        }
        L=p;
return L;
}



int main(){

    printf("\nProbando Lista.. :");
    Lista L=newList(), L1=newList();

    writeList(L,"L");
    inserta(2,&L);
    inserta(11,&L);
    inserta(8,&L);
    writeList(L,"L");

    printf("\nA la cabeza de L esta: %d", firstInList(L));

    if(esVacia(L1)) printf("\nL1 es vacia,");
        else printf("\nL1 NO es vacia");

    int x= 8; char s[]= "L";

    if(estaEn(x,L)) printf("\n%d esta en %s. ",x, s );
        else printf("\n%d No esta en %s. ",x, s );

    printf("\nInsertando en la cola:");
    InsertaT(78,&L);
    writeList(L,"L");

    printf("\nEliminando x:");
    elimina(11,&L);
    writeList(L,"L");

    printf("\nClonando:");

    clona(L,&L1);
    writeList(L1,"L1");

    printf("\nConcatenando:");
    concat(&L,&L1);
    writeList(L,"L");
    writeList(L1,"L1");

    Lista L2=newList();

    Nodo* t;
    Nodo* r;

    InsertaT(1,&L2);
    InsertaT(4,&L2);
    InsertaT(8,&L2);
    InsertaT(9,&L2);
    InsertaT(20,&L2);

    writeList(L2,"L2");

    insertOrd(7,&L2);

    writeList(L2,"L2");

    t=maximo(L2);

    printf("\nel maximo es :%d",t->val);

    r=posicion(L2,9);

    printf("\nel numero que busco es %d",r->val);
    InsertaT(5,&L1);
    InsertaT(7,&L1);
    InsertaT(12,&L1);
    InsertaT(18,&L1);

    writeList(merge(L1,L2),"merge");


    return 0;
}



