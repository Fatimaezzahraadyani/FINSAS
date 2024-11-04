#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int length=0;
int i;
int indice; //l'indice de tache
int choix=0; //LE MENU
int n=0;//le nombre  de taches
int choixEdit; // menu de modification
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
    char statue [20];
date timeline ;
}taches;

taches T[100];
//validation de date
void valide(taches T[]){
    do{
        printf("jour : ");
        scanf("%d", &T[n].timeline.jour);
    }while(T[n].timeline.jour < 1 || T[n].timeline.jour > 31);

    do{
        printf("mois : ");
        scanf("%d", &T[n].timeline.mois);
    }while(T[n].timeline.mois < 1 || T[n].timeline.mois > 12);

    do{
        printf("annee : ");
        scanf("%d", &T[n].timeline.annee);
    }while(T[n].timeline.annee < 2024 );

}

//la fonction qui permet  d'ajouter des taches :
void ajouter(){

    printf("donnez les informations de la t%cche num %d : \n",131,n+1);
    printf("le titre : ");
    scanf(" %[^\n]s", T[n].titre);
    printf("la discription : ");
    scanf(" %[^\n]s", T[n].discription);
    do{
        printf("la priorit%c (high,meduim,low): ",130);
        scanf(" %[^\n]s", T[n].priority);
    } while(strcmp(T[n].priority,"high")!=0  &&              //l'utilisateur doit entrer obligatoirement la priorite valide //
           strcmp(T[n].priority , "meduim")!=0 &&
           strcmp(T[n].priority, "low")!=0 );
    do{
        printf("la statut (complete, incomplete) : ");
        scanf(" %[^\n]s",T[n].statue);
    }while (strcmp(T[n].statue, "complete")!=0 &&             //l'utilisateur doit entrer obligatoirement la statue valide //
            strcmp(T[n].statue , "incomplete")!=0 );

    printf("la date d'%cch%cance : \n",130,130);
    valide(T);                                                    //l'utilisateur doit entrer obligatoirement la date valide //
    length++;
    n=length;

}
//la fonction qui permet  d'afficher des infos sur les taches :
void afficher(){
    for (i=0;i<n;i++){
    printf("-----------------------------------------\n");
    printf("les informations de la tache num %d : \n",i+1);
    printf("le titre : %s \n", T[i].titre);
    printf("la discription : %s \n", T[i].discription);
    printf("la priority : %s \n", T[i].priority);
    printf("la statut : %s \n", T[i].statue);
    printf("la date d echeance : %02d/%02d/%d \n", T[i].timeline.jour, T[i].timeline.mois , T[i].timeline.annee);
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
        printf("[4] Editer la statue \n");
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
        case 3:
            do{
            printf("entrer la nouvelle priority : \n");
            scanf("%s", T[i-1].priority);
            } while(strcmp(T[i-1].priority,"high")!=0  &&
           strcmp(T[i-1].priority , "meduim")!=0 &&
           strcmp(T[i-1].priority, "low")!=0 );
        break;
        case 4: do{
            printf("entrer la nouvelle statue : \n");
            scanf("%s", T[i-1].statue);
        }while (strcmp(T[i-1].statue,"complete")!=0  &&
               strcmp(T[i-1].statue , "incomplete")!=0);
        break;
        case 5: printf("Menu de modification date \n");
        printf("\t 1.jour : \n");
        printf("\t 2.mois : \n");
        printf("\t 3.annee : \n");
        printf("\t 4.quitter : \n");
        printf("\t ***entrez votre choix : \n");
        scanf("%d", &choixDate);
        switch (choixDate){
            case 1:
               do{
                printf("le nouveau jour est : \n");
                scanf("%d", &T[i-1].timeline.jour);
                } while(T[i-1].timeline.jour < 1 || T[i-1].timeline.jour > 31);
            break;
            case 2:
                do{
                printf("le nouveau mois est : \n");
                scanf("%d", &T[i-1].timeline.mois);
                } while(T[i-1].timeline.mois < 1 || T[i-1].timeline.mois > 12);
               // valide(T);
            break;
            case 3:
                do{
                printf("la nouvelle annee est : \n");
                scanf("%d", &T[i-1].timeline.annee);
                }while(T[i-1].timeline.annee < 2024 );
            break;
            case 4:
                printf("\t vous avez quitter la liste ! \n");
            break;
            default: printf("entrez un nombre de puis la liste \n");
            break;
        }
        break;
        case 6:
            printf("Editer tout \n");
            //editer toutes les infos
        printf("entrer le nouveau titre : \n");
        scanf("%s",T[i-1].titre);
        printf("entrer la nouvelle discription : \n");
        scanf("%s", T[i-1].discription);
        printf("entrer la nouvelle priority : \n");
        scanf("%s", T[i-1].priority);
        printf("entrer la nouvelle statue : \n");
        scanf("%s", T[i-1].statue);
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
     if (i<=0 || i>n){
    printf("L'indice que vous voulez modifier n'existe pas \n");
    }else {
    for(i=0;i<length-1;i++){
            T[i] = T[i+1];
        }
        length--;
        n--;
    printf(" \t Vous avez supprimer cette tache ! \n");

    afficher();

}
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
             printf("la statut : %s \n", T[i].statue);
             printf("la date d echeance %d /%d / %d \n", T[i].timeline.jour, T[i].timeline.mois , T[i].timeline.annee);
        found = 1;
        }
        if (found=0){
            printf(" \t Y'a aucune tache avec cette priorite \n");
            }

}
}
//fonction pour filtrer les taches selon la statue//
void search(){
    char Srecherche[20];
    printf("veuillez entrez la statut de votre tache \n");
    scanf("%s", &Srecherche);
    int found=0;
    for(i=0;i<n;i++){
        if(strcmp (T[i].statue , Srecherche)==0){
             printf("\t tache trouvee !");
             printf("les informations de la tache num %d : \n",i+1);
             printf("le titre : %s \n", T[i].titre);
             printf("la discription : %s \n", T[i].discription);
             printf("la priority : %s \n", T[i].priority);
             printf("la statue : %s \n", T[i].statue);
             printf("la date d echeance %d /%d / %d \n", T[i].timeline.jour, T[i].timeline.mois , T[i].timeline.annee);
        found = 1;
    }
}
        if (found==0){
     printf("\t Y'a aucune tache avec cette statue ! \n");
}
}

