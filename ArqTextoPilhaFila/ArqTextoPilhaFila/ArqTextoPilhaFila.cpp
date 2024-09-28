#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdio.h>
#define TF 7
#define TAML 100
#define TL 7
#include"TADPilha.h"
#include "TADPilhaPadraoChar.h"

#pragma region Arquivo Texto
void fecharArq(FILE* NomeArq1, FILE* NomeArq2) {

	fclose(NomeArq1);
	fclose(NomeArq2);
}

void ExibirMsg() {
	printf("\nFeito exercicio");
	_getch();

}

void ExibeArqCriado() {
	char arqNome[100];
	printf("\nAqui sera exibido qualquer arquivo criado pelos exercicios feitos e claro, tendo o mesmo criado\n");
	printf("Apos a exibicao do arquivo, aperte qualquer tecla para sair da mesma:");
	printf("\n\n");
	printf("\nForneca o nome do arquivo recem criado: ");
	fflush(stdin);
	scanf("%s", arqNome);

	system("cls");

	FILE* PtrArq = fopen(arqNome, "r");
	char linha[100];

	if (PtrArq == NULL) {
		printf("\nErro ao abrir o arquivo, verifique se o mesmo existe e/ou foi criado corretamente com seu devido nome.");
	}
	else {
		while (fgets(linha, sizeof(linha), PtrArq) != NULL) {
			printf("%s", linha);
		}
		fclose(PtrArq);

		printf("\n\nO Arquivo nomeado de [%s] foi listado com sucesso.", arqNome);
	}


	printf("\n\nPressione qualquer tecla para voltar ao menu...");
	_getch();
}

void Ex1(const char nomeArq[100]) {

	char chr;

	FILE* PtrArq = fopen(nomeArq, "r");

	if (PtrArq == NULL)
		printf("\nErro com o arquivo");
	else {

		chr = fgetc(PtrArq);
		FILE* PtrN = fopen("arqN.txt", "w");
		while (!feof(PtrArq)) {

			fputc(toupper(chr), PtrN);
			chr = fgetc(PtrArq);

		}
		fclose(PtrArq);
		fclose(PtrN);
	}
	printf("\nFeito exercicio 1");
	_getch();
	Sleep(1000);
}

void Ex1B(const char nomeArq[100]) {

	char chr[100];
	FILE* PtrArq = fopen(nomeArq, "r");

	if (PtrArq == NULL)
		printf("\nErro com o arquivo");
	else {

		FILE* PtrN = fopen("Ex1B.txt", "w");
		fgets(chr, 100, PtrArq);

		while (!feof(PtrArq)) {
			_strupr(chr);
			fputs(chr, PtrN);
			fgets(chr, 100, PtrArq);
		}

		fecharArq(PtrArq, PtrN);
	}
	ExibirMsg();

}

void Ex2(const char nomeArq[100]) {
	FILE* PtrArq = fopen(nomeArq, "r");
	char chr;

	int linha = 0, esp = 0, letras = 0;

	if (PtrArq == NULL)
		printf("\nErro com o arquivo");
	else {

		chr = fgetc(PtrArq);
		while (!feof(PtrArq)) {

			if (chr == 32)
				esp++;
			if (chr == 10)
				linha++;
			if (chr != 10 && chr != 32)
				letras++;
			chr = fgetc(PtrArq);
		}
		fclose(PtrArq);
	}
	printf("\nHa um total de: [%d] espacos [%d] linhas e [%d] letras", esp, linha, letras);
	ExibirMsg();
	Sleep(1000);



}

void Ex3(const char nomeArq[100], const char nomeArq2[100]) {

	FILE* PtrArq = fopen(nomeArq, "r");
	FILE* PtrN = fopen(nomeArq2, "r");

	char chr, chr2;
	int cont = 0, diferentes = 0;

	if (PtrArq == NULL || PtrN == NULL)
		printf("\nErro com um dos arquivos");
	else {

		chr = fgetc(PtrArq);
		chr2 = fgetc(PtrN);

		while (!feof(PtrArq) && !feof(PtrN)) {

			if (chr == chr2)
				cont++;
			else
				diferentes++;

			chr = fgetc(PtrArq);
			chr2 = fgetc(PtrN);
		}
	}

	if (diferentes > 0)
		printf("\nArquivos diferentes");
	else
		printf("\nArquivos iguais");

	fecharArq(PtrArq, PtrN);
	ExibirMsg();
	Sleep(1000);
}

