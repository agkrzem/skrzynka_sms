#ifndef WIADOMOSC_H_INCLUDED
#define WIADOMOSC_H_INCLUDED

#include <vector>
#include <string>

using namespace std;

struct wiadomosc
{
    unsigned int nrTelefonu;
    string m_wiadomosc;
    bool odczytana;

    wiadomosc()
    {

    }

    wiadomosc( unsigned int telefon, string wiadomosc )
    {
        nrTelefonu = telefon;
        m_wiadomosc = wiadomosc;
        odczytana = false;
    }
};

struct skrzynka
{
    vector<wiadomosc> skrzynka;

    void pokazWszystkie(bool czyNowa );
    void pokazJedna(int nr);
    void usunJedna(int nr);
    void usunWszystkie();
    void wyszukajTel(unsigned int telefon);
    void wyszukajText(string text);
    void dodajWiadomosc( wiadomosc nowa );
    void QSORT(int first, int last);
    void sortuj();
    void zamien(int a, int b);
};


#endif // WIADOMOSC_H_INCLUDED
