#include <iostream>
#include <fstream>
#include <string>

using namespace std;


struct student {
    std::string imie;
    std::string nazwisko;
    int punkty;
};

void zamianaMiejsc(student *tab, int indeks1, int indeks2) {
    student wartoscTymczasowa = tab[indeks1];
    tab[indeks1] = tab[indeks2];
    tab[indeks2] = wartoscTymczasowa;
}

int sortujCzesc(student *tab, int odkad, int dokad, int tryb) {
    int punktPodzialu = tab[dokad].punkty;
    int i = (odkad - 1);

    for (int j = odkad; j <= dokad - 1; j++) {
        if (tryb == 0) {
            if (tab[j].punkty <= punktPodzialu) {
                i++;
                zamianaMiejsc(tab, i, j);
            }
        } else {
            if (tab[j].punkty >= punktPodzialu) {
                i++;
                zamianaMiejsc(tab, i, j);
            }
        }
    }
    zamianaMiejsc(tab, i + 1, dokad);
    return i + 1;
}

void quickSort(student *tab, int odkad, int dokad, int tryb) {
    if (odkad < dokad) {
        int punktPodzialu = sortujCzesc(tab, odkad, dokad, tryb);
        quickSort(tab, odkad, punktPodzialu - 1, tryb);
        quickSort(tab, punktPodzialu + 1, dokad, tryb);
    }
}

int wczytajIloscStudentow(const string &sciezka);

void sortowanieQuickSort(student *tab, int n, int tryb) {
    quickSort(tab, 0, n - 1, tryb);
}


void wczytajStudentow(student *&tab, int n, string studenci) {
    ifstream plik(studenci);
    if (!plik.is_open()) {
        cerr << "Nie udalo sie otworzyc pliku: " << studenci << endl;
        return;
    }
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

}

void usunTabliceStudentow(student *&tab) {
    delete tab;
}

void wyswietlStudentow(student *tab, int n) {
    for (int i = 0; i < n; i++) {
        cout << tab[i].imie << " " << tab[i].nazwisko << " " << tab[i].punkty << endl;
    }
}

int main() {

    int tryb;
    cout << "wybierz tryb sortowania: 1-malejaco, 0 - rosnaco\n";
    cin >> tryb;
    string sciezka = "C:\\Users\\annad\\CLionProjects\\untitled3\\studenci.csv";
    int n = wczytajIloscStudentow(sciezka);

    student *tab = new student[n];
    wczytajStudentow(tab, n, sciezka);
    wyswietlStudentow(tab, n);

    sortowanieQuickSort(tab, n, tryb);
    cout << "\n\n\nStudenci posortowani:\n\n\n";
    wyswietlStudentow(tab, n);

    usunTabliceStudentow(tab);

    return 0;
}

int wczytajIloscStudentow(const string &sciezka) {
    ifstream plik(sciezka);
    string linia;
    getline(plik, linia);
    size_t pozycja = linia.find(';');
    string rozmiarTablicy = linia.substr(0, pozycja);
    int n = stoi(rozmiarTablicy);
    return n;
}