void Ex4(const char nomeArq[100]) {

	FILE* PtrArq = fopen(nomeArq, "r");
	char chr;

	if (PtrArq == NULL)
		printf("\nErro com o arquivo");
	else {
		FILE* PtrN = fopen("Ex4.txt", "w");
		chr = fgetc(PtrArq);
		fputc(toupper(chr), PtrN);
		chr = fgetc(PtrArq);
		while (!feof(PtrArq)) {

			if (chr == 32 || chr == 10) {
				fputc(chr, PtrN);
				chr = fgetc(PtrArq);
				if (chr != -1)//evita gravar o lixo no arquivo texto
					fputc(toupper(chr), PtrN);
			}
			else
				fputc(chr, PtrN);
			chr = fgetc(PtrArq);

		}

		fecharArq(PtrArq, PtrN);
		ExibirMsg();
		Sleep(1000);
	}


}

void Ex5() {

	int numAposta[TF], codigoAposta = 0, qtdeCadastros = 6, j = 0;
	char data[12];

	FILE* PtrArq = fopen("Aposta.txt", "w");

	while (j < 2) {
		printf("\nQual o codigo da aposta ?: ");
		scanf("%d", &codigoAposta);
		fprintf(PtrArq, "%d", codigoAposta);
		fprintf(PtrArq, "\t");

		printf("\nQual a data da aposta ? [dd/mm/yyyy]: ");
		fflush(stdin);
		scanf("%s", &data);//uso scanf pq o gets não funciona no vstudio
		fprintf(PtrArq, "%s", data);
		fprintf(PtrArq, "\t");

		printf("\nForneca os 7 numeros apostados: ");

		for (int i = 0; i < 7; i++) {
			scanf("%d", &numAposta[i]);
			fprintf(PtrArq, "%d\t", numAposta[i]);
		}
		fprintf(PtrArq, "\n");
		j++;
	}

	fclose(PtrArq);
}

void Ex7(const char nomeArq[100]) {
	FILE* PtrArq = fopen(nomeArq, "r");
	char chr;

	if (PtrArq == NULL)
		printf("\nErro com o arquivo");
	else {

		FILE* PtrN = fopen("Ex7.txt", "w");
		chr = fgetc(PtrArq);

		while (!feof(PtrArq)) {

			fputc(chr + 2, PtrN);

			chr = fgetc(PtrArq);
		}

		fecharArq(PtrArq, PtrN);

	}
	ExibirMsg();
	Sleep(1500);
}

void Ex8(const char nomeArq[100]) {
	FILE* PtrArq = fopen(nomeArq, "r");
	char chr;

	if (PtrArq == NULL)
		printf("\nErro no arquivo");
	else {
		FILE* PtrN = fopen("Ex8Descriptografado.txt", "w");
		chr = fgetc(PtrArq);
		while (!feof(PtrArq)) {
			fputc(chr - 2, PtrN);
			chr = fgetc(PtrArq);
		}
		fecharArq(PtrArq, PtrN);
	}
	ExibirMsg();
	Sleep(1500);
}

void Ex9(const char nomeArq[100]) { //tem que arrumar
	FILE* PtrArq = fopen(nomeArq, "r");
	char chr;
	int vogs = 0;

	if (PtrArq == NULL)
		printf("\nErro com o arquivo");
	else {
		chr = fgetc(PtrArq);
		while (!feof(PtrArq)) {

			if (chr == 'A' || chr == 'a' || chr == 'E' || chr == 'e' || chr == 'I' || chr == 'i' || chr == 'O' || chr == 'o' || chr == 'U' || chr == 'u')
				vogs++;
			chr = fgetc(PtrArq);
		}
		fclose(PtrArq);
	}

	printf("\nHa um total de [%d] vogais", vogs);
	ExibirMsg();
	Sleep(1300);
}

void Ex10() {

	FILE* PtrArq = fopen("Arq10.txt", "w");
	int i, num = 0;

	for (i = 0; i < 10000; i++) {
		printf("\n%d", i);
		fprintf(PtrArq, "%d", i);
		fprintf(PtrArq, "\n");
	}
	printf("\nArthur");
	fprintf(PtrArq, "Arthur");
	fclose(PtrArq);
	Sleep(5000);//apertar enter varias vezes retorna ao menu
}

