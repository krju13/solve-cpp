#include<iostream>
using namespace std;

typedef struct Vset {
    bool visited;
    int connets;
    int myconnets[20];
};

Vset vset[20];

int solveByRecusion(int mywhere, int dest, int deep, int Long);
int main() {
    //¿œ¥‹ ¿‘∑¬
    int test;
    FILE *fp = fopen("input1.txt", "r");
    fscanf(fp,"%d", &test);
    for (int m = 0; m < test; m++) {
        int V;
        fscanf(fp, "%d", &V);
        for (int i = 0; i < V; i++) {
            fscanf(fp, "%d", &vset[i].connets);
            for (int j = 0; j < vset[i].connets; j++) {
                fscanf(fp, "%d", &vset[i].myconnets[j]);
            }
        }
        int start, dest, Long;
        fscanf(fp, "%d", &start);
        fscanf(fp, "%d", &dest);
        fscanf(fp, "%d", &Long);


        //solve
        printf("%d\n",solveByRecusion(start, dest, 0, Long));

    }
    return 0;
}
int solveByRecusion(int mywhere,int dest,int deep,int Long) {
    //base case
    if (deep > Long) {
        return 0;
    }
    else if (mywhere == dest) {
        return 1;
    }
    if (vset[mywhere].visited == true) {
        return 0;
    }
    //solve
    int sum = 0;
    vset[mywhere].visited = true;
    for (int i = 0; i < vset[mywhere].connets; i++) {
        sum+=solveByRecusion(vset[mywhere].myconnets[i], dest, deep + 1, Long);
    }
    vset[mywhere].visited = false;
    return sum;
}
