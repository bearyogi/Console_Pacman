#include <iostream>
#include <stdio.h>
#include "conio.h"
#include <limits>
#include <stdexcept>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <math.h>



using namespace std;

int minimalna(int tab[])
{
    int minimalna = tab[0];
    for (int i = 0; i < 4; i++)
    {
        if (tab[i] < minimalna)
            minimalna = tab[i];
    }
    return minimalna;
}

int minimalna2(int tab[], int minimalna)
{
    int minimalna2 = 500000000000000;
    int a = 0;
    for (int i = 0; i < 4; i++)
    {
        if (minimalna == tab[i] && a == 0)
        {
            a++;
            continue;
        }

        if (tab[i] < minimalna2)
            minimalna2 = tab[i];
    }
    return minimalna2;

}

int minimalna3(int tab[], int minimalna, int minimalna2)
{
    int minimalna3 = 500000000000000;

    for (int i = 0; i < 4; i++)
    {
        if (minimalna == tab[i] || minimalna2 == tab[i])
            continue;
        if (tab[i] < minimalna3)
            minimalna3 = tab[i];
    }
    return minimalna3;
}

int minimalna4(int tab[], int minimalna, int minimalna2, int minimalna3)
{
    int minimalna4 = 500000000000000;

    for (int i = 0; i < 4; i++)
    {
        if (minimalna == tab[i] || minimalna2 == tab[i] || minimalna3 == tab[i])
            continue;
        if (tab[i] < minimalna4)
            minimalna4 = tab[i];
    }
    return minimalna4;
}


string PL(const char* text)
{
    std::string result;
    for (; *text; text++)
        switch (*text)
        {
        case 'ą': result += static_cast <char>(0xa5); break;
        case 'ć': result += static_cast <char>(0x86); break;
        case 'ę': result += static_cast <char>(0xa9); break;
        case 'ł': result += static_cast <char>(0x88); break;
        case 'ń': result += static_cast <char>(0xe4); break;
        case 'ó': result += static_cast <char>(0xa2); break;
        case 'ś': result += static_cast <char>(0x98); break;
        case 'ż': result += static_cast <char>(0xbe); break;
        case 'ź': result += static_cast <char>(0xab); break;
        case 'Ą': result += static_cast <char>(0xa4); break;
        case 'Ć': result += static_cast <char>(0x8f); break;
        case 'Ę': result += static_cast <char>(0xa8); break;
        case 'Ł': result += static_cast <char>(0x9d); break;
        case 'Ń': result += static_cast <char>(0xe3); break;
        case 'Ó': result += static_cast <char>(0xe0); break;
        case 'Ś': result += static_cast <char>(0x97); break;
        case 'Ż': result += static_cast <char>(0xbd); break;
        case 'Ź': result += static_cast <char>(0x8d); break;
        default: result += *text; break;
        }
    return result;
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
void SetWindow(int Width, int Height)
{
    _COORD coord;
    coord.X = Width;
    coord.Y = Height;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height;
    Rect.Right = Width;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(Handle, coord);
    SetConsoleWindowInfo(Handle, TRUE, &Rect);
}
void SetWindow1(int Width, int Height)
{
    _COORD coord;
    coord.X = Width;
    coord.Y = Height;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height - 1;
    Rect.Right = Width - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
    SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}

void remove_scrollbar()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size =
    {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    SetConsoleScreenBufferSize(handle, new_size);
}

void gotoxy(int  x, int  y)
{
    COORD p = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
void pup()
{
    HANDLE hConsole;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY);


}

void pac()
{
    HANDLE hConsole;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN);


}

void d()
{
    HANDLE hConsole;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_INTENSITY);
}
void duch()
{
    HANDLE hConsole;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
}
void def()
{
    HANDLE hConsole;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, BACKGROUND_BLUE & BACKGROUND_RED);
}
void zielony()
{
    HANDLE hConsole;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, BACKGROUND_GREEN | BACKGROUND_INTENSITY);
}
void drzwi()
{
    HANDLE hConsole;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, BACKGROUND_GREEN | BACKGROUND_RED);
}
void fio()
{
    HANDLE hConsole;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, BACKGROUND_BLUE | BACKGROUND_RED);
}
void pur()
{
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute

    (hConsole, BACKGROUND_RED | BACKGROUND_INTENSITY);
}
void pacnap()
{
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute

    (hConsole, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
}
void ram()
{
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute

    (hConsole, BACKGROUND_RED);
    pur();
    cout << "  ";
    def();
    cout << "                                                                             ";
    pur();
    cout << "  ";
    def();
}
void red()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    GetConsoleScreenBufferInfo(h, &csbiInfo);
    wOldColorAttrs = csbiInfo.wAttributes;

    SetConsoleTextAttribute(h, BACKGROUND_INTENSITY);

}
void red1()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    GetConsoleScreenBufferInfo(h, &csbiInfo);
    wOldColorAttrs = csbiInfo.wAttributes;

    SetConsoleTextAttribute(h, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY);

}
void reds()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    GetConsoleScreenBufferInfo(h, &csbiInfo);
    wOldColorAttrs = csbiInfo.wAttributes;

    SetConsoleTextAttribute(h, FOREGROUND_INTENSITY);

}
void zlo()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    GetConsoleScreenBufferInfo(h, &csbiInfo);
    wOldColorAttrs = csbiInfo.wAttributes;

    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
}
void bia()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    GetConsoleScreenBufferInfo(h, &csbiInfo);
    wOldColorAttrs = csbiInfo.wAttributes;

    SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
}
void rams()
{
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute

    (hConsole, BACKGROUND_RED);
    red();
    cout << "  ";
    def();
    cout << "                                                                             ";
    red();
    cout << "  ";
}
void rams1()
{
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute

    (hConsole, BACKGROUND_RED);
    red();
    cout << "  ";
    def();
    cout << "                                                                             ";
    red();
    cout << "  ";
}
void blu()
{
    HANDLE hConsole;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, BACKGROUND_BLUE);
}
void napis()
{
    gotoxy(8, 5);
    pacnap();
    cout << "          ";
    def();
    gotoxy(21, 5);
    pacnap();
    cout << "          ";
    def();
    gotoxy(34, 5);
    pacnap();
    cout << "          ";
    def();
    gotoxy(8, 6);
    pacnap();
    cout << "  ";
    def();
    gotoxy(16, 6);
    pacnap();
    cout << "  ";
    def();
    gotoxy(21, 6);
    pacnap();
    cout << "  ";
    def();
    gotoxy(29, 6);
    pacnap();
    cout << "  ";
    def();
    gotoxy(34, 6);
    pacnap();
    cout << "  ";
    def();
    gotoxy(42, 6);
    pacnap();
    cout << "  ";
    def();
    gotoxy(8, 7);
    pacnap();
    cout << "  ";
    def();
    gotoxy(16, 7);
    pacnap();
    cout << "  ";
    def();
    gotoxy(21, 7);
    pacnap();
    cout << "  ";
    def();
    gotoxy(29, 7);
    pacnap();
    cout << "  ";
    def();
    gotoxy(34, 7);
    pacnap();
    cout << "  ";
    def();
    gotoxy(8, 8);
    pacnap();
    cout << "  ";
    def();
    gotoxy(16, 8);
    pacnap();
    cout << "  ";
    def();
    gotoxy(21, 8);
    pacnap();
    cout << "  ";
    def();
    gotoxy(29, 8);
    pacnap();
    cout << "  ";
    def();
    gotoxy(34, 8);
    pacnap();
    cout << "  ";
    def();
    gotoxy(8, 9);
    pacnap();
    cout << "  ";
    def();
    gotoxy(16, 9);
    pacnap();
    cout << "  ";
    def();
    gotoxy(21, 9);
    pacnap();
    cout << "  ";
    def();
    gotoxy(29, 9);
    pacnap();
    cout << "  ";
    def();
    gotoxy(34, 9);
    pacnap();
    cout << "  ";
    def();
    gotoxy(8, 10);
    pacnap();
    cout << "  ";
    def();
    gotoxy(16, 10);
    pacnap();
    cout << "  ";
    def();
    gotoxy(21, 10);
    pacnap();
    cout << "  ";
    def();
    gotoxy(29, 10);
    pacnap();
    cout << "  ";
    def();
    gotoxy(34, 10);
    pacnap();
    cout << "  ";
    def();
    gotoxy(8, 11);
    pacnap();
    cout << "          ";
    def();
    gotoxy(21, 11);
    pacnap();
    cout << "          ";
    def();
    gotoxy(34, 11);
    pacnap();
    cout << "  ";
    def();
    for (int a = 12; a < 18; a++)
    {
        gotoxy(8, a);
        pacnap();
        cout << "  ";
        def();
        gotoxy(21, a);
        pacnap();
        cout << "  ";
        def();
        gotoxy(29, a);
        pacnap();
        cout << "  ";
        def();
        gotoxy(34, a);
        pacnap();
        cout << "  ";
        def();

    }
    gotoxy(8, 18);
    pacnap();
    cout << "  ";
    def();
    gotoxy(21, 18);
    pacnap();
    cout << "  ";
    def();
    gotoxy(29, 18);
    pacnap();
    cout << "  ";
    def();
    gotoxy(34, 18);
    pacnap();
    cout << "  ";
    def();
    gotoxy(42, 18);
    pacnap();
    cout << "  ";
    def();
    gotoxy(8, 19);
    pacnap();
    cout << "  ";
    def();
    gotoxy(21, 19);
    pacnap();
    cout << "  ";
    def();
    gotoxy(29, 19);
    pacnap();
    cout << "  ";
    def();
    gotoxy(34, 19);
    pacnap();
    cout << "          ";
    def();
    for (int a = 22; a <= 36; a++)
    {
        gotoxy(40, a);
        pacnap();
        cout << "  ";
        def();
        gotoxy(50, a);
        pacnap();
        cout << "  ";
        def();
        gotoxy(54, a);
        pacnap();
        cout << "  ";
        def();
        gotoxy(58, a);
        pacnap();
        cout << "  ";
        def();
        gotoxy(62, a);
        pacnap();
        cout << "  ";
        def();
        gotoxy(70, a);
        pacnap();
        cout << "  ";
        def();
    }
    gotoxy(42, 24);
    pacnap();
    cout << "  ";
    def();
    gotoxy(42, 25);
    pacnap();
    cout << "  ";
    def();
    gotoxy(48, 24);
    pacnap();
    cout << "  ";
    def();
    gotoxy(48, 25);
    pacnap();
    cout << "  ";
    def();
    gotoxy(43, 26);
    pacnap();
    cout << "  ";
    def();
    gotoxy(43, 27);
    pacnap();
    cout << "  ";
    def();
    gotoxy(47, 26);
    pacnap();
    cout << "  ";
    def();
    gotoxy(47, 27);
    pacnap();
    cout << "  ";
    def();
    gotoxy(45, 28);
    pacnap();
    cout << "  ";
    def();
    gotoxy(45, 29);
    pacnap();
    cout << "  ";
    def();
    gotoxy(56, 22);
    pacnap();
    cout << "  ";
    def();
    gotoxy(56, 30);
    pacnap();
    cout << "  ";
    def();


    gotoxy(64, 24);
    pacnap();
    cout << "  ";
    def();
    gotoxy(64, 25);
    pacnap();
    cout << "  ";
    def();
    gotoxy(65, 26);
    pacnap();
    cout << "  ";
    def();
    gotoxy(65, 27);
    pacnap();
    cout << "  ";
    def();
    gotoxy(66, 28);
    pacnap();
    cout << "  ";
    def();
    gotoxy(66, 29);
    pacnap();
    cout << "  ";
    def();
    gotoxy(67, 30);
    pacnap();
    cout << "  ";
    def();
    gotoxy(67, 31);
    pacnap();
    cout << "  ";
    def();
    gotoxy(68, 32);
    pacnap();
    cout << "  ";
    def();
    gotoxy(68, 33);
    pacnap();
    cout << "  ";
    def();
    gotoxy(69, 34);
    pacnap();
    cout << "  ";
    def();
    gotoxy(69, 35);
    pacnap();
    cout << "  ";
    def();

    gotoxy(39, 8);
    pur();
    cout << "  ";
    def();
    gotoxy(37, 9);
    pur();
    cout << "      ";
    def();
    gotoxy(39, 10);
    pur();
    cout << "  ";
    def();

    gotoxy(39, 13);
    pur();
    cout << "  ";
    def();
    gotoxy(37, 14);
    pur();
    cout << "      ";
    def();
    gotoxy(39, 15);
    pur();
    cout << "  ";
    def();
}




