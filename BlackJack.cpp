#include "stdafx.h"
#include <string>
#include <windows.h>		//Sleep
#include <iostream>
#include <vector>
#include <random>



using namespace std;

class Card {
public:
	int color;
	int figure;
	int deck;
	Card() {

	}
	void Fill(int dec, int col, int fig) {
		deck = dec;
		color = col;
		figure = fig;


	}
};


class Player {
public:
	vector <Card> Talia;
	int points = 0;

	void Sortuj1() {
		for (int i = 0; i < Talia.size() - 1; i++) {
			if (Talia.at(i).deck > Talia.at(i + 1).deck) {
				Card a = Talia.at(i + 1);
				Talia.at(i + 1) = Talia.at(i);
				Talia.at(i) = a;

			}

		}
	}

	void Sortuj2() {
		for (int i = 0; i < Talia.size() - 1; i++) {
			if ((Talia.at(i).figure > Talia.at(i + 1).figure) && (Talia.at(i).deck == Talia.at(i + 1).deck)) {
				Card a = Talia.at(i + 1);
				Talia.at(i + 1) = Talia.at(i);
				Talia.at(i) = a;

			}

		}
	}

	void Sortuj3() {
		for (int i = 0; i < Talia.size() - 1; i++) {
			if ((Talia.at(i).color > Talia.at(i + 1).color) && (Talia.at(i).figure == Talia.at(i + 1).figure) && (Talia.at(i).deck == Talia.at(i + 1).deck)) {
				Card a = Talia.at(i + 1);
				Talia.at(i + 1) = Talia.at(i);
				Talia.at(i) = a;

			}

		}
	}



	void ShowCards() {
		Sortuj1();
		Sortuj2();
		Sortuj3();
		string kolor;
		string f;
		for (int i = 0; i < Talia.size(); i++) {
			switch (Talia.at(i).figure)
			{
			case 1: f = 'A'; break;
			case 2: f = '2'; break;
			case 3: f = '3'; break;
			case 4: f = '4'; break;
			case 5: f = '5'; break;
			case 6: f = '6'; break;
			case 7: f = '7'; break;
			case 8: f = '8'; break;
			case 9: f = '9'; break;
			case 10: f = "10"; break;
			case 11: f = 'J'; break;
			case 12: f = 'Q'; break;
			case 13: f = 'K'; break;
			default:
				break;
			}
			switch (Talia.at(i).color)
			{
			case 1: kolor = "Kier"; break;
			case 2: kolor = "Pik"; break;
			case 3: kolor = "Karo"; break;
			case 4: kolor = "Trefl"; break;
			default:
				kolor = "cos nie tak"; break;
			}
			cout << Talia.at(i).deck << " " << f << " " << kolor << endl;

		}
	}


	bool Decision() {
		char decision;
		Points();
		cout << endl << "Masz " << points << "punktow" << endl;
		cout << "Dobierasz?" << endl;
		cout << "T/n" << endl;
		cin >> decision;
		if (decision == 'y' || decision == 'Y') {
			return true;
		}
		if (decision == 'n' || decision == 'N') {
			return false;
		}

	}


	/*int Points() {
	points = 0;
	int mypoints;
	if ((((Talia.at(0).figure >= 11 && Talia.at(0).figure <= 13) || Talia.at(0).figure == 1) && Talia.at(1).figure == 1) || (((Talia.at(1).figure >= 11 && Talia.at(1).figure <= 13) || Talia.at(1).figure == 1) && Talia.at(1).figure == 1)) points = 21; //blackjack
	else
	{
	for (int i = 0; i<Talia.size(); i++) {
	if (Talia.at(i).figure >= 2 && Talia.at(i).figure <= 9) { points += Talia.at(i).figure; } //2-9
	else if (Talia.at(i).figure >= 10 && Talia.at(i).figure <= 13) { points += 10; } //10 + K,Q,J
	else if (Talia.at(i).figure == 1) { if (points + 10>21) { points += 1; } else { points += 10; } }
	}
	}
	mypoints = points;
	return mypoints;

	}*/

