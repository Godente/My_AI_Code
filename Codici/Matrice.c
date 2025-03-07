#define RIGHE 3
#define COLONNE 4
//#include <stdio.h>
#include "matrix.h"
/* void stampa_matrice(double *matrice, size_t righe, size_t colonne)
{
    for (size_t i = 0; i < righe; i++)
    {
        for (size_t j = 0; j < colonne; j++)
        {
            printf("%f ", matrice[i * colonne + j]);
        }
        printf("\n");
    }
}*/

int main()
{
    double matrice[RIGHE * COLONNE];
    for (size_t i = 0; i < RIGHE * COLONNE; i++)
    {
        matrice[i] = i;
    }
    stampa_matrice(matrice, RIGHE, COLONNE);
    return 0;
}