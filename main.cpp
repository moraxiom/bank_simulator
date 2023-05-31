#include <iostream> 
#include <clocale>
#include <fstream>
#include <string>
#include <cctype>
#include <chrono>

using namespace std;
const int MAX{ 100 };

struct Compte
{
	string prenom{ "" };
	string nom{ "" };
	int nCompte{ 0 };
	int nip{ 0 };
	float solde{ 0 };
};

enum class Type
{
	Retrait,
	Depot,
	Transfert,
};

struct Transaction
{
	Type type{ };
	float solde{ };
};

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

	system("pause");
	system("cls");
}

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

	system("pause");
	system("cls");
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
	system("pause");
	system("cls");
}

void AfficherMenu(int& indice, Compte infostableau[])
{
	cout << "===============================================" << endl;
	cout << "|                BANQUE SNYDER                |" << endl;
	cout << "===============================================" << endl;
	cout << endl;
	cout << " Bienvenue, " << infostableau[indice].prenom << " " << infostableau[indice].nom << " !" << endl;
	cout << " Voici vos options : " << endl;
	cout << endl;
	cout << " [1] - Afficher le solde du compte" << endl;
	cout << " [2] - Effectuer un retrait" << endl;
	cout << " [3] - Deposer une somme d'argent" << endl;
	cout << " [4] - Transfert vers un autre compte" << endl;
	cout << " [5] - Voir l'historique des transactions" << endl;
	cout << " [6] - QUITTER" << endl;
	cout << endl;
}

void AfficherSolde(int& indice, Compte infostableau[])
{
	cout << "===============================================" << endl;
	cout << "|                VOTRE SOLDE!                 |" << endl;
	cout << "===============================================" << endl;
	cout << endl;
	cout << " Vous avez " << infostableau[indice].solde << "$ dans votre compte." << endl;
	cout << endl;
}

void AfficherBarreRetrait()
{
	cout << "===============================================" << endl;
	cout << "|            EFFECTUER UN RETRAIT?            |" << endl;
	cout << "===============================================" << endl;
	cout << endl;
}

void AfficherBarreDepot()
{
	cout << "===============================================" << endl;
	cout << "|             EFFECTUER UN DEPOT?             |" << endl;
	cout << "===============================================" << endl;
	cout << endl;
}

void AfficherBarreTransfert()
{
	cout << "===============================================" << endl;
	cout << "|           EFFECTUER UN TRANSFERT?           |" << endl;
	cout << "===============================================" << endl;
	cout << endl;
}

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

int RechercherCompte(int size, int inputNC, Compte infostableau[])
{
	int g{ 0 };
	int d{ size };
	int milieu{ };

	while (g <= d)
	{
		milieu = ((g + d) / 2);
		if (infostableau[milieu].nCompte == inputNC)
		{
			return milieu;
		}
		else if (infostableau[milieu].nCompte < inputNC)
		{
			g = milieu + 1;
		}
		else
		{
			d = milieu - 1;
		}
	}
	return -2;
}

float EffectuerRetrait(int& indice, Compte infostableau[])
{
	float retrait{ 0.0f };
	do
	{
		cout << " Retirer au compte : ";
		cin >> retrait;
		if (retrait < 0)
		{
			cout << "Vous ne pouvez pas retirer une somme negative." << endl;
		}
	} while (retrait < 0);

	return (infostableau[indice].solde - retrait);
}

float EffectuerDepot(int& indice, Compte infostableau[])
{
	float depot{ 0.0f };
	do
	{
		cout << " Ajouter au compte : ";
		cin >> depot;
		if (depot < 0)
		{
			cout << "Vous ne pouvez pas retirer une somme negative." << endl;
		}
	} while (depot < 0);

	return (infostableau[indice].solde + depot);
}

