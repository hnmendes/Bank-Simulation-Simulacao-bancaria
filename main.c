/* PROGRAMA DE LISTAS FUNCIONAIS */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#include <locale.h>
#include <time.h>


typedef struct {

  char nconta[8]; //N�mero da conta
  float saldo; //Saldo cliente
  char nome[61]; //Nome cliente
  char cpf[12]; //Cpf cliente
  char telefone[12]; //Telefone cliente
  int ativo;

}Usuario;

Usuario cliente[MAX];

int cont=1,busc=0;

void menu();
void cadastrarClientes(Usuario *x);
void removerClientes();
int buscar(Usuario *cl, char *conta);
void listarClientes();
void consultarSaldoClientes(Usuario* x, char nrConta[8]);
void checarNumCPF(Usuario* x);
void checarNumTel(Usuario* x);
void checarNumConta(Usuario* x);
void buscarsw(Usuario* x);
void consultarsw(Usuario* x);
void depositarsw(Usuario* x);
void saquesw(Usuario* x);

int main(){

setlocale(LC_ALL,"");

menu();


return 0;

}

void menu(){
    system("CLS");
    char nCont[8];
    int chec;

    system("CLS");

    do{
        system("CLS");
        printf("Bem vindo ao Banco--Dinheiro--Certo\n\n");
        printf("Digite 1 para cadastrar uma conta.\n");
        printf("Digite 2 para buscar uma conta pelo seu n�.\n");
        printf("Digite 3 para consultar o saldo de uma conta.\n");
        printf("Digite 4 para fazer dep�sito em uma conta.\n");
        printf("Digite 5 para fazer saque de uma conta.\n");
        printf("Digite 6 para entrar no menu administrativo e acessar todas as contas.\n");
        printf("Digite 7 para entrar no menu administrativo e remover uma conta.\n");
        printf("Digite 0 para sair do programa.\n");

        printf("Sua op��o: ");
        scanf("%d",&chec);
        getchar();
        switch(chec){

        case 1:
            cadastrarClientes(cliente);
        break;

        case 3:
            system("cls");
            consultarsw(cliente);
        break;

        case 4:
            system("cls");
            depositarsw(cliente);
        break;

        case 5:
            system("cls");
            saquesw(cliente);
        break;

        case 6:
            listarClientes(cliente);
        break;

        case 7:

            system("cls");

            printf("Digite um n�mero de conta para remover:\n");
            scanf("%s",nCont);

            removerClientes(cliente,nCont);

            system("pause");
            break;
        break;

        case 2:
            system("cls");
            buscarsw(cliente);
        break;

        }
        getchar();

    }while(chec!=0);//////////////

}

void cadastrarClientes(Usuario* x){

    system("cls");


    int chec;

    do{

        checarNumConta(x);

        while(strlen(x[cont].nconta) == 0){
            printf("Digite alguma coisa, seu cabra...\n");
            checarNumConta(x);
        }

        fflush(stdin);

        printf("\nNome:\n");
        fgets(x[cont].nome,sizeof(x[cont].nome)-1,stdin);


        while(strlen(x[cont].nome) == 0){
            printf("Digite alguma coisa, seu cabra...\n");
            fgets(x[cont].nome,sizeof(x[cont].nome)-1,stdin);
        }

        checarNumCPF(x);

        while(strlen(x[cont].cpf) == 0){
            printf("Digite alguma coisa, seu cabra...\n");
            checarNumCPF(x);
        }

        checarNumTel(x);

        while(strlen(x[cont].telefone) == 0){
            printf("Digite alguma coisa, seu cabra...\n");
            checarNumTel(x);
        }

        x[cont].saldo = 0.0;

        system("cls");

        x[cont].ativo = 1;
        printf("Seu n�mero da conta �: %s  [ATEN��O: N�O DEIXE DE ANOTAR]",x[cont].nconta);
        printf("\n\n\nCADASTRO REALIZADO COM SUCESSO...\n\n\n");
        printf("\a\a");

        cont++;

        printf("Digite sim para continuar a fazer mais cadastros.\nDigite n�o para voltar ao menu.\n");
        scanf("%d",&chec);

        system("cls");


    }while(chec==1);

}

void listarClientes(Usuario *x){

    system("cls");

    int i,j;

    printf("\n-------Lista de clientes--------\n\n");

        for(i=1;i<cont;i++){
        for(j=i+1;j<cont;j++){
            if( strcoll(x[i].nome, x[j].nome) > 0){
                x[0] = x[i];
                x[i] = x[j];
                x[j] = x[0];
            }
        }
    }

        for(i=1; i<cont; i++){
            if(x[i].ativo==1){
                printf("\n\n--------Cliente [%d]------------\n",i);
                fflush(stdin);
                printf("\nN�mero da Conta: %s",x[i].nconta);
                printf("\nNome: %s\n",x[i].nome);
                printf("CPF: %s\n",x[i].cpf);
                printf("Telefone: %s\n",x[i].telefone);
                printf("Saldo: %f\n",x[i].saldo);
                printf("\n--------------------------------\n\n");
        }
    }



}

int buscar(Usuario *cl,char *conta){

    int i;

    for(i=1; i<cont; i++){

    if(strcmp(cl[i].nconta, conta)==0){

        return i;

    }else

    if(strlen(cl[i].nconta)!=0 && strcmp(cl[i].nconta, conta)!=0 ){

        return -1;

    }

    }

        return -2;

}

