#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void afficherMenu()
{
    printf("+-----------------------------------+\n|1 : Addition                       |\n|2 : Soustraction                   |\n|3 : Multiplication                 |\n|4 : Tables des multiplications     |\n|5 : Divisions                      |\n|0 : Sortir du jeu                  |\n+-----------------------------------+\nQuel est votre choix ?\t");
}

void addition(int *score)
{
    srand(time(NULL));
    int a = rand() % 101; // nombre aléatoire entre 0 et 100
    int b = rand() % 101; // nombre aléatoire entre 0 et 100
    int resultat = a + b;
    int reponse;

    printf("\nAddition :\n%d + %d = ?\nEntrer le résultat\t", a, b);
    scanf("%d", &reponse);
    printf("Vous avez entré : %d\n", reponse);

    if (reponse == resultat)
    {
        printf("Bravo !\n\n");
        (*score)++; // incrémentation du score
    }
    else
    {
        printf("Désolé, la bonne réponse est %d.\n\n", resultat);
    }
}

void multiplication(int *score)
{
    srand(time(NULL));
    int a = rand() % 10 +1; // nombre aléatoire entre 1 et 10
    int b = rand() % 10 +1; // nombre aléatoire entre 1 et 10
    int resultat = a * b;
    int reponse;

    printf("\nMultiplication :\n%d * %d = ?\nEntrer le résultat\t", a, b);
    scanf("%d", &reponse);
    printf("Vous avez entré : %d\n", reponse);

    if (reponse == resultat)
    {
        printf("Bravo !\n\n");
        (*score)++; // incrémentation du score
    }
    else
    {
        printf("Désolé, la bonne réponse est %d.\n\n", resultat);
    }
}

void division(int *score)
{
    srand(time(NULL));
    int a = rand() % 20 + 1; // nombre aléatoire entre 1 et 20
    int b = rand() % 9 + 2; // nombre aléatoire entre 2 et 10
    int resultat = a; // le dividende
    int reponse;

    printf("\nDivision :\n%d / %d = ? (entier uniquement)\nEntrer le résultat\t", a * b, b);
    scanf("%d", &reponse);
    printf("Vous avez entré : %d\n", reponse);

    if (reponse == a)
    {
        printf("Bravo !\n\n");
        (*score)++; // incrémentation du score
    }
    else
    {
        printf("Désolé, la bonne réponse est %d.\n\n", a);
    }
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

    printf("\nSoustraction :\n%d - %d = ?\nEntrer le résultat\t", max, min);
    scanf("%d", &reponse);
    printf("Vous avez entré : %d\n", reponse);

    if (reponse == resultat)
    {
        printf("Bravo !\n\n");
        (*score)++; // incrémentation du score
    }
    else
    {
        printf("Désolé, la bonne réponse est %d.\n\n", resultat);
    }
}

void choixtables(int *score)
{
    int n; // largeur de la table
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
    {}
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

void enregistrerScore(const char *nom, int score) {
    FILE *fichier = fopen("score/scores.csv", "a"); // Ouvrir en mode ajout
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier des scores.\n");
        return;
    }

    // Obtenir la date et l'heure actuelles
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Écrire les informations dans le fichier
    fprintf(fichier, "Nom: %s | Score: %d | Date: %02d/%02d/%04d %02d:%02d:%02d\n",
            nom, score, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900,
            tm.tm_hour, tm.tm_min, tm.tm_sec);

    fclose(fichier);
}

int main()
{
    char nom[50]; // tableau pour stocker le nom de l'utilisateur
    int choix;
    int score = 0; // initialisation du score

    printf("Entrez votre nom : ");
    scanf("%s", nom);

    afficherMenu();
    scanf("%d", &choix);

    while (choix != 0)
    {
        switch (choix)
        {
            case 1:
                addition(&score);
                break;
            case 2:
                soustraction(&score);
                break;
            case 3:
                multiplication(&score);
                break;
            case 4:
                choixtables(&score);
                break;
            case 5:
                division(&score);
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }

        printf("Score actuel : %d\n", score); // affichage du score actuel
        afficherMenu();
        scanf("%d", &choix);
    }

    printf("Merci d'avoir joué ! Votre score final est : %d\n", score); // affichage du score final
    enregistrerScore(nom, score); // enregistrement du score dans le fichier
    return 0;
}