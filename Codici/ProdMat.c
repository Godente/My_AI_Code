#include <stdio.h>
#include <stdlib.h>

// ipotizziamo che le matrici in ingresso siano delle dimensioni giuste
void prod_matrice(double *matrice1, size_t righe1, size_t colonne1, double *matrice2, size_t colonne2, double *matrice3)
{
    for (size_t i = 0; i < righe1; i++)
    {
        for (size_t j = 0; j < colonne2; j++)
        {
            matrice3[ i * colonne2 + j] = 0;
            for (size_t k = 0; k < colonne1; k++)
            {
                matrice3[i * colonne2 + j] += matrice1[i * colonne1 + k] * matrice2[k * colonne2 + j];
            }

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
    //effettuiamo il prodotto tra due matrici identiche
    int righe = 3;
    int colonne = 4;
    // essendo allocazione dinamica posso evitare il define
    // malloc preassegna locazioni di memoria per questo ci si riferisce con un puntatore 
    double *M1 = (double *) malloc(righe * colonne * sizeof(double));
    for(size_t i = 0; i < righe * colonne; i++)
    {
        M1[i] = i;
    }
    if (M1 == NULL) 
    {
        return -1;
    }
    stampa_matrice(M1, righe, colonne);
    printf("\n");

    double *M2 = (double *) malloc (colonne * righe * sizeof (double));
    for(size_t i = 0; i < righe * colonne; i++)
    {
        M2[i]= i;
    }
    if (M2 == NULL)
    {
        return -1;
    }
    stampa_matrice(M2, colonne, righe);
    printf("\n");

    double *M3 = (double *) malloc (colonne * righe * sizeof (double));
    /*for(size_t i = 0; i < righe * colonne; i++)
    {
        M3[i]= i;
    }
    if (M3 == NULL)
    {
        return -1;
    } */
    stampa_matrice(M3, colonne, righe);
    printf("\n");
    

    prod_matrice(M1, righe, colonne, M2, righe, M3);
    stampa_matrice(M3, colonne, righe);

    return 0;
}