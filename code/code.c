#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void afficherMenu()
{
    printf("+-----------------------------------+\n|1 : Addition                       |\n|2 : Soustraction                   |\n|3 : Multiplication                 |\n|4 : Tables des multiplications     |\n|5 : Divisions                      |\n|0 : Sortir du jeu et               |\n|    enregistrer le score           |\n+-----------------------------------+\nQuel est votre choix ?  ");
}

void gestionReponse(int resultat, int *score)
{
    int essaie = 3; // 3 essaie
    int reponse; // réponse de l'utilisateur

    while (essaie > 0)
    {
        printf("Entrer le résultat\t");
        scanf("%d", &reponse);
        printf("Vous avez entré : %d\n", reponse);
        if (reponse == resultat)
        {
            switch (essaie)
            {
                case 3:
                    printf("Bravo, vous gagnez 10 points!\n\n");
                    *score += 10; // incrémentation du score
                    return;
                case 2:
                    printf("Bravo ! Vous avez utilisé 2 essais. Vous gagnez donc 5 points.\n\n");
                    *score += 5; // incrémentation du score
                    return;
                case 1:
                    printf("Bravo ! Vous avez utilisé 3 essai. Vous ne gagnez donc qu'un point.\n\n");
                    *score += 1; // incrémentation du score
                    return;
            }
        }
        else
        {
            essaie--;
            if (essaie == 0){
                printf("Désolé, la bonne réponse est %d.\n\n", resultat);
            }
            else{
                printf("Désolé, ce n'est pas la bonne réponse. Il vous reste %d essais.\n\n", essaie);
            }
        }
    }
}

void addition(int *score)
{
    srand(time(NULL));
    int a = rand() % 101; // nombre aléatoire entre 0 et 100
    int b = rand() % 101; // nombre aléatoire entre 0 et 100
    int resultat = a + b;
    int reponse;
    int essaie = 3; // 3 essaie

    printf("\nAddition :\n%d + %d = ?\n", a, b);

    gestionReponse(resultat, score); // appel de la fonction pour gérer la réponse de l'utilisateur
}

void soustraction(int *score)
{
    srand(time(NULL));
    int a = rand() % 101; // nombre aléatoire entre 0 et 100
    int b = rand() % 101; // nombre aléatoire entre 0 et 100
    int max = (a > b) ? a : b;
    int min = (a > b) ? b : a;
    int resultat = max - min;
    int reponse;
    int essaie = 3; // 3 essaie

    printf("\nSoustraction :\n%d - %d = ?\n", max, min);

    gestionReponse(resultat, score); // appel de la fonction pour gérer la réponse de l'utilisateur
}

void multiplication(int *score)
{
    srand(time(NULL));
    int a = rand() % 10 +1; // nombre aléatoire entre 1 et 10
    int b = rand() % 10 +1; // nombre aléatoire entre 1 et 10
    int resultat = a * b;
    int reponse;
    int essaie = 3; // 3 essaie

    printf("\nMultiplication :\n%d * %d = ?\n", a, b);

    gestionReponse(resultat, score); // appel de la fonction pour gérer la réponse de l'utilisateur
}

void division(int *score)
{
    srand(time(NULL));
    int a = rand() % 20 + 1; // nombre aléatoire entre 1 et 20
    int b = rand() % 9 + 2; // nombre aléatoire entre 2 et 10
    int resultat = a; // le dividende
    int reponse;
    int essaie = 3; // 3 essaie

    printf("\nDivision :\n%d / %d = ? (entier uniquement)\n", a * b, b);

    gestionReponse(resultat, score); // appel de la fonction pour gérer la réponse de l'utilisateur
}

