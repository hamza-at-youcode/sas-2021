#include<stdio.h>
#include<stdlib.h>

typedef struct account{
    char cin[20];
    char fname[20];
    char lname[20];
    float amt;
}Account;

void createAccount(Account *a){
    printf("\nEntrer le CIN: ");
    gets(a->cin);
    printf("\nEntrer le Nom: ");
    gets(a->lname);
    printf("\nEntrer le Prenom: ");
    gets(a->fname);
    printf("\nEntrer le Montant: ");
    scanf("%f",&a->amt);
}

void displayAccount(Account a){
    printf("\n\n****** CIN: %s ******\n",a.cin);
    printf("Nom: %s\n",a.lname);
    printf("Prenom: %s\n",a.fname);
    printf("Montant: %f DH\n",a.amt);
    printf("----------------------------\n");
}

int main(){
    Account *ac;
    ac = (Account*)malloc(sizeof(Account));
    createAccount(ac);
    displayAccount(*ac);


    return 0;
}