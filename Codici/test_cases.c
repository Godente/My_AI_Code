#include "matrix.h"

#define DEBUG 0

int test_add_array(){
    double array1[3] = {0, 1, 3};
    double array2[3] = {4, 5, 6};
    double holder[3];
    
    addizione(array1, 3, array2);
    
    #if DEBUG
    stampa_matrice(array1, 1, 3);
    stampa_matrice(array2, 1, 3);
    stampa_matrice(array1, 1, 3);
    #endif
}

int main () {

}