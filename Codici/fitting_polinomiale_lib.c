#include "lib/matrix.h"

int main()
{
 double x[5] = {1, 2, 3, 4, 5};
 double y[5] = {1.5, 2, 1.5, 0, -2.5};

 size_t ordine = 4;
 size_t dim_x = sizeof(x) / sizeof(x[0]);

 double *coefficenti = (double*)malloc(ordine * sizeof(double));

 coefficent(x, dim_x, ordine, y, coefficenti);
 stampa_matrice(coefficenti, ordine, 1);

 free(coefficenti);

return 0;
}
//gcc-14 fitting_polinomiale_copy.c lib/matrix.c -Ilib  -o fitting_polinomiale_copy 
//-I include la cartella degli headers, però sta volta l'ho specificata nel codice