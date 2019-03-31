#pragma once
// Part2_SE_CI.h : 2eme Partie du MiniProjet SE , Création et gestion des CIs .
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
// // Date & Time : Du 07/03/2016 à 21/03/2016
// // ///
//

//



#include "stdafx.h"

#include <stdlib.h>
#include <conio.h>


#include <iostream>
using namespace std;


#include "Pilote_DISQ_SGF.h"



// /////////////////////////////////////////////////////////////////////////////////////




#define TailleCI 10 // Taille d'une CI (Nbr de secteur dans un fichier)
#define NbCI 10 // Nbr de CIs dans la memoire 
#define EmptyCaseCI -1 // la valeur de la case vide dans un Secteur
#define dispoCI true // la valeur de dispoCI
#define NNdispoCI false // la valeur de non dispoCI
#define NNaffectCI -1 // la valeur indiquant que la CI n'a pas de N° Secteur en disque

#define NotFoundCI -1




struct CIinMemory {
	bool Dispo;
	int CI[TailleCI];
	int SecteurMemoire;
};

struct ComplementCI
{
	char UserName[4];
	char FileName[4];
};

CIinMemory* RecupTabCI();
ComplementCI* RecupTabComplementCI();
bool Init_CI(int indice); // Initialiser une Table CI ;
bool Add_Enregistrement(int NumCI, int NumSector); // Ajouter le NumSector d'un enregistrement a la CI ;
bool Del_Enregistrement(int NumCI, int IndexToDel); // enlever un enregistrement d'une CI ;

bool RendreDispoCI(int NumCI); // Rendre une CI dispoCI ;
bool RendreNNDispoCI(int NumCI); // Rendre une CI Non- dispoCI ;
bool Init_TablesCI(); // Initialiser la dispoCInibilité des CIs ;
void AffichageCI(int NumCI); // Affichage des secteurs d'une CI ;
void Affichage_CIs_Dispo(); // Affichage de la dispoCInibilités des CIs ;
int Research_Dispo_CI();

bool Sauvegarder_CIs(int indiceMC);
void Charger_CI(int secteurCI, int indiceMC);

void MenuCI(); // Menu de Simulation de la CI

int ResearchCI_File(char* userName, char* FileName);
bool FermetureFichier(char* userName, char* FileName);
bool FermetureFichiers_User(char* userName);

			   // /////////////////////////////////////////////////////////////////////////////////////
