#pragma once
// Part3_SE_CatPrive.cpp : 3eme Partie du MiniProjet SE, Création et gestion des Catalogues Privé.
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

#include "stdafx.h"
#include "Part3_SE_CatPrive.h"


CatPrivInMemory CPs[NbCPs];

char NomCat[NbCPs][10];
int IndexCI_CP[NbCPs];
bool DisponibiliteCP[NbCPs];

int RecupIndexCI_CP(int NumCP)
{
	return IndexCI_CP[NumCP];
}

// .===================================================================================

int mainCP()
{
	
	MenuCP();
    return 0;

}





// .===================================================================================


bool init_CPs()
{
	for (int i = 0; i < NbCPs; i++)
	{
		DisponibiliteCP[i] = dispoCP;
		CPs[i].SectorInMemory = NNaffectCP;
		IndexCI_CP[i] = NNaffectCI;
		strcpy(NomCat[i], "");
	}
	
	return true;
}


bool RendreDispoCP(int NumCP)
{
	if (NumCP >= 0 && NumCP < NbCPs)
	{
		DisponibiliteCP[NumCP] = dispoCP;
		CPs[NumCP].SectorInMemory = NNaffectCP;
		IndexCI_CP[NumCP] = NNaffectCI;
		strcpy(NomCat[NumCP], "");
		return true;
	}
	else return false;
}

bool RendreNNDispoCP(int NumCP)
{
	
	if (NumCP >= 0 && NumCP < NbCPs)
	{
		DisponibiliteCP[NumCP] = NNdispoCP;
		CPs[NumCP].SectorInMemory = NNaffectCP;
		IndexCI_CP[NumCP] = NNaffectCI;
		strcpy(NomCat[NumCP], "");
		return true;
	}
	else return false;
}


int ResearchDispoCP()
{
	int i = 0;
	for (i = 0; i < NbCPs; i++)
		if (DisponibiliteCP[i] == dispoCP) return i;

	return NotFoundCP;
}

void PrintDisponibiliteCPs()
{
	int i = 0;
	while (i< NbCPs)
	{
		if (DisponibiliteCP[i] == dispoCP) cout << "Le CatPrive num " << i << " est dispo !!" << endl;
		else cout << "Le CatPrive num " << i << " est NNdispo !!" << endl;
		i++;
	}
}

int researchCP(char* username)
{
	int i;
	
	for (i = 0; i < NbCPs; i++)
		if( DisponibiliteCP[i] == NNdispoCP && strcmp(NomCat[i], username) == 0)
			return i;
	return NotFoundCP;
}


// .===================================================================================



bool init_PartOfCatPriv(int NumCP)
{
	if (NumCP >= 0 && NumCP < NbCPs && DisponibiliteCP[NumCP] == NNdispoCP)
	{
		for (int i = 0; i < TailleCatPrive; i++)
		{
			strcpy_s(CPs[NumCP].CatPrive[i].NomExtern, EmptyCP);
			CPs[NumCP].CatPrive[i].Intern = NNaffectCP;
		}

		return true;
	}
	else return false;
}


bool init_CatPriv(int NumCP)
{
	CIinMemory* pTabCI = RecupTabCI();
	
	int indice = 0;
	while (DisponibiliteCP[NumCP] == NNdispoCI && indice < TailleCI &&  pTabCI[IndexCI_CP[NumCP]].CI[indice] != EmptyCaseCI)
	{
		Charger_CP((NumCP), (pTabCI[IndexCI_CP[NumCP]].CI[indice]));
		if (init_PartOfCatPriv(NumCP) == false)
			return false;
		indice++;
	}
	return true;
}


int researchEmptyCaseInPartOfCP(int NumCP)
{
	if (NumCP >= 0 && NumCP < NbCPs && DisponibiliteCP[NumCP] == NNdispoCP)
	{
		int i = 0;
		while (i < TailleCatPrive)
			if (CPs[NumCP].CatPrive[i].Intern == NNaffectCP)
				return i;
			else
				i++;
		return NotFoundCP;
	}
	else return NotFoundCP;
}


