#include <stdio.h>
#include <stdlib.h> //Cambio necesario para utilizar malloc

typedef struct agenda {

    char nombre[20];
    char telefono[12];
    struct agenda *siguiente;
}agenda;

struct agenda *ultimo;
void *primero;

void mostrar_menu() {

    printf("\n\nMenú:\n=====\n\n");
    printf("1.- Añadir elementos\n");
    printf("2.- Borrar elementos\n");
    printf("3.- Mostrar lista\n");
    printf("4.- Salir\n\n");
    printf("Escoge una opción: ");
    fflush(stdout);

}

/* Con esta función añadimos un elemento al final de la lista */

void anadir_elemento() {
    struct agenda *nuevo;

/* reservamos memoria para el nuevo elemento */
    nuevo = (struct agenda *) malloc (sizeof(struct agenda));

    if (nuevo==NULL)

        printf( "No hay memoria disponible!\n");

    printf("\nNuevo elemento:\n");
    printf("Nombre: ");
    fflush(stdout);
    scanf("%s",nuevo->nombre);//gets es obsoleto
    printf("Teléfono: ");
    fflush(stdout);
    scanf("%s",nuevo->telefono);

/* el campo siguiente va a ser NULL por ser el último

elemento de la lista */

    nuevo->siguiente = NULL;

/* ahora metemos el nuevo elemento en la lista. lo situamos
al final de la lista, se comprueba si la lista está vacía. si primero==NULL es que no hay ningún elemento en la lista. también vale ultimo==NULL */

    if (primero==NULL) {
        printf( "Primer elemento\n");
        primero = nuevo;
        ultimo = nuevo;

    } else {

/* el hasta ahora último apuntará al nuevo */
        ultimo->siguiente = nuevo;
/* hacemos que el nuevo sea ahora el último */
        ultimo = nuevo;

    }

}

void mostrar_lista() {

    struct agenda *auxiliar; /* para recorrer la lista */

    int i; i=0;
    auxiliar = primero;
    printf("\nMostrando la lista completa:\n");
    while (auxiliar!=NULL) {

        printf( "Nombre: %s, Telefono: %s\n",
                auxiliar->nombre,auxiliar->telefono);

        auxiliar = auxiliar->siguiente;
        i++;

    }
    if (i==0) printf( "\nLa lista está vacía!!\n" );

}

int main() {
    char opcion;
    primero = (struct agenda *) NULL;
    ultimo = (struct agenda *) NULL;
    do {
        mostrar_menu();
        scanf("%c",&opcion); // getch es obsoleto
        switch ( opcion ) {
            case '1': anadir_elemento(); break;
            case '2': printf("No disponible todavía!\n"); break;
            case '3': mostrar_lista(); break; // no se necesitan argumentos en esta funcion
            case '4': exit( 1 );
            default:
                printf( "Opción no válida\n" );
                break;

        }

    } while (opcion!='4');
}