void Ex11(const char nomeArq[100]) {

	FILE* PtrArq = fopen(nomeArq, "r");
	int i = 0;
	char linha[100];

	if (PtrArq == NULL)
		printf("\nErro com o arquivo");
	else {

		fgets(linha, 100, PtrArq);

		while (!feof(PtrArq)) {
			printf("%d ", i);
			printf("%s", linha);
			i++;
			fgets(linha, 100, PtrArq);

		}

		fclose(PtrArq);
		ExibirMsg();
		Sleep(1300);

	}

}

void Ex12(const char nomeArq[100], char letra) {

	FILE* PtrArq = fopen(nomeArq, "r");
	char chr[100], chr2;
	int i = 0, j = 0, linhaAtual = -1, k = 0;

	if (PtrArq == NULL)
		printf("\nErro com o arquivo");
	else {

		fgets(chr, 100, PtrArq);

		while (!feof(PtrArq)) {

			for (int i = 0; i < strlen(chr); i++) {
				if (chr[i] == letra)
					j++;
			}

			if (j > k) {
				linhaAtual++;
				k = j;

			}

			fgets(chr, 100, PtrArq);
			j = 0;
		}
		printf("\nHouve um total de [%d] repeticoes da letra [%c] e essa repeticao ocorreu mais na linha [%d]", k, letra, linhaAtual);
	}

	fclose(PtrArq);
	ExibirMsg();


}

void Ex13(const char nomeArq[100], const char* palavra) {

	FILE* PtrArq = fopen(nomeArq, "r");
	char linha[100], chr;
	int i = 0, qtdeLinha = -1, plvra = 0, repLinha = 0;

	if (PtrArq == NULL)
		printf("\nErro com o arquivo");
	else {

		chr = fgetc(PtrArq);

		while (!feof(PtrArq)) {

			if (chr != 32 || chr == 10) {
				linha[i] = chr;
				i++;
			}

			else {

				if (strcmp(linha, palavra) == 0) {
					plvra++;
					i = 0;
					repLinha = qtdeLinha;
				}


			}
			chr = fgetc(PtrArq);
			if (chr == 10)
				qtdeLinha++;

		}

	}

	printf("\nA palavra [%s] se repete mais na posicao [%d] do arquivo.", palavra, repLinha);
	fclose(PtrArq);
	ExibirMsg();
	Sleep(1300);
}

void Ex14(const char nomeArq[100]) {
	FILE* PtrArq = fopen(nomeArq, "r");
	char chr;
	int vogs = 0;

	if (PtrArq == NULL)
		printf("\nErro com o arquivo\n");
	else {

		FILE* PtrN = fopen("Ex14.txt", "w");
		chr = fgetc(PtrArq);

		while (!feof(PtrArq)) {

			if (chr == 'A' || chr == 'a' || chr == 'E' || chr == 'e' || chr == 'I' || chr == 'i' || chr == 'O' || chr == 'o' || chr == 'U' || chr == 'u')
				fputc('@', PtrN);
			else
				fputc(chr, PtrN);

			chr = fgetc(PtrArq);

		}

		fecharArq(PtrArq, PtrN);
		ExibirMsg();
		Sleep(1300);

	}
}

void Ex15(const char nomeArq[100], char letra, char caractere) {
	FILE* PtrArq = fopen(nomeArq, "r");
	char chr;

	if (PtrArq == NULL)
		printf("\nErro com o arquivo");
	else {

		FILE* PtrN = fopen("Ex15.txt", "w");
		chr = fgetc(PtrArq);
		while (!feof(PtrArq)) {

			if (chr == letra)
				fputc(caractere, PtrN);
			else
				fputc(chr, PtrN);

			chr = fgetc(PtrArq);
		}

		fecharArq(PtrArq, PtrN);
		ExibirMsg();
	}
	_getch();
}

void Ex16(const char nomeArq[100]) {
	FILE* PtrArq = fopen(nomeArq, "r");
	char chr;
	int parent1 = 0, parent2 = 0;

	if (PtrArq == NULL)
		printf("\nErro com o arquivo");
	else {

		chr = fgetc(PtrArq);
		while (!feof(PtrArq)) {

			if (chr == ')')
				parent1++;
			if (chr == '(')
				parent2++;

			chr = fgetc(PtrArq);
		}

		fclose(PtrArq);
		ExibirMsg();
	}

	if (parent2 != parent1) {
		printf("\nHa um erro com o codigo, existe parentes diferentes.\n");
		printf("\nHa cerca de [%d )] e ha cerca de [%d (]", parent1, parent2);
	}
	else
		printf("\nO codigo esta correto em questao de abre e fecha parenteses");

	_getch();
}

