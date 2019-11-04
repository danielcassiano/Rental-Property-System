#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX_ARRAY 100

extern void ListaImoveis();

typedef struct {
	char rua[MAX_ARRAY];
	int num;
	char bairro[MAX_ARRAY];
	char cidade[MAX_ARRAY];
	char cep[15];
	int ativo;

} tendereco;

typedef struct {
	char aouv; //área ou valor
	char titulo[MAX_ARRAY];
	int areaTerreno, areaConstruida, numQuartos, numPavimentos;
	int valor;
    int ativo;
	tendereco endereco;

} tcasa;

typedef struct {
	char aouv; //área ou valor
	char titulo[MAX_ARRAY];
	char posicao[MAX_ARRAY];
	int area, numQuartos, numVagasG, andar;
	int valor, valorCond;
	int ativo;
	tendereco endereco;

} tapt;

typedef struct {
	char aouv; //área ou valor
	char titulo[MAX_ARRAY];
	int area;
	int valor;
    int ativo;
	tendereco endereco;

} tterreno;

void ImprimeTerreno(tterreno *pTerreno){
    printf("\t\t%s\n", pTerreno->titulo);
    printf("\tÁrea: %d\n", pTerreno->area);
    printf("\tValor: %d\n", pTerreno->valor);
    if(pTerreno->aouv == 'a'){
    printf("\tDisponível para aluguel\n");
    }else{
    printf("\tDisponível para venda\n");
    }
    printf("\n\tEndereço:\n");
    printf("\tRua: %s", pTerreno->endereco.rua);
    printf("\tNúmero: %d\n\n", pTerreno->endereco.num);
    printf("\tCidade: %s", pTerreno->endereco.cidade);
    printf("\tBairro: %s", pTerreno->endereco.bairro);
    printf("\tCEP: %s\n\n", pTerreno->endereco.cep);
}

void ImprimeCasa(tcasa *pCasa){
    printf("\t\t%s\n", pCasa->titulo);
    printf("\tValor: %d\n", pCasa->valor);
    printf("\tÁrea do terreno: %d\n", pCasa->areaTerreno);
    printf("\tÁrea construída: %d\n", pCasa->areaConstruida);
    printf("\tNúmero de quartos: %d\n", pCasa->numQuartos);
    printf("\tNúmero de pavimentos: %d\n", pCasa->numPavimentos);
    if(pCasa->aouv == 'a'){
    printf("\tDisponível para aluguel\n");
    }else{
    printf("\tDisponível para venda\n");
    }
    printf("\n\tEndereço:\n");
    printf("\tRua: %s", pCasa->endereco.rua);
    printf("\tNúmero: %d\n\n", pCasa->endereco.num);
    printf("\tCidade: %s", pCasa->endereco.cidade);
    printf("\tBairro: %s", pCasa->endereco.bairro);
    printf("\tCEP: %s\n\n", pCasa->endereco.cep);
}

void ImprimeApt(tapt *pApt){
    printf("\t\t%s\n", pApt->titulo);
    printf("\tValor: %d\n", pApt->valor);
    printf("\tValor do condomínio: %d\n", pApt->valorCond);
    printf("\tÁrea: %d\n", pApt->area);
    printf("\tAndar: %d\n", pApt->andar);
    printf("\tNúmero de quartos: %d\n", pApt->numQuartos);
    printf("\tNúmero de vagas na garagem: %d\n", pApt->numVagasG);
    printf("\tPosição do apartamento: %s", pApt->posicao);
    if(pApt->aouv == 'a'){
    printf("\tDisponível para aluguel\n");
    }else{
    printf("\tDisponível para venda\n");
    }
    printf("\n\tEndereço:\n");
    printf("\tRua: %s", pApt->endereco.rua);
    printf("\tNúmero: %d\n\n", pApt->endereco.num);
    printf("\tCidade: %s", pApt->endereco.cidade);
    printf("\tBairro: %s", pApt->endereco.bairro);
    printf("\tCEP: %s\n\n", pApt->endereco.cep);
}

