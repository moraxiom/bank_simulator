#include <iostream>
#include <clocale>
#include <fstream>
#include <string>

using namespace std;
const int MAX{ 100 };

/* STRUCT */
struct Compte
{
	string prenom{ "" };
	string nom{ "" };
	int nCompte{ 0 };
	int nip{ 0 };
	float solde{ 0 };
};
/* STRUCT */

/* INT */
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
		for (i; !fichier.eof(); i++)
		{
			getline(fichier, ligne);
		}
		return i;
	}
}

int CreerTableau(int size, Compte infostableau[])
{
	ifstream fichier("informations.txt");
	if (!fichier.is_open())
	{
		return -1;
	}
	else if (fichier.is_open())
	{
		Compte infos{};
		for (int i{ 0 }; i < size; i++)
		{
			fichier >> infos.prenom >> infos.nom >> infos.nCompte >> infos.nip >> infos.solde;
			infostableau[i] = infos;
		}
	}
	return 0;
}

int RechercherCompte(int size, int& inputNC, int& inputNIP, Compte infostableau[])
{
	int g{ 0 };
	int d{ size - 1 };
	int milieu{ };

	while (g <= d)
	{
		milieu = ((g + d) / 2);
		if (infostableau[milieu].nCompte == inputNC)
		{
			return milieu;
		}
		else if (infostableau[milieu].nCompte > g)
		{
			g = milieu + 1;
		}
		else
		{
			d = milieu - 1;
		}
	}
	return -1;
}
/* INT */

/* BOOL */
/*
bool ValiderInput(int size, int indice, int& inputNC, int& inputNIP, Compte infostableau[])
{
	return true;
}
*/

bool ValiderInformations(int size, int indice, int& inputNC, int& inputNIP, Compte infostableau[])
{
	if (indice == -1)
	{
		return false;
	}
	else
	{
		if (infostableau[indice].nip == inputNIP)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
/* BOOL */

/*
void AfficherAideFormat()
{
	cout << "===============================================" << endl;
	cout << "|             VEUILLEZ REESSAYER!             |" << endl;
	cout << "===============================================" << endl;
	cout << endl;
	cout << " Votre # de compte et/ou votre NIP ne" << endl;
	cout << " correspond pas au  bon format!" << endl;
	cout << endl;
	cout << " # : 6 CHIFFRES" << endl;
	cout << " NIP : 5 CHIFFRES" << endl;
	cout << endl;
}
*/

/* AFFICHAGE */
void AfficherAideConnexion()
{
	cout << "===============================================" << endl;
	cout << "|             VEUILLEZ REESSAYER!             |" << endl;
	cout << "===============================================" << endl;
	cout << endl;
	cout << " Votre # de compte et/ou votre NIP est" << endl;
	cout << " introuvable!" << endl;
	cout << endl;
	cout << " OU" << endl;
	cout << " Votre NIP ne correspond pas au NIP de" << endl;
	cout << " votre compte!" << endl;
	cout << endl;
}

void AfficherBarreConnexion()
{
	cout << "===============================================" << endl;
	cout << "|                CONNEXION...                 |" << endl;
	cout << "===============================================" << endl;
	cout << endl;
}

void AfficherBarreValidation()
{
	cout << endl;
	cout << "===============================================" << endl;
	cout << "|            VALIDATION EN COURS...           |" << endl;
	cout << "===============================================" << endl;
	cout << endl;
	cout << endl;
	system("pause");
	system("cls");
}

void AfficherMenu()
{
	cout << "===============================================" << endl;
	cout << "|                BANQUE SNYDER                |" << endl;
	cout << "===============================================" << endl;
	cout << endl;
	cout << " [1] - Afficher le solde du compte" << endl;
	cout << " [2] - Effectuer un retrait" << endl;
	cout << " [3] - Deposer une somme d'argent" << endl;
	cout << " [4] - Voir l'historique des transactions" << endl;
	cout << " [5] - QUITTER" << endl;
	cout << endl;
}
/* AFFICHAGE */

int main()
{
	locale::global(locale("C"));

	ifstream fichier{ "informations.txt" };
	Compte infostableau[MAX]{};
	int inputNC{ 0 };
	int inputNIP{ 0 };
	int size{ Taille() };
	int indice{ };

	do
	{
		AfficherBarreConnexion();
		cout << "      # de compte : ";
		cin >> inputNC;
		cout << "      NIP : ";
		cin >> inputNIP;
		AfficherBarreValidation();

		CreerTableau(size, infostableau);
		indice = (RechercherCompte(size, inputNC, inputNIP, infostableau));

		if (ValiderInformations(size, indice, inputNC, inputNIP, infostableau) == false)
		{
			AfficherAideConnexion();
			system("pause");
		}
		else
		{
			AfficherMenu();
		}
	}
	while (false);
	return 0;
}