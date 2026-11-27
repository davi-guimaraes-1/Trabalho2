#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include "locadora.h"
	
	int main(void) {
	veiculo veiculos[MAX_LOCACOES];
	Categoria categorias[MAX_CATEGORIAS];
 	locacao locacoes[MAX_VEICULOS];
	int contCat=0;
	int contVe=0;
	int contLoc=0;
	int qtdAcao;
	
	setlocale(LC_ALL, "Portuguese");
	int select, i;
	
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
		scanf("%d", &select);
		
		i++;
		
		switch (select) {
			case 0:
				i--;
				break;
			case 1:
			if (cadastraCategoria(categorias, contCat) == 1) {
   				contCat++;
   				qtdAcao++;
			}
			continue;
			case 2:
				exibirCategoria(categorias, contCat);
				qtdAcao++;
				continue;
			case 3:
				if (cadastraVeiculo(veiculos, contVe) == 1){
					contVe++;
					qtdAcao++;
				}
				
				continue;
			case 4:
				exibirRelacao();
				continue;
			case 5:
				realizarAluguel();
				continue;
			case 6:
				realizarDevolucao();
				continue;
			case 7:
				exibirVeiculosAlugadosCategoria();
				continue;
			case 8:
				exibirTodosVeiculoAlugadoPorCategoria();
				continue;
			case 9:
				exibirLocacoesAbertasGeral();
				continue;
			default: 
				printf("\n\Opção inválida!\n\n");
				i--;
				continue;
		}
	} while(i != 0);
	return 0;
}
