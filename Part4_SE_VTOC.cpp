#pragma once
// Part4_SE_VTOC.cpp : 4eme Partie du MiniProjet SE, Création et gestion de la VTOC.
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


#include "stdafx.h"
#include "Part4_SE_VTOC.h"
#include "Part1_SE_TOS.h"


StructVTOC VTOCinMemory;



bool InitPartOfVTOC()
{
	for (int i = 0; i < TailleVTOC; i++)
		VTOCinMemory.VTOC[i].NumSectorCI = EmptyCaseVTOC;


	return DONE;
}


bool InitVTOC()
{
	CIinMemory* pTabCI = RecupTabCI();
	int indice = 0;
	VTOCinMemory.IndexCI = 0;
	while (indice < TailleCI && pTabCI[VTOCinMemory.IndexCI].CI[indice] != EmptyCaseCI)
	{
		Charger_VTOC(pTabCI[VTOCinMemory.IndexCI].CI[indice]);
		InitPartOfVTOC();
		sauvegarder_VTOC();
		indice++;
	}
	return DONE;
}


int ResearchFreeDescriptorInPartOfVTOC()
{
	for (int i = 0; i < TailleVTOC; i++)
		if(VTOCinMemory.VTOC[i].NumSectorCI == EmptyCaseVTOC) return i;
	return NotFoundDescripteur;
}

int ResearchFreeDescriptor()
{
	CIinMemory* pTabCI = RecupTabCI();
	int x = NotFoundDescripteur;
	int indice = 0;

	while (indice < TailleCI && pTabCI[VTOCinMemory.IndexCI].CI[indice] != EmptyCaseCI && x == NotFoundDescripteur)
	{
		Charger_VTOC(pTabCI[VTOCinMemory.IndexCI].CI[indice]);
		x = ResearchFreeDescriptorInPartOfVTOC();
		indice++;
	}

	if (x != NotFoundDescripteur) return (indice - 1)*TailleVTOC + x;
	return x;
}


bool AddDescriptorInPartOfVTOC(int tailleFichier, int NumeroSecteur, int x)
{
	
	if (x < 0  || x >= TailleVTOC) return UNDONE;
	else
	{
		VTOCinMemory.VTOC[x].SizeFile = tailleFichier;
		VTOCinMemory.VTOC[x].NumSectorCI = NumeroSecteur;
		return DONE;
	}
}

bool AddDescriptor(int tailleFichier, int NumeroSecteur, int x)
{
	CIinMemory* pTabCI = RecupTabCI();
	
	int indice = x / TailleVTOC;

	if (indice < TailleCI && pTabCI[VTOCinMemory.IndexCI].CI[indice] != EmptyCaseCI)
	{
		Charger_VTOC(pTabCI[VTOCinMemory.IndexCI].CI[indice]);
		if (AddDescriptorInPartOfVTOC(tailleFichier, NumeroSecteur, x%TailleVTOC))
		{
			sauvegarder_VTOC();
			return DONE;
		}
			
	}
	return false;
}


bool BackUpDescriptorInPartOfVTOC(Descripteur &D, int NumeroIntern)
{
	if (VTOCinMemory.VTOC[NumeroIntern].NumSectorCI != EmptyCaseVTOC)
	{
		D.NumSectorCI = VTOCinMemory.VTOC[NumeroIntern].NumSectorCI;
		D.SizeFile = VTOCinMemory.VTOC[NumeroIntern].SizeFile;
		return DONE;

	}
	else return UNDONE;
}


bool BackUpDescriptor(Descripteur &D, int NumeroIntern)
{
	CIinMemory* pTabCI = RecupTabCI();

	
	int indice = NumeroIntern / TailleVTOC;
	if (indice < TailleCI && pTabCI[VTOCinMemory.IndexCI].CI[indice] != EmptyCaseCI)
	{
		
		Charger_VTOC(pTabCI[VTOCinMemory.IndexCI].CI[indice]);
		if (BackUpDescriptorInPartOfVTOC(D, NumeroIntern % TailleVTOC))
			return DONE;
		
	}
	return false;
}



bool LibererDescripteurInPartOfVTOC(int NumeroIntern)
{
	if (NumeroIntern >= TailleVTOC && NumeroIntern < 0) return UNDONE;
	else
	{
		if (VTOCinMemory.VTOC[NumeroIntern].NumSectorCI != EmptyCaseVTOC) return DONE;
		else
		{
			VTOCinMemory.VTOC[NumeroIntern].NumSectorCI = EmptyCaseVTOC;
			return DONE;
		}
	}
	
}

bool LibererDescripteur(int NumeroIntern)
{
	CIinMemory* pTabCI = RecupTabCI();

	int indice = NumeroIntern / TailleVTOC;

    if (indice < TailleCI && pTabCI[VTOCinMemory.IndexCI].CI[indice] != EmptyCaseCI)
	{
		Charger_VTOC(pTabCI[VTOCinMemory.IndexCI].CI[indice]);
		if( LibererDescripteurInPartOfVTOC( NumeroIntern%TailleVTOC) )
			return DONE;
		
	}
	return false;
}



bool Charger_VTOC(int NumSecteur)
{
	if (NumSecteur >= 0 && NumSecteur < TAILLE_DISC)
	{
		lecture_bloc(NumSecteur, VTOCinMemory.VTOC);
		VTOCinMemory.SectorInMemory = NumSecteur;
		return true;
	}
	else return false;

}

bool sauvegarder_VTOC()
{
	if (VTOCinMemory.SectorInMemory != NNaffectCI)
	{
		ecriture_bloc(VTOCinMemory.SectorInMemory, VTOCinMemory.VTOC);
		return true;
	}

	else return false;
}

