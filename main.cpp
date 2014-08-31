#include <iostream>
#include "wiadomosc.h"
#include "abc.h"

using namespace std;

string losowe_teksty[] = {"Losowy tekst 1", "Losowy tekst 2", "Losowy tekst 3", "Losowy tekst 4"};

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

void wypelnijlosowoskrzynke( skrzynka& sk, int liczba_wiadomosci )
{
    int nr_telefonu = 0;
    int nr_tekstu   = 0;
    for ( int i=0; i < liczba_wiadomosci; i++ )
    {
        nr_telefonu = rand() % 999999999 + 1;
        nr_tekstu = rand() % 4;
        sk.dodajWiadomosc(wiadomosc(nr_telefonu,losowe_teksty[nr_tekstu] ));
    }
}

//moja funkcja słuchająca, która wywoła się za każdym razem, gdy coś przyjdzie.
//sender to IP:port nadawcy, a message to kompletny odebrany tekst.
void my_listener(string sender, string message)
{
    cout << "From: " << sender << " \"" << message << "\"" << endl;
}

int main()
{
    int opcja = 0;
    skrzynka sk;

    net_init("192.168.207.255", 1234); //włącz sieć i skonfiguruj IP oraz numer portu
    net_start_receiver(my_listener); //włącz wątek sieciowy i przekaż mu wskaźnik funkcyjny
    srand (time(NULL));

    //wypelnijskrzynke(&sk);
    wypelnijlosowoskrzynke(sk,5);

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
                net_done();
                return 0;
            }
        }
    }

    net_done();
    return 0;
}
