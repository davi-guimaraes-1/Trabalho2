#include <stdio.h>
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
	
	
	switch (select){
		case 0:
			
		case 1:
			cadastraCategoria;
		case 2:
			exibieCategoria;
		case 3:
			cadastraVeiculo;
		case 4:
			exibirRelacao;
		case 5:
			realizarAluguel;
		case 6:
			realizarDevolucao;
		case 7:
			exibirVeiculosAlugadosCategoria;
		case 8:
			exibirTodosVeiculoAlugadoPorCategoria;
		case 9:
			exibirLocacoesAbertasGeral;
		default : 
			printf("\n\Opção inválida!\n\n");
			i--;
			continue;
		
	}
	
	}while(i != 0);
	return 0;
}
//ola