void choixTables(int *score)
{
    int n; // taille de la table
    int reponse; // réponse de l'utilisateur

    printf("Vous avez choisi les tables des multiplications.\nSur quelle table voulez-vous travailler (entrez la valeur maximale. Exemple : 10 pour une table de 1 à 10)\t");
    scanf("%d", &n);

    // Affichage de l'en-tête
    printf("\n   ");
    for (int i = 1; i <= n; i++)
    {
        printf("%4d", i);
    }
    printf("\n");

    // Affichage des lignes de la table
    for (int i = 1; i <= n; i++)
    {
        printf("%2d ", i); // Affichage de l'indice de ligne
        for (int j = 1; j <= n; j++)
        {
            printf("%4d", i * j); // Affichage du produit
        }
        printf("\n");
    }
    printf("Voulez vous remplir une colonne par vous même ? (1=Oui,0=Non)\t");
    scanf("%d", &reponse); // lecture de la réponse de l'utilisateur
    if (reponse == 1)
    {
        int colonne; // numéro de la colonne à remplir
        printf("Entrez le numéro de la colonne (1 à %d)\t", n);
        scanf("%d", &colonne); // lecture du numéro de la colonne

        if (colonne < 1 || colonne > n) // vérification de la validité du numéro de colonne
        {
            printf("Numéro de colonne invalide.\n");
            return;
        }

        for (int i = 1; i <= n; i++)
        {
            int reponse_utilisateur; // réponse de l'utilisateur pour chaque case de la colonne
            printf("Quel est le résultat de %d * %d ?\t", i, colonne); // question posée à l'utilisateur
            scanf("%d", &reponse_utilisateur); // lecture de la réponse de l'utilisateur

            if (reponse_utilisateur == i * colonne) // vérification de la réponse
            {
                printf("Bravo !\n");
                (*score)++; // incrémentation du score
            }
            else
            {
                printf("Désolé, la bonne réponse est %d.\n", i * colonne);
            }
        }
    }
}

char menuEnregistrement(int *nom,int *score, int lignejoeur) // fonction pour afficher le menu d'enregistrement et gérer le choix du joueur
{
    char choix;

    while (1==1)
    {
        printf("Bienvenue dans le jeu Champion des Maths !\n");
        printf("+-----------------------------------+\n|1 : Se connecter                   |\n|   (avec un nom d'utilisateur)     |\n|2 : ne pas se connecter            |\n+-----------------------------------+\nQuel est votre choix ?  ");
        scanf(" %c", &choix);

        while (getchar() != '\n');

        switch (choix)
        {
            case '1':
                printf("Entrez votre nom d'utilisateur :  ");
                scanf("%s", nom); // lecture du nom d'utilisateur
                // appel de la fonction pour lire le score
                if (lectureScore(nom,score,lignejoeur) == 0) // si le score n'est pas trouvé
                {
                    printf("Erreur, le score n'a pas pu être trouvé (verifiez bien que le nom d'utilisateur soit le même).\n\n");
                    break; // sortie de la boucle                    
                }
                return; // sortie de la fonction
            case '2':
                do {
                    printf("Entrez votre nom d'utilisateur : (ce nom doit être unique)  ");
                    scanf("%s", nom); // lecture du nom d'utilisateur
                    if (verifJoueur(nom) == 1) {
                        printf("Ce nom d'utilisateur existe déjà. Veuillez en choisir un autre.\n");
                    }
                } while (verifJoueur(nom) == 1);
                
                *score = 0; // initialisation du score à 0
                return choix; // sortie de la fonction
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
        
    }
}

int verifJoueur(char *nom_joueur) {    
    FILE *fichier = fopen("score/score.txt", "r");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return 1;
    }

    char ligne[256];
    int nom_trouve = 0;

    while (fgets(ligne, sizeof(ligne), fichier)) {
        // Créer une copie de la ligne car strtok modifie la chaîne
        char ligne_copy[256];
        strcpy(ligne_copy, ligne);
        
        // Récupère uniquement le nom (première partie avant la virgule)
        char *nom = strtok(ligne_copy, ",");

        if (strcmp(nom, nom_joueur) == 0) {
            nom_trouve = 1;
            break;
        }
    }

    fclose(fichier);
    return nom_trouve; // retourne 1 si le nom existe déjà, 0 sinon
}

