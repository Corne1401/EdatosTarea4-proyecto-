#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Pokemon{
    int id;
    char name[30];
    char nickname[30];
    char type[30];
    int gender;
    char nature[30];
    float weight;
    float height;
    int shiny;
    struct Pokemon *next;
}Pokemon;

Pokemon *primero;
Pokemon *ultimo;

void mostrar_menu() {

    printf("\n\nMenú:\n=====\n\n");
    printf("1.- Añadir elementos\n");
    printf("2.- Mostrar lista\n");
    printf("3.- Consultar Registro\n");
    printf("4.- Eliminar Registro\n");
    printf("5.- Consultar Nombre\n");
    printf("6.- Posiciones de memoria\n");
    printf("7.- Salir\n\n");
    printf("Escoge una opción: ");
    fflush(stdout);
}

void AgregarElemnto(){
    Pokemon *nuevo;
    nuevo = (Pokemon *)malloc(sizeof(Pokemon));

    printf("Pokemon id(el id es numerico): ");
    scanf("%d",&nuevo->id);
    while (getchar() != '\n');
    printf("\n");

    printf("Nombre del pokemon(maximo 30 caracteres): ");
    scanf("%s",nuevo->name);
    while (getchar() != '\n');
    printf("\n");

    printf("Nick del pokemon(maximo 30 caracteres): ");
    scanf("%s",nuevo->nickname);
    while (getchar() != '\n');
    printf("\n");

    printf("Tipo de pokemon(maximo 30 caracteres): ");
    scanf("%s",nuevo->type);
    while (getchar() != '\n');
    printf("\n");

    printf("1.Masculino\n");
    printf("2.Femenino\n");
    scanf("%d",&nuevo->gender);
    while (getchar() != '\n');

    printf("1.Shiny\n");
    printf("2.No Shiny\n");
    scanf("%d",&nuevo->shiny);
    while (getchar() != '\n');

    printf("Naturaleza del pokemon(maximo 30 caracteres): ");
    scanf("%s",nuevo->nature);
    while (getchar() != '\n');
    printf("\n");


    printf("Peso del pokemon: ");
    scanf("%f",&nuevo->weight);
    while (getchar() != '\n');
    printf("\n");


    printf("Altura del pokemon: ");
    scanf("%f",&nuevo->height);
    while (getchar() != '\n');
    printf("\n");

    nuevo->next = NULL;

    if(primero==NULL){
        primero = nuevo;
        ultimo = nuevo;
    }
    else{
        ultimo->next = nuevo;
        ultimo = nuevo;
    }

}
void MostrarLista(){
    struct Pokemon *aux = primero;

    while(aux != NULL){
        printf("------------------------\n");
        printf("pokemon id: %d\n",aux->id);
        printf("nombre: %s\n",aux->name);
        printf("nick: %s\n",aux->nickname);
        printf("tipo: %s\n",aux->type);
        if(aux->gender == 1){
            printf("genero: male\n");
        }else if(aux->gender == 2){
            printf("genero: female\n");
        }
        printf("naturaleza: %s\n",aux->nature);
        printf("peso: %f\n",aux->weight);
        printf("altura: %f\n",aux->height);
        if(aux->shiny == 1){
            printf("shiny: si\n");
        }else if(aux->shiny == 2){
            printf("shiny: no\n");
        }
        aux = aux->next;
    }
}
void ConsultarRegistro(int searchId){
    struct Pokemon *aux = primero;
    while(aux->id != searchId){
        if(aux == NULL){
            printf("No existe el registro\n");
            return;
        }
        aux = aux->next;
    }
    printf("pokemon id: %d\n",aux->id);
    printf("nombre: %s\n",aux->name);
    printf("nick: %s\n",aux->nickname);
    printf("tipo: %s\n",aux->type);
    if(aux->gender == 1){
        printf("genero: male\n");
    }else if(aux->gender == 2){
        printf("genero: female\n");
    }
    printf("naturaleza: %s\n",aux->nature);
    printf("peso: %f\n",aux->weight);
    printf("altura: %f\n",aux->height);
    if(aux->shiny == 1){
        printf("shiny: si\n");
    }else if(aux->shiny == 2){
        printf("shiny: no\n");
    }

}
void ConsultarRegistroNombre(const char *searchName){
    struct Pokemon *aux = primero;
    while(strcmp(aux->name,searchName)!=0){
        if(aux == NULL){
            printf("No existe el registro\n");
            return;
        }
        aux = aux->next;
    }
    printf("pokemon id: %d\n",aux->id);
    printf("nombre: %s\n",aux->name);
    printf("nick: %s\n",aux->nickname);
    printf("tipo: %s\n",aux->type);
    if(aux->gender == 1){
        printf("genero: male\n");
    }else if(aux->gender == 2){
        printf("genero: female\n");
    }
    printf("naturaleza: %s\n",aux->nature);
    printf("peso: %f\n",aux->weight);
    printf("altura: %f\n",aux->height);
    if(aux->shiny == 1){
        printf("shiny: si\n");
    }else if(aux->shiny == 2){
        printf("shiny: no\n");
    }

}
void EliminarRegistro(int registro){
    Pokemon *aux1 = primero;

    while(aux1 != NULL){
        if(registro == primero->id && registro == ultimo->id){
            free(primero);
            free(ultimo);
            primero = NULL;
            ultimo = NULL;
        }
        else if(aux1->next->id == registro){
            Pokemon *borrar = aux1->next;
            aux1->next = borrar->next;
            free(borrar);
            break;
        }
        else if(registro == primero->id){
            Pokemon *borrar = primero;
            primero = aux1->next;
            free(borrar);
            break;
        }
        aux1 = aux1->next;
    }
    if (registro == ultimo->id){
        free(ultimo);
        aux1->next = NULL;
        ultimo = aux1;
    }
}
void ConsultarDireccionRegistro(int registro){
    struct Pokemon *aux = primero;
    while(aux->id != registro){
        if(aux == NULL){
            printf("No existe el registro\n");
            return;
        }
        aux = aux->next;
    }
    printf("Direccion de memoria: %p\n", aux);
    printf("int id: %lu\n",sizeof(aux->id));
    printf("char nombre: %lu\n",sizeof(aux->name));
    printf("char nick: %lu\n",sizeof(aux->nickname));
    printf("char tipo: %lu\n",sizeof(aux->type));
    printf("int gender: %lu", sizeof(aux->gender));
    printf("char naturaleza: %lu\n",sizeof(aux->nature));
    printf("float peso: %lu\n",sizeof(aux->weight));
    printf("float altura: %lu\n",sizeof(aux->height));
    printf("int shiny: %lu", sizeof(aux->shiny));
}

