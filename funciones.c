#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void toma_de_datos(char M[5][10][50], int *n)
{
    int cantidad = 0;
    printf("Cuantas mascotas desea registrar independientemente del dueño\n");
    scanf("%d", &cantidad);
    *n = cantidad;
    system("cls");

    for (int i = 0; i < cantidad; i++)
    {
        printf("\t Datos mascota %d\n", i + 1);
        for (int j = 0; j < 5; j++)
        {
            if (j == 0)
            {
                printf("Ingrese el ID de la mascota\n");
                scanf("%s", M[j][i]);
            }
            else if (j == 1)
            {
                printf("Ingrese el nombre de la mascota\n");
                scanf("%s", M[j][i]);
            }
            else if (j == 2)
            {
                printf("Ingrese el tipo de mascota\n");
                scanf("%s", M[j][i]);
            }
            else if (j == 3)
            {
                printf("Ingrese la edad de la mascota\n");
                scanf("%s", M[j][i]);
            }
            else if (j == 4)
            {
                printf("Ingrese el nombre del dueño de la mascota\n");
                scanf("%s", M[j][i]);
            }
        }
        system("cls");
    }
}

void Servicios(int S[6][10], int n_de_mascotas, char M[5][10][50])
{
    char dato;
    char alternativa;

    for (int i = 0; i < n_de_mascotas; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            S[j][i] = 0;
        }

    servicios:
        printf("\t\tEliga los servicios que desea para %s\n\n", M[1][i]);
        printf("\t\t\t SERVICIOS\n\n");
        printf("a.  (ID 1010)\tDesparasitacion\t\tPastillas que ingiere la mascota\t\t\t\t($15)\n");
        printf("b.  (ID 1020)\tCorte de pelo\t\tCorte con tijeras del pelaje de la mascota\t\t\t($12)\n");
        printf("c.  (ID 1030)\tBaño\t\t\tLimpieza general de la mascota\t\t\t\t\t($20)\n");
        printf("d.  (ID 1040)\tVacunas\t\t\tColocar las Inmunizaciones requeridas para la mascota\t\t($30)\n");
        printf("e.  (ID 1050)\tPipetas antipulgas\tInyecciones en el hombro para quitar las pulgas\t\t\t($10)\n");
        printf("Seleccione una opccion\n");
        scanf("%c", &dato);
        getchar();
        fflush(stdin);
        system("cls");

        switch (dato)
        {
        case 'a':

            S[0][i] = 15;

            printf("Desea otro servicio para %s, Si(s); No(n)\n", M[1][i]);
            scanf("%c", &alternativa);
            getchar();
            fflush(stdin);
            if (alternativa == 's' || alternativa == 'S')
            {
                goto servicios;
            }

            break;
        case 'b':

            S[1][i] = 12;

            printf("Desea otro servicio para %s, Si(s); No(n)\n", M[1][i]);
            scanf("%c", &alternativa);
            getchar();
            fflush(stdin);
            if (alternativa == 's' || alternativa == 'S')
            {
                goto servicios;
            }
            break;
        case 'c':

            S[2][i] = 20;

            printf("Desea otro servicio para %s, Si(s); No(n)\n", M[1][i]);
            scanf("%c", &alternativa);
            getchar();
            fflush(stdin);
            if (alternativa == 's' || alternativa == 'S')
            {
                goto servicios;
            }
            break;
        case 'd':

            S[3][i] = 30;

            printf("Desea otro servicio para %s, Si(s); No(n)\n", M[1][i]);
            scanf("%c", &alternativa);
            getchar();
            fflush(stdin);
            if (alternativa == 's' || alternativa == 'S')
            {
                goto servicios;
            }
            break;
        case 'e':

            S[4][i] = 10;

            printf("Desea otro servicio para %s, Si(s); No(n)\n", M[1][i]);
            scanf("%c", &alternativa);
            getchar();
            fflush(stdin);
            if (alternativa == 's' || alternativa == 'S')
            {
                goto servicios;
            }
            break;
        default:
            break;
        }
        S[5][i] = S[0][i] + S[1][i] + S[2][i] + S[3][i] + S[4][i];
    }
}

