#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#define TAM 16


char yes_not;

void bin_for_dec() //Cada posi��o tem um peso de uma pot�ncia de 2 (base do sistema bin�rio).
                   // Sendo assim, para se converter um n�mero de bin�rio para decimal,
                   //deve-se multiplicar cada bit pela pot�ncia de sua posi��o e somar os resultados
{
    setlocale(LC_ALL, "Portuguese");
    int dec = 0, num, d = 1;

    printf("\n\t\t\t\Digite o n�mero bin�rio: ");
    scanf("%d", &num);

        do
        {
            dec = dec+ (num%10)*d;
            d = d*2;
            num =  num/10;
        }
        while (num!=0);
        printf("\n\t\t\tEste n�mero em decimal � %d", dec);
        getch();
}

void dec_for_bin()
{
    setlocale(LC_ALL, "Portuguese");
    int n_dec, aux, bin[TAM];//Esse tam j� foi definido anteriormente em 16 ou seja ex:0000 0000 0000 0000.


    printf("\n\t\t\tDigite o n�mero decimal: ");
    scanf("%d", &n_dec);//Para converter um numero decimal em binario � necessario dividi-lo v�rias vezes por 2 (base bin�ria)
//Quando o quociente for menor que 2 a divis�o ser� parada, � coletado os dados do menor para o maior
// ex: numero 23, 23/2 (tem resto 1) 11/2 (tem resto 1) 5/2 (tem resto 1) 2/2 tem resto 0, sobra 1 e a divis�o para.
// ficando 11101 s� que se l� do menor para o maior ent�o o resultado do numero 23 em bin�rio �: 10111


        for (aux= TAM -1; aux >= 0; aux --)
        {
            bin[aux]= (n_dec %2) == 0 ? 0 :1;
            n_dec =  n_dec /2;
        }

        printf( "\n\t");
        printf("\n\t\t\tEste n�mero em bin�rio �:");
        for (aux=0; aux < TAM; aux++){

        printf("%d", bin[aux]);

        }
        getch();
}
//Aqui � o menu onde � escolhida a op��o de convers�o.
void menu()
{
    setlocale(LC_ALL, "Portuguese");
    int option = 0;
	printf ("\t\t\t ------------------------------------------------\t\t\t\ ");
    printf ("\n\t\t\t\tCalculadora de convers�o de bases.\n");
	printf ("\t\t\t ------------------------------------------------\t\t\t\ ");
	printf ("\n\t\t\t escolha a tipo de convers�o a ser realizado:\n");
    printf("\t\t\t 0 - Bin�rio para decimal\n");
    printf("\t\t\t 1 - Decimal para bin�rio\n");
    printf ("\t\t\t ------------------------------------------------\t\t\t\ ");
    printf ("\n\t\t\t\tFeito por: Luis, Clovis e Adri.\n");

    scanf("%d", &option);

        if (option == 0)
        {
            bin_for_dec();
        } else if (option == 1)
        {
            dec_for_bin();
        } else if (option != 0 && option != 1)
        {
            printf("\t\t\tOp��o inv�lida. Por favor, tente novamente.");
            menu();
        }
}

int main()
{
setlocale(LC_ALL, "Portuguese");
  menu();

  printf("\n\t\t\t Deseja fazer outro c�lculo\?");

  printf("\n\t\t\t(s) - Sim\n\t\t\t(n) - N�o\n");

  scanf(" %s", &yes_not);// Switch case para poder reiniciar a calculadora


    switch(yes_not)
    {
    case 's':
        printf("\n\t\t\tTecle enter <ENTER> para reiniciar a calculadora.\n");
        system("pause");
        system("cls");
        main();
        break;

    case 'n':
        system ("cls");
        exit(0);
        break;
// caso digite algo diferente de s ou n, ele ir� informar esta mensagem

    default:
        printf("\n\t\t\t Para encerrar o programa digite Sim(s) ou N�o(n).\n");
    }
return 0;
}