bool ValiderInputCompte(int inputNC)
{
	string n1{ to_string(inputNC) };

	if (n1.size() != 6)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int TrouverIndiceReceveur(int size, int& indice, Compte infostableau[])
{
	int inputNC{ };
	int n{ };
	do
	{
		cout << " # de compte du receveur : ";
		cin >> inputNC;
		n = RechercherCompte(size, inputNC, infostableau);

	} while (ValiderInputCompte(inputNC) == false || n == -2);

	return n;
}

float EffectuerTransfert(int size, int& indice, Compte infostableau[])
{
	float nSolde{ };
	float nSoldeRec{ };
	int nRec{ };
	float somme{ 0.0f };

	nRec = TrouverIndiceReceveur(size, indice, infostableau);
	cout << " Montant a transferer : ";
	cin >> somme;

	nSolde = (infostableau[indice].solde - somme);
	infostableau[indice].solde = nSolde;
	nSoldeRec = (infostableau[nRec].solde + somme);
	infostableau[nRec].solde = nSoldeRec;

	return nSolde;
}

void AfficherHistorique(int nTransaction, Transaction historique[])
{
	cout << "===============================================" << endl;
	cout << "|         HISTORIQUE DES TRANSACTIONS         |" << endl;
	cout << "===============================================" << endl;
	cout << endl;
	cout << " TYPE DE TRANSACTION			SOLDE" << endl;
	cout << "-----------------------------------------------" << endl;

	int taille{ nTransaction + 1 };
	for (int i{ 0 }; i < taille; i++)
	{
		switch (historique[i].type)
		{
			case Type::Retrait:
				cout << " Retrait";
				break;

			case Type::Depot:
				cout << " Depot";
				break;

			case Type::Transfert:
				cout << " Transfert";
				break;
		}
		cout << "				";
		cout << historique[i].solde << endl;
	}
}

void SauvegarderDonnees(int size, Compte infostableau[])
{
	ofstream fichier{ "informations.txt" };
	for (int i{ 0 }; i < size; i++)
	{
		fichier << infostableau[i].prenom << " " << infostableau[i].nom << " " << infostableau[i].nCompte;
		fichier << " " << infostableau[i].nip << " " << infostableau[i].solde << endl;
	}
}

int ExecuterOperations(int size, int& indice, int inputNC, int choix, int nTransaction, Transaction historique[], Compte infostableau[])
{
	float nSolde{ };
	switch (choix)
	{
		case 1:
			AfficherSolde(indice, infostableau);
			break;

		case 2:
			AfficherBarreRetrait();
			nSolde = EffectuerRetrait(indice, infostableau);
			infostableau[indice].solde = nSolde;
			historique[nTransaction].type = Type::Retrait;
			historique[nTransaction].solde = nSolde;
			break;


		case 3:
			AfficherBarreDepot();
			nSolde = EffectuerDepot(indice, infostableau);
			infostableau[indice].solde = nSolde;
			historique[nTransaction].type = Type::Depot;
			historique[nTransaction].solde = nSolde;
			break;

		case 4:
			AfficherBarreTransfert();
			nSolde = EffectuerTransfert(size, indice, infostableau);
			historique[nTransaction].type = Type::Transfert;
			historique[nTransaction].solde = nSolde;
			break;

		case 5:
			AfficherHistorique(nTransaction, historique);
			break;

		case 6:
			SauvegarderDonnees(size, infostableau);
			return 0;

		default:
			return -3;
	}
}

bool ValiderInputNIP(int& inputNIP)
{
	string n2{ to_string(inputNIP) };

	if (n2.size() != 5)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool ValiderInformations(int& indice, int& inputNIP, Compte infostableau[])
{
	if (indice == -2)
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

bool ConnecterJoueur(int size, int& indice, int inputNC, int& inputNIP, Compte infostableau[])
{
	indice = RechercherCompte(size, inputNC, infostableau);
	if ((ValiderInputCompte(inputNC) == false) || (ValiderInputNIP(inputNIP) == false))
	{
		AfficherAideFormat();
		return false;
	}
	else if (ValiderInformations(indice, inputNIP, infostableau) == false)
	{
		AfficherAideConnexion();
		return false;
	}
	return true;
}

int main()
{
	locale::global(locale("C"));

	ifstream fichier{ "informations.txt" };
	Compte infostableau[MAX]{ };
	Transaction historique[MAX]{ };

	int inputNC{ 0 };
	int inputNIP{ 0 };
	int size{ Taille() };
	int indice{ };

	CreerTableau(size, infostableau);

	do
	{
		AfficherBarreConnexion();
		cout << "      # de compte : ";
		cin >> inputNC;
		cout << "      NIP : ";
		cin >> inputNIP;
		AfficherBarreValidation();
	}
	while (ConnecterJoueur(size, indice, inputNC, inputNIP, infostableau) == false);

	int nTransaction{ };
	int choix{ };
	do
	{
		AfficherMenu(indice, infostableau);
		cin >> choix;
		system("cls");

		ExecuterOperations(size, indice, inputNC, choix, nTransaction, historique, infostableau);
		system("pause");
		system("cls");
		nTransaction++;
	}
	while (choix != 6);
	
	return 0;
}