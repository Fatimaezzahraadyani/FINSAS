#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lentgh;
int i;
int indice; //l'indice de tache
int choix=0; //LE MENU
int n=0;//le nombre  de taches
int choixEdit;
int choixDate; //modifier la date
//declaration des structures :
//date d'echéance
typedef struct {
    int jour;
    int mois;
    int annee;

}date;
//les infos du chaque taches
typedef struct {
    char titre [100];
    char discription [40];
    char priority [40];
    char statut [20];
date timeline ;
}taches;

taches T[100];

//la fonction qui permet  d'ajouter des taches :
void ajouter(){

    //for (i=0;i<nbrtache;i++)
    printf("donnez les informations de la t%cche num %d : \n",131,n+1);
    printf("le titre : ");
    scanf(" %[^\n]s", T[n].titre);
    printf("la discription : ");
    scanf(" %[^\n]s", T[n].discription);
    printf("la priorit%c (high,meduim,low): ",130);
    scanf(" %[^\n]s", T[n].priority);
    printf("la statut (complete, incomplete) : ");
    scanf(" %[^\n]s",T[n].statut);
    printf("la date d'%cch%cance : \n",130,130);
    printf("jour : ");
    scanf("%d", &T[n].timeline.jour);
    printf("mois : ");
    scanf("%d", &T[n].timeline.mois);
    printf("annee : ");
    scanf("%d", &T[n].timeline.annee);
    lentgh++;
    n=lentgh;

}
//la fonction qui permet  d'afficher des infos sur les taches :
void afficher(){
    printf("les informations de(s) t%cche(s) %d : \n",131,i+1);
    printf("titre\t\tdiscription\t\tpriority\t\tstatut\t\tdate d'echeance\t \n");
    for (i=0;i<n;i++){
    //printf("titre \t discription \t priority \t statut \t date d'echeance");
    //printf("les informations de la t%cche num %d : \n",131,i+1);
    //printf("titre\t\tdiscription\t\tpriority\t\tstatut\t\tdate d'echeance\t \n");
    printf("%s \t", T[i].titre);
    printf("\t%s\t\t", T[i].discription);
    printf("\t%s\t\t", T[i].priority);
    printf("\t%s\t\t", T[i].statut);
    printf("%d/%d/%d\n", T[i].timeline.jour, T[i].timeline.mois , T[i].timeline.annee);
}
}
//la fonction qui permet de modifier des taches
void modifier(){
    printf("entrez l'indice de t%cche que vous voulez modifier : \n",131);
    scanf("%d",&i);
    if (i<=0 || i>n){
    printf("L'indice que vous voulez modifier n'existe pas \n");}
    else{
            printf("vous pouvez choisir l'element que vouz voulez modifier ou modifier tout \n");
     while(choixEdit!=7) {
        printf("[1] Editer le titre \n");
        printf("[2] Editer la discription \n");
        printf("[3] Editer la priority \n");
        printf("[4] Editer la statut \n");
        printf("[5] Editer la date d'echeance \n");
        printf("[6] Editer tout \n");
        printf("[7] Quitter la liste \n");
        printf("***entrez votre choix : \n");
        scanf("%d",&choixEdit);
        switch (choixEdit)
        {
        case 1: printf("entrer le nouveau titre : \n");
        scanf("%s",T[i-1].titre);
        break;
        case 2: printf("entrer la nouvelle discription : \n");
        scanf("%s", T[i-1].discription);
        break;
        case 3: printf("entrer la nouvelle priority : \n");
        scanf("%s", T[i-1].priority);
        break;
        case 4: printf("entrer la nouvelle statut : \n");
        scanf("%s", T[i-1].statut);
        case 5: printf("**Menu de modification date** \n");
        printf("\t 1.jour : \n");
        printf("\t 2.mois : \n");
        printf("\t 3.annee : \n");
        printf("\t ***entrez votre choix : \n");
        scanf("%d", choixDate);
        switch (choixDate){
            case 1:
                printf("le nouveau jour est : \n");
                scanf("%d", &T[i-1].timeline.jour);
            break;
            case 2:
                printf("le nouveau mois est : \n");
                scanf("%d", &T[i-1].timeline.mois);
            break;
            case 3:
                printf("la nouvelle annee est : \n");
                scanf("%d", &T[i-1].timeline.annee);
            break;
            default: printf("entrez un nombre de puis la liste \n");
            break;
        }
        case 6:
            printf("Editer tout \n");
            //editer toutes les infos
        printf("entrer le nouveau titre : \n");
        scanf("%s",T[i-1].titre);
        printf("entrer la nouvelle discription : \n");
        scanf("%s", T[i-1].discription);
        printf("entrer la nouvelle priority : \n");
        scanf("%s", T[i-1].priority);
        printf("entrer la nouvelle statut : \n");
        scanf("%s", T[i-1].statut);
        printf("le nouveau jour est : \n");
        scanf("%d", &T[i-1].timeline.jour);
        printf("le nouveau mois est : \n");
        scanf("%d", &T[i-1].timeline.mois);
        printf("la nouvelle annee est : \n");
        scanf("%d", &T[i-1].timeline.annee);
        break;
        case 7 : printf("vouz avez quitter la liste \n");
        break;
        default: printf("entrez un nombre depuis la liste , merci de resseyer \n");
        break;
        }
        }
}afficher();
}
void supprimer(){
    printf("entrez l'indice de tache que vous voulez supprimer : \n");
    scanf("%d",&i);
        for(i=0;i<lentgh-1;i++){
            T[i] = T[i+1];
        }
        lentgh--;
        n--;
    printf(" \t Vous avez supprimer cette tache ! \n");

    afficher();

}
//fonction pour filtrer les taches selon la priorite
void filtrer (){
    char Precherche[20];
    printf("veuillez entrez la priorite de votre tache \n");
    scanf("%s", &Precherche);
    int found = 0 ;
    for (i=0;i<n;i++){
        if(strcmp(T[i].priority, Precherche)==0){
             printf(" \t Tache trouvee ! ");
             printf("les informations de la tache num %d : \n",i+1);
             printf("le titre : %s \n", T[i].titre);
             printf("la discription : %s \n", T[i].discription);
             printf("la priority : %s \n", T[i].priority);
             printf("la statut : %s \n", T[i].statut);
             printf("la date d echeance %d /%d / %d \n", T[i].timeline.jour, T[i].timeline.mois , T[i].timeline.annee);
        found = 1;
        }
        if (found=0){
            printf(" \t Y'a aucune tache avec cette priorite \n");
            }

}
}
//fonction pour filtrer les taches selon la statut//
void search(){
    char Srecherche[20];
    printf("veuillez entrez la statut de votre tache \n");
    scanf("%s", &Srecherche);
    int found=0;
    for(i=0;i<n;i++){
        if(strcmp (T[i].statut , Srecherche)==0){
             printf("\t tache trouvee !");
             printf("les informations de la tache num %d : \n",i+1);
             printf("le titre : %s \n", T[i].titre);
             printf("la discription : %s \n", T[i].discription);
             printf("la priority : %s \n", T[i].priority);
             printf("la statut : %s \n", T[i].statut);
             printf("la date d echeance %d /%d / %d \n", T[i].timeline.jour, T[i].timeline.mois , T[i].timeline.annee);
        found = 1;
    }
}
        if (found==0){
     printf("\t Y'a aucune tache avec cette statut \n");
}
}

