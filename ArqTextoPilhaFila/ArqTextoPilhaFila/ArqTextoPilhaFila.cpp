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
#define tl 3 //paletes
#define PMA 5 //exercicio 1 de pilha multipla caso 1
#define B 100
#include"TADPilha.h"
#include "TADPilhaPadraoChar.h"
#include "PilhaMultiplaCaso1.h"
#include "TADPilhaNPilhasCaso2.h"
#include "TADFila.h"
#include "TadFilaCircular.h"
#include "TADPilhaBrinquedo.h"

#pragma region Arquivo Texto
void fecharArq(FILE* NomeArq1, FILE* NomeArq2) {

	fclose(NomeArq1);
	fclose(NomeArq2);
}

void ExibirMsg() {
	printf("\nExercicio feito, pressione qualquer tecla de forma repetida para voltar ao menu....... :)");
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

#pragma region Pilha padrão
void pilha01() {
	TpPilha p1, p2, paux;
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
	int num = 0, elemRemove = 0;
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
	printf("\nO elemento [%d] foi removido com sucesso, a pilha então ficou assim:\n", elemRemove);
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

	TpPilha p1, p2;
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
			if (chr != 32)
				insere(p1, chr - '0');

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
	char frase[100], aux;
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

void pilha09() {
	TpPilhaPadraoChar p1, p2;
	char frase[100], chr;;
	inicializaPilhaTipoChar(p1);
	inicializaPilhaTipoChar(p2);


	printf("\nForneca a frase: ");
	fflush(stdin);
	gets_s(frase);

	for (int i = 0; i < strlen(frase); i++)
		inserePilhaTipoChar(p1, frase[i]);

	while (!vazia(p1.TOPO)) {

		chr = retiraPilhaTipoChar(p1);

		if (chr != 32)
			inserePilhaTipoChar(p2, chr);
		if (chr == 32 || vaziaPilhaTipoChar(p1.TOPO)) {
			while (!vaziaPilhaTipoChar(p2.TOPO))
				printf("%c", retiraPilhaTipoChar(p2));
			printf(" ");
		}

	}

	_getch();



}

void Paletes(const char nomeArq[100]) {

	TpPilha pa, pb, pc, paux;

	inicializa(pa);//7t
	inicializa(pb);//5t
	inicializa(pc);//3t

	char chr;
	FILE* PtrArq = fopen(nomeArq, "r");

	if (PtrArq == NULL)
		printf("\nErro com o arquivo dos paletes");
	else {
		chr = fgetc(PtrArq);
		while (!feof(PtrArq)) {

			switch (chr) {

			case '3':
				if (!cheia(pc.topo))
					insere(pc, chr - '0');
				break;

			case '5':
				if (!cheia(pb.topo))
					insere(pb, chr - '0');
				break;
			case '7':
				if (!cheia(pa.topo))
					insere(pa, chr - '0');
				break;

			}
			chr = fgetc(PtrArq);
		}
	}

	while (!cheia(pa.topo) && !vazia(pb.topo))
		insere(pa, retira(pb));
	while (!cheia(pa.topo) && !vazia(pc.topo))
		insere(pa, retira(pc));

	exibe(pa);
	_getch();


}

void PaletesComVetor(const char nomeArq[100]) {

	TpPilha p1, p2;
	int num[tl], i = 0, aux = 0;
	inicializa(p1);
	FILE* PtrArq = fopen(nomeArq, "r");
	char chr;

	if (PtrArq == NULL)
		printf("\nErro com o arquivo");
	else {

		chr = fgetc(PtrArq);

		while (!feof(PtrArq)) {
			if (chr != 32) {
				num[i] = chr - '0';
				i++;
			}

			chr = fgetc(PtrArq);
		}

		for (int i = 0; i < tl - 1; i++) {
			for (int j = 0; j < tl - 1 - i; j++) {
				if (num[j] < num[j + 1]) {
					aux = num[j];
					num[j] = num[j + 1];
					num[j + 1] = aux;
				}
			}
		}
		printf("\n\n\nO vetor ordenado do maior para o menor ");//faz assim pq ao inserir na pilha, insere o 7 primeiro e o 3 se torna meu topo
		for (int i = 0; i < tl; i++) {
			printf(" %d ", num[i]);
			insere(p1, num[i]);
		}

		exibe(p1);
		fclose(PtrArq);
		_getch();
	}

}
#pragma endregion

#pragma region Pilha múltipla CASO 1
void pilhaCASO1Ex1() {

	TpPilhaM pm;
	char chr, aux, vet[PMA];
	inicializarPMA(pm);

	for (int i = 0; i <= 4; i++) {
		printf("\nForneca os valores da primeira pilha:");
		scanf("%s", &chr);
		inserirPMA(pm, chr, 1);
	}

	for (int i = 0; i < MAXP / 2; i++) {
		printf("\nForneca os valores da segunda pilha:");
		scanf("%s", &chr);
		inserirPMA(pm, chr, 0);
	}

	for (int i = 0; i < PMA; i++) {
		aux = retirarPMA(pm, 0);
		vet[i] = aux;
	}

	//bubble sort para ordenar o vetor e deixar filé pra inserir essa merda corretamente pq não pensei em outra forma
	//28 do 09 de 2023+1, às 03:45, conclui essa merda tirando a ideia do bubble sort da alma, meu deus
	for (int i = 0; i < PMA - 1; i++) {
		for (int j = 0; j < PMA - 1; j++) {
			if (vet[j] > vet[j + 1]) {
				aux = vet[j];
				vet[j] = vet[j + 1];
				vet[j + 1] = aux;
			}
		}
	}

	for (int i = 0; i < PMA; i++)
		inserirPMA(pm, vet[i], 1);


	exibirPMA(pm, 1);
	_getch();




}

void pilhaCASO1Ex2() {
	TpPilhaM pm;

	inicializarPMA(pm);

	char chr, elemRemove, aux, vet[MAXPILHAPM1];

	for (int i = 0; i < MAXPILHAPM1; i++) {
		printf("\nForneca os elementos da pilha: ");
		scanf("%s", &chr);
		inserirPMA(pm, chr, 1);
	}

	printf("\n\nQual elemento deseja remover ?:	");
	scanf("%s", &elemRemove);

	while (!vazia(pm.TOPO1)) {

		aux = retirarPMA(pm, 1);

		if (aux != elemRemove)
			inserirPMA(pm, aux, 0);
	}


	while (!vaziaPMA(pm.TOPO1, 0))
		inserirPMA(pm, retirarPMA(pm, 0), 1);



	exibirPMA(pm, 1);
	_getch();


}

void PaletesCaso1(const char nomeArq[100]) {

	FILE* PtrArq = fopen(nomeArq, "r");
	char chr;
	int vet[tl], aux = 0, i = 0;
	TpPilhaM pm;

	inicializarPMA(pm);


	if (PtrArq == NULL)
		printf("\nErro com o arquivo");
	else {

		chr = fgetc(PtrArq);

		while (!feof(PtrArq)) {
			if (chr != 32) {
				vet[i] = chr - '0';
				i++;
			}
			chr = fgetc(PtrArq);
		}


		for (int i = 0; i <= tl - 1; i++) {
			for (int j = 0; j <= tl - 1; j++) {
				if (vet[j] < vet[j + 1]) {
					aux = vet[j];
					vet[j] = vet[j + 1];
					vet[j + 1] = aux;
				}
			}
		}

		for (int i = 0; i < tl; i++)
			inserirPMA(pm, vet[i] + '0', 1);

	}

	fclose(PtrArq);
	exibirPMA(pm, 1);
	_getch();



}

void pilhaCaso1Ex6(const char nomeArq[100]) {
	TpPilhaM pm;
	FILE* PtrArq = fopen(nomeArq, "r");
	char chr;

	inicializarPMA(pm);

	if (PtrArq == NULL)
		printf("\nErro com o arquivo");
	else {

		FILE* PtrN = fopen("pilhaCaso1Ex6.txt", "w");
		chr = fgetc(PtrArq);

		while (!feof(PtrArq)) {

			if (chr != 32)
				inserirPMA(pm, chr, 1);
			chr = fgetc(PtrArq);


		}


		while (!vaziaPMA(pm.TOPO1, 1))
			fprintf(PtrN, " %c ", retirarPMA(pm, 1));

		fecharArq(PtrN, PtrArq);

	}

	_getch();


}

void pilhaCaso1Ex5() {

	TpPilhaM pm;
	char chr[TL];
	inicializarPMA(pm);


	for (int i = 0; i < TL; i++) {
		printf("\nForneca os dados do vetor: ");
		fflush(stdin);
		scanf("%s", &chr[i]);
	}


	printf("\nVETOR: ");
	for (int i = 0; i < TL; i++) {
		printf(" %c ", chr[i]);
		inserirPMA(pm, chr[i], 0);
	}

	printf("\nVETOR INVERTIDO: ");
	exibirPMASemBarraN(pm, 0);

	_getch();

}

void pilhaCaso1Ex7() {
	TpPilhaM pm;
	char frase[10], aux;
	int dif = 0, j = 0;
	inicializarPMA(pm);

	printf("\nForneca a frase: ");
	fflush(stdin);
	gets_s(frase);


	for (int i = 0; i < strlen(frase); i++)
		inserirPMA(pm, frase[i], 1);


	while (!vaziaPMA(pm.TOPO1, 1)) {
		aux = retirarPMA(pm, 1);

		if (aux == frase[j]) {
			j++;
			inserirPMA(pm, aux, 0);
		}

		else
			dif++;
	}

	if (dif > 0)
		printf("\nNao sao palindromos");
	else
		printf("\nSao palindromos");

	_getch();


}
#pragma endregion

#pragma region Pilha múltipla CASO 2
//ajustar o maxpilha caso for testar o ex 1 de PM caso 2, por que alterei o maxpilha de 10 para 100 por causa do ex 9.
void pilhaCaso2Ex1() {
	TpPilhaM2 pm;
	char elem;
	inicializarPM2(pm, 3);

	for (int i = 0; i < MAXPILHACASO2 / 3; i++) {
		printf("\nForneca os elementos do tipo CHAR para a pilha 1:");
		fflush(stdin);
		scanf("%s", &elem);
		inserirPM2(pm, elem, 0);
	}

	exibirPM2(pm, 0);

	for (int i = 0; i < MAXPILHACASO2 / 3; i++) {
		printf("\nForneca os elementos do tipo CHAR para a pilha 2:");
		fflush(stdin);
		scanf("%s", &elem);
		inserirPM2(pm, elem, 1);
	}

	while (!vaziaPM2(pm, 1))
		inserirPM2(pm, retirarPM2(pm, 1), 2);

	while (!vaziaPM2(pm, 2))
		inserirPM2(pm, retirarPM2(pm, 2), 0);

	exibirPM2(pm, 0);
	_getch();


}

void pilhaCaso2Ex2() {

	TpPilhaM2 pm;
	char elem, elemRemove, aux;
	inicializarPM2(pm, 2);


	for (int i = 0; i < MAXPILHACASO2; i++) {
		printf("\nForneca os elementos da pilha: ");
		fflush(stdin);
		scanf("%s", &elem);
		inserirPM2(pm, elem, 0);
	}

	printf("\nForneca o elemento que deseja remover: ");
	fflush(stdin);
	scanf("%s", &elemRemove);

	while (!vaziaPM2(pm, 0)) {

		aux = retirarPM2(pm, 0);

		if (aux != elemRemove)
			inserirPM2(pm, aux, 1);
	}

	while (!vaziaPM2(pm, 1))
		inserirPM2(pm, retirarPM2(pm, 1), 0);

	exibirPM2(pm, 0);
	printf("\n____________\n");

	_getch();


}

void pilhaCaso2Ex3() {

	printf("\nExpressao polonesa com TAD de char convertendo para inteiro\n");
	TpPilhaM2 pm;

	inicializarPM2(pm, 1);
	char exp[100], aux;
	int num1 = 0, num2 = 0, resultado = 0;

	printf("\nForneca a expressao bolonhesa: ");
	fflush(stdin);
	gets_s(exp);

	for (int i = 0; i < strlen(exp); i++) {
		aux = exp[i];

		if (isdigit(aux))
			inserirPM2(pm, aux - '0', 0);

		else if (aux == '*' || aux == '+' || aux == '-') {

			num1 = retirarPM2(pm, 0);
			num2 = retirarPM2(pm, 0);

			if (aux == '*')
				resultado = num1 * num2;
			if (aux == '+')
				resultado = num1 + num2;
			if (aux == '-')
				resultado = num1 - num2;

			inserirPM2(pm, resultado, 0);

		}

	}

	resultado = retirarPM2(pm, 0);
	printf("\nResultado da expressao polonesa pos-fixada foi: [%d]", resultado);

	_getch();
}

void pilhaCaso2Ex5() {

	TpPilhaM2 pm;

	inicializarPM2(pm, 1);

	char elem[TL];

	for (int i = 0; i < TL; i++) {
		printf("\nForneca os dados do vetor: ");
		fflush(stdin);
		scanf("%s", &elem[i]);
		inserirPM2(pm, elem[i], 0);
	}
	system("cls");
	printf("Vetor: \n");
	for (int i = 0; i < TL; i++)
		printf(" %c ", elem[i]);

	printf("\nVetor invertido: \n");
	while (!vaziaPM2(pm, 0))
		printf(" %c ", retirarPM2(pm, 0));

	_getch();

}

void pilhaCaso2Ex6(const char nomeArq[100]) {

	FILE* PtrArq = fopen(nomeArq, "r");
	TpPilhaM2 pm;
	char chr;

	inicializarPM2(pm, 1);


	if (PtrArq == NULL)
		printf("\nErro com o arquivo");
	else {

		FILE* PtrN = fopen("pilhaCaso2Ex6.txt", "w");
		chr = fgetc(PtrArq);

		while (!feof(PtrArq)) {

			if (chr != 32)
				inserirPM2(pm, chr, 0);

			chr = fgetc(PtrArq);
		}

		while (!vaziaPM2(pm, 0))
			fprintf(PtrN, " %c ", retirarPM2(pm, 0));

		fecharArq(PtrArq, PtrN);
	}

	ExibirMsg();
	_getch();

}

void pilhaCaso2Ex7() {

	TpPilhaM2 pm;
	inicializarPM2(pm, 1);
	char frase[10], aux;
	int dif = 0, i = 0;

	printf("\nForneca a frase: ");
	fflush(stdin);
	gets_s(frase);

	for (int i = 0; i < strlen(frase); i++)
		inserirPM2(pm, frase[i], 0);

	while (!vaziaPM2(pm, 0)) {

		aux = retirarPM2(pm, 0);

		if (aux != frase[i])
			dif++;
		i++;
	}

	if (dif > 0)
		printf("\nNao sao palindromos");
	else
		printf("\nSao palindromos");


	_getch();




}

void pilhaCaso2Ex9() {

	TpPilhaM2 pm;

	inicializarPM2(pm, 2);
	char frase[100], aux;


	printf("\nForneca a frase: ");
	fflush(stdin);
	gets_s(frase);

	for (int i = 0; i < strlen(frase); i++)
		inserirPM2(pm, frase[i], 0);

	while (!vaziaPM2(pm, 0)) {

		aux = retirarPM2(pm, 0);

		if (aux != 32)
			inserirPM2(pm, aux, 1);

		if (aux == 32 || vaziaPM2(pm, 0)) {
			while (!vaziaPM2(pm, 1))
				printf("%c", retirarPM2(pm, 1));
			printf(" ");
		}

	}
	printf("\n\n");
	ExibirMsg();
	_getch();

}

void PaletesCaso2(const char nomeArq[100]) {

	FILE* PtrArq = fopen(nomeArq, "r");
	TpPilhaM2 pm;
	char chr;
	inicializarPM2(pm, 3);

	if (PtrArq == NULL)
		printf("\nErro com o arquivo");
	else {

		chr = fgetc(PtrArq);
		while (!feof(PtrArq)) {

			switch (chr) {

			case '3':
				if (chr == '3')
					inserirPM2(pm, chr, 2);
				break;
			case '5':
				if (chr == '5')
					inserirPM2(pm, chr, 1);
				break;
			case '7':
				if (chr == '7')
					inserirPM2(pm, chr, 0);
				break;

			}
			chr = fgetc(PtrArq);

		}


	}

	while (!vaziaPM2(pm, 1) && elementoTopoPM2(pm, 1) < elementoTopoPM2(pm, 0))
		inserirPM2(pm, retirarPM2(pm, 1), 0);
	while (!vaziaPM2(pm, 2) && elementoTopoPM2(pm, 2) < elementoTopoPM2(pm, 0))
		inserirPM2(pm, retirarPM2(pm, 2), 0);

	exibirPM2(pm, 0);

	ExibirMsg();

}

void OrdenaVetorCaso2() {

	TpPilhaM2 pm;
	inicializarPM2(pm, 2);
	char vet[TL], op, aux;

	for (int i = 0; i < TL; i++) {
		printf("\nInsira os dados do vetor: ");
		fflush(stdin);
		scanf("%s", &vet[i]);
	}

	system("cls");

	printf("\nVetor atualmente: ");
	for (int i = 0; i < TL; i++)
		printf(" %c ", vet[i]);

	printf("\nDeseja ordenar do maior para o menor ou do menor para o maior ? [S = Menor para Maior] / [N = Maior para Menor]: ");
	op = toupper(_getche());

	system("cls");

	if (op == 'S') {

		for (int i = 0; i < TL - 1; i++) {
			for (int j = 0; j < TL - 1; j++) {
				if (vet[j] > vet[j + 1]) {
					aux = vet[j];
					vet[j] = vet[j + 1];
					vet[j + 1] = aux;
				}
			}
		}

		printf("\nVetor ordenado com sucesso, ficando assim [Menor para Maior]");
		for (int i = 0; i < TL; i++)
			printf(" %c ", vet[i]);

	}
	else {
		for (int i = 0; i < TL - 1; i++) {
			for (int j = 0; j < TL - 1; j++) {
				if (vet[j] < vet[j + 1]) {
					aux = vet[j];
					vet[j] = vet[j + 1];
					vet[j + 1] = aux;
				}
			}
		}

		printf("\nVetor ordenado com sucesso, ficando assim [Maior para o Menor]");
		for (int i = 0; i < TL; i++)
			printf(" %c ", vet[i]);

	}

	for (int k = 0; k < TL; k++)
		inserirPM2(pm, vet[k], 0);

	while (!vaziaPM2(pm, 0))
		inserirPM2(pm, retirarPM2(pm, 0), 1);

	printf("\nVetor inserido na pilha: ");
	while (!vaziaPM2(pm, 1))
		printf(" %c ", retirarPM2(pm, 1));

	_getch();
}
#pragma endregion

#pragma region Fila
void InserindoFila() {

	TpFila f1, f2, faux;
	int elem;
	inicializaF(f1);
	inicializaF(f2);
	inicializaF(faux);

	for (int i = 0; i < MAXF / 2; i++) {
		printf("\nForneca os elementos da fila 1: ");
		scanf("%d", &elem);
		insereF(f1, elem);
	}

	for (int i = 0; i < MAXF / 2; i++) {
		printf("\nForneca os elementos da fila 2: ");
		scanf("%d", &elem);
		insereF(f2, elem);
	}

	printf("\nFila 1: ");
	exibeF(f1);
	printf("\nFila 2: ");
	exibeF(f2);
	Sleep(1200);
	system("cls");

	while (!vaziaF(f2.fim))
		insereF(faux, retiraF(f2));

	while (!vaziaF(faux.fim))
		insereF(f1, retiraF(faux));

	printf("\nFila Final: ");
	exibeF(f1);
	ExibirMsg();
	_getch();


}

void RemovendoElemFila() {
	TpFila f1, f2;
	int elem = 0, elemRemove = 0, aux = 0;
	inicializaF(f1);
	inicializaF(f2);

	for (int i = 0; i < MAXF; i++) {
		printf("\nForneca os elementos da FILA: ");
		scanf("%d", &elem);
		insereF(f1, elem);
	}

	printf("\nFila atualmente: ");
	exibeF(f1);

	printf("\nForneca o elemento para ser removido: ");
	scanf("%d", &elemRemove);

	system("cls");

	printf("\nFila atualmente: ");
	exibeF(f1);

	while (!vazia(f1.fim)) {

		aux = retiraF(f1);

		if (aux != elemRemove)
			insereF(f2, aux);

	}

	printf("\nFila sem o elemento: ");
	exibeF(f2);


	_getch();



}

void Ex01() {
	TpFila f1;

	int num = 0;

	inicializaF(f1);

	do {

		num = rand() % 2;

		printf("\nOpcao escolhida: %d", num);

		if (num == 1 && !cheia(f1.fim)) {

			num = rand() % 10;

			insereF(f1, num);
			printf("\n");
			exibeF(f1);
		}
		else if (num != 1 && !vazia(f1.fim)) {

			retiraF(f1);
			printf("\n");
			exibeF(f1);
		}

		Sleep(1000);

	} while (!_kbhit());

	_getch();
}

void Ex03() {

	TpFila f;

	inicializaF(f);

	int imp = 3, gravaInterno = 5, leitura = 4, gravaExt = 8;
	int ut = 2, tarefa, utTarefa = 0;


	do {

		if (ut % 2 == 1) {

			tarefa = rand() % 4;

			switch (tarefa) {

			case '0':
				if (!cheiaF(f.fim)) {

					printf("\nInseriu uma impressao na fila: ");
					printf("\nFila atual: ");
					exibeF(f);
					insereF(f, imp);
				}
				break;

			case '1':
				if (!cheiaF(f.fim)) {
					printf("\nInseriu uma gravacao em dispositivo interno: ");
					printf("\nFila Atual: ");
					exibeF(f);
					insereF(f, gravaInterno);
				}
				break;
			case '2':
				if (!cheiaF(f.fim)) {
					printf("\nInseriu uma leitura: ");
					printf("\nFila atual: ");
					exibeF(f);
					insereF(f, leitura);
				}
				break;

			case '3':
				if (!cheiaF(f.fim)) {
					printf("\nInseriu uma gravacao em dispositivo externo: ");
					printf("Fila atual: ");
					exibeF(f);
					insereF(f, gravaExt);
				}
			}
		}

		if (utTarefa % 3 == 1 && !vaziaF(f.fim) && f.fila[0] == 3) {
			printf("\nRetirou uma impressao da fila: ");
			retiraF(f);
			printf("\nFila atual: ");
			exibeF(f);
		}
		if (utTarefa % 5 == 1 && !vaziaF(f.fim) && f.fila[0] == 5) {
			printf("\nRetirou uma gravacao interna da fila");
			retiraF(f);
			printf("\nFila atualmente: ");
			exibeF(f);
		}
		if (utTarefa % 4 == 1 && !vaziaF(f.fim) && f.fila[0] == 4) {
			printf("\nRetirou uma leitura da fila: ");
			retiraF(f);
			printf("Fila atual: ");
			exibeF(f);
		}
		if (utTarefa % 4 == 1 && !vaziaF(f.fim) && f.fila[0] == 8) {
			printf("\nRetirou uma gravacao externa da fila: ");
			retiraF(f);
			printf("\nFila atualmente: ");
			exibeF(f);
		}

		ut++;
		utTarefa++;


	} while (!_kbhit());


	_getch();

}

void ExCaixasBanco() {

	TpFila f;
	inicializaF(f);

	int c1 = 1, c2 = 2, c3 = 3, caixas = 0, numTarefas = 0, pessoas = 0, pessoasTentaram = 0;
	int ut = 0, utAtual = 0;
	int caixa1Func = 0, caixa2Func = 0, caixa3Func = 0;
	float tempoM = 0;
	int dep = 0, saq = 0, poup = 0, cCorrente = 0, boletos = 0, tExterna = 0, tInterna = 0;

	printf("\nForneca a UT: ");
	scanf("%d", &ut);

	while (utAtual <= ut) {

		caixas = rand() % 3;
		numTarefas = rand() % 7;

		pessoasTentaram++;

		if (!cheiaF(f.fim)) {
			insereF(f, numTarefas);

			switch (caixas) {

			case 0:
				printf("\nOptou pelo caixa 1 ");
				retiraF(f);
				pessoas++;
				caixa1Func++;
				break;

			case 1:
				printf("\nOptou pelo caixa 2 ");
				retiraF(f);
				pessoas++;
				caixa2Func++;
				break;

			case 2:
				printf("\nOptou pelo caixa 3 ");
				retiraF(f);
				pessoas++;
				caixa3Func++;
				break;
			}
		}
		else {
			printf("\nFila cheia. Pessoa não pode ser atendida.");
		}

		if (numTarefas == 1) dep++;
		if (numTarefas == 2) saq++;
		if (numTarefas == 3) poup++;
		if (numTarefas == 4) cCorrente++;
		if (numTarefas == 5) boletos++;
		if (numTarefas == 6) tExterna++;
		if (numTarefas == 7) tInterna++;

		utAtual++;
	}

	Sleep(1300);
	system("cls");

	if (pessoas > 0) {
		tempoM = (float)ut / pessoas;
	}
	else {
		printf("\nNenhuma pessoa foi atendida.\n");
		return;
	}

	int pessoasNaoAtendidas = pessoasTentaram - pessoas;

	// Resultados
	printf("\nTempo medio de espera: %.3f", tempoM);
	printf("\nQtde de pessoas atendidas: %d", pessoas);
	printf("\nQtde de pessoas que tentaram ser atendidas: %d", pessoasTentaram);
	printf("\nQtde de pessoas nao atendidas: %d", pessoasNaoAtendidas);
	printf("\nHouve %d depositos, %d saques, %d acessos ao extrato poupanca, %d acessos ao extrato de conta corrente, %d boletos pagos, %d transferencias externas e %d transferencias internas.", dep, saq, poup, cCorrente, boletos, tExterna, tInterna);
	printf("\nO caixa 1 atendeu %d, o caixa 2 atendeu %d e o caixa 3 atendeu %d", caixa1Func, caixa2Func, caixa3Func);

	_getch();
}

void Ex02() {

	TpFila f;
	inicializaF(f);

	int tempo = 10, carros = 0, qtdeVeiculos = 0, tempProx = 0;

	for (int i = 0; i < MAXF; i++)
		insereF(f, i);

	do {

		if (tempo > 0 && !vaziaF(f.fim)) {
			carros = retiraF(f);
			tempo--;
			qtdeVeiculos++;
			tempProx++;
			printf("\nO veiculo %d saiu do semaforo no tempo %d", carros, tempProx);
		}
		if (tempo <= 0) {
			printf("\nSinal fechado\n");
			tempo = 10;
			tempProx += 10;
		}

		if (vaziaF(f.fim)) {
			for (int i = 0; i < MAXF; i++)
				insereF(f, i);
		}

	} while (!_kbhit());

	Sleep(1300);
	system("cls");
	printf("Houve um total de %d veiculos que passaram pelo semaforo", qtdeVeiculos);

	_getch();
	Sleep(1500);
}

void Ex04() {
	TpFila f;
	int c1 = 5, c2 = 2, c3 = 4, c4 = 7, caixas = 0;
	int ut = 3, utAtendimento = 0, pessoas = 0, diasSemana = 0, pess = 0;
	int atendimentosC1 = 0, atendimentosC2 = 0, atendimentosC3 = 0, atendimentosC4 = 0;
	int fechadoC1 = 0, fechadoC2 = 0, fechadoC3 = 0, fechadoC4 = 0;
	float tempoM = 0;
	inicializaF(f);

	do {
		if (ut % 3 == 1) {
			caixas = rand() % 4;
			diasSemana = rand() % 4;
			switch (caixas) {
			case 0:

				if (!cheia(f.fim) && diasSemana != 0) {
					printf("\nEntrou no caixa 1: ");
					insereF(f, c1);
					printf("\nFila atualmente: ");
					exibeF(f);
					pess++;
					atendimentosC1++;
				}
				else {
					printf("\nCaixa 1 esta fechado");
					fechadoC1++;
				}


				break;

			case 1:
				if (!cheia(f.fim) && diasSemana != 1) {
					printf("\nEntrou no caixa 2: ");
					insereF(f, c2);
					printf("\nFila atualmente");
					exibeF(f);
					pess++;
					atendimentosC2++;
				}
				else {
					printf("\nCaixa 2 esta fechado");
					fechadoC2++;
				}
				break;

			case 2:
				if (!cheia(f.fim) && diasSemana != 2) {
					printf("\nEntrou no caixa 3");
					insereF(f, c3);
					printf("\nFila atualmente: ");
					exibeF(f);
					pess++;
					atendimentosC3++;
				}
				else {
					printf("\nCaixa 3 esta fechado");
					fechadoC3++;
				}
				break;
			case 4:
				if (!cheia(f.fim) && diasSemana != 3) {
					printf("\nEntrou no caixa 4");
					insereF(f, c4);
					printf("\nFila atualmente");
					exibeF(f);
					pessoas++;
					atendimentosC4++;
				}
				else {
					printf("\nCaixa 4 esta fechado");
					fechadoC4++;
				}
			}

		}

		if (utAtendimento % 5 == 1 && !vaziaF(f.fim) && f.fila[0] == 5) {
			printf("\nPessoa se retirando do caixa 1 apos o atendimento..");
			retiraF(f);
			printf("Fila atual: ");
			exibeF(f);
		}
		if (utAtendimento % 2 == 1 && !vaziaF(f.fim) && f.fila[0] == 2) {
			printf("\nPessoa se retirando do caixa 2 apos o atendimento..");
			retiraF(f);
			printf("\nFila atual: ");
			exibeF(f);
		}
		if (utAtendimento % 4 == 1 && !vaziaF(f.fim) && f.fila[0] == 4) {
			printf("\nPessoa se retirando do caixa 3 apos o atendimento..");
			retiraF(f);
			printf("\nFila atual: ");
			exibeF(f);
		}
		if (utAtendimento % 7 == 1 && !vaziaF(f.fim) && f.fila[0] == 7) {
			printf("\nPessoa se retirando do caixa 4 apos o atendimento..");
			retiraF(f);
			printf("\nFila atual: ");
			exibeF(f);
		}

		ut++;
		utAtendimento++;
	} while (!_kbhit());


	tempoM = float(ut) / pess;

	system("cls");
	printf("\nO tempo medio de atendimento eh de: %.5f", tempoM);
	printf("\nO caixa 1 atendeu %d, o caixa 2 atendeu %d, o 3 atendeu %d e o 4 atendeu %d ", atendimentosC1, atendimentosC2, atendimentosC3, atendimentosC4);
	printf("\nTivemos um total de %d clientes", pess);
	printf("\nO caixa 1 ficou %d fechado, o caixa 2 ficou %d fechado, o 3 ficou %d fechado e o 4 ficou %d fechado", fechadoC1, fechadoC2, fechadoC3, fechadoC4);

	Sleep(20000);
	_getch();



}

void VetorOrdenadoFila() {

	TpFila f;
	inicializaF(f);

	int vet[TL], aux = 0;
	char ops;


	for (int i = 0; i < TL; i++) {
		printf("\nInsira os numeros do vetor: ");
		scanf("%d", &vet[i]);
	}


	printf("\nInforme se quer ordenar do menor para o maior ou do maior para o menor: Opcao 1 ou 2: ");
	ops = toupper(_getche());

	system("cls");

	if (ops == '1') {

		printf("\nVetor atualmente: ");
		for (int i = 0; i < TL; i++)
			printf(" %d ", vet[i]);

		for (int i = 0; i < TL - 1; i++) {
			for (int j = 0; j < TL - 1; j++) {
				if (vet[j] > vet[j + 1]) {
					aux = vet[j];
					vet[j] = vet[j + 1];
					vet[j + 1] = aux;
				}
			}
		}

		printf("\n\nVetor ordenado do menor para o maior: ");
		for (int i = 0; i < TL; i++)
			printf(" %d ", vet[i]);

	}
	else {

		printf("\nVetor atualmente: ");
		for (int i = 0; i < TL; i++)
			printf(" %d ", vet[i]);

		for (int i = 0; i < TL; i++) {
			for (int j = 0; j < TL; j++) {
				if (vet[j] < vet[j + 1]) {
					aux = vet[j];
					vet[j] = vet[j + 1];
					vet[j + 1] = aux;
				}
			}
		}

		printf("\nVetor ordenado do maior para o menor: ");
		for (int i = 0; i < TL; i++)
			printf(" %d ", vet[i]);
	}


	printf("\nFila atualmente com o vetor ajustado:");
	for (int i = 0; i < TL; i++)
		insereF(f, vet[i]);

	exibeFSemBarraN(f);

	Sleep(10000);
	_getch();


}
#pragma endregion

#pragma region Fila com prioridade
void RemanejarParaPilha(TpFilaCirc fc, TpPilhaBrinquedo p);
void ordenarBrinquedo(TpBrinquedo brinquedo[], int n);
void Ex1A(const char nomeArq[100]);
void Ex1A(const char nomeArq[100]) {

	FILE* PtrArq = fopen(nomeArq, "r");
	TpBrinquedo b;
	TpFilaCirc fc;
	TpPilhaBrinquedo p;
	inicializaB(p);
	char ceps[8];
	int numCasas, numBrinqs;
	inicializarFC(fc);
	if (PtrArq == NULL)
		printf("\nErro com o arquivo");
	else {

		fscanf(PtrArq, "%[^;];%d;%d", &b.cep, &b.numCasa, &b.numBrinq);
		while (!feof(PtrArq)) {

			inserirBrinqFC(fc, b);
			fscanf(PtrArq, "%[^;];%d;%d", &b.cep, &b.numCasa, &b.numBrinq);
		}

		fclose(PtrArq);

	}
	exibeFCBrinquedo(fc);
	printf("\n------------FILA---------------------\n\n\n\n");
	RemanejarParaPilha(fc, p);


	_getch();

}


void ordenarBrinquedo(TpBrinquedo brinquedo[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (strcmp(brinquedo[j].cep, brinquedo[j + 1].cep) > 0 ||
				(strcmp(brinquedo[j].cep, brinquedo[j + 1].cep) == 0 &&
					brinquedo[j].numCasa > brinquedo[j + 1].numCasa)) {

				// Troca os brinquedos
				TpBrinquedo temp = brinquedo[j];
				brinquedo[j] = brinquedo[j + 1];
				brinquedo[j + 1] = temp;
			}
		}
	}
}





void RemanejarParaPilha(TpFilaCirc fc, TpPilhaBrinquedo p) {
	TpBrinquedo brinquedo[MAXFILAFC];
	int n = 0; // Contador de brinquedos


	while (!vaziaFC(fc.cont)) {
		brinquedo[n] = retirarBrinqFC(fc);
		printf("%s, %d, %d\n", brinquedo[n].cep, brinquedo[n].numCasa, brinquedo[n].numBrinq); 
		
		n++;
	}

	ordenarBrinquedo(brinquedo, n);

	printf("Depois da ord \n\n");
	for (int i = 0; i < n; i++) {
		printf("%s, %d, %d\n", brinquedo[i].cep, brinquedo[i].numCasa, brinquedo[i].numBrinq); 
		insereBrinquedo(p, brinquedo[i]); 
	}
	system("cls");
	exibeBrinquedo(p);
	system("cls"); 
	exibeBrinquedo(p); 
}








#pragma endregion

char Menu(void)
{

	system("cls");
	printf("### MENU para os exercicios de Arq. Texto, Pilha e Fila. ###\n");
	printf("**** OPCOES ****");
	printf("\n\n***** ARQUIVO TEXTO *****");
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
	printf("\n[M] Ex13 - Arquivo texto");//bagulho merda, sou quenga de string, não sei trabalhar direito como isso nao, só no csharp msm
	printf("\n[N] Ex14 - Arquivo texto");
	printf("\n[O] Ex15 - Arquivo texto");
	printf("\n[P] Ex16 - Arquivo texto");
	printf("\n[Q] Ex22 - Arquivo texto");
	printf("\n[R] Ex23 - Arquivo texto");
	printf("\n[S] Formatador - Ex. Prova");
	printf("\n[T] Exibir arquivos criados pelos exercicios de arq. texto sem precisar abrir ele manualmente.");
	printf("\n\n***** PILHA PADRAO *****");
	printf("\n[U] Ex1 - Pilha com inteiros");
	printf("\n[V] Ex2 - Pilha com inteiros");
	printf("\n[W] Ex3 - Pilha com inteiros");
	printf("\n[X] Ex5 - Pilha com inteiros");
	printf("\n[Y] Ex6 - Pilha com inteiros");
	printf("\n[Z] Ex7 - Pilha com char");
	printf("\n[0] Ex9 - Pilha com char");
	printf("\n[1] Exercicio paletes - Prova ED1");
	printf("\n[2] Exercicio paletes - Prova ED1 (com vetor e ordenação de bolha)");
	printf("\n\n***** PILHA CASO 1 *****");
	printf("\n[3] Ex1 - Pilha com char - CASO 1");
	printf("\n[4] Ex2 - Pilha com char - CASO 1");
	printf("\n[5] Exercicio Paletes - CASO 1 - Feito com int");
	printf("\n[6] Ex06 - Pilha com int - CASO 1");
	printf("\n[7] Ex05 - Pilha com int - CASO 1");
	printf("\n[8] Ex08 - pilha com char - CASO 1");
	printf("\n\n***** PILHA CASO 2 *****");
	printf("\n[9] Ex01 - pilha com char - CASO 2");
	printf("\n[/] Ex02 - pilha com char - CASO 2");
	printf("\n[+] Ex03 - pilha com char - CASO 2");
	printf("\n[-] Ex05 - pilha com char - CASO 2");
	printf("\n[*] Ex06 - pilha com char - CASO 2");
	printf("\n[;] Ex07 - pilha com char - CASO 2");
	printf("\n[.] Ex09 - pilha com char - CASO 2");
	printf("\n[,] Exercicio Paletes - CASO 2 - Feito com int");
	printf("\n[:] Ordenar vetor - CASO 2");
	printf("\n\n***** FILA *****");
	printf("\n[=] Inserir na fila - Feito com int");
	printf("\n[]] Remove da fila - Feito com int");
	printf("\n[[] Ex01 - FILA");
	printf("\n[`] Ex caixas de banco - FILA");
	printf("\n[|] Ex03 - FILA");
	printf("\n[~] Ex02 - FILA");
	printf("\n[?] Ex04 - FILA sem prioridade (pq eu nao sei direito essa merda)");
	printf("\n[{] Vetor ordenado e inserido na FILA.");
	printf("\n[^] Inserir no bau - FILA Circular.");
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
		case '0':pilha09();
			break;
		case '1':Paletes("Paletes.txt");
			break;
		case '2':PaletesComVetor("Paletes.txt");
			break;
		case '3':pilhaCASO1Ex1();
			break;
		case '4':pilhaCASO1Ex2();
			break;
		case '5':PaletesCaso1("Paletes.txt");
			break;
		case '6':pilhaCaso1Ex6("arqEx6Pilha.txt");
			break;
		case '7':pilhaCaso1Ex5();
			break;
		case '8':pilhaCaso1Ex7();
			break;
		case '9':pilhaCaso2Ex1();
			break;
		case '/':pilhaCaso2Ex2();
			break;
		case '+':pilhaCaso2Ex3();
			break;
		case '-':pilhaCaso2Ex5();
			break;
		case '*':pilhaCaso2Ex6("arqEx6Pilha.txt");
			break;
		case ';':pilhaCaso2Ex7();
			break;
		case '.':pilhaCaso2Ex9();
			break;
		case ',':PaletesCaso2("Paletes.txt");
			break;
		case ':':OrdenaVetorCaso2();
			break;
		case '=':InserindoFila();
			break;
		case ']':RemovendoElemFila();
			break;
		case '[':Ex01();
			break;
		case '|':Ex03();
			break;
		case '`':ExCaixasBanco();
			break;
		case '~':Ex02();
			break;
		case '?':Ex04();
			break;
		case '{':VetorOrdenadoFila();
			break;
		case '^':Ex1A("arqs.txt");
			break;
		case '}':
			break;
		}

	} while (opcao != 27);
	return 0;
}