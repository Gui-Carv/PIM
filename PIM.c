#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <conio.h>
#define ANSI_COLOR_WHITE "\033[1;97m"
#define ANSI_COLOR_BLACK "\033[1;30m"
#define ANSI_COLOR_RED "\033[1;91m"
#define ANSI_COLOR_BLUE "\033[1;34m"
#define ANSI_COLOR_GREEN "\033[1;32m"
#define ANSI_COLOR_YELLOW "\033[1;93m"
#define ANSI_COLOR_BACK_BLACK "\033[1;40m"

//Declaração das Estruturas a serem utilizadas

char cores[7];
char pais[20];
char cep[8];
char nome[40];
char idade[2];
char telefone[11];
char senha[12];
char modalidade[20];
char equipe[20];
char segredo[12];


//Declaração das variáveis
int input = 0;
int qtdUsers;
int tamUsers;
char users_dir[] = "Users.bin";
FILE *arquivo;

//Declaração dos Procedimentos e Funções a serem utilizados
void menuPrincipal();
void menuLogin();
void menuUsers();
void menuCad();
void menuDates();
void menuMedalhas();
void menuMedalhas2();
void menuMedalhas3();
void menuMedalhas4();
void menuMedalhas5();
void menuMedalhas6();
void menuAlterarUser();
void removerQuebraLinha();
void inserirUser();
void alterarEndereco();
void alterarNome();
void alterarTelefone();
int removerUser();
int receberUser();
int receberEndereco();

//Início do main
int main(int argc, char** argv)
{
    menuPrincipal();
    return 0;
}

void erro(char *nome_arquivo)
{
    printf("Nao foi possivel abrir o arquivo %s\n", nome_arquivo);
}

void sucesso()
{
    system("cls");
    printf ("Operacao realizada com sucesso!");
}

