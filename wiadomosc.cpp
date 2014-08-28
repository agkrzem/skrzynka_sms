#include "wiadomosc.h"
#include <iostream>

void skrzynka::pokazWszystkie(bool czyNowa)
{
    for (unsigned int i = 0; i < skrzynka.size(); ++i )
    {
        if ( czyNowa == true && skrzynka[i].odczytana == true )
        {
            continue;
        }

        pokazJedna(i);
    }
}

void skrzynka::pokazJedna(int nr)
{
    if ( (unsigned int)nr < skrzynka.size() )
    {
        cout << "Wiadomosc: " << nr+1 << " od " << skrzynka[nr].nrTelefonu << endl;
        cout << skrzynka[nr].m_wiadomosc << endl;
        skrzynka[nr].odczytana = true;
    }
    else
    {
        cout << "Bledny numer wiadomosci" << endl;
    }
}

void skrzynka::usunJedna(int nr)
{
//    for (unsigned int i = nr; i < skrzynka.size(); ++i )
//    {
//        if ( i + 1 < skrzynka.size() )
//        {
//            skrzynka[i] = skrzynka[i+1];
//        }
//    }
//    skrzynka.pop_back();
    if ( (unsigned int)nr < skrzynka.size() && nr >= 0 )
    {
        vector<wiadomosc>::iterator it = skrzynka.begin();
        it += nr;
        skrzynka.erase(it);
    }
    else
    {
        cout << "Niepoprawny nr wiadokosci do usuniecia" << endl;
    }
}

void skrzynka::QSORT(int first, int last)
{
   static int i;
   int j;

   while (last - first > 1)
   {
      i = first;
      j = last;
      for (;;)
      {
         while (++i < last && skrzynka[i].nrTelefonu < skrzynka[first].nrTelefonu);
         while (--j > first && skrzynka[j].nrTelefonu > skrzynka[first].nrTelefonu);
         if (i >= j) break;
         zamien(i, j);
      }
      if (j == first)
      {
         ++first;
         continue;
      }
      zamien(first, j);
      if (j - first < last - (j + 1))
      {
         QSORT(first, j);
         first = j + 1;
      }
      else
      {
         QSORT(j + 1, last);
         last = j;
      }
   }
}

void skrzynka::zamien(int a, int b)
{
   wiadomosc tmp;
   tmp = skrzynka[a];
   skrzynka[a] = skrzynka[b];
   skrzynka[b] = tmp;
}

void skrzynka::sortuj()
{
    QSORT( 0, skrzynka.size() );
}

void skrzynka::usunWszystkie()
{
    skrzynka.clear();
}

void skrzynka::wyszukajTel(unsigned int telefon)
{
    for (unsigned int i = 0; i < skrzynka.size(); ++i )
    {
        if ( telefon == skrzynka[i].nrTelefonu )
        {
            pokazJedna(i);
        }
    }
}

void skrzynka::wyszukajText(string text)
{
    for (unsigned int i = 0; i < skrzynka.size(); ++i )
    {
        if ( skrzynka[i].m_wiadomosc.find(text) != string::npos )
        {
            pokazJedna(i);
        }
    }
}

void skrzynka::dodajWiadomosc( wiadomosc nowa )
{
    if ( skrzynka.size() < 10 )
    {
        skrzynka.push_back( nowa );
    }
}