//ordinner les taches par order croissant
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

//ordinner les taches par order decroissant
void decroissant(){
    int j;
    taches tmp;
    //tmp; //tmp just pour stocker les données
    for (i=0;i<n-1;i++){
        for (j=i+1;j<n;j++){
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
void fichier(){
       FILE *fich  ;
    fich = fopen("fich.txt","w");
    for(i=0;i<n;i++){
        fprintf(fich, "titre : %s \n" , T[i].titre);
        fprintf(fich, "discription : %s \n" , T[i].discription);
        fprintf(fich, "priority : %s \n" , T[i].priority);
        fprintf(fich, "statue : %s \n" , T[i].statue);
        fprintf(fich , "date d echeance : %d / %d /%d \n", T[i].timeline.jour,T[i].timeline.mois,T[i].timeline.annee);

}
    fclose(fich);
}



int main(){
    while(choix!=10) {
    printf("################### \t Voici la liste des operations que vous pouvez faire ###################: \n\n");

        printf("1* Ajouter des taches \n");
        printf("2* Afficher des infos sur les taches \n");
        printf("3* Modifier les taches \n");
        printf("4* Supprimer des taches \n");
        printf("5* Filtrer les taches selon la priority \n");
        printf("6* Filtrer les taches selon la statue \n");
        printf("7* order croissant \n");
        printf("8* order decroissant \n");
        printf("9* enregistrer les infos \n");
        printf("10* Quitter la liste \n");
        printf("***entrez votre choix : \n");
        scanf("%d",&choix);

        if (length>0 || choix==1){
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
         case 6: printf(" §§§§§§§§§§§§ Filtrer selon la statue §§§§§§§§§§§§ \n");
        search();
        break;
         case 7: printf(" §§§§§§§§§§§§ Tri croissant §§§§§§§§§§§§ \n");
        Order();
        break;
        case 8: printf(" §§§§§§§§§§§§ Tri decroissant §§§§§§§§§§§§ \n");
        decroissant();
        break;
        case 9 : printf("§§§§§§§les informations sont enregitrer §§§§§§§§§§§§ \n");
        fichier();
        break;
        default: printf("§§§§§§§§§§§§ Entrez un choix depuis la liste afficher §§§§§§§§§§§§\n");
        break;
        }
        }else if(choix !=10 && (length<0 || choix!=1)){
             printf("§§§§§§§§§§§§ Y'a pas des informations merci de resseyer §§§§§§§§§§§§\n\n");
        }
        if(choix==10)
        {printf("§§§§§§§§§§§§ Quitter la liste §§§§§§§§§§§§ \n");
        }



    }




return 0;
}
