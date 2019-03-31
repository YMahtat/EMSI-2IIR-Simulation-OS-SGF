#pragma once

// Part4_SE_VTOC.h : 4eme Partie du MiniProjet SE, Création et gestion de la VTOC.
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
// // Langage Utilisé : Langage de Programmation C/C++
// //
// // Développé sous WINDOWS 10 (64bits) && WINDOWS 7 (64bits), IDE : MicroSoft Visual Studio Professinal 2015 
// // Date & Time : Du  04/04/2016 au 24/05/2016
// // ///
//

//


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include <string.h>
#include <ctype.h>



#include <windows.h>
#include <iostream>
using namespace std;

#include "Pilote_DISQ_SGF.h"
#include "Part2_SE_CI.h"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define TailleVTOC 5
#define EmptyCaseVTOC -1
#define NotFoundDescripteur -1
#define NumInternVTOC 0
#define NumInternCG 1
#define NumSect_FirstPart_VTOC 0
#define IndexCI_VTOC 0
#define NonTrouveeVTOC false
#define TrouveeVTOC true

#define DONE true
#define UNDONE false


//////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Descripteur
{
	int SizeFile;
	int NumSectorCI;
};


struct StructVTOC
{
	Descripteur VTOC[TailleVTOC];
	char IndexCI;
	char SectorInMemory;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool InitPartOfVTOC();
bool InitVTOC();
int ResearchFreeDescriptorInPartOfVTOC();
int ResearchFreeDescriptor();
bool AddDescriptorInPartOfVTOC(int tailleFichier, int NumeroSecteur, int x);
bool AddDescriptor(int tailleFichier, int NumeroSecteur, int x);
bool BackUpDescriptorInPartOfVTOC(Descripteur &D, int NumeroIntern);
bool BackUpDescriptor(Descripteur &D, int NumeroIntern);

bool LibererDescripteurInPartOfVTOC(int NumeroIntern);
bool LibererDescripteur(int NumeroIntern);

bool Charger_VTOC(int NumSecteur);
bool sauvegarder_VTOC();
bool AllongerVTOC();

void AffichageVTOC();

void MenuVTOC();
int mainVTOC();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

