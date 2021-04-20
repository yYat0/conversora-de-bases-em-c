#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#define TAM 16


char yes_not;

void bin_for_dec() //Cada posição tem um peso de uma potência de 2 (base do sistema binário).
                   // Sendo assim, para se converter um número de binário para decimal,
                   //deve-se multiplicar cada bit pela potência de sua posição e somar os resultados
{
    setlocale(LC_ALL, "Portuguese");
    int dec = 0, num, d = 1;

    printf("\n\t\t\t\Digite o número binário: ");
    scanf("%d", &num);

        do
        {
            dec = dec+ (num%10)*d;
            d = d*2;
            num =  num/10;
        }
        while (num!=0);
        printf("\n\t\t\tEste número em decimal é %d", dec);
        getch();
}

void dec_for_bin()
{
    setlocale(LC_ALL, "Portuguese");
    int n_dec, aux, bin[TAM];//Esse tam já foi definido anteriormente em 16 ou seja ex:0000 0000 0000 0000.


    printf("\n\t\t\tDigite o número decimal: ");
    scanf("%d", &n_dec);//Para converter um numero decimal em binario é necessario dividi-lo várias vezes por 2 (base binária)
//Quando o quociente for menor que 2 a divisão será parada, é coletado os dados do menor para o maior
// ex: numero 23, 23/2 (tem resto 1) 11/2 (tem resto 1) 5/2 (tem resto 1) 2/2 tem resto 0, sobra 1 e a divisão para.
// ficando 11101 só que se lê do menor para o maior então o resultado do numero 23 em binário é: 10111


        for (aux= TAM -1; aux >= 0; aux --)
        {
            bin[aux]= (n_dec %2) == 0 ? 0 :1;
            n_dec =  n_dec /2;
        }

        printf( "\n\t");
        printf("\n\t\t\tEste número em binário é:");
        for (aux=0; aux < TAM; aux++){

        printf("%d", bin[aux]);

        }
        getch();
}
//Aqui é o menu onde é escolhida a opção de conversão.
void menu()
{
    setlocale(LC_ALL, "Portuguese");
    int option = 0;
	printf ("\t\t\t ------------------------------------------------\t\t\t\ ");
    printf ("\n\t\t\t\tCalculadora de conversão de bases.\n");
	printf ("\t\t\t ------------------------------------------------\t\t\t\ ");
	printf ("\n\t\t\t escolha a tipo de conversão a ser realizado:\n");
    printf("\t\t\t 0 - Binário para decimal\n");
    printf("\t\t\t 1 - Decimal para binário\n");
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
            printf("\t\t\tOpção inválida. Por favor, tente novamente.");
            menu();
        }
}

int main()
{
setlocale(LC_ALL, "Portuguese");
  menu();

  printf("\n\t\t\t Deseja fazer outro cálculo\?");

  printf("\n\t\t\t(s) - Sim\n\t\t\t(n) - Não\n");

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
// caso digite algo diferente de s ou n, ele irá informar esta mensagem

    default:
        printf("\n\t\t\t Para encerrar o programa digite Sim(s) ou Não(n).\n");
    }
return 0;
}