int main(void) {

    setlocale(LC_ALL, "Portuguese");
    //int ativo = 1;
	char crud = '.', tipoImovel; //crud = create, read, update and delete
	/*declaração de arrays com suas respectivas variáveis a seguir.*/
	tterreno terrenos[MAX_ARRAY];
	tcasa casas[MAX_ARRAY];
	tapt apts[MAX_ARRAY];
	int i, selecaoUpdate;
	char tituloBuscado[100];

	//for para ativar todos os imóveis
    int j, k, igual[3];
    for (j = 0; j< MAX_ARRAY; j++){
    terrenos[j].ativo = 0;
    casas[j].ativo = 0;
    apts[j].ativo = 0;
    }

	while(crud != 's' && crud != 'S'){

        printf("Seja bem-vindo(a) ao simulador de imobiliária!\n\n"
        "C. CADASTRAR IMÓVEIS\n"
		"R. VISUALIZAR IMÓVEIS\n"
		"U. ATUALIZAR IMÓVEIS\n"
		"D. DELETAR IMÓVEIS\n"
		"S. SAIR\n\n");
        scanf("%c%*c", &crud);

        switch (crud) {

                //CREATE-----------------------------------------------------------------------------------------------------------------------------------------------------------

            case 'c':
            case 'C': //create

            printf("O que você deseja cadastrar?\n\n"
                   "T. TERRENO\n"
                   "C. CASA\n"
                   "A. APARTAMENTO\n");

            scanf("%c", &tipoImovel);

            switch (tipoImovel){

            case 't':
            case 'T': //terreno
                for (i = 0; i < MAX_ARRAY; i++) {
                    if (terrenos[i].titulo[0] == '\0') //caso encontre algum terreno sem nenhum caracter, pare.
                        break;
                }

                printf("Por favor, digite a área do terreno.\n");
                scanf("%d%*c", &terrenos[i].area);
                printf("Por favor, digite o valor do terreno.\n");
                scanf("%d%*c", &terrenos[i].valor);
                puts("Por favor, digite o título do anúncio do terreno.");
                fgets(terrenos[i].titulo, MAX_ARRAY, stdin);
                puts("O terreno está para aluguel(a), ou para venda(v)?.");
                scanf("%c%*c", &terrenos[i].aouv);
                printf("Por favor, digite a cidade do terreno.\n");
                fgets(terrenos[i].endereco.cidade, MAX_ARRAY, stdin);
                printf("Por favor, digite o bairro do terreno.\n");
                fgets(terrenos[i].endereco.bairro, MAX_ARRAY, stdin);
                printf("Por favor, digite a rua do terreno.\n");
                fgets(terrenos[i].endereco.rua, MAX_ARRAY, stdin);
                printf("Por favor, digite o número do terreno na rua.\n");
                scanf("%d%*c", &terrenos[i].endereco.num);
                printf("Por favor, digite o CEP do terreno.");
                fgets(terrenos[i].endereco.cep, MAX_ARRAY, stdin);
                terrenos[i].ativo = 1;
                printf("\n\n%s foi cadastrado com sucesso!\n\n", terrenos[i].titulo);

                break;

            case 'c': //casas
            case 'C':

                for (i = 0; i < MAX_ARRAY; i++) {
                    if (casas[i].titulo[0] == '\0')
                        break;
                }

                puts("Digite a área do terreno:");
                scanf("%d%*c", &casas[i].areaTerreno);
                puts("Digite a área construida:");
                scanf("%d%*c", &casas[i].areaConstruida);
                puts("Digite o número de quartos:");
                scanf("%d%*c", &casas[i].numQuartos);
                puts("Digite o número de pavimentos:");
                scanf("%d%*c", &casas[i].numPavimentos);
                puts("Digite o valor da casa:");
                scanf("%d%*c", &casas[i].valor);
                puts("A casa está disponível para aluguel(a) ou venda(v)?.");
                scanf("%c%*c", &casas[i].aouv);
                puts("Por favor, digite o titulo do anuncio da casa.");
                fgets(casas[i].titulo, MAX_ARRAY, stdin);
                printf("Por favor, digite a cidade da casa.\n");
                fgets(casas[i].endereco.cidade, MAX_ARRAY, stdin);
                printf("Por favor, digite o bairro da casa.\n");
                fgets(casas[i].endereco.bairro, MAX_ARRAY, stdin);
                printf("Por favor, digite a rua da casa.\n");
                fgets(casas[i].endereco.rua, MAX_ARRAY, stdin);
                printf("Por favor, digite o número da casa na rua.\n");
                scanf("%d%*c", &casas[i].endereco.num);
                printf("Por favor, digite o CEP da casa.");
                fgets(casas[i].endereco.cep, MAX_ARRAY, stdin);
                printf("\n\n%s foi cadastrado com sucesso!\n\n", casas[i].titulo);
                casas[i].ativo = 1;

                break;

            case 'a': //apartamentos
            case 'A':

                for (i = 0; i < MAX_ARRAY; i++) {
                    if (apts[i].titulo[0] == '\0')
                        break;
                }

                puts("Por favor, digite o andar do apartamento:");
                scanf("%d%*c", &apts[i].andar);
                puts("Por favor, digite a área do apartamento:");
                scanf("%d%*c", &apts[i].area);
                puts("Por favor, digite o número de quartos do apartamento:");
                scanf("%d%*c", &apts[i].numQuartos);
                puts("Por favor, digite o número de vagas de garagem do apartamento:");
                scanf("%d%*c", &apts[i].numVagasG);
                puts("Por favor, digite o preço do condomínio:");
                scanf("%d%*c", &apts[i].valorCond);
                puts("Por favor, digite o valor do imóvel:");
                scanf("%d%*c", &apts[i].valor);
                puts("O apartamento está disponível para aluguel(a) ou para venda(v)?:");
                scanf("%c%*c", &apts[i].aouv);
                puts("Por favor, digite o titulo do anuncio do apartamento.");
                fgets(apts[i].titulo, MAX_ARRAY, stdin);
                printf("Por favor, digite a cidade do apartamento.\n");
                fgets(apts[i].endereco.cidade, MAX_ARRAY, stdin);
                printf("Por favor, digite o bairro do apartamento.\n");
                fgets(apts[i].endereco.bairro, MAX_ARRAY, stdin);
                printf("Por favor, digite a rua do apartamento.\n");
                fgets(apts[i].endereco.rua, MAX_ARRAY, stdin);
                printf("Por favor, digite o número do apartamento na rua.\n");
                scanf("%d%*c", &apts[i].endereco.num);
                printf("Por favor, digite o CEP do apartamento\n.");
                fgets(apts[i].endereco.cep, MAX_ARRAY, stdin);
                puts("Por favor, digite a posição do apartamento");
                fgets(apts[i].posicao, MAX_ARRAY, stdin);
                apts[i].ativo = 1;
                printf("\n\n%s foi cadastrado com sucesso!\n\n", apts[i].titulo);
                break;

            }

            break;

            //UPDATE-----------------------------------------------------------------------------------------------------------------------------------------------------------

        case 'u':
        case 'U': //update
            printf("Voce deseja atualizar um terreno(t), uma casa(c) ou um apartamento(a)?\n");
            scanf("%c%*c", &tipoImovel);
            switch (tipoImovel) {
            case 't': //terreno
            case 'T':

                for (i = 0; i < MAX_ARRAY; i++) {
                    if (terrenos[i].titulo[0] == '\0')
                        break;
                    printf("Selecione o terreno que voce deseja atualizar\n");
                                        if (terrenos[i].ativo != 0){
                    printf("(%d): %s\n", i + 1, terrenos[i].titulo);
                        }
                    }

                scanf("%d%*c", &selecaoUpdate);
                selecaoUpdate--;

                puts("Por favor, digite a nova área do terreno:");
                scanf("%d%*c", &terrenos[selecaoUpdate].area);
                puts("Por favor, digite o novo valor do terreno:");
                scanf("%d%*c", &terrenos[selecaoUpdate].valor);
                puts("O terreno está disponível para aluguel ou para venda?:");
                scanf("%c%*c", &terrenos[selecaoUpdate].aouv);
                puts("Por favor digite o título do anúncio do terreno.");
                fgets(terrenos[selecaoUpdate].titulo, MAX_ARRAY, stdin);
                puts("Por favor, digite a rua do terreno.");
                fgets(terrenos[selecaoUpdate].endereco.rua, MAX_ARRAY, stdin);
                puts("Por favor, digite o número do terreno");
                scanf("%d%*c", &terrenos[selecaoUpdate].endereco.num);
                puts("Por favor, digite o bairro do terreno");
                fgets(terrenos[selecaoUpdate].endereco.bairro, MAX_ARRAY, stdin);
                puts("Por favor, digite a cidade do terreno");
                fgets(terrenos[selecaoUpdate].endereco.cidade, MAX_ARRAY, stdin);
                puts("Por favor, digite o CEP do terreno");
                fgets(terrenos[selecaoUpdate].endereco.cep, MAX_ARRAY, stdin);

                printf("\n\n%s foi atualizado com sucesso!\n\n", terrenos[i].titulo);
                break;

            case 'c'://casa
            case 'C':

                for (i = 0; i < MAX_ARRAY; i++) {
                    if (casas[i].titulo[0] == '\0')
                        break;
                    printf("Selecione a casa que voce deseja atualizar\n");
                    printf("(%d): %s\n", i + 1, casas[i].titulo);
                }

                scanf("%d%*c", &selecaoUpdate);
                selecaoUpdate--;

                puts("Por favor digite a área do terreno");
                scanf("%d", &casas[selecaoUpdate].areaTerreno);
                puts("Por favor digite a área construída do terreno");
                scanf("%d", &casas[selecaoUpdate].areaConstruida);
                puts("Por favor digite o número de quartos do terreno");
                scanf("%d", &casas[selecaoUpdate].numQuartos);
                puts("Por favor digite o número de pavimentos do terreno");
                scanf("%d", &casas[selecaoUpdate].numPavimentos);
                puts("Por favor digite o valor da casa do terreno");
                scanf("%d", &casas[selecaoUpdate].valor);
                puts("Está disponível para aluguel(a) ou para venda(v)?");
                scanf("%c%*c", &casas[selecaoUpdate].aouv);
                puts("Por favor digite o titulo do anuncio da casa");
                fgets(casas[i].titulo, MAX_ARRAY, stdin);
                puts("Por favor digite a rua da casa");
                fgets(casas[i].endereco.rua, MAX_ARRAY, stdin);
                puts("Por favor digite o numero da casa");
                scanf("%d%*c", &casas[i].endereco.num);
                puts("Por favor digite o bairro da casa");
                fgets(casas[i].endereco.bairro, MAX_ARRAY, stdin);
                puts("Por favor digite o cidade da casa");
                fgets(casas[i].endereco.cidade, MAX_ARRAY, stdin);
                puts("Por favor digite o CEP da casa");
                fgets(casas[i].endereco.cep, MAX_ARRAY, stdin);
                printf("\n\n%s foi cadastrado com sucesso!\n\n", casas[i].titulo);

                break;

            case 'a'://apartamento
            case 'A':

                for (i = 0; i < MAX_ARRAY; i++) {
                    if (apts
                        [i].titulo[0] == '\0')
                        break;
                    printf("Selecione o apartamento que voce deseja atualizar\n");
                    printf("(%d): %s\n", i + 1, apts[i].titulo);

                }

                scanf("%d%*c", &selecaoUpdate);
                selecaoUpdate--;
                printf("Por favor, digite o andar do apartamento.\n");
                scanf("%d", &apts[selecaoUpdate].andar);
                printf("Por favor, digite a área do apartamento.\n");
                scanf("%d", &apts[selecaoUpdate].area);
                printf("Por favor, digite o número de quartos do apartamento.\n");
                scanf("%d", &apts[selecaoUpdate].numQuartos);
                printf("Por favor, digite o número de vagas na garagem do apartamento.\n");
                scanf("%d", &apts[selecaoUpdate].numVagasG);
                printf("Por favor, digite o valor do condomínio do apartamento.\n");
                scanf("%d", &apts[selecaoUpdate].valorCond);
                printf("Por favor, digite o valor do apartamento.\n");
                scanf("%d", &apts[selecaoUpdate].valor);
                printf("O apartamento está para alugar(a) ou vender(v)?.\n");
                scanf("%d", &apts[selecaoUpdate].aouv);
                printf("Por favor digite o titulo do anuncio do apartamento.\n");
                fgets(apts[i].titulo, MAX_ARRAY, stdin);
                printf("Por favor digite a posicao do apartamento.\n");
                fgets(apts[i].posicao, MAX_ARRAY, stdin);
                printf("Por favor digite a rua do apartamento.\n");
                fgets(apts[i].endereco.rua, MAX_ARRAY, stdin);
                printf("Por favor digite o bairro do apartamento.\n");
                fgets(apts[i].endereco.bairro, MAX_ARRAY, stdin);
                printf("Por favor digite o número do apartamento.\n");
                scanf("%d%*c", &apts[i].endereco.num);
                printf("Por favor digite a cidade do apartamento.\n");
                fgets(apts[i].endereco.cidade, MAX_ARRAY, stdin);
                printf("Por favor digite o CEP do apartamento.\n");
                printf("\n\n%s foi cadastrado com sucesso!\n\n", apts[i].titulo);
                break;

                default:
                puts("Por favor, digite outra letra.");
            }

//READ------------------------------------------------------------------------------------------------------------------------------------------

        char tipoRead;
        int valorBuscado;
        char alugOuVenda;
        case 'r':
        case 'R':

            printf("\tSelecione de que forma você quer ver os imoveis cadastrados:\n");
            printf("1) Mostrar todos os imóveis\n");
            printf("2) Mostrar os imóveis a partir de um preço\n");
            printf("3) Mostrar os imóveis para aluguel ou para venda\n");
            printf("4) Buscar um imóvel por título\n");
            printf("5) Buscar um imóvel por bairro\n");

            scanf("%d%*c", &tipoRead);

            system("cls");

            switch(tipoRead){
            case 2:
                printf("Selecione o valor mínimo dos imóveis buscados: ");
                scanf("%d%*c", &valorBuscado);
            break;

            case 3:
                printf("Selecione se você deseja ver os imóveis disponíveis para aluguel ou para venda (a ou v):");
                scanf("%c%*c", &alugOuVenda);
            break;

            case 4:
                printf("Digite o título do imóvel que você deseja procurar:\n");
                fgets(tituloBuscado, 100, stdin);
            break;

            case 5:
                printf("Digite o título do bairro que você deseja procurar os imóveis:\n");
                fgets(tituloBuscado, 100, stdin);
            break;
            }

            printf("\n\tTERRENOS\n\n");

                for(i = 0, j = 0; i < MAX_ARRAY; i++, j++){
                    if(terrenos[i].titulo[0] == '\0')
                    break;

                    printf("\n");

                    if(!terrenos[i].ativo){
                        j--;
                        continue;
                        //Em caso de imoveis deletados
                    }
                    switch(tipoRead){
                    case 1:
                        ImprimeTerreno(&terrenos[j]);
                    break;

                    case 2:
                        if(terrenos[j].valor >= valorBuscado){
                            ImprimeTerreno(&terrenos[j]);
                        }else{
                            i--;
                        }
                    break;

                    case 3:
                        if(terrenos[j].aouv == alugOuVenda){
                            ImprimeTerreno(&terrenos[j]);
                        }else{
                            i--;
                        }
                    break;

                    case 4:
                        igual[0] = 1;
                        for(k = 0; tituloBuscado[k] != '\0'; k++){
                            if(tituloBuscado[k] != terrenos[j].titulo[k]){
                                igual[0] = 0;
                                break;
                            }
                        }

                        if(igual[0]){
                            ImprimeTerreno(&terrenos[j]);
                        }

                    break;

                    case 5:
                        igual[0] = 1;
                        for(k = 0; tituloBuscado[k] != '\0'; k++){
                            if(tituloBuscado[k] != terrenos[j].endereco.bairro[k]){
                                igual[0] = 0;
                                break;
                            }
                        }

                        if(igual[0]){
                            ImprimeTerreno(&terrenos[j]);
                        }

                    break;
                }
            }

            printf("\n\tCASAS\n\n");

                for(i = 0, j = 0; i < MAX_ARRAY; i++, j++){
                    if(casas[i].titulo[0] == '\0')
                    break;

                    printf("\n");

                    if(!casas[i].ativo){
                        j--;
                        continue;
                        //Em caso de imoveis deletados
                    }
                    switch(tipoRead){
                    case 1:
                        ImprimeCasa(&casas[j]);
                    break;

                    case 2:
                        if(casas[j].valor >= valorBuscado){
                            ImprimeCasa(&casas[j]);
                        }else{
                            i--;
                        }
                    break;

                    case 3:
                        if(casas[j].aouv == alugOuVenda){
                            ImprimeCasa(&casas[j]);
                        }else{
                            i--;
                        }
                    break;

                    case 4:
                        igual[1] = 1;
                        for(k = 0; tituloBuscado[k] != '\0'; k++){
                            if(tituloBuscado[k] != casas[j].titulo[k]){
                                igual[1] = 0;
                                break;
                            }
                        }

                        if(igual[1]){
                            ImprimeCasa(&casas[j]);
                        }

                    break;

                    case 5:
                        igual[1] = 1;
                        for(k = 0; tituloBuscado[k] != '\0'; k++){
                            if(tituloBuscado[k] != casas[j].endereco.bairro[k]){
                                igual[1] = 0;
                                break;
                            }
                        }

                        if(igual[1]){
                            ImprimeCasa(&casas[j]);
                        }

                    break;

                    }
                }

            printf("\n\tAPARTAMENTOS\n\n");

                for(i = 0, j = 0; i < MAX_ARRAY; i++, j++){
                    if(apts[i].titulo[0] == '\0')
                    break;

                    printf("\n");

                    if(!apts[i].ativo){
                        j--;
                        continue;
                        //Em caso de imoveis deletados
                    }
                    switch(tipoRead){
                    case 1:
                        ImprimeApt(&apts[j]);
                    break;

                    case 2:
                        if(apts[j].valor >= valorBuscado){
                            ImprimeApt(&apts[j]);
                        }else{
                            i--;
                        }
                    break;

                    case 3:
                        if(apts[j].aouv == alugOuVenda){
                            ImprimeApt(&apts[j]);
                        }else{
                            i--;
                        }
                    break;

                    case 4:
                        igual[2] = 1;
                        for(k = 0; tituloBuscado[k] != '\0'; k++){
                            if(tituloBuscado[k] != apts[j].titulo[k]){
                                igual[2] = 0;
                                break;
                            }
                        }

                        if(igual[2]){
                            ImprimeApt(&apts[j]);
                        }

                    break;

                    case 5:
                        igual[2] = 1;
                        for(k = 0; tituloBuscado[k] != '\0'; k++){
                            if(tituloBuscado[k] != apts[j].endereco.bairro[k]){
                                igual[2] = 0;
                                break;
                            }
                        }

                        if(igual[2]){
                            ImprimeApt(&apts[j]);
                        }

                    break;

                    }
                }

            break;

        //FUNÇÃO PARA REMOVER UM DETERMINADO IMÓVEL
            case 'd': //delete
            case 'D':
                printf("Voce deseja deletar um terreno(t), uma casa(c) ou um apartamento(a)?\n");
                scanf("%c%*c", &tipoImovel);
                switch (tipoImovel) {
                case 't': //terreno
                case 'T':

                    puts("Digite o numero do terreno que voce deseja deletar:\n");

                    int numeroterreno;

                    for (i = 0; i < MAX_ARRAY; i++) {
                    if (terrenos[i].titulo[0] == '\0')
                        break;
                    printf("Selecione o terreno que voce deseja deletar:\n");
                    if (terrenos[i].ativo != 0){
                    printf("(%d): %s\n", i + 1, terrenos[i].titulo);
                        }
                    scanf("%d%*c", &numeroterreno+1);
                    terrenos[numeroterreno].ativo = 0;
                    puts("Terreno deletado com sucesso.");
                    break;
                    }
                    break;

                case 'c': //casa
                case 'C':

                    puts("Digite o numero da casa que voce deseja deletar:");

                    int numerocasa;

                    for (i = 0; i < MAX_ARRAY; i++) {
                    if (casas[i].titulo[0] == '\0')
                        break;
                    printf("Selecione o terreno que voce deseja deletar:\n");
                    if (casas[i].ativo != 0){
                    printf("(%d): %s\n", i + 1, casas[i].titulo);
                        }
                    scanf("%d%*c", &numerocasa+1);
                    casas[numerocasa].ativo = 0;
                    puts("Casa deletada com sucesso.");
                    break;
                    }
                    break;

                case 'a': //apartamento
                case 'A':

                    puts("Digite o numero do apartamento que voce deseja deletar:");

                    int numeroapt;

                    for (i = 0; i < MAX_ARRAY; i++) {
                    if (apts[i].titulo[0] == '\0')
                        break;
                    printf("Selecione o terreno que voce deseja deletar:\n");
                    if (apts[i].ativo != 0){
                    printf("(%d): %s\n", i + 1, apts[i].titulo);
                        }
                    scanf("%d%*c", &numeroapt+1);
                    apts[numeroapt].ativo = 0;
                    puts("Apartamento deletado com sucesso.");
                    break;
                    }
                    break;
                }
            }
        }


FILE *fp;
fp = fopen("file1.txt", "a");
if (!fp){
        puts("Erro ao abrir FP.");
        return 1;
    }


    for(int i = 0; i < casas[i].titulo[0] == '\0' ; i++){
            fprintf(fp, "%s\n", casas[i].aouv);
            fprintf(fp, "%s\n", casas[i].titulo);
            fprintf(fp, "%d\n", casas[i].areaTerreno);
            fprintf(fp, "%d\n", casas[i].areaConstruida);
            fprintf(fp, "%d\n", casas[i].numQuartos);
            fprintf(fp, "%d\n", casas[i].numPavimentos);
            fprintf(fp, "%d\n", casas[i].valor);
            fprintf(fp, "%s\n", casas[i].ativo);
            fprintf(fp, "%s\n", casas[i].endereco.rua);
            fprintf(fp, "%s\n", casas[i].endereco.num);
            fprintf(fp, "%s\n", casas[i].endereco.bairro);
            fprintf(fp, "%s\n", casas[i].endereco.cidade);
            fprintf(fp, "%s\n", casas[i].endereco.cep);
            fprintf(fp, "%s\n", casas[i].endereco.ativo);
        }



        for(int i = 0; i < apts[i].titulo[0] == '\0'; i++){
            fprintf(fp, "%s\n", apts[i].aouv);
            fprintf(fp, "%s\n", apts[i].titulo);
            fprintf(fp, "%d\n", apts[i].area);
            fprintf(fp, "%d\n", apts[i].valor);
            fprintf(fp, "%s\n", apts[i].ativo);
            fprintf(fp, "%s\n", apts[i].endereco.rua);
            fprintf(fp, "%d\n", apts[i].endereco.num);
            fprintf(fp, "%s\n", apts[i].endereco.bairro);
            fprintf(fp, "%s\n", apts[i].endereco.cidade);
            fprintf(fp, "%s\n", apts[i].endereco.cep);
            fprintf(fp, "%s\n", apts[i].endereco.ativo);
        }



        for(int i = 0; i < terrenos[i].titulo[0] == '\0' ; i++){
            fprintf(fp, "%s\n", terrenos[i].titulo);
            fprintf(fp, "%s\n", terrenos[i].aouv);
            fprintf(fp, "%s\n", terrenos[i].valor);
            fprintf(fp, "%d\n", terrenos[i].area);
            fprintf(fp, "%s\n", terrenos[i].ativo);
            fprintf(fp, "%s\n", terrenos[i].endereco.rua);
            fprintf(fp, "%d\n", terrenos[i].endereco.num);
            fprintf(fp, "%s\n", terrenos[i].endereco.bairro);
            fprintf(fp, "%s\n", terrenos[i].endereco.cidade);
            fprintf(fp, "%s\n", terrenos[i].endereco.cep);
            fprintf(fp, "%s\n", terrenos[i].endereco.ativo);
        }

fclose(fp);

return 0;} // final da main
/*
char cat = '.';
scanf("%c%*c", cat);
void vendertipo(){ // Uma função que retorna todos os imóveis disponíveis para vender por tipo (casa, apartamento, terreno);
    switch(cat){
        case 'c':{
        for(int i = 0; i<MAX_ARRAY; i++){
            if(casas[i].aouv == 'v'){
                printf(casas[i].titulo);
                }
            }
        break;
        }
        case 'a':{
        for(int i = 0; i<MAX_ARRAY; i++){
            if(apts[i].aouv == 'v'){
                printf(apts[i].titulo);
                }
            }
        break;
        }
        case 't':{
        for(int i = 0; i<MAX_ARRAY; i++){
            if(terrenos[i].aouv == 'v'){
                printf(terrenos[i].titulo);
                }
            }
        break;
        }
        default:
        puts("Opção inválida");
    return;
    }
}
void alugartipo(){ // Uma função que retorna todos os imóveis disponíveis para alugar por tipo (casa, apartamento, terreno);
    switch(cat){
        case 'c':{
        for(int i = 0; i<MAX_ARRAY; i++){
            if(casas[i].aouv == 'a'){
                printf(casas[i].titulo);
                }
            }
        break;
        }
        case 'a':{
        for(int i = 0; i<MAX_ARRAY; i++){
            if(apts[i].aouv == 'a'){
                printf(apts[i].titulo);
                }
            }
        break;
        }
        case 't':{
        for(int i = 0; i<MAX_ARRAY; i++){
            if(terrenos[i].aouv == 'a'){
                printf(terrenos[i].titulo);
                }
            }
        break;
        }
        default:
        puts("Opção inválida");
    return;
    }
}*/


//FUNCAO LISTA DE IMÓVEIS DISPONÍVEIS


/*
void ListaImovei s(){
puts("Esta é a lista de imóveis cadastrados em nossa imobiliária");
int auxt = 2;
int auxc = 2;
int auxa = 2;
        for (int i = 0; i < MAX_ARRAY; i++) {
            if (terrenos[i].titulo[0] == '\0'){ //caso encontre algum terreno sem nenhum caracter
                auxt = 1;}
                if (auxt > 1){
                    if (terrenos[i].ativo == 1){
                printf("%d%*c", terrenos[i].titulo);
                    }
                }
            else if(casas[i].titulo[0] == '\0'){
                auxc = 1;
                if (auxc > 1){
                    if (casas[i].ativo == 1){
                    printf("%d%*c", casas[i].titulo);
                }
            }
        }
            else if(apts[i].titulo[0] == '\0'){
                auxc = 1;
                if (auxa > 1){
                    if (apts[i].ativo == 1){
                printf("%d%*c", apts[i].titulo);
                }
            }
        }
}
*/
