#include <stdio.h>
#include <cs50.h>
 
int main(void)
{
    long long num_cartao, cc_atual, divisor = 10;
    int soma1 =0, soma2 = 0, somaTotal, cont = 0; // variaveis para contagem
 
    do
    {
        printf(" Informe seu cartão de crédito: \n");
        scanf("%lld", &num_cartao); // esse scanf vai ler a variável e esse "d" é para dizer que é int
    }while(num_cartao <= 0);
 
    // 1 passo
    // a variavell capitada vai ser atribuida/quardada nessa
    cc_atual = num_cartao;
    while(cc_atual > 0)
    {
        int ultimoDig = cc_atual % 10; // vai encontar o resto (último dígito)
        soma1 = soma1 + ultimoDig; //e vai somar o ultimo digitar
        cc_atual = cc_atual / 100; // Isso vai fazer que se pular o numero alternadamente.  Pois o numero vai ser dividido constantemente e seu ultimo número vai sempre mudar .
    }
     // 2 passo
    cc_atual = num_cartao/10; // vamos trabalhar com o cartao atual de novo de uma forma reduzida. Pois a gente vai dividir por 10 e vai pegar os números que anteriormente foram pulados na soma1
     while(cc_atual > 0)
     {
          int ultimoDig = cc_atual % 10;
         int mult = ultimoDig *2;
           soma2 = soma2 + (mult %10 ) + (mult/ 10);  // isso aqui vai servir se o produto tiver mais que 1 algarismo, pois vai achar o modulo 10% dele que vai trazer o ultimo digito e depois soma com o outro dígito(que vai ser pego a partir atraves de de uma divisao por 10 )
       cc_atual = cc_atual / 100;  // isso aqui vai servir para reduzir o numero para pegar os valores pulados
     }
 
     // 3 passo
     somaTotal = soma1 + soma2;
 
     // verificar tamanho do cartao e ver seu inicio, para saber diferenciar o banco
     cc_atual = num_cartao;
     while(cc_atual != 0)
     {
         cc_atual = cc_atual / 10;
         cont++;
     }
       // pegar os 2 primeiros dígitos
     for (int i = 0; i < cont - 2; i++)
     {
         divisor = divisor* 10; // ficar 1000
     }
 
      int primeiroDig = num_cartao / divisor ; // esse primeiro ddígito é uma exceção pro cartão visa
      int doisPrimeiros = num_cartao / (divisor/10);
 
      if(somaTotal % 10 == 0)
      {
          if(primeiroDig == 4 && (cont == 13 || cont == 16))
          {
             printf(" Cartão VISA verificado!\n");
          }
          else if ((doisPrimeiros == 34 || doisPrimeiros == 37) && cont ==15)
          {
               printf(" Cartão AMERICAN EXPRESS verificado!\n");
          }
 
          else if ((doisPrimeiros > 50 && doisPrimeiros < 56) && cont ==16)
          {
               printf(" Cartão MASTERCARD verificado!\n");
          }
          else
          {
              printf("invalido");
          }
      }
 
}
 
 
 