void menuPrincipal()
{
    system("color 07");
    printf(ANSI_COLOR_BACK_BLACK);
    printf("\n");
    printf(ANSI_COLOR_BLUE"\n\t\t\t\t\t   #######   ##       #### ##     ##"),printf(ANSI_COLOR_WHITE" ########    #######"),printf(ANSI_COLOR_RED"   #######  ##    ##  #######\n");
    printf(ANSI_COLOR_BLUE"\t\t\t\t\t  ##     ##  ##        ##  ###   ### "),printf(ANSI_COLOR_WHITE"##      #  ##     ##"),printf(ANSI_COLOR_RED" ##     ##  #    #  ##     ##\n");
    printf(ANSI_COLOR_BLUE"\t\t\t\t\t ##       ## ##        ##  #### #### "),printf(ANSI_COLOR_WHITE"##      # ##       #"),printf(ANSI_COLOR_RED" ##          #  #   ##\n");
    printf(ANSI_COLOR_BLUE"\t\t\t\t\t ##       ## ##        ##  ## ### ## "),printf(ANSI_COLOR_WHITE"########  ##        "),printf(ANSI_COLOR_RED"  #######     ##     #######\n");
    printf(ANSI_COLOR_BLUE"\t\t\t\t\t ##       ## ##        ##  ##  #  ## "),printf(ANSI_COLOR_WHITE"##        ##       #"),printf(ANSI_COLOR_RED"        ##    ##           ##\n");
    printf(ANSI_COLOR_BLUE"\t\t\t\t\t  ##     ##  ##        ##  ##     ## "),printf(ANSI_COLOR_WHITE"##         ##     ##"),printf(ANSI_COLOR_RED" ##     ##    ##    ##     ##\n");
    printf(ANSI_COLOR_BLUE"\t\t\t\t\t   #######   ######## #### ##     ## "),printf(ANSI_COLOR_WHITE"##          #######"),printf(ANSI_COLOR_RED"   #######    ####    #######\n\n");
    printf(ANSI_COLOR_BLUE"\t\t\t\t\t        .::::::::::."),printf(ANSI_COLOR_WHITE"                 .###########."),printf(ANSI_COLOR_RED"                 .::::::::::.\n");
    printf(ANSI_COLOR_BLUE"\t\t\t\t\t    .:::.          .:::."),printf(ANSI_COLOR_WHITE"         .####           ####."),printf(ANSI_COLOR_RED"         .:::.          .:::.\n");
    printf(ANSI_COLOR_BLUE"\t\t\t\t\t  .::                  ::."),printf(ANSI_COLOR_WHITE"     .###                 ###."),printf(ANSI_COLOR_RED"     .::                  ::.\n");
    printf(ANSI_COLOR_BLUE"\t\t\t\t\t .::                    ::."),printf(ANSI_COLOR_WHITE"   .##                     ##."),printf(ANSI_COLOR_RED"   .::                    ::.\n");
    printf(ANSI_COLOR_BLUE"\t\t\t\t\t :::"),printf(ANSI_COLOR_WHITE"                   ."),printf(ANSI_COLOR_BLUE":::"),printf(ANSI_COLOR_YELLOW":::::::."),printf(ANSI_COLOR_GREEN"                 .:"),printf(ANSI_COLOR_WHITE"##:"),printf(ANSI_COLOR_GREEN"::::::."),printf(ANSI_COLOR_RED"                   :::\n");
    printf(ANSI_COLOR_BLUE"\t\t\t\t\t .::"),printf(ANSI_COLOR_YELLOW"               .:::."),printf(ANSI_COLOR_BLUE"::."),printf(ANSI_COLOR_WHITE"   .##"),printf(ANSI_COLOR_YELLOW" .:::."),printf(ANSI_COLOR_GREEN"         .:::."),printf(ANSI_COLOR_WHITE" ##."),printf(ANSI_COLOR_RED"   .::."),printf(ANSI_COLOR_GREEN":::."),printf(ANSI_COLOR_RED"               ::.\n");
    printf(ANSI_COLOR_BLUE"\t\t\t\t\t  .:."),printf(ANSI_COLOR_YELLOW"            .::"),printf(ANSI_COLOR_BLUE"   .:."),printf(ANSI_COLOR_WHITE"     .###"),printf(ANSI_COLOR_YELLOW"   ::."),printf(ANSI_COLOR_GREEN"     .::"),printf(ANSI_COLOR_WHITE"   ###."),printf(ANSI_COLOR_RED"     .:."),printf(ANSI_COLOR_GREEN"   ::."),printf(ANSI_COLOR_RED"            .:.\n");
    printf(ANSI_COLOR_BLUE"\t\t\t\t\t    ::."),printf(ANSI_COLOR_YELLOW"         .::"),printf(ANSI_COLOR_BLUE"  .::"),printf(ANSI_COLOR_WHITE"        .####"),printf(ANSI_COLOR_YELLOW"  ::."),printf(ANSI_COLOR_GREEN"   .::"),printf(ANSI_COLOR_WHITE" ####."),printf(ANSI_COLOR_RED"         ::."),printf(ANSI_COLOR_GREEN"  ::."),printf(ANSI_COLOR_RED"         .::\n");
    printf(ANSI_COLOR_BLUE"\t\t\t\t\t      .:::::::::"),printf(ANSI_COLOR_YELLOW":::"),printf(ANSI_COLOR_BLUE"::."),printf(ANSI_COLOR_WHITE"              .########"),printf(ANSI_COLOR_GREEN":::"),printf(ANSI_COLOR_WHITE"#."),printf(ANSI_COLOR_RED"               .::::::::::::::.\n");
    printf(ANSI_COLOR_YELLOW"\t\t\t\t\t                .::                    ::."),printf(ANSI_COLOR_GREEN"   .::                    ::.\n");
    printf(ANSI_COLOR_YELLOW"\t\t\t\t\t                 .:.                  .:."),printf(ANSI_COLOR_GREEN"     .:.                  .:.\n");
    printf(ANSI_COLOR_YELLOW"\t\t\t\t\t                   ::.              .::"),printf(ANSI_COLOR_GREEN"         ::.              .::\n");
    printf(ANSI_COLOR_YELLOW"\t\t\t\t\t                     .::::::::::::::."),printf(ANSI_COLOR_GREEN"             .::::::::::::::.\n\n");
    printf(ANSI_COLOR_WHITE"\t\t\t\t\t\t\t\t\t    Seja Bem-vindo!\n");
    printf("\t\t\t\t\t\t\t    ===============================================\n");
    printf("\t\t\t\t\t\t\t    |\t                                          |\n");
    printf("\t\t\t\t\t\t\t    |\t 1 - Ja tenho uma conta                   |\n");
    printf("\t\t\t\t\t\t\t    |\t 2 - Fazer login como Atleta              |\n");
    printf("\t\t\t\t\t\t\t    |\t 3 - Fazer login como Medico              |\n");
    printf("\t\t\t\t\t\t\t    |\t 4 - Fazer login como Funcionario         |\n");
    printf("\t\t\t\t\t\t\t    |\t 5 - Fazer login como Voluntario          |\n");
    printf("\t\t\t\t\t\t\t    |\t 6 - Quadro de Medalhas                   |\n");
    printf("\t\t\t\t\t\t\t    |\t 0 - Sair                                 |\n");
    printf("\t\t\t\t\t\t\t    |\t                                          |\n");
    printf("\t\t\t\t\t\t\t    ===============================================\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t   Por favor, selecione uma opcao: ");
    fflush(stdin);
    scanf("%d", &input);
    system("cls");

    switch(input)
        {
        case 1:
            menuLogin();
            break;   
        case 2:
            menuUsers();
            break;
        case 3:
            menuUsers();
            break;
        case 4:
            menuUsers();
            break;
        case 5:
            menuUsers();
            break;
        case 6:
            menuMedalhas();
            break;
        case 0:
            exit(EXIT_SUCCESS);
        default:
            printf ("\n\t\t\tOpcao invalida!\n\n");
            fflush(stdin);
        }
    system("cls");
}

