#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int formula(int x, int y) {
    return x + y*y + 2;
}

int main() {
    clock_t start, end;
    double total_time;

    start = clock();

    FILE *datafile = fopen("data.csv", "r");
    if (datafile == NULL) {
        printf("Error opening data file.\n");
        return 1;
    }

    char *Xs = (char*)malloc(sizeof(char) * 300000000);
    char *Ys = (char*)malloc(sizeof(char) * 300000000);
    fgets(Xs, 300000000, datafile);
    fgets(Ys, 300000000, datafile);

    fclose(datafile);

    int *X = (int*)malloc(sizeof(int) * 300000000);
    int *Y = (int*)malloc(sizeof(int) * 300000000);
    int *Z = (int*)malloc(sizeof(int) * 300000000);

    int i = 0;
    char *token = strtok(Xs, ",");
    while (token != NULL) {
        X[i++] = atoi(token);
        token = strtok(NULL, ",");
    }

    i = 0;
    token = strtok(Ys, ",");
    while (token != NULL) {
        Y[i++] = atoi(token);
        token = strtok(NULL, ",");
    }

    for (int j = 0; j < i; j++) {
        Z[j] = formula(X[j], Y[j]);
    }

    int total = 0;
    int limit = (i < 100) ? i : 100;
    for (int j = 0; j < limit; j++) {
        total += Z[j];
    }

    end = clock();
    total_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Total is %d and execution time is %f seconds\n", total, total_time);

    free(Xs);
    free(Ys);
    free(X);
    free(Y);
    free(Z);

    return 0;
}
