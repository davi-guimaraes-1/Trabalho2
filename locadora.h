#ifndef LOCADORA_H
#define LOCADORA_H
#define MAX_LOCACOES 1000
#define MAX_CATEGORIAS 10
#define MAX_VEICULOS 100
#endif

typedef struct {
	int dia;
	int mes;
	int ano;
} data;
	
typedef struct {
	int codigoCategoria;
	char nome[20];
} categoria;
	
typedef struct {
	 char codigoVeiculo[30];
	 char marca[20];
	 char modelo[40];
	 int categoria;
	 int ano;
	 float diaria;
	 int qtdUnidades;
	 int qtdAlugada;
} veiculo;
	
typedef struct {
	int numero;
	char codigoVeiculo[30];
	data dataRetirada;
	data dataPrevistaDevolucao;
	data dataDevolucao;
	int status;
	float diariaAtrasoContrato;
	float valorPrevisto;
	float valorPago;
} locacao;

int cadastraCategoria(categoria categorias[], int qtd);
void exibirCategoria(categoria categorias[], int qtd);
int cadastraVeiculo(veiculo veiculos[], int qtd, categoria categorias[], int qtdCat);
void exibirRelacao(veiculo veiculos[], categoria categorias[], int qtdVeic, int qtdCat);
void realizarAluguel();
void realizarDevolucao();
void exibirVeiculosAlugadosCategoria();
void exibirTodosVeiculoAlugadoPorCategoria();
void exibirLocacoesAbertasGeral();
void limpaBuffer();
int buscaCategoria(categoria categorias[], int qtd, int codigo);
