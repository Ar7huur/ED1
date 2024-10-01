#define MAXFILAFC 100

// Definição da estrutura TpBrinquedo
struct TpBrinquedo {
    char cep[9];      // CEP da casa
    int numCasa;      // Número da casa
    int numBrinq;     // Número do brinquedo
};

// Definição da estrutura TpFilaCirc
struct TpFilaCirc {
    int fim, inicio, cont;         // Controle do início, fim e contagem da fila
    TpBrinquedo b[MAXFILAFC];      // Array para armazenar os brinquedos
};

// Função para inicializar a fila circular
void inicializarFC(TpFilaCirc& f) {
    f.inicio = 0;
    f.fim = -1;
    f.cont = 0;
}

// Função para inserir um brinquedo na fila circular
void inserirBrinqFC(TpFilaCirc& f, TpBrinquedo elem) {
    if (f.fim == MAXFILAFC - 1) {
        f.fim = -1;  // Volta ao início se o fim atingir o tamanho máximo
    }
    f.b[++f.fim] = elem;  // Inserir o brinquedo na fila
    f.cont++;             // Incrementa o contador de elementos
}

// Função para remover um brinquedo da fila circular
TpBrinquedo retirarBrinqFC(TpFilaCirc& f) {
    TpBrinquedo aux = f.b[f.inicio++];  // Retira o brinquedo do início da fila

    if (f.inicio == MAXFILAFC) {
        f.inicio = 0;  // Volta ao início se o índice atingir o limite da fila
    }

    f.cont--;  // Decrementa o contador de elementos
    return aux;
}

// Função para verificar se a fila circular está vazia
int vaziaFC(int cont) {
    return cont == 0;
}

// Função para verificar se a fila circular está cheia
int cheiaFC(int cont) {
    return cont == MAXFILAFC;
}

// Função para exibir os brinquedos da fila circular
void exibeFCBrinquedo(TpFilaCirc f) {
    while (!vaziaFC(f.cont)) {
        TpBrinquedo b = retirarBrinqFC(f);  // Retira e exibe o brinquedo
        printf("%s %d %d\n", b.cep, b.numCasa, b.numBrinq);
    }
}
