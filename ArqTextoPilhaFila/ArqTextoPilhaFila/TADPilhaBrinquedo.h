#define MAXPB 100


struct TpPilhaBrinquedo {
    TpBrinquedo pilhaBrinquedo[MAXPB];  // Pilha para armazenar brinquedos
    char pilhaChar[MAXPB];              // Pilha para armazenar caracteres
    int topoBrinquedo;                 // Topo da pilha de brinquedos
    int topoChar;                      // Topo da pilha de caracteres
};

// Inicializa a pilha com topo em -1 para ambas as pilhas
void inicializaB(TpPilhaBrinquedo& P) {
    P.topoBrinquedo = -1;
    P.topoChar = -1;
}

// Insere um caractere na pilha de caracteres
void insereB(TpPilhaBrinquedo& P, char elem) {
    P.pilhaChar[++P.topoChar] = elem;
}

// Remove e retorna um caractere da pilha de caracteres
char retiraB(TpPilhaBrinquedo& P) {
    return P.pilhaChar[P.topoChar--];
}

// Insere um brinquedo na pilha de brinquedos
void insereBrinquedo(TpPilhaBrinquedo& P, TpBrinquedo elem) {
    P.pilhaBrinquedo[++P.topoBrinquedo] = elem;
}

// Remove e retorna um brinquedo da pilha de brinquedos
TpBrinquedo retiraBrinquedo(TpPilhaBrinquedo& P) {
    return P.pilhaBrinquedo[P.topoBrinquedo--];
}

// Verifica se a pilha de brinquedos está vazia
int vaziaBrinquedo(int topo) {
    return topo == -1;
}

// Verifica se a pilha de caracteres está vazia
int vaziaChar(int topo) {
    return topo == -1;
}

// Verifica se a pilha de brinquedos está cheia
int cheiaBrinquedo(int topo) {
    return topo == MAXPB - 1;
}

// Verifica se a pilha de caracteres está cheia
int cheiaChar(int topo) {
    return topo == MAXPB - 1;
}

// Retorna o elemento no topo da pilha de brinquedos sem removê-lo
TpBrinquedo elemTopoBrinquedo(TpPilhaBrinquedo P) {
    return P.pilhaBrinquedo[P.topoBrinquedo];
}

// Retorna o elemento no topo da pilha de caracteres sem removê-lo
char elemTopoChar(TpPilhaBrinquedo P) {
    return P.pilhaChar[P.topoChar];
}

// Exibe todos os caracteres da pilha
void exibeChar(TpPilhaBrinquedo P) {
    while (!vaziaChar(P.topoChar))
        printf("\n %c ", retiraB(P));  // Exibir cada caractere
}

// Exibe todos os brinquedos da pilha
void exibeBrinquedo(TpPilhaBrinquedo P) {
    while (!vaziaBrinquedo(P.topoBrinquedo)) {
        TpBrinquedo b = retiraBrinquedo(P);
        printf("%s, %d, %d\n", b.cep, b.numCasa, b.numBrinq);
    }
}
