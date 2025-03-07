#include <stdio.h>
#include <stdlib.h>

void trasposta (double *matrice1, size_t righe1, size_t colonne1, double *matrice2)
{
    for(size_t i = 0; i < colonne1; i++)
    {
        for(size_t j = 0; j < righe1; j++)
        {
            matrice2[i * righe1 + j] = matrice1[j * colonne1 + i];
        }
    }
}

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
    int righe = 4;
    int colonne = 5;

    double *M1 = (double *) malloc( righe * colonne * sizeof(double));
    for( size_t i = 0; i < righe * colonne; i++)
    {
        M1[i] = i;
    }
    if (M1 == NULL)
    {
        return -1;
    }
    stampa_matrice(M1, righe, colonne);
    printf("\n");

    double *M2 = (double *) malloc ( righe * colonne * sizeof(double));

    trasposta(M1, righe, colonne, M2);
    stampa_matrice(M2, colonne, righe);
    return 0;
}