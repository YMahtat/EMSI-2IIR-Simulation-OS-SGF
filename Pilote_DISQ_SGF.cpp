#pragma once
// Pilote_DISQ_SGF.cpp : Interface Disque !! .
// 
// 
//
//
// //
// // EMSI    -   IIR   -    INFORMATIQUE
// //
// // SYSTEMES D'EXPLOITATION & PROGRAMMATION SYSTEMES
// //
// // EMSI3 - 2°IIR 2 (G1) - MiniProjet SE
//
// // MiniProjet en Systèmes d'Exploitation
// //
// // Projet de realisation du MODULE SGF ;
// //
// // Professeur : Dr. A. CHRAIBI
// // Etudiants concepteurs & développeurs du MODULE SGF (Projet): [ Youssef MAHTAT  &&  IBRAHIM MANNANE ]
// //
// //Langage Utilisé : Langage de Programmation C/C++
// //
// // Développé sous WINDOWS 10 (64bits) && WINDOWS 7 (64bits), IDE : MicroSoft Visual Studio Professinal 2015 
// // Date & Time : Du  
// // ///
//

//


#include "stdafx.h"
#include <HimoCryptoLibs.h>


//////////////////////////////////////////////////////////////////////////////////////////////////////////////


#define TAILLE_DISC 40
#define TAILLE_SECT 40




//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void creation_disque()
{
	int i; char secteur[TAILLE_SECT];
	for (i = 0; i < TAILLE_SECT; i++) secteur[i] = 46;
	FILE* disque = fopen("mondisque.sgf", "wb+");
	for (i = 0; i < TAILLE_DISC; i++)
		fwrite(secteur, TAILLE_SECT, 1, disque);
	fclose(disque);
}


void lecture_bloc(int num_sect, void* zone)
{
	FILE* disque = fopen("mondisque.sgf", "r");
	fseek(disque, num_sect * TAILLE_SECT, SEEK_SET);
	fread(zone, TAILLE_SECT, 1, disque);
	fclose(disque);
}


void ecriture_bloc(int num_sect, void* zone)
{
	FILE* disque = fopen("mondisque.sgf", "r+");
	fseek(disque, num_sect*TAILLE_SECT, SEEK_SET);
	fwrite(zone, TAILLE_SECT, 1, disque);
	fclose(disque);
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////


