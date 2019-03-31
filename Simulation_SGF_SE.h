#pragma once

// Simulation_SGF_SE.cpp : dernière Partie du MiniProjet SE, LE module SGF (avec toutes ces interfaces).
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
// // Etudiants concepteurs & développeurs du MODULE SGF (Projet): [ IBRAHIM MANNANE && Youssef MAHTAT ]
// //
// // Langage Utilisé : Langage de Programmation C/C++
// //
// // Développé sous WINDOWS 10 (64bits) && WINDOWS 7 (64bits), IDE : MicroSoft Visual Studio Professinal 2015 
// // Date & Time : Du  26/05/2016 au 
// // ///
//

//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>


#include <windows.h>
#include <iostream>
using namespace std;


#include "Pilote_DISQ_SGF.h"
#include "Part1_SE_TOS.h"
#include "Part2_SE_CI.h"
#include "Part3_SE_CatPrive.h"
#include "Part4_SE_VTOC.h"

#define FileCreated true
#define FileNotCreated false




bool CreationFichier(char* UserName, char* FileName);
bool DestructionFichier(char* UserName, char* FileName);
bool ModifierNomFichier(char* UserName, char* FileName, char* nouv_nom);
bool OuvertureFichier(char* UserName, char* FileName);
bool AjouterEnregistrementFichier(char* UserName, char* FileName, char enreg[TAILLE_SECT]);
bool Supp_enregistrement_fichier(char* UserName, char* FileName, int NumOrdre);
bool LectureEnregistrementFichier(char* UserName, char* FileName, int NumOrdre, char enreg[TAILLE_SECT]);

bool EcritureEnregistrementFichier(char* UserName, char* FileName, int NumOrdre, char enreg[TAILLE_SECT]);

bool FormatageDisque();
bool DemarrageSE();

bool creationSession(char* UserName);
bool OuvertureSession(char* UserName);
bool FermetureSession(char* UserName);
bool SupprimerSession(char* userName);
bool DestructionFilesUser(char* UserName);
void MENU_SGF();
void MENU_SGF_BIS();
void MENU_Simulation();