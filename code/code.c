#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void afficherMenu()
{
    printf("+-----------------------------------+\n|1 : Addition                       |\n|2 : Soustraction                   |\n|3 : Multiplication                 |\n|4 : Tables des multiplications     |\n|5 : Divisions                      |\n|0 : Sortir du jeu et               |\n|    enregistrer le score           |\n+-----------------------------------+\nQuel est votre choix ?\t");
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

void enregistrerScore(const char *nom, int score) {
    FILE *fichier = fopen("score/scores.csv", "a"); // Ouvrir en mode ajout
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier des scores.\n");
        return;
    }



}

int enregistrerScore() {
    FILE *fichier = fopen("score.txt","a");
    if (fichier == NULL){
        printf("Erreur d'ouverture du fichier.\n");
        return 0;
    }


}

int main()
{
    char nom[50]; // tableau pour stocker le nom de l'utilisateur
    char choix;
    int score = 0; // initialisation du score
    int peutquitter; // variable pour savoir si l'utilisateur peut quitter le jeu

    menuEnregistrement(); // appel de la fonction pour afficher le menu d'enregistrement et la gestion du choix du joueur

    afficherMenu();
    scanf(" %c", &choix);

    while (choix != '0')
    {
        while (getchar() != '\n');
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
                printf("Merci d'avoir joué ! Votre score final est : %d\n", score); // affichage du score final
                peutquitter = enregistrerScore(); // enregistrement du score dans le fichier
                if (peutquitter == 1){ //true
                    return 0;
                }
            default:
                printf("Choix invalide. Veuillez réessayer.\n\n");
        }
        choix = 0;
        printf("Score actuel : %d\n", score); // affichage du score actuel
        afficherMenu();
        scanf(" %c", &choix);
        printf("");
    }
}
