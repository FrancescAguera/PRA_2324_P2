#include <limits>
#include <ostream>
#include <algorithm>

int infinito = std::numeric_limits<int>::max();

int* cambio (int N, int* v, int M) {
    int** matrix = new int*[N];
    for(int i=0; i < N; i++){
        matrix[i] = new int[M+1];
        for (int j = 0; j <= M; j++) {
            if(!j){
                matrix[i][j] = 0;
            } else {
                matrix[i][j] = -1;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 1; j < M+1; j++) {
            if (i == 0 && v[i] > j) {
                matrix[i][j] = infinito;
            } else if (i == 0) {
                matrix[i][j] = 1+matrix[i][j-v[i]];
            } else if(v[i] > j) {
                matrix[i][j] = matrix[i-1][j];
            } else {
                matrix[i][j] = std::min(matrix[i-1][j], 1 + matrix[i][j - v[i]]);
            } printf ("%d  ", matrix[i][j]);
        } printf("\n");
    }
    int i = N - 1;
    int j = M;
    int* x = new int[N];
    while ( i >= 0 && j >= 0) {
        if(matrix[i][j] == 1 + matrix[i][j-v[i]]) {
            x[i] = x[i] + 1;
            j = j- v[i];
        } else {
            i--;
        }
    }

    return x;
}

int main(){

    int v[] = {1, 4, 6};
    int N = 3;
    int M = 8;
    int* valor = cambio(N, v, M);
    printf("Vector solución: ");
    for (int i = 0; i < 3; i++) {
        printf("%d, ", valor[i]);
    }
    printf("\n");
    return 0;
}
