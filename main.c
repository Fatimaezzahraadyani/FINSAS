#include <stdio.h>
#include <stdlib.h>
int lentgh;
int i;
int indice; //l'indice de tache
int choix=0; //LE MENU
int nbrtache=0;//le nombre  de taches
int choixEdit;
int choixDate; //modifier la date
//declaration des structures :
typedef struct {
    int jour;
    int mois;
    int annee;
}date;
typedef struct {
    char titre [10];
    char discription [20];
    char priority [10];
date timeline ;
}taches;

taches T[100];

//la fonction qui permet  d'ajouter des taches :
void ajouter(){

    for (i=0;i<nbrtache;i++)
    printf("donnez les informations de la tache num %d : \n",i+1);
    printf("le titre : ");
    scanf("%s", T[i].titre);
    printf("la discription : ");
    scanf("%s", T[i].discription);
    printf("la priority : ");
    scanf("%s", T[i].priority);
    printf("la date d echeance : \n");
    printf("jour : ");
    scanf("%d", &T[i].timeline.jour);
    printf("mois : ");
    scanf("%d", &T[i].timeline.mois);
    printf("annee : ");
    scanf("%d", &T[i].timeline.annee);
    lentgh=i+1;
    nbrtache=lentgh;

}
//la fonction qui permet  d'afficher des infos sur les taches :
void afficher(){

    for (i=0;i<nbrtache;i++){
    printf("les informations de la tache num %d : \n",i+1);
    printf("le titre : %s \n", T[i].titre);
    printf("la discription : %s \n", T[i].discription);
    printf("la priority : %s \n", T[i].priority);
    printf("la date d echeance %d /%d / %d \n", &T[i].timeline.jour, &T[i].timeline.mois , &T[i].timeline.annee);

}
}
//la fonction qui permet de modifier des taches
void modifier(){
    printf("entrez l'indice de tache que vous voulez modifier : \n");
    scanf("%d",&i);
    if (i<=0 || i>nbrtache){
    printf("L'indice que vous voulez modifier n'existe pas \n");}
    else{
            printf("vous pouvez choisir l'element que vouz voulez modifier ou modifier tout \n");
     while(choixEdit!=6) {
        printf("1* Editer le titre \n");
        printf("2* Editer la discription \n");
        printf("3* Editer la priority \n");
        printf("4* Editer la date d'echeance \n");
        printf("5* Editer tout \n");
        printf("6* Quitter la liste \n");
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
        case 4: printf("***Menu de modification date*** \n");
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
        case 5:
            printf("Editer tout \n");
            //editer toutes les infos
        printf("entrer le nouveau titre : \n");
        scanf("%s",T[i-1].titre);
        printf("entrer la nouvelle discription : \n");
        scanf("%s", T[i-1].discription);
        printf("entrer la nouvelle priority : \n");
        scanf("%s", T[i-1].priority);
        printf("le nouveau jour est : \n");
        scanf("%d", &T[i-1].timeline.jour);
        printf("le nouveau mois est : \n");
        scanf("%d", &T[i-1].timeline.mois);
        printf("la nouvelle annee est : \n");
        scanf("%d", &T[i-1].timeline.annee);

        break;

        default: printf("entrez un nombre depuis la liste , merci de resseyer \n");
        break;
        }
        }
}
}
void supprimer(){
    printf("entrez l'indice de tache que vous voulez supprimer : \n");
    scanf("%d",&i);
        for(i=0;i<lentgh-1;i++){
            T[i] = T[i+1];
        }
        lentgh--;
        nbrtache--;
    printf(" \t Vous avez supprimer cette tache ! \n");

    afficher();

}


int main(){
    while(choix!=5) {
    printf("###################Voici la liste des operations que vous pouvez faire ###################: \n\n");

        printf("1* Ajouter des taches \n");
        printf("2* Afficher des infos sur les taches \n");
        printf("3* Modifier les taches \n");
        printf("4* Supprimer des taches \n");
        printf("5* Quitter la liste \n");
        printf("***entrez votre choix : \n");
        scanf("%d",&choix);
        switch (choix)
        {
        case 1: printf("\n§§§§§§§§§§§§ Ajouter des taches : §§§§§§§§§§§§ \n");
        ajouter();
        break;
        case 2: printf("§§§§§§§§§§§§ Afficher des info sur les taches : §§§§§§§§§§§§ \n");
        if (lentgh==0){
            printf("§§§§§§§§§§§§ Y'a pas des informations merci de resseyer §§§§§§§§§§§§\n\n");
        }else
            afficher();
        break;
        case 3: printf("§§§§§§§§§§§§ Modifier les taches : §§§§§§§§§§§§\n");
        if (lentgh==0){
            printf("§§§§§§§§§§§§ Y'a pas des informations merci de resseyer §§§§§§§§§§§§\n\n");
        }else
            modifier();
        break;
        case 4: printf("§§§§§§§§§§§§ Supprimer des taches §§§§§§§§§§§§ :\n");
        if (lentgh==0){
            printf("§§§§§§§§§§§§ Y'a pas des informations merci de resseyer §§§§§§§§§§§§\n\n");
        }else
            supprimer();
        break;
        case 5: printf("Quitter la liste \n");
        break;
        default: printf("§§§§§§§§§§§§ Entrez un choix depuis la liste afficher §§§§§§§§§§§§\n");
        break;
        }
        }


    return 0;
    }
