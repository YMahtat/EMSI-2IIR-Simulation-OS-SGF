#pragma once
// Part2_SE_CI.cpp : 2eme Partie du MiniProjet SE , Création et gestion des CIs .
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
#include "Part2_SE_CI.h"



// Declaration des CIs en Memoire : 
CIinMemory TablesCI[NbCI];

ComplementCI TableComplementCIs[NbCI];


// .===================================================================================


CIinMemory* RecupTabCI()
{
	CIinMemory* pTAB = TablesCI;
	return pTAB ;
}

// Init_CI() : la fct Initialiser une Table CI ;
bool Init_CI(int indice)
{
	if (indice >= 0 && indice < NbCI && TablesCI[indice].Dispo == NNdispoCI)
	{
		for (int i = 0; i < TailleCI; i++)
			TablesCI[indice].CI[i] = EmptyCaseCI;
		return true;
	}
	else return false;
	
}


// Add_Enregistrement() : la fct Ajouter le NumSector d'un enregistrement a la CI ;
bool Add_Enregistrement(int NumCI,int NumSector)
{
	int Index = 0;
	if (NumCI >= 0 && NumCI < NbCI && TablesCI[NumCI].Dispo == NNdispoCI)
	{
		while (Index < TailleCI && TablesCI[NumCI].CI[Index] != EmptyCaseCI) Index++;

		if (Index < TailleCI) { TablesCI[NumCI].CI[Index] = NumSector; return true; }
		else return false;

	}
	else return false;
	
}



// Del_Enregistrement() : la fct enlever un enregistrement d'une CI ;
bool Del_Enregistrement(int NumCI,int IndexToDel)
{

	if (NumCI >= 0 && NumCI < NbCI  && TablesCI[NumCI].Dispo == NNdispoCI && TablesCI[NumCI].CI[0] != EmptyCaseCI &&TablesCI[NumCI].CI[IndexToDel] != EmptyCaseCI)
	{
		if (IndexToDel >= 0 && IndexToDel < TailleCI)
		{
			int i = IndexToDel;
			while (i < TailleCI && TablesCI[NumCI].CI[i] != EmptyCaseCI )
			{

				TablesCI[NumCI].CI[i] = TablesCI[NumCI].CI[++i];

			}
			return true;
		}
		else return false;
	}
	else return false;
}


// Init_TablesCI() : la fct Initialiser la disponibilité des CIs ;
bool Init_TablesCI()
{
	for (int i = 0; i < NbCI; i++) 
	{
		TablesCI[i].Dispo = dispoCI;
		TablesCI[i].SecteurMemoire = NNaffectCI;
		strcpy(TableComplementCIs[i].UserName, "");
		strcpy(TableComplementCIs[i].FileName, "");
	}
		
	return true;
}

int Research_Dispo_CI()
{
	for (int i = 0; i < NbCI; i++)
		if(TablesCI[i].Dispo == dispoCI) return i;
	return NotFoundCI;
}

// AffichageCI() : la fct d'Affichage des secteurs d'une CI ;
void AffichageCI(int NumCI)
{

	int i = 0;
	cout << " Carte d'Implantation :" << endl;
	while ( i<TailleCI)
	{
		if(TablesCI[NumCI].CI[i] != EmptyCaseCI) cout << "Secteur " << i << " est " << TablesCI[NumCI].CI[i] << endl;
		else cout << "Secteur " << i << " est NULL " << endl;
		i++;
	}
	system("PAUSE");
}


// RendreDispoCI(int NumCI) : la fct Rendre une CI Dispo;
bool RendreDispoCI(int NumCI)
{
	if (NumCI < NbCI && NumCI >=0)
	{
		TablesCI[NumCI].Dispo = dispoCI;
		//Init_CI(NumCI);
		TablesCI[NumCI].SecteurMemoire = NNaffectCI;
		return true;
	}
	else return false;
	
}


//  RendreNNDispoCI() : la fct Rendre une CI Non- Dispo ;
bool RendreNNDispoCI(int NumCI)
{
	if (NumCI < NbCI && NumCI >=0)
	{
		TablesCI[NumCI].Dispo = NNdispoCI;

		return true;
	}
	else return false;

}

