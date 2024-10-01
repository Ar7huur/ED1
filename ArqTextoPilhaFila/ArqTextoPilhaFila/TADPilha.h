#define MAXP 100

struct TpPilha {

    char pilha[MAXP];  // Trocar de int para char
    int topo;
};

// Inicializa a pilha com topo em -1
void inicializa(TpPilha& P) {
    P.topo = -1;
}

// Insere um caractere na pilha
void insere(TpPilha& P, char elem) {
    P.pilha[++P.topo] = elem;
}

// Remove e retorna um caractere da pilha
char retira(TpPilha& P) {
    return P.pilha[P.topo--];
}

// Verifica se a pilha está vazia
int vazia(int topo) {
    return topo == -1;
}

// Verifica se a pilha está cheia
int cheia(int topo) {
    return topo == MAXP - 1;
}

// Retorna o elemento no topo da pilha sem removê-lo
char elemTopo(TpPilha P) {
    return P.pilha[P.topo];
}

// Exibe todos os elementos da pilha
void exibe(TpPilha P) {
    while (!vazia(P.topo))
        printf("\n %c ", retira(P));  // Modificar para exibir char
}
