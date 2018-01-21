#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstdlib>
using namespace std;

struct Uzytkownik
{
  int id;

  string imie, nazwisko, numerTel, adresZam,email;

};
    int dodaj (Uzytkownik uzytkownicy[], int iloscOsob)
    {
        //int id;
        string imie,nazwisko,numerTel,adresZam,email ;
        cin.sync();
        cin.clear();
        cout<< "Podaj imie: ";
        cin>>imie;
        cout<< "Podaj nazwisko: ";
        cin>>nazwisko;
        cout<<"Podaj numer telefonu: ";
        cin.sync();
        getline(cin,numerTel);
        cout<< "Podaj adres zamieszkania: ";
        cin.sync();
        getline(cin,adresZam);
        cout<< "Podaj adres email: ";
        cin>>email;


        int idOsoba= iloscOsob+1;
        uzytkownicy[iloscOsob].id=idOsoba;
        uzytkownicy[iloscOsob].imie=imie;
        uzytkownicy[iloscOsob].nazwisko=nazwisko;
        uzytkownicy[iloscOsob].numerTel=numerTel;
        uzytkownicy[iloscOsob].adresZam=adresZam;
        uzytkownicy[iloscOsob].email=email;

        fstream plik;
        plik.open("ksiazka_adresowa.txt", ios::out | ios::app);

        if(plik.good())
        {
            plik<<idOsoba<<endl;
            plik<<imie<<endl;
            plik<<nazwisko<<endl;
            plik<<numerTel<<endl;
            plik<<adresZam<<endl;
            plik<<email<<endl;

            plik.close();
            cout<< "Osoba zostala dodana"<<endl;
            Sleep(1000);
        }
        else
        {
            cout<< "Nie mozna otworzyc pliku";
        }
        iloscOsob++;
        return iloscOsob;

    }

    int wczytaj (Uzytkownik uzytkownicy[], int iloscOsob)
    {
        system("cls");
        for (int i=0; i<iloscOsob; i++)
        {
        cout<<uzytkownicy[i].id<<endl;
        cout<<uzytkownicy[i].imie<<endl;
        cout<<uzytkownicy[i].nazwisko<<endl;
        cout<<uzytkownicy[i].numerTel<<endl;
        cout<<uzytkownicy[i].adresZam<<endl;
        cout<<uzytkownicy[i].email<<endl<<endl;
        }
        cout<< "Koniec listy twoich znajomych. Nacisnij enter"<<endl;
        cin.sync();
        getchar();

    }
    int wyszukajPoImieniu (Uzytkownik uzytkownicy[], int iloscOsob, int idOsoba)
     {
        string imieSzukanejosoby;
        int iloscOsobZtymSamymImieniem=0;


      system("cls");
       cout << "Podaj imie: ";

       cin>> imieSzukanejosoby;


        for (int i=0; i<iloscOsob; i++)
        {
           if (uzytkownicy[i].imie==imieSzukanejosoby)
           {
            cout<<uzytkownicy[i].id<<endl;
            cout<<uzytkownicy[i].imie<<endl;
            cout<<uzytkownicy[i].nazwisko<<endl;
            cout<<uzytkownicy[i].numerTel<<endl;
            cout<<uzytkownicy[i].adresZam<<endl;
            cout<<uzytkownicy[i].email<<endl;
            iloscOsobZtymSamymImieniem++;
           }

        }
        if (iloscOsobZtymSamymImieniem==0){cout<<"Nie ma takiego uzytkownika";}
        else {cout<<"ilosc osbo o imieniu "<<imieSzukanejosoby<< " jest w ksiazce "<<iloscOsobZtymSamymImieniem;}
        cin.sync();
        getchar();
     }
void wyszukajPoNazwisku (Uzytkownik uzytkownicy[], int iloscOsob)
     {
        string nazwiskoSzukanejOsoby;
        int iloscOsobZtymSamymNazwiskiem=0;

        system("cls");
        cout << "Podaj nazwisko: ";
        cin>> nazwiskoSzukanejOsoby;

        for (int i=0; i<iloscOsob; i++)
        {
           if (uzytkownicy[i].nazwisko==nazwiskoSzukanejOsoby)
           {
            cout<<uzytkownicy[i].id<<endl;
            cout<<uzytkownicy[i].imie<<endl;
            cout<<uzytkownicy[i].nazwisko<<endl;
            cout<<uzytkownicy[i].numerTel<<endl;
            cout<<uzytkownicy[i].adresZam<<endl;
            cout<<uzytkownicy[i].email<<endl;
            iloscOsobZtymSamymNazwiskiem++;
            }
        }
        if (iloscOsobZtymSamymNazwiskiem==0) {cout<< "Nie ma takiego uzytkownika";}
        else
            {cout<< "Osob o nazwisku "<<nazwiskoSzukanejOsoby<<" jest "<<iloscOsobZtymSamymNazwiskiem<<endl;}
        cout<< "Kliknij enter, aby wrocic do menu glownego";
        cin.sync();
        getchar();
     }
int wczytaj_uzytkownikow (Uzytkownik uzytkownicy[])
    {
        fstream plik;

        int iloscOsob=0;

        plik.open("ksiazka_adresowa.txt", ios::in);
        if (plik.good()==false)
        {
                cout<<"Plik nie istnieje";
                exit(0);
        }
        string linia;
        int nr_linii=1;

        while (getline(plik,linia))
        {
            switch (nr_linii)
            {
                case 1: uzytkownicy[iloscOsob].id=              atoi(linia.c_str());break;
                case 2: uzytkownicy[iloscOsob].imie=            linia;break;
                case 3: uzytkownicy[iloscOsob].nazwisko=        linia;break;
                case 4: uzytkownicy[iloscOsob].numerTel=        linia;break;
                case 5: uzytkownicy[iloscOsob].adresZam=        linia;break;
                case 6: uzytkownicy[iloscOsob].email=           linia;break;
            }
            if (nr_linii==6){nr_linii=0; iloscOsob++;}
            nr_linii++;

        }
        plik.close();
        return iloscOsob;
    }

int main()
{
    Uzytkownik uzytkownicy [100];

    int iloscOsob=0;
    int idOsoba=0;
    char wybor;

    iloscOsob=wczytaj_uzytkownikow(uzytkownicy);


    while (1)
    {
    system ("cls");
    cout <<"---|||Menu Ksiazki Adresowej|||---" << endl<< endl;
    cout <<"1. Dodaj uzytkownika do Ksiazki Adresowej."<<endl;
    cout <<"2. Znajdz uzytkownika po imieniu w Ksiazce Adresowej."<<endl;
    cout <<"3. Znajdz uzytkownika po nazwisku w Ksiazce Adresowej."<<endl;
    cout <<"4. Wczytaj wszystkich uzytkownikow z Ksiazki Adresowej."<<endl;
    cout <<"9. Zakoncz program"<<endl;

    cin>> wybor;

    wybor=tolower(wybor);

        if (wybor=='1')
        {
           iloscOsob=dodaj(uzytkownicy,iloscOsob);


        }
        else if (wybor=='2')
        {
             idOsoba=wyszukajPoImieniu(uzytkownicy,iloscOsob,idOsoba);
        }

        else if (wybor=='3')
        {
             wyszukajPoNazwisku(uzytkownicy,iloscOsob);
        }
        else if (wybor=='4')
        {
           wczytaj(uzytkownicy, iloscOsob);
        }
        else if (wybor=='9')
        {


            exit(0);
        }
    }


    return 0;
}
