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

#include "stdafx.h"
#include "Simulation_SGF_SE.h"


int main()
{
	init_CPs();
	Init_TablesCI();
	MENU_Simulation();
    return 0;
}



void MENU_Simulation()
{
	int choix;
	do {
		fflush(stdin);
		system("cls");
		cout << "** EMSI MULTIX by [YOUSSEF MAHTAT & IBRAHIM MANNANE] " << (char)184 << " . ** " << endl << endl << endl;
		cout << "=>  Menu de Simulation du SGF du SE :   " << endl << endl;
		cout << "  1 - Menu_TOS" << endl;
		cout << "  2 - Menu_CI" << endl;
		cout << "  3 - Menu_CATALOGUES " << endl;
		cout << "  4 - Menu_VTOC " << endl;
		cout << "  5 - Menu Gestion des Fichiers " << endl;
		cout << "  6 - Autres Fcts SGF " << endl << endl << endl;

		cout << "  0 - Quitter" << endl << endl << endl;

		cout << " => Entrez votre choix : ";
		cin >> choix;

		
		switch (choix) {

		case 1:	system("cls");
			main_TOS();
			break;
		case 2:	system("cls");
			MenuCI();
			break;
		case 3:	system("cls");
			mainCP();
			break;
		case 4:	system("cls");
			mainVTOC();
			break;
		case 5:	system("cls");
			MENU_SGF();
			break;
		case 6:	system("cls");
			MENU_SGF_BIS();
			break;
		

		default:cout << "erreur!!" << endl;
			break;
		}
	} while (choix != 0);

}




void MENU_SGF()
{
	int choix;
	int x;
	char username[4];
	char FileName[4];
	char New[4];
	char enrg[TAILLE_SECT] = "AHMED ABDELALI IBRAHIM YOUSSEF 123456";
	do {
		fflush(stdin);
		system("cls");
		cout << "** EMSI MULTIX by [YOUSSEF MAHTAT & IBRAHIM MANNANE] " << (char)184 << " . ** " << endl << endl << endl;
		cout << "=>  Menu SGF du SE :   " << endl << endl;
		cout << "  1 - Creation Fichier" << endl;
		cout << "  2 - Destruction Fichier" << endl;
		cout << "  3 - Ouverture Fichier" << endl;
		cout << "  4 - Fermeture Fichier" << endl << endl;
		cout << "  5 - Ajouter Enregistrement" << endl;
		cout << "  6 - Supprimer un  Enregistrement" << endl << endl;
		cout << "  7 - Lire un  Enregistrement" << endl ;
		cout << "  8 - Ecrire un  Enregistrement" << endl << endl;
		cout << "  9 - Modifier Nom Fichier " << endl << endl;

		cout << "  0 - Quitter" << endl << endl << endl;

		cout << " => Entrez votre choix : ";
		cin >> choix;


		switch (choix) {

		case 1:	system("cls");
			cout << "Donnez le nom de l'user : ";
			cin >> username;
			cout << "Donnez le nom du Fichier : ";
			cin >> FileName;
			if (CreationFichier(username, FileName))
				cout << "le Fichier est creee" << endl;
			else
				cout << "HERROUR !!" << endl;
			system("PAUSE");
			break;
		case 2:	system("cls");
			cout << "Donnez le nom de l'user : ";
			cin >> username;
			cout << "Donnez le nom du Fichier : ";
			cin >> FileName;
			if (DestructionFichier(username, FileName))
				cout << "le Fichier est Detruit" << endl;
			else
				cout << "HERROUR !!" << endl;
			system("PAUSE");
			break;
		case 3:	system("cls");
			cout << "Donnez le nom de l'user : ";
			cin >> username;
			cout << "Donnez le nom du Fichier : ";
			cin >> FileName;
			if (OuvertureFichier(username, FileName))
				cout << "le Fichier est Ouvert" << endl;
			else
				cout << "HERROUR !!" << endl;
			system("PAUSE");
			break;
		case 4:	system("cls");
			cout << "Donnez le nom de l'user : ";
			cin >> username;
			cout << "Donnez le nom du Fichier : ";
			cin >> FileName;
			if (FermetureFichier(username, FileName))
				cout << "le Fichier est Ouvert" << endl;
			else
				cout << "HERROUR !!" << endl;
			system("PAUSE");
			
			
			break;
		case 5:	system("cls");
		
			cout << "Donnez le nom de l'user : ";
			cin >> username;
			cout << "Donnez le nom du Fichier : ";
			cin >> FileName;
			if (AjouterEnregistrementFichier(username, FileName,enrg))
				cout << "l'enregistrement est ajoutee" << endl;
			else
				cout << "HERROUR !!" << endl;
			system("PAUSE");

			break;
		case 6:		system("cls");

			cout << "Donnez le nom de l'user : ";
			cin >> username;
			cout << "Donnez le nom du Fichier : ";
			cin >> FileName;
			cout << "Donnez le numero d'ordre de l'enregistrement : ";
			cin >> x;
			if (Supp_enregistrement_fichier(username, FileName, x))
				cout << "l'enregistrement est supprimer" << endl;
			else
				cout << "HERROUR !!" << endl;
			system("PAUSE");
			break;
		case 7:
			cout << "Donnez le nom de l'user : ";
			cin >> username;
			cout << "Donnez le nom du Fichier : ";
			cin >> FileName;
			cout << "Donnez le numero d'ordre de l'enregistrement : ";
			cin >> x;
			if (LectureEnregistrementFichier(username, FileName, x,enrg))
				cout << "l'enregistrement est Lue" << endl;
			else
				cout << "HERROUR !!" << endl;
			system("PAUSE");
			break;
		case 8:
			cout << "Donnez le nom de l'user : ";
			cin >> username;
			cout << "Donnez le nom du Fichier : ";
			cin >> FileName;
			cout << "Donnez le numero d'ordre de l'enregistrement : ";
			cin >> x;
			if (EcritureEnregistrementFichier(username, FileName, x,enrg))
				cout << "l'enregistrement est Ecrit" << endl;
			else
				cout << "HERROUR !!" << endl;
			system("PAUSE");
			break;

		case 9:
			cout << "Donnez le nom de l'user : ";
			cin >> username;
			cout << "Donnez le nom du Fichier : ";
			cin >> FileName;
			cout << "Donnez le nouveau nom : ";
			cin >> New;
			if (ModifierNomFichier(username,FileName,New))
				cout << "lLe nom fichier est modifer" << endl;
			else
				cout << "HERROUR !!" << endl;
			system("PAUSE");
			break;


		default:cout << "erreur!!" << endl;
			break;
		}
	} while (choix != 0);

}




