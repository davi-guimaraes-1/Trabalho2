

#include <stdio.h>
#include <locale.h>
#include "locadora.h"

int main() {
	categoria categorias[MAX_CATEGORIAS];
	veiculo veiculos[MAX_VEICULOS];
	int qtdCat = 0, qtdVeic = 0;
	int opcao, acoes = 0;

	setlocale(LC_ALL, "Portuguese");

	do {
		printf("\n---------------- SISTEMA DE LOCADORA DE CARROS ----------------\n");
		printf("0 - SAIR DA APLICAÇÃO\n");
		printf("1 - Cadastrar categoria\n");
		printf("2 - Exibir categorias\n");
		printf("3 - Inserir veículo\n");
		printf("\nDIGITE A OPÇÃO DESEJADA: ");

		if (scanf("%d", &opcao) != 1) {
			printf("\nEntrada inválida!\n");
			limpaBuffer();
			continue;
		}
		limpaBuffer();

		switch (opcao) {
			case 0:
				break;
			case 1:
				if (cadastraCategoria(categorias, qtdCat)) {
					qtdCat++;
				}
				acoes++;
				break;
			/* case 2 e case 3: você escreve */
			default:
				printf("\nOpção inválida!\n");
		}
	} while (opcao != 0);

	printf("\nAções executadas: %d\n", acoes);
	return 0;
}