void menuLogin()
{

    FILE *pon_arq;

    pon_arq = fopen("cadastro.txt", "a");

    printf("\n");
    printf ("\t\t\t\tFaca seu Login:\n");
    
    printf("Digite seu nome: ");
    scanf("%s", nome);
    fscanf(pon_arq, "%s\n", nome);

    printf("Digite sua senha: ");
    scanf("%s", senha);
    fscanf(pon_arq, "%s\n", senha);

    system("cls");
    menuPrincipal();
}

void menuUsers()
{
        printf("\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t            Area de cadastro\n");
        printf("\t\t\t\t\t\t\t\t    ===============================\n");
        printf("\t\t\t\t\t\t\t\t    |                             |\n");
        printf("\t\t\t\t\t\t\t\t    |    1 - Cadastrar            |\n");
        printf("\t\t\t\t\t\t\t\t    |    2 - Alterar Cadastro     |\n");
        printf("\t\t\t\t\t\t\t\t    |    3 - Excluir Cadastro     |\n");
        printf("\t\t\t\t\t\t\t\t    |    4 - Menu Principal       |\n");
        printf("\t\t\t\t\t\t\t\t    |    0 - Sair                 |\n");
        printf("\t\t\t\t\t\t\t\t    |                             |\n");
        printf("\t\t\t\t\t\t\t\t    ===============================\n");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t\t    Por favor, selecione uma opcao: ");
        fflush(stdin);
        scanf("%d", &input);
        system("cls");
        switch(input)
        {
        case 1:
            menuCad();
            break;
        case 2:
            menuAlterarUser();
            break;
        case 3:
            //removerUser(qtdUsers, users_dir);
            break;
        case 4:
            menuPrincipal();
            break;
        case 0:
            exit(EXIT_SUCCESS);
        default:
            printf ("\n\t\t\tOpcao invalida!\n\n");
            fflush(stdin);
        }
    system("cls");
}

void menuCad()
{

    FILE *pon_arq;

    pon_arq = fopen("cadastro.txt", "a");

    printf("\n");
    printf ("\t\t\t\tFaca de cadastro\n");
    
    printf("Digite seu nome: ");
    scanf("%s", nome);
    fprintf(pon_arq, "%s\n", nome);

    printf("Digite sua idade: ");
    scanf("%s", idade);
    fprintf(pon_arq, "%s\n", idade);

    printf("Digite seu telefone: ");
    scanf("%s", telefone);
    fprintf(pon_arq, "%s\n", telefone);

    printf("Crie uma senha: ");
    scanf("%s", senha);
    fprintf(pon_arq, "%s\n", senha);

    system("cls");
    menuPrincipal();
}