void MENU_SGF_BIS()
{
	int choix;
	char username[4];
	do {
		fflush(stdin);
		system("cls");
		cout << "** EMSI MULTIX by [YOUSSEF MAHTAT & IBRAHIM MANNANE] " << (char)184 << " . ** " << endl << endl << endl;
		cout << "=>  Menu de Simulation du SGF du SE :   " << endl << endl;
		cout << "  1 - Formatage Disque " << endl;
		cout << "  2 - Demarage SE " << endl;
		cout << "  3 - Creation session " << endl;
		cout << "  4 - Ouverture Session " << endl;
		cout << "  5 - Fermeture Session " << endl;
		cout << "  6 - Supprimer Session " << endl << endl;

		cout << "  0 - Quitter" << endl << endl << endl;

		cout << " => Entrez votre choix : ";
		cin >> choix;


		switch (choix) {

		case 1:	system("cls");
			if (FormatageDisque())
				cout << "Le Disque est Formatee" << endl;
			else
				cout << "HERROUR !!" << endl;
			system("PAUSE");
			break;
			break;
		case 2:	system("cls");
			if (DemarrageSE())
				cout << "SE (SGF) est demarrer" << endl;
			else
				cout << "HERROUR !!" << endl;
			system("PAUSE");
			break;
		case 3:	system("cls");
			cout << "Donnez le nom de l'user : ";
			cin >> username;
			if (creationSession(username))
				cout << "La session est cree" << endl;
			else
				cout << "HERROUR !!" << endl;
			system("PAUSE");
			break;
		case 4:	system("cls");
			cout << "Donnez le nom de l'user : ";
			cin >> username;
			if (OuvertureSession(username))
				cout << "La session est ouvete" << endl;
			else
				cout << "HERROUR !!" << endl;
			system("PAUSE");
			break;
		case 5:	system("cls");
			cout << "Donnez le nom de l'user : ";
			cin >> username;
			if (FermetureSession(username))
				cout << "La session est Fermee" << endl;
			else
				cout << "HERROUR !!" << endl;
			system("PAUSE");
			break;
		case 6:	system("cls");

			cout << "Donnez le nom de l'user : ";
			cin >> username;
			if (SupprimerSession(username))
				cout << "La session est Supprimer" << endl;
			else
				cout << "HERROUR !!" << endl;
			system("PAUSE");
			break;


		default:cout << "erreur!!" << endl;
			break;
		}
		
	} while (choix != 0);

}





