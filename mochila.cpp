#include <ostream>
#include <algorithm>

int* backpack (int N, int M, int *v, int *p) {
    int** matrix = new int*[N+1];
    for (int i = 0; i <= N; i++ ) {
        matrix[i] = new int[M+1];
        for (int j = 0; j <= M; j++) {
            if(i == 0) {
                matrix[i][j] = 0;
            } else if (j == 0) {
                matrix[i][j] = 0;
            } else if (i == 1 && p[0] > j){
                matrix[i][j] = 0;
            } else if (i == 1) {
                matrix[i][j] = v[0];
            } else if (p[i] > j) {
                matrix[i][j] = matrix[i-1][j];
            } else {
                matrix[i][j] = std::max(matrix[i-1][j], v[i-1] + matrix[i-1][j-p[i-1]]);
            }

        }

    }
    /// comprobacion
    for (int i = 0; i <= N; i++ ) {
        for (int j = 0; j <= M; j++) {
            printf ("%d   ", matrix[i][j]);
        }
        printf("\n");
    }

    int i = N;
    int j = M;
    int* x = new int[N];

    while ( i > 0 && j > 0) {
        if (i == 1 && matrix[i][j] == v[0]) {
            x[i] = 1;
        } else if (matrix[i][j] == (v[i-1] + matrix[i-1][j-p[i-1]])) {
            x[i] = 1;
            j -= p[i-1];
        }
        i--;
    }
    return x;

}
int main () {
    int v[3] = {38, 40, 24};
    int p[3] = {9, 6, 5};
    int* valor = backpack(3,15, v, p);
    printf("Vector solución: ");
    for (int i = 0; i < 3; i++) {
        printf("%d, ", valor[i]);
    }
    printf("\n");
}