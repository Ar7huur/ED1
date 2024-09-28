#define MAXPILHAPM1 10 

struct TpPilhaM
{
	int TOPO1, TOPO2;
	char PILHA[MAXPILHAPM1];
};

void inicializarPMA(TpPilhaM& PM)
{
	PM.TOPO1 = -1;
	PM.TOPO2 = MAXPILHAPM1;
}

void inserirPMA(TpPilhaM& PM, char Elem, int nPilha)
{
	if (nPilha == 1)
		PM.PILHA[++PM.TOPO1] = Elem;
	else
		PM.PILHA[--PM.TOPO2] = Elem;
}
char retirarPMA(TpPilhaM& PM, int nPilha)
{
	if (nPilha == 1)
		return PM.PILHA[PM.TOPO1--];
	else
		return PM.PILHA[PM.TOPO2++];
}
char elementoTopoPMA(TpPilhaM PM, int nPilha)
{
	if (nPilha == 1)
		return PM.PILHA[PM.TOPO1];
	else
		return PM.PILHA[PM.TOPO2];
}
int cheiaPMA(int topo1, int topo2) // Verifica se a Estrutura está Cheia! 
{
	return topo1 == topo2 - 1;
}
int vaziaPMA(int topo, int nPilha)
{
	if (nPilha == 1)
		return topo == -1;
	else
		return topo == MAXPILHAPM1;
}

void exibirPMA(TpPilhaM PM, int nPilha)
{
	if (nPilha == 1)
		while (!vaziaPMA(PM.TOPO1, nPilha))
			printf("\n%c", retirarPMA(PM, nPilha));
	else
		while (!vaziaPMA(PM.TOPO2, nPilha))
			printf("\n%c", retirarPMA(PM, nPilha));
}

void exibirPMASemBarraN(TpPilhaM PM, int nPilha)
{
	if (nPilha == 1)
		while (!vaziaPMA(PM.TOPO1, nPilha))
			printf(" %c ", retirarPMA(PM, nPilha));
	else
		while (!vaziaPMA(PM.TOPO2, nPilha))
			printf(" %c ", retirarPMA(PM, nPilha));
}