bool CreationFichier(char* UserName,char* FileName)
{
	int NumCP = researchCP(UserName);
	if (NumCP == NotFoundCP)
		return FileNotCreated;
	else
	{

		int NumSectCI = Research_FreeSector();
		if (NumSectCI == NotFoundSector)
			return FileNotCreated;
		else
		{
			if (ResearchFileInCP(NumCP, FileName) != NotFoundCP)
				return false;
			int ind = Research_Dispo_CI();
			if (ind == NotFoundCI)
				return false;
			RendreNNDispoCI(ind);
			Charger_CI(NumSectCI, ind);
			Init_CI(ind);
			Sauvegarder_CIs(ind);
			RendreDispoCI(ind);
			int NumIntern = ResearchFreeDescriptor();

			if(NumIntern == NotFoundDescripteur)
				if(AllongerVTOC())
					NumIntern = ResearchFreeDescriptor();
				else
					return FileNotCreated;
			if (AddDescriptor(0, NumSectCI, NumIntern) == UNDONE)
				return FileNotCreated;
			

			if (AddFileToCP(NumCP, FileName, NumIntern) == UNDONE)
				if(researchCP(UserName) != NotFoundCP && AllongerCatPriv(NumCP))
					if (AddFileToCP(NumCP, FileName, NumIntern) == UNDONE)
						return FileNotCreated;
			
			OccuperSector(NumSectCI);
			Sauvegarder_CP(NumCP);
			Sauvegarder_TOS();
			return FileCreated;


		}
	}
}





bool DestructionFichier(char* UserName, char* FileName)
{
	int NumCP = researchCP(UserName);
	if (NumCP == NotFoundCP)
		return false;
	else
	{
		FermetureFichier(UserName, FileName);

		CatPrivInMemory* pTabCPs = RecupTabCPs();
		int indexFile = ResearchFileInCP(NumCP, FileName);
		if (indexFile == NotFoundCP)
			return false;
		else
		{
			int NumIntern = pTabCPs[NumCP].CatPrive[indexFile].Intern;

			Descripteur D;

			if (BackUpDescriptor(D, NumIntern) == UNDONE)
				return false;
			else
			{
				int x = Research_Dispo_CI();
				if (x == NotFoundCI)
					return false;
				RendreNNDispoCI(x);
				CIinMemory* pTabCIs = RecupTabCI();
				Charger_CI(D.NumSectorCI, x);
				int i = 0;
				while (i < TailleCI && pTabCIs[x].CI[i] != EmptyCaseCI)
					LibererSector(pTabCIs[x].CI[i++]);
				LibererSector(D.NumSectorCI);

				LibererDescripteur(NumIntern);
				DelFileFromCP(NumCP, FileName);
				sauvegarder_VTOC();
				Sauvegarder_TOS();
				return true;
			}
		}
	}
}


bool DestructionFilesUser(char* UserName)
{
	int NumCP = researchCP(UserName);
	if (NumCP == NotFoundCP)
		return false;
	else
	{
		CatPrivInMemory* pTabCP = RecupTabCPs();
		int indexCI_CP = RecupIndexCI_CP(NumCP);
		CIinMemory* pTabCI = RecupTabCI();
		int indice = 0;
		while (indice < TailleCI && pTabCI[indexCI_CP].CI[indice] != EmptyCaseCI)
		{
			Charger_CP(NumCP, pTabCI[indexCI_CP].CI[indice]);
			for (int i = 0; i < TailleCatPrive; i++)
			{
				if (pTabCP[NumCP].CatPrive[i].Intern != EmptyCaseVTOC)
					DestructionFichier(UserName, pTabCP[NumCP].CatPrive[i].NomExtern);
			}
			indice++;
		}
		return true;
	}
}