bool AddFileToPartOfCP(int NumCP, char* NomExtern, int NumIntern)
{
	if (NumCP >= 0 && NumCP < NbCPs && DisponibiliteCP[NumCP] == NNdispoCP && strcmp(NomExtern,EmptyCP) != 0)
	{
		int i = 0;
		while (i< TailleCatPrive && strcmp(CPs[NumCP].CatPrive[i].NomExtern, EmptyCP) != 0) i++;
		if (i < TailleCatPrive)
		{
			strcpy_s(CPs[NumCP].CatPrive[i].NomExtern, NomExtern);
			CPs[NumCP].CatPrive[i].Intern = NumIntern;
			return true;
		}
		else return false;
	}
	else return false;
}

bool AddFileToCP(int NumCP, char* NomExtern, int NumIntern)
{
	if (ResearchFileInCP(NumCP, NomExtern) == NotFoundCP)
	{
		CIinMemory* pTabCI = RecupTabCI();

		int x = NotFoundCP;
		int indice = 0;
		while (indice < TailleCI && pTabCI[IndexCI_CP[NumCP]].CI[indice] != EmptyCaseCI && x == NotFoundCP)
		{
			Charger_CP((NumCP), (pTabCI[IndexCI_CP[NumCP]].CI[indice]));
			x = researchEmptyCaseInPartOfCP(NumCP);
			indice++;
		}
		if (x != NotFoundCP)
		{
			if (AddFileToPartOfCP(NumCP, NomExtern, NumIntern))
				return true;
			else return false;
		}
		else return false;
	}
	else return false;
}




bool DelFileFromPartOfCP(int NumCP, char* NomExtern)
{
	if (NumCP >= 0 && NumCP < NbCPs && DisponibiliteCP[NumCP] == NNdispoCP)
	{
		int i = 0;
		while (i< TailleCatPrive && strcmp(CPs[NumCP].CatPrive[i].NomExtern,NomExtern) != 0) i++;
		if (i >= TailleCatPrive) return false;
		while (i < TailleCatPrive && CPs[NumCP].CatPrive[i].Intern != NNaffectCP)
		{
			CPs[NumCP].CatPrive[i] = CPs[NumCP].CatPrive[i+1];
			i++;
		}
		if (i >= TailleCatPrive)
		{
			strcpy_s(CPs[NumCP].CatPrive[TailleCatPrive-1].NomExtern, EmptyCP);
			CPs[NumCP].CatPrive[TailleCatPrive-1].Intern = NNaffectCP;
		}

		return true;
	}
	else return false;
}


bool DelFileFromCP(int NumCP, char* NomExtern)
{
	if (ResearchFileInCP(NumCP, NomExtern) == NotFoundCP)
		return false;
	bool IsDeleted = false;

	CaseCP TableIntermediaire[TailleCatPrive*TailleCI];
	int tailleTab = 0;

	int indice = 0;
	CIinMemory* pTabCI = RecupTabCI();

	while (indice < TailleCI && pTabCI[IndexCI_CP[NumCP]].CI[indice] != EmptyCaseCI)
	{
		Charger_CP((NumCP), (pTabCI[IndexCI_CP[NumCP]].CI[indice]));
		IsDeleted = DelFileFromPartOfCP(NumCP, NomExtern);
		int i;
		for (i = 0; i < TailleCatPrive; i++)
		{
			if(CPs[NumCP].CatPrive[i].Intern != EmptyCaseCI)
				TableIntermediaire[tailleTab++] = CPs[NumCP].CatPrive[i];
		}
		indice++;
	}


	if (IsDeleted)
	{
		if (tailleTab % TailleCatPrive == 0)
		{
			int NumCI = IndexCI_CP[NumCP];
			CIinMemory* pTabCI = RecupTabCI();
			LibererSector(pTabCI[NumCI].CI[indice - 1]);
			Del_Enregistrement(NumCI, indice - 1);

			Sauvegarder_CIs(NumCI);
		}

		int j = 0;
		indice = 0;
		if (tailleTab == 0)
		{
			Sauvegarder_CP(NumCP);
			return IsDeleted;
		}
		Charger_CP(NumCP, pTabCI[IndexCI_CP[NumCP]].CI[indice]);
		int i;
		for (i = 0; i<tailleTab; i++)
		{
			CPs[NumCP].CatPrive[j] = TableIntermediaire[i];
			j++;
			if (j == TailleCatPrive || j == tailleTab)
			{
				j = 0;
				Sauvegarder_CP(NumCP);
				Charger_CP(NumCP, pTabCI[IndexCI_CP[NumCP]].CI[indice]);
			}
		}

	}

	
	return IsDeleted;
}