void pizza()
{
    gotoxy(55, 4);
    pup();
    cout << "      ";
    def();
    gotoxy(51, 5);
    pup();
    cout << "              ";
    def();
    gotoxy(49, 6);
    pup();
    cout << "                  ";
    def();
    gotoxy(47, 7);
    pup();
    cout << "                      ";
    def();
    gotoxy(45, 8);
    pup();
    cout << "                        ";
    def();
    gotoxy(45, 9);
    pup();
    cout << "                    ";
    def();
    gotoxy(45, 10);
    pup();
    cout << "                ";
    def();
    gotoxy(45, 11);
    pup();
    cout << "              ";
    def();
    gotoxy(45, 12);
    pup();
    cout << "                ";
    def();
    gotoxy(45, 13);
    pup();
    cout << "                    ";
    def();
    gotoxy(45, 14);
    pup();
    cout << "                        ";
    def();
    gotoxy(47, 15);
    pup();
    cout << "                      ";
    def();
    gotoxy(49, 16);
    pup();
    cout << "                  ";
    def();
    gotoxy(51, 17);
    pup();
    cout << "              ";
    def();
    gotoxy(55, 18);
    pup();
    cout << "      ";
    def();
    gotoxy(55, 8);
    def();
    cout << "  ";
    def();
    gotoxy(53, 9);
    def();
    cout << "  ";
    def();
    gotoxy(57, 9);
    def();
    cout << "  ";
    def();
}
void pizza1()
{
    gotoxy(55, 4);
    pup();
    cout << "      ";
    def();
    gotoxy(51, 5);
    pup();
    cout << "              ";
    def();
    gotoxy(49, 6);
    pup();
    cout << "                  ";
    def();
    gotoxy(47, 7);
    pup();
    cout << "                      ";
    def();
    gotoxy(45, 8);
    pup();
    cout << "                        ";
    def();
    gotoxy(45, 9);
    pup();
    cout << "                        ";
    def();
    gotoxy(45, 10);
    pup();
    cout << "                        ";
    def();
    gotoxy(45, 11);
    pup();
    cout << "                        ";
    def();
    gotoxy(45, 12);
    pup();
    cout << "                        ";
    def();
    gotoxy(45, 13);
    pup();
    cout << "                        ";
    def();
    gotoxy(45, 14);
    pup();
    cout << "                        ";
    def();
    gotoxy(47, 15);
    pup();
    cout << "                      ";
    def();
    gotoxy(49, 16);
    pup();
    cout << "                  ";
    def();
    gotoxy(51, 17);
    pup();
    cout << "              ";
    def();
    gotoxy(55, 18);
    pup();
    cout << "      ";
    def();
    gotoxy(55, 8);
    def();
    cout << "  ";
    def();
    gotoxy(59, 11);
    def();
    cout << "          ";
    def();
}
void nick(string& name)
{
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    do
    {
        gotoxy(19, 16);
        cout << "====================================" << endl;
        gotoxy(19, 17);
        cout << "WPISZ NAZW" << PL("Ę") << " GRACZA: " << endl;
        gotoxy(19, 18);
        cout << "====================================" << endl;
        gotoxy(38, 17);
        cin >> name;
    } while (name.empty() != 0);
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    system("cls");
}

void tytul()
{
    gotoxy(25, 23);
    cout << " MADE BY Y&M STUDIO ~ 2016 ";
    gotoxy(37, 8);
    cout << "G";
    Beep(600, 500);
    cout << "R";
    Beep(600, 500);
    cout << "A";
    Beep(600, 500);
    gotoxy(25, 10);
    cout << "J";
    Beep(300, 200);
    Sleep(50);
    cout << "A";
    Beep(300, 200);
    Sleep(50);
    cout << "K";
    Beep(300, 200);
    Sleep(50);
    cout << "I";
    Beep(300, 200);
    Sleep(50);
    cout << "E";
    Beep(300, 200);
    Sleep(50);
    cout << "J";
    Beep(300, 200);
    Sleep(50);
    cout << " ";
    Beep(300, 200);
    Sleep(50);
    cout << PL("Ś");
    Sleep(50);
    cout << "W";
    Beep(300, 200);
    Sleep(50);
    cout << "I";
    Beep(300, 200);
    Sleep(50);
    cout << "A";
    Beep(300, 200);
    Sleep(50);
    cout << "T";
    Beep(300, 200);
    Sleep(50);
    cout << " ";
    Beep(300, 200);
    Sleep(50);
    cout << "N";
    Beep(300, 200);
    Sleep(50);
    cout << "I";
    Beep(300, 200);
    Sleep(50);
    cout << "E";
    Beep(300, 200);
    Sleep(50);
    cout << " ";
    Beep(300, 200);
    Sleep(50);
    cout << "W";
    Beep(300, 200);
    Sleep(50);
    cout << "I";
    Sleep(50);
    cout << "D";
    Beep(300, 200);
    Sleep(50);
    cout << "Z";
    Beep(300, 200);
    Sleep(50);
    cout << "I";
    Beep(300, 200);
    Sleep(50);
    cout << "A";
    Beep(300, 200);
    Sleep(50);
    cout << PL("Ł");
    Beep(300, 200);
    Sleep(50);
    cout << ".";
    Sleep(3000);
    system("cls");

}
void rysuj(int  a, int  b)
{
    gotoxy(a, b);
    cout << "#";
    return;
}