void menuAlterarUser()
{
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t            Gerenciar Dados\n");
    printf("\t\t\t\t\t\t\t\t    ===============================\n");
    printf("\t\t\t\t\t\t\t\t    |                             |\n");
    printf("\t\t\t\t\t\t\t\t    |    1 - Alterar Nome         |\n");
    printf("\t\t\t\t\t\t\t\t    |    2 - Alterar Telefone     |\n");
    printf("\t\t\t\t\t\t\t\t    |    3 - Alterar Endereco     |\n");
    printf("\t\t\t\t\t\t\t\t    |    4 - Menu Principal       |\n");
    printf("\t\t\t\t\t\t\t\t    |    0 - Sair                 |\n");
    printf("\t\t\t\t\t\t\t\t    |                             |\n");
    printf("\t\t\t\t\t\t\t\t    ===============================\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t    Por favor, selecione uma opcao: ");
    fflush(stdin);
    scanf("%d", &input);
    system("cls");

    switch(input)
    {
    case 1:
        //alterarNome();
        break;
    case 2:
        //alterarTelefone();
        break;
    case 3:
        //alterarEndereco();
        break;
    case 4:
        menuPrincipal();
        break;
    case 0:
        exit(EXIT_SUCCESS);
    default:
        printf ("\n\t\t\tOpcao invalida!\n\n");
        fflush(stdin);
    }
}

void menuMedalhas()
{
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t   Tabela de Medalhas\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\t\t\t\t\t\t\t   |        PAISES                   MEDALHAS       |\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\t\t\t\t\t\t\t   |                          OURO / PRATA / BRONZE |\n");
    printf("\t\t\t\t\t\t\t   |    1 - Estados Unidos     39 |   41  |    33   |\n");
    printf("\t\t\t\t\t\t\t   |    2 - China              38 |   32  |    18   |\n");
    printf("\t\t\t\t\t\t\t   |    3 - Japao              27 |   14  |    17   |\n");
    printf("\t\t\t\t\t\t\t   |    4 - Gra-Bretanha       22 |   21  |    22   |\n");
    printf("\t\t\t\t\t\t\t   |    5 - ROC                20 |   28  |    23   |\n");
    printf("\t\t\t\t\t\t\t   |    6 - Australia          17 |    7  |    22   |\n");
    printf("\t\t\t\t\t\t\t   |    7 - Paises Baixos      10 |   12  |    14   |\n");
    printf("\t\t\t\t\t\t\t   |    8 - Franca             10 |   12  |    11   |\n");
    printf("\t\t\t\t\t\t\t   |    9 - Alemanha           10 |   11  |    16   |\n");
    printf("\t\t\t\t\t\t\t   |   10 - Italia             10 |   10  |    20   |\n");
    printf("\t\t\t\t\t\t\t   |   11 - Canada              7 |    6  |    11   |\n");
    printf("\t\t\t\t\t\t\t   |   12 - Brasil              7 |    6  |     8   |\n");
    printf("\t\t\t\t\t\t\t   |   13 - Nova Zelandia       7 |    6  |     7   |\n");
    printf("\t\t\t\t\t\t\t   |   14 - Cuba                7 |    3  |     5   |\n");
    printf("\t\t\t\t\t\t\t   |   15 - Hungria             6 |    7  |     7   |\n");
    printf("\t\t\t\t\t\t\t   |                              |       |         |\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\t\t\t\t\t\t\t   |        Digite 2 Numero da Pagina:              |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   |          "),printf(ANSI_COLOR_GREEN"1"),printf(ANSI_COLOR_WHITE" / 2 / 3 / 4 / 5 / 6                 |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   |           0 - Ir para o menu                   |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t   Por favor, selecione uma opcao: ");
    fflush(stdin);
    scanf("%d", &input);
    system("cls");

    switch(input)
    {
    case 1:
        menuMedalhas();
        break;
    case 2:
        menuMedalhas2();
        break;
    case 3:
        menuMedalhas3();
        break;
    case 4:
        menuMedalhas4();
        break;
    case 5:
        menuMedalhas5();
        break;
    case 6:
        menuMedalhas6();
        break;
    case 0:
        menuPrincipal();
    default:
        printf ("\n\t\t\tOpcao invalida!\n\n");
        fflush(stdin);
    }
}