int ResearchFileInPartOfCP(int NumCP, char* NomExtern)
{
	if (NumCP >= 0 && NumCP < NbCPs && DisponibiliteCP[NumCP] == NNdispoCP && strcmp(NomExtern, "") != 0)
	{
		int i = 0;
		while (i< TailleCatPrive && strcmp(CPs[NumCP].CatPrive[i].NomExtern, NomExtern) != 0) i++;
		if (i < TailleCatPrive) return i;
		else return NotFoundCP;
	}
	else return NotFoundCP;
}


int ResearchFileInCP(int NumCP, char* NomExtern)
{
	CIinMemory* pTabCI = RecupTabCI();
	int x = NotFoundCP;
	int indice = 0;

	while (DisponibiliteCP[NumCP] == NNdispoCP && indice < TailleCI && pTabCI[IndexCI_CP[NumCP]].CI[indice] != EmptyCaseCI && x == NotFoundCP)
	{
		Charger_CP(  (NumCP)  ,  (pTabCI[IndexCI_CP[NumCP]].CI[indice])   );
		x = ResearchFileInPartOfCP(NumCP, NomExtern);
		indice++;
	} 
	return x;
}

 
bool PrintPartOfCP(int NumCP)
{
	if (NumCP >= 0 && NumCP < NbCPs && DisponibiliteCP[NumCP] == NNdispoCP )
	{
		int i=0;
		for (i = 0; i < TailleCatPrive; i++)
		{
			if (strcmp(CPs[NumCP].CatPrive[i].NomExtern, EmptyCP ) != 0) cout << "Case " << i << " :  NomExterne = " << CPs[NumCP].CatPrive[i].NomExtern << " et NumIntern = " << CPs[NumCP].CatPrive[i].Intern<< endl;
			else cout <<  "Case " << i << " est Vide (NON SIGNIFICATIF !!) " << endl;
		}
		return true;
	}
	else return false;

} 

 bool PrintCP(int NumCP)
{
	CIinMemory* pTabCI = RecupTabCI();
	int indice = 0;

	while (indice < TailleCI && pTabCI[IndexCI_CP[NumCP]].CI[indice] != EmptyCaseCI)
	{
		Charger_CP((NumCP), (pTabCI[IndexCI_CP[NumCP]].CI[indice]));
		if(PrintPartOfCP(NumCP))
			indice++;
		else
		{
			cout << "HERROUR !!!" << endl;
			return false;
		}
	}
	if (indice == 0)
		cout << "Le CataloguePrivee ne contient aucun Fichier !!" << endl;
	return true;
}


 bool ModifFileNameInCP(int NumCP, char* NomExtern, char * NewNomExtern)
 {
	 int x = ResearchFileInCP(NumCP, NomExtern);
	 if (x != NotFoundCP)
	 {
		 strcpy_s(CPs[NumCP].CatPrive[x].NomExtern, NewNomExtern);
		 if(Sauvegarder_CP(NumCP))
			return true;
		 else return false;
	 }
	 else return false;
 }







bool Charger_CP(int indexCP, int secteur)
{
	if (secteur >= 0 && secteur < TAILLE_DISC && indexCP >=0 && indexCP < NbCPs && DisponibiliteCP[indexCP] == NNdispoCP)
	{
		lecture_bloc(secteur, CPs[indexCP].CatPrive);
		CPs[indexCP].SectorInMemory = secteur;
		return true;
	}
	else return false;
}


bool Charger_FirstPartCP(int indexCP)
{
	if ( indexCP >= 0 && indexCP < NbCPs && DisponibiliteCP[indexCP] == NNdispoCP )
	{
		CIinMemory* pTabCI = RecupTabCI();
		int indice = 0;

		Charger_CP((indexCP), (pTabCI[IndexCI_CP[indexCP]].CI[0]));
		return true;
	}
	else return false;
}


bool InscrireCIofCatPriv(int indexCP, int IndexCI)
{
	if (indexCP >= 0 && indexCP < NbCPs && DisponibiliteCP[indexCP] == NNdispoCP)
	{
		IndexCI_CP[indexCP] = IndexCI;
		return true;
	}
	else return false;
}

