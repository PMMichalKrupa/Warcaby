
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <cstdlib>
using namespace std;

int PION;
int POZIOM;
int poziom_przesuniecie;
int pion_przesuniecie;
int licznik_pionkow_bialych = 0;
int licznik_pionkow_czarnych = 0;
int bicieLG, biciePG, bicieLD, biciePD;


void start_mapy(int plansza[30][30], int a, int b)
{
    if (a % 2 == 0)
    {
        for (int i = 0; i < (a / 2) - 1; i++)
        {
            for (int j = 0; j < b; j++)
            {
                if ((i + j) % 2 == 1)
                {
                    plansza[i][j] = 2;
                }
                else
                {
                    plansza[i][j] = 0;
                }
            }
        }
        for (int i = (a/2)-1 ; i < (a / 2)+1; i++)
        {
            for (int j = 0; j < b; j++)
            {
                if ((i + j) % 2 == 1)
                {
                    plansza[i][j] = 1;
                }
                else
                {
                    plansza[i][j] = 0;
                }
            }
        }
        for (int i = (a / 2) + 1; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                if ((i + j) % 2 == 1)
                {
                    plansza[i][j] = 3;
                }
                else
                {
                    plansza[i][j] = 0;
                }
            }
        }

    }
    else
    {
        for (int i = 0; i < ((a-3) / 2); i++)
        {
            for (int j = 0; j < b; j++)
            {
                if ((i + j) % 2 == 1)
                {
                    plansza[i][j] = 2;
                }
                else
                {
                    plansza[i][j] = 0;
                }
            }
        }
        for (int i = ((a-3) / 2); i < ((a+3) / 2); i++)
        {
            for (int j = 0; j < b; j++)
            {
                if ((i + j) % 2 == 1)
                {
                    plansza[i][j] = 1;
                }
                else
                {
                    plansza[i][j] = 0;
                }
            }
        }
        for (int i = ((a+3) / 2); i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                if ((i + j) % 2 == 1)
                {
                    plansza[i][j] = 3;
                }
                else
                {
                    plansza[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (plansza[i][j] == 2)
            {
                licznik_pionkow_bialych++;
                licznik_pionkow_czarnych = licznik_pionkow_bialych;
            }
        }
    }
}

void kolejne_rysowania(int plansza[30][30], int a, int b)
{
    for (int i = 0; i < a; i++)
    {
        cout << "  ";
        for (int h = 0; h < 4 * b + 1; h++)
        {
            cout << "-";
        }
        cout << endl;
        if (i < 10)
        {
            cout << i << " |";
        }
        else
        {
            cout << i << "|";
        }
        for (int j = 0; j < b; j++)
        {
            if (plansza[i][j] == 0)
            {
                cout << "///";
            }
            if (plansza[i][j] == 1)
            {
                cout << "   ";
            }
            if (plansza[i][j] == 2)
            {
                cout << ".b.";
            }
            if (plansza[i][j] == 3)
            {
                cout << ".c.";
            }
            if (plansza[i][j] == 4)
            {
                cout << "{C}";
            }
            if (plansza[i][j] == 5)
            {
                cout << "{B}";
            }
            cout << "|";
        }
        cout << endl;
    }
    cout << "  ";
    for (int h = 0; h < 4 * b + 1; h++)
    {
        cout << "-";
    }
    cout << endl << "    ";
    for (int i = 0; i < b; i++)
    {
        if (i < 10)
            cout << i << "   ";
        else
            cout << i << "  ";
    }
    cout << endl;
}
void zapis(int a, int b, int tm, int plansza[30][30])
{
    ofstream saveFile("Warcaby_zapis.txt");
    saveFile << a << " " << b << " " << tm << endl;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            saveFile << plansza[i][j] << " ";
        }
        saveFile << endl;
    }
    saveFile.close();
}
void kordy_pionka()
{
    cout << "Podaj kolumne pionka: ";
    cin >> PION;
    cout << "Podaj wiersz pionka: ";
    cin >> POZIOM;
    cout << "Podaj kolumne miejsca docelowego pionka: ";
    cin >> poziom_przesuniecie;
    cout << "Podaj wiersz miejsca docelowegp pionka: ";
    cin >> pion_przesuniecie;
}

