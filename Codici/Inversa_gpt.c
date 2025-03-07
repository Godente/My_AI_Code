#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    printf("\n");
}

void swap_rows(double *mat, size_t riga1, size_t riga2, size_t colonne)
{
    double holder;
    for(size_t j = 0; j < colonne; j++)
    {
        holder = mat[riga1 * colonne + j];
        mat[riga1 * colonne + j] = mat[riga2 * colonne + j]; // correzione qui
        mat[riga2 * colonne + j] = holder;
    }
}

void multiply_array(double *array, size_t L, double val)
{
    for(size_t i = 0; i < L; i++)
    {
        array[i] *= val;
    }
}

void enchaced_matrix(double *mat, size_t righe, size_t col, double* enanched_mat)
{
    for(size_t i = 0; i < righe; i++)
    {
        for(size_t j = 0; j < col; j++)
        {
            enanched_mat[i * col + j] = mat[i * col + j];
            enanched_mat[i * col * 2 + j] = (double)(i == j); // per evitare if/else
        }
    }
}

void sottrazione(double *array1, size_t L, double *array2)
{
    for(size_t i = 0; i < L; i++)
    {
        array1[i] -= array2[i]; // sottrazione
    }
}

void clona_array(double* src, double* dest, size_t L)
{
    for(size_t i = 0; i < L; i++)
    {
        dest[i] = src[i];
    }
}

void gauss_inversion(double *mat, size_t riga, size_t col, double *i_mat)
{
    double *e_mat = (double *)malloc(riga * col * 2 * sizeof(double));
    double *row_copy = (double*)malloc(col * 2 * sizeof(double));

    enchaced_matrix(mat, riga, col, e_mat);

    for(size_t i = 0; i < riga; i++)
    {
        double best_val = e_mat[i * 2 * col + i];
        size_t best_row = i;

        for(size_t j = i + 1; j < riga; j++) // Correzione del ciclo interno
        {
            if (fabs(e_mat[j * 2 * col + i]) > fabs(best_val))
            {
                best_val = e_mat[j * 2 * col + i];
                best_row = j;
            }
        }

        swap_rows(e_mat, i, best_row, 2 * col);
        multiply_array(&e_mat[i * 2 * col + i], 2 * col, 1.0 / best_val); // Dividi la riga per best_val

        for(size_t k = 0; k < riga; k++)
        {
            if (k == i) { continue; }

            clona_array(&e_mat[i * 2 * col], row_copy, 2 * col); // Copia la riga
            multiply_array(row_copy, 2 * col, e_mat[k * 2 * col + i]); // Moltiplica la riga per il coefficiente

            sottrazione(&e_mat[k * 2 * col], 2 * col, row_copy); // Sottrai la riga da quella corrente
        }
    }

    for(size_t i = 0; i < riga; i++)
    {
        for(size_t j = 0; j < col; j++)
        {
            i_mat[i * col + j] = e_mat[i * 2 * col + j]; // Copia la matrice inversa
        }
    }

    free(e_mat); // Liberazione della memoria
    free(row_copy);
}

int main()
{
    size_t riga = 3, col = 3;
    double mat[9] = { 2, 1, 3, 4, 1, 6, 3, 2, 5};
    double i_mat[9];

    stampa_matrice(mat, riga, col);
    gauss_inversion(mat, riga, col, i_mat);

    printf("Matrice Inversa:\n");
    for(size_t i = 0; i < riga; i++)
    {
        for(size_t j = 0; j < col; j++)
        {
            printf("%f ", i_mat[i * col + j]);
        }
        printf("\n");
    }

    return 0;
}