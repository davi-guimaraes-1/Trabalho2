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

veiculo veiculos[MAX_VEICULOS];//vetor de veículos (máx. 100)
categoria categorias[MAX_CATEGORIAS];//vetor de categorias (máx. 10)
locacao locacoes[MAX_LOCACOES];//vetor de locações (máx. 1000)

int cadastraCategoria(int qtd);
void exibirCategoria(int qtd);
int cadastraVeiculo(int qtd, int qtdCat);
void exibirRelacao(int qtdVeic, int qtdCat);
void realizarAluguel();
void realizarDevolucao();
void exibirVeiculosAlugadosCategoria();
void exibirTodosVeiculoAlugadoPorCategoria();
void exibirLocacoesAbertasGeral();
void limpaBuffer();
int buscaCategoria(int qtd, int codigo);