// Affichage_CIs_Dispo() : la fct d'Affichage de la disponibilités des CIs ;
void Affichage_CIs_Dispo()
{
	int i = 0;
	while (i< NbCI)
	{
		if(TablesCI[i].Dispo == dispoCI) cout << "La CI num " << i << " est dispo !!" << endl;
		else cout << "La CI num " << i << " est NNdispo !!" << endl;
		i++;
	}
}





void Charger_CI(int secteurCI,int indiceMC)
{
	lecture_bloc(secteurCI, (int*)TablesCI[indiceMC].CI);
	TablesCI[indiceMC].SecteurMemoire = secteurCI;
}

bool Sauvegarder_CIs(int indiceMC)
{
	if (TablesCI[indiceMC].SecteurMemoire != NNaffectCI)
	{
		ecriture_bloc(TablesCI[indiceMC].SecteurMemoire, (int*)TablesCI[indiceMC].CI);
		return true;
	}
	else return false;
}


int ResearchCI_File(char* userName, char* FileName)
{
	int i = 0;
	for (i = 0; i < NbCI; i++)
		if (TablesCI[i].Dispo == NNdispoCI && strcmp(TableComplementCIs[i].UserName, userName) == 0 && strcmp(TableComplementCIs[i].FileName, FileName) == 0)
			return i;

	return NotFoundCI;
}

bool FermetureFichier(char* userName,char* FileName)
{
	int i = 0;
	for (i = 0; i < NbCI; i++)
		if (TablesCI[i].Dispo == NNdispoCI && strcmp(TableComplementCIs[i].UserName, userName) == 0 && strcmp(TableComplementCIs[i].FileName, FileName) == 0)
		{
			Sauvegarder_CIs(i);
			strcpy(TableComplementCIs[i].UserName, "");
			strcpy(TableComplementCIs[i].FileName, "");
			RendreDispoCI(i);
			return true;

		}

	return false;
}



bool FermetureFichiers_User(char* userName)
{
	int i = 0;
	for (i = 0; i < NbCI;i++)
		if (TablesCI[i].Dispo == NNdispoCI && strcmp(TableComplementCIs[i].UserName, userName) == 0)
		{
			Sauvegarder_CIs(i);
			strcpy(TableComplementCIs[i].UserName, "");
			strcpy(TableComplementCIs[i].FileName, "");
			RendreDispoCI(i);
		}
	return true;
}

ComplementCI* RecupTabComplementCI()
{
	ComplementCI* pTab = TableComplementCIs;
	return pTab;
}




