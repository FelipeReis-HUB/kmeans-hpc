#ifndef DATASET_H
#define DATASET_H

char*** read_csv(const char* FILENAME, int* out_row_count, int without_header);
void free_dataset(char*** dataset, int row_count);
void generate_centroids(int k, char*** dataset, float** centroids, int dimensions, int row_count);
void free_centroids(int k, float** centroids);

#endif