void busqueda_por_id(int n_de_mascotas, char M[5][10][50], int S[6][10])
{
    FILE *archivo = fopen("factura.txt", "a");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo de factura\n");
        return;
    }

    int comper;

    printf("Ingrese el Id de la mascota que desea facturar\n");
    scanf("%d", &comper);
    getchar();
    fflush(stdin);
    system("cls");

    for (int i = 0; i < n_de_mascotas; i++)
    {
        if (comper == atoi(M[0][i]))
        {
            for (int j = 0; j < 5; j++)
            {
                if (j == 0)
                {
                    fprintf(archivo, "\t\t\t\t\t\t########## FACTURA #########\n\n");
                    fprintf(archivo, "ID de la mascota = %s\t\t", M[j][i]);
                }
                if (j == 1)
                {
                    fprintf(archivo, "Nombre de la mascota = %s\t\t", M[j][i]);
                }
                if (j == 2)
                {
                    fprintf(archivo, "Tipo de mascota = %s\n", M[j][i]);
                }
                if (j == 3)
                {
                    fprintf(archivo, "Edad = %s\t\t\t\t\t", M[j][i]);
                }
                if (j == 4)
                {
                    fprintf(archivo, "Nombre del dueño = %s\n\n", M[j][i]);
                    fprintf(archivo, "======================================================================================================================================\n\n");
                }
            }
        }
    }

    for (int i = 0; i < n_de_mascotas; i++)
    {
        if (comper == atoi(M[0][i]))
        {
            for (int j = 0; j < 6; j++)
            {

                if (S[j][i] == 15)
                {
                    fprintf(archivo, "(ID 1010)\tDesparasitacion\t\tPastillas que ingiere la mascota\t\t\t\t\t\t\t%d\n", S[j][i]);
                }
                if (S[j][i] == 12)
                {
                    fprintf(archivo, "(ID 1020)\tCorte de pelo\t\tCorte con tijeras del pelaje de la mascota\t\t\t\t\t%d\n", S[j][i]);
                }
                if (S[j][i] == 20)
                {
                    fprintf(archivo, "(ID 1030)\tBaño\t\t\t\tLimpieza general de la mascota\t\t\t\t\t\t\t\t%d\n", S[j][i]);
                }
                if (S[j][i] == 30)
                {
                    fprintf(archivo, "(ID 1040)\tVacunas\t\t\t\tColocar las Inmunizaciones requeridas para la mascota\t\t%d\n", S[j][i]);
                }
                if (S[j][i] == 10)
                {
                    fprintf(archivo, "(ID 1050)\tPipetas antipulgas\tInyecciones en el hombro para quitar las pulgas\t\t\t\t%d\n\n", S[j][i]);
                }
                if (S[j][i] == S[5][i])
                {
                    fprintf(archivo, "Total\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t%d\n\n\n", S[5][i]);
                }
            }
        }
    }
    fclose(archivo);
    for (int i = 0; i < n_de_mascotas; i++)
    {
        if (comper == atoi(M[0][i]))
        {
            for (int j = 0; j < 5; j++)
            {
                if (j == 0)
                {
                    printf("\t\t\t########## FACTURA #########\n\n");
                    printf("ID de la mascota = %s\t", M[j][i]);
                }
                if (j == 1)
                {
                    printf("Nombre de la mascota = %s\t", M[j][i]);
                }
                if (j == 2)
                {
                    printf("Tipo de mascota = %s\n", M[j][i]);
                }
                if (j == 3)
                {
                    printf("Edad = %s\t", M[j][i]);
                }
                if (j == 4)
                {
                    printf("\tNombre del dueño = %s\n\n", M[j][i]);
                    printf("======================================================================================================================================\n\n");
                }
            }
        }
    }

    for (int i = 0; i < n_de_mascotas; i++)
    {
        if (comper == atoi(M[0][i]))
        {
            for (int j = 0; j < 6; j++)
            {

                if (S[j][i] == 15)
                {
                    printf("(ID 1010)\tDesparasitacion\t\tPastillas que ingiere la mascota\t\t\t%d\n", S[j][i]);
                }
                if (S[j][i] == 12)
                {
                    printf("(ID 1020)\tCorte de pelo\t\tCorte con tijeras del pelaje de la mascota\t\t%d\n", S[j][i]);
                }
                if (S[j][i] == 20)
                {
                    printf("(ID 1030)\tBaño\t\t\tLimpieza general de la mascota\t\t\t\t%d\n", S[j][i]);
                }
                if (S[j][i] == 30)
                {
                    printf("(ID 1040)\tVacunas\t\t\tColocar las Inmunizaciones requeridas para la mascota\t%d\n", S[j][i]);
                }
                if (S[j][i] == 10)
                {
                    printf("(ID 1050)\tPipetas antipulgas\tInyecciones en el hombro para quitar las pulgas\t\t%d\n\n", S[j][i]);
                }
                if (S[j][i] == S[5][i])
                {
                    printf("Total\t\t\t\t\t\t\t\t\t\t\t\t%d\n\n\n", S[5][i]);
                }
            }
        }
    }
}

