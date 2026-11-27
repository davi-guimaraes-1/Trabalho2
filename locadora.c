#include <stdio.h>
#include <locale.h>
#include "locadora.h"
#define MAX 1000
#define MAX_CATEGORIAS 10
#define MID 100 



void limpaBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}
int cadastraCategoria(categoria categorias[], int qtd) {
	int codigo, i;
	
	if (qtd >= MAX_CATEGORIAS) {
		printf("Número máximo de categorias atingido!\n");
		return 0;
	}

	printf("Informe o codigo da categoria que deseja cadastrar: ");
	
	if (scanf("%d", &codigo) != 1) {
		printf("\nFalha ao ler o número!\n");
		limpaBuffer();
		return 0;
	}

	if (codigo < 1 || codigo > MAX_CATEGORIAS) {
		printf("\nCódigo inválido! Use um valor de 1 a %d.\n", MAX_CATEGORIAS);
		return 0;
	}

	for (i = 0; i < qtd; i++) {
		if (categorias[i].codigoCategoria == codigo) {
			printf("\nJá existe uma categoria com esse código!\n");
			return 0;
		}
	}

	categorias[qtd].codigoCategoria = codigo;
	
	
	printf("\n\n Informe o nome da categoria que deseja cadastrar: ");
	if (scanf(" %19[^\n]", categorias[qtd].nome) != 1){
		printf("\nErro ao digitar o nome!\n");
		limpaBuffer();
		return 0;
	}
	limpaBuffer();
	printf("\nCategoria cadastrada com sucesso!\n");
	return 1;
}
void exibirCategoria() {
	
}
void cadastraVeiculo() {
}
void exibirRelacao() {
}
void realizarAluguel() {
}
void realizarDevolucao() {
}
void exibirVeiculosAlugadosCategoria() {
}
void exibirTodosVeiculoAlugadoPorCategoria() {
}
void exibirLocacoesAbertasGeral() {
}