void Ex22() {
	FILE* PtrArq = fopen("Ex22.txt", "w");

	char nome[15];
	int nota1 = 0, nota2 = 0, portcentagemFaltas = 0, media = 0;

	printf("Cadastro de notas de alunos: ");
	printf("\nNome aluno: ");
	fflush(stdin);
	gets_s(nome);
	fprintf(PtrArq, "%s \t", nome);

	while (strcmp(nome, "\0") != 0) {

		printf("Nota 1 do Aluno: ");
		scanf("%d", &nota1);
		fprintf(PtrArq, "%d \t", nota1);

		printf("Nota 2 do Aluno: ");
		scanf("%d", &nota2);
		fprintf(PtrArq, "%d \t", nota2);

		printf("Qtde de faltas: ");
		scanf("%d", &portcentagemFaltas);
		fprintf(PtrArq, "%d \t", portcentagemFaltas);

		media = (nota1 + nota2) / 2;

		printf("O Aluno [%s] teve uma media de: [%d]", nome, media);
		fprintf(PtrArq, "%d \t", media);
		fprintf(PtrArq, "\n");

		_getch();
		printf("\nNome aluno: ");
		fflush(stdin);
		gets_s(nome);
		fprintf(PtrArq, "%s \t", nome);

	}

	fclose(PtrArq);
	ExibirMsg();

	_getch();

}

void Ex23() {
	//validando a conta de aulas assistidas, aonde: faltas com 18, então houve 36 aulas sendo assim reprovado, faltas com 18 e 80 aulas, sendo assim, aprovado
	FILE* PtrArq = fopen("Ex22.txt", "r");
	char nome[100];
	int n1 = 0, n2 = 0, media = 0, freq = 0, qtdeAulas = 0;
	float calcFreq = 0;

	if (PtrArq == NULL)
		printf("\nErro com o arquivo");
	else {
		while (!feof(PtrArq)) {
			fscanf(PtrArq, "%s %d %d %d %d", &nome, &n1, &n2, &freq, &media);

			printf("\nQual foi a qtde de aulas no semestre ?: ");
			scanf("%d", &qtdeAulas);

			calcFreq = (qtdeAulas - freq);

			calcFreq = (calcFreq / qtdeAulas) * 100;

			printf("\n\n\nO Aluno [%s] teve uma media de [%d] e uma frequencia de [%.1f]%", nome, media, calcFreq);
			printf(" Sendo assim ele foi: ");

			if (media >= 6 && calcFreq >= 75)
				printf("\nAprovado");
			else
				printf("\nReprovado");

		}

	}
	fclose(PtrArq);
	ExibirMsg();
	_getch();


}

void Insere(char linha[TAML], int& i, FILE* PtrN) {
	fputs(linha, PtrN);
	for (int j = 0; j < strlen(linha); j++)
		printf("%c", linha[j]);
	i = 0;
	memset(linha, 0, TAML);
}

void Formatador(const char nomeArq[100]) {
	char linha[TAML], chr;
	int i = 0;

	FILE* PtrArq = fopen(nomeArq, "r");
	FILE* PtrN = fopen("ArqN.txt", "w");

	chr = fgetc(PtrArq);
	while (!feof(PtrArq)) {

		switch (chr) {

		case '@':
			chr = fgetc(PtrArq);
			while (chr != ' ' && i < TAML - 1) {
				linha[i] = chr;
				i++;
				chr = fgetc(PtrArq);
			}
			if (chr == ' ' && i < TAML - 1) {
				linha[i - 1] = ' ';
				i--;
			}
			if (i == TAML - 1) {
				Insere(linha, i, PtrN);
				printf("\nInseriu no @");
			}
			break;

		case '/':
			while (chr != 10)
				fputc('\n', PtrN);
			if (chr == 10)
				memset(linha, 0, TAML);
			break;

		case '#':
			chr = fgetc(PtrArq);
			while (chr != ' ' && i < TAML - 1) {
				linha[i]++;
				i++;
				chr = fgetc(PtrArq);
			}
			if (chr == ' ')
				fputc('\n', PtrN);
			if (i == TAML - 1) {
				Insere(linha, i, PtrN);
				printf("\nInseriu no #");
			}
			break;
		default:
			if (i == TAML - 1) {
				Insere(linha, i, PtrN);
				printf("Inseriu no default");
			}
			linha[i]++;
			i++;
			chr = fgetc(PtrArq);
		}
		
	}
	fclose(PtrArq);
	fclose(PtrN);


}
#pragma endregion

