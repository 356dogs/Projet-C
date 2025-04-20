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

void choixtables()
{
    int n; // largeur de la table
    
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
}

int main()
{
    int choix;
    int score = 0; // initialisation du score

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
                choixtables();
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
    return 0;
}