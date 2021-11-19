#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct account{
    char cin[20];
    char fname[20];
    char lname[20];
    float amt;
}Account;

void ascSort(Account *a,int len){
    bool s = 0; int i=0;
    do{
        for(int j=0;j<len-i-1;j++){
            if(a[j].amt > a[j+1].amt){
                Account tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;}
        }
        i++;
    }while(!s && i<len-1);
}

void descSort(Account *a,int len){
    bool s = 0; int i=0;
    do{
        for(int j=0;j<len-i-1;j++){
            if(a[j].amt < a[j+1].amt){
                Account tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;}
        }
        i++;
    }while(!s && i<len-1);
}

void createAccount(Account *a){
    printf("\nEntrer le CIN: ");
    fflush(stdin);
    gets(a->cin);
    printf("\nEntrer le Nom: ");
    fflush(stdin);
    gets(a->lname);
    printf("\nEntrer le Prenom: ");
    fflush(stdin);
    gets(a->fname);
    printf("\nEntrer le Montant: ");
    fflush(stdin);
    scanf("%f",&a->amt);
}

void displayAccount(Account a){
    printf("\n\n****** CIN: %s ******\n",a.cin);
    printf("Nom: %s\n",a.lname);
    printf("Prenom: %s\n",a.fname);
    printf("Montant: %f DH\n",a.amt);
    printf("----------------------------\n");
}

void _displayAccounts(Account a[],int len){
    for(int i=0;i<len;i++) displayAccount(a[i]);
}

void _createAccounts(Account *a,int nbrOfAc){
    for(int i=0;i<nbrOfAc;i++){
        printf("\n\n***** Compte: [%d/%d] *****\n",i,nbrOfAc);
        createAccount(&a[i]);}
}

int main(){
    Account *ac;
    int nbrAc;
    printf("\nDonner le nombre des comptes a ajouter: ");scanf("%d",&nbrAc);
    ac = (Account*)malloc(nbrAc*sizeof(Account));
    _createAccounts(ac,nbrAc);
    printf("\nBEFOR sorting:\n");
    _displayAccounts(ac,nbrAc);
    printf("\nAFTER sorting:\n");
    descSort(ac,nbrAc);
    _displayAccounts(ac,nbrAc);


    return 0;
}