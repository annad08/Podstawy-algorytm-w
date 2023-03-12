#include <iostream>

using namespace std;

void przydzielPamiec1D(int *&tab, int n) {
    tab = new int[n];
}

void przydzielPamiec2D(int **&tab, int w, int k) {
    tab = new int *[w];
    for (int i = 0; i < w; i++) {
        tab[i] = new int[k];
    }
}

void wypelnijTablice1D(int *tab, int n, int a, int b) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        tab[i] = rand() % (b - a + 1) + a;
    }
}

void wypelnijTablice2D(int **tab, int w, int k, int a, int b) {
    srand(time(NULL));
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < k; j++) {
            tab[i][j] = rand() % (b - a + 1) + a;
        }
    }
}

void usunTablice1D(int *&tab) {
    delete[]tab;
}

void usunTablice2D(int **&tab, int w) {
    for (int i = 0; i < w; i++) {
        delete[]tab[i];
    }
    delete[]tab;
}

void wyswietl1D(int *tab, int n) {
    for (int i = 0; i < n; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;
}

void wyswietl2D(int **tab, int w, int k) {
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < k; j++) {
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}

void zad1_2() {
    int rozmiar;
    int a;
    int b;
    cout << "Podaj rozmiar tablicy" << endl;
    cin >> rozmiar;
    cout << "Podaj mniejsza liczbe przedzialu" << endl;
    cin >> a;
    cout << "Podaj wieksza liczbe przedzialu" << endl;
    cin >> b;
    int *tab;
    przydzielPamiec1D(tab, rozmiar);
    wypelnijTablice1D(tab, rozmiar, a, b);
    wyswietl1D(tab, rozmiar);
    int min = tab[0];
    for (int i = 0; i < rozmiar; i++) {
        if (tab[i] < min) {
            min = tab[i];
        }
    }
    cout << "Minimalny element to: " << min << endl;
    bool jestPierwsza = true;
    for (int j = 2; j < min; j++) {
        if (min % j == 0) {
            jestPierwsza = false;
            break;
        }
    }
    if (jestPierwsza) {
        cout << min << " jest liczba pierwsza";
    } else {
        cout << min << " nie jest liczba pierwsza";
    }

}

int main() {
    zad1_2();
}