#pragma once

// Part1_SE.cpp : 1er Partie du MiniProjet SE , Création et gestion de la TOS.
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
// // Etudiants concepteurs & développeurs du MODULE SGF (Projet): [ IBRAHIM MANNANE  && Youssef MAHTAT ]
// //
// // Langage Utilisé : Langage de Programmation C/C++
// //
// // Développé sous WINDOWS 10 (64bits) && WINDOWS 7 (64bits), IDE : MicroSoft Visual Studio Professinal 2015 
// // Date & Time : Du 29/02/2016 à 05/03/2016
// // ///
//
//

#include "stdafx.h"
#include "Part1_SE_TOS.h"

bool TOS[TAILLE_DISC];// Si une case est "false" alors elle est occupé sinon libre ;

int main_TOS()
{
	
	Menu();// Menu de la simulation ;
    return 0;
}



// .===================================================================================

// init_TOS() : "Initialisation des case de la TOS" 
bool init_TOS()
{
	int i;
	// On parcours toute la TOS :
	for (i = 0; i < TAILLE_DISC; i++)
		TOS[i] = Libre; // On affecte à chaque case la valeur "Libre"
	return true;

}


// Research_FreeSector() : "Rechercher un secteur Libre"
int Research_FreeSector()
{
	int i;
	// On parcours la TOS :
	for (i = 0; i < TAILLE_DISC; i++)
		// Si le secteur est "Libre" on retourne -> l'indice de la case :
		if (TOS[i] == Libre) return i;
	
	// Sinon : si on a parcouru toute la TOS et on a pas touvé de secteur libre
	//      // On retourne NonTrouvé !!!
	return NotFoundSector;
}


// OccuperSector() : " La fct Occuper un secteur dans la TOS " 
bool OccuperSector(int Sector)
{
	// Si l'indice est entre 0 et TAILLE_DISC alors :
	if (Sector < TAILLE_DISC && Sector >=0)
	{
		// On rend le secteur d'indice Sector "Ocuupé" :
		TOS[Sector] = Occupee;
		return true;

	}
	else return false;
	

}


// LibererSector() : " La fct qui libère un secteur dans la TOS "
bool LibererSector(int Sector)
{
	// Si l'indice est entre 0 et TAILLE_DISC alors :
	if (Sector < TAILLE_DISC  && Sector >= 0)
	{
		// On rend le secteur d'indice Sector "Libre" :
		TOS[Sector] = Libre;
		return true;

	}
	else return false;


}


// Taille_Libre_Disque() : la fct qui Calcul de la Taille Libre sur le Disque ;
	int Taille_Libre_Disque()
	{
		int cpt = 0;
		for (int i = 0; i < TAILLE_DISC; i++)
			if (TOS[i] == Libre) cpt++;

		return cpt;

	}




// Taille_Occupee_Disque() : la fct qui Calcul de la Taille Occupée sur le Disque ;
  int Taille_Occupee_Disque()
   {
		int cpt = 0;
		for (int i = 0; i < TAILLE_DISC; i++)
			if (TOS[i] == Occupee) cpt++;

		return cpt;

   }



// AffichageTOS() : " La fct qui affiche l'état des secteur depuis la TOS "
void AffichageTOS()
{

	int i;
	cout << "Table d'Occupation des Secteurs :" << endl << endl ;
	// On parcours toute la TOS :
	for (i = 0; i < TAILLE_DISC; i++)
	{
		cout << "  Secteur " << i << " est ";
		if (TOS[i]) cout << "Libre ;" << endl;
		else cout << "Occupe ;" << endl;
	}
	cout << endl << endl;
	system("PAUSE");
}


void Charger_TOS()
{
	lecture_bloc(Secteur_TOS, (bool*) TOS);
}

void Sauvegarder_TOS()
{
	ecriture_bloc(Secteur_TOS, (bool*) TOS);
}
// Menu() : " La fct du Menu de simulation des fcts de la TOS "
void Menu()
{
	bool Boucle = true;
	int x;

	while (Boucle)
	{
		system("cls");
		int choix;
		cout << "EMSI MULTIX by [YOUSSEF MAHTAT & IBRAHIM MANNANE] " << (char)184 << " . " << endl;
		cout << endl << "=> Menu de Simulation :" << endl << endl << endl ;
		cout << "     1- Initialisation de la TOS ;" << endl;
		cout << "     2 - Research of Free Sector ;" << endl;
		cout << "     3 - Rendre Secteur Libre" << endl;
		cout << "     4 - Rendre Secteur Occupee" << endl;
		cout << "     5 - Taille Occupee sur le Disque ;" << endl;
		cout << "     6 - Taille Libre sur le Disque ;" << endl;
		cout << "     7 - Affichage de la TOS ;" << endl;
		cout << "     8 - CREATION DISQUE ;" << endl;
		cout << "     9 - CHARGER TOS ;" << endl;
		cout << "     10 - SAUV de la TOS ;" << endl;
		cout << "     0 - Quittez la Simulation de la TOS ;" << endl;

		cout << endl << endl << "======>" << " Enter votre CHOIX : ";
		cin >> choix;

		switch (choix)
		{
		case 1:
			system("cls");
			if(init_TOS()) cout << "La TOS est initialisee !!" << endl;
			else cout << "La TOS ne est initialisee !!" << endl;
			break;
		case 2:
			system("cls");
			x = Research_FreeSector();
			if(x != NotFoundSector)
				cout << "Le secteur num " << x << " est libre " << endl;
			else
				cout << "Il n'y a pas de secteur libre" << endl;
			system("PAUSE");
			break;
		case 3:
			system("cls");
			cout << "Enter le num du secteur a liberer : ";
			
			cin >> x;
			if (LibererSector(x)) cout << "Le secteur " << x << " est libre" << endl;
			else cout << "Erreur !! " << endl;
			system("PAUSE");
			break;
		case 4:
			system("cls");
			cout << "Enter le num du secteur a Occuper : ";
			
			cin >> x;
			if (OccuperSector(x)) cout << "Le secteur " << x << " est occuper" << endl;
			else cout << "Erreur !! " << endl;
			system("PAUSE");
			break;
		case 5:
			system("cls");
			cout << " La Taille Occuppee sur disque est de " << Taille_Occupee_Disque() << " Secteurs" << endl;
			system("PAUSE");
			break;
		case 6:
			system("cls");
			cout << " La Taille Libre sur disque est de " << Taille_Libre_Disque() << " Secteurs" << endl;
			system("PAUSE");
			break;
		case 7:
			system("cls");
			AffichageTOS();
			break;
		case 8:
			creation_disque();
			break;
		case 9:
			Charger_TOS();
			break;
		case 10:
			Sauvegarder_TOS();
			break;
		case 0:
			Boucle = false;
			break;
		default:
			cout << "HEROURRRR !!!" << endl;
			break;
		}
	}
}