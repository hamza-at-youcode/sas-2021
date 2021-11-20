#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

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
        printf("\n\n***** Compte: [%d/%d] *****\n",i+1,nbrOfAc);
        createAccount(&a[i]);}
}

int findByCin(Account a[],char cin[],int nbrOfAc){
    for(int i=0;i<nbrOfAc;i++)
    if(strcmp(cin,a[i].cin) == 0) return i;
    return -1;
}

void withdrawal(Account *a,int nbrOfAc){
    char cin[20];
    float ammount;
    printf("\nEntrer le CIN: ");
    fflush(stdin);
    gets(cin);
    int index = findByCin(a,cin,nbrOfAc);
    if(index == -1){
    printf("\nIl n'ya pas une compte avec le CIN: %s\n",cin);
    return;}
    printf("\nEntrer le Mantant: ");
    fflush(stdin);
    scanf("%f",&ammount);
    printf("\nAncien Montant: %f",a[index].amt);
    a[index].amt-=ammount;
    printf("\nMontant Courant: %f",a[index].amt);
}

void deposit(Account *a,int nbrOfAc){
    char cin[20];
    float ammount;
    printf("\nEntrer le CIN: ");
    fflush(stdin);
    gets(cin);
    int index = findByCin(a,cin,nbrOfAc);
    if(index == -1){
    printf("\nIl n'ya pas une compte avec le CIN: %s\n",cin);
    return;}
    printf("\nEntrer le Mantant: ");
    fflush(stdin);
    scanf("%f",&ammount);
    printf("\nAncien Montant: %f",a[index].amt);
    a[index].amt+=ammount;
    printf("\nMontant Courant: %f",a[index].amt);
}

int main(){
    Account *ac;
    int nbrAc;
    printf("\nDonner le nombre des comptes a ajouter: ");scanf("%d",&nbrAc);
    ac = (Account*)malloc(nbrAc*sizeof(Account));
    _createAccounts(ac,nbrAc);
    _displayAccounts(ac,nbrAc);

    // TEST withrwal function
    deposit(ac,nbrAc);
    _displayAccounts(ac,nbrAc);
    


    return 0;
}