void pilha01() {
	TpPilha p1, p2,paux;
	int num = 0;
	inicializa(p1);
	inicializa(p2);
	inicializa(paux);


	for (int i = 0; i < MAXP / 2; i++) {
		printf("Forneca os valores da pilha 1: ");
		scanf("%d", &num);
		insere(p1, num);
	}
	for (int i = 0; i < MAXP / 2; i++) {
		printf("Forneca os valores da pilha 2: ");
		scanf("%d", &num);
		insere(p2, num);
	}

	while (!vazia(p2.topo))
		insere(paux, retira(p2));
	while (!vazia(paux.topo))
		insere(p1, retira(paux));

	exibe(p1);
	printf("\n_____");
	_getch();



}

void pilha02() {
	TpPilha p1, p2;
	int num = 0, elemRemove=0;
	inicializa(p1);
	inicializa(p2);

	for (int i = 0; i < MAXP; i++) {
		printf("\nPreencha a pilha: ");
		scanf("%d", &num);
		insere(p1, num);
	}

	printf("\nForneca o elemento que deseja remover: ");
	scanf("%d", &elemRemove);

	while (!vazia(p1.topo))
		insere(p2, retira(p1));

	while (!vazia(p2.topo)) {
		num = retira(p2);

		if (num != elemRemove)
			insere(p1, num);
	}
	printf("\nO elemento [%d] foi removido com sucesso, a pilha então ficou assim:\n",elemRemove);
	exibe(p1);
	_getch();


}

void pilha03() {
	TpPilha p1;
	char exp[20], aux;
	int num = 0, num2 = 0, resultado = 0;
	inicializa(p1);

	printf("\nForneca a expressao polonesa: ");
	fflush(stdin);
	gets_s(exp, 20);

	for (int i = 0; i < strlen(exp); i++) {
		aux = exp[i];

		if (isdigit(aux)) {
			
			insere(p1, aux - '0');
		}
		else if (aux == '*' || aux == '+' || aux == '-') {
			num = retira(p1); 
			num2 = retira(p1); 

			if (aux == '*') {
				resultado = num * num2;
			}
			else if (aux == '+') {
				resultado = num + num2;
			}
			else if (aux == '-') {
				resultado = num2 - num;
			}

			insere(p1, resultado); 
		}
	}

	resultado = retira(p1); // O resultado final está na pilha
	printf("\nResultado: %d\n", resultado);

	_getch();
}

void pilha05() {

	TpPilha p1,p2;
	int num[TL];
	inicializa(p1);
	inicializa(p2);

	for (int i = 0; i < TL; i++) {
		printf("\nForneca os dados do vetor: ");
		scanf("%d", &num[i]);
	}

	for (int j = 0; j < TL; j++)
		insere(p1, num[j]);

	while (!vazia(p1.topo))
		insere(p2, retira(p1));


	exibe(p2);
	_getch();


}

void pilha06(const char nomeArq[100]) {
	FILE* PtrArq = fopen(nomeArq, "r");
	char chr;
	TpPilha p1;
	inicializa(p1);


	if (PtrArq == NULL)
		printf("\nErro com o arquivo");
	else {

		FILE* PtrN = fopen("Ex6PilhaNew.txt", "w");

		chr = fgetc(PtrArq);
		while (!feof(PtrArq)) {
			if(chr != 32)
				insere(p1, chr-'0');
			chr = fgetc(PtrArq);
		}

		while (!vazia(p1.topo))
			fprintf(PtrN, " %d ", retira(p1));
		fecharArq(PtrArq, PtrN);
	}

	_getch();

}

void pilha07() {

	TpPilhaPadraoChar p1, p2;
	char frase[100],aux;
	int cont = 0, cont2 = 0;

	inicializaPilhaTipoChar(p1);
	inicializaPilhaTipoChar(p2);

	printf("\nForneca a frase: ");
	fflush(stdin);
	gets_s(frase);

	for (int i = 0; i < strlen(frase); i++)
		inserePilhaTipoChar(p1, frase[i]);

	for (int j = 0; j < strlen(frase); j++) {

		aux = retiraPilhaTipoChar(p1);

		if (aux == frase[j])
			cont++;
		else
			cont2++;
	}

	if (cont2 > 0)
		printf("\nFrases nao sao palindromos");
	else
		printf("Sao palindromos");
	_getch();


}