void Order(){
    int j;
    taches tmp;
    //tmp; //tmp just pour stocker les données
    for (i=0;i<n-1;i++){
        for (j=i+1;j<n;j++){
            if(T[i].timeline.annee > T[j].timeline.annee || T[i].timeline.annee==T[j].timeline.annee
               && T[i].timeline.mois > T[j].timeline.mois || T[i].timeline.mois==T[j].timeline.mois
                && T[i].timeline.jour > T[j].timeline.jour )
            {
                tmp = T[i];
                T[i] = T[j];
                T[j] = tmp;
            }
        }
    }afficher();
}
void decroissant(){
    int j;
    taches tmp;
    //tmp; //tmp just pour stocker les données
    for (i=0;i<
    n-1;i++){
        for (j=i+1;j>n;j++){
            if(T[i].timeline.annee < T[j].timeline.annee || T[i].timeline.annee==T[j].timeline.annee
               && T[i].timeline.mois < T[j].timeline.mois || T[i].timeline.mois==T[j].timeline.mois
                && T[i].timeline.jour < T[j].timeline.jour )
            {
                tmp = T[i];
                T[i] = T[j];
                T[j] = tmp;
            }
        }
    }afficher();
}



int main(){
    while(choix!=9) {
    printf("################### \t Voici la liste des operations que vous pouvez faire ###################: \n\n");

        printf("1* Ajouter des taches \n");
        printf("2* Afficher des infos sur les taches \n");
        printf("3* Modifier les taches \n");
        printf("4* Supprimer des taches \n");
        printf("5* Filtrer les taches selon la priority \n");
        printf("6* Filtrer les taches selon la statut \n");
        printf("7* order croissant \n");
        printf("8* order decroissant \n");
        printf("9* Quitter la liste \n");
        printf("***entrez votre choix : \n");
        scanf("%d",&choix);

        if (lentgh>0 || choix==1){
        switch (choix)
        {
        case 1: printf("\n§§§§§§§§§§§§ Ajouter des taches : §§§§§§§§§§§§ \n");
        ajouter();
        break;
        case 2: printf("§§§§§§§§§§§§ Afficher des info sur les taches : §§§§§§§§§§§§ \n");
        afficher();
        break;
        case 3: printf("§§§§§§§§§§§§ Modifier les taches : §§§§§§§§§§§§\n");
        modifier();
        break;
        case 4: printf("§§§§§§§§§§§§ Supprimer des taches §§§§§§§§§§§§ :\n");
        supprimer();
        break;
        case 5: printf(" §§§§§§§§§§§§ Filtrer selon la priority §§§§§§§§§§§§ \n");
        filtrer();
        break;
         case 6: printf(" §§§§§§§§§§§§ Filtrer selon la statut §§§§§§§§§§§§ \n");
        search();
        break;
         case 7: printf(" §§§§§§§§§§§§ Tri croissant §§§§§§§§§§§§ \n");
        Order();
        break;
        case 8: printf(" §§§§§§§§§§§§ Tri decroissant §§§§§§§§§§§§ \n");
        decroissant();
         case 9: printf("§§§§§§§§§§§§ Quitter la liste §§§§§§§§§§§§ \n");
        break;
        default: printf("§§§§§§§§§§§§ Entrez un choix depuis la liste afficher §§§§§§§§§§§§\n");
        break;
        }
        }else{
             printf("§§§§§§§§§§§§ Y'a pas des informations merci de resseyer §§§§§§§§§§§§\n\n");
        }



    }
    return 0;
}