void removerClientes(Usuario *x){

    int i;

        for(i=1; i < cont; i++){

            int res = buscar(x, x[i].nconta);

            if(res!=-1 && res!=-2 && x[i].saldo == 0.0 && x[i].ativo == 1){
                    x[i].ativo=0;
                    printf("\n\nCliente removido com sucesso.\n\n");
            }else if(res!=-1 && res!=-2 && x[i].saldo != 0.0 && x[i].ativo == 1){
                    printf("\n\nCliente n�o pode ser removido, pois seu saldo � superior a zero.\n\n");
            }else{
                    printf("\nConta n�o encontrada ou o cadastro est� vazio.\n");
            }
        }
}

void consultarSaldoClientes(Usuario* x,char nrConta[8]){

    system("cls");

    int i;
    int res = buscar(x, nrConta);

    for(i=1; i < cont; i++){

            if(res!=-1 && res!=-2 && x[res].ativo == 1){
                    printf("\n\nO saldo do cliente %s � de R$%2.f.\n\n",x[res].nome, x[res].saldo);
                    system("pause");
            }else{
                    printf("\nConta n�o encontrada.\n");
                    system("pause");
                    getchar();
            }
        }

}

 void checarNumCPF(Usuario* x){

    int cpfi;

        while(1){
        printf ("\nCPF:\n");
        fgets(x[cont].cpf,11,stdin);
        fflush(stdin);
        if (sscanf (x[cont].cpf, "%d", &cpfi) != 1)
        {
            fprintf (stderr, "Por favor, entre com um valor num�rico.\n");
        }
        else
        {
            break;
        }

        }

}

void checarNumTel(Usuario* x){    //Tratar telefone

    int teli;

        while(1){
        printf ("\nTelefone:\n");
        fgets (x[cont].telefone,11,stdin);

        if (sscanf (x[cont].telefone, "%d", &teli) != 1)
        {
            fprintf (stderr, "Por favor, entre com um valor num�rico.\n");
        }
        else
        {
            break;
        }

        }

}

void checarNumConta(Usuario* x){

    int contai;

        while(1){
        printf ("Conta:\n");
        fgets (x[cont].nconta,7,stdin);
        fflush(stdin);

        int res = buscar(x,x[cont].nconta);

        if(res!= -1 && res != -2){
            system("cls");
            printf("Conta j� est� cadastrada, por favor, insira outra.\n\n");
            checarNumConta(x);
        }

        if (sscanf (x[cont].nconta, "%d", &contai) != 1)
        {
            fprintf (stderr, "Por favor, entre com um valor num�rico.\n");
        }
        else
        {
            break;
        }

        }

}

void buscarsw(Usuario* x){

    while(1){
        printf ("Digite uma conta a ser buscada:\n");
        fgets (x[cont].nconta,7,stdin);
        fflush(stdin);

        int res = buscar(x,x[cont].nconta);

        if(res!= -1 && res != -2){
            system("cls");
            printf("A conta foi encontrada.\n\n");
            printf("\a\a");
            break;
        }else{
            printf("A conta n�o pode ser encontrada.\n\n");
            break;
        }
    }
}

void consultarsw(Usuario* x){

    while(1){
        printf ("Digite uma conta para consultar seu saldo:\n");
        fgets (x[cont].nconta,7,stdin);
        fflush(stdin);

        int res = buscar(x,x[cont].nconta);

        if(res!= -1 && res != -2){
            system("cls");
            printf("A conta foi encontrada e seu saldo � de R$%2.f .\n\n",x[res].saldo);
            printf("\a\a");
            break;
        }else{
            printf("A conta n�o pode ser encontrada.\n\n");
            break;
        }
    }
}

void saquesw(Usuario* x){

    float quant;

    while(1){
        printf ("Digite uma conta para que tenha o saque:\n");
        fgets (x[cont].nconta,7,stdin);
        fflush(stdin);

        int res = buscar(x,x[cont].nconta);

        if(res!= -1 && res != -2){
            system("cls");
            printf("\nO saldo dessa conta � R$%2.f .",x[res].saldo);
            printf("\nDigite a quantidade que deseja sacar da conta:\n");
            scanf("%f",&quant);
                if(quant>0 && quant<=x[res].saldo){
                    x[res].saldo= x[res].saldo - quant;
                    printf("\nDinheiro sacado com sucesso!!\n");
                    printf("\a\a");
                }else{
                    printf("\nQuantidade precisa estar dentro dos limites do saldo da conta acessada.\n");

                }

        break;

        }else{
            printf("A conta n�o pode ser encontrada.\n\n");
            break;
        }
    }
}

void depositarsw(Usuario* x){

    float quant;

    while(1){
        printf ("Digite uma conta para que deposite nela:\n");
        fgets (x[cont].nconta,7,stdin);
        fflush(stdin);

        int res = buscar(x,x[cont].nconta);

        if(res!= -1 && res != -2){
            system("cls");
            printf("\nO saldo dessa conta � R$%2.f .",x[res].saldo);
            printf("\nDigite a quantidade que deseja depositar na conta:\n");
            scanf("%f",&quant);
                if(quant>0){
                    x[res].saldo= x[res].saldo + quant;
                    printf("\nDinheiro depositado com sucesso!!\n");
                    printf("\a\a");
                }else{
                    printf("\nQuantidade deve ser maior que zero.\n");
                    system("pause");
                    system("cls");
                    depositarsw(x);

                }

        break;

        }else{
            printf("A conta n�o pode ser encontrada.\n\n");
            break;
        }
    }
}