void menuMedalhas2()
{
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t   Tabela de Medalhas\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\t\t\t\t\t\t\t   |        PAISES                   MEDALHAS       |\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\t\t\t\t\t\t\t   |                          OURO / PRATA / BRONZE |\n");
    printf("\t\t\t\t\t\t\t   |   16 - Estados Unidos                          |\n");
    printf("\t\t\t\t\t\t\t   |   17 - China                                   |\n");
    printf("\t\t\t\t\t\t\t   |   18 - Japao                                   |\n");
    printf("\t\t\t\t\t\t\t   |   19 - Gra-Bretanha                            |\n");
    printf("\t\t\t\t\t\t\t   |   20 - ROC                                     |\n");
    printf("\t\t\t\t\t\t\t   |   21 - Australia                               |\n");
    printf("\t\t\t\t\t\t\t   |   22 - Paises Baixos                           |\n");
    printf("\t\t\t\t\t\t\t   |   23 - Franca                                  |\n");
    printf("\t\t\t\t\t\t\t   |   24 - Alemanha                                |\n");
    printf("\t\t\t\t\t\t\t   |   25 - Italia                                  |\n");
    printf("\t\t\t\t\t\t\t   |   26 - Canada                                  |\n");
    printf("\t\t\t\t\t\t\t   |   27 - Brasil                                  |\n");
    printf("\t\t\t\t\t\t\t   |   28 - Nova Zelandia                           |\n");
    printf("\t\t\t\t\t\t\t   |   29 - Cuba                                    |\n");
    printf("\t\t\t\t\t\t\t   |   30 - Hungria                                 |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\t\t\t\t\t\t\t   |        Digite 2 Numero da Pagina:              |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   |          1 / "),printf(ANSI_COLOR_GREEN"2"),printf(ANSI_COLOR_WHITE" / 3 / 4 / 5 / 6                 |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   |           0 - Ir para o menu                   |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t   Por favor, selecione uma opcao: ");
    fflush(stdin);
    scanf("%d", &input);
    system("cls");

    switch(input)
    {
    case 1:
        menuMedalhas();
        break;
    case 2:
        menuMedalhas2();
        break;
    case 3:
        menuMedalhas3();
        break;
    case 4:
        menuMedalhas4();
        break;
    case 5:
        menuMedalhas5();
        break;
    case 6:
        menuMedalhas6();
        break;
    case 0:
        menuPrincipal();
    default:
        printf ("\n\t\t\tOpcao invalida!\n\n");
        fflush(stdin);
    }
}

void menuMedalhas3()
{
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t   Tabela de Medalhas\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\t\t\t\t\t\t\t   |        PAISES                   MEDALHAS       |\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\t\t\t\t\t\t\t   |                          OURO / PRATA / BRONZE |\n");
    printf("\t\t\t\t\t\t\t   |   31 - Estados Unidos                          |\n");
    printf("\t\t\t\t\t\t\t   |   32 - China                                   |\n");
    printf("\t\t\t\t\t\t\t   |   33 - Japao                                   |\n");
    printf("\t\t\t\t\t\t\t   |   34 - Gra-Bretanha                            |\n");
    printf("\t\t\t\t\t\t\t   |   35 - ROC                                     |\n");
    printf("\t\t\t\t\t\t\t   |   36 - Australia                               |\n");
    printf("\t\t\t\t\t\t\t   |   37 - Paises Baixos                           |\n");
    printf("\t\t\t\t\t\t\t   |   38 - Franca                                  |\n");
    printf("\t\t\t\t\t\t\t   |   39 - Alemanha                                |\n");
    printf("\t\t\t\t\t\t\t   |   40 - Italia                                  |\n");
    printf("\t\t\t\t\t\t\t   |   41 - Canada                                  |\n");
    printf("\t\t\t\t\t\t\t   |   42 - Brasil                                  |\n");
    printf("\t\t\t\t\t\t\t   |   43 - Nova Zelandia                           |\n");
    printf("\t\t\t\t\t\t\t   |   44 - Cuba                                    |\n");
    printf("\t\t\t\t\t\t\t   |   45 - Hungria                                 |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\t\t\t\t\t\t\t   |        Digite 2 Numero da Pagina:              |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   |          1 / 2 / "),printf(ANSI_COLOR_GREEN"3"),printf(ANSI_COLOR_WHITE" / 4 / 5 / 6                 |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   |           0 - Ir para o menu                   |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t   Por favor, selecione uma opcao: ");
    fflush(stdin);
    scanf("%d", &input);
    system("cls");

    switch(input)
    {
    case 1:
        menuMedalhas();
        break;
    case 2:
        menuMedalhas2();
        break;
    case 3:
        menuMedalhas3();
        break;
    case 4:
        menuMedalhas4();
        break;
    case 5:
        menuMedalhas5();
        break;
    case 6:
        menuMedalhas6();
        break;
    case 0:
        menuPrincipal();
    default:
        printf ("\n\t\t\tOpcao invalida!\n\n");
        fflush(stdin);
    }
}

