#include "matrix.h"

void stampa_matrice(double *matrix, size_t righe, size_t colonne)
{
    for (size_t i = 0; i < righe; i++)
    {
        for (size_t j = 0; j < colonne; j++)
        {
            printf("%f ", matrix[i * colonne + j]);
        }
        printf("\n");
    }
}

void trasposta (double *matrix1, size_t righe1, size_t colonne1, double *holder)
{
    for(size_t i = 0; i < colonne1; i++)
    {
        for(size_t j = 0; j < righe1; j++)
        {
            holder[i * righe1 + j] = matrix1[j * colonne1 + i];
        }
    }
}

void swap_rows(double *matrix, size_t riga1, size_t riga2, size_t colonne)
{
    double holder;
    for (size_t j = 0; j < colonne; j++)
    {
        holder = matrix[riga1 * colonne + j];
        matrix[riga1 * colonne + j] = matrix[riga2 * colonne + j];
        matrix[riga2 * colonne + j] = holder;
    }
}

void multiply_array(double *array, size_t L, double scalar)
{
    for (size_t i = 0; i < L; i++)
    {
        array[i] *= scalar;
    }
}

void enhanced_matrix(double *matrix, size_t righe, size_t col, double *enhanced_matrix)
{
    for (size_t i = 0; i < righe; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            enhanced_matrix[i * 2 * col + j] = matrix[i * col + j]; // Parte sinistra: matrice originale
            enhanced_matrix[i * 2 * col + col + j] = (i == j) ? 1.0 : 0.0; // Parte destra: matrice identità
                                              //condizione ? valore_se_vero : valore_se_falso
        }
    }
}

void sottrazione(double *array1, size_t length, double *array2)
{
    for (size_t i = 0; i < length; i++)
    {
        array1[i] -= array2[i];
    }
}

void addizione(double *array1, size_t length, double *array2)
{
    for (size_t i = 0; i < length; i++)
    {
        array1[i] += array2[i];
    }
}

void clona_array(double *source, double *dest, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        dest[i] = source[i];
    }
}

int gauss_inversion(double *matrix, size_t riga, size_t col, double *inv_matrix)
{
    double *e_mat = (double *)malloc(riga * 2 * col * sizeof(double));
    double *row_copy = (double *)malloc(2 * col * sizeof(double));

    enhanced_matrix(matrix, riga, col, e_mat);

    for (size_t i = 0; i < riga; i++)
    {
        double best_val = e_mat[i * 2 * col + i];
        size_t best_row = i;

        // Trova la riga con il valore massimo nella colonna corrente
        for (size_t j = i + 1; j < riga; j++)
        {
            if (fabs(e_mat[j * 2 * col + i]) > fabs(best_val))
            {
                best_val = e_mat[j * 2 * col + i];
                best_row = j;
            }
        }

        // Se il valore massimo è zero, la matrice non è invertibile
        if (fabs(best_val) < 1e-10)
        {
            free(e_mat);
            free(row_copy);
            return 0; // Matrice non invertibile
        }

        swap_rows(e_mat, i, best_row, 2 * col);

        // Normalizza la riga corrente
        multiply_array(&e_mat[i * 2 * col], 2 * col, 1.0 / e_mat[i * 2 * col + i]);

        // Sottrai la riga corrente dalle altre righe
        for (size_t k = 0; k < riga; k++)
        {
            if (k == i) continue;

            clona_array(&e_mat[i * 2 * col], row_copy, 2 * col);
            multiply_array(row_copy, 2 * col, e_mat[k * 2 * col + i]);
            sottrazione(&e_mat[k * 2 * col], 2 * col, row_copy);
        }
    }

    // Copia la parte destra della matrice aumentata (matrice inversa)
    for (size_t i = 0; i < riga; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            inv_matrix[i * col + j] = e_mat[i * 2 * col + col + j];
        }
    }
    //quando si lavora con i malloc bisogna ricordarsi di liberare la memoria
    free(e_mat);
    free(row_copy);
    return 0; // Successo
}

void prod_matrice(double *matrice1, size_t righe1, size_t colonne1, double *matrice2, size_t colonne2, double *holder)
{
    for (size_t i = 0; i < righe1; i++)
    {
        for (size_t j = 0; j < colonne2; j++)
        {
            holder[ i * colonne2 + j] = 0;
            for (size_t k = 0; k < colonne1; k++)
            {
                holder[i * colonne2 + j] += matrice1[i * colonne1 + k] * matrice2[k * colonne2 + j];
            }

        }
    }
}

void matrice_vandermon (double *matrix, size_t righe, size_t col, double *x)
{
    for(size_t i = 0; i < righe; i++)
    {
        for(size_t j = 0; j < col; j++)
        {
            matrix[i * col + j] = pow(x[i], j); // = x[i]^j
        }
    }
}

void coefficent (double *x, size_t row, size_t col, double *y, double *risultato)
{
    double *vander_mat = (double*)malloc(row * col * sizeof(double));
    double *holder = (double*)malloc(row * col * sizeof(double));
    double *vander_trasposta = (double*)malloc(row * col * sizeof(double));
    double *denominatore = (double*)malloc(col * col * sizeof(double));
    double *numeratore = (double*)malloc(col * sizeof(double));
    
    matrice_vandermon(vander_mat, row, col, x);
    trasposta(vander_mat, row, col, vander_trasposta);
    prod_matrice(vander_trasposta, col, row, vander_mat, col, holder);
    gauss_inversion(holder, col, col, denominatore);
    prod_matrice(vander_trasposta, col, row, y, 1, numeratore);
    prod_matrice(denominatore, col, col, numeratore, 1, risultato);
    // "Debug"
   #if DEBUG
    printf("vander matrix\n");
    stampa_matrice(vander_mat, row, col);
    printf("vander trasposta\n");
    stampa_matrice(vander_trasposta, col, row);
    printf("vander per\n");
    stampa_matrice(holder, col, col);
    printf("inversa della precendete\n");
    stampa_matrice(denominatore, col, col);
    printf("numeratore\n");
    stampa_matrice(numeratore, col, 1);
    #endif
    
    free(vander_mat);
    free(holder);
    free(vander_trasposta);
    free(denominatore);
    free(numeratore);
}