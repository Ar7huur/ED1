#define MAXFILAFC 100

// Defini��o da estrutura TpBrinquedo
struct TpBrinquedo {
    char cep[9];      // CEP da casa
    int numCasa;      // N�mero da casa
    int numBrinq;     // N�mero do brinquedo
};

// Defini��o da estrutura TpFilaCirc
struct TpFilaCirc {
    int fim, inicio, cont;         // Controle do in�cio, fim e contagem da fila
    TpBrinquedo b[MAXFILAFC];      // Array para armazenar os brinquedos
};

// Fun��o para inicializar a fila circular
void inicializarFC(TpFilaCirc& f) {
    f.inicio = 0;
    f.fim = -1;
    f.cont = 0;
}

// Fun��o para inserir um brinquedo na fila circular
void inserirBrinqFC(TpFilaCirc& f, TpBrinquedo elem) {
    if (f.fim == MAXFILAFC - 1) {
        f.fim = -1;  // Volta ao in�cio se o fim atingir o tamanho m�ximo
    }
    f.b[++f.fim] = elem;  // Inserir o brinquedo na fila
    f.cont++;             // Incrementa o contador de elementos
}

// Fun��o para remover um brinquedo da fila circular
TpBrinquedo retirarBrinqFC(TpFilaCirc& f) {
    TpBrinquedo aux = f.b[f.inicio++];  // Retira o brinquedo do in�cio da fila

    if (f.inicio == MAXFILAFC) {
        f.inicio = 0;  // Volta ao in�cio se o �ndice atingir o limite da fila
    }

    f.cont--;  // Decrementa o contador de elementos
    return aux;
}

// Fun��o para verificar se a fila circular est� vazia
int vaziaFC(int cont) {
    return cont == 0;
}

// Fun��o para verificar se a fila circular est� cheia
int cheiaFC(int cont) {
    return cont == MAXFILAFC;
}

// Fun��o para exibir os brinquedos da fila circular
void exibeFCBrinquedo(TpFilaCirc f) {
    while (!vaziaFC(f.cont)) {
        TpBrinquedo b = retirarBrinqFC(f);  // Retira e exibe o brinquedo
        printf("%s %d %d\n", b.cep, b.numCasa, b.numBrinq);
    }
}
