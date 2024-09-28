#define MAXPILHA 10

struct TpPilhaPadraoChar
{
	int TOPO;
	char PILHA[MAXPILHA];
};

void inicializaPilhaTipoChar(TpPilhaPadraoChar& p)
{
	p.TOPO = -1;
}

void inserePilhaTipoChar(TpPilhaPadraoChar& p, char elem)
{
	p.PILHA[++p.TOPO] = elem;
}

char retiraPilhaTipoChar(TpPilhaPadraoChar& p)
{
	return p.PILHA[p.TOPO--];
}

char elementoTopoPilhaTipoChar(TpPilhaPadraoChar  p)
{
	return p.PILHA[p.TOPO];
}

int cheiaPilhaTipoChar(int topo)
{
	return topo == MAXPILHA - 1;
}

int vaziaPilhaTipoChar(int topo)
{
	return topo == -1;
}

void exibePilhaTipoChar(TpPilhaPadraoChar p) {
	while (!vazia(p.TOPO))
		printf("\n %c ", retiraPilhaTipoChar(p));
}