bool InscrireNameOfCatPriv(int indexCP, char* Nom)
{
	if (indexCP >= 0 && indexCP < NbCPs && DisponibiliteCP[indexCP] == NNdispoCP)
	{
		
		strcpy(NomCat[indexCP], Nom);
		
		return true;
	}
	else return false;
}

bool Sauvegarder_CP(int indexCP)
{
	if ( indexCP >= 0 && indexCP < NbCPs && DisponibiliteCP[indexCP] == NNdispoCP && CPs[indexCP].SectorInMemory != NNaffectCP)
	{
		ecriture_bloc(CPs[indexCP].SectorInMemory, CPs[indexCP].CatPrive);
		return true;
	}
	else return false;

}


bool AllongerCatPriv(int NumCP)
{
	if (DisponibiliteCP[NumCP] != NNdispoCP)
		return false;
	CIinMemory* pTabCI = RecupTabCI();

	int indice = 0;
	while (indice < TailleCI && pTabCI[IndexCI_CP[NumCP]].CI[indice] != EmptyCaseCI)
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
			Charger_CP(NumCP, x);
			init_PartOfCatPriv(NumCP);
			Sauvegarder_CP(NumCP);
			pTabCI[IndexCI_CP[NumCP]].CI[indice] = x;
			Sauvegarder_CIs(IndexCI_CP[NumCP]);
			return true;
		}
	}

}






