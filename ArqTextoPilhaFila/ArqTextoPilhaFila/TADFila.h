#define MAXF 10

struct TpFila{
	int fim,fila[MAXF];
};

void inicializaF(TpFila &f){
	f.fim=-1;
}
void insereF(TpFila &f,int elem){
	f.fila[++f.fim]=elem;
}
int retiraF(TpFila &f){
	int aux;
	aux=f.fila[0];
	for(int i=0;i<f.fim;i++)	
		f.fila[i]=f.fila[i+1];
	f.fim--;
	return aux;	
}
int vaziaF(int fim){
	return fim==-1;
}
int cheiaF(int fim){
	return fim==MAXF-1;
}
void exibeFSemBarraN(TpFila f) {
	while (!vaziaF(f.fim))
		printf(" %d ", retiraF(f));
}


void exibeF(TpFila f){
	while(!vaziaF(f.fim))
		printf(" %d ",retiraF(f));
}
