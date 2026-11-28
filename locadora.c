#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "locadora.h"


void limpaBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int cadastraCategoria(int qtd) {
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
		limpaBuffer();
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

void exibirCategoria(int qtd) {
	int i;
	for (i = 0; i < qtd; i++){//simplesmente o qtd que é passado com a quantidade qtdCat no main, conta quanto numero de categorias foi inserido o codigo e exibe cada dado em relação a cada posição
		printf("======================================================\n");
		printf("\nCodigo da categoria: %d\n", categorias[i].codigoCategoria);
		printf("\nNome da categoria: %s\n", categorias[i].nome);
		printf("======================================================\n");
	}
}

int cadastraVeiculo(int qtd, int qtdCat) {
	//vetores auxiliares para caso haja erro não passe valores errados ao struct
	char codigo[30];
	char marca[20];
	char modelo[40];
	int codCategoria, ano, qtdUnidades;
	int i;
	float diaria;
	int pos;
	char resp;

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
	limpaBuffer();

	for (i = 0; i < qtd; i++) {
		if (strcmp(veiculos[i].codigoVeiculo, codigo) == 0) {//verifica se o codigo informado pelo usuario não está repetido 
			printf("\nO codigo do veiculo está repetido!\n");
			return 0;
		}
	}
	
	printf("Informe a marca do veiculo: ");
	if(scanf(" %19[^\n]", marca) != 1){//verifica se houve erro no scanf
		printf("\nErro ao digitar a marca!\n");
		limpaBuffer();//limpabuffer caso ocorra um erro
		return 0; 
	}
	limpaBuffer();//limpa buffer para previnir erros

	
	printf("Digite o modelo do veiculo: ");
	if(scanf(" %39[^\n]", modelo) != 1){
		printf("\nErro ao cadastrar o modelo!\n");
		limpaBuffer();
		return 0;
	}
	limpaBuffer();
	
	printf("\nDigite a categoria veiculo cadastrado: \n");
	if(scanf("%d", &codCategoria) != 1){
		printf("Erro ao cadastrar categoria!");
		limpaBuffer();		
		return 0;
	}
	limpaBuffer();
	pos = buscaCategoria(qtdCat, codCategoria);
	if(pos ==  -1){
		printf("Categoria não cadastrada!\n");
		return 0;
	}
	printf("\nCategoria encontrada: %s\n", categorias[pos].nome);//pos é a posição, por isso dá pra pegar o nome
	printf("Confirma? (S/N): ");
	if (scanf(" %c", &resp) != 1) {
		limpaBuffer();
		return 0;
	}
	limpaBuffer();
	if (resp != 'S' && resp != 's') {
		printf("\nCadastro cancelado.\n");
		return 0;
	}
	
	printf("Digite o ano do veiculo: ");
	if(scanf("%d", &ano) != 1){
		printf("\nErro ao cadastrar ano do veiculo!\n");
		limpaBuffer();
		return 0;
	} 
	limpaBuffer();
	if(ano < 1980 || ano > 2026){
		printf("\nAno invalido!\n");
		return 0;
	}
	
	printf("\nInforme a diaria do veiculo: \n");
	if(scanf("%f", &diaria) != 1){
		printf("\nErro ao cadastrar a diaria!\n");
		limpaBuffer();
		return 0;
	}
	limpaBuffer();

	if (diaria <= 0) {
		printf("\nA diaria deve ser maior que zero!\n");
		return 0;
	}
	
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
	
	strcpy(veiculos[qtd].codigoVeiculo, codigo);//função da biblioteca string que nos possiblita atribuir o valor de codigo para veiculos[qtd].codigoVeiculo
	strcpy(veiculos[qtd].marca, marca);//função da biblioteca string que nos possiblita atribuir o valor de marca para veiculos[qtd].marca	
	strcpy(veiculos[qtd].modelo, modelo);
	veiculos[qtd].categoria = codCategoria;
	veiculos[qtd].ano = ano;
	veiculos[qtd].diaria = diaria;
	veiculos[qtd].qtdUnidades = qtdUnidades;
	veiculos[qtd].qtdAlugada = 0;
	
	printf("\nVeiculo cadastrado com sucesso!");
	return 1;
}

	
void exibirRelacao(int qtdVeic, int qtdCat){
	int i, posCat;

	if (qtdVeic == 0) {
		printf("\nNão há veículos cadastrados!\n");
		return;
	}
	
	for (i = 0; i < qtdVeic; i++) {
		posCat = buscaCategoria(qtdCat, veiculos[i].categoria);
		
		if (posCat != -1) {
			printf("Nome da categoria: %s\n", categorias[posCat].nome);
		} else {
			printf("Nome da categoria: Não encontrada\n");
		}
		
		printf("======================================================\n");
		printf("Código do veículo: %s\n", veiculos[i].codigoVeiculo);
		printf("Marca: %s\n", veiculos[i].marca);
		printf("Modelo: %s\n", veiculos[i].modelo);
		printf("Ano: %d\n", veiculos[i].ano);
		printf("Valor da diária: R$ %.2f\n", veiculos[i].diaria);
		printf("Quantidade total de unidades: %d\n", veiculos[i].qtdUnidades);
		printf("Quantidade atualmente alugada: %d\n", veiculos[i].qtdAlugada);
		printf("======================================================\n");
	}
}


int realizarAluguel(int qtdLoc, int qtdVeic, int qtdCat) {
	char codigo[30], resp;
	int posVeic, posCat, diasContratados;
	data retirada, prevista;
	float diariaAtraso, valorPrevisto;

	if (qtdLoc >= MAX_LOCACOES) {
		printf("\nNúmero máximo de locações atingido!\n");
		return 0;
	}

	if (qtdVeic == 0) {
		printf("\nNão há veículos cadastrados na frota!\n");
		return 0;
	}

	printf("Informe o código do veículo: ");
	if (scanf(" %29[^\n]", codigo) != 1) {
		printf("\nErro ao ler o código do veículo!\n");
		limpaBuffer();
		return 0;
	}
	limpaBuffer();

	// Localiza o veículo na frota
	posVeic = buscaVeiculo(qtdVeic, codigo);
	if (posVeic == -1) {
		printf("\nVeículo não encontrado!\n");
		return 0;
	}

	// Exibe os dados do veículo para confirmação do usuário
	posCat = buscaCategoria(qtdCat, veiculos[posVeic].categoria);
	printf("\n--- DADOS DO VEÍCULO ---\n");
	printf("Marca/Modelo: %s %s (%d)\n", veiculos[posVeic].marca, veiculos[posVeic].modelo, veiculos[posVeic].ano);
	if (posCat != -1) {
		printf("Categoria: %s\n", categorias[posCat].nome);
	}
	printf("Diária padrão: R$ %.2f\n", veiculos[posVeic].diaria);
	printf("Disponíveis: %d de %d\n", veiculos[posVeic].qtdUnidades - veiculos[posVeic].qtdAlugada, veiculos[posVeic].qtdUnidades);

	printf("\nConfirma o veículo para locação? (S/N): ");
	if (scanf(" %c", &resp) != 1) {
		limpaBuffer();
		return 0;
	}
	limpaBuffer();
	if (resp != 'S' && resp != 's') {
		printf("\nLocação cancelada.\n");
		return 0;
	}

	// Só permite alugar se houver unidade disponível (qtdAlugada < qtdUnidades)
	if (veiculos[posVeic].qtdAlugada >= veiculos[posVeic].qtdUnidades) {
		printf("\nIndisponível! Todas as unidades deste veículo já estão alugadas.\n");
		return 0;
	}

	// Leitura e validação da data de retirada
	printf("\nInforme a data de retirada (DD MM AAAA): ");
	if (scanf("%d %d %d", &retirada.dia, &retirada.mes, &retirada.ano) != 3 || !dataValida(retirada)) {
		printf("\nData de retirada inválida!\n");
		limpaBuffer();
		return 0;
	}
	limpaBuffer();

	// Leitura e validação da data prevista de devolução
	printf("Informe a data prevista de devolução (DD MM AAAA): ");
	if (scanf("%d %d %d", &prevista.dia, &prevista.mes, &prevista.ano) != 3 || !dataValida(prevista)) {
		printf("\nData prevista de devolução inválida!\n");
		limpaBuffer();
		return 0;
	}
	limpaBuffer();

	// Calcula a diferença em dias e valida o mínimo de 1 diária
	diasContratados = calcularDias(retirada, prevista);

	if (diasContratados < 1) {
		printf("\nErro: A data prevista de devolução deve ser posterior à retirada (mínimo de 1 diária)!\n");
		return 0;
	}

	// Leitura e validação da diária de atraso do contrato
	printf("Informe o valor da diária de atraso do contrato (R$): ");
	if (scanf("%f", &diariaAtraso) != 1 || diariaAtraso <= 0) {
		printf("\nValor inválido! A diária de atraso deve ser maior que zero.\n");
		limpaBuffer();
		return 0;
	}
	limpaBuffer();

	// Cálculos e gravação do contrato
	valorPrevisto = diasContratados * veiculos[posVeic].diaria;

	locacoes[qtdLoc].numero = qtdLoc + 1;
	strcpy(locacoes[qtdLoc].codigoVeiculo, veiculos[posVeic].codigoVeiculo);
	locacoes[qtdLoc].dataRetirada = retirada;
	locacoes[qtdLoc].dataPrevistaDevolucao = prevista;
	locacoes[qtdLoc].dataDevolucao.dia = 0;
	locacoes[qtdLoc].dataDevolucao.mes = 0;
	locacoes[qtdLoc].dataDevolucao.ano = 0;
	locacoes[qtdLoc].status = 0;
	locacoes[qtdLoc].diariaAtrasoContrato = diariaAtraso;
	locacoes[qtdLoc].valorPrevisto = valorPrevisto;
	locacoes[qtdLoc].valorPago = 0.0;

	// Incrementa a quantidade alugada do veículo
	veiculos[posVeic].qtdAlugada++;

	// Exibe o resumo da locação
	printf("\n======================================================\n");
	printf("LOCAÇÃO REALIZADA COM SUCESSO!\n");
	printf("Número do contrato: %d\n", locacoes[qtdLoc].numero);
	printf("Veículo: %s - %s %s\n", veiculos[posVeic].codigoVeiculo, veiculos[posVeic].marca, veiculos[posVeic].modelo);
	printf("Retirada: %02d/%02d/%04d\n", retirada.dia, retirada.mes, retirada.ano);
	printf("Devolução prevista: %02d/%02d/%04d (%d diária(s))\n", prevista.dia, prevista.mes, prevista.ano, diasContratados);
	printf("Valor previsto: R$ %.2f\n", valorPrevisto);
	printf("======================================================\n");

	return 1;
}

void realizarDevolucao() {
	
}

void exibirVeiculosAlugadosCategoria(int codigo, int qtd) {
	int i;
	int pos = buscaCategoria(qtd, codigo);
	
	printf("\nCategoria: %s", categorias[pos].nome);
	
	for(i = 0; i < MAX_VEICULOS; i++) {
		
		if(veiculos[i].qtdAlugada > 0) {
			
			printf("\n Código: %s", veiculos[i].codigoVeiculo);
			printf("\n Marca: %s", veiculos[i].marca);
			printf("\n Modelo: %s", veiculos[i].modelo);
			printf("\n Quantidade alugada: %d\n", veiculos[i].qtdAlugada);
		}
	}
}

void exibirTodosVeiculoAlugadoPorCategoria(int qtd) {
	int i;
	
	for(i = 0; i < qtd; i++) {
		exibirVeiculosAlugadosCategoria(i, qtd);
	}
}

void exibirLocacoesAbertasGeral() {
	
}

int buscaCategoria(int qtd, int codigo) {
	int i;
	for (i = 0; i < qtd; i++) {
		if (categorias[i].codigoCategoria == codigo) {
			return i;
		}
	}
	return -1;
}

// Busca o índice de um veículo pelo código; retorna -1 se não encontrar
int buscaVeiculo(int qtd, char codigo[]) {
	int i;
	for (i = 0; i < qtd; i++) {
		if (strcmp(veiculos[i].codigoVeiculo, codigo) == 0) {
			return i;
		}
	}
	return -1;
}

// Valida se a data existe no calendário (retorna 1 se for válida, 0 se for inválida)
int dataValida(data d) {
	int diasMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (d.ano < 2000 || d.mes < 1 || d.mes > 12 || d.dia < 1) {
		return 0;
	}
	// Se for ano bissexto, fevereiro passa a ter 29 dias
	if ((d.ano % 4 == 0 && d.ano % 100 != 0) || (d.ano % 400 == 0)) {
		diasMes[2] = 29;
	}
	if (d.dia > diasMes[d.mes]) {
		return 0;
	}
	return 1;
}

// Conta quantos dias existem entre duas datas (retorna -1 se fim for antes do inicio)
int calcularDias(data inicio, data fim) {
	int diasMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int contDias = 0;

	// Garante que a data final não seja anterior à inicial
	if (fim.ano < inicio.ano || 
	   (fim.ano == inicio.ano && fim.mes < inicio.mes) || 
	   (fim.ano == inicio.ano && fim.mes == inicio.mes && fim.dia < inicio.dia)) {
		return -1;
	}

	// Avança dia a dia da data de início até alcançar a data de fim
	while (inicio.dia != fim.dia || inicio.mes != fim.mes || inicio.ano != fim.ano) {
		inicio.dia++;
		contDias++;

		// Ajusta fevereiro se o ano atual da contagem for bissexto
		if ((inicio.ano % 4 == 0 && inicio.ano % 100 != 0) || (inicio.ano % 400 == 0)) {
			diasMes[2] = 29;
		} else {
			diasMes[2] = 28;
		}

		// Se passou do último dia do mês, vira o mês
		if (inicio.dia > diasMes[inicio.mes]) {
			inicio.dia = 1;
			inicio.mes++;
		}
		// Se passou de dezembro, vira o ano
		if (inicio.mes > 12) {
			inicio.mes = 1;
			inicio.ano++;
		}
	}
	return contDias;
}