void busqueda_por_nombre(int n_de_mascotas, char M[5][10][50], int S[6][10])
{
    FILE *archivo = fopen("factura.txt", "a");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo de factura\n");
        return;
    }

    char nombre[50];

    system("cls");
    printf("Ingrese el nombre del dueño de las mascotas que desea facturar\n");
    scanf("%s", nombre);
    getchar();
    fflush(stdin);
    system("cls");

    for (int i = 0; i < n_de_mascotas; i++)
    {
        if (strcmp(nombre, M[4][i]) == 0)
        {
            for (int j = 0; j < 5; j++)
            {
                if (j == 0)
                {
                    fprintf(archivo, "\t\t\t\t\t\t########## FACTURA #########\n\n");
                    fprintf(archivo, "ID de la mascota = %s\t\t", M[j][i]);
                }
                if (j == 1)
                {
                    fprintf(archivo, "Nombre de la mascota = %s\t\t", M[j][i]);
                }
                if (j == 2)
                {
                    fprintf(archivo, "Tipo de mascota = %s\n", M[j][i]);
                }
                if (j == 3)
                {
                    fprintf(archivo, "Edad = %s\t\t\t\t\t", M[j][i]);
                }
                if (j == 4)
                {
                    fprintf(archivo, "Nombre del dueño = %s\n\n", M[j][i]);
                    fprintf(archivo, "======================================================================================================================================\n\n");

                    if (strcmp(nombre, M[4][i]) == 0)
                    {
                        for (int k = 0; k < 6; k++)
                        {

                            if (S[k][i] == 15)
                            {
                                fprintf(archivo, "(ID 1010)\tDesparasitacion\t\tPastillas que ingiere la mascota\t\t\t\t\t\t\t%d\n", S[k][i]);
                            }
                            if (S[k][i] == 12)
                            {
                                fprintf(archivo, "(ID 1020)\tCorte de pelo\t\tCorte con tijeras del pelaje de la mascota\t\t\t\t\t%d\n", S[k][i]);
                            }
                            if (S[k][i] == 20)
                            {
                                fprintf(archivo, "(ID 1030)\tBaño\t\t\t\tLimpieza general de la mascota\t\t\t\t\t\t\t\t%d\n", S[k][i]);
                            }
                            if (S[k][i] == 30)
                            {
                                fprintf(archivo, "(ID 1040)\tVacunas\t\t\t\tColocar las Inmunizaciones requeridas para la mascota\t\t%d\n", S[k][i]);
                            }
                            if (S[k][i] == 10)
                            {
                                fprintf(archivo, "(ID 1050)\tPipetas antipulgas\tInyecciones en el hombro para quitar las pulgas\t\t\t\t%d\n\n", S[k][i]);
                            }
                            if (S[k][i] == S[5][i])
                            {
                                fprintf(archivo, "Total\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t%d\n\n\n", S[5][i]);
                            }
                        }
                    }
                }
            }
        }
    }
    fclose(archivo);
    for (int i = 0; i < n_de_mascotas; i++)
    {
        if (strcmp(nombre, M[4][i]) == 0)
        {
            for (int j = 0; j < 5; j++)
            {
                if (j == 0)
                {
                    printf("\t\t\t########## FACTURA #########\n\n");
                    printf("ID de la mascota = %s\t", M[j][i]);
                }
                if (j == 1)
                {
                    printf("Nombre de la mascota = %s\t", M[j][i]);
                }
                if (j == 2)
                {
                    printf("Tipo de mascota = %s\n", M[j][i]);
                }
                if (j == 3)
                {
                    printf("Edad = %s\t", M[j][i]);
                }
                if (j == 4)
                {
                    printf("\tNombre del dueño = %s\n\n", M[j][i]);
                    printf("======================================================================================================================================\n\n");

                    if (strcmp(nombre, M[4][i]) == 0)
                    {
                        for (int k = 0; k < 6; k++)
                        {

                            if (S[k][i] == 15)
                            {
                                printf("(ID 1010)\tDesparasitacion\t\tPastillas que ingiere la mascota\t\t\t%d\n", S[k][i]);
                            }
                            if (S[k][i] == 12)
                            {
                                printf("(ID 1020)\tCorte de pelo\t\tCorte con tijeras del pelaje de la mascota\t\t%d\n", S[k][i]);
                            }
                            if (S[k][i] == 20)
                            {
                                printf("(ID 1030)\tBaño\t\t\tLimpieza general de la mascota\t\t\t\t%d\n", S[k][i]);
                            }
                            if (S[k][i] == 30)
                            {
                                printf("(ID 1040)\tVacunas\t\t\tColocar las Inmunizaciones requeridas para la mascota\t%d\n", S[k][i]);
                            }
                            if (S[k][i] == 10)
                            {
                                printf("(ID 1050)\tPipetas antipulgas\tInyecciones en el hombro para quitar las pulgas\t\t%d\n\n", S[k][i]);
                            }
                            if (S[k][i] == S[5][i])
                            {
                                printf("Total\t\t\t\t\t\t\t\t\t\t\t\t%d\n\n\n", S[5][i]);
                            }
                        }
                    }
                }
            }
        }
    }
}