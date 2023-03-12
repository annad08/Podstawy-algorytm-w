#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct student {
    std::string imie;
    std::string nazwisko;
    int punkty;
};

int wczytajIloscStudentow(const string &sciezka) {
    ifstream plik(sciezka);
    string linia;
    getline(plik, linia);
    size_t pozycja = linia.find(';');
    string rozmiarTablicy = linia.substr(0, pozycja);
    int n = stoi(rozmiarTablicy);
    return n;
}

student *wczytajStudentow(string sciezkaDoPliku, int n) {

    student *tab = new student[n];
    ifstream plik(sciezkaDoPliku);

    string linia;
    getline(plik, linia);
    for (int i = 0; i < n; i++) {
        getline(plik, linia);
        size_t pozycja = linia.find(';');
        tab[i].imie = linia.substr(0, pozycja);
        linia = linia.substr(pozycja + 1);
        pozycja = linia.find(';');
        tab[i].nazwisko = linia.substr(0, pozycja);
        linia = linia.substr(pozycja + 1);
        tab[i].punkty = stoi(linia);
    }
    return tab;
}

void wyswietlStudentow(student *tab, int n) {
    for (int i = 0; i < n; i++) {
        cout << tab[i].imie << " " << tab[i].nazwisko << " " << tab[i].punkty << endl;
    }
}

void zad1() {
    cout << "uruchomiono zad 1 " << endl;
    string sciezka = "C:\\Users\\annad\\CLionProjects\\Podstawy-algorytm-w\\studenci.csv";
    int iloscStudentow = wczytajIloscStudentow(sciezka);
    student *studenci = wczytajStudentow(sciezka, iloscStudentow);
    wyswietlStudentow(studenci, iloscStudentow);
}

void zad2() {
    cout << "uruchomiono zad 2 " << endl;
    string sciezka = "C:\\Users\\annad\\CLionProjects\\Podstawy-algorytm-w\\studenci.csv";
    int iloscStudentow = wczytajIloscStudentow(sciezka);
    student *studenci = wczytajStudentow(sciezka, iloscStudentow);

    cout << "Zawartosc tablicy przed podzialem:" << endl;
    wyswietlStudentow(studenci, iloscStudentow);
    vector<student> mniejNiz10;
    vector<student> wiecejNiz10;
    for (int i = 0; i < iloscStudentow; i++) {
        if(studenci[i].punkty > 10){
            mniejNiz10.push_back(studenci[i]);
        }
    }

}

void zad3() {
    cout << "uruchomiono zad 1 " << endl;
}

void zad4() {
    cout << "uruchomiono zad 3 " << endl;
}

int main() {
    cout << "Wybierz zadanie do uruchomienia:" << endl;
    cout << "1. Zad 1." << endl;
    cout << "2. Zad 2." << endl;
    cout << "3. Zad 3." << endl;
    cout << "4. Zad 4." << endl;
    int zadanie = 0;
    cin >> zadanie;
    if (zadanie == 1) {
        zad1();
    } else if (zadanie == 2) {
        zad2();
    } else if (zadanie == 3) {
        zad3();
    } else if (zadanie == 4) {
        zad4();
    } else {
        cout << "Podano niepoprawny numer zadania: [" << zadanie << "]" << endl;
    }


    return 0;
}

