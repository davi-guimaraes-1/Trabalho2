/* TRABALHO DE ALGORITMOS E ESTRUTURAS DE DADOS
   NOME DO SISTEMA DESENVOLVIDO: Locadora de Carros
   COMPONENTES: Davi Guimarães, Gustavo Brzesky, Henrique Paiva
   DATA: (data da última alteração) */

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "locadora.h"

int main(void) {
	int qtdVeic = 0, qtdCat = 0, qtdLoc = 0;//contadores de elementos cadastrados
	int select = -1, i = 0;//i conta as ações do usuário, sem contar a saída
	int cod;
	
	setlocale(LC_ALL, "Portuguese");
	
	do {
		printf(
		"======================================================\n"
		" >SELECIONE UMA DAS OPÇÕES ABAIXO PARA PROSSEGUIR<\n"
		"\n\n 0) SAIR DA APLICAÇÃO" 
		"\n 1) CADASTRAR CATEGORIA."
		"\n 2) EXIBIR CATEGORIAS."
		"\n 3) INSERIR VEÍCULO."
		"\n 4) EXIBIR RELAÇÃO DE VEÍCULOS."
		"\n 5) REALIZAR ALUGUEL."
		"\n 6) REALIZAR DEVOLUÇÃO"
		"\n 7) EXIBIR VEÍCULOS ALUGADOS DE UMA DETERMINADA CATEGORIA"
		"\n 8) EXIBIR VEÍCULOS ALUGADOS POR CATEGORIA."
		"\n 9) EXIBIR LOCAÇÕES ABERTAS.\n\n\n"
		"======================================================\n"
		);
		
		printf("Digite a opção desejada: ");
		if (scanf("%d", &select) != 1) {//se digitar letra, avisa e volta ao menu
			printf("\nEntrada inválida!\n\n");
			limpaBuffer();
			select = -1;
			continue;
		}
		limpaBuffer();
		
		i++;//conta a ação; é descontada abaixo se for sair ou opção inválida
		
		switch (select) {
			case 0:
				i--;
				break;
			case 1:
				if (cadastraCategoria(qtdCat)) {
					qtdCat++;//só aumenta se o cadastro deu certo
				}
				continue;
			case 2:
				exibirCategoria(qtdCat);
				continue;
			case 3:
				if (cadastraVeiculo(qtdVeic, qtdCat)) {
					qtdVeic++;//só aumenta se o cadastro deu certo
				}
				continue;
			case 4:
				exibirRelacao(qtdVeic, qtdCat);
				continue;
			case 5:
				if (realizarAluguel(qtdLoc, qtdVeic, qtdCat)) {
					qtdLoc++;
				}
				continue;
			case 6:
				realizarDevolucao();
				continue;
			case 7:
				printf("\nInforme o código: ");
				scanf("%d", &cod);
				exibirVeiculosAlugadosCategoria(cod, qtdCat);
				continue;
			case 8:
				exibirTodosVeiculoAlugadoPorCategoria(qtdCat);
				continue;
			case 9:
				exibirLocacoesAbertasGeral();
				continue;
			default: 
				printf("\nOpção inválida!\n\n");
				i--;
				continue;
		}
	} while(select != 0);
	
	printf("\nAções executadas: %d\n", i);
	return 0;
}
