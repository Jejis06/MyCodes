#include <iostream>
using namespace std;

/*
		Super Progaram : 

  Użytkownik ma do wyboru 3 opcje:

	  1 - program włącza program DODAWANIE
	  2 - program włącza program MNOZENIE
	  3 - program się wyłącza 
*/


int main(){

	int wybor=0;
	
	//Powtarzaj zawsze
	while(true){
		//pobieramy od uzytkownika numer programu ktory chce wykonac
		cin >> wybor;

		//jezeli uzytkownik wybiera opcje 1 wykonujemy program DODAWANIE
		if(wybor == 1){
			cout << "WYBRANO DODAWANIE" << endl;
			int a,b;
			
			//pobieramy dwie liczby
			cin >> a;
			cin >> b;
			
			//wypisujemy sume liczb a i b pobranych od uzytkownika
			cout << "suma : " << a+b << endl;
		}

		//jezeli uzytkownik wybiera opcje 2 wykonujemy program MNOZENIE
		else if(wybor == 2){
			cout << "WYBRANO MNOZENIE" << endl;
			int a,b;
			
			//pobieramy dwie liczby
			cin >> a;
			cin >> b;
			
			//wypisujemy iloczyn liczb a i b pobranych od uzytkownika
			cout << "iloczyn : " << a*b << endl;
			
		}
		//jezeli uzytkownik wybiera opcje 3 konczymy program
		else if (wybor == 3){
			return 0;
		}
	}
}
