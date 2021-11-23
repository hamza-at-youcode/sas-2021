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
    bool sorted = 1; int i=0;
    do{
        for(int j=0;j<len-i-1;j++){
            if(a[j].amt > a[j+1].amt){
                Account tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                sorted = 0;}
        }
        i++;
    }while(!sorted && i<len-1);
}

void descSort(Account *a,int len){
    bool sorted = 1; int i=0;
    do{
        for(int j=0;j<len-i-1;j++){
            if(a[j].amt < a[j+1].amt){
                Account tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                sorted = 0;}
        }
        i++;
    }while(!sorted && i<len-1);
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

void _displayAccounts(Account a[],int from,int to){
    for(int i=from;i<to;i++) displayAccount(a[i]);
}

void _createAccounts(Account *ac,int *currentNbrOfAc,int nbrAc){
    int a = *currentNbrOfAc;
    int b = a + nbrAc;

    if(ac == NULL) ac = (Account*)malloc(b*sizeof(Account));
    else ac = (Account*)realloc(ac,b*sizeof(Account));

    for(int i=a;i<b;i++){
        printf("\n\n***** Compte: [%d/%d] *****\n",i+1,b);
        createAccount(ac+i);}
    
    (*currentNbrOfAc) = b;
}

int findByCin(Account a[],char cin[],int nbrOfAc){
    for(int i=0;i<nbrOfAc;i++)
    if(strcmp(cin,a[i].cin) == 0) return i;
    return -1;
}

void startFrom(Account a[],float amt,int nbrAc,bool desc){
    int i;
    ascSort(a,nbrAc);
    if(amt<a[0].amt || amt > a[nbrAc-1].amt){
        printf("\nVeuillez fournir un montant entre %0.2f et %0.2f",a[0].amt,a[nbrAc-1].amt);
        return;
    }
    for (i = 0; i < nbrAc; i++) if (a[i].amt >= amt) break;
    if (desc) {
        descSort(a,nbrAc);
        _displayAccounts(a,0,nbrAc-i);
    }else _displayAccounts(a,i,nbrAc);
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
    if(a[index].amt == 0) {
        printf("\nCe compte est vide!!\n");
        return;
    }
    do{
        printf("\nEntrer le Mantant: ");
        printf("\n(Le montant doit etre inferieur ou egale: %f)\n",a[index].amt);
        printf("> ");
        fflush(stdin);
        scanf("%f",&ammount);
    }while((a[index].amt - ammount)<0);
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

void bonus(Account *ac,int nbrAc,float percentage){
    descSort(ac,nbrAc);
    for (int i = 0; i < 3; i++) ac[i].amt*=ac[i].amt*percentage;     
}

char menu(int nbrAc){
    printf("\nPress any key to continue/ ");
    char c = getch();
    system("cls");
    printf("\n\n      ******** MENU ********\n");
    printf("   Clicker sur 1: pour introduire un compte bancaire.\n");
    printf("   Clicker sur 2: pour introduire plusieurs comptes bancaires.\n");
    if(nbrAc == 0) return;
    printf("   Clicker sur 3: pour fair une Retrait .\n");
    printf("   Clicker sur 4: pour fair une Depot.\n");
    printf("   Clicker sur 5: pour afficher les comptes par order Ascendant.\n");
    printf("   Clicker sur 6: pour afficher les comptes par order Descendant.\n");
    printf("   Clicker sur 7: pour afficher par ordre ascendant\n\t\t  les comptes bancaires ayant un montant superieur\n\t\t  a un chiffre introduit.\n");
    printf("   Clicker sur 8: pour afficher par ordre descendant\n\t\t  les comptes bancaires ayant un montant superieur\n\t\t  a un chiffre introduit.\n");
    printf("   Clicker sur 9: pour fair une recherche par CIN.\n");
    printf("   Clicker sur b: Ajouter 1.3/100 aux comptes ayant les 3\n\t\t  premiers montants superieurs.\n");
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
        ch = menu(nbrAc);
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
                _createAccounts(ac,&nbrAc,n);
            }break;

            case '3':withdrawal(ac,nbrAc);break;
            case '4':deposit(ac,nbrAc);break;
            case '5':ascSort(ac,nbrAc);_displayAccounts(ac,0,nbrAc);break;
            case '6':descSort(ac,nbrAc);_displayAccounts(ac,0,nbrAc);break;
            case '7':{
                float amount;
                printf("\nEntrer le montant: "); scanf("%f",&amount);
                startFrom(ac,amount,nbrAc,0);
            }break;
            case '8':{
                float amount;
                printf("\nEntrer le montant: "); scanf("%f",&amount);
                startFrom(ac,amount,nbrAc,1);
            }break;
            case '9':{
                char c[20];
                printf("\nEntrer le cin: ");
                fflush(stdin);
                gets(c);
                int index = findByCin(ac,c,nbrAc);
                if(index == -1) printf("\nIl n'ya pas une compte avec le CIN: %s\n",c);
                else displayAccount(ac[index]);
            }break;
            case 'b':{
                char c;
                printf("Etes-vous sur de vouloir ajouter 1,3/100 aux trois premiers comptes?(y|n)");
                c = getch();
                if (c == 'y') bonus(ac,nbrAc,1.3);
            }
            case '0': free(ac);
        }
    }while(ch != '0');
    return 0;
}