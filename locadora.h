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

void cadastraCategoria();
void exibieCategoria();
void cadastraVeiculo();
void exibirRelacao();
void realizarAluguel();
void realizarDevolucao();
void exibirVeiculosAlugadosCategoria();
void exibirTodosVeiculoAlugadoPorCategoria();
void exibirLocacoesAbertasGeral();