	int Points() {
		int mypoints = 0;
		for (int i = 0; i<Talia.size(); i++) {
			switch (Talia.at(i).figure)
			{
			case 2: mypoints += 2; break;
			case 3: mypoints += 3; break;
			case 4: mypoints += 4; break;
			case 5: mypoints += 5; break;
			case 6: mypoints += 6; break;
			case 7: mypoints += 7; break;
			case 8: mypoints += 8; break;
			case 9: mypoints += 9; break;
			case 10: mypoints += 10; break;
			case 11: mypoints += 10; break;
			case 12: mypoints += 10; break;
			case 13: mypoints += 10; break;
			default:
				break;
			}
		}
		for (int i = 0; i < Talia.size(); i++) {
			if (Talia.at(i).figure == 1) {
				if (mypoints == 11 and Talia.size() == 2) {
					mypoints = 21;
				}
				else if (mypoints < 11) {
					mypoints += 11;
				}
				else if (mypoints > 10) {
					mypoints += 1;
				}

			}

		}
		points = mypoints;
		return mypoints;
	}




};


class Croupier {
public:
	vector<Card> Talia;
	int points;

	Croupier() {
		points = 0;
	}


	void Sortuj1() {
		for (int i = 0; i < Talia.size() - 1; i++) {
			if (Talia.at(i).deck > Talia.at(i + 1).deck) {
				Card a = Talia.at(i + 1);
				Talia.at(i + 1) = Talia.at(i);
				Talia.at(i) = a;

			}

		}
	}

	void Sortuj2() {
		for (int i = 0; i < Talia.size() - 1; i++) {
			if ((Talia.at(i).figure > Talia.at(i + 1).figure) && (Talia.at(i).deck == Talia.at(i + 1).deck)) {
				Card a = Talia.at(i + 1);
				Talia.at(i + 1) = Talia.at(i);
				Talia.at(i) = a;

			}

		}
	}

	void Sortuj3() {
		for (int i = 0; i < Talia.size() - 1; i++) {
			if ((Talia.at(i).color > Talia.at(i + 1).color) && (Talia.at(i).figure == Talia.at(i + 1).figure) && (Talia.at(i).deck == Talia.at(i + 1).deck)) {
				Card a = Talia.at(i + 1);
				Talia.at(i + 1) = Talia.at(i);
				Talia.at(i) = a;

			}

		}
	}

	int Points() {
		int mypoints = 0;
		for (int i = 0; i<Talia.size(); i++) {
			switch (Talia.at(i).figure)
			{
			case 2: mypoints += 2; break;
			case 3: mypoints += 3; break;
			case 4: mypoints += 4; break;
			case 5: mypoints += 5; break;
			case 6: mypoints += 6; break;
			case 7: mypoints += 7; break;
			case 8: mypoints += 8; break;
			case 9: mypoints += 9; break;
			case 10: mypoints += 10; break;
			case 11: mypoints += 10; break;
			case 12: mypoints += 10; break;
			case 13: mypoints += 10; break;
			default:
				break;
			}
		}
		for (int i = 0; i < Talia.size(); i++) {
			if (Talia.at(i).figure == 1) {
				if (mypoints == 11 and Talia.size() == 2) {
					mypoints = 21;
				}
				else if (mypoints < 11) {
					mypoints += 11;
				}
				else if (mypoints > 10) {
					mypoints += 1;
				}

			}

		}
		points = mypoints;
		return mypoints;
	}