int main()
{
	menu:
    int plansza[30][30], a = 0, b = 0;
    int dlugosc_gry = 0;
    bool wygrana = false;
    int kolor=0;
    int blad = 0;
    int zwc = 0;
    int tm;

    
    while ((zwc != 1) && (zwc != 2) && (zwc != 3))
    {
        cout << "1 - Nowa Gra" << endl << "2 - Wczytaj" << endl << "3 - Jak grac" << endl;
        cin >> zwc;
    }
    if (zwc == 1)
    {
        while (a < 4 || a > 30)
        {
            cout << "Podaj dlugosc planszy: (4-30): ";
            cin >> a;
        }
        while (b < 4 || b > 30)
        {
            cout << "Podaj szerokosc planszy (4-30): ";
            cin >> b;
        }
        tm = 1;
        system("cls");
        start_mapy(plansza, a, b);
    }
    else if (zwc == 2)
    {
        ifstream readFile("Warcaby_zapis.txt");
        readFile >> a >> b >> tm;
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                readFile >> plansza[i][j];
            }
        }
        readFile.close();
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                if (plansza[i][j] == 2)
                {
                    licznik_pionkow_bialych++;
                    licznik_pionkow_czarnych = licznik_pionkow_bialych;
                }
            }
        }
        system("cls");
    }
	else if (zwc == 3)
	{
		system("cls");
		cout << "W celu wykonania ruchu pionka wpisz w kolejnosci: " << endl << " - Kolumne wybranego pionka (Podane na dole planszy)" << endl << " - Wiersz wybranego pionka (Podany po lewej stronie planszy)" << endl << " - Kolumne pozycji, gdzie ma sie ruszyc" << endl << " - Wiersz pozycji, gdzie ma sie ruszyc" << endl;
		cout << endl << "Aby zbic pionek przeciwnika, podaj kolumne i wiersz zbijanego pionka w miejscu gdzie bijacy pionek ma sie ruszyc" << endl;
		cout << endl << "Aby wyjsc do menu, wpisz we wszystkich polach taka sama liczbe." << endl << "Funkcja ta jest nadrzeda do funkcji zapisu (Ponizej)" << endl;
		cout << endl << "Aby zapisac gre, w dowolnym polu (Kolumna/wiersz/kolumna ruchu/wiersz ruchu) wpisz liczbe 99. Gra zapisze sie a nastepnie zresetuje dane ruchu aby gracz zapisujacy mogl wykonac swoj ruch." << endl;
		cout << endl;
		system("pause");
		system("cls");
		goto menu;
	}
    for (int i = 0; i < a; i++)
    {
        cout << "  ";
        for (int h = 0; h < 4 * b + 1; h++)
        {
            cout << "-";
        }
        cout << endl;
        if (i < 10)
        {
            cout << i << " |";
        }
        else
        {
            cout << i << "|";
        }
        for (int j = 0; j < b; j++)
        {
            if (plansza[i][j] == 0)
            {
                cout << "///";
            }
            if (plansza[i][j] == 1)
            {
                cout << "   ";
            }
            if (plansza[i][j] == 2)
            {
                cout << ".b.";
            }
            if (plansza[i][j] == 3)
            {
                cout << ".c.";
            }
            if (plansza[i][j] == 4)
            {
                cout << "{C}";
            }
            if (plansza[i][j] == 5)
            {
                cout << "{B}";
            }
            cout << "|";
        }
        cout << endl;
    }
    cout << "  ";
    for (int h = 0; h < 4 * b + 1; h++)
    {
        cout << "-";
    }
    cout << endl << "    ";
    for (int i = 0; i < b; i++)
    {
        if (i < 10)
            cout << i << "   ";
        else
            cout << i << "  ";
    }
    cout << endl;

    for (int x = tm; x < 10000; x++)
    {
        tm = x;
		z:
        if (blad == 1)
        {
            cout << endl;
            kolejne_rysowania(plansza, a, b);
            blad--;
        }
        cout << endl << endl;
        if (tm % 2 == 1)
        {
            cout << "Tura gracza 1";
        }
        else
        {
            cout << "Tura gracza 2";
        }
        if (licznik_pionkow_bialych == 0)
        {
            system("cls");
            cout << "Czarne wygraly gratulacje";
            exit(0);
        }

        if (licznik_pionkow_czarnych == 0)
        {
            system("cls");
            cout << "Biale wygraly gratulacje";
            exit(0);
        }
        cout << endl;
        kordy_pionka();

        system("pause");
        system("cls");
        
		if (PION == POZIOM && PION == poziom_przesuniecie && PION == pion_przesuniecie)
		{
			system("cls");
			cout << "Czy zapisac gre?" << endl << "1 - Tak" << endl << "2 - Nie" << endl << "3 - Anuluj" << endl;
			int zapwyj = 0;
			while ((zapwyj != 1) && (zapwyj != 2) && (zapwyj != 3))
			{
				cin >> zapwyj;
			}
			if (zapwyj == 1)
			{
				zapis(a, b, x, plansza);
				cout << endl << "Gra zapisana" << endl << endl;
				system("pause");
				system("cls");
				goto menu;
			}
			else if (zapwyj == 2)
			{
				system("cls");
				goto menu;
			}
			else if (zapwyj == 3)
			{
				system("cls");
				blad++;
				goto z;
			}
			
		}
		if (PION == 99 || POZIOM == 99 || poziom_przesuniecie == 99 || pion_przesuniecie == 99)
		{
			system("cls");
			zapis(a, b, x, plansza);
			cout << "Gra zapisana";
			blad++;
			goto z;
		}
        if (x % 2 == 1)
        {
            if (plansza[POZIOM][PION] == 3 || plansza[POZIOM][PION] == 4)
            {
                system("cls");
                cout << "To nie twoj pionek - wybierz pionek bialy";
                blad++;
                goto z;
            }
        }
        if (x % 2 == 0)
        {
            if (plansza[POZIOM][PION] == 2 || plansza[POZIOM][PION] == 5)
            {
                system("cls");
                cout << "To nie twoj pionek - wybierz pionek czarny";
                blad++;
                goto z;
            }
        }
        if (plansza[POZIOM][PION] < 2)
        {
            system("cls");
            cout << "Tu nie ma pionka";
            blad++;
            goto z;
        }
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                if ((i == POZIOM) && (j == PION))
                {
                    if (plansza[i][j] == 0)
                    {
                        system("cls");
                        cout << "nieprawidlowe pole, nie ma tu pionka";
                        goto z;
                    }
                    else
                    {
                        if (plansza[i][j] == 2)
                        {
                            plansza[i][j] = 1;
                            kolor = 2;
                        }
                        else if (plansza[i][j] == 4)
                        {
                            plansza[i][j] = 1;
                            kolor = 4;
                        }
                        else if (plansza[i][j] == 5)
                        {
                            plansza[i][j] = 1;
                            kolor = 5;
                        }
                        else 
                        {
                            plansza[i][j] = 1;
                            kolor = 1;
                        }
                    }
                }
            }
        }
        //-----------------
        //przesuwanie pionkami

		int pion_p = pion_przesuniecie + 1;
		int poziom_p = poziom_przesuniecie + 1;
		int pion_p_2 = pion_przesuniecie - 1;
		int poziom_p_2 = poziom_przesuniecie - 1;

		for (int j = 0; j < a; j++)
		{


			for (int i = 0; i < b; i++)
			{

				if ((j == pion_przesuniecie) && (i == poziom_przesuniecie))
				{
					if (kolor == 2)
					{
						if ((plansza[j][i] == 3) || (plansza[j][i] == 4))
						{
							if (((pion_przesuniecie - POZIOM == 1) && (poziom_przesuniecie - PION == 1)) || ((pion_przesuniecie - POZIOM == 1) && (poziom_przesuniecie - PION == -1)) || ((pion_przesuniecie - POZIOM == -1) && (poziom_przesuniecie - PION == -1)) || ((pion_przesuniecie - POZIOM == -1) && (poziom_przesuniecie - PION == 1)))
							{
								licznik_pionkow_czarnych--;

								if (pion_p - POZIOM == 0)
								{
									if (poziom_p - PION == 0)
									{
										if (plansza[pion_p_2][poziom_p_2] == 3)
										{
											system("cls");
											cout << "nie mozna zbic";
											blad++;
											goto z;
										}
										else
										{
											plansza[pion_p_2][poziom_p_2] = 2;
										}
									}

									else
									{
										if (plansza[pion_p_2][poziom_p] == 3)
										{
											system("cls");
											cout << "nie mozna zbic";
											blad++;
											goto z;
										}
										else
										{
											plansza[pion_p_2][poziom_p] = 2;
										}
									}
								}
								else
								{
									if (poziom_p - PION == 0)
									{
										if (plansza[pion_p][poziom_p_2] == 3)
										{
											system("cls");
											cout << "nie mozna zbic";
											blad++;
											goto z;
										}
										else if (plansza[pion_p][poziom_p_2] == 1)
										{
											if (j == a-2)
											{
												plansza[pion_p][poziom_p_2] = 5;
											}
											else
											{
												plansza[pion_p][poziom_p_2] = 2;
											}
										}

									}

									else
									{
										if (plansza[pion_p][poziom_p] == 3)
										{
											system("cls");
											cout << "nie mozna zbic";
											blad++;
											goto z;
										}
										else if (plansza[pion_p][poziom_p] == 1)
										{
											if (j == a-2)
											{
												plansza[pion_p][poziom_p] = 5;
											}
											else
											{
												plansza[pion_p][poziom_p] = 2;
											}
										}
									}
								}



								// -----------
								if (plansza[j][i] == 0)
								{
									cout << "Blad";
									blad++;
									goto z;
								}

								else
								{
									if (kolor == 2)
									{
										plansza[j][i] = 1;
									}
									else
									{
										plansza[j][i] = 1;
									}

								}
							}
							else
							{

								blad++;
								goto z;
							}
						}

						else
						{
							if (((pion_przesuniecie - POZIOM == 1) && (poziom_przesuniecie - PION == 1)) || ((pion_przesuniecie - POZIOM == 1) && (poziom_przesuniecie - PION == -1)))
							{
								if (j != a-1)
								{
									if (plansza[j][i] == 0)
									{
										cout << "Blad";
										blad++;
										goto z;
									}

									if (plansza[j][i] == 2)
									{
										cout << "Blad, nie mozna bic swojego";
										blad++;
										goto z;
									}

									else
									{
										if (kolor == 2)
										{
											plansza[j][i] = 2;
										}
										else
										{
											plansza[j][i] = 3;
										}

									}
								}
								else
								{
									if (plansza[j][i] == 0)
									{
										cout << "Blad";
										blad++;
										goto z;
									}
									else
									{
										if (kolor == 2)
										{
											plansza[j][i] = 5;
										}

									}
								}

							}
							else
							{

								blad++;
								goto z;
							}
						}

					}
					// -------------------------------------------------------------------------------------------
					else if (kolor == 1)
					{
						if ((plansza[j][i] == 2) || (plansza[j][i] == 5))
						{
							if (((pion_przesuniecie - POZIOM == -1) && (poziom_przesuniecie - PION == -1)) || ((pion_przesuniecie - POZIOM == -1) && (poziom_przesuniecie - PION == 1)) || /*tu*/ ((pion_przesuniecie - POZIOM == 1) && (poziom_przesuniecie - PION == 1)) || ((pion_przesuniecie - POZIOM == 1) && (poziom_przesuniecie - PION == -1)))
							{
								licznik_pionkow_bialych--;

								if (pion_p - POZIOM == 0)
								{
									if (poziom_p - PION == 0)
									{
										if (plansza[pion_p_2][poziom_p_2] == 2)
										{
											system("cls");
											cout << "nie mozna zbic";
											blad++;
											goto z;
										}
										else if (plansza[pion_p_2][poziom_p_2] == 1)
										{
											if (j == 1)
											{
												plansza[pion_p_2][poziom_p_2] = 4;
											}
											else
											{
												plansza[pion_p_2][poziom_p_2] = 3;
											}
										}

									}
									else
									{
										if (plansza[pion_p_2][poziom_p] == 2)
										{
											system("cls");
											cout << "nie mozna zbic";
											blad++;
											goto z;
										}
										else if (plansza[pion_p_2][poziom_p] == 1)
										{
											if (j == 1)
											{
												plansza[pion_p_2][poziom_p] = 4;
											}
											else
											{
												plansza[pion_p_2][poziom_p] = 3;
											}
										}

									}
								}
								else
								{
									if (poziom_p - PION == 0)
									{
										if (plansza[pion_p][poziom_p_2] == 2)
										{
											system("cls");
											cout << "nie mozna zbic";
											blad++;
											goto z;
										}

										else
										{
											plansza[pion_p][poziom_p_2] = 3;
										}
									}
									else
									{
										if (plansza[pion_p][poziom_p] == 2)
										{
											system("cls");
											cout << "nie mozna zbic";
											blad++;
											goto z;
										}
										else
										{
											plansza[pion_p][poziom_p] = 3;
										}
									}
								}


								// ------------------

								if (plansza[j][i] == 0)
								{
									cout << "Blad";
									blad++;
									goto z;
								}
								else
								{
									if (kolor == 2)
									{
										plansza[j][i] = 1;
									}
									else
									{
										plansza[j][i] = 1;
									}

								}




							}
							else
							{

								blad++;
								goto z;
							}
						}
						// --
						else
						{
							if (((pion_przesuniecie - POZIOM == -1) && (poziom_przesuniecie - PION == -1)) || ((pion_przesuniecie - POZIOM == -1) && (poziom_przesuniecie - PION == 1)))
							{
								if (j != 0)
								{
									if (plansza[j][i] == 0)
									{
										cout << "Blad";
										blad++;
										goto z;
									}

									if (plansza[j][i] == 3)
									{
										cout << "Blad, nie mozna bic swojego"; //
										blad++;
										goto z;
									}
									else
									{
										if (kolor == 2)
										{
											plansza[j][i] = 2;
										}
										else
										{
											plansza[j][i] = 3;
										}

									}
								}
								else
								{
									if (plansza[j][i] == 0)
									{
										cout << "Blad";
										blad++;
										goto z;
									}
									else
									{
										if (kolor == 1)
										{
											plansza[j][i] = 4;
										}

									}
								}

							}
							else
							{

								blad++;
								goto z;
							}
						}

					}
					else if (kolor == 4)
					{
						if ((plansza[j][i] == 2) || (plansza[j][i] == 5))
						{
							if (((pion_przesuniecie - POZIOM == -1) && (poziom_przesuniecie - PION == -1)) || ((pion_przesuniecie - POZIOM == -1) && (poziom_przesuniecie - PION == 1)) || /*tu*/ ((pion_przesuniecie - POZIOM == 1) && (poziom_przesuniecie - PION == 1)) || ((pion_przesuniecie - POZIOM == 1) && (poziom_przesuniecie - PION == -1)) || ((pion_przesuniecie - POZIOM == -2) && (poziom_przesuniecie - PION == -2)) || ((pion_przesuniecie - POZIOM == -2) && (poziom_przesuniecie - PION == 2)) || /*tu*/ ((pion_przesuniecie - POZIOM == 2) && (poziom_przesuniecie - PION == 2)) || ((pion_przesuniecie - POZIOM == 2) && (poziom_przesuniecie - PION == -2)) || ((pion_przesuniecie - POZIOM == -3) && (poziom_przesuniecie - PION == -3)) || ((pion_przesuniecie - POZIOM == -3) && (poziom_przesuniecie - PION == 3)) || /*tu*/ ((pion_przesuniecie - POZIOM == 3) && (poziom_przesuniecie - PION == 3)) || ((pion_przesuniecie - POZIOM == 3) && (poziom_przesuniecie - PION == -3)) || ((pion_przesuniecie - POZIOM == -4) && (poziom_przesuniecie - PION == -4)) || ((pion_przesuniecie - POZIOM == -4) && (poziom_przesuniecie - PION == 4)) || /*tu*/ ((pion_przesuniecie - POZIOM == 4) && (poziom_przesuniecie - PION == 4)) || ((pion_przesuniecie - POZIOM == 4) && (poziom_przesuniecie - PION == -4)) || ((pion_przesuniecie - POZIOM == -5) && (poziom_przesuniecie - PION == -5)) || ((pion_przesuniecie - POZIOM == -5) && (poziom_przesuniecie - PION == 5)) || /*tu*/ ((pion_przesuniecie - POZIOM == 5) && (poziom_przesuniecie - PION == 5)) || ((pion_przesuniecie - POZIOM == 5) && (poziom_przesuniecie - PION == -5)) || ((pion_przesuniecie - POZIOM == -6) && (poziom_przesuniecie - PION == -6)) || ((pion_przesuniecie - POZIOM == -6) && (poziom_przesuniecie - PION == 6)) || /*tu*/ ((pion_przesuniecie - POZIOM == 6) && (poziom_przesuniecie - PION == 6)) || ((pion_przesuniecie - POZIOM == 6) && (poziom_przesuniecie - PION == -6)) || ((pion_przesuniecie - POZIOM == -7) && (poziom_przesuniecie - PION == -7)) || ((pion_przesuniecie - POZIOM == -7) && (poziom_przesuniecie - PION == 7)) || /*tu*/ ((pion_przesuniecie - POZIOM == 7) && (poziom_przesuniecie - PION == 7)) || ((pion_przesuniecie - POZIOM == 7) && (poziom_przesuniecie - PION == -7)) || ((pion_przesuniecie - POZIOM == -8) && (poziom_przesuniecie - PION == -8)) || ((pion_przesuniecie - POZIOM == -8) && (poziom_przesuniecie - PION == 8)) || /*tu*/ ((pion_przesuniecie - POZIOM == 8) && (poziom_przesuniecie - PION == 8)) || ((pion_przesuniecie - POZIOM == 8) && (poziom_przesuniecie - PION == -8)) || ((pion_przesuniecie - POZIOM == -9) && (poziom_przesuniecie - PION == -9)) || ((pion_przesuniecie - POZIOM == -9) && (poziom_przesuniecie - PION == 9)) || /*tu*/ ((pion_przesuniecie - POZIOM == 9) && (poziom_przesuniecie - PION == 9)) || ((pion_przesuniecie - POZIOM == 9) && (poziom_przesuniecie - PION == -9)) || ((pion_przesuniecie - POZIOM == -10) && (poziom_przesuniecie - PION == -10)) || ((pion_przesuniecie - POZIOM == -10) && (poziom_przesuniecie - PION == 10)) || /*tu*/ ((pion_przesuniecie - POZIOM == 10) && (poziom_przesuniecie - PION == 10)) || ((pion_przesuniecie - POZIOM == 10) && (poziom_przesuniecie - PION == -10)) || ((pion_przesuniecie - POZIOM == -11) && (poziom_przesuniecie - PION == -11)) || ((pion_przesuniecie - POZIOM == -11) && (poziom_przesuniecie - PION == 11)) || /*tu*/ ((pion_przesuniecie - POZIOM == 11) && (poziom_przesuniecie - PION == 11)) || ((pion_przesuniecie - POZIOM == 11) && (poziom_przesuniecie - PION == -11)) || ((pion_przesuniecie - POZIOM == -12) && (poziom_przesuniecie - PION == -12)) || ((pion_przesuniecie - POZIOM == -12) && (poziom_przesuniecie - PION == 12)) || /*tu*/ ((pion_przesuniecie - POZIOM == 12) && (poziom_przesuniecie - PION == 12)) || ((pion_przesuniecie - POZIOM == 12) && (poziom_przesuniecie - PION == -12)) || ((pion_przesuniecie - POZIOM == -13) && (poziom_przesuniecie - PION == -13)) || ((pion_przesuniecie - POZIOM == -13) && (poziom_przesuniecie - PION == 13)) || /*tu*/ ((pion_przesuniecie - POZIOM == 13) && (poziom_przesuniecie - PION == 13)) || ((pion_przesuniecie - POZIOM == 13) && (poziom_przesuniecie - PION == -13)) || ((pion_przesuniecie - POZIOM == -14) && (poziom_przesuniecie - PION == -14)) || ((pion_przesuniecie - POZIOM == -14) && (poziom_przesuniecie - PION == 14)) || /*tu*/ ((pion_przesuniecie - POZIOM == 14) && (poziom_przesuniecie - PION == 14)) || ((pion_przesuniecie - POZIOM == 14) && (poziom_przesuniecie - PION == -14)) || ((pion_przesuniecie - POZIOM == -15) && (poziom_przesuniecie - PION == -15)) || ((pion_przesuniecie - POZIOM == -15) && (poziom_przesuniecie - PION == 15)) || /*tu*/ ((pion_przesuniecie - POZIOM == 15) && (poziom_przesuniecie - PION == 15)) || ((pion_przesuniecie - POZIOM == 15) && (poziom_przesuniecie - PION == -15)) || ((pion_przesuniecie - POZIOM == -16) && (poziom_przesuniecie - PION == -16)) || ((pion_przesuniecie - POZIOM == -16) && (poziom_przesuniecie - PION == 16)) || /*tu*/ ((pion_przesuniecie - POZIOM == 16) && (poziom_przesuniecie - PION == 16)) || ((pion_przesuniecie - POZIOM == 16) && (poziom_przesuniecie - PION == -16)) || ((pion_przesuniecie - POZIOM == -17) && (poziom_przesuniecie - PION == -17)) || ((pion_przesuniecie - POZIOM == -17) && (poziom_przesuniecie - PION == 17)) || /*tu*/ ((pion_przesuniecie - POZIOM == 17) && (poziom_przesuniecie - PION == 17)) || ((pion_przesuniecie - POZIOM == 17) && (poziom_przesuniecie - PION == -17)) || ((pion_przesuniecie - POZIOM == -18) && (poziom_przesuniecie - PION == -18)) || ((pion_przesuniecie - POZIOM == -18) && (poziom_przesuniecie - PION == 18)) || /*tu*/ ((pion_przesuniecie - POZIOM == 18) && (poziom_przesuniecie - PION == 18)) || ((pion_przesuniecie - POZIOM == 18) && (poziom_przesuniecie - PION == -18)) || ((pion_przesuniecie - POZIOM == -19) && (poziom_przesuniecie - PION == -19)) || ((pion_przesuniecie - POZIOM == -19) && (poziom_przesuniecie - PION == 19)) || /*tu*/ ((pion_przesuniecie - POZIOM == 19) && (poziom_przesuniecie - PION == 19)) || ((pion_przesuniecie - POZIOM == 19) && (poziom_przesuniecie - PION == -19)) || ((pion_przesuniecie - POZIOM == -20) && (poziom_przesuniecie - PION == -20)) || ((pion_przesuniecie - POZIOM == -20) && (poziom_przesuniecie - PION == 20)) || /*tu*/ ((pion_przesuniecie - POZIOM == 20) && (poziom_przesuniecie - PION == 20)) || ((pion_przesuniecie - POZIOM == 20) && (poziom_przesuniecie - PION == -20)) || ((pion_przesuniecie - POZIOM == -21) && (poziom_przesuniecie - PION == -21)) || ((pion_przesuniecie - POZIOM == -21) && (poziom_przesuniecie - PION == 21)) || /*tu*/ ((pion_przesuniecie - POZIOM == 21) && (poziom_przesuniecie - PION == 21)) || ((pion_przesuniecie - POZIOM == 21) && (poziom_przesuniecie - PION == -21)) || ((pion_przesuniecie - POZIOM == -22) && (poziom_przesuniecie - PION == -22)) || ((pion_przesuniecie - POZIOM == -22) && (poziom_przesuniecie - PION == 22)) || /*tu*/ ((pion_przesuniecie - POZIOM == 22) && (poziom_przesuniecie - PION == 22)) || ((pion_przesuniecie - POZIOM == 22) && (poziom_przesuniecie - PION == -22)) || ((pion_przesuniecie - POZIOM == -23) && (poziom_przesuniecie - PION == -23)) || ((pion_przesuniecie - POZIOM == -23) && (poziom_przesuniecie - PION == 23)) || /*tu*/ ((pion_przesuniecie - POZIOM == 23) && (poziom_przesuniecie - PION == 23)) || ((pion_przesuniecie - POZIOM == 23) && (poziom_przesuniecie - PION == -23)) || ((pion_przesuniecie - POZIOM == -24) && (poziom_przesuniecie - PION == -24)) || ((pion_przesuniecie - POZIOM == -24) && (poziom_przesuniecie - PION == 24)) || /*tu*/ ((pion_przesuniecie - POZIOM == 24) && (poziom_przesuniecie - PION == 24)) || ((pion_przesuniecie - POZIOM == 24) && (poziom_przesuniecie - PION == -24)) || ((pion_przesuniecie - POZIOM == -25) && (poziom_przesuniecie - PION == -25)) || ((pion_przesuniecie - POZIOM == -25) && (poziom_przesuniecie - PION == 25)) || /*tu*/ ((pion_przesuniecie - POZIOM == 25) && (poziom_przesuniecie - PION == 25)) || ((pion_przesuniecie - POZIOM == 25) && (poziom_przesuniecie - PION == -25)) || ((pion_przesuniecie - POZIOM == -26) && (poziom_przesuniecie - PION == -26)) || ((pion_przesuniecie - POZIOM == -26) && (poziom_przesuniecie - PION == 26)) || /*tu*/ ((pion_przesuniecie - POZIOM == 26) && (poziom_przesuniecie - PION == 26)) || ((pion_przesuniecie - POZIOM == 26) && (poziom_przesuniecie - PION == -26)) || ((pion_przesuniecie - POZIOM == -27) && (poziom_przesuniecie - PION == -27)) || ((pion_przesuniecie - POZIOM == -27) && (poziom_przesuniecie - PION == 27)) || /*tu*/ ((pion_przesuniecie - POZIOM == 27) && (poziom_przesuniecie - PION == 27)) || ((pion_przesuniecie - POZIOM == 27) && (poziom_przesuniecie - PION == -27)) || ((pion_przesuniecie - POZIOM == -28) && (poziom_przesuniecie - PION == -28)) || ((pion_przesuniecie - POZIOM == -28) && (poziom_przesuniecie - PION == 28)) || /*tu*/ ((pion_przesuniecie - POZIOM == 28) && (poziom_przesuniecie - PION == 28)) || ((pion_przesuniecie - POZIOM == 28) && (poziom_przesuniecie - PION == -28)) || ((pion_przesuniecie - POZIOM == -29) && (poziom_przesuniecie - PION == -29)) || ((pion_przesuniecie - POZIOM == -29) && (poziom_przesuniecie - PION == 29)) || /*tu*/ ((pion_przesuniecie - POZIOM == 29) && (poziom_przesuniecie - PION == 29)) || ((pion_przesuniecie - POZIOM == 29) && (poziom_przesuniecie - PION == -29)))
							{
								licznik_pionkow_bialych--;

								if ((pion_p - POZIOM == 0) || (pion_p - POZIOM <= 0))
								{
									if ((poziom_p - PION == 0) || (poziom_p - PION <= 0))
									{
										if (plansza[pion_p_2][poziom_p_2] == 2)
										{
											system("cls");
											cout << "nie mozna zbic";
											blad++;
											goto z;
										}
										else if (plansza[pion_p_2][poziom_p_2] == 1)
										{
											if (j == 1)
											{
												plansza[pion_p_2][poziom_p_2] = 4;
											}
											else
											{
												plansza[pion_p_2][poziom_p_2] = 4;
											}
										}

									}
									else
									{
										if (plansza[pion_p_2][poziom_p] == 2)
										{
											system("cls");
											cout << "nie mozna zbic";
											blad++;
											goto z;
										}
										else if (plansza[pion_p_2][poziom_p] == 1)
										{
											if (j == 1)
											{
												plansza[pion_p_2][poziom_p] = 4;
											}
											else
											{
												plansza[pion_p_2][poziom_p] = 4;
											}
										}

									}
								}
								else
								{
									if ((poziom_p - PION == 0) || (poziom_p - PION <= 0))
									{
										if (plansza[pion_p][poziom_p_2] == 2)
										{
											system("cls");
											cout << "nie mozna zbic";
											blad++;
											goto z;
										}

										else
										{
											plansza[pion_p][poziom_p_2] = 4;
										}
									}
									else
									{
										if (plansza[pion_p][poziom_p] == 2)
										{
											system("cls");
											cout << "nie mozna zbic";
											blad++;
											goto z;
										}
										else
										{
											plansza[pion_p][poziom_p] = 4;
										}
									}
								}


								// ------------------

								if (plansza[j][i] == 0)
								{
									cout << "Blad";
									blad++;
									goto z;
								}
								else
								{
									if (kolor == 2)
									{
										plansza[j][i] = 1;
									}
									else
									{
										plansza[j][i] = 1;
									}

								}
							}
							else
							{
								system("cls");
								cout << "damka nie jest wrzechmocna";
								blad++;
								goto z;
							}

						}
						else
						{
							if (((pion_przesuniecie - POZIOM == -1) && (poziom_przesuniecie - PION == -1)) || ((pion_przesuniecie - POZIOM == -1) && (poziom_przesuniecie - PION == 1)) || /*tu*/ ((pion_przesuniecie - POZIOM == 1) && (poziom_przesuniecie - PION == 1)) || ((pion_przesuniecie - POZIOM == 1) && (poziom_przesuniecie - PION == -1)) || ((pion_przesuniecie - POZIOM == -2) && (poziom_przesuniecie - PION == -2)) || ((pion_przesuniecie - POZIOM == -2) && (poziom_przesuniecie - PION == 2)) || /*tu*/ ((pion_przesuniecie - POZIOM == 2) && (poziom_przesuniecie - PION == 2)) || ((pion_przesuniecie - POZIOM == 2) && (poziom_przesuniecie - PION == -2)) || ((pion_przesuniecie - POZIOM == -3) && (poziom_przesuniecie - PION == -3)) || ((pion_przesuniecie - POZIOM == -3) && (poziom_przesuniecie - PION == 3)) || /*tu*/ ((pion_przesuniecie - POZIOM == 3) && (poziom_przesuniecie - PION == 3)) || ((pion_przesuniecie - POZIOM == 3) && (poziom_przesuniecie - PION == -3)) || ((pion_przesuniecie - POZIOM == -4) && (poziom_przesuniecie - PION == -4)) || ((pion_przesuniecie - POZIOM == -4) && (poziom_przesuniecie - PION == 4)) || /*tu*/ ((pion_przesuniecie - POZIOM == 4) && (poziom_przesuniecie - PION == 4)) || ((pion_przesuniecie - POZIOM == 4) && (poziom_przesuniecie - PION == -4)) || ((pion_przesuniecie - POZIOM == -5) && (poziom_przesuniecie - PION == -5)) || ((pion_przesuniecie - POZIOM == -5) && (poziom_przesuniecie - PION == 5)) || /*tu*/ ((pion_przesuniecie - POZIOM == 5) && (poziom_przesuniecie - PION == 5)) || ((pion_przesuniecie - POZIOM == 5) && (poziom_przesuniecie - PION == -5)) || ((pion_przesuniecie - POZIOM == -6) && (poziom_przesuniecie - PION == -6)) || ((pion_przesuniecie - POZIOM == -6) && (poziom_przesuniecie - PION == 6)) || /*tu*/ ((pion_przesuniecie - POZIOM == 6) && (poziom_przesuniecie - PION == 6)) || ((pion_przesuniecie - POZIOM == 6) && (poziom_przesuniecie - PION == -6)) || ((pion_przesuniecie - POZIOM == -7) && (poziom_przesuniecie - PION == -7)) || ((pion_przesuniecie - POZIOM == -7) && (poziom_przesuniecie - PION == 7)) || /*tu*/ ((pion_przesuniecie - POZIOM == 7) && (poziom_przesuniecie - PION == 7)) || ((pion_przesuniecie - POZIOM == 7) && (poziom_przesuniecie - PION == -7)) || ((pion_przesuniecie - POZIOM == -8) && (poziom_przesuniecie - PION == -8)) || ((pion_przesuniecie - POZIOM == -8) && (poziom_przesuniecie - PION == 8)) || /*tu*/ ((pion_przesuniecie - POZIOM == 8) && (poziom_przesuniecie - PION == 8)) || ((pion_przesuniecie - POZIOM == 8) && (poziom_przesuniecie - PION == -8)) || ((pion_przesuniecie - POZIOM == -9) && (poziom_przesuniecie - PION == -9)) || ((pion_przesuniecie - POZIOM == -9) && (poziom_przesuniecie - PION == 9)) || /*tu*/ ((pion_przesuniecie - POZIOM == 9) && (poziom_przesuniecie - PION == 9)) || ((pion_przesuniecie - POZIOM == 9) && (poziom_przesuniecie - PION == -9)) || ((pion_przesuniecie - POZIOM == -10) && (poziom_przesuniecie - PION == -10)) || ((pion_przesuniecie - POZIOM == -10) && (poziom_przesuniecie - PION == 10)) || /*tu*/ ((pion_przesuniecie - POZIOM == 10) && (poziom_przesuniecie - PION == 10)) || ((pion_przesuniecie - POZIOM == 10) && (poziom_przesuniecie - PION == -10)) || ((pion_przesuniecie - POZIOM == -11) && (poziom_przesuniecie - PION == -11)) || ((pion_przesuniecie - POZIOM == -11) && (poziom_przesuniecie - PION == 11)) || /*tu*/ ((pion_przesuniecie - POZIOM == 11) && (poziom_przesuniecie - PION == 11)) || ((pion_przesuniecie - POZIOM == 11) && (poziom_przesuniecie - PION == -11)) || ((pion_przesuniecie - POZIOM == -12) && (poziom_przesuniecie - PION == -12)) || ((pion_przesuniecie - POZIOM == -12) && (poziom_przesuniecie - PION == 12)) || /*tu*/ ((pion_przesuniecie - POZIOM == 12) && (poziom_przesuniecie - PION == 12)) || ((pion_przesuniecie - POZIOM == 12) && (poziom_przesuniecie - PION == -12)) || ((pion_przesuniecie - POZIOM == -13) && (poziom_przesuniecie - PION == -13)) || ((pion_przesuniecie - POZIOM == -13) && (poziom_przesuniecie - PION == 13)) || /*tu*/ ((pion_przesuniecie - POZIOM == 13) && (poziom_przesuniecie - PION == 13)) || ((pion_przesuniecie - POZIOM == 13) && (poziom_przesuniecie - PION == -13)) || ((pion_przesuniecie - POZIOM == -14) && (poziom_przesuniecie - PION == -14)) || ((pion_przesuniecie - POZIOM == -14) && (poziom_przesuniecie - PION == 14)) || /*tu*/ ((pion_przesuniecie - POZIOM == 14) && (poziom_przesuniecie - PION == 14)) || ((pion_przesuniecie - POZIOM == 14) && (poziom_przesuniecie - PION == -14)) || ((pion_przesuniecie - POZIOM == -15) && (poziom_przesuniecie - PION == -15)) || ((pion_przesuniecie - POZIOM == -15) && (poziom_przesuniecie - PION == 15)) || /*tu*/ ((pion_przesuniecie - POZIOM == 15) && (poziom_przesuniecie - PION == 15)) || ((pion_przesuniecie - POZIOM == 15) && (poziom_przesuniecie - PION == -15)) || ((pion_przesuniecie - POZIOM == -16) && (poziom_przesuniecie - PION == -16)) || ((pion_przesuniecie - POZIOM == -16) && (poziom_przesuniecie - PION == 16)) || /*tu*/ ((pion_przesuniecie - POZIOM == 16) && (poziom_przesuniecie - PION == 16)) || ((pion_przesuniecie - POZIOM == 16) && (poziom_przesuniecie - PION == -16)) || ((pion_przesuniecie - POZIOM == -17) && (poziom_przesuniecie - PION == -17)) || ((pion_przesuniecie - POZIOM == -17) && (poziom_przesuniecie - PION == 17)) || /*tu*/ ((pion_przesuniecie - POZIOM == 17) && (poziom_przesuniecie - PION == 17)) || ((pion_przesuniecie - POZIOM == 17) && (poziom_przesuniecie - PION == -17)) || ((pion_przesuniecie - POZIOM == -18) && (poziom_przesuniecie - PION == -18)) || ((pion_przesuniecie - POZIOM == -18) && (poziom_przesuniecie - PION == 18)) || /*tu*/ ((pion_przesuniecie - POZIOM == 18) && (poziom_przesuniecie - PION == 18)) || ((pion_przesuniecie - POZIOM == 18) && (poziom_przesuniecie - PION == -18)) || ((pion_przesuniecie - POZIOM == -19) && (poziom_przesuniecie - PION == -19)) || ((pion_przesuniecie - POZIOM == -19) && (poziom_przesuniecie - PION == 19)) || /*tu*/ ((pion_przesuniecie - POZIOM == 19) && (poziom_przesuniecie - PION == 19)) || ((pion_przesuniecie - POZIOM == 19) && (poziom_przesuniecie - PION == -19)) || ((pion_przesuniecie - POZIOM == -20) && (poziom_przesuniecie - PION == -20)) || ((pion_przesuniecie - POZIOM == -20) && (poziom_przesuniecie - PION == 20)) || /*tu*/ ((pion_przesuniecie - POZIOM == 20) && (poziom_przesuniecie - PION == 20)) || ((pion_przesuniecie - POZIOM == 20) && (poziom_przesuniecie - PION == -20)) || ((pion_przesuniecie - POZIOM == -21) && (poziom_przesuniecie - PION == -21)) || ((pion_przesuniecie - POZIOM == -21) && (poziom_przesuniecie - PION == 21)) || /*tu*/ ((pion_przesuniecie - POZIOM == 21) && (poziom_przesuniecie - PION == 21)) || ((pion_przesuniecie - POZIOM == 21) && (poziom_przesuniecie - PION == -21)) || ((pion_przesuniecie - POZIOM == -22) && (poziom_przesuniecie - PION == -22)) || ((pion_przesuniecie - POZIOM == -22) && (poziom_przesuniecie - PION == 22)) || /*tu*/ ((pion_przesuniecie - POZIOM == 22) && (poziom_przesuniecie - PION == 22)) || ((pion_przesuniecie - POZIOM == 22) && (poziom_przesuniecie - PION == -22)) || ((pion_przesuniecie - POZIOM == -23) && (poziom_przesuniecie - PION == -23)) || ((pion_przesuniecie - POZIOM == -23) && (poziom_przesuniecie - PION == 23)) || /*tu*/ ((pion_przesuniecie - POZIOM == 23) && (poziom_przesuniecie - PION == 23)) || ((pion_przesuniecie - POZIOM == 23) && (poziom_przesuniecie - PION == -23)) || ((pion_przesuniecie - POZIOM == -24) && (poziom_przesuniecie - PION == -24)) || ((pion_przesuniecie - POZIOM == -24) && (poziom_przesuniecie - PION == 24)) || /*tu*/ ((pion_przesuniecie - POZIOM == 24) && (poziom_przesuniecie - PION == 24)) || ((pion_przesuniecie - POZIOM == 24) && (poziom_przesuniecie - PION == -24)) || ((pion_przesuniecie - POZIOM == -25) && (poziom_przesuniecie - PION == -25)) || ((pion_przesuniecie - POZIOM == -25) && (poziom_przesuniecie - PION == 25)) || /*tu*/ ((pion_przesuniecie - POZIOM == 25) && (poziom_przesuniecie - PION == 25)) || ((pion_przesuniecie - POZIOM == 25) && (poziom_przesuniecie - PION == -25)) || ((pion_przesuniecie - POZIOM == -26) && (poziom_przesuniecie - PION == -26)) || ((pion_przesuniecie - POZIOM == -26) && (poziom_przesuniecie - PION == 26)) || /*tu*/ ((pion_przesuniecie - POZIOM == 26) && (poziom_przesuniecie - PION == 26)) || ((pion_przesuniecie - POZIOM == 26) && (poziom_przesuniecie - PION == -26)) || ((pion_przesuniecie - POZIOM == -27) && (poziom_przesuniecie - PION == -27)) || ((pion_przesuniecie - POZIOM == -27) && (poziom_przesuniecie - PION == 27)) || /*tu*/ ((pion_przesuniecie - POZIOM == 27) && (poziom_przesuniecie - PION == 27)) || ((pion_przesuniecie - POZIOM == 27) && (poziom_przesuniecie - PION == -27)) || ((pion_przesuniecie - POZIOM == -28) && (poziom_przesuniecie - PION == -28)) || ((pion_przesuniecie - POZIOM == -28) && (poziom_przesuniecie - PION == 28)) || /*tu*/ ((pion_przesuniecie - POZIOM == 28) && (poziom_przesuniecie - PION == 28)) || ((pion_przesuniecie - POZIOM == 28) && (poziom_przesuniecie - PION == -28)) || ((pion_przesuniecie - POZIOM == -29) && (poziom_przesuniecie - PION == -29)) || ((pion_przesuniecie - POZIOM == -29) && (poziom_przesuniecie - PION == 29)) || /*tu*/ ((pion_przesuniecie - POZIOM == 29) && (poziom_przesuniecie - PION == 29)) || ((pion_przesuniecie - POZIOM == 29) && (poziom_przesuniecie - PION == -29)))
							{
								if (plansza[j][i] == 0)
								{
									cout << "Blad";
									blad++;
									goto z;
								}
								else
								{
									if (kolor == 2)
									{
										plansza[j][i] = 2;
									}
									else
									{
										plansza[j][i] = 4;
									}

								}
							}
							else
							{
								system("cls");
								cout << "damka nie jest wrzechmocna";
								blad++;
								goto z;
							}

						}


					}
					// -------------------------------------------------------------------
					else if (kolor == 5)
					{
						if ((plansza[j][i] == 3) || (plansza[j][i] == 4))
						{
							if (((pion_przesuniecie - POZIOM == -1) && (poziom_przesuniecie - PION == -1)) || ((pion_przesuniecie - POZIOM == -1) && (poziom_przesuniecie - PION == 1)) || /*tu*/ ((pion_przesuniecie - POZIOM == 1) && (poziom_przesuniecie - PION == 1)) || ((pion_przesuniecie - POZIOM == 1) && (poziom_przesuniecie - PION == -1)) || ((pion_przesuniecie - POZIOM == -2) && (poziom_przesuniecie - PION == -2)) || ((pion_przesuniecie - POZIOM == -2) && (poziom_przesuniecie - PION == 2)) || /*tu*/ ((pion_przesuniecie - POZIOM == 2) && (poziom_przesuniecie - PION == 2)) || ((pion_przesuniecie - POZIOM == 2) && (poziom_przesuniecie - PION == -2)) || ((pion_przesuniecie - POZIOM == -3) && (poziom_przesuniecie - PION == -3)) || ((pion_przesuniecie - POZIOM == -3) && (poziom_przesuniecie - PION == 3)) || /*tu*/ ((pion_przesuniecie - POZIOM == 3) && (poziom_przesuniecie - PION == 3)) || ((pion_przesuniecie - POZIOM == 3) && (poziom_przesuniecie - PION == -3)) || ((pion_przesuniecie - POZIOM == -4) && (poziom_przesuniecie - PION == -4)) || ((pion_przesuniecie - POZIOM == -4) && (poziom_przesuniecie - PION == 4)) || /*tu*/ ((pion_przesuniecie - POZIOM == 4) && (poziom_przesuniecie - PION == 4)) || ((pion_przesuniecie - POZIOM == 4) && (poziom_przesuniecie - PION == -4)) || ((pion_przesuniecie - POZIOM == -5) && (poziom_przesuniecie - PION == -5)) || ((pion_przesuniecie - POZIOM == -5) && (poziom_przesuniecie - PION == 5)) || /*tu*/ ((pion_przesuniecie - POZIOM == 5) && (poziom_przesuniecie - PION == 5)) || ((pion_przesuniecie - POZIOM == 5) && (poziom_przesuniecie - PION == -5)) || ((pion_przesuniecie - POZIOM == -6) && (poziom_przesuniecie - PION == -6)) || ((pion_przesuniecie - POZIOM == -6) && (poziom_przesuniecie - PION == 6)) || /*tu*/ ((pion_przesuniecie - POZIOM == 6) && (poziom_przesuniecie - PION == 6)) || ((pion_przesuniecie - POZIOM == 6) && (poziom_przesuniecie - PION == -6)) || ((pion_przesuniecie - POZIOM == -7) && (poziom_przesuniecie - PION == -7)) || ((pion_przesuniecie - POZIOM == -7) && (poziom_przesuniecie - PION == 7)) || /*tu*/ ((pion_przesuniecie - POZIOM == 7) && (poziom_przesuniecie - PION == 7)) || ((pion_przesuniecie - POZIOM == 7) && (poziom_przesuniecie - PION == -7)) || ((pion_przesuniecie - POZIOM == -8) && (poziom_przesuniecie - PION == -8)) || ((pion_przesuniecie - POZIOM == -8) && (poziom_przesuniecie - PION == 8)) || /*tu*/ ((pion_przesuniecie - POZIOM == 8) && (poziom_przesuniecie - PION == 8)) || ((pion_przesuniecie - POZIOM == 8) && (poziom_przesuniecie - PION == -8)) || ((pion_przesuniecie - POZIOM == -9) && (poziom_przesuniecie - PION == -9)) || ((pion_przesuniecie - POZIOM == -9) && (poziom_przesuniecie - PION == 9)) || /*tu*/ ((pion_przesuniecie - POZIOM == 9) && (poziom_przesuniecie - PION == 9)) || ((pion_przesuniecie - POZIOM == 9) && (poziom_przesuniecie - PION == -9)) || ((pion_przesuniecie - POZIOM == -10) && (poziom_przesuniecie - PION == -10)) || ((pion_przesuniecie - POZIOM == -10) && (poziom_przesuniecie - PION == 10)) || /*tu*/ ((pion_przesuniecie - POZIOM == 10) && (poziom_przesuniecie - PION == 10)) || ((pion_przesuniecie - POZIOM == 10) && (poziom_przesuniecie - PION == -10)) || ((pion_przesuniecie - POZIOM == -11) && (poziom_przesuniecie - PION == -11)) || ((pion_przesuniecie - POZIOM == -11) && (poziom_przesuniecie - PION == 11)) || /*tu*/ ((pion_przesuniecie - POZIOM == 11) && (poziom_przesuniecie - PION == 11)) || ((pion_przesuniecie - POZIOM == 11) && (poziom_przesuniecie - PION == -11)) || ((pion_przesuniecie - POZIOM == -12) && (poziom_przesuniecie - PION == -12)) || ((pion_przesuniecie - POZIOM == -12) && (poziom_przesuniecie - PION == 12)) || /*tu*/ ((pion_przesuniecie - POZIOM == 12) && (poziom_przesuniecie - PION == 12)) || ((pion_przesuniecie - POZIOM == 12) && (poziom_przesuniecie - PION == -12)) || ((pion_przesuniecie - POZIOM == -13) && (poziom_przesuniecie - PION == -13)) || ((pion_przesuniecie - POZIOM == -13) && (poziom_przesuniecie - PION == 13)) || /*tu*/ ((pion_przesuniecie - POZIOM == 13) && (poziom_przesuniecie - PION == 13)) || ((pion_przesuniecie - POZIOM == 13) && (poziom_przesuniecie - PION == -13)) || ((pion_przesuniecie - POZIOM == -14) && (poziom_przesuniecie - PION == -14)) || ((pion_przesuniecie - POZIOM == -14) && (poziom_przesuniecie - PION == 14)) || /*tu*/ ((pion_przesuniecie - POZIOM == 14) && (poziom_przesuniecie - PION == 14)) || ((pion_przesuniecie - POZIOM == 14) && (poziom_przesuniecie - PION == -14)) || ((pion_przesuniecie - POZIOM == -15) && (poziom_przesuniecie - PION == -15)) || ((pion_przesuniecie - POZIOM == -15) && (poziom_przesuniecie - PION == 15)) || /*tu*/ ((pion_przesuniecie - POZIOM == 15) && (poziom_przesuniecie - PION == 15)) || ((pion_przesuniecie - POZIOM == 15) && (poziom_przesuniecie - PION == -15)) || ((pion_przesuniecie - POZIOM == -16) && (poziom_przesuniecie - PION == -16)) || ((pion_przesuniecie - POZIOM == -16) && (poziom_przesuniecie - PION == 16)) || /*tu*/ ((pion_przesuniecie - POZIOM == 16) && (poziom_przesuniecie - PION == 16)) || ((pion_przesuniecie - POZIOM == 16) && (poziom_przesuniecie - PION == -16)) || ((pion_przesuniecie - POZIOM == -17) && (poziom_przesuniecie - PION == -17)) || ((pion_przesuniecie - POZIOM == -17) && (poziom_przesuniecie - PION == 17)) || /*tu*/ ((pion_przesuniecie - POZIOM == 17) && (poziom_przesuniecie - PION == 17)) || ((pion_przesuniecie - POZIOM == 17) && (poziom_przesuniecie - PION == -17)) || ((pion_przesuniecie - POZIOM == -18) && (poziom_przesuniecie - PION == -18)) || ((pion_przesuniecie - POZIOM == -18) && (poziom_przesuniecie - PION == 18)) || /*tu*/ ((pion_przesuniecie - POZIOM == 18) && (poziom_przesuniecie - PION == 18)) || ((pion_przesuniecie - POZIOM == 18) && (poziom_przesuniecie - PION == -18)) || ((pion_przesuniecie - POZIOM == -19) && (poziom_przesuniecie - PION == -19)) || ((pion_przesuniecie - POZIOM == -19) && (poziom_przesuniecie - PION == 19)) || /*tu*/ ((pion_przesuniecie - POZIOM == 19) && (poziom_przesuniecie - PION == 19)) || ((pion_przesuniecie - POZIOM == 19) && (poziom_przesuniecie - PION == -19)) || ((pion_przesuniecie - POZIOM == -20) && (poziom_przesuniecie - PION == -20)) || ((pion_przesuniecie - POZIOM == -20) && (poziom_przesuniecie - PION == 20)) || /*tu*/ ((pion_przesuniecie - POZIOM == 20) && (poziom_przesuniecie - PION == 20)) || ((pion_przesuniecie - POZIOM == 20) && (poziom_przesuniecie - PION == -20)) || ((pion_przesuniecie - POZIOM == -21) && (poziom_przesuniecie - PION == -21)) || ((pion_przesuniecie - POZIOM == -21) && (poziom_przesuniecie - PION == 21)) || /*tu*/ ((pion_przesuniecie - POZIOM == 21) && (poziom_przesuniecie - PION == 21)) || ((pion_przesuniecie - POZIOM == 21) && (poziom_przesuniecie - PION == -21)) || ((pion_przesuniecie - POZIOM == -22) && (poziom_przesuniecie - PION == -22)) || ((pion_przesuniecie - POZIOM == -22) && (poziom_przesuniecie - PION == 22)) || /*tu*/ ((pion_przesuniecie - POZIOM == 22) && (poziom_przesuniecie - PION == 22)) || ((pion_przesuniecie - POZIOM == 22) && (poziom_przesuniecie - PION == -22)) || ((pion_przesuniecie - POZIOM == -23) && (poziom_przesuniecie - PION == -23)) || ((pion_przesuniecie - POZIOM == -23) && (poziom_przesuniecie - PION == 23)) || /*tu*/ ((pion_przesuniecie - POZIOM == 23) && (poziom_przesuniecie - PION == 23)) || ((pion_przesuniecie - POZIOM == 23) && (poziom_przesuniecie - PION == -23)) || ((pion_przesuniecie - POZIOM == -24) && (poziom_przesuniecie - PION == -24)) || ((pion_przesuniecie - POZIOM == -24) && (poziom_przesuniecie - PION == 24)) || /*tu*/ ((pion_przesuniecie - POZIOM == 24) && (poziom_przesuniecie - PION == 24)) || ((pion_przesuniecie - POZIOM == 24) && (poziom_przesuniecie - PION == -24)) || ((pion_przesuniecie - POZIOM == -25) && (poziom_przesuniecie - PION == -25)) || ((pion_przesuniecie - POZIOM == -25) && (poziom_przesuniecie - PION == 25)) || /*tu*/ ((pion_przesuniecie - POZIOM == 25) && (poziom_przesuniecie - PION == 25)) || ((pion_przesuniecie - POZIOM == 25) && (poziom_przesuniecie - PION == -25)) || ((pion_przesuniecie - POZIOM == -26) && (poziom_przesuniecie - PION == -26)) || ((pion_przesuniecie - POZIOM == -26) && (poziom_przesuniecie - PION == 26)) || /*tu*/ ((pion_przesuniecie - POZIOM == 26) && (poziom_przesuniecie - PION == 26)) || ((pion_przesuniecie - POZIOM == 26) && (poziom_przesuniecie - PION == -26)) || ((pion_przesuniecie - POZIOM == -27) && (poziom_przesuniecie - PION == -27)) || ((pion_przesuniecie - POZIOM == -27) && (poziom_przesuniecie - PION == 27)) || /*tu*/ ((pion_przesuniecie - POZIOM == 27) && (poziom_przesuniecie - PION == 27)) || ((pion_przesuniecie - POZIOM == 27) && (poziom_przesuniecie - PION == -27)) || ((pion_przesuniecie - POZIOM == -28) && (poziom_przesuniecie - PION == -28)) || ((pion_przesuniecie - POZIOM == -28) && (poziom_przesuniecie - PION == 28)) || /*tu*/ ((pion_przesuniecie - POZIOM == 28) && (poziom_przesuniecie - PION == 28)) || ((pion_przesuniecie - POZIOM == 28) && (poziom_przesuniecie - PION == -28)) || ((pion_przesuniecie - POZIOM == -29) && (poziom_przesuniecie - PION == -29)) || ((pion_przesuniecie - POZIOM == -29) && (poziom_przesuniecie - PION == 29)) || /*tu*/ ((pion_przesuniecie - POZIOM == 29) && (poziom_przesuniecie - PION == 29)) || ((pion_przesuniecie - POZIOM == 29) && (poziom_przesuniecie - PION == -29)))
							{
								licznik_pionkow_czarnych--;
								if ((pion_p - POZIOM == 0) || (pion_p - POZIOM <= 0))
								{
									if ((poziom_p - PION == 0) || (poziom_p - PION <= 0))
									{
										if (plansza[pion_p_2][poziom_p_2] == 3)
										{
											system("cls");
											cout << "nie mozna zbic";
											blad++;
											goto z;
										}
										else
										{
											plansza[pion_p_2][poziom_p_2] = 5;
										}
									}

									else
									{
										if (plansza[pion_p_2][poziom_p] == 3)
										{
											system("cls");
											cout << "nie mozna zbic";
											blad++;
											goto z;
										}
										else
										{
											plansza[pion_p_2][poziom_p] = 5;
										}
									}
								}
								else
								{
									if ((poziom_p - PION == 0) || (poziom_p - PION <= 0))
									{
										if (plansza[pion_p][poziom_p_2] == 3)
										{
											system("cls");
											cout << "nie mozna zbic";
											blad++;
											goto z;
										}
										else if (plansza[pion_p][poziom_p_2] == 1)
										{
											if (j == a-2)
											{
												plansza[pion_p][poziom_p_2] = 5;
											}
											else
											{
												plansza[pion_p][poziom_p_2] = 5;
											}
										}

									}

									else
									{
										if (plansza[pion_p][poziom_p] == 3)
										{
											system("cls");
											cout << "nie mozna zbic";
											blad++;
											goto z;
										}
										else if (plansza[pion_p][poziom_p] == 1)
										{
											if (j == a-2)
											{
												plansza[pion_p][poziom_p] = 5;
											}
											else
											{
												plansza[pion_p][poziom_p] = 5;
											}
										}
									}
								}



								// -----------
								if (plansza[j][i] == 0)
								{
									cout << "Blad";
									blad++;
									goto z;
								}

								else
								{
									if (kolor == 2)
									{
										plansza[j][i] = 1;
									}
									else
									{
										plansza[j][i] = 1;
									}

								}
							}
							else
							{
								system("cls");
								cout << "damka nie jest wrzechmocna";
								blad++;
								goto z;
							}


						}
						else
						{
							if (((pion_przesuniecie - POZIOM == -1) && (poziom_przesuniecie - PION == -1)) || ((pion_przesuniecie - POZIOM == -1) && (poziom_przesuniecie - PION == 1)) || /*tu*/ ((pion_przesuniecie - POZIOM == 1) && (poziom_przesuniecie - PION == 1)) || ((pion_przesuniecie - POZIOM == 1) && (poziom_przesuniecie - PION == -1)) || ((pion_przesuniecie - POZIOM == -2) && (poziom_przesuniecie - PION == -2)) || ((pion_przesuniecie - POZIOM == -2) && (poziom_przesuniecie - PION == 2)) || /*tu*/ ((pion_przesuniecie - POZIOM == 2) && (poziom_przesuniecie - PION == 2)) || ((pion_przesuniecie - POZIOM == 2) && (poziom_przesuniecie - PION == -2)) || ((pion_przesuniecie - POZIOM == -3) && (poziom_przesuniecie - PION == -3)) || ((pion_przesuniecie - POZIOM == -3) && (poziom_przesuniecie - PION == 3)) || /*tu*/ ((pion_przesuniecie - POZIOM == 3) && (poziom_przesuniecie - PION == 3)) || ((pion_przesuniecie - POZIOM == 3) && (poziom_przesuniecie - PION == -3)) || ((pion_przesuniecie - POZIOM == -4) && (poziom_przesuniecie - PION == -4)) || ((pion_przesuniecie - POZIOM == -4) && (poziom_przesuniecie - PION == 4)) || /*tu*/ ((pion_przesuniecie - POZIOM == 4) && (poziom_przesuniecie - PION == 4)) || ((pion_przesuniecie - POZIOM == 4) && (poziom_przesuniecie - PION == -4)) || ((pion_przesuniecie - POZIOM == -5) && (poziom_przesuniecie - PION == -5)) || ((pion_przesuniecie - POZIOM == -5) && (poziom_przesuniecie - PION == 5)) || /*tu*/ ((pion_przesuniecie - POZIOM == 5) && (poziom_przesuniecie - PION == 5)) || ((pion_przesuniecie - POZIOM == 5) && (poziom_przesuniecie - PION == -5)) || ((pion_przesuniecie - POZIOM == -6) && (poziom_przesuniecie - PION == -6)) || ((pion_przesuniecie - POZIOM == -6) && (poziom_przesuniecie - PION == 6)) || /*tu*/ ((pion_przesuniecie - POZIOM == 6) && (poziom_przesuniecie - PION == 6)) || ((pion_przesuniecie - POZIOM == 6) && (poziom_przesuniecie - PION == -6)) || ((pion_przesuniecie - POZIOM == -7) && (poziom_przesuniecie - PION == -7)) || ((pion_przesuniecie - POZIOM == -7) && (poziom_przesuniecie - PION == 7)) || /*tu*/ ((pion_przesuniecie - POZIOM == 7) && (poziom_przesuniecie - PION == 7)) || ((pion_przesuniecie - POZIOM == 7) && (poziom_przesuniecie - PION == -7)) || ((pion_przesuniecie - POZIOM == -8) && (poziom_przesuniecie - PION == -8)) || ((pion_przesuniecie - POZIOM == -8) && (poziom_przesuniecie - PION == 8)) || /*tu*/ ((pion_przesuniecie - POZIOM == 8) && (poziom_przesuniecie - PION == 8)) || ((pion_przesuniecie - POZIOM == 8) && (poziom_przesuniecie - PION == -8)) || ((pion_przesuniecie - POZIOM == -9) && (poziom_przesuniecie - PION == -9)) || ((pion_przesuniecie - POZIOM == -9) && (poziom_przesuniecie - PION == 9)) || /*tu*/ ((pion_przesuniecie - POZIOM == 9) && (poziom_przesuniecie - PION == 9)) || ((pion_przesuniecie - POZIOM == 9) && (poziom_przesuniecie - PION == -9)) || ((pion_przesuniecie - POZIOM == -10) && (poziom_przesuniecie - PION == -10)) || ((pion_przesuniecie - POZIOM == -10) && (poziom_przesuniecie - PION == 10)) || /*tu*/ ((pion_przesuniecie - POZIOM == 10) && (poziom_przesuniecie - PION == 10)) || ((pion_przesuniecie - POZIOM == 10) && (poziom_przesuniecie - PION == -10)) || ((pion_przesuniecie - POZIOM == -11) && (poziom_przesuniecie - PION == -11)) || ((pion_przesuniecie - POZIOM == -11) && (poziom_przesuniecie - PION == 11)) || /*tu*/ ((pion_przesuniecie - POZIOM == 11) && (poziom_przesuniecie - PION == 11)) || ((pion_przesuniecie - POZIOM == 11) && (poziom_przesuniecie - PION == -11)) || ((pion_przesuniecie - POZIOM == -12) && (poziom_przesuniecie - PION == -12)) || ((pion_przesuniecie - POZIOM == -12) && (poziom_przesuniecie - PION == 12)) || /*tu*/ ((pion_przesuniecie - POZIOM == 12) && (poziom_przesuniecie - PION == 12)) || ((pion_przesuniecie - POZIOM == 12) && (poziom_przesuniecie - PION == -12)) || ((pion_przesuniecie - POZIOM == -13) && (poziom_przesuniecie - PION == -13)) || ((pion_przesuniecie - POZIOM == -13) && (poziom_przesuniecie - PION == 13)) || /*tu*/ ((pion_przesuniecie - POZIOM == 13) && (poziom_przesuniecie - PION == 13)) || ((pion_przesuniecie - POZIOM == 13) && (poziom_przesuniecie - PION == -13)) || ((pion_przesuniecie - POZIOM == -14) && (poziom_przesuniecie - PION == -14)) || ((pion_przesuniecie - POZIOM == -14) && (poziom_przesuniecie - PION == 14)) || /*tu*/ ((pion_przesuniecie - POZIOM == 14) && (poziom_przesuniecie - PION == 14)) || ((pion_przesuniecie - POZIOM == 14) && (poziom_przesuniecie - PION == -14)) || ((pion_przesuniecie - POZIOM == -15) && (poziom_przesuniecie - PION == -15)) || ((pion_przesuniecie - POZIOM == -15) && (poziom_przesuniecie - PION == 15)) || /*tu*/ ((pion_przesuniecie - POZIOM == 15) && (poziom_przesuniecie - PION == 15)) || ((pion_przesuniecie - POZIOM == 15) && (poziom_przesuniecie - PION == -15)) || ((pion_przesuniecie - POZIOM == -16) && (poziom_przesuniecie - PION == -16)) || ((pion_przesuniecie - POZIOM == -16) && (poziom_przesuniecie - PION == 16)) || /*tu*/ ((pion_przesuniecie - POZIOM == 16) && (poziom_przesuniecie - PION == 16)) || ((pion_przesuniecie - POZIOM == 16) && (poziom_przesuniecie - PION == -16)) || ((pion_przesuniecie - POZIOM == -17) && (poziom_przesuniecie - PION == -17)) || ((pion_przesuniecie - POZIOM == -17) && (poziom_przesuniecie - PION == 17)) || /*tu*/ ((pion_przesuniecie - POZIOM == 17) && (poziom_przesuniecie - PION == 17)) || ((pion_przesuniecie - POZIOM == 17) && (poziom_przesuniecie - PION == -17)) || ((pion_przesuniecie - POZIOM == -18) && (poziom_przesuniecie - PION == -18)) || ((pion_przesuniecie - POZIOM == -18) && (poziom_przesuniecie - PION == 18)) || /*tu*/ ((pion_przesuniecie - POZIOM == 18) && (poziom_przesuniecie - PION == 18)) || ((pion_przesuniecie - POZIOM == 18) && (poziom_przesuniecie - PION == -18)) || ((pion_przesuniecie - POZIOM == -19) && (poziom_przesuniecie - PION == -19)) || ((pion_przesuniecie - POZIOM == -19) && (poziom_przesuniecie - PION == 19)) || /*tu*/ ((pion_przesuniecie - POZIOM == 19) && (poziom_przesuniecie - PION == 19)) || ((pion_przesuniecie - POZIOM == 19) && (poziom_przesuniecie - PION == -19)) || ((pion_przesuniecie - POZIOM == -20) && (poziom_przesuniecie - PION == -20)) || ((pion_przesuniecie - POZIOM == -20) && (poziom_przesuniecie - PION == 20)) || /*tu*/ ((pion_przesuniecie - POZIOM == 20) && (poziom_przesuniecie - PION == 20)) || ((pion_przesuniecie - POZIOM == 20) && (poziom_przesuniecie - PION == -20)) || ((pion_przesuniecie - POZIOM == -21) && (poziom_przesuniecie - PION == -21)) || ((pion_przesuniecie - POZIOM == -21) && (poziom_przesuniecie - PION == 21)) || /*tu*/ ((pion_przesuniecie - POZIOM == 21) && (poziom_przesuniecie - PION == 21)) || ((pion_przesuniecie - POZIOM == 21) && (poziom_przesuniecie - PION == -21)) || ((pion_przesuniecie - POZIOM == -22) && (poziom_przesuniecie - PION == -22)) || ((pion_przesuniecie - POZIOM == -22) && (poziom_przesuniecie - PION == 22)) || /*tu*/ ((pion_przesuniecie - POZIOM == 22) && (poziom_przesuniecie - PION == 22)) || ((pion_przesuniecie - POZIOM == 22) && (poziom_przesuniecie - PION == -22)) || ((pion_przesuniecie - POZIOM == -23) && (poziom_przesuniecie - PION == -23)) || ((pion_przesuniecie - POZIOM == -23) && (poziom_przesuniecie - PION == 23)) || /*tu*/ ((pion_przesuniecie - POZIOM == 23) && (poziom_przesuniecie - PION == 23)) || ((pion_przesuniecie - POZIOM == 23) && (poziom_przesuniecie - PION == -23)) || ((pion_przesuniecie - POZIOM == -24) && (poziom_przesuniecie - PION == -24)) || ((pion_przesuniecie - POZIOM == -24) && (poziom_przesuniecie - PION == 24)) || /*tu*/ ((pion_przesuniecie - POZIOM == 24) && (poziom_przesuniecie - PION == 24)) || ((pion_przesuniecie - POZIOM == 24) && (poziom_przesuniecie - PION == -24)) || ((pion_przesuniecie - POZIOM == -25) && (poziom_przesuniecie - PION == -25)) || ((pion_przesuniecie - POZIOM == -25) && (poziom_przesuniecie - PION == 25)) || /*tu*/ ((pion_przesuniecie - POZIOM == 25) && (poziom_przesuniecie - PION == 25)) || ((pion_przesuniecie - POZIOM == 25) && (poziom_przesuniecie - PION == -25)) || ((pion_przesuniecie - POZIOM == -26) && (poziom_przesuniecie - PION == -26)) || ((pion_przesuniecie - POZIOM == -26) && (poziom_przesuniecie - PION == 26)) || /*tu*/ ((pion_przesuniecie - POZIOM == 26) && (poziom_przesuniecie - PION == 26)) || ((pion_przesuniecie - POZIOM == 26) && (poziom_przesuniecie - PION == -26)) || ((pion_przesuniecie - POZIOM == -27) && (poziom_przesuniecie - PION == -27)) || ((pion_przesuniecie - POZIOM == -27) && (poziom_przesuniecie - PION == 27)) || /*tu*/ ((pion_przesuniecie - POZIOM == 27) && (poziom_przesuniecie - PION == 27)) || ((pion_przesuniecie - POZIOM == 27) && (poziom_przesuniecie - PION == -27)) || ((pion_przesuniecie - POZIOM == -28) && (poziom_przesuniecie - PION == -28)) || ((pion_przesuniecie - POZIOM == -28) && (poziom_przesuniecie - PION == 28)) || /*tu*/ ((pion_przesuniecie - POZIOM == 28) && (poziom_przesuniecie - PION == 28)) || ((pion_przesuniecie - POZIOM == 28) && (poziom_przesuniecie - PION == -28)) || ((pion_przesuniecie - POZIOM == -29) && (poziom_przesuniecie - PION == -29)) || ((pion_przesuniecie - POZIOM == -29) && (poziom_przesuniecie - PION == 29)) || /*tu*/ ((pion_przesuniecie - POZIOM == 29) && (poziom_przesuniecie - PION == 29)) || ((pion_przesuniecie - POZIOM == 29) && (poziom_przesuniecie - PION == -29)))
							{
								if (plansza[j][i] == 0)
								{
									cout << "Blad";
									blad++;
									goto z;
								}

								if ((plansza[j][i] == 2) || (plansza[j][i] == 5))
								{
									cout << "Blad , nie mozna bic swojego";
									blad++;
									goto z;
								}

								else
								{
									if (kolor == 2)
									{
										plansza[j][i] = 5;
									}
									else
									{
										plansza[j][i] = 5;
									}

								}
							}
							else
							{
								system("cls");
								cout << "damka nie jest wrzechmocna";
								blad++;
								goto z;
							}

						}


					}

				}
			}
		}
		kolejne_rysowania(plansza, a, b);
	}

}