bool AllongerVTOC()
{
	CIinMemory* pTabCI = RecupTabCI();

	int indice = 0;
	while (indice < TailleCI && pTabCI[VTOCinMemory.IndexCI].CI[indice] != NNaffectCI)
		indice++;
	if (indice >= TailleCI)
		return false;
	else
	{
		int x = Research_FreeSector();
		if (x == NotFoundSector)
			return false;
		else
		{
			OccuperSector(x);
			Charger_VTOC(x);
			InitPartOfVTOC();
			sauvegarder_VTOC();
			Add_Enregistrement(VTOCinMemory.IndexCI, x);
			Sauvegarder_CIs(VTOCinMemory.IndexCI);
			Sauvegarder_TOS();
			return true;
		}
	}

}



void AffichageVTOC()
{
	for (int i = 0; i < TailleVTOC; i++)
	{
		cout << "NumINtern : " << i << " , NumSector : " << VTOCinMemory.VTOC[i].NumSectorCI << " , Taille Fichier ";
		(VTOCinMemory.VTOC[i].NumSectorCI == EmptyCaseVTOC) ? cout << "NoN Significatif !! " : cout << VTOCinMemory.VTOC[i].SizeFile;
		cout << endl;
	}
	
}


void MenuVTOC()
{	
	int x,y,z;
	Descripteur D;
	bool Boucle = true;
	do {
		fflush(stdin);
		system("cls");
		cout << " ===>    Menu    " << endl << endl ;
		cout << "    1- Initialisation" << endl << "    2- Rechereche un descropteur" << endl << "    3- Ajouter un descripteur" << endl << "    4- Recuperer les infos d'un descripteur" << endl << "    5- Liberer un descripteur" << endl<< "    6- Creation Disque" <<endl <<"    7- Charger (une partie de ) la VTOC" << endl << "    8- Sauvegarder la VTOC" << endl << "    9- Affichage" << endl << "    10- AllongerVTOC" << endl << "    0- quitter" << endl << endl << endl;
		int choix;
		fflush(stdin);
		cout << "    ==> Entrer votre choix ( Entre 0 et 9 ) : ";
		cin >> choix;
		fflush(stdin);
		switch (choix)
		{
		case 1: 
			system("cls");
			if (InitVTOC()) cout << "la vtoc est initialisee" << endl;
			else cout << "Herreeeuur" << endl;
			system("PAUSE");
			break;
		case 2: 
			system("cls");
			x = ResearchFreeDescriptor();
			if (x != NotFoundDescripteur) cout << "Le descripteur dont le num interne " << x << " est libre" << endl;
			else cout << "wa la vtoc 3amra" << endl;
			system("PAUSE");
			break;
		case 3:
			system("cls");
			fflush(stdin);
			cout << " entrer le NumeroIntern : "; cin >> x;
			fflush(stdin);
			cout << " Entrer le NumeroSector a ajouter : "; cin >> y;
			fflush(stdin);
			cout << " Entrer la TailleFichier a ajouter : "; cin >> z;
			fflush(stdin);
			if (AddDescriptor(z, y, x) == DONE) cout << "Le decripteur est Ajouter " << endl;
			else cout << "HERROUR le decripteur n'est pas Ajouter" << endl;
			system("PAUSE");
			break;
		case 4:
			system("cls");
			fflush(stdin);
			cout << " entrer le NumeroIntern : "; cin >> x;
			fflush(stdin);
			if (BackUpDescriptor(D, x))
			{
				cout << "Le contenu du Descripteur : " << endl << "Numero de Secteur de la CI : " << D.NumSectorCI << endl << "Taille Fichier : " << D.SizeFile << endl;
			}
			else cout << "Herreeeuur" << endl;
			system("PAUSE");
			break;
		case 5:
			system("cls");
			fflush(stdin);
			cout << " entrer le NumeroIntern : "; cin >> x;
			fflush(stdin);
			if (LibererDescripteur(x)) cout << " Descripteur liberee !!" << endl;
			else cout << "Herreeeuur" << endl;
			system("PAUSE");
			break;
		case 6 :
			system("cls");
			creation_disque();
			cout << "Le DISQUE EST CREEE !!" << endl;
			system("PAUSE");
			break;
		case 7 :
			system("cls");
			fflush(stdin);
			cout << "Entrer le Numero de Secteur : "; cin >> x;
			fflush(stdin);
			if (Charger_VTOC(x)) cout << "La (nouvelle) partie de VTOC est CHARGER" << endl;
			else cout << "HERROUR !!" << endl;
			system("PAUSE");
			break;
		case 8:
			system("cls");
			fflush(stdin);
			
			fflush(stdin);
			if (sauvegarder_VTOC()) cout << "Cette partie de VTOC est sauvegarder" << endl;
			else cout << "HERROUR !!" << endl;
			system("PAUSE");
			break;

		case 9:
			system("cls");
			AffichageVTOC();
			system("PAUSE");
			break;

		case 10:
			system("cls");
			if (AllongerVTOC())
				cout << "VTOC allongee" << endl;
			else
				cout << "VTOC non allongee" << endl;

			system("PAUSE");
			break;
		case 0:
			Boucle = false;
			break;
		default:
			cout << "        ***  HEROUR - PLEASE DO INSERT A CORRECT NUMBER !!!  *** " << endl;
			
			break;
		}

	} while (Boucle);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////


int mainVTOC()
{
	MenuVTOC();
	return 0;
}