#include <stdio.h>
#include <locale.h>

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int select, i;
	
	
	do{
	printf(
	"======================================================\n"
	" >SELECIONE UMA DAS OPÇÕES ABAIXO PARA PROSSEGUIR<\n"
	"\n\n 0) SAIR DA APLICAÇÃO" 
	"1) CADASTRAR CATEGORIA."
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
			
		case 2:
			
		case 3:
			
		case 4:
			
		case 5:
			
		case 6:
			
		case 7:
			
		case 8:
		
		case 9:
			
		default : 
			printf("\n\Opção inválida!\n\n");
			i--;
			continue;
		
	}
	
	}while(i != 0);
	return 0;
}