void menuMedalhas4()
{
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t   Tabela de Medalhas\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\t\t\t\t\t\t\t   |        PAISES                   MEDALHAS       |\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\t\t\t\t\t\t\t   |                          OURO / PRATA / BRONZE |\n");
    printf("\t\t\t\t\t\t\t   |   46 - Estados Unidos                          |\n");
    printf("\t\t\t\t\t\t\t   |   47 - China                                   |\n");
    printf("\t\t\t\t\t\t\t   |   48 - Japao                                   |\n");
    printf("\t\t\t\t\t\t\t   |   49 - Gra-Bretanha                            |\n");
    printf("\t\t\t\t\t\t\t   |   50 - ROC                                     |\n");
    printf("\t\t\t\t\t\t\t   |   51 - Australia                               |\n");
    printf("\t\t\t\t\t\t\t   |   52 - Paises Baixos                           |\n");
    printf("\t\t\t\t\t\t\t   |   53 - Franca                                  |\n");
    printf("\t\t\t\t\t\t\t   |   54 - Alemanha                                |\n");
    printf("\t\t\t\t\t\t\t   |   55 - Italia                                  |\n");
    printf("\t\t\t\t\t\t\t   |   56 - Canada                                  |\n");
    printf("\t\t\t\t\t\t\t   |   57 - Brasil                                  |\n");
    printf("\t\t\t\t\t\t\t   |   58 - Nova Zelandia                           |\n");
    printf("\t\t\t\t\t\t\t   |   59 - Cuba                                    |\n");
    printf("\t\t\t\t\t\t\t   |   60 - Hungria                                 |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\t\t\t\t\t\t\t   |        Digite 2 Numero da Pagina:              |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   |          1 / 2 / 3 / "),printf(ANSI_COLOR_GREEN"4"),printf(ANSI_COLOR_WHITE" / 5 / 6                 |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   |           0 - Ir para o menu                   |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t   Por favor, selecione uma opcao: ");
    fflush(stdin);
    scanf("%d", &input);
    system("cls");

    switch(input)
    {
    case 1:
        menuMedalhas();
        break;
    case 2:
        menuMedalhas2();
        break;
    case 3:
        menuMedalhas3();
        break;
    case 4:
        menuMedalhas4();
        break;
    case 5:
        menuMedalhas5();
        break;
    case 6:
        menuMedalhas6();
        break;
    case 0:
        menuPrincipal();
    default:
        printf ("\n\t\t\tOpcao invalida!\n\n");
        fflush(stdin);
    }
}

