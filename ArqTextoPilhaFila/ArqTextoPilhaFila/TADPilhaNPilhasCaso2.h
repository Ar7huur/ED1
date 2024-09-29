#define MAXPILHACASO2 10

struct TpPilhaM2
{
	int BASES[MAXPILHACASO2], TOPOS[MAXPILHACASO2];
	char PILHAS[MAXPILHACASO2];
};

void inicializarPM2(TpPilhaM2& PM, int quantidade)  //Obrigatório SEMPRE
{
	int i, quantElem = MAXPILHA / quantidade;
	for (i = 0; i <= quantidade; i++)
	{
		PM.BASES[i] = quantElem * i; PM.TOPOS[i] = PM.BASES[i] - 1;
	}
}

void inserirPM2(TpPilhaM2& PM, char Elem, int nPilha)
{
	PM.PILHAS[++PM.TOPOS[nPilha]] = Elem;
}

char retirarPM2(TpPilhaM2& PM, int nPilha)
{
	return PM.PILHAS[PM.TOPOS[nPilha]--];
}

char elementoTopoPM2(TpPilhaM2 PM, int nPilha)
{
	return PM.PILHAS[PM.TOPOS[nPilha]];
}

int cheiaPM2(TpPilhaM2 PM, int nPilha)
{
	return PM.TOPOS[nPilha] + 1 == PM.BASES[nPilha + 1];
}

int vaziaPM2(TpPilhaM2 PM, int nPilha)
{
	return PM.TOPOS[nPilha] < PM.BASES[nPilha];
}

void exibirPM2(TpPilhaM2 PM, int nPilha)
{
	while (!vaziaPM2(PM, nPilha))
		printf("\n%c", retirarPM2(PM, nPilha));
}


