#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main(int argc, char *argv[])
{

    int opcion = 0;
    char M[5][10][50];
    int S[6][10];
    int n_de_mascotas;
    int caso;

    remove("factura.txt");

    while (1)
    {
        printf("\tServicio de mascotas\n");
        printf("\nMenu principal:\n");
        printf("1. Toma de datos para las mascotas \n");
        printf("2. Servicios \n");
        printf("3. Facturar Servicios \n");
        printf("4. Salir\n");
        printf("Ingrese una opcion\n");
        scanf("%d", &opcion);
        getchar();
        fflush(stdin);
        system("cls");

        switch (opcion)
        {
        case 1:
            toma_de_datos(M, &n_de_mascotas);
            break;
        case 2:
            Servicios(S, n_de_mascotas, M);
            break;
        case 3:

            printf("\t\tMETODOS PARA IMPRIMIR FACTURA\n\n");
            printf("1.  Busqueda por ID de la mascota\n");
            printf("2.  Busqueda por el nombre del dueño\n");
            scanf("%d", &caso);

            switch (caso)
            {
            case 1:
                busqueda_por_id(n_de_mascotas, M, S);
                break;
            case 2:
                busqueda_por_nombre(n_de_mascotas, M, S);
                break;

            default:
                printf("Ingrese una opcion valida\n\n");
                break;
            }

            break;
        case 4:
            return 0;
            break;

        default:
            printf("Ingrese una opcion valida\n\n");
            break;
        }
    }
}