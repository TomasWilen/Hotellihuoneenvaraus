#include <iostream>
#include <list>
using namespace std;

class Hotelroom {
	
public:
	int tyyppi;
	float hinta;
	bool varattu;
	Hotelroom(int, float, bool);
	void setValues(int, float, bool);
};
Hotelroom::Hotelroom(int tyyppi1, float hinta1, bool varattu1) {
	tyyppi = tyyppi1;
	hinta = hinta1;
	varattu = varattu1;

}

class Hotel {												//Hotelli luokka joka pit�� sis�ll��n hotellihuoneet.
	std::list<Hotelroom> hotellihuoneet;

public:
	void SetHotelrooms() {										//Asetetaan hotellihuoneet hotelille.
		std::list<Hotelroom> dataset;
		int roomCount = 2 * rand() % 20 + 150;

		for (int i = 1; i <= roomCount; i++) {
			if (i <= roomCount / 2) {
				Hotelroom hotellihuone(1, 100, false);
				dataset.insert(dataset.begin(), hotellihuone);
			}
			else {
				Hotelroom hotellihuone(2, 150, false);
				dataset.insert(dataset.begin(), hotellihuone);

			}
		}
		hotellihuoneet = dataset;
	}
	bool ReserveRoom(int value) {								//Varataan hotellihuone.
		for (std::list<Hotelroom>::iterator i = hotellihuoneet.begin(); i != hotellihuoneet.end(); i++) {
			if (i->tyyppi == value && i->varattu == false) {
				i->varattu = true;
				return true;
			}
		}
		return false;
	}
	float PrintPrice(int value, int tyyppi) {			//Tulostetaan hinta �iden ja huoneen tyypin perusteella.
		float random1 = (float)(rand() % 2);
		float random = 1.0 - random1 * 0.1 ;
		if (tyyppi == 1) {
			return 100 * value * random;
		}
		return 150 * value * random;
	}
};

int main() {
	
	setlocale(LC_ALL, "fi-FI");
	
	int huone_numero;
	int �iden_m��r�;
	int toiminto{};
	string nimi;
	
	Hotel hotelli;
	hotelli.SetHotelrooms();
	while (toiminto != 2) {


		cout << "Valitse toiminto (1.Varaa huone, 2.Lopeta): "; //Kysyt��n k�ytt�j�lt� mit� haluaa tehd�.
		cin >> toiminto;

		if (toiminto == 1) {
			cout << "Anna nimesi: ";	//Kysyt��n k�ytt�j�n nime�.
			cin >> nimi;

			cout << "Sy�t� huoneen tyyppi(1 = yhden henkil�n huone, 2 = kahden hengen huone) : ";	//Kysyt��n huoneen tyyppi� jonka k�ytt�j� haluaa varata.
			cin >> huone_numero;

			cout << "Anna �iden m��r�: ";	//Kysyt��n k�ytt�j�lt� montako y�t� aikoo olla.
			cin >> �iden_m��r�;
			
			if (hotelli.ReserveRoom(huone_numero)) {
				cout << "Varauksen hinta on: " << hotelli.PrintPrice(�iden_m��r�, huone_numero);
			}
			else {
				cout << "Sopivaa huonetta ei l�ytynyt ";
			}
		
			cout << "Valitse toiminto (1.Varaa huone, 2.Lopeta): ";
			cin >> toiminto;

		}
		else (toiminto == 2); {
		cout << "Kiitos varauksesta! ";
		}
	}
}