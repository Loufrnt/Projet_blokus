#include "matrice.h"
#include "structures.h"

/**
 * \file matrice.c
 * \brief Ensemble de fonctions servants à l'utilisation des matrices.
 * \author Friant Marilou Tourpe Florian Semamra Kevin Amillard Joris
 * \version 1
 *
 * \fn void init_matrice (t_matrice* matrice)
 * \brief Fonction qui initialise une matrice de taille 5x5.
 * \param matrice Pointeur de type t_matrice contenant la matrice a initialiser.
 *
 * \fn void afficher_matrice (t_matrice matrice) 
 * \brief Affiche tous les elements de la liste, utile au debug et pour afficher la piece selectionnee
 * \param matrice Variable de type t_matrice.
 *
 * \fn void copie_matrice(t_matrice* source, t_matrice* copie)
 * \brief Copie le contenu de la marice source vers la marice copie.
 * \param source Variable de type t_matrice.
 * \param copie Variable de type t_matrice.
 *
 * \fn void insertion_matrice_piece(t_matrice* matrice, t_coordonnee coord)
 * \brief Affecte a la structure t_matrice les coordonnees d'une piece contenues dans la variable coord
 * \param matrice Pointeur de type t_matrice qui recoit l'affectation dans son champ mat.
 * \param coord Variable de type t_coordonnee comportant les coordonnees de la piece.
 *
 * \fn void insertion_num_piece(t_matrice* matrice, int numero)
 * \brief Affecte a la structure t_matrice un numero de piece
 * \param matrice Pointeur de type t_matrice qui recoit l'affectation dans son champ num.
 * \param numero Variable de type integer contenant le numero de la piece.
 *
 * \fn void insertion_taille_piece(t_matrice* matrice, int taille_piece)
 * \brief Affecte a la structure t_matrice la taille d'une piece dans son champ taille.
 * \param matrice Pointeur de type t_matrice qui recoit l'affectation.
 * \param numero Variable de type integer contenant la taille de la piece.
 *
 * \fn void miroir_horizontal (int mat [5][5])
 * \brief Effecue une rotation horizontale sur la matrice passee en parametre
 * \param matrice Matrice de type integer contenant la piece a tourner.
 *
 * \fn void miroir_vertical (int mat [5][5]) 
 * \brief Effecue une rotation verticale sur la matrice passee en parametre
 * \param matrice Matrice de type integer contenant la piece a tourner.
 *
 * \fn void tourner_piece (int mat [5][5])
 * \brief Effecue une rotation a 90 degre sur la matrice passee en parametre
 * \param matrice Matrice de type integer contenant la piece a tourner.
 *
 * \fn void rotation (int mat [5][5], int sens)
 * \brief Fonction appelant tourner_piece mais permettant de faire plusieurs rotations d'un coup.
 * \param matrice Matrice de type integer contenant la piece a tourner.
 * \param sens Variable de type integer donnant le nombre de rotation a effectuer.
 *
 */

void init_matrice (t_matrice* matrice) {
	int i, j;

	matrice->taille = 0;
	matrice->num = 0;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++)
			matrice->mat[i][j] = 0;
	}
}

void afficher_matrice (t_matrice matrice) {
	int i, j;

	for (i = 0; i < 5; i++) {
		for ( j = 0; j < 5; j++){
            if(matrice.mat[i][j] == 0){
                printf("|   ");
            }else{
                printf("| X ");
            }
		}
		printf("|");
		printf("\n");
	}
	printf("num = %i\n", matrice.num+1); // !! ATTTENTION n'affiche pas le numeros contenue dans la memoire
    printf("taille = %i\n", matrice.taille);
    printf("\n");
}


void copie_matrice(t_matrice* source, t_matrice* copie){
    int i,j;

    copie->num = source->num;
    copie->taille = source->taille;

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            copie->mat[i][j]  = source->mat[i][j];
        }
    }
}


void insertion_matrice_piece(t_matrice* matrice, t_coordonnee coord){ 
    matrice->mat[coord.x][coord.y] = 1;
}


void insertion_num_piece(t_matrice* matrice, int numero){ 
    matrice->num = numero;
}


void insertion_taille_piece(t_matrice* matrice, int taille_piece){
    matrice->taille = taille_piece;
}


void miroir_horizontal (int mat [5][5]) {
    int i, j, tampon, max = 4;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 5; j++) {
            tampon = mat [i][j];
            mat [i] [j] = mat [max - i] [j];
            mat [max - i] [j] = tampon;
        }
    }
}


void miroir_vertical (int mat [5][5]) {
    int i, j, tampon, max = 4;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            tampon = mat [i][j];
            mat [i] [j] = mat [i] [max - j];
            mat [i] [max - j] = tampon;
        }
    }
}


void tourner_piece (int mat [5][5]) {
    int i,j, tampon, max = 4;

    for (j = 0; j < 3; j++) {
        for (i = j; i < max - j; i++) {
            tampon = mat[i] [j] ;
            mat[i] [j] = mat[max - j] [i];
            mat[max - j] [i] = mat[max - i] [max - j];
            mat[max - i] [max-j] = mat[j] [max - i];
            mat[j] [max - i] = tampon;
        }
    }
}

/*
sens = 1 rotation droite
sens = 2 retourner
sens = 3 rotation gauche
*/
void rotation (int mat [5][5], int sens) {
    int i;

    for (i = 0; i < sens; i++){
        tourner_piece(mat);
    }
}
