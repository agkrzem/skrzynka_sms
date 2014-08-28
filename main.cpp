#include <iostream>
#include "wiadomosc.h"

using namespace std;

void wypelnijskrzynke( skrzynka& sk )
{
    sk.dodajWiadomosc(wiadomosc(123321123, "Pierwsza wiadomosc"));
    sk.dodajWiadomosc(wiadomosc(987654321, "Druga wiadomosc"));
    sk.dodajWiadomosc(wiadomosc(348576077, "trzecia wiadomosc"));
    sk.dodajWiadomosc(wiadomosc(576893002, "czwarta wiadomosc"));
    sk.dodajWiadomosc(wiadomosc(625145566, "piąta wiadomosc"));
    sk.dodajWiadomosc(wiadomosc(552147899, "szósta wiadomosc"));
    sk.dodajWiadomosc(wiadomosc(522154866, "siódma wiadomosc"));
    sk.dodajWiadomosc(wiadomosc(145563254, "ósma wiadomosc"));
}

int main()
{
    int opcja = 0;
    skrzynka sk;

    wypelnijskrzynke(sk);

    while(1)
    {
        cout << "Wybierz opcje:" << endl;
        cout << "1: Wyświetlenie wszystkich wiadomości pozostawionych w skrzynce" << endl;
        cout << "2. Wyświetlenie jednej, wybranej wiadomości." << endl;
        cout << "3. Wyświetlenie nowych, nieodczytanych wiadomości." << endl;
        cout << "4. Usunięcie dowolnej z wiadomości." << endl;
        cout << "5. Usunięcie wszystkich wiadomości." << endl;
        cout << "6. Wyszukanie wiadomości po numerze telefonu." << endl;
        cout << "7. Wyszukanie wiadomości po podaniu fragmentu poszukiwanego tekstu." << endl;
        cout << "8. Sortuj po numerze telefonu." << endl;
        cout << "0. Wyjscie." << endl;

        cin >> opcja;

        switch (opcja)
        {
            case 1:
            {
                sk.pokazWszystkie(false);
                break;
            }
            case 2:
            {
                int nr;
                cout << "Podaj nr wiadomosci" << endl;
                cin >> nr;
                sk.pokazJedna(nr-1);
                break;
            }
            case 3:
            {
                sk.pokazWszystkie(true);
                break;
            }
            case 4:
            {
                int nr;
                cout << "Podaj nr wiadomosci" << endl;
                cin >> nr;
                sk.usunJedna(nr-1);
                break;
            }
            case 5:
            {
                sk.usunWszystkie();
                break;
            }
            case 6:
            {
                unsigned int nr;
                cout << "Podaj nr telefonu" << endl;
                cin >> nr;
                sk.wyszukajTel(nr);
                break;
            }
            case 7:
            {
                string text;
                cout << "Podaj tekst" << endl;
                cin >> text;
                sk.wyszukajText(text);
                break;
            }
            case 8:
            {
                sk.sortuj();
                break;
            }
            default:
            {
                return 0;
            }
        }
    }

    return 0;
}