	void ShowCards(int a) {
		Sortuj1();
		Sortuj2();
		Sortuj3();
		string kolor;
		string f;
		if (a == 1) {

			switch (Talia.at(0).figure)
			{
			case 1: f = 'A'; break;
			case 2: f = '2'; break;
			case 3: f = '3'; break;
			case 4: f = '4'; break;
			case 5: f = '5'; break;
			case 6: f = '6'; break;
			case 7: f = '7'; break;
			case 8: f = '8'; break;
			case 9: f = '9'; break;
			case 10: f = "10"; break;
			case 11: f = 'J'; break;
			case 12: f = 'Q'; break;
			case 13: f = 'K'; break;
			default:
				break;
			}

			switch (Talia.at(0).color)
			{
			case 1: kolor = "Kier"; break;
			case 2: kolor = "Pik"; break;
			case 3: kolor = "Karo"; break;
			case 4: kolor = "Trefl"; break;
			default:
				kolor = "cos nie tak"; break;
			}
			cout << Talia.at(0).deck << " " << f << " " << kolor << endl;
			cout << "##########" << endl;

		}
		else {


			for (int i = 0; i < Talia.size(); i++) {
				switch (Talia.at(i).figure)
				{
				case 1: f = 'A'; break;
				case 2: f = '2'; break;
				case 3: f = '3'; break;
				case 4: f = '4'; break;
				case 5: f = '5'; break;
				case 6: f = '6'; break;
				case 7: f = '7'; break;
				case 8: f = '8'; break;
				case 9: f = '9'; break;
				case 10: f = "10"; break;
				case 11: f = 'J'; break;
				case 12: f = 'Q'; break;
				case 13: f = 'K'; break;
				default:
					break;
				}
				switch (Talia.at(i).color)
				{
				case 1: kolor = "Kier"; break;
				case 2: kolor = "Pik"; break;
				case 3: kolor = "Karo"; break;
				case 4: kolor = "Trefl"; break;
				default:
					kolor = "cos nie tak"; break;
				}
				cout << Talia.at(i).deck << " " << f << " " << kolor << endl;


			}
		}
	}







};



class Game {
public:

	vector <Card> MyDeck;
	Player gracz;
	Croupier krupier;

public:

	void CreateDeck(int a) {
		MyDeck.clear();
		for (int t = 0; t < a; t++) {
			for (int c = 1; c < 5; c++) {
				for (int f = 1; f < 14; f++) {
					Card karta;
					karta.Fill(t, c, f);
					MyDeck.push_back(karta);
					//   cout<<karta.color<<" "<<karta.figure<<endl;
				}
			}
		}
	}


	void Tasuj() {


	}

	void Distribution() {
		random_device rd;
		mt19937 gen(rd());
		krupier.Talia.clear();
		gracz.Talia.clear();
		for (int it = 0; it<2; it++) {
			int cards = ((int)MyDeck.size()) - 1;
			uniform_int_distribution<> dis(0, cards);
			int a = dis(gen);
			Card karta;
			karta = MyDeck.at(a);
			MyDeck.erase(MyDeck.begin() + a);
			gracz.Talia.push_back(karta);
		}



		for (int it = 0; it<2; it++) {
			int cards = ((int)MyDeck.size()) - 1;
			uniform_int_distribution<> dis(0, cards);
			int a = dis(gen);
			Card karta;
			karta = MyDeck.at(a);
			MyDeck.erase(MyDeck.begin() + a);
			krupier.Talia.push_back(karta);
		}
	}


	void showDeck() {
		for (int i = 0; i<MyDeck.size(); i++) {
			string kolor;
			string f;
			switch (MyDeck.at(i).figure)
			{
			case 1: f = 'A'; break;
			case 2: f = '2'; break;
			case 3: f = '3'; break;
			case 4: f = '4'; break;
			case 5: f = '5'; break;
			case 6: f = '6'; break;
			case 7: f = '7'; break;
			case 8: f = '8'; break;
			case 9: f = '9'; break;
			case 10: f = '10'; break;
			case 11: f = 'J'; break;
			case 12: f = 'Q'; break;
			case 13: f = 'K'; break;
			default:
				break;
			}

			switch (MyDeck.at(i).color)
			{
			case 1: kolor = "Kier"; break;
			case 2: kolor = "Pik"; break;
			case 3: kolor = "Karo"; break;
			case 4: kolor = "Trefl"; break;
			default:
				kolor = "cos nie tak"; break;
			}
			cout << MyDeck.at(i).deck << " " << f << " " << kolor << endl;
		}
	}

