#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "locadora.h"


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
		//verifica se o vetor está preenchido com a qtd que é contada no main e passada por parametro
	}

	printf("Informe o codigo da categoria que deseja cadastrar: ");
	
	if (scanf("%d", &codigo) != 1) {
		printf("\nFalha ao ler o número!\n");
		limpaBuffer();
		return 0;
		//verifica se houve exito no scanf, caso haja ele continua, caso haja algum erro ele retirna 0 voltando para o main
	}

	if (codigo < 1 || codigo > MAX_CATEGORIAS) {
		printf("\nCódigo inválido! Use um valor de 1 a %d.\n", MAX_CATEGORIAS);
		return 0;
		//verifica se o codigo da categoria está dentro dos parametros pré estabalecidos
	}

	for (i = 0 ; i < qtd; i++) {
		if (categorias[i].codigoCategoria == codigo) {
			printf("\nJá existe uma categoria com esse código!\n");
			return 0;
		//verifica se o usuario colocou un codigo repetido
		}
	}

	categorias[qtd].codigoCategoria = codigo;
	//atribui o valor e codigo informado pelo usuario ao struct
	//a variavel codigo foi usado por segurança, pois caso haja algum erro o programa não amarzena diretamente no struct 
	
	printf("\n\n Informe o nome da categoria que deseja cadastrar: ");
	if (scanf(" %19[^\n]", categorias[qtd].nome) != 1){//verifica se houve erro ao digitar a string, caso haja retorna 0 e volta para o main
		printf("\nErro ao digitar o nome!\n");
		limpaBuffer();
		//limpa buffer para caso haja erro ao digitar a string, 
		return 0;
	}
	limpaBuffer();//limpa o buffer para previnir possiveis erros no programa
	printf("\nCategoria cadastrada com sucesso!\n");
	return 1;
}

void exibirCategoria(categoria categorias[], int qtd) {
	int i;
	for (i = 0; i < qtd; i++){//simplesmente o qtd que é passado com a quantidade qtdCat no main, conta quanto numero de categorias foi inserido o codigo e exibe cada dado em relação a cada posição
		printf("======================================================\n");
		printf("\nCodigo da categoria: %d\n", categorias[i].codigoCategoria);
		printf("\nNome da categoria: %s\n", categorias[i].nome);
		printf("======================================================\n");
	}
}

int cadastraVeiculo(veiculo veiculos[], int qtd) {
	//vetores auxiliares para caso haja erro não passe valores errados ao struct
	char codigo[30];
	char marca[20];
	char modelo[40];
	int codCategoria, ano, qtdUnidades;
	int i;
	float diaria;

	if (qtd >= MAX_VEICULOS) {
		printf("Número máximo de veiculos atingido!\n");
		return 0;
	//caso o vetor tenha atingido o numero maximo de elementops
	}

	printf("Informe o codigo do veiculo: ");
	if (scanf(" %29[^\n]", codigo) != 1) {//verifica se não houve erro no scanf e caso haja erro ele retorna 0, finalizando essa função voltando para o main
		printf("Erro ao digitar o codigo! ");
		limpaBuffer();
		return 0;
	}

	for (i = 0; i < qtd; i++) {
		if (strcmp(veiculos[i].codigoVeiculo, codigo) == 0) {//verifica se o codigo informado pelo usuario não está repetido 
			printf("\nO codigo do veiculo está repetido!\n");
			return 0;
		}
	}

	strcpy(veiculos[qtd].codigoVeiculo, codigo);//função da biblioteca string que nos possiblita atribuir o valor de codigo para veiculos[qtd].codigoVeiculo
	
	printf("Informe a marca do veiculo: ");
	if(scanf(" %19[^\n]", marca) != 1){//verifica se houve erro no scanf
		printf("\nErro ao digitar a marca! \n");
		limpaBuffer();//limpabuffer caso ocorra um erro
		return 0; 
	}
	limpaBuffer();//limpa buffer para previnir erros
	strcpy(veiculos[qtd].marca, marca);//função da biblioteca string que nos possiblita atribuir o valor de marca para veiculos[qtd].marca

	
	printf("Digite o modelo do veiculo: ");
	if(scanf(" %39[^\n]", modelo) != 1){
		printf("\nErro ao cadastrar o modelo!\n");
		limpaBuffer();
		return 0;
	}
	limpaBuffer();
	strcpy(veiculos[qtd].modelo, modelo);
	
	printf("\nDigite a categoria veiculo cadastrado: \n");
	if(scanf("%d", &codCategoria) != 1){
		printf("Erro ao cadastrar categoria!");
		limpaBuffer();		
		return 0;
	}
	limpaBuffer();
	veiculos[qtd].categoria = codCategoria;
	
	
	printf("Digite o ano do veiculo: ");
	if(scanf("%d", &ano) != 1){
		printf("\nErro ao cadastrar ano do veiculo!\n");
		limpaBuffer();
		return 0;
	} 
	limpaBuffer();
	veiculos[qtd].ano = ano;
	
	printf("\nInforme a diaria do veiculo: \n");
		if(scanf("%f", &diaria) != 1){
		printf("\nErro ao cadastrar a diaria!\n");
		limpaBuffer();
		return 0;
		}

		if (diaria <= 0) {
		printf("\nA diaria deve ser maior que zero!\n");
		return 0;
		}
	limpaBuffer();
	veiculos[qtd].diaria = diaria;
	
	printf("\nInforme o número de unidades do veiculo: \n");
	if(scanf("%d", &qtdUnidades) != 1){
		printf("\nErro ao cadastrar o número de unidades do veiculo");
		limpaBuffer();
		return 0;
	}		
	limpaBuffer();
	
	if(qtdUnidades <= 0){
		printf("\nInsira um valor válido! \n");
		return 0;
	}
	
	
	veiculos[qtd].qtdUnidades = qtdUnidades;
	
	veiculos[qtd].qtdAlugada = 0;
	
	printf("\nVeiculo cadastrado com sucesso!\n");
	return 1;
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
