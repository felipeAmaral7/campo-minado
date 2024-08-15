#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int eBomba;
    int estaAberta;
    int vizinhos;
}Celula;

Celula mapa [10][10];
int tam = 10;

void campoMinado();

void preencheMapa();

void preencheBomba(int numBombas);

int verificaCoordenada(int l, int c);

int bombaVizinho(int l, int c);

void contaBombas();

int fazerJogada();

int verificaEhBomba(int l, int c);

void acertouMapa(int l, int c);

void mapaBombas();

void imprimeMapa();

int main(void){

    campoMinado();

}

void campoMinado(){
    printf("SEJA BEM VINDO AO CAMPO MINADO!\n\n");

    srand(time(NULL));

    preencheMapa();
    preencheBomba(20);
    contaBombas();
    
    int continuaJogo = 1;
    while(continuaJogo){
        imprimeMapa();
        printf("\n\n\n");
        //mapaDeBombas();
        continuaJogo = fazerJogada();
    }
}

void preencheMapa(){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            mapa[i][j].eBomba = 0;
            mapa[i][j].estaAberta = 0;
            mapa[i][j].vizinhos = 0;
        }
    }
}

void preencheBomba(int tamBombas){
    int l, c = 0;
    
    for(int i = 0; i < tamBombas; i++){
        l = rand() % tam;
        c = rand() % tam;
        if (mapa[l][c].eBomba == 0){
            mapa[l][c].eBomba = 1;
        }
        else{
            i --;
        }
    }
}

int verificaCoordenada(int l, int c){
    int ehValida = 0;

    if(l >= 0 && l < tam && c >= 0 && c < tam){
        ehValida = 1;
    }
    else{
        ehValida = 0;
    }

    return ehValida;
}

int bombaVizinho(int l, int c){
    int quantBombas = 0;

    //verifica se os vizinhos estao em uma posicao valida e depois verifica se há bombas no vizinho requisitado
    if (verificaCoordenada(l, c + 1)){
        if (mapa[l][c + 1].eBomba == 1){
            quantBombas ++;
        }
    }
    if (verificaCoordenada(l, c - 1)){
        if (mapa[l][c - 1].eBomba == 1){
            quantBombas ++;
        }
    }
    if (verificaCoordenada(l - 1, c)){
        if (mapa[l - 1][c].eBomba == 1){
            quantBombas ++;
        }
    }
    if (verificaCoordenada(l + 1, c)){
        if (mapa[l + 1][c].eBomba == 1){
            quantBombas ++;
        }
    }

    return quantBombas;
}

void contaBombas(){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            mapa[i][j].vizinhos = bombaVizinho(i, j);
        }
    }
}

int fazerJogada(){
    int continuaJogo = 1;
    int posL, posC;

    printf("Digite uma linha para colocar no campo minado:\n");
    do{
        scanf("%d%d", &posL, &posC);
        if(verificaCoordenada(posL, posC) == 0 || mapa[posL][posC].estaAberta == 1){
            printf("Digite uma posicao valida!\n");
        }
    }while(verificaCoordenada(posL, posC) == 0 || mapa[posL][posC].estaAberta == 1);

    if(verificaEhBomba(posL, posC)){
        printf("BOMBAAAA!!!\n");
        continuaJogo = 0;
    }
    else{
        acertouMapa(posL, posC);
    }

    return continuaJogo;
}

int verificaEhBomba(int l, int c){
    int temBomba = 0;
    if(mapa[l][c].eBomba){
        temBomba = 1;
    }

    return temBomba;
}

void acertouMapa(int l, int c){

    if(verificaCoordenada(l, c) && mapa[l][c].estaAberta == 0){
        mapa[l][c].estaAberta = 1;
        if(mapa[l][c].vizinhos == 0){
            acertouMapa(l, c + 1);
            acertouMapa(l, c - 1);
            acertouMapa(l + 1, c);
            acertouMapa(l - 1, c);
        }
    }
}

void imprimeMapa(){
    printf("   ");
    for(int i = 0; i < tam; i++){
        printf(" %d %c", i, '|');
    }
    printf("\n");
    printf("   ----------------------------------------\n");

    for(int i = 0; i < tam; i++){
        printf("%d%c ", i, '|');
        for(int j = 0; j < tam; j++){
            if(mapa[i][j].estaAberta){
                printf(" %d ", mapa[i][j].vizinhos);
            }
            else{
                printf("   ");
            }
            printf("|");
        }
        printf("\n   ----------------------------------------\n");
    }
}

void mapaDeBombas(){
    printf("   ");
    for(int i = 0; i < tam; i++){
        printf(" %d %c", i, '|');
    }
    printf("\n");
    printf("   ----------------------------------------\n");

    for(int i = 0; i < tam; i++){
        printf("%d%c ", i, '|');
        for(int j = 0; j < tam; j++){
            printf(" %d ", mapa[i][j].eBomba);
            printf("|");
        }
        printf("\n   ----------------------------------------\n");
    }
}