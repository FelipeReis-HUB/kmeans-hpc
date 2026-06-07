#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dataset.h"

void sequential_kmeans(int k, char*** dataset, int row_count){
    int dimensions = 0;
    char** clusters = NULL;

    while (dataset[1][dimensions] != NULL) {
        printf("[%s] ", dataset[1][dimensions]);
        dimensions++;
    }
    printf("\n");

    float** centroids = malloc(k * sizeof(float*));
    generate_centroids(k, dataset, centroids, dimensions, row_count);
    int converged = 0;//false

    for(int i = 0; i < k; i++) {
        printf("Centroide %d: ", i);
        for(int j = 0; j < dimensions; j++) {
            printf("%f ", centroids[i][j]);
        }
        printf("\n");
    }

    while(converged == 0){
        //adad
    }

    free_centroids(k, centroids);

}

int main(int argc, char *argv[]){

    srand(time(NULL));

    int row_count = 0;
    char*** dataset = read_csv("Iris.csv", &row_count, 1);

    if (dataset == NULL) {
        printf("Error at loading the dataset.\n");
        return 1;
    }

    sequential_kmeans(3, dataset, row_count);

    free_dataset(dataset, row_count);

    return 0;
}