// Fonction pour lire le score d'un joueur dans le fichier "score.txt"
int lectureScore(char *nom_joueur, int *score_joueur, int *lignejoueur) {    
    FILE *fichier = fopen("score/score.txt", "r");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    char ligne[256];
    int score_trouve = 0;
    int ligne_courante = 0;  // Compteur de lignes

    while (fgets(ligne, sizeof(ligne), fichier)) {
        // Créer une copie de la ligne car strtok modifie la chaîne
        char ligne_copy[256];
        strcpy(ligne_copy, ligne);
        
        // Séparer la ligne en éléments
        char *nom = strtok(ligne_copy, ",");// Récupère le nom
        char *score_str = strtok(NULL, ",");// Récupère le score
        char *date = strtok(NULL, "\n");// Récupère la date

        if (nom && score_str && date) {
            if (strcmp(nom, nom_joueur) == 0) {
                *score_joueur = atoi(score_str); // Convertit le score en entier
                printf("Score trouvé pour %s le %s : %d\n", nom_joueur, date, *score_joueur);
                score_trouve = 1;
                break;
            }
        }
        ligne_courante++; // Incrémente le compteur de lignes
    }
    *lignejoueur = ligne_courante; // Met à jour la ligne du joueur 

    fclose(fichier);
    return score_trouve; // retourne 1 si le score a été trouvé, sinon 0
}

int enregistrerScore(char *nom_joueur, int score,int lignejoueur) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    if (lignejoueur == -1) // Si le joueur n'existe pas dans le fichier
    {
        FILE *fichier = fopen("score/score.txt", "a"); // Ouvre le fichier en mode ajout
        if (fichier == NULL) {
            printf("Erreur d'ouverture du fichier.\n");
            return 0;
        }
        
        fprintf(fichier,"%s,%d,%02d/%02d/%04d à %02dh%02d\n",nom_joueur, score,tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900,tm.tm_hour, tm.tm_min);
        fclose(fichier);
    }
    else // Si le joueur existe déjà dans le fichier
    {
        FILE *fichier = fopen("score/score.txt", "r+"); // Ouvre le fichier en mode lecture/écriture
        if (fichier == NULL) {
            printf("Erreur d'ouverture du fichier.\n");
            return 0;
        }
        
        char ligne[256];
        int ligne_courante = 0;  // Compteur de lignes

        while (fgets(ligne, sizeof(ligne), fichier)) {
            if (ligne_courante == lignejoueur) { // Si on est à la ligne du joueur
                fseek(fichier, -strlen(ligne)-1, SEEK_CUR); // Reculer à la position de la ligne actuelle
                fprintf(fichier,"%s,%d,%02d/%02d/%04d à %02dh%02d\n",nom_joueur,score,tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900,tm.tm_hour, tm.tm_min);
                fclose(fichier);
                return 1; // Score mis à jour avec succès
            }
            ligne_courante++; // Incrémente le compteur de lignes
        }

        fclose(fichier);
    }
}

int main()
{
    char nom[50]; // tableau pour stocker le nom de l'utilisateur
    char choix;
    int score = 0; // initialisation du score
    int peutquitter; // variable pour savoir si l'utilisateur peut quitter le jeu
    int lignejoueur = -1; // variable pour stocker a quelle ligne se trouve le joueur dans le fichier score.txt (-1 veut dire a la fin)

    menuEnregistrement(nom,&score,&lignejoueur); // appel de la fonction pour afficher le menu d'enregistrement et la gestion du choix du joueur

    afficherMenu();
    scanf(" %c", &choix);

    while (1)
    {
        while (getchar() != '\n');
        {

        switch (choix)
        {
            case '1':
                addition(&score);
                break;
            case '2':
                soustraction(&score);
                break;
            case '3':
                multiplication(&score);
                break;
            case '4':
                choixTables(&score);
                break;
            case '5':
                division(&score);
                break;
            case '0':
                printf("Merci d'avoir joué %s ! Votre score final est : %d\n", nom, score);
                if (enregistrerScore(nom, score,lignejoueur)) {
                    printf("Score enregistré avec succès !\n");
                    return 1;
                } else {
                    printf("Erreur lors de l'enregistrement du score.\n");
                    return -1;
                }
            default:
                printf("Choix invalide. Veuillez réessayer.\n\n");
        }
        printf("Score actuel de %s : %d\n", nom, score); // affichage du score actuel
        afficherMenu();
        scanf(" %c", &choix);
        printf("");
    }
    }
}
