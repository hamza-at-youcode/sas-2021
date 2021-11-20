#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<conio.h>

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

char menu(){
    printf("\nPress any key to continue/ ");
    char c = getch();
    system("cls");
    printf("\n\n      ******** MENU ********\n");
    printf("   Clicker sur 1: pour introduire un compte bancaire.\n");
    printf("   Clicker sur 2: pour introduire plusieurs comptes bancaires.\n");
    printf("   Clicker sur 3: pour fair une Retrait .\n");
    printf("   Clicker sur 4: pour fair une Depot.\n");
    printf("   Clicker sur 5: pour afficher les comptes par order Ascendant.\n");
    printf("   Clicker sur 6: pour afficher les comptes par order Descendant.\n");
    printf("   Clicker sur 0: pour quiter.\n"); 
    printf("\n   Votre choi: "); 
    char ch;
    ch = getch();
    return ch;
}

int main(){
    Account *ac = NULL;
    int nbrAc = 0;
    char ch;
    do{
        ch = menu();
        switch(ch){
            case '1':{
                nbrAc++;
                if(ac == NULL) ac = (Account*)malloc(nbrAc*sizeof(Account));
                else ac = (Account*)realloc(ac,nbrAc*sizeof(Account));
                createAccount(&ac[nbrAc-1]);
            }break;
            case '2':{
                int n;
                printf("\nEntrer le nombre des comptes: ");
                fflush(stdin);
                scanf("%d",&n);
                // _createAccounts(ac,n);
            }break;

            case '3':{printf("\nWorking on it...");}break;
            case '4':{printf("\nWorking on it...");}break;
            case '5':ascSort(ac,nbrAc);_displayAccounts(ac,nbrAc);break;
            case '6':descSort(ac,nbrAc);_displayAccounts(ac,nbrAc);break;
        }
    }while(ch != '0');
    


    return 0;
}