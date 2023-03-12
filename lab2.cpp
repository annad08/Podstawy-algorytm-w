#include <iostream>

using namespace std;

void zamianaMiejsc(int *tab, int indeks1, int indeks2) {
    int wartoscTymczasowa = tab[indeks1];
    tab[indeks1] = tab[indeks2];
    tab[indeks2] = wartoscTymczasowa;
}

void sortowanieBabelkowe(int *tab, int n, int tryb) {
    if (tryb == 0) {
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n - 1 - j; i++) {
                if (tab[i] > tab[i + 1]) {
                    zamianaMiejsc(tab, i, i + 1);
                }
            }
        }
    } else {
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n - 1 - j; i++) {
                if (tab[i] < tab[i + 1]) {
                    zamianaMiejsc(tab, i, i + 1);
                }
            }
        }

    }
}

void sortowaniePrzezWybor(int *tab, int n, int tryb) {
    if (tryb == 0) {
        for (int j = 0; j < n; j++) {
            int wartoscNajmniejsza = tab[j];
            int indeksWartosciNajmniejszej = j;
            for (int i = j; i < n; i++) {
                if (tab[i] < wartoscNajmniejsza) {
                    wartoscNajmniejsza = tab[i];
                    indeksWartosciNajmniejszej = i;
                }

            }
            zamianaMiejsc(tab, j, indeksWartosciNajmniejszej);
        }
    } else {
        for (int j = n - 1; j >= 0; j--) {
            int wartoscNajmniejsza = tab[j];
            int indeksWartosciNajmniejszej = j;
            for (int i = j; i >= 0; i--) {
                if (tab[i] < wartoscNajmniejsza) {
                    wartoscNajmniejsza = tab[i];
                    indeksWartosciNajmniejszej = i;
                }

            }
            zamianaMiejsc(tab, j, indeksWartosciNajmniejszej);
        }
    }
}

void sortowaniePrzezWstawianie(int *tab, int n, int tryb) {
    if (tryb == 0) {
        for (int i = 1; i < n; i++) {
            int obecnaWartosc = tab[i];
            int j = i - 1;
            while (j >= 0 && tab[j] > obecnaWartosc) {
                tab[j + 1] = tab[j];
                j--;
            }
            tab[j + 1] = obecnaWartosc;
        }
    } else {
        for (int i = n - 2; i >= 0; i--) {
            int obecnaWartosc = tab[i];
            int j = i + 1;
            while (j < n && tab[j] > obecnaWartosc) {
                tab[j - 1] = tab[j];
                j++;
            }
            tab[j - 1] = obecnaWartosc;

        }
    }
}

void sortowanieBabelkowe2D(int **tab, int w, int k, int tryb, int nrKol) {

}

int main() {
    int rozmiar;
    int a;
    int b;
    cout << "Podaj rozmiar tablicy";
    cin >> rozmiar;
    cout << "Podaj najmniejsza liczba przedzialu";
    cin >> a;
    cout << "Podaj najwieksza liczba przedzialu";
    cin >> b;
    int *tab = new int[rozmiar];
    srand(time(NULL));
    for (int i = 0; i < rozmiar; i++) {
        tab[i] = rand() % (b - a + 1) + a;

    }
    for (int j = 0; j < rozmiar; j++) {
        cout << tab[j] << " ";
    }
    cout << endl;
    cout << "Sortowanie babelkowe, tryb:0" << endl;
    sortowanieBabelkowe(tab, rozmiar, 0);
    for (int j = 0; j < rozmiar; j++) {
        cout << tab[j] << " ";
    }
    cout << endl;
    cout << "Sortowanie babelkowe, tryb:1" << endl;

    sortowanieBabelkowe(tab, rozmiar, 1);
    for (int j = 0; j < rozmiar; j++) {
        cout << tab[j] << " ";
    }
    cout << endl;
    cout << "Sortowanie przez wybor, tryb:0" << endl;

    sortowaniePrzezWybor(tab, rozmiar, 0);
    for (int j = 0; j < rozmiar; j++) {
        cout << tab[j] << " ";
    }
    cout << endl;
    cout << "Sortowanie przez wybor, tryb:1" << endl;

    sortowaniePrzezWybor(tab, rozmiar, 1);
    for (int j = 0; j < rozmiar; j++) {
        cout << tab[j] << " ";

    }
    cout << endl;
    cout << "Sortowanie przez wstawianie, tryb:0" << endl;

    sortowaniePrzezWstawianie(tab, rozmiar, 0);
    for (int j = 0; j < rozmiar; j++) {
        cout << tab[j] << " ";
    }
    cout << endl;
    cout << "Sortowanie przez wstawianie, tryb:1" << endl;

    sortowaniePrzezWstawianie(tab, rozmiar, 1);
    for (int j = 0; j < rozmiar; j++) {
        cout << tab[j] << " ";
    }

    delete tab;


    return 0;
}