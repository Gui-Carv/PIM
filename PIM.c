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
    printf("\t\t\t\t\t\t\t    |\t 7 - Marque um treino                     |\n");
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
        case 7:
            menuTreino();
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

    pon_arq = fopen("cadastro.txt", "r");

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
    printf ("\t\t\t\tFaca seu cadastro\n");

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
    printf("\t\t\t\t\t\t\t   |        Digite o Numero da Pagina:              |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   |          "),printf(ANSI_COLOR_GREEN"1"),printf(ANSI_COLOR_WHITE" / 2 /             |\n");
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
    printf("\t\t\t\t\t\t\t   |         PAISES                  MEDALHAS       |\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\t\t\t\t\t\t\t   |                          OURO / PRATA / BRONZE |\n");
    printf("\t\t\t\t\t\t\t   |    16 - Coreia do sul       6 |    4  |    10   |\n");
    printf("\t\t\t\t\t\t\t   |    17 - Polonia             4 |    5  |     5   |\n");
    printf("\t\t\t\t\t\t\t   |    18 - Republica Checa     4 |    4  |     3   |\n");
    printf("\t\t\t\t\t\t\t   |    19 - Quenia              4 |    4  |     2   |\n");
    printf("\t\t\t\t\t\t\t   |    20 - Noruega             4 |    2  |     4   |\n");
    printf("\t\t\t\t\t\t\t   |    21 - Jamaica             4 |    1  |     6   |\n");
    printf("\t\t\t\t\t\t\t   |    22 - Espanha             3 |    8  |     0   |\n");
    printf("\t\t\t\t\t\t\t   |    23 - Suecia              3 |    6  |     6   |\n");
    printf("\t\t\t\t\t\t\t   |    24 - Suica               3 |    4  |     4   |\n");
    printf("\t\t\t\t\t\t\t   |    25 - Dinamarca           3 |    4  |     4   |\n");
    printf("\t\t\t\t\t\t\t   ==================================================\n");
    printf("\t\t\t\t\t\t\t   |        Digite o Numero da Pagina:              |\n");
    printf("\t\t\t\t\t\t\t   |                                                |\n");
    printf("\t\t\t\t\t\t\t   |          "),printf(ANSI_COLOR_GREEN"1"),printf(ANSI_COLOR_WHITE" 1/ 2 /                 |\n");
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
    case 0:
        menuPrincipal();
    default:
        printf ("\n\t\t\tOpcao invalida!\n\n");
        fflush(stdin);
    }
}



    void menuTreino()
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
    printf("\t\t\t\t\t\t\t   |        Digite o Numero da Pagina:              |\n");
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

    FILE *pon_arq;

    pon_arq = fopen("treino.txt", "a");

    printf("\n\n\n\n\n\n\n");
    printf ("\t\t\t\t     Dias disponiveis\n");
    printf ("\t\t\t\tSegunda-feira: 10h 13h 15h 17h\n");
    printf ("\t\t\t\tterca-feira:   10h 15h 17h\n");
    printf ("\t\t\t\tQuarta-feira:  10h 13h 19h\n");
    printf ("\t\t\t\tquinta-feira:  10h 19h 21h\n");
    printf ("\t\t\t\tquinta-feira:  Nao ha horarios\n");
    printf ("\t\t\t\tsexta-feira:   Nao ha horarios\n");
    printf("\n\n");


    printf("\n");
    printf ("\t\t\t\t "),printf(ANSI_COLOR_GREEN"Marque seu treino"),printf(ANSI_COLOR_WHITE" \n");

    printf("Digite seu nome: ");
    scanf("%s", nome);
    fprintf(pon_arq, "%s\n", nome);

    printf("Digite sua modalidade: ");
    scanf("%s", modalidade);
    fprintf(pon_arq, "%s\n", modalidade);

    printf("Digite sua equipe(pais): ");
    scanf("%s", equipe);
    fprintf(pon_arq, "%s\n", equipe);


    system("cls");
    menuPrincipal();
}

