#include <cstdio>
#include <cstdlib>
#include <queue>
#include <limits>
#include <ctime>
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int** createG(int len) {
    int** G;
    srand(time(0));
    G = new int* [len];
    for (int i = 0; i < len; i++) {
        G[i] = new int[len];
    }
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (i == j) G[i][i] = 0;
            else {
                G[i][j] = rand() % 10;
                G[j][i] = G[i][j];
            }
        }
    }
    return G;
}

void printG(int** G, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void BFSDD(int** G, int size, int s, int* dist) {
    queue<int> Q;
    Q.push(s);
    dist[s] = 0;

    while (!Q.empty()) {
        s = Q.front();
        Q.pop();
        for (int i = 0; i < size; i++) {
            if (G[s][i] != 0 && dist[s] + G[s][i] < dist[i]) {
                dist[i] = dist[s] + G[s][i];
                Q.push(i);
            }
        }
    }
}

int main() {
    int** G = NULL;
    int s, size;
    setlocale(LC_ALL, "");
    printf("Введите размер графа: ");
    scanf("%d", &size);
    printf("\n");

    printf("Введите начальную вершину для поиска: ");
    scanf("%d", &s);

    G = createG(size);
    printG(G, size);

    int* dist = new int[size];
    for (int i = 0; i < size; i++) {
        dist[i] = INT_MAX;
    }

    BFSDD(G, size, s, dist);
    for (int i = 0; i < size; i++) {
        if (dist[i] == INT_MAX) {
            dist[i] = -1;
        }
        printf("Расстояние от вершины %d до вершины %d = %d\n", s, i, dist[i]);
    }
   
    return 0;
}
