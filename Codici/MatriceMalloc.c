#include <stdio.h>
#include <stdlib.h>

void stampa_matrice(double *matrice, size_t righe, size_t colonne)
{
    for (size_t i = 0; i < righe; i++)
    {
        for (size_t j = 0; j < colonne; j++)
        {
            printf("%f ", matrice[i * colonne + j]);
        }
        printf("\n");
    }
}

int main()
{
    int righe = 3;
    int colonne = 4;
    // essendo allocazione dinamica posso evitare il define
    // malloc preassegna locazioni di memoria per questo ci si riferisce con un puntatore 
    double *matrice = (double *) malloc(righe * colonne * sizeof(double));
    for(size_t i = 0; i < righe * colonne; i++)
    {
        matrice[i] = i;
    }
    if (matrice == NULL) 
    {
        return -1;
    }
    stampa_matrice(matrice, righe, colonne);
    return 0;
}