bool OuvertureFichier(char* UserName, char* FileName)
{
	if (ResearchCI_File(UserName, FileName) != NotFoundCI)
		return false;
	else
	{
		int NumCP = researchCP(UserName);
		if (NumCP == NotFoundCP)
			return false;
		else
		{
			int indexFile = ResearchFileInCP(NumCP, FileName);

			if (indexFile == NotFoundCP)
				return false;
			else
			{
				CatPrivInMemory* pTabCPs = RecupTabCPs();
				
				int NumIntern = pTabCPs[NumCP].CatPrive[indexFile].Intern;
				Descripteur D;
				
				if (BackUpDescriptor(D,NumIntern) == UNDONE)
					return false;
				else
				{
					int indiceCI = Research_Dispo_CI();
					if (indiceCI == NotFoundCI)
						return false;
					else
					{
						RendreNNDispoCI(indiceCI);
						Charger_CI(D.NumSectorCI, indiceCI);
						ComplementCI* pTabComplementCIs = RecupTabComplementCI();
						strcpy(pTabComplementCIs[indiceCI].FileName, FileName);
						strcpy(pTabComplementCIs[indiceCI].UserName, UserName);
						return true;
					}

				}
			
			}

		}
	}
}


















bool DemarrageSE()
{
	Charger_TOS();
	init_CPs();
	Init_TablesCI();

	if (Charger_VTOC(NumSect_FirstPart_VTOC) == UNDONE)
		return UNDONE;
	else
	{
		
		if(RendreNNDispoCI(IndexCI_VTOC) == false)
			return false;
		else
		{
			Descripteur D;
			
			if (BackUpDescriptor(D, NumInternVTOC) == UNDONE)
				return false;
				
			Charger_CI(D.NumSectorCI, IndexCI_VTOC);
			
			if(RendreNNDispoCI(IndexCI_CG) == false)
				return false;
			else
			{
				if (BackUpDescriptor(D, NumInternCG) == UNDONE)
					return false;

				
				Charger_CI(D.NumSectorCI, IndexCI_CG);
				if (RendreNNDispoCP(IndexCG) == false)
					return false;
				else
				{
					InscrireCIofCatPriv(IndexCG, IndexCI_CG);
					Charger_FirstPartCP(IndexCG);
					
					
					return true;
				}
			}
			
		}

	}

}




bool FormatageDisque()
{
	creation_disque();

	init_TOS();
	Init_TablesCI();
	init_CPs();

	OccuperSector(Secteur_TOS);
	OccuperSector(NumSect_FirstPart_VTOC);
	Charger_VTOC(NumSect_FirstPart_VTOC);
	InitPartOfVTOC();

	int NumSectCI_VTOC = Research_FreeSector();
	OccuperSector(NumSectCI_VTOC);
	RendreNNDispoCI(IndexCI_VTOC);
	Charger_CI(NumSectCI_VTOC, IndexCI_VTOC);
	Init_CI(IndexCI_VTOC);
	Add_Enregistrement(IndexCI_VTOC, NumSect_FirstPart_VTOC);
	
	
	if (Sauvegarder_CIs(IndexCI_VTOC) == UNDONE)
		return false;
	AddDescriptorInPartOfVTOC(1, NumSectCI_VTOC, NumInternVTOC);

	int NumSectCI_CG = Research_FreeSector();
	OccuperSector(NumSectCI_CG);
	RendreNNDispoCI(IndexCI_CG);
	
	Charger_CI(NumSectCI_CG, IndexCI_CG);
	Init_CI(IndexCI_CG);
	
	
	int NumSect_FirstPart_CG = Research_FreeSector();
	OccuperSector(NumSect_FirstPart_CG);

	Add_Enregistrement(IndexCI_CG, NumSect_FirstPart_CG);
	
	if (Sauvegarder_CIs(IndexCI_CG) == UNDONE)
		return false;
	AddDescriptorInPartOfVTOC(1, NumSectCI_CG, NumInternCG);

	RendreNNDispoCP(IndexCG);
	Charger_CP(IndexCG, NumSect_FirstPart_CG);
	init_PartOfCatPriv(IndexCG);
	Sauvegarder_CP(IndexCG);
	RendreDispoCP(IndexCG);
	sauvegarder_VTOC();
	Sauvegarder_TOS();

	return true;


}




