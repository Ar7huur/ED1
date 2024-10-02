#define MAXP 100

// Agora, a pilha armazena TpBrinquedo
struct TpPilhaBrinquedo {
    TpBrinquedo pilha[MAXP];
    int topo;
};

// Inicializa a pilha com topo em -1
void inicializaB(TpPilhaBrinquedo& P) {
    P.topo = -1;
}

// Insere um brinquedo na pilha
void insereB(TpPilhaBrinquedo& P, TpBrinquedo elem) {
    P.pilha[++P.topo] = elem;
}

// Remove e retorna um brinquedo da pilha
TpBrinquedo retiraB(TpPilhaBrinquedo& P) {
    return P.pilha[P.topo--];
}

// Verifica se a pilha está vazia
int vaziaB(int topo) {
    return topo == -1;
}

// Verifica se a pilha está cheia
int cheiaB(int topo) {
    return topo == MAXP - 1;
}

TpBrinquedo elemTopoB(TpPilhaBrinquedo P) {
    return P.pilha[P.topo];
}

void exibeBrinquedosOrdenados(TpPilhaBrinquedo P) {
    while (!vaziaB(P.topo)) {
        TpBrinquedo b = retiraB(P);  
        printf("%s %d %d\n", b.cep, b.numCasa, b.numBrinq);
    }
}