void menuMedalhas5()
{
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t   Tabela de Medalhas\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\t\t\t\t\t\t\t   |        PAISES                   MEDALHAS       |\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\t\t\t\t\t\t\t   |                          OURO / PRATA / BRONZE |\n");
    printf("\t\t\t\t\t\t\t   |   61 - Estados Unidos                          |\n");
    printf("\t\t\t\t\t\t\t   |   62 - China                                   |\n");
    printf("\t\t\t\t\t\t\t   |   63 - Japao                                   |\n");
    printf("\t\t\t\t\t\t\t   |   64 - Gra-Bretanha                            |\n");
    printf("\t\t\t\t\t\t\t   |   65 - ROC                                     |\n");
    printf("\t\t\t\t\t\t\t   |   66 - Australia                               |\n");
    printf("\t\t\t\t\t\t\t   |   67 - Paises Baixos                           |\n");
    printf("\t\t\t\t\t\t\t   |   68 - Franca                                  |\n");
    printf("\t\t\t\t\t\t\t   |   69 - Alemanha                                |\n");
    printf("\t\t\t\t\t\t\t   |   70 - Italia                                  |\n");
    printf("\t\t\t\t\t\t\t   |   71 - Canada                                  |\n");
    printf("\t\t\t\t\t\t\t   |   72 - Brasil                                  |\n");
    printf("\t\t\t\t\t\t\t   |   73 - Nova Zelandia                           |\n");
    printf("\t\t\t\t\t\t\t   |   74 - Cuba                                    |\n");
    printf("\t\t\t\t\t\t\t   |   75 - Hungria                                 |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\t\t\t\t\t\t\t   |        Digite 2 Numero da Pagina:              |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   |          1 / 2 / 3 / 4 / "),printf(ANSI_COLOR_GREEN"5"),printf(ANSI_COLOR_WHITE" / 6                 |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   |           0 - Ir para o menu                   |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t   Por favor, selecione uma opcao: ");
    fflush(stdin);
    scanf("%d", &input);
    system("cls");

    switch(input)
    {
    case 1:
        menuMedalhas();
        break;
    case 2:
        menuMedalhas2();
        break;
    case 3:
        menuMedalhas3();
        break;
    case 4:
        menuMedalhas4();
        break;
    case 5:
        menuMedalhas5();
        break;
    case 6:
        menuMedalhas6();
        break;
    case 0:
        menuPrincipal();
    default:
        printf ("\n\t\t\tOpcao invalida!\n\n");
        fflush(stdin);
    }
}

void menuMedalhas6()
{
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\t   Tabela de Medalhas\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\t\t\t\t\t\t\t   |        PAISES                   MEDALHAS       |\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\t\t\t\t\t\t\t   |                          OURO / PRATA / BRONZE |\n");
    printf("\t\t\t\t\t\t\t   |   76 - Estados Unidos                          |\n");
    printf("\t\t\t\t\t\t\t   |   77 - China                                   |\n");
    printf("\t\t\t\t\t\t\t   |   78 - Japao                                   |\n");
    printf("\t\t\t\t\t\t\t   |   79 - Gra-Bretanha                            |\n");
    printf("\t\t\t\t\t\t\t   |   80 - ROC                                     |\n");
    printf("\t\t\t\t\t\t\t   |   81 - Australia                               |\n");
    printf("\t\t\t\t\t\t\t   |   82 - Paises Baixos                           |\n");
    printf("\t\t\t\t\t\t\t   |   83 - Franca                                  |\n");
    printf("\t\t\t\t\t\t\t   |   84 - Alemanha                                |\n");
    printf("\t\t\t\t\t\t\t   |   85 - Italia                                  |\n");
    printf("\t\t\t\t\t\t\t   |   86 - Canada                                  |\n");
    printf("\t\t\t\t\t\t\t   |   87 - Brasil                                  |\n");
    printf("\t\t\t\t\t\t\t   |   88 - Nova Zelandia                           |\n");
    printf("\t\t\t\t\t\t\t   |   89 - Cuba                                    |\n");
    printf("\t\t\t\t\t\t\t   |   90 - Hungria                                 |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\t\t\t\t\t\t\t   |        Digite 2 Numero da Pagina:              |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   |          1 / 2 / 3 / 4 / 5 / "),printf(ANSI_COLOR_GREEN"6"),printf(ANSI_COLOR_WHITE"\t\t    |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   |           0 - Ir para o menu                   |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t\t\t   Por favor, selecione uma opcao: ");
    fflush(stdin);
    scanf("%d", &input);
    system("cls");

    switch(input)
    {
    case 1:
        menuMedalhas();
        break;
    case 2:
        menuMedalhas2();
        break;
    case 3:
        menuMedalhas3();
        break;
    case 4:
        menuMedalhas4();
        break;
    case 5:
        menuMedalhas5();
        break;
    case 6:
        menuMedalhas6();
        break;
    case 0:
        menuPrincipal();
    default:
        printf ("\n\t\t\tOpcao invalida!\n\n");
        fflush(stdin);
    }
}