bool creationSession(char* UserName)
{
	int NumSectCI = Research_FreeSector();
	if (NumSectCI == NotFoundSector)
		return FileNotCreated;
	else
	{
		
		int ind = Research_Dispo_CI();
		if (ind == NotFoundCI)
			return false;
		RendreNNDispoCI(ind);
		Charger_CI(NumSectCI, ind);
		if (Init_CI(ind) == false)
			return false;
		Sauvegarder_CIs(ind);
		
		int NumIntern = ResearchFreeDescriptor();

		if (NumIntern == NotFoundDescripteur)
			if (AllongerVTOC())
				NumIntern = ResearchFreeDescriptor();
			else
				return FileNotCreated;
		if (AddDescriptor(0, NumSectCI, NumIntern) == UNDONE)
			return FileNotCreated;


		if (AddFileToCP(IndexCG, UserName, NumIntern) == UNDONE)
			if (AllongerCatPriv(IndexCG))
				if (AddFileToCP(IndexCG, UserName, NumIntern) == UNDONE)
				{
					LibererDescripteur(NumIntern);
					return FileNotCreated;
				}

		Sauvegarder_CP(IndexCG);
		sauvegarder_VTOC();
		OccuperSector(NumSectCI);

		int NumSect_FirstPartCP = Research_FreeSector();
		if (NumSect_FirstPartCP == NotFoundSector)
			return false;
		else
		{
			
			if (Add_Enregistrement(ind, NumSect_FirstPartCP) == false)
				return false;
			int indexCP = ResearchDispoCP();
			if (indexCP == NotFoundCP)
				return false;
			else
			{
				RendreNNDispoCP(indexCP);
				Charger_CP(indexCP, NumSect_FirstPartCP);
				init_PartOfCatPriv(indexCP);
				Sauvegarder_CP(indexCP);
				RendreDispoCP(indexCP);
			}
		}

		OccuperSector(NumSect_FirstPartCP);
		Sauvegarder_CIs(ind);
		RendreDispoCI(ind);
		Sauvegarder_TOS();
		return FileCreated;
	}
}






bool OuvertureSession(char* UserName)
{

	int x = ResearchFileInCP(IndexCG, UserName);
	if (x == NotFoundCP)
		return false;
	else
	{
		CatPrivInMemory* pTabCPs = RecupTabCPs();
		
		int NumIntern = pTabCPs[IndexCG].CatPrive[x].Intern;
		Descripteur D;
		
		if (BackUpDescriptor(D, NumIntern) == false)
			return false;
		else
		{
			int indexCI = Research_Dispo_CI();
			if (indexCI == NotFoundCI)
				return false;
			else
			{
				RendreNNDispoCI(indexCI);
				Charger_CI(D.NumSectorCI, indexCI);
				int NumCP = ResearchDispoCP();
				if (NumCP == NonTrouveeCP)
					return false;
				else
				{
					RendreNNDispoCP(NumCP);
					InscrireCIofCatPriv(NumCP, indexCI);
					Charger_FirstPartCP(NumCP);
					InscrireNameOfCatPriv(NumCP, UserName);
					
					return true;
				}
			}
		}

	}
}


bool FermetureSession(char* UserName)
{
	int NumCP = researchCP(UserName);
	if (NumCP == NotFoundCP)
		return false;
	else
	{
		CatPrivInMemory* pTabCPs = RecupTabCPs();
		Sauvegarder_CP(NumCP);
		Sauvegarder_CIs(RecupIndexCI_CP(NumCP));
		FermetureFichiers_User(UserName);
		RendreDispoCI(RecupIndexCI_CP(NumCP));
		RendreDispoCP(NumCP);
		return true;
	}
}