// MenuCI() : Menu de Simulation des CIs
void MenuCI()
{
	bool Boucle = true;

	
	while (Boucle)
	{
		fflush(stdin);
		system("cls");
		int choix;
		cout << "EMSI MULTIX by [YOUSSEF MAHTAT & IBRAHIM MANNANE] " << (char)184 << " . " << endl;
		cout << endl << " => Menu de Simulation :" << endl;
		cout << "    0 - Initialisation des CIs ;" << endl;
		cout << "    1 - Initialisation d'une CI ;" << endl;
		cout << "    2 - Ajout d'un Enregistrement ;" << endl;
		cout << "    3 - Enlever d'un Enregistrement ;" << endl;
		cout << "    4 - Rendre dispo une CI ;" << endl;
		cout << "    5 - Rendre NN dispo une CI ;" << endl;
		cout << "    6 - Recherche d'une CI dipo ;" << endl;
		cout << "    7 - Affichage d'une CI ;" << endl;
		cout << "    8 - Affichage des CIs Dispo ;" << endl;
		cout << "    9 - Charger une CI de la memoire ;" << endl;

		cout << "    10 - Sauvgarder les CIs en memoire ;" << endl;
		cout << "    11 - Creation Disque ;" << endl<< endl << endl;

		cout << "    12 - Rechercher CI d'un fichier ;" << endl << endl << endl;

		cout << "    13 - Quitter ;" << endl;


		cout << endl << endl << "    " << " Enter votre CHOIX : ";
		cin >> choix;


		switch (choix)
		{
		case 0:
			
			system("cls");
			Init_TablesCI();
			cout << "Les CIs sont initialisees !!" << endl;
				
			
			system("PAUSE");
			break;

		case 1:
			int x;
			system("cls");
			cout << "Entrer le Num de la CI : ";
			cin >> x;
		
			if (Init_CI(x)) cout << "La CI " << x << " est initialisee !!" << endl;
			else cout << "La CI " << x << " ne est pas initialisee !!" << endl;

			system("PAUSE");
			break;
		case 2:
			system("cls");
			cout << "Entrer le Num de la CI : ";
			cin >> x;
		
				int NumSector;
				cout << "Enter le num du secteur a ajouter : ";

				cin >> NumSector;
				if(Add_Enregistrement(x,NumSector)) cout << "Ajoutee a la CI !!  " ;
				else cout << "HERREUUUURRR A OUSTAD !!! " << endl;

				
			
			system("PAUSE");
			break;
		case 3:
			system("cls");
			
			cout << "Entrer le Num de la CI : ";
			cin >> x;

			int IndexToDel;
			cout << "Enter le num de la Case : ";

			cin >> IndexToDel;
			if(Del_Enregistrement(x,IndexToDel)) 
				cout << "Le secteur " << IndexToDel << " est enlever de la CI Num "<< x << " !!" << endl ;
			else cout << " Erreur !!! " << endl;
			
			system("PAUSE");
			break;
		case 4:
			system("cls");
			cout << "Entrer le Num de la CI : ";
			cin >> x;
			if (RendreDispoCI(x)) cout << " La CI " << x << " est Dispo ;";
			else cout << "erreur!!!!";
			system("PAUSE");
			break;
		case 5:
			system("cls");
			cout << "Entrer le Num de la CI : ";
			cin >> x;
			if (RendreNNDispoCI(x)) cout << " La CI " << x << " est NN-Dispo NOW !!!;" << endl;
			else cout << "erreur!!!!";
			system("PAUSE");
			break;
		case 6:
			system("cls");
			x = Research_Dispo_CI();
			if ( x == NotFoundCI ) cout << " Il ne y a pas de CI dispo ";

			else cout << "La CI Num " << x << " est dispo !!" << endl;
			system("PAUSE");
			break;

		case 7:
			system("cls");

			cout << "Entrer le Num de la CI : ";
			cin >> x;
			if (x < 0 && x >= NbCI && TablesCI[x].Dispo == NNdispoCI)
				cout << "Erreur !!";
			else AffichageCI(x);
			break;
		case 8:
			system("cls");

			cout << "Liste des CIs Disponible : " << endl;
			Affichage_CIs_Dispo();
			system("PAUSE");

			break;
		case 9:
			system("cls");

			cout << "Donnez le secteur de la carte d'implantation en memoire : ";
			cin >> x;
			cout << "Donnez l'indice dans la table des CIs en Memoire : ";
			int y; cin >> y;
			Charger_CI(x, y);
			cout << "CI chargee !!!" << endl;
			system("PAUSE");

			break;
		case 10:
			system("cls");
			cout << "Donnez l'indice dans la table des CIs en Memoire : ";
			cin >> x;
			if(Sauvegarder_CIs(x)) cout << "CIs sauvgarder !!!" << endl;
			else cout << "HERROUR !!" << endl;
			system("PAUSE");

			break;
		case 11:
			system("cls");
			creation_disque();
			cout << "DIKSE CREATED !!!" << endl;
			system("PAUSE");

			break;

		case 12:
			system("cls");
			
			char ch1[10], ch2[10];
			cout << "Donnez le nom de l'user : ";
			cin >> ch1;
			cout << "Donnez le nom du Fichier : ";
			cin >> ch2;
			x = ResearchCI_File(ch1, ch2);
			if (x != NotFoundCI)
				cout << "le Fichier est dans la CI num : "<< x << " !" << endl;
			else
				cout << "le Fichier n'est pas ouvert!!" << endl;

			system("PAUSE");

			break;

		case 13:
			Boucle = false;
			break;
		default:
			cout << "HEROURRRR !!!" << endl;
			break;
		}
	}
}