void rysuj2(int  a, int  b)
{
    gotoxy(a, b);
    cout << "=";
    return;
}
void rysuj3(int  a, int  b)
{
    gotoxy(a, b);
    cout << "|" << "|";
    return;
}
void rysuj4(int  a, int  b)
{
    gotoxy(a, b);
    cout << "|";
    return;
}
void obramowka()
{
    for (int i = 4; i <= 14; i++)
    {
        if (i == 4 || i == 14)

        {
            for (int j = 19; j < 56; j++)
                rysuj2(j, i);
        }
        rysuj3(19, i);
        rysuj3(56, i);
    }

}
void autorzy()
{
    system("color 1E");
    gotoxy(30, 4);
    cout << "========================" << endl;
    gotoxy(30, 5);
    cout << "        Autorzy" << endl;
    gotoxy(30, 6);
    cout << "========================" << endl;
    gotoxy(3, 11);
    cout << "                         Ta mniej niska -  Julia Fidor";
    gotoxy(3, 13);
    cout << "                   Ta co robi ciasto w nagrode - Kinga Bazak";
    gotoxy(3, 38);
    cout << "                            (Iiiiii reszta roboli....)";
}
void ta()
{
    gotoxy(10, 21);
    blu(); cout << "                           ";
    gotoxy(0, 22);
    for (int a = 22; a < 35; a++)
    {
        if (a <= 24 && a >= 34)
        {
            gotoxy(9, a);
            blu(); cout << "   "; def(); cout << "                       "; blu(); cout << "   "; def();
            gotoxy(0, a + 1);
            a++;
        }
        gotoxy(9, a);
        blu(); cout << "  "; def(); cout << "                         "; blu(); cout << "  "; def();
        gotoxy(0, a + 1);


    }
    gotoxy(10, 35);
    blu(); cout << "                           ";
    gotoxy(0, 36);
    def();
}
void rama()
{
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    gotoxy(0, 1);
    for (int a = 0; a < 80; a++)
    {
        gotoxy(a, 1);
        blu();
        cout << " ";
        def();
        gotoxy(a, 40);
        blu();
        cout << " ";
        def();
    }
    for (int a = 4; a < 76; a++)
    {
        gotoxy(a, 3);
        blu();
        cout << " ";
        def();
        gotoxy(a, 38);
        blu();
        cout << " ";
        def();
    }
    gotoxy(0, 1);
    for (int a = 1; a < 40; a++)
    {
        gotoxy(0, a);
        blu();
        cout << " ";
        def();
        gotoxy(1, a);
        blu();
        cout << " ";
        def();
        gotoxy(78, a);
        blu();
        cout << " ";
        def();
        gotoxy(79, a);
        blu();
        cout << " ";
        def();
    }
    for (int a = 3; a < 37; a++)
    {
        gotoxy(4, a);
        blu();
        cout << " ";
        def();
        gotoxy(5, a);
        blu();
        cout << " ";
        def();
        gotoxy(74, a);
        blu();
        cout << " ";
        def();
        gotoxy(75, a);
        blu();
        cout << " ";
        def();
    }
}
void menu0(bool c)
{
    HANDLE hConsole;
    napis();
    rama();
    ta();
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(16, 24);
    if (c == 1)
        Beep(60, 300);
    cout << "S T A R T   G R Y" << endl;
    Sleep(500);
    gotoxy(16, 26);
    if (c == 1)
        Beep(80, 300);
    cout << "O P C J E" << endl;
    Sleep(500);
    gotoxy(16, 28);
    if (c == 1)
        Beep(100, 300);
    cout << "R E K O R D Y" << endl;
    Sleep(500);
    gotoxy(16, 30);
    if (c == 1)
        Beep(120, 300);
    cout << "A U T O R Z Y" << endl;
    Sleep(500);
    gotoxy(16, 32);
    if (c == 1)
        Beep(140, 300);
    cout << "K O N I E C" << endl;
}
void menu1(bool c)
{
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    system("cls");
    napis();
    rama();
    ta();
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(16, 24);
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "S T A R T   G R Y" << endl;
    SetConsoleTextAttribute

    (hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    gotoxy(16, 26);
    cout << "O P C J E" << endl;
    gotoxy(16, 28);
    cout << "R E K O R D Y" << endl;
    gotoxy(16, 30);
    cout << "A U T O R Z Y" << endl;
    gotoxy(16, 32);
    cout << "K O N I E C" << endl;

    pizza1();



    if (c == 1)
        Beep(200, 300);
}
void menu2(bool c)
{
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    napis();
    rama();
    ta();
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(16, 24);
    cout << "S T A R T   G R Y" << endl;
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    gotoxy(16, 26);
    cout << "O P C J E" << endl;
    SetConsoleTextAttribute

    (hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    gotoxy(16, 28);
    cout << "R E K O R D Y" << endl;
    gotoxy(16, 30);
    cout << "A U T O R Z Y" << endl;
    gotoxy(16, 32);
    cout << "K O N I E C" << endl;
    pizza();
    if (c == 1)
        Beep(200, 300);
}
void menu3(bool c)
{
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    napis();
    rama();
    ta();
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(16, 24);
    cout << "S T A R T   G R Y" << endl;
    gotoxy(16, 26);
    cout << "O P C J E" << endl;
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    gotoxy(16, 28);
    cout << "R E K O R D Y" << endl;
    SetConsoleTextAttribute

    (hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    gotoxy(16, 30);
    cout << "A U T O R Z Y" << endl;
    gotoxy(16, 32);
    cout << "K O N I E C" << endl;
    pizza1();
    if (c == 1)
        Beep(200, 300);
}
void menu4(bool c)
{
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    napis();
    rama();
    ta();
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(16, 24);
    cout << "S T A R T   G R Y" << endl;
    gotoxy(16, 26);
    cout << "O P C J E" << endl;
    gotoxy(16, 28);
    cout << "R E K O R D Y" << endl;
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    gotoxy(16, 30);
    cout << "A U T O R Z Y" << endl;
    SetConsoleTextAttribute

    (hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    gotoxy(16, 32);
    cout << "K O N I E C" << endl;
    pizza();
    if (c == 1)
        Beep(200, 300);
}
void menu5(bool c)
{
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    napis();
    rama();
    ta();
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(16, 24);
    cout << "S T A R T   G R Y" << endl;
    gotoxy(16, 26);
    cout << "O P C J E" << endl;
    gotoxy(16, 28);
    cout << "R E K O R D Y" << endl;
    gotoxy(16, 30);
    cout << "A U T O R Z Y" << endl;
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    gotoxy(16, 32);
    cout << "K O N I E C" << endl;
    SetConsoleTextAttribute

    (hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    pizza1();
    if (c == 1)
        Beep(200, 300);
}
void opcje()
{
    system("cls");
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    gotoxy(0, 2);
    cout << "================================================================================" << endl;
    gotoxy(5, 3);
    cout << "                                OPCJE" << endl;
    gotoxy(0, 4);
    cout << "================================================================================" << endl;

    SetConsoleTextAttribute
    (hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    gotoxy(5, 10);
    cout << "DZWIEK WLACZONY" << endl;
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(5, 14);
    cout << "POWROT DO MENU" << endl;

}
void opcje2()
{
    system("cls");
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    gotoxy(0, 2);
    cout << "================================================================================" << endl;
    gotoxy(5, 3);
    cout << "                                OPCJE" << endl;
    gotoxy(0, 4);
    cout << "================================================================================" << endl;

    SetConsoleTextAttribute
    (hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    gotoxy(5, 10);
    cout << "DZWIEK WYLACZONY" << endl;
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(5, 14);
    cout << "POWROT DO MENU" << endl;
}
void opcje3()
{
    system("cls");
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    gotoxy(0, 2);
    cout << "================================================================================" << endl;
    gotoxy(5, 3);
    cout << "                                OPCJE" << endl;
    gotoxy(0, 4);
    cout << "================================================================================" << endl;
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

    gotoxy(5, 10);
    cout << "DZWIEK WLACZONY" << endl;

    gotoxy(5, 14);
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "POWROT DO MENU" << endl;
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
}
void opcje4()
{
    system("cls");
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    gotoxy(0, 2);
    cout << "================================================================================" << endl;
    gotoxy(5, 3);
    cout << "                                OPCJE" << endl;
    gotoxy(0, 4);
    cout << "================================================================================" << endl;
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);

    gotoxy(5, 10);
    cout << "DZWIEK WYLACZONY" << endl;

    gotoxy(5, 14);
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "POWROT DO MENU" << endl;
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
}
void  Menu_Opcje(bool& c)
{
    int b = 1;

    char k;
    do
    {

        switch (c)
        {
        case true:
            switch (b)
            {
            case 1:
                opcje();
                k = _getch();
                switch (k)
                {
                case -32:
                    k = _getch();
                    switch (k)
                    {
                    case 72:
                        b = 2;
                        break;
                    case 80:
                        b = 2;
                        break;
                    }
                    break;
                case 13:
                    b = 1;
                    c = false;
                    break;
                }
                break;

            case 2:
                opcje3();
                k = _getch();
                switch (k)
                {
                case -32:
                    k = _getch();
                    switch (k)
                    {
                    case 72:
                        b = 1;
                        break;
                    case 80:
                        b = 1;
                        break;
                    }
                    break;
                case 13:
                    b = 5;
                    break;
                }
                break;
            }
            break;
        case false:
            switch (b)
            {
            case 1:
                opcje2();
                k = _getch();
                switch (k)
                {
                case -32:
                    k = _getch();
                    switch (k)
                    {
                    case 72:
                        b = 2;
                        break;
                    case 80:
                        b = 2;
                        break;
                    }
                    break;
                case 13:
                    b = 1;
                    c = true;
                    break;
                }
                break;

            case 2:
                opcje4();
                k = _getch();
                switch (k)
                {
                case -32:
                    k = _getch();
                    switch (k)
                    {
                    case 72:
                        b = 1;
                        break;
                    case 80:
                        b = 1;
                        break;
                    }
                    break;
                case 13:
                    b = 5;
                    break;
                }
                break;
            }
            break;
        }


    } while (b != 5);
}

void ekran_koncowy()
{
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    system("cls");
    for (int a = 0; a <= 40; a++)
    {
        gotoxy(29, a);
        cout << "DZIENA ZA ZAGRANIE :D" << endl;
        Sleep(40);
        system("cls");
    }

    SetConsoleTextAttribute

    (hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void rekordsort(int* x, string* najlepsi)
{
    ifstream plik;
    plik.open("wyniki.txt", ios::in | ios::out | ios::binary);
    if (plik)
    {
        int a = 1, maks = 0, c, b, i = 0, y[10], x[10], e, d = 0;

        string najlepsi[10], teraz, najlepszy;
        plik.seekg(0, ios::beg);
        i = 0;
        for (int g = 0; g < 10; g++)
            y[g] = 0;
        while (i <= 9)
        {
            plik.seekg(0, ios::beg);
            a = 1;
            e = 0;



            while (true)
            {
                d = 0;

                if (plik.good())
                {
                    if (a % 2 == 1)
                    {
                        plik >> teraz;

                    }
                    if (a % 2 == 0)
                    {

                        plik >> b;

                        for (int j = 0; j <= i; j++)
                        {
                            if (y[j] == a)
                                d = 1;
                        }
                        if (d > 0)
                        {
                            a++;
                            continue;
                        }
                        if (b > maks)
                        {
                            maks = b;
                            e = a;
                            najlepszy = teraz;


                        }

                    }


                    a++;
                }
                else
                    break;
            }

            x[i] = maks;
            y[i] = e;
            najlepsi[i] = najlepszy;
            maks = 0;
            i++;





        }

        for (int f = 0; f <= 9; f++)
            cout << najlepsi[f] << " " << x[f] << endl;
        plik.close();

    }
    else
    {
        cout << "cos nie habla" << endl;
    }
}
void menu(bool& c, int* x, string* y)
{
    gotoxy(5, 8);
    int a = 1;

    char k;
    do
    {
        switch (a)
        {
        case 1:
            menu1(c);
            k = _getch();
            //cout<<k<<endl;
            //Sleep(5000);
            switch (k)
            {
            case -32:
                k = _getch();
                switch (k)
                {
                case 80:
                    a = 2;
                    break;
                case 72:
                    a = 5;
                    break;
                }
                break;

            case 13:
                a = 6;
                break;

            }
            break;
        case 2:
            menu2(c);
            k = _getch();
            switch (k)
            {
            case -32:
                k = _getch();
                switch (k)
                {
                case 72:
                    a = 1;
                    break;
                case 80:
                    a = 3;
                    break;
                }
                break;
            case 13:
                system("cls");
                Menu_Opcje(c);
                a = 2;
                break;

            }
            break;
        case 3:
            menu3(c);
            k = _getch();
            switch (k)
            {
            case -32:
                k = _getch();
                switch (k)
                {
                case 72:
                    a = 2;
                    break;
                case 80:
                    a = 4;
                    break;

                }
                break;
            case 13:
                system("cls");
                rekordsort(x, y);
                gotoxy(9, 22);
                cout << "gra jest w wersji wczesnego dostepu, dokup dlc" << endl;
                do
                {
                    k = _getch();
                    system("cls");
                    rekordsort(x, y);
                } while (k != 13);
                a = 3;
                break;
            }
            break;
        case 4:
            menu4(c);
            k = _getch();
            switch (k)
            {
            case -32:
                k = _getch();
                switch (k)
                {
                case 80:
                    a = 5;
                    break;
                case 72:
                    a = 3;
                    break;
                }
                break;
            case 13:
                system("cls");
                autorzy();

                do
                {
                    k = _getch();
                    system("cls");

                } while (k != 13);
                a = 4;
                break;
            }
            system("color 7");
            break;

        case 5:
            menu5(c);
            k = _getch();
            switch (k)
            {
            case -32:
                k = _getch();
                switch (k)
                {
                case 80:
                    a = 1;
                    break;
                case 72:
                    a = 4;
                    break;
                }
                break;
            case 13:
                a = 7;
                break;

            }
            break;
        case 7:
            ekran_koncowy();
            Sleep(3000);
            system("cls");
            exit(0);
            break;



        }
    } while (a != 6);
}
void rozdzielczosc()
{
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    obramowka();
    gotoxy(23, 6);
    cout << "Dostosuj wymiary swojej konsoli ";
    gotoxy(23, 8);
    cout << "tak by poni" << PL("ż") << "sze paski zajmowa" << PL("ł") << "y";
    gotoxy(23, 10);
    cout << "ca" << PL("ł") << PL("ą") << " szeroko" << PL("ś") << PL("ć") << " i wysoko" << PL("ś") << PL("ć") << " ekranu.";
    gotoxy(31, 12);
    cout << " ZRESETUJ GRE";
    gotoxy(0, 0);
    pur();
    for (int a = 0; a < 40; a++)
    {
        gotoxy(0, a);
        cout << " ";
    }
    def();
    gotoxy(0, 15);
    pur();
    for (int a = 0; a < 80; a++)
    {
        gotoxy(a, 17);
        cout << " ";
    }
    def();
    Sleep(3000);
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    system("cls");

}
void pacmapa()
{


    gotoxy(2, 6);
    for (int a = 6; a < 40; a++)
    {
        gotoxy(2, a);
        pup();
        cout << "                                                                            ";
        def();
    }
    gotoxy(2, 6);
    fio();

    cout << "  ";
    def();
    gotoxy(76, 6);
    fio();

    cout << "  ";
    def();
    gotoxy(2, 39);
    fio();

    cout << "  ";
    def();
    gotoxy(76, 39);
    fio();

    cout << "  ";
    def();
    gotoxy(32, 19);
    blu();
    cout << "                ";

    def();
    gotoxy(32, 24);
    blu();

    cout << "                ";
    def();
    for (int a = 19; a < 24; a++)
    {
        gotoxy(32, a);
        blu();

        cout << " ";
        def();
        gotoxy(47, a);
        blu();

        cout << " ";
        def();
    }
    gotoxy(33, 20);
    for (int a = 20; a < 24; a++)
    {
        gotoxy(33, a);
        def();
        cout << "              ";

    }
    gotoxy(35, 21);
    zielony();
    cout << "  ";
    def();
    gotoxy(39, 21);
    d();
    cout << "  ";
    def();
    gotoxy(43, 21);
    duch();
    cout << "  ";
    def();
    gotoxy(39, 19);
    drzwi();
    cout << "  ";
    def();
    //przeszkody
    gotoxy(4, 7);
    blu();
    cout << "                    ";

    def();
    gotoxy(26, 7);
    blu();
    cout << "      ";

    def();
    gotoxy(34, 7);
    blu();
    cout << "            ";

    def();
    gotoxy(48, 7);
    blu();
    cout << "      ";

    def();
    gotoxy(48, 7);
    blu();
    cout << "      ";

    def();
    gotoxy(56, 7);
    blu();
    cout << "                    ";

    def();
    //2
    gotoxy(4, 8);
    blu();
    cout << "                    ";

    def();
    gotoxy(26, 8);
    blu();
    cout << "      ";

    def();
    gotoxy(34, 8);
    blu();
    cout << "            ";

    def();
    gotoxy(48, 8);
    blu();
    cout << "      ";

    def();
    gotoxy(48, 8);
    blu();
    cout << "      ";
    def();
    gotoxy(56, 8);
    blu();
    cout << "                    ";
    def();
    //3
    gotoxy(10, 9);
    blu();
    cout << "  ";
    def();
    gotoxy(16, 9);
    blu();
    cout << "  ";
    def();
    gotoxy(26, 9);
    blu();
    cout << "      ";
    def();
    gotoxy(34, 9);
    blu();
    cout << "            ";
    def();
    gotoxy(48, 9);
    blu();
    cout << "      ";
    def();
    gotoxy(62, 9);
    blu();
    cout << "  ";
    def();
    gotoxy(68, 9);
    blu();
    cout << "  ";
    def();
    //4
    gotoxy(4, 10);
    blu();
    cout << "    ";
    def();
    gotoxy(10, 10);
    blu();
    cout << "  ";
    def();
    gotoxy(16, 10);
    blu();
    cout << "  ";
    def();
    gotoxy(20, 10);
    blu();
    cout << "            ";
    def();
    gotoxy(38, 10);
    blu();
    cout << "    ";
    def();
    gotoxy(48, 10);
    blu();
    cout << "            ";
    def();
    gotoxy(62, 10);
    blu();
    cout << "  ";
    def();
    gotoxy(68, 10);
    blu();
    cout << "  ";
    def();
    gotoxy(72, 10);
    blu();
    cout << "    ";
    def();
    //5
    gotoxy(10, 11);
    blu();
    cout << "  ";
    def();
    gotoxy(16, 11);
    blu();
    cout << "  ";
    def();
    gotoxy(26, 11);
    blu();
    cout << "          ";
    def();
    gotoxy(38, 11);
    blu();
    cout << "    ";
    def();
    gotoxy(44, 11);
    blu();
    cout << "          ";
    def();
    gotoxy(62, 11);
    blu();
    cout << "  ";
    def();
    gotoxy(68, 11);
    blu();
    cout << "  ";
    def();
    //6
    gotoxy(4, 12);
    blu();
    cout << "    ";
    def();
    gotoxy(10, 12);
    blu();
    cout << "  ";
    def();
    gotoxy(16, 12);
    blu();
    cout << "  ";
    def();
    gotoxy(20, 12);
    blu();
    cout << "  ";
    def();
    gotoxy(38, 12);
    blu();
    cout << "    ";
    def();
    gotoxy(58, 12);
    blu();
    cout << "  ";
    def();
    gotoxy(62, 12);
    blu();
    cout << "  ";
    def();
    gotoxy(68, 12);
    blu();
    cout << "  ";
    def();
    gotoxy(72, 12);
    blu();
    cout << "    ";
    def();
    //7

    gotoxy(10, 13);
    blu();
    cout << "  ";
    def();
    gotoxy(16, 13);
    blu();
    cout << "  ";
    def();
    gotoxy(20, 13);
    blu();
    cout << "  ";
    def();
    gotoxy(38, 13);
    blu();
    cout << "    ";
    def();
    gotoxy(58, 13);
    blu();
    cout << "  ";
    def();
    gotoxy(62, 13);
    blu();
    cout << "  ";
    def();
    gotoxy(68, 13);
    blu();
    cout << "  ";
    def();
    //8
    gotoxy(4, 14);
    blu();
    cout << "    ";
    def();
    gotoxy(72, 14);
    blu();
    cout << "    ";
    def();
    //9
    gotoxy(10, 15);
    blu();
    cout << "                            ";
    def();
    gotoxy(42, 15);
    blu();
    cout << "                            ";
    def();
    //10
    gotoxy(2, 16);
    blu();
    cout << "      ";
    def();
    gotoxy(10, 16);
    blu();
    cout << " ";
    def();
    gotoxy(69, 16);
    blu();
    cout << " ";
    def();
    gotoxy(72, 16);
    blu();
    cout << "      ";
    def();
    //11
    gotoxy(2, 17);
    blu();
    cout << "      ";
    def();
    gotoxy(10, 17);
    blu();
    cout << " ";
    def();
    gotoxy(13, 17);
    blu();
    cout << "              ";
    def();
    gotoxy(29, 17);
    blu();
    cout << "      ";
    def();
    gotoxy(38, 17);
    blu();
    cout << "    ";
    def();
    gotoxy(45, 17);
    blu();
    cout << "      ";
    def();
    gotoxy(53, 17);
    blu();
    cout << "              ";
    def();

    gotoxy(69, 17);
    blu();
    cout << " ";
    def();
    gotoxy(72, 17);
    blu();
    cout << "      ";
    def();
    //12
    gotoxy(7, 18);
    blu();
    cout << " ";
    def();
    gotoxy(10, 18);
    blu();
    cout << " ";
    def();
    gotoxy(29, 18);
    blu();
    cout << " ";
    def();
    gotoxy(50, 18);
    blu();
    cout << " ";
    def();
    gotoxy(69, 18);
    blu();
    cout << " ";
    def();
    gotoxy(72, 18);
    blu();
    cout << " ";
    def();
    //13
    gotoxy(7, 19);
    blu();
    cout << " ";
    def();
    gotoxy(10, 19);
    blu();
    cout << " ";
    def();
    gotoxy(29, 19);
    blu();
    cout << " ";
    def();
    gotoxy(50, 19);
    blu();
    cout << " ";
    def();
    gotoxy(69, 19);
    blu();
    cout << " ";
    def();
    gotoxy(72, 19);
    blu();
    cout << " ";
    def();
    //14
    gotoxy(2, 20);
    blu();
    cout << "      ";
    def();
    gotoxy(10, 20);
    blu();
    cout << " ";
    def();
    gotoxy(29, 20);
    blu();
    cout << " ";
    def();
    gotoxy(50, 20);
    blu();
    cout << " ";
    def();
    gotoxy(69, 20);
    blu();
    cout << " ";
    def();
    gotoxy(72, 20);
    blu();
    cout << "      ";
    def();
    //15
    gotoxy(10, 21);
    blu();
    cout << " ";
    def();
    gotoxy(13, 21);
    blu();
    cout << "              ";
    def();
    gotoxy(53, 21);
    blu();
    cout << "              ";
    def();
    gotoxy(69, 21);
    blu();
    cout << " ";
    def();
    //16
    gotoxy(4, 22);
    blu();
    cout << "    ";
    def();
    gotoxy(72, 22);
    blu();
    cout << "    ";
    def();

    //naodwrot
    gotoxy(4, 38);
    blu();
    cout << "                    ";
    def();
    gotoxy(26, 38);
    blu();
    cout << "      ";
    def();
    gotoxy(34, 38);
    blu();
    cout << "            ";
    def();
    gotoxy(48, 38);
    blu();
    cout << "      ";
    def();
    gotoxy(48, 38);
    blu();
    cout << "      ";
    def();
    gotoxy(56, 38);
    blu();
    cout << "                    ";
    def();
    //2
    gotoxy(4, 37);
    blu();
    cout << "                    ";
    def();
    gotoxy(26, 37);
    blu();
    cout << "      ";
    def();
    gotoxy(34, 37);
    blu();
    cout << "            ";
    def();
    gotoxy(48, 37);
    blu();
    cout << "      ";
    def();
    gotoxy(48, 37);
    blu();
    cout << "      ";
    def();
    gotoxy(56, 37);
    blu();
    cout << "                    ";
    def();
    //3
    gotoxy(10, 36);
    blu();
    cout << "  ";
    def();
    gotoxy(16, 36);
    blu();
    cout << "  ";
    def();
    gotoxy(26, 36);
    blu();
    cout << "      ";
    def();
    gotoxy(34, 36);
    blu();
    cout << "            ";
    def();
    gotoxy(48, 36);
    blu();
    cout << "      ";
    def();
    gotoxy(62, 36);
    blu();
    cout << "  ";
    def();
    gotoxy(68, 36);
    blu();
    cout << "  ";
    def();
    //4
    gotoxy(4, 35);
    blu();
    cout << "    ";
    def();
    gotoxy(10, 35);
    blu();
    cout << "  ";
    def();
    gotoxy(16, 35);
    blu();
    cout << "  ";
    def();
    gotoxy(20, 35);
    blu();
    cout << "            ";
    def();
    gotoxy(38, 35);
    blu();
    cout << "    ";
    def();
    gotoxy(48, 35);
    blu();
    cout << "            ";
    def();
    gotoxy(62, 35);
    blu();
    cout << "  ";
    def();
    gotoxy(68, 35);
    blu();
    cout << "  ";
    def();
    gotoxy(72, 35);
    blu();
    cout << "    ";
    def();
    //5
    gotoxy(10, 34);
    blu();
    cout << "  ";
    def();
    gotoxy(16, 34);
    blu();
    cout << "  ";
    def();
    gotoxy(26, 34);
    blu();
    cout << "          ";
    def();
    gotoxy(38, 34);
    blu();
    cout << "    ";
    def();
    gotoxy(44, 34);
    blu();
    cout << "          ";
    def();
    gotoxy(62, 34);
    blu();
    cout << "  ";
    def();
    gotoxy(68, 34);
    blu();
    cout << "  ";
    def();
    //6
    gotoxy(4, 33);
    blu();
    cout << "    ";
    def();
    gotoxy(10, 33);
    blu();
    cout << "  ";
    def();
    gotoxy(16, 33);
    blu();
    cout << "  ";
    def();
    gotoxy(20, 33);
    blu();
    cout << "  ";
    def();
    gotoxy(38, 33);
    blu();
    cout << "    ";
    def();
    gotoxy(58, 33);
    blu();
    cout << "  ";
    def();
    gotoxy(62, 33);
    blu();
    cout << "  ";
    def();
    gotoxy(68, 33);
    blu();
    cout << "  ";
    def();
    gotoxy(72, 33);
    blu();
    cout << "    ";
    def();
    //7

    gotoxy(10, 32);
    blu();
    cout << "  ";
    def();
    gotoxy(16, 32);
    blu();
    cout << "  ";
    def();
    gotoxy(20, 32);
    blu();
    cout << "  ";
    def();
    gotoxy(38, 32);
    blu();
    cout << "    ";
    def();
    gotoxy(58, 32);
    blu();
    cout << "  ";
    def();
    gotoxy(62, 32);
    blu();
    cout << "  ";
    def();
    gotoxy(68, 32);
    blu();
    cout << "  ";
    def();
    //8
    gotoxy(4, 31);
    blu();
    cout << "    ";
    def();
    gotoxy(72, 31);
    blu();
    cout << "    ";
    def();
    //9
    gotoxy(10, 30);
    blu();
    cout << "                            ";
    def();
    gotoxy(42, 30);
    blu();
    cout << "                            ";
    def();
    //10
    gotoxy(2, 29);
    blu();
    cout << "      ";
    def();
    gotoxy(10, 29);
    blu();
    cout << " ";
    def();
    gotoxy(69, 29);
    blu();
    cout << " ";
    def();
    gotoxy(72, 29);
    blu();
    cout << "      ";
    def();
    //11
    gotoxy(2, 28);
    blu();
    cout << "      ";
    def();
    gotoxy(10, 28);
    blu();
    cout << " ";
    def();
    gotoxy(13, 28);
    blu();
    cout << "              ";
    def();
    gotoxy(29, 28);
    blu();
    cout << "      ";
    def();
    gotoxy(38, 28);
    blu();
    cout << "    ";
    def();
    gotoxy(45, 28);
    blu();
    cout << "      ";
    def();
    gotoxy(53, 28);
    blu();
    cout << "              ";
    def();

    gotoxy(69, 28);
    blu();
    cout << " ";
    def();
    gotoxy(72, 28);
    blu();
    cout << "      ";
    def();
    //12
    gotoxy(7, 27);
    blu();
    cout << " ";
    def();
    gotoxy(10, 27);
    blu();
    cout << " ";
    def();
    gotoxy(29, 27);
    blu();
    cout << " ";
    def();
    gotoxy(50, 27);
    blu();
    cout << " ";
    def();
    gotoxy(69, 27);
    blu();
    cout << " ";
    def();
    gotoxy(72, 27);
    blu();
    cout << " ";
    def();
    //13
    gotoxy(7, 26);
    blu();
    cout << " ";
    def();
    gotoxy(10, 26);
    blu();
    cout << " ";
    def();
    gotoxy(29, 26);
    blu();
    cout << " ";
    def();
    gotoxy(50, 26);
    blu();
    cout << " ";
    def();
    gotoxy(69, 26);
    blu();
    cout << " ";
    def();
    gotoxy(72, 26);
    blu();
    cout << " ";
    def();
    //14
    gotoxy(2, 25);
    blu();
    cout << "      ";
    def();
    gotoxy(10, 25);
    blu();
    cout << " ";
    def();
    gotoxy(29, 25);
    blu();
    cout << " ";
    def();
    gotoxy(50, 25);
    blu();
    cout << " ";
    def();
    gotoxy(69, 25);
    blu();
    cout << " ";
    def();
    gotoxy(72, 25);
    blu();
    cout << "      ";
    def();
    //15
    gotoxy(10, 24);
    blu();
    cout << " ";
    def();
    gotoxy(13, 24);
    blu();
    cout << "              ";
    def();
    gotoxy(53, 24);
    blu();
    cout << "              ";
    def();
    gotoxy(69, 24);
    blu();
    cout << " ";
    def();
    //16
    gotoxy(4, 23);
    blu();
    cout << "    ";
    def();
    gotoxy(72, 23);
    blu();
    cout << "    ";
    def();
    gotoxy(2, 18);
    def();
    cout << "     ";
    def();
    gotoxy(2, 19);
    def();
    cout << "     ";
    def();
    gotoxy(2, 26);
    def();
    cout << "     ";
    def();
    gotoxy(2, 27);
    def();
    cout << "     ";
    def();
    gotoxy(73, 18);
    def();
    cout << "     ";
    def();
    gotoxy(73, 19);
    def();
    cout << "     ";
    def();
    gotoxy(73, 26);
    def();
    cout << "     ";
    def();
    gotoxy(73, 27);
    def();
    cout << "     ";
    def();
    gotoxy(0, 1);
    for (int a = 0; a < 80; a++)
    {
        gotoxy(a, 1);
        blu();
        cout << " ";
        def();
        gotoxy(a, 40);
        blu();
        cout << " ";
        def();
        gotoxy(a, 5);
        blu();
        cout << " ";
        def();

    }
    gotoxy(0, 1);
    for (int a = 1; a < 40; a++)
    {
        gotoxy(0, a);
        blu();
        cout << " ";
        def();
        gotoxy(1, a);
        blu();
        cout << " ";
        def();
        gotoxy(78, a);
        blu();
        cout << " ";
        def();
        gotoxy(79, a);
        blu();
        cout << " ";
        def();
    }
    gotoxy(32, 24);
    blu();
    cout << " ";
    def();
    gotoxy(33, 23);
    def();
    cout << "              ";
    gotoxy(33, 24);
    def();
    cout << "              ";
    gotoxy(47, 24);
    blu();
    cout << " ";
    def();
    gotoxy(32, 25);
    blu();
    cout << "                ";
    def();
}


void ekran_zwyciestwa()
{
    HANDLE hConsole;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute
    (hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);

    gotoxy(36, 16);
    cout << "YOU WON!";
    gotoxy(30, 17);
    cout << "THANKS FOR PLAYING";
    def();
}



void plansza_1()
{

    //system("Color 1A");
    int plansza[81][42];
    int plansza2[81][42];
    int kierunek[4];
    plansza[0][0] = 0;
    {
        for (int j = 0; j < 40; j++)
        {
            for (int i = 0; i < 80; i++)
            {

                plansza[i][j] = 1;
                gotoxy(i, j);
                //cout<<plansza[i][j];

            }
        }

        for (int j = 0; j < 6; j++)
        {
            for (int i = 0; i < 80; i++)
            {

                plansza[i][j] = 0;
                gotoxy(i, j);
                //cout<<plansza[i][j];

            }
        }

        for (int i = 0; i < 80; i++)
        {
            if (i == 24 || i == 25 || i == 32 || i == 33 || i == 46 || i == 47 || i == 54 || i == 55)
                continue;
            plansza[i][6] = 0;
            plansza[i][7] = 0;
        }

        for (int j = 8; j < 20; j++)
        {
            for (int i = 0; i < 4; i++)
                plansza[i][j] = 0;
        }

        for (int j = 9; j < 40; j++)
        {
            if (j == 10 || j == 12 || j == 14 || j == 20 || j == 23 || j == 29 || j == 31 || j == 33 || j == 35 || j == 38)
                continue;
            for (int i = 4; i < 8; i++)
                plansza[i][j] = 0;
        }

        for (int j = 20; j < 40; j++)
        {
            for (int i = 0; i < 2; i++)
                plansza[i][j] = 0;
        }

        plansza[2][39] = 0;
        plansza[3][39] = 0;

        for (int j = 24; j < 28; j++)
        {
            for (int i = 2; i < 4; i++)
                plansza[i][j] = 0;
        }

        for (int i = 8; i < 80; i++)
            plansza[i][39] = 0;

        for (int j = 8; j < 39; j++)
        {
            for (int i = 78; i < 80; i++)
                plansza[i][j] = 0;
        }

        for (int i = 8; i < 80; i++)
        {
            if (i == 24 || i == 25 || i == 32 || i == 33 || i == 46 || i == 47 || i == 54 || i == 55 || i == 76 || i == 77)
                continue;
            plansza[i][36] = 0;
            plansza[i][37] = 0;
        }

        for (int j = 9; j < 40; j++)
        {
            if (j == 10 || j == 12 || j == 14 || j == 20 || j == 23 || j == 29 || j == 31 || j == 33 || j == 35 || j == 38)
                continue;
            for (int i = 72; i < 76; i++)
                plansza[i][j] = 0;
        }

        for (int i = 4; i < 78; i++)
            plansza[i][5] = 1;

        for (int j = 5; j < 15; j++)
        {
            for (int i = 2; i < 4; i++)
                plansza[i][j] = 1;
        }

        for (int j = 6; j < 8; j++)
        {
            for (int i = 76; i < 78; i++)
                plansza[i][j] = 1;
        }

        for (int j = 8; j < 36; j++)
        {
            if (j == 13 || j == 21 || j == 22 || j == 30)
                continue;
            plansza[10][j] = 0;
        }

        for (int j = 11; j < 70; j++)
        {
            if (j == 38 || j == 39 || j == 40 || j == 41)
                continue;
            plansza[j][14] = 0;
        }

        for (int j = 11; j < 70; j++)
        {
            if (j == 38 || j == 39 || j == 40 || j == 41)
                continue;
            plansza[j][29] = 0;
        }

        for (int j = 8; j < 36; j++)
        {
            if (j == 13 || j == 21 || j == 22 || j == 30)
                continue;
            plansza[69][j] = 0;
        }

        for (int j = 15; j < 29; j++)
        {
            if (j > 19 && j < 24)
                continue;
            for (int i = 76; i < 78; i++)
                plansza[i][j] = 0;
        }


        for (int i = 13; i < 27; i++)
        {
            plansza[i][16] = 0;
            plansza[i][20] = 0;
            plansza[i][23] = 0;
            plansza[i][27] = 0;
        }

        for (int i = 53; i < 67; i++)
        {
            plansza[i][16] = 0;
            plansza[i][20] = 0;
            plansza[i][23] = 0;
            plansza[i][27] = 0;
        }

        for (int i = 8; i < 13; i++)
            plansza[11][i] = 0;

        for (int i = 31; i < 36; i++)
            plansza[11][i] = 0;


        for (int i = 31; i < 36; i++)
            plansza[68][i] = 0;


        for (int i = 8; i < 13; i++)
            plansza[68][i] = 0;


        for (int j = 8; j < 13; j++)
        {
            for (int i = 16; i < 18; i++)
                plansza[i][j] = 0;
        }

        for (int j = 31; j < 36; j++)
        {
            for (int i = 16; i < 18; i++)
                plansza[i][j] = 0;
        }

        for (int j = 8; j < 13; j++)
        {
            for (int i = 62; i < 64; i++)
                plansza[i][j] = 0;
        }

        for (int j = 31; j < 36; j++)
        {
            for (int i = 62; i < 64; i++)
                plansza[i][j] = 0;
        }

        for (int j = 11; j < 13; j++)
        {
            for (int i = 20; i < 22; i++)
                plansza[i][j] = 0;
        }

        for (int j = 31; j < 33; j++)
        {
            for (int i = 20; i < 22; i++)
                plansza[i][j] = 0;
        }

        for (int j = 31; j < 33; j++)
        {
            for (int i = 58; i < 60; i++)
                plansza[i][j] = 0;
        }

        for (int j = 11; j < 13; j++)
        {
            for (int i = 58; i < 60; i++)
                plansza[i][j] = 0;
        }

        for (int j = 8; j < 11; j++)
        {
            for (int i = 26; i < 32; i++)
                plansza[i][j] = 0;
        }

        for (int j = 33; j < 36; j++)
        {
            for (int i = 26; i < 32; i++)
                plansza[i][j] = 0;
        }

        for (int j = 8; j < 11; j++)
        {
            for (int i = 48; i < 54; i++)
                plansza[i][j] = 0;
        }

        for (int j = 33; j < 36; j++)
        {
            for (int i = 48; i < 54; i++)
                plansza[i][j] = 0;
        }

        for (int j = 8; j < 13; j++)
        {
            for (int i = 38; i < 42; i++)
                plansza[i][j] = 0;
        }


        for (int j = 31; j < 36; j++)
        {
            for (int i = 38; i < 42; i++)
                plansza[i][j] = 0;
        }

        for (int i = 20; i < 26; i++)
            plansza[i][9] = 0;

        for (int i = 20; i < 26; i++)
            plansza[i][34] = 0;

        for (int i = 54; i < 60; i++)
            plansza[i][9] = 0;

        for (int i = 54; i < 60; i++)
            plansza[i][34] = 0;

        for (int i = 34; i < 38; i++)
            plansza[i][8] = 0;

        for (int i = 34; i < 38; i++)
            plansza[i][35] = 0;

        for (int i = 42; i < 46; i++)
            plansza[i][8] = 0;

        for (int i = 42; i < 46; i++)
            plansza[i][35] = 0;

        for (int i = 32; i < 36; i++)
            plansza[i][10] = 0;

        for (int i = 32; i < 36; i++)
            plansza[i][33] = 0;

        for (int i = 44; i < 48; i++)
            plansza[i][10] = 0;


        for (int i = 44; i < 48; i++)
            plansza[i][33] = 0;

        for (int i = 29; i < 34; i++)
            plansza[i][16] = 0;

        for (int i = 29; i < 34; i++)
            plansza[i][27] = 0;

        for (int i = 46; i < 51; i++)
            plansza[i][16] = 0;

        for (int i = 46; i < 51; i++)
            plansza[i][27] = 0;

        for (int i = 38; i < 42; i++)
            plansza[i][16] = 0;

        for (int i = 38; i < 42; i++)
            plansza[i][27] = 0;

        for (int i = 17; i < 20; i++)
            plansza[29][i] = 0;

        for (int i = 24; i < 27; i++)
            plansza[29][i] = 0;

        for (int i = 17; i < 20; i++)
            plansza[50][i] = 0;

        for (int i = 24; i < 27; i++)
            plansza[50][i] = 0;

        for (int i = 32; i < 48; i++)
            plansza[i][18] = 0;

        for (int i = 32; i < 48; i++)
            plansza[i][25] = 0;

        for (int i = 19; i < 25; i++)
            plansza[32][i] = 0;

        for (int i = 19; i < 25; i++)
            plansza[47][i] = 0;
        plansza[2][28] = 0;
        plansza[3][28] = 0;

        gotoxy(34, 28);
        pup();
        cout << " ";
        def();

        gotoxy(45, 28);
        pup();
        cout << " ";
        def();

        gotoxy(34, 17);
        pup();
        cout << " ";
        def();

        gotoxy(45, 17);
        pup();
        cout << " ";
        def();

    }
    int punkty = 0;
    /*
    for(int i=0;i<80;i++)
    {
        for(int j=0;j<40;j++)
        {
            plansza2[i][j]=plansza[i][j];
            //punkty+=plansza[i][j];
        }
    }

    for(int i=0;i<80;i++)
    {
        for(int j=0;j<41;j++)
        {
            plansza[i][j]=0;

            //punkty+=plansza[i][j];
        }
    }

    for(int i=0;i<80;i++)
    {
        for(int j=1;j<42;j++)
        {
            plansza[i][j]=plansza2[i][j-1];
            gotoxy(i,j);
            //cout<<plansza[i][j];
            //punkty+=plansza[i][j];
        }
    }
    */
    int red_x = 39, red_x2 = 40;
    int red_y = 21;
    int green_x = 35, green_x2 = 36;
    int green_y = 20;
    int white_x = 43, white_x2 = 44;
    int white_y = 20;
    punkty -= 84;
    pac();
    gotoxy(2, 6);
    cout << " ";
    gotoxy(3, 6);
    cout << " ";
    def();
    int ruch = 7, green_ruch = 7, white_ruch = 7;
    int x_poz = 2, x_poz2 = 3;
    int y_poz = 6, y_poz2 = 6;
    int ruchy = 0, los, ile = 0, los1 = 0, zycia = 3;
    punkty = 1462;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    while (punkty > 0 && zycia > 0)
    {
        gotoxy(5, 3);
        SetConsoleTextAttribute(hConsole, 13);
        cout << "PUNKTY: " << 1462 - punkty;
        gotoxy(20, 3);
        cout << PL("Ż") << "YCIA: " << zycia;
        bool c = 1;

        while (c != 0)
        {
            plansza[x_poz][y_poz] = 3;
            plansza[x_poz2][y_poz] = 3;
            char k;
            k = _getch();
            switch (k)
            {
            case -32:
                k = _getch();
                switch (k)
                {
                case 80:
                    if ((plansza[x_poz][y_poz + 1] == 1 || plansza[x_poz][y_poz + 1] == 3) && (plansza[x_poz2][y_poz + 1] == 1 || plansza[x_poz2][y_poz + 1] == 3))
                    {
                        if (plansza[x_poz][y_poz + 1] == 1)
                        {
                            plansza[x_poz][y_poz + 1] = 3;
                            punkty--;

                        }
                        if (plansza[x_poz2][y_poz + 1] == 1)
                        {
                            plansza[x_poz2][y_poz + 1] = 3;
                            punkty--;
                        }
                        gotoxy(x_poz, y_poz);
                        cout << " ";
                        gotoxy(x_poz2, y_poz2);
                        cout << " ";
                        pac();
                        gotoxy(x_poz, y_poz + 1);
                        cout << " " << endl;
                        gotoxy(x_poz2, y_poz2 + 1);
                        cout << " " << endl;
                        def();
                        y_poz2 += 1;
                        y_poz += 1;
                        c = 0;
                        ruchy++;
                    }
                    else
                        continue;
                    break;
                case 72:
                    if ((plansza[x_poz][y_poz - 1] == 1 || plansza[x_poz][y_poz - 1] == 3) && (plansza[x_poz2][y_poz - 1] == 1 || plansza[x_poz2][y_poz - 1] == 3))
                    {
                        if (plansza[x_poz][y_poz - 1] == 1)
                        {
                            plansza[x_poz][y_poz - 1] = 3;
                            punkty--;
                        }
                        if (plansza[x_poz2][y_poz - 1] == 1)
                        {
                            plansza[x_poz2][y_poz - 1] = 3;
                            punkty--;
                        }
                        gotoxy(x_poz, y_poz);
                        cout << " ";
                        gotoxy(x_poz2, y_poz2);
                        cout << " ";
                        gotoxy(x_poz, y_poz - 1);
                        pac();
                        cout << " " << endl;
                        gotoxy(x_poz2, y_poz2 - 1);
                        cout << " " << endl;
                        def();
                        y_poz2 = y_poz2 - 1;
                        y_poz = y_poz - 1;
                        c = 0;
                        ruchy++;
                    }
                    else
                        continue;
                    break;
                case 75:
                    if (plansza[x_poz - 1][y_poz] == 1 || plansza[x_poz - 1][y_poz] == 3)
                    {
                        if (plansza[x_poz - 1][y_poz] == 1)
                        {
                            plansza[x_poz - 1][y_poz] = 3;
                            punkty--;
                        }
                        gotoxy(x_poz, y_poz);
                        cout << " ";
                        gotoxy(x_poz2, y_poz2);
                        cout << " ";
                        pac();
                        gotoxy(x_poz - 1, y_poz);
                        cout << " " << endl;
                        gotoxy(x_poz2 - 1, y_poz2);
                        cout << " " << endl;
                        def();
                        c = 0;
                        x_poz -= 1;
                        x_poz2 -= 1;
                        ruchy++;
                    }
                    else
                        continue;
                    break;
                case 77:
                    if (plansza[x_poz2 + 1][y_poz] == 1 || plansza[x_poz2 + 1][y_poz] == 3)
                    {
                        if (plansza[x_poz2 + 1][y_poz] == 1)
                        {
                            plansza[x_poz2 + 1][y_poz] = 3;
                            punkty--;
                        }
                        gotoxy(x_poz, y_poz);
                        cout << " ";
                        gotoxy(x_poz2, y_poz2);
                        cout << " ";
                        pac();
                        gotoxy(x_poz + 1, y_poz);
                        cout << " " << endl;
                        gotoxy(x_poz2 + 1, y_poz2);
                        cout << " " << endl;
                        def();
                        c = 0;
                        x_poz += 1;
                        x_poz2 += 1;
                        ruchy++;
                    }
                    else
                        continue;
                    break;
                }




            }

            if ((x_poz == red_x && y_poz == red_y) || (x_poz2 == red_x && y_poz == red_y) || (x_poz == red_x2 && y_poz == red_y) || (x_poz2 == red_x2 && y_poz == red_y) || (x_poz == green_x && y_poz == green_y) || (x_poz2 == green_x && y_poz == green_y) || (x_poz == green_x2 && y_poz == green_y) || (x_poz2 == green_x2 && y_poz == green_y) || (x_poz == white_x && y_poz == white_y) || (x_poz2 == white_x && y_poz == white_y) || (x_poz == white_x2 && y_poz == white_y) || (x_poz2 == white_x2 && y_poz == white_y))
            {
                zycia--;
                gotoxy(x_poz, y_poz);
                cout << " ";
                gotoxy(x_poz2, y_poz);
                cout << " ";
                gotoxy(2, 6);
                pac();
                cout << " ";
                gotoxy(3, 6);
                cout << " ";
                def();
                y_poz = 6;
                y_poz2 = 6;
                x_poz = 2;
                x_poz2 = 3;
            }


            if (ruchy == 10)
            {
                int a = 1;
                if (ruchy == 10)
                {
                    for (int i = 0; i < 3; i++)
                    {
                        gotoxy(red_x, red_y - 1);
                        pur();
                        cout << " ";
                        gotoxy(red_x, red_y);
                        def();
                        cout << " ";

                        gotoxy(red_x2, red_y - 1);
                        pur();
                        cout << " ";
                        gotoxy(red_x2, red_y);
                        def();
                        cout << " ";

                        red_y -= 1;
                        Sleep(300);
                    }

                }

            }

            int los_x, los_y;
            if (ruchy > 10)
            {

                //gotoxy(6,6);
               // pup();
              //  cout<<red_x<<endl;
               // cout<<red_y<<endl;
                def();
                /*
                if(ruchy==11 || (red_x==los_x && red_y==los_y))
                {
                    do
                {
                 los_x=(rand()%80);
                do
                {
                     los_y=(rand()%41);
                }while(los_y!=6 && los_y!=40);
                }while(plansza[los_x][los_y]==0);
                }
                */
                kierunek[0] = 0;
                kierunek[1] = 0;
                kierunek[2] = 0;
                kierunek[3] = 0;

                if (plansza[red_x - 1][red_y] != 0)
                    kierunek[0] = sqrt(pow(red_x - x_poz - 1, 2) + pow(red_y - y_poz, 2));
                else
                    kierunek[0] = 50000000;
                if (plansza[red_x][red_y - 1] != 0 && plansza[red_x2][red_y - 1] != 0)
                    kierunek[1] = sqrt(pow(red_x - x_poz, 2) + pow(red_y - y_poz - 1, 2));
                else
                    kierunek[1] = 50000000;
                if (plansza[red_x2 + 1][red_y] != 0)
                    kierunek[2] = sqrt(pow(red_x - x_poz + 1, 2) + pow(red_y - y_poz, 2));
                else
                    kierunek[2] = 50000000;
                if (plansza[red_x][red_y + 1] != 0 && plansza[red_x2][red_y + 1] != 0)
                    kierunek[3] = sqrt(pow(red_x - x_poz, 2) + pow(red_y - y_poz + 1, 2));
                else
                    kierunek[3] = 50000000;
                /*

                gotoxy(60,1);
                pur();
                cout<<"1. "<<kierunek[0];

                gotoxy(60,2);
                pur();
                cout<<"2. "<<kierunek[1];

                gotoxy(60,3);
                pur();
                cout<<"3. "<<kierunek[2];

                gotoxy(60,4);
                pur();
                cout<<"4. "<<kierunek[3];

*/

                def();
                int where = minimalna(kierunek);
                int i = 0, a = 0;
                while (true)
                {
                    gotoxy(30, 1);
                    pur();
                    //cout<<"Where: "<<minimalna2(kierunek,minimalna(kierunek));
                    def();

                    gotoxy(2, 7);
                    pur();
                    //cout<<ruch;
                    def();
                    if (where == kierunek[0])
                    {
                        if (plansza[red_x - 1][red_y] == 0)
                        {
                            where = minimalna3(kierunek, minimalna(kierunek), minimalna2(kierunek, minimalna(kierunek)));
                            continue;
                        }

                        if (ruch == 3 && a == 0)
                        {
                            where = minimalna2(kierunek, minimalna(kierunek));
                            a++;
                            continue;
                        }

                        else
                        {

                            gotoxy(red_x2, red_y);
                            if (plansza[red_x2][red_y] == 1)
                                pup();
                            else def();
                            cout << " ";
                            gotoxy(red_x - 1, red_y);
                            pur();
                            cout << " ";
                            def();
                            red_x--;
                            red_x2--;
                            ruch = 1;
                            break;
                        }
                    }



                    if (where == kierunek[2])
                    {
                        if (plansza[red_x2 + 1][red_y] == 0)
                        {
                            where = minimalna3(kierunek, minimalna(kierunek), minimalna2(kierunek, minimalna(kierunek)));
                            continue;
                        }

                        if (ruch == 1 && a == 0)
                        {
                            where = minimalna2(kierunek, minimalna(kierunek));
                            a++;
                            continue;
                        }
                        else
                        {
                            gotoxy(red_x, red_y);
                            if (plansza[red_x][red_y] == 1)
                                pup();
                            else def();
                            cout << " ";

                            gotoxy(red_x2 + 1, red_y);
                            pur();
                            cout << " ";
                            def();
                            red_x++;
                            red_x2++;
                            ruch = 3;
                            break;
                        }
                    }

                    if (where == kierunek[1])
                    {
                        if (plansza[red_x][red_y - 1] == 0 || plansza[red_x2][red_y - 1] == 0)
                        {
                            where = minimalna3(kierunek, minimalna(kierunek), minimalna2(kierunek, minimalna(kierunek)));
                            continue;
                        }


                        if (ruch == 4 && a == 0)
                        {
                            where = minimalna2(kierunek, minimalna(kierunek));
                            a++;
                            continue;
                        }
                        else
                        {
                            gotoxy(red_x, red_y);
                            if (plansza[red_x][red_y] == 1)
                                pup();
                            else def();
                            cout << " ";
                            gotoxy(red_x2, red_y);
                            if (plansza[red_x2][red_y] == 1)
                                pup();
                            else def();
                            cout << " ";
                            gotoxy(red_x, red_y - 1);
                            pur();
                            cout << " ";
                            def();
                            gotoxy(red_x2, red_y - 1);
                            pur();
                            cout << " ";
                            def();
                            red_y--;
                            ruch = 2;
                            break;
                        }
                    }

                    if (where == kierunek[3])
                    {
                        if (plansza[red_x][red_y + 1] == 0 || plansza[red_x2][red_y + 1] == 0)
                        {
                            where = minimalna3(kierunek, minimalna(kierunek), minimalna2(kierunek, minimalna(kierunek)));
                            continue;
                        }


                        if (ruch == 2 && a == 0)
                        {
                            where = minimalna2(kierunek, minimalna(kierunek));
                            a++;
                            continue;
                        }


                        else
                        {
                            gotoxy(red_x, red_y);
                            if (plansza[red_x][red_y] == 1)
                                pup();
                            else def();
                            cout << " ";
                            gotoxy(red_x2, red_y);
                            if (plansza[red_x2][red_y] == 1)
                                pup();
                            else def();
                            cout << " ";
                            gotoxy(red_x, red_y + 1);
                            pur();
                            cout << " ";
                            def();
                            gotoxy(red_x2, red_y + 1);
                            pur();
                            cout << " ";
                            def();
                            red_y++;
                            ruch = 4;
                            break;
                        }
                    }


                    where = minimalna4(kierunek, minimalna(kierunek), minimalna2(kierunek, minimalna(kierunek)), minimalna3(kierunek, minimalna(kierunek), minimalna2(kierunek, minimalna(kierunek))));


                }


            }

            if ((x_poz == red_x && y_poz == red_y) || (x_poz2 == red_x && y_poz == red_y) || (x_poz == red_x2 && y_poz == red_y) || (x_poz2 == red_x2 && y_poz == red_y) || (x_poz == green_x && y_poz == green_y) || (x_poz2 == green_x && y_poz == green_y) || (x_poz == green_x2 && y_poz == green_y) || (x_poz2 == green_x2 && y_poz == green_y) || (x_poz == white_x && y_poz == white_y) || (x_poz2 == white_x && y_poz == white_y) || (x_poz == white_x2 && y_poz == white_y) || (x_poz2 == white_x2 && y_poz == white_y))
            {
                zycia--;
                gotoxy(x_poz, y_poz);
                cout << " ";
                gotoxy(x_poz2, y_poz);
                cout << " ";
                gotoxy(2, 6);
                pac();
                cout << " ";
                gotoxy(3, 6);
                cout << " ";
                def();
                y_poz = 6;
                y_poz2 = 6;
                x_poz = 2;
                x_poz2 = 3;
            }


            if (ruchy == 50)
            {

                if (ruchy == 50)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        gotoxy(green_x2 + 1, green_y);
                        zielony();
                        cout << " ";
                        def();
                        gotoxy(green_x, green_y);
                        def();
                        cout << " ";
                        green_x++; green_x2++;
                    }




                    for (int i = 0; i < 3; i++)
                    {
                        gotoxy(green_x, green_y - 1);
                        zielony();
                        cout << " ";
                        gotoxy(green_x, green_y);
                        def();
                        cout << " ";

                        gotoxy(green_x2, green_y - 1);
                        zielony();
                        cout << " ";
                        gotoxy(green_x2, green_y);
                        def();
                        cout << " ";

                        green_y -= 1;
                        Sleep(300);
                    }

                }

            }

            if (ruchy > 50)
            {
                while (true)
                {
                    int a = (rand() % 4) + 1;

                    if (a == 1 && plansza[green_x - 1][green_y] != 0 && green_ruch != 3)
                    {
                        gotoxy(green_x2, green_y);
                        if (plansza[green_x2][green_y] == 1)
                            pup();
                        cout << " ";
                        gotoxy(green_x - 1, green_y);
                        zielony();
                        cout << " ";
                        def();
                        green_x--;
                        green_x2--;
                        green_ruch = 1;
                        break;
                    }

                    if (a == 3 && plansza[green_x2 + 1][green_y] != 0 && green_ruch != 1)
                    {
                        gotoxy(green_x, green_y);
                        if (plansza[green_x][green_y] == 1)
                            pup();
                        cout << " ";

                        gotoxy(green_x2 + 1, green_y);
                        zielony();
                        cout << " ";
                        def();
                        green_x++;
                        green_x2++;
                        green_ruch = 3;
                        break;
                    }

                    if (a == 2 && plansza[green_x][green_y - 1] != 0 && plansza[green_x2][green_y - 1] != 0 && green_ruch != 4)
                    {
                        gotoxy(green_x, green_y);
                        if (plansza[green_x][green_y] == 1)
                            pup();
                        cout << " ";
                        gotoxy(green_x2, green_y);
                        if (plansza[green_x2][green_y] == 1)
                            pup();
                        cout << " ";
                        gotoxy(green_x, green_y - 1);
                        zielony();
                        cout << " ";
                        def();
                        gotoxy(green_x2, green_y - 1);
                        zielony();
                        cout << " ";
                        def();
                        green_y--;
                        green_ruch = 2;
                        break;
                    }

                    if (a == 4 && plansza[green_x][green_y + 1] != 0 && plansza[green_x2][green_y + 1] != 0 && green_ruch != 2)
                    {
                        gotoxy(green_x, green_y);
                        if (plansza[green_x][green_y] == 1)
                            pup();
                        cout << " ";
                        gotoxy(green_x2, green_y);
                        if (plansza[green_x2][green_y] == 1)
                            pup();
                        cout << " ";
                        gotoxy(green_x, green_y + 1);
                        zielony();
                        cout << " ";
                        def();
                        gotoxy(green_x2, green_y + 1);
                        zielony();
                        cout << " ";
                        def();
                        green_y++;
                        green_ruch = 4;
                        break;
                    }


                }






            }

            if ((x_poz == red_x && y_poz == red_y) || (x_poz2 == red_x && y_poz == red_y) || (x_poz == red_x2 && y_poz == red_y) || (x_poz2 == red_x2 && y_poz == red_y) || (x_poz == green_x && y_poz == green_y) || (x_poz2 == green_x && y_poz == green_y) || (x_poz == green_x2 && y_poz == green_y) || (x_poz2 == green_x2 && y_poz == green_y) || (x_poz == white_x && y_poz == white_y) || (x_poz2 == white_x && y_poz == white_y) || (x_poz == white_x2 && y_poz == white_y) || (x_poz2 == white_x2 && y_poz == white_y))
            {
                zycia--;
                gotoxy(x_poz, y_poz);
                cout << " ";
                gotoxy(x_poz2, y_poz);
                cout << " ";
                gotoxy(2, 6);
                pac();
                cout << " ";
                gotoxy(3, 6);
                cout << " ";
                def();
                y_poz = 6;
                y_poz2 = 6;
                x_poz = 2;
                x_poz2 = 3;
            }

            if (ruchy == 70)
            {

                if (ruchy == 70)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        gotoxy(white_x - 1, white_y);
                        red1();
                        cout << " ";
                        def();
                        gotoxy(white_x2, white_y);
                        def();
                        cout << " ";
                        white_x--; white_x2--;
                    }




                    for (int i = 0; i < 3; i++)
                    {
                        gotoxy(white_x, white_y - 1);
                        red1();
                        cout << " ";
                        gotoxy(white_x, white_y);
                        def();
                        cout << " ";

                        gotoxy(white_x2, white_y - 1);
                        red1();
                        cout << " ";
                        gotoxy(white_x2, white_y);
                        def();
                        cout << " ";

                        white_y--;
                        Sleep(300);
                    }

                }

            }

            if (ruchy > 70)
            {
                while (true)
                {
                    int a = (rand() % 4) + 1;

                    if (a == 1 && plansza[white_x - 1][white_y] != 0 && white_ruch != 3)
                    {
                        gotoxy(white_x2, white_y);
                        if (plansza[white_x2][white_y] == 1)
                            pup();
                        cout << " ";
                        gotoxy(white_x - 1, white_y);
                        red1();
                        cout << " ";
                        def();
                        white_x--;
                        white_x2--;
                        white_ruch = 1;
                        break;
                    }

                    if (a == 3 && plansza[white_x2 + 1][white_y] != 0 && white_ruch != 1)
                    {
                        gotoxy(white_x, white_y);
                        if (plansza[white_x][white_y] == 1)
                            pup();
                        cout << " ";

                        gotoxy(white_x2 + 1, white_y);
                        red1();
                        cout << " ";
                        def();
                        white_x++;
                        white_x2++;
                        white_ruch = 3;
                        break;
                    }

                    if (a == 2 && plansza[white_x][white_y - 1] != 0 && plansza[white_x2][white_y - 1] != 0 && white_ruch != 4)
                    {
                        gotoxy(white_x, white_y);
                        if (plansza[white_x][white_y] == 1)
                            pup();
                        cout << " ";
                        gotoxy(white_x2, white_y);
                        if (plansza[white_x2][white_y] == 1)
                            pup();
                        cout << " ";
                        gotoxy(white_x, white_y - 1);
                        red1();
                        cout << " ";
                        def();
                        gotoxy(white_x2, white_y - 1);
                        red1();
                        cout << " ";
                        def();
                        white_y--;
                        white_ruch = 2;
                        break;
                    }

                    if (a == 4 && plansza[white_x][white_y + 1] != 0 && plansza[white_x2][white_y + 1] != 0 && white_ruch != 2)
                    {
                        gotoxy(white_x, white_y);
                        if (plansza[white_x][white_y] == 1)
                            pup();
                        cout << " ";
                        gotoxy(white_x2, white_y);
                        if (plansza[white_x2][white_y] == 1)
                            pup();
                        cout << " ";
                        gotoxy(white_x, white_y + 1);
                        red1();
                        cout << " ";
                        def();
                        gotoxy(white_x2, white_y + 1);
                        red1();
                        cout << " ";
                        def();
                        white_y++;
                        white_ruch = 4;
                        break;
                    }


                }






            }

            if ((x_poz == red_x && y_poz == red_y) || (x_poz2 == red_x && y_poz == red_y) || (x_poz == red_x2 && y_poz == red_y) || (x_poz2 == red_x2 && y_poz == red_y) || (x_poz == green_x && y_poz == green_y) || (x_poz2 == green_x && y_poz == green_y) || (x_poz == green_x2 && y_poz == green_y) || (x_poz2 == green_x2 && y_poz == green_y) || (x_poz == white_x && y_poz == white_y) || (x_poz2 == white_x && y_poz == white_y) || (x_poz == white_x2 && y_poz == white_y) || (x_poz2 == white_x2 && y_poz == white_y))
            {
                zycia--;
                gotoxy(x_poz, y_poz);
                cout << " ";
                gotoxy(x_poz2, y_poz);
                cout << " ";
                gotoxy(2, 6);
                pac();
                cout << " ";
                gotoxy(3, 6);
                cout << " ";
                def();
                y_poz = 6;
                y_poz2 = 6;
                x_poz = 2;
                x_poz2 = 3;
            }



        }


    }

    system("cls");
    if (punkty == 0)
    {
        ekran_zwyciestwa();
    }


}











void gra()
{
    system("cls");

    ekran_zwyciestwa();

    pacmapa();

    plansza_1();


    Sleep(300000);
    system("cls");
}


int main()
{
    string name, r_nicki[10];
    char key;
    int r_wyniki[10];
    int pom = 1, ruch, pkt = 0;
    bool c = true;
    srand(time(NULL));
    int dx = 1, i = 5, l = 0;
    SetWindow1(80, 40);
    while (l < 1)
    {
        i = i + dx;
        if ((i < 1) || (i > 10)) { dx = -dx; l++; }

        SetWindow1(10 * i, 5 * i);
    }
    SetWindow(80, 40);

    //remove_scrollbar();
 //tytul();
    ShowConsoleCursor(false);
    rozdzielczosc();
    ShowConsoleCursor(true);
    nick(name);
    ShowConsoleCursor(false);
    SetWindow(80, 40);
    do
    {
        menu0(c);
        menu(c, r_wyniki, r_nicki);
        system("color 7");
        gra();
    } while (c == 0 || c == 1);
    system("PAUSE");

    plansza_1();
    Sleep(4000);
    /*
    char k;
    k=getch();
    if(k==-32)
    cout<<(int)k<<endl;
    */
    return 0;
}