void pilha09(){

}



char Menu(void)
{

	system("cls");
	printf("### MENU PARA OS Exercicios de Pilha padrao e caso 1 e 2 ###\n");
	printf("**** MENU DE OPCOES ****");
	printf("\n[A] Ex1 - Arquivo Texto");
	printf("\n[B] Ex1 - B: Arquivo Texto com string");
	printf("\n[C] Ex2 - Arquivo texto");
	printf("\n[D] Ex3 - Arquivo texto");
	printf("\n[E] Ex4 - Arquivo texto");
	printf("\n[F] Ex5 - Arquivo texto");
	printf("\n[G] Ex7 - Arquivo texto");
	printf("\n[H] Ex8 - Arquivo texto");
	printf("\n[I] Ex9 - Arquivo texto");
	printf("\n[J] Ex10 - Arquivo texto");
	printf("\n[K] Ex11 - Arquivo texto");
	printf("\n[L] Ex12 - Arquivo texto");
	printf("\n[M] Ex13 - Arquivo texto");//bagulho merda, sou quenga de string, não sei trabalhar direito como isso nao
	printf("\n[N] Ex14 - Arquivo texto");
	printf("\n[O] Ex15 - Arquivo texto");
	printf("\n[P] Ex16 - Arquivo texto");
	printf("\n[Q] Ex22 - Arquivo texto");
	printf("\n[R] Ex23 - Arquivo texto");
	printf("\n[S] Formatador - Ex. Prova");
	printf("\n[T] Exibir arquivos criados pelos exercicios de arq. texto sem precisar abrir ele manualmente.");
	printf("\nIniciando os exercicios de pilha padrao:");
	printf("\n[U] Ex1 - Pilha com inteiros");
	printf("\n[V] Ex2 - Pilha com inteiros");
	printf("\n[W] Ex3 - Pilha com inteiros");
	printf("\n[X] Ex5 - Pilha com inteiros");
	printf("\n[Y] Ex6 - Pilha com inteiros");
	printf("\n[Z] Ex7 - Pilha com char");
	printf("\n[0] Ex9 - pilha com char");
	printf("Iniciando os exercicios de pilha caso 1:");
	printf("\n[1] ");
	printf("\n[2] ");
	printf("\n[3] ");
	printf("\n[4] ");
	printf("\n[5] ");
	printf("\n[6] ");
	printf("\n[7] ");
	printf("\n[8] ");
	printf("\n[9] ");
	printf("\n[/] ");
	printf("\n['] ");
	printf("\n[-] ");
	printf("\n[-] ");

	printf("\n[ESC] Sair do Programa");
	printf("\nOpcao: ");

	_getch();
	return toupper(_getch());

}

int main() {
	char opcao;
	do
	{
		opcao = Menu();
		system("cls");
		switch (opcao)
		{

		case 'A':Ex1("arq.txt");
			break;
		case 'B':
			Ex1B("arq.txt");
			break;
		case 'C':Ex2("arq.txt");
			break;
		case 'D':Ex3("arq.txt", "arq2.txt");
			break;
		case 'E':Ex4("arq.txt");
			break;
		case 'F':Ex5();
			break;
		case 'G':Ex7("arq.txt");
			break;
		case 'H':Ex8("Ex7.txt");
			break;
		case 'I':Ex9("arq.txt");
			break;
		case 'J':Ex10();
			break;
		case 'K':Ex11("Ex11.txt");
			break;
		case 'L':Ex12("arq.txt", 'a');
			break;
		case 'M':Ex13("Ex13.txt", "arthur");
			break;
		case 'N':Ex14("arq.txt");
			break;
		case 'O':Ex15("arq.txt", 'a', '@');
			break;
		case 'P':Ex16("Ex11.txt");
			break;
		case 'Q':Ex22();
			break;
		case 'R':Ex23();
			break;
		case 'S':Formatador("arq.txt");//nome aleatorio do arquivo, precisa criar para testar o exercicio, coloquei pra remover o erro
			break;
		case 'T':ExibeArqCriado();
			break;
		case 'U':pilha01();
			break;
		case 'V':pilha02();
			break;
		case 'W':pilha03();
			break;
		case 'X':pilha05();
			break;
		case 'Y':pilha06("arqEx6Pilha.txt");
			break;
		case 'Z':pilha07();
			break;


		}

	} while (opcao != 27);
	return 0;
}