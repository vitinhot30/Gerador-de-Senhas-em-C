#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

int generate(int type);
int save_key();
void about(void);

int key_num[10] = {1,2,3,4,5,6,7,8,9,0};

char key_lchar[52] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

char key_espec[17] = {'_','.','-','$','%','/','&','(',')','[',']','?','!','@','=','*','+'};

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int opc;
    int op1;
    int to1 = 1;
    int to2 = 2;
    int to3 = 3;
    int to4 = 4;

    printf("\t\t ==== Gerador de Senhas ====\n");
    printf("\t\t ======= versão: 1.0 =======\n");
    printf("Escolha uma das opções... \n");
    printf("[1] Gerar Senha.\n");
    printf("[2] Sobre o Gerador de Senhas. \n");
    printf("[3] Sair. \n");
    scanf("%d", &opc);

    if(opc == 1)
    {
        printf("\nEscolha uma das opções... \n");
        printf("[1] Senhas que contém somente letras.\n");
        printf("[2] Senhas que contém somente números.\n");
        printf("[3] Senhas que contém letras e números.\n");
        printf("[4] Senhas que contém tudo, inclusive caracteres especiais.\n");
        scanf("%d", &op1);

        if(op1 == 1)
            generate(to1);

        if(op1 == 2)
            generate(to2);

        if(op1 == 3)
            generate(to3);

        if(op1 == 4)
            generate(to4);
    }
    if(opc == 2)
        about();
    if(opc == 3)
        exit(0);

    return(0);
}

int generate(int type)
{
    char *pass;
    int quant;
    int qtn;
    int n;

    srand(time(NULL));
    pass = (char *) malloc(sizeof(char));

    if(type == 1)
    {
        printf("\nDigite a quantidade de caracteres que deseja.\n");
        scanf("%d", &quant);

        for(n = 0; n < quant; n++)
        {
            printf("%c", key_lchar[rand()%53]);
            sleep(1);

        }
        printf("\n");

    }
    if(type == 2)
    {
        printf("\nDigite a quantidade de caracteres que deseja.\n");
        scanf("%d", &quant);

         for(n = 0; n < quant; n++)
        {
            printf("%d", key_num[rand()%11]);
            sleep(1);
        }
        printf("\n");
    }
    if(type == 3)
    {
        printf("\nDigite a quantidade de caracteres que deseja. \n");
        scanf("%d", &quant);
        qtn = quant / 2;

        for(n = 0; n < qtn; n++)
        {
                printf("%c", key_lchar[rand()%53]);
                printf("%d", key_num[rand()%11]);

            sleep(1);
        }
        printf("\n");
    }
    if(type == 4)
    {
        printf("\nDigite a quantidade de caracteres que deseja. \n");
        scanf("%d", &quant);
        qtn = quant / 2;

        for(n = 0; n < qtn; n++)
        {
            printf("%c", key_lchar[rand()%53]);

            if(n % 2 == 0)
            {
                if((rand()%11) %2 == 0)
                    printf("%c", key_espec[rand()%18]);
                else
                printf("%d", key_num[rand()%11]);
            }
        else
            printf("%d", key_num[rand()%11]);
        sleep(1);

        }
        printf("\n");
    }
    free(pass);
    return(0);

}

void about(void)
{
    printf("Gerador de Senhas 1.0\n");
    printf("Autor: Vitor Tores Alves De Anhaia.\n");
    printf("Projeto destinado ao estudo na linguagem C.\n");
}
