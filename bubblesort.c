#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void bubbleSort(char *arr[], int n, int ascending) {
    int i, j;
    char *temp;
    int swapped;
    
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        
        for (j = 0; j < n - i - 1; j++) {
            int comparison = strcmp(arr[j], arr[j + 1]);
            
            // Si ascending == 1, tri croissant; si ascending == 0, tri décroissant
            if ((ascending && comparison > 0) || (!ascending && comparison < 0)) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        
        if (swapped == 0) {
            break;
        }
    }
}

// Fonction pour trier les entiers
void bubbleSortInt(int arr[], int n, int ascending) {
    int i, j, temp;
    int swapped;
    
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        
        for (j = 0; j < n - i - 1; j++) {
            // Si ascending == 1, tri croissant; si ascending == 0, tri décroissant
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        
        if (swapped == 0) {
            break;
        }
    }
}

void printArray(char *arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("\"%s\" ", arr[i]);
    }
    printf("\n");
}

// Fonction pour afficher un tableau d'entiers
void printArrayInt(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Fonction pour afficher le menu principal
void afficherMenu() {
    printf("\n=== PROGRAMME DE TRI BUBBLE SORT ===\n");
    printf("Choisissez le type de données à trier :\n");
    printf("1. Nombres entiers\n");
    printf("2. Phrases/texte (alphanumérique)\n");
    printf("3. Quitter\n");
    printf("Votre choix (1-3) : ");
}

// Fonction pour afficher le menu de direction de tri
void afficherMenuTri() {
    printf("\nChoisissez la direction du tri :\n");
    printf("1. Croissant (A-Z / 1-9)\n");
    printf("2. Décroissant (Z-A / 9-1)\n");
    printf("Votre choix (1-2) : ");
}

// Fonction pour trier et afficher des entiers
void trierEntiers() {
    int nombres[] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50, 42};
    int n = sizeof(nombres) / sizeof(nombres[0]);
    int choix;
    
    printf("\n=== TRI DE NOMBRES ENTIERS ===\n");
    printf("Tableau original : ");
    printArrayInt(nombres, n);
    
    afficherMenuTri();
    scanf("%d", &choix);
    
    if (choix == 1) {
        bubbleSortInt(nombres, n, 1);  // Tri croissant
        printf("\nTableau trié (croissant) : ");
    } else if (choix == 2) {
        bubbleSortInt(nombres, n, 0);  // Tri décroissant
        printf("\nTableau trié (décroissant) : ");
    } else {
        printf("Choix invalide! Tri croissant par défaut.\n");
        bubbleSortInt(nombres, n, 1);
        printf("\nTableau trié (croissant) : ");
    }
    
    printArrayInt(nombres, n);
}

// Fonction pour trier et afficher des phrases
void trierPhrases() {
    char *phrases[] = {
        "Le chat mange sa nourriture",
        "Une belle journée ensoleillée",
        "Programming is fun",
        "Bonjour tout le monde",
        "123 est un nombre",
        "Apple pie recipe",
        "Zebra crossing"
    };
    int n = sizeof(phrases) / sizeof(phrases[0]);
    int choix;
    
    printf("\n=== TRI DE PHRASES/TEXTE ===\n");
    printf("Phrases originales :\n");
    printArray(phrases, n);
    
    afficherMenuTri();
    scanf("%d", &choix);
    
    if (choix == 1) {
        bubbleSort(phrases, n, 1);  // Tri croissant
        printf("\nPhrases triées (A-Z) :\n");
    } else if (choix == 2) {
        bubbleSort(phrases, n, 0);  // Tri décroissant
        printf("\nPhrases triées (Z-A) :\n");
    } else {
        printf("Choix invalide! Tri croissant par défaut.\n");
        bubbleSort(phrases, n, 1);
        printf("\nPhrases triées (A-Z) :\n");
    }
    
    printArray(phrases, n);
}

int main() {
    int choix;
    
    do {
        afficherMenu();
        scanf("%d", &choix);
        
        switch (choix) {
            case 1:
                trierEntiers();
                break;
            case 2:
                trierPhrases();
                break;
            case 3:
                printf("\nMerci d'avoir utilisé le programme de tri!\n");
                break;
            default:
                printf("\nChoix invalide! Veuillez choisir entre 1 et 3.\n");
                break;
        }
        
        if (choix != 3) {
            printf("\nAppuyez sur Entrée pour continuer...");
            getchar(); // Pour one tap le '\n' restant
            getchar(); // Pour attendre l'appui sur Entrée
        }
        
    } while (choix != 3);
    
    return 0;
}
