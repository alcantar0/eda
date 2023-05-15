#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_tabela(int vetor[], int n){
    for (int x= 0; x < n; x++)
        {
            printf("%d ", vetor[x]);
        }
    puts("\n");
}
void zerar(int* tabela, int t){
    for (int i = 0; i < t; i++)
    {
        tabela[i]=0;
    }
    
}
void divisao(int* tabela, int chave, int t){
    int x = t % chave;
    printf("aqui %d\n", x);
    tabela[x] = chave;
}

void dobra(int* tabela, char* chave, int t){
    unsigned int hash = 0;
    for (int i = 0; chave[i]!='\0'; i++)
    {
        hash += (unsigned int)chave[i] - '0';
    }

    hash = hash % t;

    tabela[hash] = atoi(chave);

}

int main(){
    /*
    int tabela[100];
    print_tabela(tabela, 100);
    zerar(tabela, 100);
    divisao(tabela, 23, 100);
    divisao(tabela, 50, 100);
    print_tabela(tabela, 100);
    */

    int tabela2[10];
    zerar(tabela2, 10);
    dobra(tabela2, "98", 10);
    print_tabela(tabela2, 10);

    /*
    int x =12;
    int y= 10;

    printf("%d\n", x % y);
    printf("%d\n", y % x);
    */

    return 0;
}