	void GiveCardC() {
		random_device rd;
		mt19937 gen(rd());
		int cards = ((int)MyDeck.size()) - 1;
		uniform_int_distribution<> dis(0, cards - 1);
		int a = dis(gen);


		Card karta;
		karta = MyDeck.at(a);
		MyDeck.erase(MyDeck.begin() + a);
		krupier.Talia.push_back(karta);
		krupier.Points();
	}

	void GiveCardP() {
		random_device rd;
		mt19937 gen(rd());
		int cards = ((int)MyDeck.size()) - 1;
		uniform_int_distribution<> dis(0, cards);
		int a = dis(gen);


		Card karta;
		karta = MyDeck.at(a);
		MyDeck.erase(MyDeck.begin() + a);
		gracz.Talia.push_back(karta);
		gracz.Points();
	}


	void Title() {
		system("cls");
		cout << "$$$$$$$$$$$ BLACKJACK $$$$$$$$$$$" << endl << endl;
	}

	void Tasowanie() {
		cout << "Tasowanie";
		for (int i = 0; i < 4; i++) {
			cout << " . ";
			Sleep(300);
		}
		Title();
	}


	void Show() {
		int iloscTalii = 2;
		int flag = 0;
		int flag2 = 0;
		int loseflag = 0;
		int win = 0;
		Title();
		Tasowanie();

		CreateDeck(iloscTalii);
		Distribution();
		krupier.Points();
		Title();

		cout << "Twoje karty" << endl;
		gracz.ShowCards();

		if (gracz.points == 21) {
			//cout << "Wygrales!\n\n";


		}
		else
			if (gracz.points > 21) {
				loseflag = 1;
			}
		cout << endl << endl;
		cout << "Karty krupiera" << endl;
		krupier.ShowCards(1);

		int ilosc = 0;
		while (1 && ilosc < 6) {
			bool a = gracz.Decision();
			if (a) {
				ilosc++;
				GiveCardP();
				Title();

				cout << "Twoje karty" << endl;
				gracz.ShowCards();
				if (gracz.points == 21) { win = 1; break; }

				if (gracz.points > 21) {
					loseflag = 1;
					break;
				}
				cout << endl << endl;
				cout << "Karty krupiera" << endl;
				krupier.ShowCards(1);
				flag2 = 1;
			}
			else { flag = 1; break; }
		}


		if (win != 1) {

			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> dis(0, 3);
			int bb = dis(gen);

			while (krupier.points < 17 || bb % 4 == 0) {
				GiveCardC();
				krupier.Points();
			}

			Title();
			cout << "Twoje punkty " << gracz.points << endl;
			cout << "Twoje karty" << endl << endl;
			gracz.ShowCards();
			cout << endl << endl;

			cout << "Punkty krupiera " << krupier.points << endl;
			cout << "Karty krupiera" << endl << endl;
			krupier.ShowCards(0);
			gracz.Points();
			krupier.Points();

			int player = 21 - gracz.points;
			int croupier = 21 - krupier.points;
			cout << endl << endl;
			if ((player == 0 && croupier == 0) || player == croupier) {
				cout << "Remis!" << endl;
			}

			if ((player < 0 && croupier > 0) || (player != 0 && croupier == 0) || loseflag == 1) {
				cout << "Przegrales!" << endl;
			}

			if ((player == 0 && croupier != 0) || (player < croupier && player >= 0) || (player >= 0 && croupier < 0)) {
				cout << "Wygrales!" << endl;

			}
		}
		system("pause");





	}


	Game() {
		MyDeck.clear();
		Show();
	}

};



int main() {
	while (1) {
		Game *game = new Game();
		delete game;
		system("cls");
	}
	return 0;
}
