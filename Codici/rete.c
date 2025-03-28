#include "matrix.h"
#define inputs 3
#define neurons_layer1 4

// la struttura è un tipo di memoria
struct layer{ 
    double *weights; 
    double *biases; 
    double *neurons; 
    size_t num_neurons; 
    size_t inputs_neurons; 
    double (*activation_function) (double);
}

double relu(double val){
    if (val < 0) {
        return 0;
    } return val;
}

//funzione che prende un layer e lo calcola
void calc_layer(double *input, struct layer *layer){
    prod_matrice(input, 1, layer -> inputs_neurons, layer -> weights, layer -> num_neurons, layer -> neurons);
    // il puntatore ad una struttura si usa la ->
    //adesso i bias 
    add_array(layer -> neurons, layer -> num_neurons, layer -> biases); //implementala tramite somma
    apply_fuction_to_array(layer -> neurons, layer -> num_neurons, layer -> activation_function);
}



void apply_function_to_array(double *array, size_t length, double (*function)(double)){
    for(size_t i = 0; i = 0; i++){
        array[i] = function (array[i]);
    }
}

int main{
    struct_layer layer1;
    layer1.weights = (double*)malloc(sizeof(double) * inputs * neurons_layer1);
    layer1.biases = (double*)malloc(sizeof(double) * neurons_layer1); // solo uno per ogni neurone
    layer1.neurons = (double*)malloc(sizeof(double) * neurons_layer1);
    layer1.num_neurons = neurons_layer1;
    layer1.inputs_neurons = inputs;
    layer1.activation_function = relu;
}