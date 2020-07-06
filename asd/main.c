#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char descripcion[128];
    int codigoPostal;
}eLocalidad;



typedef struct
{
    int dni;
    char nombre[128];
    int localidad;

}ePersona;


#define TAMPERSONAS 5
#define TAMLOCALIDADES 4

int mostrarMenu();
void mostrarPersona(ePersona x, eLocalidad localidades[], int tamlocalidades);
void mostrarPersonas(ePersona x[],int tamPersonas,eLocalidad localidades[],int tamLocalidades);
int cargarDescripcionLocalidad(char localidad[],int id, eLocalidad localidades[], int tamlocalidades);
void ordenarPersonas(ePersona vec[], int tamPersonas,eLocalidad localidades[],int tamLocalidades);

int main()
{
    char seguir='s';
    char confirma;

    ePersona listaPersonas[TAMPERSONAS] = {{43673004, "Alberto",2}, {62451305, "Jorge",3}, {35214793, "Carlos",4},{42013468, "Felipe",2},{51234602,"Jose",4}};
    eLocalidad listaLocalidades[TAMLOCALIDADES] = {{1, "Quilmes",1878}, {2, "Burzaco",3632}, {3, "Avellaneda",4451},{4, "Monserrat",1842}};

    do
    {
        fflush(stdin);
        switch(mostrarMenu())
        {
        case 1:
            //MOSTRAR PERSONAS
            mostrarPersonas(listaPersonas,TAMPERSONAS,listaLocalidades,TAMLOCALIDADES);
            break;
        case 2:
            //ORDENAR PERSONAS
            ordenarPersonas(listaPersonas,TAMPERSONAS,listaLocalidades,TAMLOCALIDADES);
            break;
        case 3:
            //SALIR
            printf("Confirma salida: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma=='s')
            {
                seguir='n';
            }
            break;
        default:
            printf("\n\nIngrese una opcion valida\n\n");
        }
        system("pause");
    }
    while(seguir=='s');

    return 0;
}

int mostrarMenu()
{
    int opcion;
    system("cls");
    printf("**** Menu de opciones ****\n\n");
    printf("1- Mostrar personas\n");
    printf("2- Ordenar personas\n");
    printf("3- Salir\n\n");
    printf("Indique la opcion: ");
    scanf("%d",&opcion);


    return opcion;
}


void mostrarPersona(ePersona x, eLocalidad localidades[], int tamlocalidades)
{
    char nombreLocalidad[128];


    cargarDescripcionLocalidad(nombreLocalidad,x.localidad,localidades,tamlocalidades);


    printf("%2d     %10s      %10s     \n",x.dni,x.nombre,nombreLocalidad);

}

void mostrarPersonas(ePersona x[],int tamPersonas,eLocalidad localidades[],int tamLocalidades)
{
    int flag=0;
    system("cls");
    printf("\n*****LISTADO DE PERSONAS *****\n");
    printf("ID              NOMBRE          LOCALIDAD    \n");

    for(int i=0; i<tamPersonas; i++)
    {
        mostrarPersona(x[i],localidades,tamLocalidades);
        flag=1;
    }
    if(flag==0)
    {
        printf("\nNo hay personas que listar\n\n");
    }

}

int cargarDescripcionLocalidad(char localidad[],int id, eLocalidad localidades[], int tamlocalidades)
{
    int todoOK = 0;

    for(int i=0; i<tamlocalidades; i++)
    {
        if(localidades[i].id==id)
        {
            strcpy(localidad,localidades[i].descripcion);
            todoOK = 1;
        }
    }

    return todoOK;
}

void ordenarPersonas(ePersona vec[], int tamPersonas,eLocalidad localidades[],int tamLocalidades)
{
    ePersona auxPersona;
    char auxLocalidad[128];
    char auxLocalidad2[128];

     for(int i=0; i<tamPersonas-1; i++)
    {
        for(int j=i+1; j<tamPersonas; j++)
        {

                if(strcmp(vec[i].nombre,vec[j].nombre)>0)
                {
                    auxPersona=vec[i];
                    vec[i]=vec[j];
                    vec[j]=auxPersona;
                }
                else
                {
                    cargarDescripcionLocalidad(auxLocalidad,vec[i].localidad,localidades,tamLocalidades);
                    cargarDescripcionLocalidad(auxLocalidad2,vec[j].localidad,localidades,tamLocalidades);
                    if(vec[i].nombre == vec[j].nombre && strcmp(auxLocalidad,auxLocalidad2)>0)
                    {
                        auxPersona=vec[i];
                        vec[i]=vec[j];
                        vec[j]=auxPersona;
                    }
                }

        }
    }
    mostrarPersonas(vec,tamPersonas,localidades,tamLocalidades);
}
