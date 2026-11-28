#ifndef LOCADORA_H
#define LOCADORA_H
#define MAX_LOCACOES 15
#define MAX_CATEGORIAS 3
#define MAX_VEICULOS 10
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

// Vetores principais declarados no cabeçalho
veiculo veiculos[MAX_VEICULOS];       // vetor de veículos (máx. 100)
categoria categorias[MAX_CATEGORIAS]; // vetor de categorias (máx. 10)
locacao locacoes[MAX_LOCACOES];       // vetor de locações (máx. 1000)

// Funções auxiliares
void limpaBuffer();
int buscaCategoria(int qtd, int codigo);
int buscaVeiculo(int qtd, char codigo[]);
int dataValida(data d);
int calcularDias(data inicio, data fim);

// Operações do Menu
int cadastraCategoria(int qtd); // 1
void exibirCategoria(int qtd); // 2
int cadastraVeiculo(int qtd, int qtdCat); // 3
void exibirRelacao(int qtdVeic, int qtdCat); // 4
int realizarAluguel(int qtdLoc, int qtdVeic, int qtdCat); // 5
void realizarDevolucao(int qtdLoc, int qtdVeic); // 6 
void exibirVeiculosAlugadosCategoria(char codigo[], int qtd); // 7 
void exibirTodosVeiculoAlugadoPorCategoria(int qtd); // 8
void exibirLocacoesAbertasGeral(); // 9
