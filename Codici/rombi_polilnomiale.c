#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void matrix_product(double *m1, size_t r1, size_t c1, double *m2, size_t c2, double *m3)
{
    for(size_t i = 0; i < r1 ; i++) {
        for(size_t j = 0; j < c2 ; j++) {
            m3[i*c2 + j] = 0;
            for(size_t k = 0; k < c1; k++) {
                m3[i*c2 + j] += m1[i*c1 + k] * m2[k*c2 + j];
            }    
        }
    }
}

void matrix_transpose(double *m1, size_t r1, size_t c1, double *m2)
{
    for (size_t i = 0; i < c1; i++) {
        for(size_t j = 0; j < r1; j++){
            m2[i*r1 + j] = m1[j*c1 + i];
        }
    }
}

void multiply_array (double *arr, size_t l, double val)
{
    for (size_t j = 0; j < l; j++)
    {
        arr[j] *= val;
    }
}


void matrix_print(double *m, size_t r, size_t c)
{
    for (size_t i = 0; i < r ; i++) {
        for (size_t j = 0; j < c; j++) {
            printf("%f ", m[i * c + j]);
        }
        printf("\n");
    }    
    printf("\n\n");
}

void create_matrix(double *m, size_t r, size_t c)
{
    for(size_t i = 0; i < r*c; i++)
    {
        m[i] = i;
    }
    printf("\n\n");
}

void hadamard_product(double *m1, size_t r, size_t c, double *m2, double *m3)
{
    for(size_t i = 0; i < r*c; i++)
    {
        m3[i] = m1[i] * m2[i];
    }
}

void vandermonde_matrix(double *mat, size_t r, size_t c, double *val)
{
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            mat[i*c +j] = pow(val[i],j);
        }
    }
}

void swap_rows (double *mat, size_t r1, size_t r2, size_t c)
{
    double holder;
    for (size_t j = 0; j < c; j++)
    {
        holder = mat[r1*c + j];
        mat[r1*c + j] = mat[r2*c +j];
        mat[r2*c + j] = holder;
    }
}

void substract_array (double *arr1, size_t l, double *arr2)
{
    for (size_t j = 0; j < l; j++)
    {
        arr1[j] -= arr2[j];
    }
}

void clone_array (double *arr1, size_t l, double *arr2) 
{
    for (size_t j = 0; j < l; j++)
    {
        arr2[j] = arr1[j];
    }
}

void enhanced_matrix (double *mat, size_t r, size_t c, double *e_mat)
{
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            e_mat[i*2*c + j] = mat[i*c + j];
            e_mat[i*2*c + c + j] = (double)( i == j) ;
        }
    }
}

void gauss_inversion (double *mat, size_t r, double *i_mat)
{
    double *e_mat = (double*)malloc(r*2*r*sizeof(double));
    double *row_copy = (double*)malloc(2*r*sizeof(double));
    enhanced_matrix(mat, r, r, e_mat);
    for (size_t i = 0; i < r; i++)
    {
        // inizializzare il best val su ciascun valore della diagonale principale della matrice da invertire
        double best_val = e_mat[i*2*r + i];
        size_t best_row = i;
        for ( size_t j = i + 1; j < r; j++)
        {
            if (fabs(e_mat[j*2*r + i]) > fabs(best_val))
            {
                best_val = e_mat[j*2*r + i];
                best_row = j;
            }
        }

        
        swap_rows(e_mat, best_row, i, 2*r);
        multiply_array(&e_mat[i*2*r + i], 2*r - i, 1/best_val);
        for (size_t k = 0; k < r; k++)
        {
            if (k == i) continue;
        
        clone_array(&e_mat[i*2*r], 2*r, row_copy);
        multiply_array(row_copy, 2*r, e_mat[k*2*r + i]);
        substract_array(&e_mat[k*2*r], 2*r, row_copy);
        }
    }
    for (size_t i = 0; i < r; i++)
    {
        for(size_t j = 0; j<r; j++)
        {
            i_mat[i*r+j] = e_mat[i*2*r + r + j];
        }
    }
    free(e_mat);
    free(row_copy);
}


int main ()
{
    double arr_x[5] = {1, 2, 3, 4, 5};
    double arr_y[5] = {1.5, 2, 1.5, 0, -2.5};
    size_t l = 5;
    size_t l_a = 4;
    double *arr_a = (double*)malloc(l_a*sizeof(double));
    double *mx_van = (double*)malloc(l*l_a*sizeof(double));
    double *mx_van_t = (double*)malloc(l*l_a*sizeof(double));
    double *mx_van_t1 = (double*)malloc(l*l_a*sizeof(double));
    double *i_mxmxt = (double*)malloc(l*l*sizeof(double)); 
    double *mxmxt = (double*)malloc(l*l*sizeof(double)); 
    

    vandermonde_matrix(mx_van, l, l_a, arr_x);
    matrix_print(mx_van, l, l_a);

    matrix_transpose(mx_van, l, l_a, mx_van_t);
    matrix_print(mx_van_t, l_a, l);

    matrix_product(mx_van_t, l_a, l, mx_van, l_a, mxmxt);
    matrix_print(mxmxt, l_a, l_a);
    

    gauss_inversion(mxmxt, l_a, i_mxmxt);
    matrix_print(i_mxmxt, l_a, l_a);

    matrix_product(i_mxmxt, l_a, l_a, mx_van_t, l, mx_van_t1);
    matrix_print(mx_van_t1, l_a, l);

    matrix_product(mx_van_t1, l_a, l, arr_y, 1, arr_a);

    matrix_print(arr_a, l_a, 1);
    return 0;

}