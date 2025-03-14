//libreria statica

#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

void stampa_matrice(double *matrice, size_t righe, size_t colonne);
void trasposta(double *matrice1, size_t righe1, size_t colonne1, double *matrice2);
void swap_rows(double *mat, size_t riga1, size_t riga2, size_t colonne);
void multiply_array(double *array, size_t L, double val);
void enhanced_matrix(double *mat, size_t righe, size_t col, double *enhanced_mat);
void sottrazione(double *array1, size_t L, double *array2);
void clona_array(double *source, double *dest, size_t L);
void prod_matrice(double *matrice1, size_t righe1, size_t colonne1, double *matrice2, size_t colonne2, double *matrice3);
void matrice_vandermon (double *mat, size_t righe, size_t col, double *val);
void coefficent (double *x, size_t row, size_t col, double *y, double *risultato);
void addizione(double *array1, size_t L, double *array2);

#endif // MATRIX_H