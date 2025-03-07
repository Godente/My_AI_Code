#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RIGHE 3
#define COLONNE 3
#include "inversa.h"


//dovrò fare questo 
//[X^T * X]^-1 * X^T * Y = [a]

//all'inizio devo riempire gli array di dati dove fare il fitting

//creo la matrice di Vandermonde, ovvero la matrice con 1, x, x^2, poi la seconda rica 1, x, x^2 etc
//prendo come imput la matrice holder e i valori di x
void matrice_vamdermondiana(double *mat, size_t righe, size_t colonne, double *valorix)
/*
{
    for (size_t i = 0; i < righe; i++)
    {
        for (size_t j = 0; j < colonne; j++)
        {
            mat[i * colonne + j] = exp(valorix[i], j); //prendo i valori di x e li elevo al numero di colonna ovvero j
            //è però computing intensive!!
        }
    }
}
*/
//per risparmiare calcoli, posso direttamente aggiungere l'1 come primo elemento, non posso fare la stessa con con il secondo 
//elemento perchè se devo approssimare una funzione costante con un solo elemento, io poi vado ad imporre che c'è anche x
//anche se in realtà non c'è 

{
    for (size_t i = 0; i < righe; i++)
    {
        mat[i * colonne] = 1; //aggiungo l'1 come primo elemento
        for (size_t j = 0; j < colonne; j++)
        {
            mat[i * colonne + j] = pow(valorix[i], j); //prendo i valori di x e li elevo al numero di colonna ovvero j
            //è però computing intensive!!
        }
    }
}

void main  ()
{
    double *matrice = (double *) malloc(RIGHE * COLONNE * sizeof(double));
    double *matrice2 = (double *) malloc(RIGHE * COLONNE * sizeof(double));
    double *valorix = (double *) malloc(RIGHE * sizeof(double));
    double *matrice_vandermondiana = (double *) malloc(RIGHE * COLONNE * sizeof(double));
    for (size_t i = 0; i < RIGHE; i++)
    {
        valorix[i] = i;//dopo skippalo
    }
    //per generalizzare, guarda bene righe e colonne
    matrice_vamdermondiana(matrice_vandermondiana, RIGHE, COLONNE, valorix);
    stampa_matrice(matrice_vandermondiana, RIGHE, COLONNE);
    matrice_trasposta(matrice_vandermondiana, RIGHE, COLONNE, matrice);
    prodotto_matrice(matrice, RIGHE, COLONNE, matrice_vandermondiana, COLONNE, matrice2);
    gauss_inversion(matrice2, RIGHE, COLONNE, matrice);
    prodotto_matrice(matrice, RIGHE, COLONNE, matrice_trasposta, COLONNE, matrice);
    //definisco Y come un array di valori che seguono la funzione x^2
    double *Y = (double *) malloc(RIGHE * sizeof(double));
    for (size_t i = 0; i < RIGHE; i++)
    {
        Y[i] = valorix[i] * valorix[i];
    }
    prodotto_matrice(matrice, RIGHE, COLONNE, Y, 1, matrice2);
    //ora matrice2 contiene i coefficienti del polinomio
    //stampo l'array
    for (size_t i = 0; i < RIGHE; i++)
    {
        printf("%lf ", matrice2[i]);
    }
    free(matrice);
    free(valorix);
    free(matrice_vandermondiana);
}