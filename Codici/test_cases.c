#include "matrix.h"

#define DEBUG 0 //per compilare i comandi nel #if mettere 1

int test_add_array(){
    double array1[3] = {0, 1, 3};
    double array2[3] = {4, 5, 6};
    double output[3] = {4, 6, 9};
    double holder[3];

    for(size_t i = 0; i < 3; i++){
        holder[i] = array1[i];
    }
    
    addizione(array1, 3, array2);
    
    #if DEBUG
    printf("Test ADD \n");
    printf("array1\n");
    stampa_matrice(holder, 1, 3);
    printf("array2 \n");
    stampa_matrice(array2, 1, 3);
    printf("risultato \n");
    stampa_matrice(array1, 1, 3);
    printf("output desiderato \n");
    stampa_matrice(output, 1, 3);
    #endif

    for (size_t i = 0; i < 3; i++){
        if(array1[i] != output[i]){
            printf("sum is failed");
            return 1;
        }
    }

    return 0;
}

int test_sottrazione_array(){
    double array1[3] = {0, 1, 3};
    double array2[3] = {4, 5, 6};
    double output[3] = {-4, -4, -3};
    double holder[3];

    for(size_t i = 0; i < 3; i++){
        holder[i] = array1[i];
    }
    
    sottrazione(array1, 3, array2);
    
    #if DEBUG
    printf("\nTest Sub \n");
    printf("array1 \n");
    stampa_matrice(holder, 1, 3);
    printf("array2 \n");
    stampa_matrice(array2, 1, 3);
    printf("risultato \n");
    stampa_matrice(array1, 1, 3);
    printf("output desiderato \n");
    stampa_matrice(output, 1, 3);
    #endif

    for (size_t i = 0; i < 3; i++){
        if(array1[i] != output[i]){
            printf("subtraction is failed");
            return 1;
        }
    }

    return 0;
}

int test_prod_matrice(){
    double mat1[8] = {1,2,3,4,5,6,7,8};
    double mat2[8] = {8,7,6,5,4,3,2,1};
    double out[4] = {40,30,120,94};
    double holder[4];

    prod_matrice(mat1, 2, 4, mat2, 2, holder);
    
    #if DEBUG
    printf("Test product matrix \n");
    printf("matrix 1\n");
    stampa_matrice(mat1, 2, 4);
    printf("matrix 2 \n");
    stampa_matrice(mat2, 4, 2);
    printf("risultato \n");
    stampa_matrice(holder, 2, 2);
    printf("output desiderato \n");
    stampa_matrice(out, 2, 2);
    #endif

    for (size_t i = 0; i < 4; i++){
        if(holder[i] != out[i]){
            printf("product is failed");
            return 1;
        }
    }

    return 0;
}

int test_enhanced_matrice(){
    
    double mat1[9] = {9,8,7,6,5,4,3,2,1};
    double holder [18];
    double out[18] = {9,8,7,1,0,0,6,5,4,0,1,0,3,2,1,0,0,1};

    enhanced_matrix(mat1, 3, 3, holder);
    
    #if DEBUG
    printf("\nTest product matrix \n");
    printf("\nmatrix 1\n");
    stampa_matrice(mat1, 3, 3);
    printf("\nrisultato \n");
    stampa_matrice(holder, 3, 6);
    printf("\noutput desiderato \n");
    stampa_matrice(out, 3, 6);
    #endif

    for(size_t i=0; i < 18; i++){
        if(holder[i] != out[i]){
            printf("Enhancing fails");
            return 1;
        }
    }

    return 0;
}

/*----MAIN----*/
 
int main () {
//test_add_array();
//test_sottrazione_array();
//test_prod_matrice();
test_enhanced_matrice();
return 0;
}