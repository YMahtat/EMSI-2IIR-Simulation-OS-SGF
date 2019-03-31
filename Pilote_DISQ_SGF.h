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
void creation_disque();
void lecture_bloc(int num_sect, void* zone);
void ecriture_bloc(int num_sect, void* zone);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