int main(){
    char opcion;
    int idSearch;
    char nameSearch[30] = {'\0'};
    int registro;
    primero = (struct Pokemon *) NULL;
    ultimo = (struct Pokemon *) NULL;

    do {

        mostrar_menu();
        scanf("%c", &opcion);
        while (getchar() != '\n');
        switch (opcion) {
            case '1':
                AgregarElemnto();
                break;
            case '2':
                MostrarLista();
                break;
            case '3':
                printf("Ingrese el numero de registro a consultar: ");
                scanf("%d",&idSearch);
                while (getchar() != '\n');
                ConsultarRegistro(idSearch);
                break;
            case '4':
                printf("Ingrese el nummero de registro a eliminar: ");
                scanf("%d", &registro);
                while((getchar()) != '\n');
                EliminarRegistro(registro);
                break;
            case '5':
                printf("Ingrese el nombre del registro a buscar: ");
                scanf("%s",nameSearch);
                while (getchar() != '\n');
                ConsultarRegistroNombre(nameSearch);
                break;
            case '6':
                printf("Ingrese el nummero de registro a consultar: ");
                scanf("%d", &registro);
                while((getchar()) != '\n');
                ConsultarDireccionRegistro(registro);
                break;
            case '7':
                printf("Gracias por usar el programa\n");
            default:
                printf("Opcion no valida\n");

        }

        } while (opcion!='7');
    return 0;
}