void MenuCP() {
	int choix;
	do {
		fflush(stdin);
		system("cls");
		cout << "** EMSI MULTIX by [YOUSSEF MAHTAT & IBRAHIM MANNANE] " << (char)184 << " . ** " << endl << endl << endl;
		cout << "=>  Menu de Simulation de la Part3 du SGF (CatPrive) :   " << endl << endl;
		cout << "  1 - Initialiser la disponibilite des CPs" << endl;
		cout << "  2 - Rendere dispo un CP" << endl;
		cout << "  3 - Rendre indispo un CP " << endl;
		cout << "  4 - Rechercher un CP dispo " << endl;
		cout << "  5 - Afficher la dispo des CPs " << endl << endl;
		cout << "  6 - Initialiser un CP " << endl;
		cout << "  7 - Ajouter un fichier au CP" << endl;
		cout << "  8 - Supprimer un fichier d'un CP " << endl;
		cout << "  9 - Rechercher un fichier dans un CP " << endl;
		cout << " 10 - Modifier le Nom d'un fichier dans un CP " << endl;
		cout << " 11 - Affichage d'un CP " << endl<<endl;

		cout << " 12 - Creation Disque " << endl ;
		cout << " 13 - Charger un CP " << endl;
		cout << " 14 - Sauvegarder un CP " << endl << endl;
		cout << " 15 - Rechercher l'indice de CP chargee " << endl;
		cout << " 16 - Inscire Nom CP " << endl << endl;
		cout << "  0 - Quitter" << endl<< endl<<endl;

		cout << " => Entrez votre choix : " ;
		cin >> choix;
		
		int x,y;
		char ch[4], ch2[4];
		int num_int;
		switch (choix) {

		case 1:	system("cls");
			if (init_CPs()) cout << "Les CPs sont initialises" << endl;
			else cout << "Erreur!! " << endl;
			system("pause");
			break;
		case 2:	system("cls");
			fflush(stdin);
			cout << "Donnez le num de CP : "; cin >> x;
			if (RendreDispoCP(x)) cout << "Le CP num " << x << " est disponible" << endl;
			else cout << "Erreur!! " << endl;
			system("pause");
			break;
		case 3:	system("cls");
			fflush(stdin);
			cout << "Donnez le num de CP : "; cin >> x;
			fflush(stdin);
			if (RendreNNDispoCP(x)) cout << "Le CP num " << x << " est non disponible" << endl;
			else cout << "Erreur!! " << endl;
			system("pause");
			break;
		case 4:	system("cls");
			x = ResearchDispoCP();
			if (x != NotFoundCP) cout << "Le CP num " << x << " est disponible" << endl;
			else cout << "Il n'y pas de CP dispo!! " << endl;
			break;
		case 5:	system("cls");
			PrintDisponibiliteCPs();
			system("pause");
			break;
		case 6:		system("cls");
			fflush(stdin);
			cout << "Donnez le num de CP : "; cin >> x;
			fflush(stdin);
			if (init_CatPriv(x)) cout << "Le CP num " << x << " est initialise" << endl;
			else cout << "Erreur!! " << endl;

			system("pause");
			break;
		case 7:		system("cls");
			fflush(stdin);
			cout << "Donnez le num de CP : "; cin >> x;
			fflush(stdin);
			cout << "Donnez le nom du ficher : "; cin >> ch;
			fflush(stdin);
			cout << "Donnez le num interne du ficher : "; cin >> num_int;
			fflush(stdin);
			if (AddFileToCP(x, ch, num_int)) cout << "Le fichier est ajoute" << endl;
			else cout << "Erreur!! " << endl;
			system("pause");
			break;
		case 8:		system("cls");
			fflush(stdin);
			cout << "Donnez le num de CP : "; cin >> x;
			fflush(stdin);
			cout << "Donnez le nom du ficher : "; cin >> ch;
			fflush(stdin);
			if (DelFileFromCP(x, ch)) cout << "Le fichier est supprimee" << endl;
			else cout << "Erreur!! " << endl;

			system("pause");
			break;
		case 9:		system("cls");
			fflush(stdin);
			cout << "Donnez le num de CP : "; cin >> x;
			fflush(stdin);
			cout << "Donnez le nom du ficher : "; cin >> ch;
			fflush(stdin);
			num_int = ResearchFileInCP(x, ch);
			if (num_int != NotFoundCP) cout << "Le fichier est trouve dans la case " << num_int << endl;
			else cout << "Non trouve " << endl;
			system("pause");
			break;

		case 10:	system("cls");
			fflush(stdin);
			cout << "Donnez le num de CP : "; cin >> x;
			fflush(stdin);
			cout << "Donnez le nom du ficher : "; cin >> ch;
			fflush(stdin);
			cout << "Donnez le nouveau nom du ficher : "; cin >> ch2;
			if (ModifFileNameInCP(x, ch,ch2) ) cout << "Le nom du fichier est modifiee "  << endl;
			else cout << " *HEROUR* " << endl;
			system("pause");
			break;



		case 11:		system("cls");
			cout << "Donnez le num de CP : "; cin >> x;


			if (!PrintCP(x)) cout << "erreur !!";
			system("pause");
			break;

		case 12:	

			system("cls");
			creation_disque();	
			cout << "Le DISQUE est creee " << endl;
			system("pause");
			break;

		case 13:		system("cls");
			fflush(stdin);
			cout << "Entrer l'indice du CP : "; cin >> x;
			fflush(stdin);
			cout << "Entrer le num de secteur : "; cin >> y;
			fflush(stdin);
			if (Charger_CP(x, y)) cout << "CP chargee" << endl;
			else cout << "HERROUR a OUSTAD" << endl;

			system("pause");
			break;

		case 14:		system("cls");
			fflush(stdin);
			cout << "Entrer l'indice du CP : "; cin >> x;
			fflush(stdin);

			if (Sauvegarder_CP(x)) cout << "CP sauvegardee" << endl;
			else cout << "HERROUR a OUSTAD" << endl;

			system("pause");
			break;

		case 15:
			
			fflush(stdin);
			cout << "Donnez le  nom du user : "; cin >> ch2;
			x = researchCP(ch2);
			if (x == NotFoundCP)
				cout << "Le CP n'est pas chargee" << endl;
			else
				cout << "Le CP est chargee dans le CP num : " << x << "  !"<< endl;
			system("pause");
			break;
		case 16:
			cout << "Entrer l'indice du CP : "; cin >> x;
			fflush(stdin);
			fflush(stdin);
			cout << "Donnez le  nom du user : "; cin >> ch2;
			
			if (InscrireNameOfCatPriv(x,ch2) == false)
				cout << "Le nom n'est pas inscrit" << endl;
			else
				cout << "Le nom est inscrit " << x << "  !" << endl;
			system("pause");
			break;
		default:cout << "erreur!!" << endl;
			break;
		}
	} while (choix != 0);


}



CatPrivInMemory* RecupTabCPs()
{
	CatPrivInMemory* pTAB = CPs;
	return pTAB;
}