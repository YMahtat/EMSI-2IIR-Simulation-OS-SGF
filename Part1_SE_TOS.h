#pragma once

// Part1_SE.h�: 1er Partie du MiniProjet SE , Cr�ation et gestion de la TOS.
// //
// // EMSI    -   IIR   -    INFORMATIQUE
// //
// // SYSTEMES D'EXPLOITATION & PROGRAMMATION SYSTEMES
// //
// // EMSI3 - 2�IIR 2 (G1) - MiniProjet SE
//
// // MiniProjet en Syst�mes d'Exploitation
// //
// // Projet de realisation du MODULE SGF ;
// //
// // Professeur : Dr. A. CHRAIBI
// // Etudiants concepteurs & d�veloppeurs du MODULE SGF (Projet): [ IBRAHIM MANNANE  && Youssef MAHTAT ]
// //
// // Langage Utilis� : Langage de Programmation C/C++
// //
// // D�velopp� sous WINDOWS 10 (64bits) && WINDOWS 7 (64bits), IDE : MicroSoft Visual Studio Professinal 2015 
// // Date & Time : Du 29/02/2016 � 05/03/2016
// // ///
//
//

#include "stdafx.h"

#include <stdlib.h>
#include <conio.h>

#include "Pilote_DISQ_SGF.h"


#include <iostream>
using namespace std;



#define NotFoundSector -1
#define Libre true // La valeur de "Libre" est la valeur Bool�ane "Vraie"
#define Occupee false // La valeur de "Occup�e" est la valeur Bool�ane "Fausse"
#define Secteur_TOS 13





bool init_TOS(); // Initialisation de la TOS pour une 1er utilisation du SE ;
int Research_FreeSector(); // Recherche d'un secteur ;
bool OccuperSector(int Sector); // Rendre un secteur occuper sur la TOS;
bool LibererSector(int Sector); // Rendre un secteur libre sur la TOS ;
int Taille_Libre_Disque(); // Calcul de la Taille Libre sur le Disque ;
int Taille_Occupee_Disque(); // Calcul de la Taille Occup�e sur le Disque ;
void AffichageTOS();  // Affichage du contenu de la table TOS ;
void Menu();  // Menu pour transiter sur les differentes fcts ;
void Charger_TOS();
void Sauvegarder_TOS();
int main_TOS();
