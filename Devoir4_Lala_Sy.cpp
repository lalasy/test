#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

const int DUREE_MIN = 1;
const int DUREE_MAX = 14;
const int NBRE_ENFANTS_MIN = 0;
const int NBRE_ENFANTS_MAX = 12;
const int AGE_MIN = 1;
const int AGE_MAX = 12;
const double TAXE = 0.15;
const int TAILLE = 12;

int lireValiderEntierEntre(int p_min, int p_max);
char lireValider2Char(char char1, char char2);
double retourRabaisEnfant(int age);
void afficheRecapitulatif(int compteurFacture, int montantFacture);

int main(void)
{
	char choix = NULL;
	string nomDuClient = " ";
	string typeDeSejour = " ";
	int dureeDuSejour = 0;
	char choixtypeDeSejour = NULL;
	int nbreEnfant = 0;
	int age = 0;
	double tarif = 0;
	double rabais = 0.0;
	double rabaisTotal = 0.0;
	double coutDuSejour = 0.0;
	double montantRabais = 0.0;
	double sousTotal = 0.0;
	double montantTaxe = 0.0;
	double grandTotal = 0.0;
	int nbreDeFacture = 0;
	double montantTotal = 0.0;
	int tabAge[TAILLE] = { 0 };
	int nbreDefacture = 0;
	int compteurFacture = 0;
	double montantFacture = 0.0;

	cout << "FACTURATION CLUB MED" << endl;

	do
	{
		cout << "1 - Entrer les informations pour produire une facture" << endl
			<< "2 - Generer et afficher la facture" << endl
			<< "3 - Afficher le recapitulatif de facturation pour la journee" << endl
			<< "4 - Terminer le programme" << endl << endl
			<< "Entrer votre choix (1,2,3 ou 4): ";
		cin >> choix;

		while (choix != '1' && choix != '2' && choix != '3' && choix != '4')
		{
			cout << "Choix incorrect. Entrez votre choix: ";
			cin >> choix;
		}
	

		if (choix != '4')
		{
			system("cls");
			switch (choix)
			{

			case '1':
				cout << "--- ENTRER DES INFORMATIONS---" << endl << endl << endl;
				cout << "Entrer le nom du client: ";
				cin >> nomDuClient;

				cout << endl << "Entrer la duree du sejour (un nombre entier entre 1 et 14) : ";
				dureeDuSejour = lireValiderEntierEntre(DUREE_MIN, DUREE_MAX);

				cout << "Entrer le type de sejour (R - regulier ou T - tout inclus) : ";
				choixtypeDeSejour = lireValider2Char('R','T');
				cout << endl << "Entrer le nombre d'enfant (un nombre entier entre 0 et 12) : ";
				nbreEnfant = lireValiderEntierEntre(NBRE_ENFANTS_MIN, NBRE_ENFANTS_MAX);

				rabaisTotal = 0.0;
				for (int i = 0; i < nbreEnfant; i++)
				{
					
					cout << "Entrer l'age (moins de 12) de l'enfant #" << i + 1 << " :";
					tabAge[i] = lireValiderEntierEntre(AGE_MIN, AGE_MAX);

					rabais = retourRabaisEnfant(tabAge[i]);
					rabaisTotal += rabais;

				}

				break;
			case '2':

				cout << "\t\t\t CLUB MED FACTURE" << endl;
				switch (choixtypeDeSejour)
				{
				case 'R':
					if (dureeDuSejour <= 3)
					{
						tarif = 250;
					}
					else if (dureeDuSejour <= 7)
					{
						tarif = 240;
					}
					else if (dureeDuSejour <= 14)
					{
						tarif = 220;
					}
					typeDeSejour = "Regulier";
					break;
				case 'T':
					if (dureeDuSejour <= 3)
					{
						tarif = 350;
					}
					else if (dureeDuSejour <= 7)
					{
						tarif = 340;
					}
					else if (dureeDuSejour <= 14)
					{
						tarif = 320;
					}
					typeDeSejour = "Tout inclus";
				
				}


				coutDuSejour = dureeDuSejour * tarif;
				montantRabais = coutDuSejour * rabaisTotal / 100;
				sousTotal = coutDuSejour - montantRabais;
				montantTaxe = sousTotal * TAXE;
				grandTotal = sousTotal + montantTaxe;
				compteurFacture = compteurFacture + 1;
				montantFacture += grandTotal;

				cout << endl << "Nom du client : " << nomDuClient << endl
					<< "Duree du sejour : " << dureeDuSejour << endl
					<< "Type de sejour : " << typeDeSejour << endl
					<< "Nombre d'enfants : " << nbreEnfant << endl
					<< "Cout du sejour : " << fixed << setprecision(2) << coutDuSejour << "$" << endl << endl
					<< "Rabais pour enfants (" << rabaisTotal << "%) : " << montantRabais << "$" << endl << endl
					<< "==========" << endl
					<< "Sous-Total: " << sousTotal << "$" << endl
					<< "Taxe(15.00 %): " << montantTaxe << "$" << endl
					<< "==========" << endl << endl
					<< "Montant a payer: " << grandTotal << "$" << endl << endl << endl;

				break;
			case '3':
				
				afficheRecapitulatif(compteurFacture, montantFacture);
				
				break;
			default:
				break;
			
			}

			cout << endl << "Appuyer sur une touche pour retourner au menu principal." << endl;

			cin.clear();
			cin.ignore();
			system("pause");

			system("cls");
		}

	} while (choix != '4');

	cout << endl << endl << "Merci d'avoir utilise un logiciel de qualite cree par logiprog inc." << endl;
	return (0);
}
int lireValiderEntierEntre(int p_min , int p_max)
{
	int	valeur = 0;

	cin >> valeur;

	while (!cin || valeur < p_min || valeur > p_max)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Votre entree est incorrecte.  S.V.P. reessayez : ";
		cin >> valeur;
	}
	return valeur;
}
char lireValider2Char(char char1, char char2)
{
	char valeur = NULL;
	
	cin >> valeur;

	while (!cin || valeur != char1 && valeur != char2)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Votre entree est incorrecte.  S.V.P. reessayez : ";
		cin >> valeur;
	}
	return valeur;
}
double retourRabaisEnfant(int age)
{
	double valeur = 0.0;

	if (age <= 5)
	{
		valeur = 4 ;
	}
	else if (age <= 8)
	{
		valeur = 3;
	}
	else if (age <= 12)
	{
		valeur = 2;
	}

	return valeur;
	
}
void afficheRecapitulatif(int compteurFacture, int montantFacture)
{
	cout << " \t\t\t CLUB MED" << endl
		<< "\t\t Recapitulatif de la journee" << endl << endl
		<< "Nombre de factures produites: " << compteurFacture << endl
		<< "Total des montants a payer: " << montantFacture << "$" << endl << endl;
}
