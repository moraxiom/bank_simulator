#include <iostream>
#include <clocale>
#include <fstream>
#include <string>

using namespace std;

const int MAX{ 100 };

struct Compte
{
	string prenom{ "" };
	string nom{ "" };
	int nCompte{ 0 };
	int nip{ 0 };
	int solde{ 0 };
};

int Taille()
{
	ifstream fichier("informations.txt");
	if (!fichier.is_open())
	{
		return -1;
	}
	else
	{
		string ligne{ };
		int i{ 0 };
		for (i; !fichier.is_open(); i++)
		{
			getline(fichier, ligne);
		}
		return i;
	}
}

int CreerTableau(int taille, Compte infostableau[])
{
	ifstream fichier("informations.txt");
	if (!fichier.is_open())
	{
		return -1;
	}
	else
	{
		Compte infos{};
		for (int i{ 0 }; i < taille; i++)
		{
			fichier >> infos.prenom >> infos.nom >> infos.nCompte >> infos.nip >> infos.solde;
		}
	}
	return 0;
}

void AfficherMenu()
{
	cout << "===============================================" << endl;
	cout << "|        BIENVENUE À LA BANQUE SNYDER!        |" << endl;
	cout << "===============================================" << endl;
	cout << endl;
	cout << " [1] - Afficher le solde du compte" << endl;
	cout << " [2] - Effectuer un retrait" << endl;
	cout << " [3] - Effectuer un dépôt" << endl;
	cout << " [4] - Voir l'historique des transactions" << endl;
	cout << " [5] - QUITTER" << endl;
	cout << endl;
}

void AfficherAide()
{
	cout << "===============================================" << endl;
	cout << "|                   UH-OH!                    |" << endl;
	cout << "===============================================" << endl;
	cout << endl;
	cout << " Votre numéro de compte et/ou votre NIP ne" << endl;
	cout << " correspond pas au format demandé!" << endl;
	cout << endl;
	cout << " NUMÉRO : 6 CHIFFRES" << endl;
	cout << " NIP : 5 CHIFFRES" << endl;
	cout << endl;
	cout << "===============================================" << endl;
	cout << "|             VEUILLEZ RÉESSAYER!             |" << endl;
	cout << "===============================================" << endl;
}

void ObtenirInput(int inputNC, int inputNIP)
{
	cout << "===============================================" << endl;
	cout << "|                CONNEXION...                 |" << endl;
	cout << "===============================================" << endl;
	cout << endl;
	cout << "      Numéro de compte : ";
	cin >> inputNC;
	cout << "      NIP : ";
	cin >> inputNIP;
	cout << endl;
	cout << "===============================================" << endl;
	cout << "|            VALIDATION EN COURS...           |" << endl;
	cout << "===============================================" << endl;
	cout << endl;
}

bool ValiderInformations(int taille, int inputNC, int inputNIP, Compte infos[])
{
	int g{ 0 };
	int d{ taille - 1 };
	int milieu{ };

	int i{ 0 };
	while (g > d)
	{
		milieu = ((g + d) / 2);
		if (milieu == i)
		{
			return milieu;
		}
		else if (milieu > g)
		{

		}
		else
		{

		}
	}

	return true;
}

int main()
{
	setlocale(LC_ALL, "");

	ifstream fichier{ "informations.txt" };
	int inputNC{ 0 };
	int inputNIP{ 0 };
	int taille{ Taille() };
	Compte infostableau[MAX]{ };

	ObtenirInput(inputNC, inputNIP);
	system("pause");

	CreerTableau(taille, infostableau);
	AfficherMenu();

	return 0;
}