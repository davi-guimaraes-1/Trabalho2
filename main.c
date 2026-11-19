#include <stdio.h>
#include <locadora.h>
#include <locale.h>

typedef struct{
	int dia;
	int mes;
	int ano;
}data;

typedef struct{
	int codigoCategoria;
	char nome[20];
}categora;


typedef struct{
 char codigoVeiculo[30];
 char marca[20];
 char modelo[40];
 int categoria;
 int ano;
 float diaria;
 int qtdUnidades;
 int qtdAlugada;
}veiculo;

typedef struct{
	int numero;
	veiculo codigoVeiculo;
	data dataRetirada;
	data dataPrevistaDevolucao;
	dat dataDevolucao;
	int status;
	float diariaAtrasoContrato;
	float valorPrevisto;
	float valorPago;
}locacao;




int main(void){
	setlocale(LC_ALL, "Portuguese");
	int select, i;
	
	
	do{
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
	switch (select){
		case 0:
			i--;
			break;
		case 1:
			cadastraCategoria;
			continue;
		case 2:
			exibieCategoria;
			continue;
		case 3:
			cadastraVeiculo;
			continue;
		case 4:
			exibirRelacao;
			continue;
		case 5:
			realizarAluguel;
			continue;
		case 6:
			realizarDevolucao;
			continue;
		case 7:
			exibirVeiculosAlugadosCategoria;
			continue;
		case 8:
			exibirTodosVeiculoAlugadoPorCategoria;
			continue;
		case 9:
			exibirLocacoesAbertasGeral;
			continue;
		default : 
			printf("\n\Opção inválida!\n\n");
			i--;
			continue;
		
	}
	
	}while(i != 0);
	return 0;
}
//ola
