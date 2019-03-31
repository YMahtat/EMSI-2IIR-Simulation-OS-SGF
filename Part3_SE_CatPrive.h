#pragma once

// Part3_SE_CatPrive.h : 3eme Partie du MiniProjet SE, Création et gestion des Catalogues Privé.
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
// // Date & Time : Du 27/03/2016 a 05/05/2016
// // ///
//

//


#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include <iostream>
using namespace std;

#include "Pilote_DISQ_SGF.h"
#include "Part1_SE_TOS.h"
#include "Part2_SE_CI.h"

#define TailleCatPrive  4// Nbr de case dans un CP
#define NbCPs 10 // Nbr de CPs dans la memoire 
#define IndexCG 0
#define IndexCI_CG 1
#define EmptyCP "" // la valeur de la case vide dans CP
#define dispoCP true // la valeur de dispo
#define NNdispoCP false // la valeur de non dispo
#define NNaffectCP -1 // la valeur indiquant que la CI n'a pas de N° Secteur en disque

#define NonTrouveeCP false
#define TrouveeCP true
#define NotFoundCP -1



struct CaseCP {
	char NomExtern[4];
	int Intern;
};

struct CatPrivInMemory {
	bool disponible;
	CaseCP CatPrive[TailleCatPrive];
	int SectorInMemory;
};




// .===================================================================================
bool init_CPs();
bool RendreDispoCP(int NumCP);
bool RendreNNDispoCP(int NumCP);
int	 ResearchDispoCP();
void PrintDisponibiliteCPs();
int researchCP(char* username);
int RecupIndexCI_CP(int NumCP);

bool init_PartOfCatPriv(int NumCP);
bool init_CatPriv(int NumCP);
bool AddFileToPartOfCP(int NumCP, char* NomExtern, int NumIntern);
bool AddFileToCP(int NumCP, char* NomExtern, int NumIntern);
bool DelFileFromPartOfCP(int NumCP, char* NomExtern);
bool DelFileFromCP(int NumCP, char* NomExtern);
int  ResearchFileInPartOfCP(int NumCP, char* NomExtern);
int  ResearchFileInCP(int NumCP, char* NomExtern);
bool PrintPartOfCP(int NumCP);
bool PrintCP(int NumCP);

bool ModifFileNameInCP(int NumCP, char* NomExtern, char * NewNomExtern);

bool InscrireCIofCatPriv(int indexCP, int indexCI);
bool InscrireNameOfCatPriv(int indexCP, char* Nom);
bool Charger_CP(int indexCP, int secteur);
bool Charger_FirstPartCP(int indexCP);
bool Sauvegarder_CP(int indexCP);
bool AllongerCatPriv(int NumCP);
CatPrivInMemory* RecupTabCPs();

void MenuCP();
int mainCP();