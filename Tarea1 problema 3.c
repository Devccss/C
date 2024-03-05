#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <string.h>

//Struct
typedef struct nodo{
    char name[30];
    int timeProcedure;
    int indice;
    struct nodo *sig;
}NODO;

//Functions
NODO *addNodo(NODO *list,int cont,int *total);
NODO *eliminarP(NODO *list,int cont,int *total);
void cambiarIndices(NODO *list,int cont);


int main(){
    int menu=0,cont=0,totalTime=0,*total;
    total=&totalTime;
    NODO *list=NULL;
    printf("Bienvenido \n\n");
    do{
        printf("\nEl tiempo total de espera es: %d Mins.\n\n",totalTime);
        printf(" Dijite '1' para agregar personas\n");
        printf(" Dijite '2' para quitar personas de la cola\n");
        printf(" Dijite '3' para salir del programa\n");
        printf(" %c ",175);
        scanf("%d",&menu);
        printf("\n");
        if(menu==1){
            cont++;
            list=addNodo(list,cont,total);
        }
        if(menu==2){
            if(list==NULL){
                printf("\tAun no hay personas en la cola\n\n");
            }else{
                list=eliminarP(list,cont,total);
                cont--;
                cambiarIndices(list,cont);
            }
            
        }
        if(menu==3){
            exit(-1);
        }
    }while(menu==1||menu==2);

}

//Agregar nodo
NODO *addNodo(NODO *list,int cont,int *total){
    int procedure,n;
    NODO *newValue=NULL;
    NODO *head=list;
    newValue=(NODO *) malloc(sizeof(NODO));
    newValue->timeProcedure = 0;
    NODO *current=NULL;
    if(list==NULL){
        system("cls");
        printf(" Retiro\n");
        printf(" Deposito\n");
        printf(" Consulta\n");
        printf(" Actualizacion\n");
        printf(" Pagos\n");
        printf("\n");
        printf(" CUANTOS de estos tramites desea relizar?: ");
        scanf("%d",&n);
        while(n<1){
            printf("\n #Ingrese un numero valido: \n");
            scanf("%d",&n);
        }
        system("cls");
        printf(" \nIngrese el nombre: ");
        scanf("%s",newValue->name);
        fflush(stdin);
        printf("\n");
        
        newValue->indice=cont;
        for(int i=0;i<n;i++){
            
            do{
                if(n>1){
                    printf(" %d%c TRAMITE \n\n",i+1,248);
                }
                printf(" 1. Retiro\n");
                printf(" 2. Deposito\n");
                printf(" 3. Consulta\n");
                printf(" 4. Actualizacion\n");
                printf(" 5. Pagos\n");
                printf(" Ingrese el NUMERO del tramite que realizara: ");
                scanf("%d",&procedure);
                printf("\n");
                switch (procedure)
                {
                case 1:
                    newValue->timeProcedure=newValue->timeProcedure+5;
                    *total=*total+5;
                    break;
                case 2:
                    newValue->timeProcedure=newValue->timeProcedure+2;
                    *total=*total+2;
                    break;
                case 3:
                    newValue->timeProcedure=newValue->timeProcedure+4;
                    *total=*total+4;
                    break;
                case 4:
                    newValue->timeProcedure=newValue->timeProcedure+5;
                    *total=*total+5;
                    break;
                case 5:
                    newValue->timeProcedure=newValue->timeProcedure+6;
                    *total=*total+6;
                    break;
                default:
                    printf("\nIngrese un numero valido: ");
                    printf("\n");
                    break;
                }
            }while(procedure<1||procedure>5);
            
            
            if(list==NULL){
                list=newValue;
                current=newValue;
            }else{
                current->sig=newValue;
                current=newValue;
            }
            current->sig=list;
        }
    }else{
        current=list;
        system("cls");
        printf(" Retiro\n");
        printf(" Deposito\n");
        printf(" Consulta\n");
        printf(" Actualizacion\n");
        printf(" Pagos\n");
        printf("\n");
        printf(" CUANTOS de estos tramites desea relizar?: ");
        scanf("%d",&n);
        while(n<1){
            printf("\n #Ingrese un numero valido: \n");
            scanf("%d",&n);
        }
        system("cls");
        printf(" \nIngrese el nombre: ");
        scanf("%s",newValue->name);
        fflush(stdin);
        printf("\n");
        newValue->indice=cont;
        for(int i=0;i<n;i++){
            
            do{
                if(n>1){
                    printf(" %d%c TRAMITE \n\n",i+1,248);
                }
                printf(" 1. Retiro\n");
                printf(" 2. Deposito\n");
                printf(" 3. Consulta\n");
                printf(" 4. Actualizacion\n");
                printf(" 5. Pagos\n");
                printf(" Ingrese el NUMERO del tramite que realizara: ");
                scanf("%d",&procedure);
                printf("\n");
                switch (procedure)
                {
                case 1:
                    newValue->timeProcedure=newValue->timeProcedure+5;
                    *total=*total+5;
                    break;
                case 2:
                    newValue->timeProcedure=newValue->timeProcedure+2;
                    *total=*total+2;
                    break;
                case 3:
                    newValue->timeProcedure=newValue->timeProcedure+4;
                    *total=*total+4;
                    break;
                case 4:
                    newValue->timeProcedure=newValue->timeProcedure+5;
                    *total=*total+5;
                    break;
                case 5:
                    newValue->timeProcedure=newValue->timeProcedure+6;
                    *total=*total+6;
                    break;
                default:
                    printf("\nIngrese un numero valido: ");
                    printf("\n");
                    break;
                }
            }while(procedure<1||procedure>5);
            for(i=0; i<cont;i++){
                current=current->sig;
            }
            current->sig=newValue;
            current=newValue;
            current->sig=head;
        }    
    }
    return list;
}

NODO *eliminarP(NODO *list,int cont,int *total){
    int i,opcion;
    NODO *actual=list,*anterior=NULL;
    for(i=0;i<cont;i++){
        printf("\n %d.%s ->",actual->indice,actual->name);
        printf("(Se restaran %d mins del tiempo de espera)\n",actual->timeProcedure);
        actual=actual->sig;
    }
    printf("\n Ingresa el NUMERO de la persona que quitaras\n");
    printf(" %c",175);
    scanf("%d",&opcion);
    actual=list;
    for(i=0;i<cont;i++){
        anterior=actual;
        if(actual->indice==opcion){
            //Unir el anterior con el siguiente
            anterior->sig=actual->sig;
            //restarle al total time
            *total=*total-actual->timeProcedure;
            //liberar memoria
            free(actual);
        }
        actual=actual->sig;
    }
    return list;
}

void cambiarIndices(NODO *list,int cont){
    int i;
    NODO *actual=list;
    for( i=0;i<cont;i++){
        actual->indice=i+1;
        actual=actual->sig;
    }
}