bool AjouterEnregistrementFichier(char* UserName, char* FileName, char enreg[TAILLE_SECT])
{
	int IndexCI = ResearchCI_File(UserName,FileName);
	if (IndexCI == NotFoundCI)
		return false;
	else
	{
		int NumSect = Research_FreeSector();
		if (NumSect == NotFoundSector)
			return false;
		if (Add_Enregistrement(IndexCI,NumSect) == false)
			return false;
		else
		{
			OccuperSector(NumSect);
			ecriture_bloc(NumSect, enreg);
			Sauvegarder_CIs(IndexCI);
			Sauvegarder_TOS();
			return true;
		}
	}
}



bool Supp_enregistrement_fichier(char* UserName, char* FileName, int NumOrdre)
{
	if (NumOrdre < 0 || NumOrdre >= TailleCI)
		return false;
	int IndexCI = ResearchCI_File(UserName, FileName);
	if (IndexCI == NotFoundCI)
		return false;
	else
	{
		CIinMemory* pTabCIs = RecupTabCI();
		int NumSect = pTabCIs[IndexCI].CI[NumOrdre];
		if (Del_Enregistrement(IndexCI,NumOrdre) == false)
			return false;
		else
		{
			LibererSector(NumSect);
			Sauvegarder_CIs(IndexCI);
			Sauvegarder_TOS();
			return true;
		}
	}
}




bool LectureEnregistrementFichier(char* UserName, char* FileName, int NumOrdre, char enreg[TAILLE_SECT])
{
	if (NumOrdre < 0 || NumOrdre >= TAILLE_SECT)
		return false;
	int IndexCI = ResearchCI_File(UserName, FileName);
	if (IndexCI == NotFoundCI)
		return false;
	else
	{
		CIinMemory* pTabCIs = RecupTabCI();
		int NumSect = pTabCIs[IndexCI].CI[NumOrdre];
		if (NumSect == NotFoundSector)
			return false;
		else
		{
			lecture_bloc(NumSect, enreg);
			return true;
		}
	}
}



bool EcritureEnregistrementFichier(char* UserName, char* FileName, int NumOrdre, char enreg[TAILLE_SECT])
{
	if (NumOrdre < 0 || NumOrdre >= TAILLE_SECT)
		return false;
	int IndexCI = ResearchCI_File(UserName, FileName);
	if (IndexCI == NotFoundCI)
		return false;
	else
	{
		CIinMemory* pTabCIs = RecupTabCI();
		int NumSect = pTabCIs[IndexCI].CI[NumOrdre];
		if (NumSect == NotFoundSector)
			return false;
		else
		{
			ecriture_bloc(NumSect, enreg);
			return true;
		}
	}
}



bool ModifierNomFichier(char* UserName, char* FileName,char* nouv_nom)
{
	int IndexCP = researchCP(UserName);
	if (IndexCP == NotFoundCI)
		return false;
	else
	{
		FermetureFichier(UserName,FileName);
		if (ModifFileNameInCP(IndexCP, FileName, nouv_nom))
			return true;
		else
			return false;
	}
}





bool SupprimerSession(char* userName)
{
	int indexFile = ResearchFileInCP(IndexCG, userName);
	if ( indexFile == NotFoundCP)
		return false;
	else
	{
		FermetureFichiers_User(userName);
		FermetureSession(userName);
		OuvertureSession(userName);
		DestructionFilesUser(userName);
		FermetureSession(userName);
		CatPrivInMemory* pTabCPs = RecupTabCPs();
		int NumIntern = pTabCPs[IndexCG].CatPrive[indexFile].Intern;
		if (NumIntern == NotFoundDescripteur)
			return false;
		else
		{
			Descripteur D;
			if (BackUpDescriptor(D, NumIntern) == UNDONE)
				return false;
			else
			{
				int IndexCI = Research_Dispo_CI();
				if (IndexCI == NotFoundCI)
					return false;
				RendreNNDispoCI(IndexCI);
				Charger_CI(D.NumSectorCI, IndexCI);
				CIinMemory* pTabCIs = RecupTabCI();
				for (int i = 0; i < TailleCI; i++)
					if (pTabCIs[IndexCI].CI[i] != EmptyCaseCI)
						LibererSector(pTabCIs[IndexCI].CI[i++]);
				LibererSector(D.NumSectorCI);
				LibererDescripteur(NumIntern);
				DelFileFromCP(IndexCG, userName);
				RendreDispoCI(IndexCI);
				return true;
			}
		}
	}
}