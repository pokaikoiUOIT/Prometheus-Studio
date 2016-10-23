#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <conio.h>
using namespace std;

class Gracz
{
public:
    int x;
    int y;
    int zycia;
    int amunicja;
    int czasRespawnu;
    char strona;
    bool stracil_zycie;
    int checkPoint;
};
class Zbierajka
{
public:
    int x;
    int y;
    bool istnieje;
};

class ArmataPoz
{
public:
    int x;
    int y;
    char strona;
    int szybkosc;
    bool istnieje;
};
class ArmataPio
{
public:
    int x;
    int y;
    char strona;
    int szybkosc;
    bool istnieje;
};

class BiegaczPoz
{
public:
    int x;
    int y;
    int zycia;
    char strona;
};

class Randomer
{
public:
    int x;
    int y;
    int xMax;
    int xMin;
    int yMax;
    int yMin;
    int zycia;
    bool udanyRuch;
    int szybkosc;
};
class Scigacz
{
public:
    int x;
    int y;
    bool istnieje;
    int szybkosc();
};

class Pocisk
{
public:
    int x;
    int y;
    char strona;
    bool istnieje;
    bool pierwszyRaz;
};

Gracz gracz;
int odswierzanie;
int bossZycie;
bool bossPostawiony=false;
bool scigaczePostawieni=false;
char c;
bool wyjscie=false;
bool wGrze;
Scigacz scigacz[30];
Zbierajka zbierajka[40];
Randomer randomer[50];
ArmataPoz armataPoz[50];
ArmataPio armataPio[50];
BiegaczPoz biegaczPoz[100];
Pocisk pocisk[400];
int nrPocisk;
int licznikPrzejsc;


void SetWindow(int Width, int Height)
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

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
char getCursorChar()
{
    char c = '\0';
    CONSOLE_SCREEN_BUFFER_INFO con;
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hcon != INVALID_HANDLE_VALUE &&
        GetConsoleScreenBufferInfo(hcon,&con))
    {
        DWORD read = 0;
        if (!ReadConsoleOutputCharacterA(hcon,&c,1,
            con.dwCursorPosition,&read) || read != 1
            )
            c = '\0';
    }
    return c;
}


void zaladujPoziomPodstawa(string fileName)
{
    string getcontent;
    ifstream openfile(fileName.c_str());
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    if(openfile.is_open())
    {
        while(! openfile.eof())
        {
            getline(openfile, getcontent);
            cout << getcontent << endl;
        }
    }
}


char readChar(int x,int y)
{
    gotoxy(x,y);
    char ccccc = getCursorChar();
    return ccccc;
}

void tworzSkrzynie(int x,int y)
{
    gotoxy(x,y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
    cout<<"@";
}
void tworzScigacza(int lp,int x,int y)
{
    scigacz[lp].x=x;
    scigacz[lp].y=y;
    scigacz[lp].istnieje=true;
    gotoxy(x,y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
    cout<<"&";
}

void tworzArmatePoz(int lp, int x,int y, char strona,int szybkosc)
{
    armataPoz[lp].x=x;
    armataPoz[lp].y=y;
    armataPoz[lp].strona=strona;
    armataPoz[lp].szybkosc=szybkosc;
    armataPoz[lp].istnieje=true;
    gotoxy(x,y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout<<"-";
}
void tworzArmatePio(int lp, int x,int y, char strona,int szybkosc)
{
    armataPio[lp].x=x;
    armataPio[lp].y=y;
    armataPio[lp].strona=strona;
    armataPio[lp].szybkosc=szybkosc;
    armataPio[lp].istnieje=true;
    gotoxy(x,y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout<<"|";
}

void tworzRandomer(int lp,int x,int y, int zycia,int zakres,int szybkosc)
{
    randomer[lp].x=x;
    randomer[lp].y=y;
    randomer[lp].xMin=x-zakres;
    randomer[lp].yMin=y-zakres;
    randomer[lp].xMax=x+zakres;
    randomer[lp].yMax=y+zakres;
    randomer[lp].zycia=zycia;
    randomer[lp].szybkosc=szybkosc;
    gotoxy(x,y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
    cout<<"%";
}

void tworzBiegaczaPoz(int lp,int x,int y,char strona,int zycia)
{
    biegaczPoz[lp].x=x;
    biegaczPoz[lp].y=y;
    biegaczPoz[lp].zycia=zycia;
    biegaczPoz[lp].strona=strona;
    gotoxy(x,y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"S";
}
void tworzZbierajkeZycie(int lp,int x,int y)
{
    zbierajka[lp].istnieje=true;
    zbierajka[lp].x=x;
    zbierajka[lp].y=y;
    gotoxy(x,y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"+";
}

void tworzZbierajkeAmunicja(int lp,int x,int y)
{
    zbierajka[lp].istnieje=true;
    zbierajka[lp].x=x;
    zbierajka[lp].y=y;
    gotoxy(x,y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
    cout<<"A";
}

void tworzZbierajkeCheckPoint(int lp,int x,int y)
{
    zbierajka[lp].istnieje=true;
    zbierajka[lp].x=x;
    zbierajka[lp].y=y;
    gotoxy(x,y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
    cout<<"C";
}


void tworzBossa()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
    gotoxy(69,19);
    cout<<"XXXXXXX";
    gotoxy(68,20);
    cout<<"XXXXXXXXX";
    gotoxy(67,21);
    cout<<"XXXXXXXXXXX";
    gotoxy(66,22);
    cout<<"XXXXXXXXXXXXX";
    gotoxy(66,23);
    cout<<"XXX XXXXX XXX";
    gotoxy(66,24);
    cout<<"XX   XXX   XX";
    gotoxy(66,25);
    cout<<"XXX XX XX XXX";
    gotoxy(66,26);
    cout<<"XXXXXX XXXXXX";
    gotoxy(67,27);
    cout<<"XXXXXXXXXXX";
    gotoxy(67,28);
    cout<<"X  XXXXX  X";
    gotoxy(67,29);
    cout<<"XX X X X XX";
    gotoxy(68,30);
    cout<<"X       X";
    gotoxy(68,31);
    cout<<"X       X";
    gotoxy(68,32);
    cout<<"XX X X XX";
    gotoxy(68,33);
    cout<<"XXXXXXXXX";
    gotoxy(69,34);
    cout<<"XXXXXXX";
    gotoxy(70,35);
    cout<<"XXXXX";
    gotoxy(70,36);
    cout<<"XXXXX";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    gotoxy(85,14);
    cout<<"#";

    for(int i=0; i<=2;i++)
    {
        tworzArmatePoz(20+i,60,16+i,'d',30);
    }
    tworzArmatePoz(23,85,17,'a',30);
    tworzArmatePoz(24,85,18,'a',30);

    tworzArmatePoz(25,60,34,'d',30);
    tworzArmatePoz(26,68,34,'a',28);
    tworzArmatePoz(27,76,34,'d',28);
    tworzArmatePoz(28,85,34,'a',30);
    tworzArmatePoz(29,69,35,'a',20);
    tworzArmatePoz(30,75,35,'d',20);
    tworzArmatePoz(31,69,36,'a',20);
    tworzArmatePoz(32,75,36,'d',20);

    tworzBiegaczaPoz(43,60,15,'d',2);

    tworzBiegaczaPoz(44,60,19,'a',2);
    tworzBiegaczaPoz(45,60,20,'a',2);
    tworzBiegaczaPoz(46,85,19,'d',2);
    tworzBiegaczaPoz(47,85,20,'d',2);
    tworzBiegaczaPoz(48,60,27,'d',2);

    tworzRandomer(8,82,24,2,3,2);
    tworzRandomer(9,63,24,2,2,3);

    tworzRandomer(10,82,29,2,4,2);
    tworzRandomer(11,64,31,2,2,3);

    for (int i=0; i<=7;i++)
        {
            tworzZbierajkeAmunicja(12+i,60+i,36);
            tworzZbierajkeAmunicja(19+i,78+i,36);
        }
}

void tworzBossaPokonany()
{
    for (int j=0;j<=4;j++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
        gotoxy(69,19);
        cout<<"XXXXXXX";
        gotoxy(68,20);
        cout<<"XXXXXXXXX";
        gotoxy(67,21);
        cout<<"XXXXXXXXXXX";
        gotoxy(66,22);
        cout<<"XXXXXXXXXXXXX";
        gotoxy(66,23);
        cout<<"XXX XXXXX XXX";
        gotoxy(66,24);
        cout<<"XX   XXX   XX";
        gotoxy(66,25);
        cout<<"XXX XX XX XXX";
        gotoxy(66,26);
        cout<<"XXXXXX XXXXXX";
        gotoxy(67,27);
        cout<<"XXXXXXXXXXX";
        gotoxy(67,28);
        cout<<"X  XXXXX  X";
        gotoxy(67,29);
        cout<<"XX X X X XX";
        gotoxy(68,30);
        cout<<"X       X";
        gotoxy(68,31);
        cout<<"X       X";
        gotoxy(68,32);
        cout<<"XX X X XX";
        gotoxy(68,33);
        cout<<"XXXXXXXXX";
        gotoxy(69,34);
        cout<<"XXXXXXX";
        gotoxy(70,35);
        cout<<"XXXXX";
        gotoxy(70,36);
        cout<<"XXXXX";
        Sleep(200);
        for(int i=0;i<=18;i++)
        {
            gotoxy(65,18+i);
            cout<<"               ";
        }
        Sleep(200);
    }
}

void tworzBossa1Raz()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
    gotoxy(69,19);
    cout<<"XXXXXXX";
    Sleep(50);
    gotoxy(68,20);
    cout<<"XXXXXXXXX";
    Sleep(50);
    gotoxy(67,21);
    cout<<"XXXXXXXXXXX";
    Sleep(50);
    gotoxy(66,22);
    cout<<"XXXXXXXXXXXXX";
    Sleep(50);
    gotoxy(66,23);
    cout<<"XXX XXXXX XXX";
    Sleep(50);
    gotoxy(66,24);
    cout<<"XX   XXX   XX";
    Sleep(50);
    gotoxy(66,25);
    cout<<"XXX XX XX XXX";
    Sleep(50);
    gotoxy(66,26);
    cout<<"XXXXXX XXXXXX";
    Sleep(50);
    gotoxy(67,27);
    cout<<"XXXXXXXXXXX";
    Sleep(50);
    gotoxy(67,28);
    cout<<"X  XXXXX  X";
    Sleep(50);
    gotoxy(67,29);
    cout<<"XX X X X XX";
    Sleep(50);
    gotoxy(68,30);
    cout<<"X       X";
    Sleep(50);
    gotoxy(68,31);
    cout<<"X       X";
    Sleep(50);
    gotoxy(68,32);
    cout<<"XX X X XX";
    Sleep(50);
    gotoxy(68,33);
    cout<<"XXXXXXXXX";
    Sleep(50);
    gotoxy(69,34);
    cout<<"XXXXXXX";
    Sleep(50);
    gotoxy(70,35);
    cout<<"XXXXX";
    Sleep(50);
    gotoxy(70,36);
    cout<<"XXXXX";
    Sleep(50);
    tworzBossa();
}

void zaladujPoziomObiekty(int nrPoziomu)
{
    if (nrPoziomu==1)
    {
        tworzSkrzynie(53,31);
        tworzSkrzynie(56,33);
        tworzSkrzynie(57,34);
        for (int i=0; i<=3; i++)
        {
            tworzSkrzynie(52,15+i*2);
        }
        tworzSkrzynie(53,15);
        for (int i=0; i<=2; i++)
        {
            tworzSkrzynie(53,16+i*2);
        }
        for (int i=0; i<=3; i++)
        {
            tworzSkrzynie(54,15+i*2);
        }
        for (int i=0; i<=1; i++)
        {
            tworzSkrzynie(55,16+i*2);
        }
        for (int i=0; i<=2; i++)
        {
            tworzSkrzynie(56,15+i*2);
        }
        tworzSkrzynie(13,25);

        tworzSkrzynie(1,13);
        tworzSkrzynie(2,12);
        tworzSkrzynie(2,11);
        tworzSkrzynie(2,10);
        tworzSkrzynie(3,11);
        tworzSkrzynie(4,12);
        tworzSkrzynie(4,11);
        tworzSkrzynie(5,10);
        tworzSkrzynie(1,9);
        tworzSkrzynie(3,8);

        tworzSkrzynie(4,9);
        tworzSkrzynie(4,13);
        tworzSkrzynie(6,12);
        tworzSkrzynie(7,11);
        tworzSkrzynie(8,10);
        tworzSkrzynie(9,9);
        tworzSkrzynie(10,8);
        tworzSkrzynie(11,9);
        tworzSkrzynie(11,12);
        tworzSkrzynie(6,13);

        tworzSkrzynie(35,12);
        tworzSkrzynie(35,13);
        tworzSkrzynie(36,12);
        tworzSkrzynie(34,13);

        tworzSkrzynie(34,7);
        tworzSkrzynie(34,8);
        tworzSkrzynie(34,6);

        tworzSkrzynie(35,7);
        tworzSkrzynie(35,8);
        tworzSkrzynie(36,8);

        tworzSkrzynie(35,10);

        for (int i=0; i<=4; i++)
        {
            tworzSkrzynie(36+i,9);
            tworzSkrzynie(36+i,11);
        }
        tworzSkrzynie(52,3);
        tworzSkrzynie(42,13);


//---------------------------------------------------------------
        tworzArmatePoz(1,11,28,'d',35);

        tworzArmatePoz(2,54,29,'a',20);
        tworzArmatePoz(3,54,33,'a',15);

        tworzArmatePoz(4,58,23,'a',3);
        tworzArmatePoz(5,58,24,'a',3);
        tworzArmatePoz(6,58,25,'a',3);

        for (int i=0; i<=5; i++)
        {
            tworzArmatePoz(7+i,17,1+i,'d',40-i*3);
        }
        tworzArmatePoz(13,33,6,'a',30);

        for (int i=0; i<=4; i++)
        {
            tworzArmatePoz(14+i,85,2+i,'a',50-i*5);
        }
//---------------------------------------------------------------
        tworzArmatePio(1,5,25,'s',40);

        tworzArmatePio(2,26,29,'s',30);
        tworzArmatePio(3,27,29,'s',40);
        tworzArmatePio(4,28,29,'s',35);
        tworzArmatePio(5,29,29,'s',50);

        tworzArmatePio(6,31,29,'s',25);
        tworzArmatePio(7,32,29,'s',30);
        tworzArmatePio(8,33,29,'s',35);
        tworzArmatePio(9,34,29,'s',40);
        tworzArmatePio(10,35,29,'s',45);
        tworzArmatePio(11,36,29,'s',50);

        tworzArmatePio(12,41,36,'w',20);
        tworzArmatePio(13,43,36,'w',20);
        tworzArmatePio(14,45,36,'w',20);
        tworzArmatePio(15,47,36,'w',20);

        tworzArmatePio(16,47,15,'s',1);

        tworzArmatePio(17,13,26,'w',2);

        tworzArmatePio(18,5,15,'s',40);

        for (int i=0; i<=14; i++)
        {
            tworzArmatePio(19+i,18+i,8,'s',2);
        }

        for (int i=0; i<=5; i++)
        {
            tworzArmatePio(34+i,78+i,1,'s',25+i*3);
        }

//---------------------------------------------------------------

        tworzBiegaczaPoz(1,7,33,'d',2);
        tworzBiegaczaPoz(2,13,31,'a',2);

        tworzBiegaczaPoz(3,38,33,'d',2);
        tworzBiegaczaPoz(4,40,32,'d',2);
        tworzBiegaczaPoz(5,42,31,'a',2);
        tworzBiegaczaPoz(6,44,30,'d',2);
        tworzBiegaczaPoz(7,46,29,'d',2);

        tworzBiegaczaPoz(8,48,28,'d',2);
        tworzBiegaczaPoz(9,54,30,'a',2);
        tworzBiegaczaPoz(10,54,34,'a',2);

        tworzBiegaczaPoz(11,7,17,'d',2);
        tworzBiegaczaPoz(12,22,18,'a',2);
        tworzBiegaczaPoz(13,7,19,'d',2);
        tworzBiegaczaPoz(14,22,20,'a',2);
        tworzBiegaczaPoz(15,7,21,'d',2);
        tworzBiegaczaPoz(16,22,22,'a',2);
        tworzBiegaczaPoz(17,7,23,'d',2);
        tworzBiegaczaPoz(18,22,24,'a',2);

        tworzBiegaczaPoz(19,1,2,'a',2);
        tworzBiegaczaPoz(20,2,3,'d',2);
        tworzBiegaczaPoz(23,8,2,'a',2);
        tworzBiegaczaPoz(24,7,3,'a',2);
        tworzBiegaczaPoz(27,9,4,'a',2);
        tworzBiegaczaPoz(28,9,3,'a',2);
        tworzBiegaczaPoz(29,15,4,'a',2);
        tworzBiegaczaPoz(30,15,5,'a',2);

        tworzBiegaczaPoz(31,36,10,'d',2);

        tworzBiegaczaPoz(32,37,7,'d',2);
        tworzBiegaczaPoz(33,37,8,'d',2);
        tworzBiegaczaPoz(34,37,12,'d',2);
        tworzBiegaczaPoz(35,37,13,'d',2);
        tworzBiegaczaPoz(36,36,6,'d',2);

        tworzBiegaczaPoz(37,59,11,'d',2);
        tworzBiegaczaPoz(38,64,12,'d',2);
        tworzBiegaczaPoz(39,62,13,'d',2);
        tworzBiegaczaPoz(40,75,11,'d',2);
        tworzBiegaczaPoz(42,77,13,'d',2);
//---------------------------------------------------------------
        if (gracz.checkPoint>=4)
        {
            tworzScigacza(1,42,9);
            tworzScigacza(2,45,13);
            tworzScigacza(3,42,4);
            tworzScigacza(4,51,7);
            tworzScigacza(5,55,7);
            tworzScigacza(6,59,7);
            tworzScigacza(7,61,7);
        }
        if (gracz.checkPoint>=5)
        {
            tworzBossa();
        }
//---------------------------------------------------------------
        tworzRandomer(1,18,33,2,3,3);
        tworzRandomer(2,30,21,2,6,3);

        tworzRandomer(3,41,18,2,3,2);
        tworzRandomer(4,30,21,2,6,2);
        tworzRandomer(5,30,21,2,6,3);
        tworzRandomer(6,30,21,2,6,3);
//---------------------------------------------------------------
        if (zbierajka[1].istnieje==true)
        {
            tworzZbierajkeAmunicja(1,15,36);
        }
        if (zbierajka[2].istnieje==true)
        {
            tworzZbierajkeAmunicja(2,8,1);
        }
        if (zbierajka[3].istnieje==true)
        {
            tworzZbierajkeZycie(3,40,35);
        }
        if (zbierajka[4].istnieje==true)
        {
            tworzZbierajkeZycie(4,25,15);
        }
        if (zbierajka[5].istnieje==true)
        {
            tworzZbierajkeZycie(5,22,6);
        }
        if (zbierajka[6].istnieje==true)
        {
            tworzZbierajkeCheckPoint(6,56,22);
        }
        if (zbierajka[7].istnieje==true)
        {
            tworzZbierajkeCheckPoint(7,4,23);
        }
        if (zbierajka[8].istnieje==true)
        {
            tworzZbierajkeCheckPoint(8,33,11);
        }
        if (zbierajka[9].istnieje==true)
        {
            tworzZbierajkeCheckPoint(9,42,12);
        }
        if (zbierajka[10].istnieje==true)
        {
            tworzZbierajkeZycie(10,58,12);
        }
        if (zbierajka[11].istnieje==true)
        {
            tworzZbierajkeCheckPoint(11,85,15);
        }
    }
}

int kolizjaRandomera(int lp,char strona)
{
    if(strona=='w')
    {
        if ((readChar(randomer[lp].x,randomer[lp].y-1)==' ')||(readChar(randomer[lp].x,randomer[lp].y-1)=='%'))
        {
            return 0;
        }else if ((readChar(randomer[lp].x,randomer[lp].y-1)=='#') || (readChar(randomer[lp].x,randomer[lp].y-1)=='@')|| (readChar(randomer[lp].x,randomer[lp].y-1)=='-')|| (readChar(randomer[lp].x,randomer[lp].y-1)=='|')|| (readChar(randomer[lp].x,randomer[lp].y-1)=='A')|| (readChar(randomer[lp].x,randomer[lp].y-1)=='+')|| (readChar(randomer[lp].x,randomer[lp].y-1)=='S')|| (readChar(randomer[lp].x,randomer[lp].y-1)=='%')|| (readChar(randomer[lp].x,randomer[lp].y-1)=='X'))
        {
            return 2;
        }else return 1;
    }
    if(strona=='s')
    {
        if ((readChar(randomer[lp].x,randomer[lp].y+1)==' ')||(readChar(randomer[lp].x,randomer[lp].y+1)=='%'))
        {
            return 0;
        }else if ((readChar(randomer[lp].x,randomer[lp].y+1)=='#') || (readChar(randomer[lp].x,randomer[lp].y+1)=='@')|| (readChar(randomer[lp].x,randomer[lp].y+1)=='-')|| (readChar(randomer[lp].x,randomer[lp].y+1)=='|')|| (readChar(randomer[lp].x,randomer[lp].y+1)=='A')|| (readChar(randomer[lp].x,randomer[lp].y+1)=='+')|| (readChar(randomer[lp].x,randomer[lp].y+1)=='S')|| (readChar(randomer[lp].x,randomer[lp].y+1)=='%')|| (readChar(randomer[lp].x,randomer[lp].y+1)=='X'))
        {
            return 2;
        }else return 1;
    }
    if(strona=='a')
    {
        if ((readChar(randomer[lp].x-1,randomer[lp].y)==' ')||(readChar(randomer[lp].x-1,randomer[lp].y)=='%'))
        {
            return 0;
        }else if ((readChar(randomer[lp].x-1,randomer[lp].y)=='#') || (readChar(randomer[lp].x-1,randomer[lp].y)=='@')|| (readChar(randomer[lp].x-1,randomer[lp].y)=='-')|| (readChar(randomer[lp].x-1,randomer[lp].y)=='|')|| (readChar(randomer[lp].x-1,randomer[lp].y)=='A')|| (readChar(randomer[lp].x-1,randomer[lp].y)=='+')|| (readChar(randomer[lp].x-1,randomer[lp].y)=='S')|| (readChar(randomer[lp].x-1,randomer[lp].y)=='%')|| (readChar(randomer[lp].x-1,randomer[lp].y)=='X'))
        {
            return 2;
        }else return 1;
    }
    if (strona=='d')
    {
        if ((readChar(randomer[lp].x+1,randomer[lp].y)==' ')||(readChar(randomer[lp].x+1,randomer[lp].y)=='%'))
        {
            return 0;
        }else if ((readChar(randomer[lp].x+1,randomer[lp].y)=='#') || (readChar(randomer[lp].x+1,randomer[lp].y)=='@')|| (readChar(randomer[lp].x+1,randomer[lp].y)=='-')|| (readChar(randomer[lp].x+1,randomer[lp].y)=='|')|| (readChar(randomer[lp].x+1,randomer[lp].y)=='A')|| (readChar(randomer[lp].x+1,randomer[lp].y)=='+')|| (readChar(randomer[lp].x+1,randomer[lp].y)=='S')|| (readChar(randomer[lp].x+1,randomer[lp].y)=='%')|| (readChar(randomer[lp].x+1,randomer[lp].y)=='X'))
        {
            return 2;
        }else return 1;
    }
}
void aktualizuj()
{
    if ((gracz.checkPoint==4) && (scigaczePostawieni==false))
    {
        tworzScigacza(1,42,9);
        tworzScigacza(2,45,13);
        tworzScigacza(3,42,4);
        tworzScigacza(4,51,7);
        tworzScigacza(5,55,7);
        tworzScigacza(6,59,7);
        tworzScigacza(7,61,7);
        scigaczePostawieni=true;
    }
    if ((gracz.checkPoint==5)&& (bossPostawiony==false))
    {
        tworzBossa1Raz();
        bossPostawiony=true;
    }
    if ((c=='w')|| (c=='s') || (c=='a') || (c=='d'))
    {
        if (c=='w')
        {
            gracz.strona='w';
            gotoxy(gracz.x,gracz.y);
            cout<<" ";
            if ((readChar(gracz.x,gracz.y-1)!= '#') && (readChar(gracz.x,gracz.y-1)!= '-') && (readChar(gracz.x,gracz.y-1)!= '|')&& (readChar(gracz.x,gracz.y-1)!= 'X'))
            {
                if (readChar(gracz.x,gracz.y-1)=='@')
                {
                    if ((readChar(gracz.x,gracz.y-2)==' ') || (readChar(gracz.x,gracz.y-2)=='o'))
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
                        gotoxy(gracz.x,gracz.y-2);
                        cout<<"@";
                        gracz.y-=1;
                    }
                }else
                {
                    gracz.y-=1;
                }
            }
        }

        if (c=='s')
        {
            gracz.strona='s';
            gotoxy(gracz.x,gracz.y);
            cout<<" ";
            if ((readChar(gracz.x,gracz.y+1)!= '#') && (readChar(gracz.x,gracz.y+1)!= '-') && (readChar(gracz.x,gracz.y+1)!= '|')&& (readChar(gracz.x,gracz.y+1)!= 'X'))
            {
                if (readChar(gracz.x,gracz.y+1)=='@')
                {
                    if ((readChar(gracz.x,gracz.y+2)==' ') || (readChar(gracz.x,gracz.y+2)=='o'))
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
                        gotoxy(gracz.x,gracz.y+2);
                        cout<<"@";
                        gracz.y+=1;
                    }
                }else
                {
                    gracz.y+=1;
                }
            }
        }

        if (c=='a')
        {
            gracz.strona='a';
            gotoxy(gracz.x,gracz.y);
            cout<<" ";
            if ((readChar(gracz.x-1,gracz.y)!= '#') && (readChar(gracz.x-1,gracz.y)!= '-') && (readChar(gracz.x-1,gracz.y)!= '|')&& (readChar(gracz.x-1,gracz.y)!= 'X'))
            {
                if (readChar(gracz.x-1,gracz.y)=='@')
                {
                    if ((readChar(gracz.x-2,gracz.y)==' ') || (readChar(gracz.x-2,gracz.y)=='o'))
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
                        gotoxy(gracz.x-2,gracz.y);
                        cout<<"@";
                        gracz.x-=1;
                    }
                }else
                {
                    gracz.x-=1;
                }
            }
        }

        if (c=='d')
        {
            gracz.strona='d';
            gotoxy(gracz.x,gracz.y);
            cout<<" ";
            if ((readChar(gracz.x+1,gracz.y)!= '#') && (readChar(gracz.x+1,gracz.y)!= '-') && (readChar(gracz.x+1,gracz.y)!= '|')&& (readChar(gracz.x+1,gracz.y)!= 'X'))
            {
                if (readChar(gracz.x+1,gracz.y)=='@')
            {
                    if ((readChar(gracz.x+2,gracz.y)==' ') || (readChar(gracz.x+2,gracz.y)=='o'))
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
                        gotoxy(gracz.x+2,gracz.y);
                        cout<<"@";
                        gracz.x+=1;
                    }
                }else
                {
                    gracz.x+=1;
                }
            }
        }
        if (readChar(gracz.x,gracz.y)== 'A')
        {
            gracz.amunicja+=5;
            for(int i=0; i<=20; i++)
            {
                if ((gracz.x==zbierajka[i].x) && (gracz.y==zbierajka[i].y))
                {
                    zbierajka[i].istnieje=false;
                }
            }
        }
        if (readChar(gracz.x,gracz.y)== '+')
        {
            gracz.zycia+=1;
            for(int i=0; i<=20; i++)
            {
                if ((gracz.x==zbierajka[i].x) && (gracz.y==zbierajka[i].y))
                {
                    zbierajka[i].istnieje=false;
                }
            }
        }
        if (readChar(gracz.x,gracz.y)== 'C')
        {
            gracz.checkPoint+=1;
            for(int i=0; i<=20; i++)
            {
                if ((gracz.x==zbierajka[i].x) && (gracz.y==zbierajka[i].y))
                {
                    zbierajka[i].istnieje=false;
                }
            }
        }
        if (readChar(gracz.x,gracz.y)== 'S')
        {
            gracz.zycia-=1;
            gracz.stracil_zycie=true;
        }
        if (readChar(gracz.x,gracz.y)== '%')
        {
            gracz.zycia-=1;
            gracz.stracil_zycie=true;
        }
        if (readChar(gracz.x,gracz.y)== 'o')
        {
            gracz.zycia-=1;
            gracz.stracil_zycie=true;
        }
        if (readChar(gracz.x,gracz.y)== '&')
        {
            gracz.zycia-=1;
            gracz.stracil_zycie=true;
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        gotoxy(gracz.x,gracz.y);
        if (gracz.strona=='w')
        {
            cout<<char(24);
        }
        if (gracz.strona=='s')
        {
            cout<<char(25);
        }
        if (gracz.strona=='a')
        {
            cout<<char(27);
        }
        if (gracz.strona=='d')
        {
            cout<<char(26);
        }
    }
    int r;
    int awaryjnyWylacnzik;
    for (int i=0; i<=50; i++)
    {
        if (randomer[i].zycia>0)
        {
            if ((licznikPrzejsc % randomer[i].szybkosc)==0)
            {
                gotoxy(randomer[i].x,randomer[i].y);
                cout<<" ";
                randomer[i].udanyRuch=false;
                while (randomer[i].udanyRuch==false)
                {
                    awaryjnyWylacnzik+=1;
                    r=rand()%4+1;
                    if ((r==1) && (randomer[i].y>randomer[i].yMin) && (kolizjaRandomera(i,'w')==0))
                    {
                        randomer[i].y-=1;
                        randomer[i].udanyRuch=true;
                    } else if ((r==1) && (randomer[i].y>randomer[i].yMin) && (kolizjaRandomera(i,'w')==1))
                    {
                        gracz.zycia-=1;
                        gracz.stracil_zycie=true;
                    }
                    if ((r==2) && (randomer[i].y<randomer[i].yMax) && (kolizjaRandomera(i,'s')==0))
                    {
                        randomer[i].y+=1;
                        randomer[i].udanyRuch=true;
                    } else if ((r==2) && (randomer[i].y<randomer[i].yMax) && (kolizjaRandomera(i,'s')==1))
                    {
                        gracz.zycia-=1;
                        gracz.stracil_zycie=true;
                    }
                    if ((r==3) && (randomer[i].x>randomer[i].xMin) && (kolizjaRandomera(i,'a')==0))
                    {
                        randomer[i].x-=1;
                        randomer[i].udanyRuch=true;
                    } else if ((r==3) && (randomer[i].x>randomer[i].xMin) && (kolizjaRandomera(i,'a')==1))
                    {
                        gracz.zycia-=1;
                        gracz.stracil_zycie=true;
                    }
                    if ((r==4) && (randomer[i].x<randomer[i].xMax) && (kolizjaRandomera(i,'d')==0))
                    {
                        randomer[i].x+=1;
                        randomer[i].udanyRuch=true;
                    } else if ((r==4) && (randomer[i].x<randomer[i].xMax) && (kolizjaRandomera(i,'d')==1))
                    {
                        gracz.zycia-=1;
                        gracz.stracil_zycie=true;
                    }
                    if (awaryjnyWylacnzik>=50)
                    {
                        randomer[i].udanyRuch=true;
                    }
                }
                gotoxy(randomer[i].x,randomer[i].y);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
                if (randomer[i].zycia<=1)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
                }
                cout<<"%";
            }
        }
    }

    for (int i=0; i<=30; i++)
    {
        if (scigacz[i].istnieje==true)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
            if (abs(scigacz[i].x-gracz.x)>=(abs(scigacz[i].y-gracz.y)))
            {
                if(scigacz[i].x>=gracz.x)
                {
                    if(readChar(scigacz[i].x-1,scigacz[i].y)==' ')
                    {
                        gotoxy(scigacz[i].x,scigacz[i].y);
                        cout<<" ";
                        scigacz[i].x-=1;
                        gotoxy(scigacz[i].x,scigacz[i].y);
                        cout<<"&";
                    }else if ((readChar(scigacz[i].x-1,scigacz[i].y)!='#') && (readChar(scigacz[i].x-1,scigacz[i].y)!='@') &&(readChar(scigacz[i].x-1,scigacz[i].y)!='A') && (readChar(scigacz[i].x-1,scigacz[i].y)!='+') && (readChar(scigacz[i].x-1,scigacz[i].y)!='&') && (readChar(scigacz[i].x-1,scigacz[i].y)!='S')&&(readChar(scigacz[i].x-1,scigacz[i].y)!='o') && (readChar(scigacz[i].x-1,scigacz[i].y)!='%'))
                    {
                        gracz.stracil_zycie=true;
                        gracz.zycia-=1;
                    }
                }else if(scigacz[i].x<gracz.x)
                {
                    if(readChar(scigacz[i].x+1,scigacz[i].y)==' ')
                    {
                        gotoxy(scigacz[i].x,scigacz[i].y);
                        cout<<" ";
                        scigacz[i].x+=1;
                        gotoxy(scigacz[i].x,scigacz[i].y);
                        cout<<"&";
                    }else if ((readChar(scigacz[i].x+1,scigacz[i].y)!='#') && (readChar(scigacz[i].x+1,scigacz[i].y)!='@') &&(readChar(scigacz[i].x+1,scigacz[i].y)!='A') && (readChar(scigacz[i].x+1,scigacz[i].y)!='+') && (readChar(scigacz[i].x+1,scigacz[i].y)!='&') && (readChar(scigacz[i].x+1,scigacz[i].y)!='S')&&(readChar(scigacz[i].x+1,scigacz[i].y)!='o') && (readChar(scigacz[i].x+1,scigacz[i].y)!='%'))
                    {
                        gracz.stracil_zycie=true;
                        gracz.zycia-=1;
                    }
                }
            }else if (abs(scigacz[i].x-gracz.x)<(abs(scigacz[i].y-gracz.y)))
            {
                if(scigacz[i].y>=gracz.y)
                {
                    if(readChar(scigacz[i].x,scigacz[i].y-1)==' ')
                    {
                        gotoxy(scigacz[i].x,scigacz[i].y);
                        cout<<" ";
                        scigacz[i].y-=1;
                        gotoxy(scigacz[i].x,scigacz[i].y);
                        cout<<"&";
                    }else if ((readChar(scigacz[i].x,scigacz[i].y-1)!='#') && (readChar(scigacz[i].x,scigacz[i].y-1)!='@') &&(readChar(scigacz[i].x,scigacz[i].y-1)!='A') && (readChar(scigacz[i].x,scigacz[i].y-1)!='+') && (readChar(scigacz[i].x,scigacz[i].y-1)!='&') && (readChar(scigacz[i].x,scigacz[i].y-1)!='S')&&(readChar(scigacz[i].x,scigacz[i].y-1)!='o') && (readChar(scigacz[i].x,scigacz[i].y-1)!='%'))
                    {
                        gracz.stracil_zycie=true;
                        gracz.zycia-=1;
                    }
                }else if(scigacz[i].y<gracz.y)
                {
                    if(readChar(scigacz[i].x,scigacz[i].y+1)==' ')
                    {
                        gotoxy(scigacz[i].x,scigacz[i].y);
                        cout<<" ";
                        scigacz[i].y+=1;
                        gotoxy(scigacz[i].x,scigacz[i].y);
                        cout<<"&";
                    }else if ((readChar(scigacz[i].x,scigacz[i].y+1)!='#') && (readChar(scigacz[i].x,scigacz[i].y+1)!='@') &&(readChar(scigacz[i].x,scigacz[i].y+1)!='A') && (readChar(scigacz[i].x,scigacz[i].y+1)!='+') && (readChar(scigacz[i].x,scigacz[i].y+1)!='&') && (readChar(scigacz[i].x,scigacz[i].y+1)!='S')&&(readChar(scigacz[i].x,scigacz[i].y+1)!='o') && (readChar(scigacz[i].x,scigacz[i].y+1)!='%'))
                    {
                        gracz.stracil_zycie=true;
                        gracz.zycia-=1;
                    }
                }
            }
        }
    }

    for (int i=0;i<=100;i++)
    {
        if (biegaczPoz[i].zycia>0)
        {
            gotoxy(biegaczPoz[i].x,biegaczPoz[i].y);
            cout<<" ";
            if (biegaczPoz[i].strona=='d')
            {
                if (readChar(biegaczPoz[i].x+1,biegaczPoz[i].y)==' ')
                {
                    biegaczPoz[i].x+=1;
                }else if (readChar(biegaczPoz[i].x+1,biegaczPoz[i].y)=='#')
                {
                    biegaczPoz[i].strona='a';
                }else if (readChar(biegaczPoz[i].x+1,biegaczPoz[i].y)=='X')
                {
                    biegaczPoz[i].strona='a';
                }else if (readChar(biegaczPoz[i].x+1,biegaczPoz[i].y)=='@')
                {
                    biegaczPoz[i].strona='a';
                }else if (readChar(biegaczPoz[i].x+1,biegaczPoz[i].y)=='+')
                {
                    biegaczPoz[i].strona='a';
                }else if (readChar(biegaczPoz[i].x+1,biegaczPoz[i].y)=='A')
                {
                    biegaczPoz[i].strona='a';
                }else if (readChar(biegaczPoz[i].x+1,biegaczPoz[i].y)=='S')
                {
                    biegaczPoz[i].strona='a';
                }else if (readChar(biegaczPoz[i].x+1,biegaczPoz[i].y)=='o')
                {
                    //NIC
                }else
                {
                    gracz.zycia-=1;
                    gracz.stracil_zycie=true;
                }
            }else if (biegaczPoz[i].strona=='a')
            {
                if (readChar(biegaczPoz[i].x-1,biegaczPoz[i].y)==' ')
                {
                    biegaczPoz[i].x-=1;
                }else if (readChar(biegaczPoz[i].x-1,biegaczPoz[i].y)=='#')
                {
                    biegaczPoz[i].strona='d';
                }else if (readChar(biegaczPoz[i].x-1,biegaczPoz[i].y)=='X')
                {
                    biegaczPoz[i].strona='d';
                }else if (readChar(biegaczPoz[i].x-1,biegaczPoz[i].y)=='@')
                {
                    biegaczPoz[i].strona='d';
                }else if (readChar(biegaczPoz[i].x-1,biegaczPoz[i].y)=='+')
                {
                    biegaczPoz[i].strona='d';
                }else if (readChar(biegaczPoz[i].x-1,biegaczPoz[i].y)=='A')
                {
                    biegaczPoz[i].strona='d';
                }else if (readChar(biegaczPoz[i].x-1,biegaczPoz[i].y)=='S')
                {
                    biegaczPoz[i].strona='d';
                }else if (readChar(biegaczPoz[i].x-1,biegaczPoz[i].y)=='o')
                {
                    //NIC
                }else
                {
                    gracz.zycia-=1;
                    gracz.stracil_zycie=true;
                }
            }
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
            if (biegaczPoz[i].zycia==1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
            }
            gotoxy(biegaczPoz[i].x,biegaczPoz[i].y);
            cout<<"S";
        }
    }

    for (int i=0; i<=50; i++)
    {
        if (armataPoz[i].istnieje==true)
        {
            if ((licznikPrzejsc % armataPoz[i].szybkosc)==0)
            {
                if (armataPoz[i].strona=='a')
                {
                    nrPocisk+=1;
                    pocisk[nrPocisk].istnieje=true;
                    pocisk[nrPocisk].x=armataPoz[i].x;
                    pocisk[nrPocisk].y=armataPoz[i].y;
                    pocisk[nrPocisk].strona=armataPoz[i].strona;
                    pocisk[nrPocisk].pierwszyRaz=true;
                }
                if (armataPoz[i].strona=='d')
                {
                    nrPocisk+=1;
                    pocisk[nrPocisk].istnieje=true;
                    pocisk[nrPocisk].x=armataPoz[i].x;
                    pocisk[nrPocisk].y=armataPoz[i].y;
                    pocisk[nrPocisk].strona=armataPoz[i].strona;
                    pocisk[nrPocisk].pierwszyRaz=true;
                }
            }
        }
    }
    for (int i=0; i<=50; i++)
    {
        if (armataPio[i].istnieje==true)
        {
            if ((licznikPrzejsc % armataPio[i].szybkosc)==0)
            {
                if (armataPio[i].strona=='w')
                {
                    nrPocisk+=1;
                    pocisk[nrPocisk].istnieje=true;
                    pocisk[nrPocisk].x=armataPio[i].x;
                    pocisk[nrPocisk].y=armataPio[i].y;
                    pocisk[nrPocisk].strona=armataPio[i].strona;
                    pocisk[nrPocisk].pierwszyRaz=true;
                }
                if (armataPio[i].strona=='s')
                {
                    nrPocisk+=1;
                    pocisk[nrPocisk].istnieje=true;
                    pocisk[nrPocisk].x=armataPio[i].x;
                    pocisk[nrPocisk].y=armataPio[i].y;
                    pocisk[nrPocisk].strona=armataPio[i].strona;
                    pocisk[nrPocisk].pierwszyRaz=true;
                }
            }
        }
    }

    if (c=='m')
    {
        if (gracz.amunicja!=0)
        {
            nrPocisk+=1;
            pocisk[nrPocisk].istnieje=false;
            pocisk[nrPocisk].pierwszyRaz=true;
            gracz.amunicja-=1;
            if (gracz.strona=='w')
            {
                pocisk[nrPocisk].x=gracz.x;
                pocisk[nrPocisk].y=gracz.y;
                pocisk[nrPocisk].strona='w';
                if ((readChar(gracz.x,gracz.y-1)==' ') || (readChar(gracz.x,gracz.y-1)=='S') || (readChar(gracz.x,gracz.y-1)=='%')|| (readChar(gracz.x,gracz.y-1)=='X'))
                {
                    pocisk[nrPocisk].istnieje=true;
                }
            }
            if (gracz.strona=='s')
            {
                pocisk[nrPocisk].x=gracz.x;
                pocisk[nrPocisk].y=gracz.y;
                pocisk[nrPocisk].strona='s';
                if ((readChar(gracz.x,gracz.y+1)==' ') || (readChar(gracz.x,gracz.y+1)=='S') || (readChar(gracz.x,gracz.y+1)=='%')|| (readChar(gracz.x,gracz.y+1)=='X'))
                {
                    pocisk[nrPocisk].istnieje=true;
                }
            }
            if (gracz.strona=='a')
            {
                pocisk[nrPocisk].x=gracz.x;
                pocisk[nrPocisk].y=gracz.y;
                pocisk[nrPocisk].strona='a';
                if ((readChar(gracz.x-1,gracz.y)==' ') || (readChar(gracz.x-1,gracz.y)=='S') || (readChar(gracz.x-1,gracz.y)=='%')|| (readChar(gracz.x-1,gracz.y)=='X'))
                {
                    pocisk[nrPocisk].istnieje=true;
                }
            }
            if (gracz.strona=='d')
            {
                pocisk[nrPocisk].x=gracz.x;
                pocisk[nrPocisk].y=gracz.y;
                pocisk[nrPocisk].strona='d';
                if ((readChar(gracz.x+1,gracz.y)==' ') || (readChar(gracz.x+1,gracz.y)=='S') || (readChar(gracz.x+1,gracz.y)=='%')|| (readChar(gracz.x+1,gracz.y)=='X'))
                {
                    pocisk[nrPocisk].istnieje=true;
                }
            }
        }

    }

    for (int i=0; i<=400; i++)
    {
        if (pocisk[i].istnieje==true)
        {
            pocisk[i].istnieje=false;
            if (readChar(pocisk[i].x,pocisk[i].y)!='@')
            {
                if ((pocisk[i].pierwszyRaz==false) && (readChar(pocisk[i].x,pocisk[i].y)!='@'))
                {
                    cout<<" ";
                }
                if (pocisk[i].strona=='w')
                {
                    pocisk[i].y-=1;
                    if ((readChar(pocisk[i].x,pocisk[i].y)==' ') || (readChar(pocisk[i].x,pocisk[i].y)=='o'))
                    {
                        pocisk[i].istnieje=true;
                    }
                }
                if (pocisk[i].strona=='s')
                {
                    pocisk[i].y+=1;
                    if ((readChar(pocisk[i].x,pocisk[i].y)==' ') || (readChar(pocisk[i].x,pocisk[i].y)=='o'))
                    {
                        pocisk[i].istnieje=true;
                    }
                }
                if (pocisk[i].strona=='a')
                {
                    pocisk[i].x-=1;
                    if ((readChar(pocisk[i].x,pocisk[i].y)==' ') || (readChar(pocisk[i].x,pocisk[i].y)=='o'))
                    {
                        pocisk[i].istnieje=true;
                    }
                }
                if (pocisk[i].strona=='d')
                {
                    pocisk[i].x+=1;
                    if ((readChar(pocisk[i].x,pocisk[i].y)==' ') || (readChar(pocisk[i].x,pocisk[i].y)=='o'))
                    {
                        pocisk[i].istnieje=true;
                    }
                }
                if (pocisk[i].istnieje==false)
                {
                    if (readChar(pocisk[i].x,pocisk[i].y)=='S')
                    {
                        for (int j=0; j<=100; j++)
                        {
                            if((pocisk[i].x==biegaczPoz[j].x) && (pocisk[i].y==biegaczPoz[j].y))
                            {
                                biegaczPoz[j].zycia-=1;
                                gotoxy(biegaczPoz[j].x,biegaczPoz[j].y);
                                cout<<" ";
                            }
                        }
                    }else if (readChar(pocisk[i].x,pocisk[i].y)=='%')
                    {
                        for (int j=0; j<=50; j++)
                        {
                            if((pocisk[i].x==randomer[j].x) && (pocisk[i].y==randomer[j].y))
                            {
                                randomer[j].zycia-=1;
                                gotoxy(randomer[j].x,randomer[j].y);
                                cout<<" ";
                            }
                        }
                    }else if (readChar(pocisk[i].x,pocisk[i].y)=='X')
                    {
                        bossZycie-=1;
                    }else if ((readChar(pocisk[i].x,pocisk[i].y)!='@') && (readChar(pocisk[i].x,pocisk[i].y)!='#') && (readChar(pocisk[i].x,pocisk[i].y)!='o') && (readChar(pocisk[i].x,pocisk[i].y)!='-') && (readChar(pocisk[i].x,pocisk[i].y)!='|')&& (readChar(pocisk[i].x,pocisk[i].y)!='A') && (readChar(pocisk[i].x,pocisk[i].y)!='+')&& (readChar(pocisk[i].x,pocisk[i].y)!='C'))
                    {
                        gracz.zycia-=1;
                        gracz.stracil_zycie=true;
                    }
                }
                pocisk[i].pierwszyRaz=false;


            }
        }
    }
    for(int i=0; i<=400; i++)
    {
        if (pocisk[i].istnieje==true)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
            gotoxy(pocisk[i].x,pocisk[i].y);
            cout<<"o";
        }
    }
    gotoxy(90,3);
    cout<<"                ";
    gotoxy(90,3);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    cout<<"Lives: "<<gracz.zycia;

    gotoxy(90,5);
    cout<<"                ";
    gotoxy(90,5);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
    cout<<"Ammo: "<<gracz.amunicja;

    gotoxy(90,7);
    cout<<"                           ";
    if (gracz.czasRespawnu>0)
    {
        gotoxy(90,7);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        cout<<"Respawn time: "<<gracz.czasRespawnu;
    }


    gotoxy(11,40);
    cout<<"                ";
    gotoxy(11,40);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"XY: ( "<<gracz.x<<", "<<gracz.y<<" )";

    if (bossPostawiony==true)
    {
        gotoxy(70,31);
        cout<<"      ";
        gotoxy(70,31);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout<<bossZycie<<" HP";
    }


}

void wyczyscTablice()
{
    for (int i=0; i<=100; i++)
    {
        biegaczPoz[i].zycia=0;
    }
    for (int i=0; i<=50; i++)
    {
        randomer[i].zycia=0;
        armataPio[i].istnieje=false;
        armataPoz[i].istnieje=false;
    }
}

void poruszenieGracz()
{
    c='0';
    if (_kbhit()==1)
    {
        c=getch();
    }
}

void rysujLegende()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
    gotoxy(87,9);
    cout<<"--------------------------";
    gotoxy(91,10);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    cout<<"     LEGEND: ";

    gotoxy(89,12);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<char(24)<<" -> YOU";

    gotoxy(89,14);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    cout<<"# -> Unmovable object";

    gotoxy(89,16);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
    cout<<"@ -> Movable object";

    gotoxy(89,18);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    cout<<"- , | -> Cannons";
    gotoxy(95,19);
    cout<<"(Indestructible)";

    gotoxy(89,21);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"S -> Vertically-moving";
    gotoxy(94,22);
    cout<<"enemy [Have 2HP]";

    gotoxy(89,24);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
    cout<<"% -> Randomly-moving";
    gotoxy(94,25);
    cout<<"enemy [Have 2HP]";
    gotoxy(91,26);
    cout<<"(move in certain area)";

    gotoxy(89,28);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
    cout<<"& -> Follows YOU";
    gotoxy(94,29);
    cout<<"(longer axis dist.)";

    gotoxy(89,31);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
    cout<<"A -> Ammo (+5)";

    gotoxy(89,33);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"+ -> life (+1)";

    gotoxy(89,35);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
    cout<<"C";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    cout<<" -> CheckPoint";

    gotoxy(87,37);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
    cout<<"--------------------------";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
    for (int i=0; i<=5; i++)
    {
        gotoxy(67,38+i);
        cout<<"|";
    }

    gotoxy(69,39);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    cout<<"ESC -> Quit to menu";

    gotoxy(69,41);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    cout<<"R -> Restart from CheckPoint (loses life)";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
    for (int i=0; i<=5; i++)
    {
        gotoxy(38,38+i);
        cout<<"|";
    }

    gotoxy(40,39);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"W/S/A/D -> Move character";

    gotoxy(40,41);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout<<"M -> Shoot";
}

void restartPoziomu()
{
    c='0';
    licznikPrzejsc=0;
    system("CLS");
    if(gracz.checkPoint==0)
    {
        gracz.x=2;
        gracz.y=35;
    }
    if (gracz.checkPoint==1)
    {
        gracz.x=56;
        gracz.y=22;
    }
    if (gracz.checkPoint==2)
    {
        gracz.x=4;
        gracz.y=23;
    }
    if (gracz.checkPoint==3)
    {
        gracz.x=33;
        gracz.y=11;
    }
    if (gracz.checkPoint==4)
    {
        gracz.x=42;
        gracz.y=12;
    }
    if (gracz.checkPoint==5)
    {
        gracz.x=85;
        gracz.y=15;
    }
    wyczyscTablice();
    zaladujPoziomPodstawa("level_1.txt");
    zaladujPoziomObiekty(1);
    rysujLegende();
    gotoxy(gracz.x,gracz.y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<char(24);
}

void szybkosc()
{
    system("CLS");
    char c=' ';
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    gotoxy(48,16);
    cout<<"CURRENT SPEED: ";
    gotoxy(41,21);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    cout<<"<- A(-)";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    cout<<" MOVING SPEED ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"(+)D ->";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    gotoxy(41,24);
    cout<<"   (Press ENTER to go back)   ";
    while (c!=char(13))
    {
        gotoxy(54,18);
        cout<<"                    ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        gotoxy(54,18);
        cout<<odswierzanie;
        gotoxy(0,0);
        c=getch();
        if (c=='d')
        {
            odswierzanie+=1;
        }
        if (c=='a')
        {
            if (odswierzanie>=2)
            {
                odswierzanie-=1;
            }
        }
    }
}

void trudnosc()
{

}

void opcje()
{
    char c='0';
    int wybrane=2;
    while (c!=' ')
    {
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    gotoxy(55,14);
    cout<<char(24);
    gotoxy(55,15);
    cout<<"W";

    gotoxy(55,28);
    cout<<char(25);
    gotoxy(55,27);
    cout<<"S";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    gotoxy(49,19);
    cout<<" DIFFICULTY ";
    gotoxy(49,21);
    cout<<"MOVING SPEED";
    gotoxy(49,23);
    cout<<"    BACK    ";
    while (c!=char(13))
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        gotoxy(46,19+wybrane);
        cout<<"->";
        gotoxy(63,19+wybrane);
        cout<<"<-";
        gotoxy(0,0);
        c=getch();
        gotoxy(46,19+wybrane);
        cout<<"  ";
        gotoxy(63,19+wybrane);
        cout<<"  ";
        if (c=='s')
        {
            if (wybrane<4)
            {
                wybrane+=2;
            }
        }
        if (c=='w')
        {
            if (wybrane>0)
            {
                wybrane-=2;
            }
        }
    }
    if (wybrane==0)
    {
        trudnosc();
        c='0';
    }
    if (wybrane==2)
    {
        szybkosc();
        c='0';
    }
    if (wybrane==4)
    {
        c=' ';
    }
    system("CLS");
    wybrane=2;
    }

}

void rozpocznijGre()
{
    srand(time(NULL));
    licznikPrzejsc=0;
    gracz.x=2;
    gracz.y=35;
    gracz.amunicja=15;
    gracz.zycia=3;
    gracz.checkPoint=0;
    bossZycie=50;
    bossPostawiony=false;
    for (int i=0; i<=20;i++)
    {
        zbierajka[i].istnieje=true;
    }
    wyczyscTablice();
    zaladujPoziomPodstawa("level_1.txt");
    zaladujPoziomObiekty(1);
    rysujLegende();
    gotoxy(gracz.x,gracz.y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<char(24);
}

void menu()
{
    char c='0';
    int wybrane=2;
    wyjscie=false;
    system("CLS");
    while ((wGrze==false) && (wyjscie==false))
    {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    gotoxy(55,14);
    cout<<char(24);
    gotoxy(55,15);
    cout<<"W";

    gotoxy(55,28);
    cout<<char(25);
    gotoxy(55,27);
    cout<<"S";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    gotoxy(52,19);
    cout<<" START ";
    gotoxy(52,21);
    cout<<"OPTIONS";
    gotoxy(52,23);
    cout<<" QUIT  ";
    while (c!=char(13))
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        gotoxy(49,19+wybrane);
        cout<<"->";
        gotoxy(60,19+wybrane);
        cout<<"<-";
        gotoxy(0,0);
        c=getch();
        gotoxy(49,19+wybrane);
        cout<<"  ";
        gotoxy(60,19+wybrane);
        cout<<"  ";
        if (c=='s')
        {
            if (wybrane<4)
            {
                wybrane+=2;
            }
        }
        if (c=='w')
        {
            if (wybrane>0)
            {
                wybrane-=2;
            }
        }
    }
    if (wybrane==0)
    {
        wGrze=true;
    }
    if (wybrane==2)
    {
        opcje();
    }
    if (wybrane==4)
    {
        wGrze=false;
        wyjscie=true;
    }
    wybrane=2;
    c=' ';
    system("CLS");
    }
}


int main()
{
    SetWindow(113,44);
    odswierzanie=10;
    menu();
    while (wyjscie==false)
    {
        rozpocznijGre();
        while(wGrze==true)
        {
            gracz.stracil_zycie=false;
            aktualizuj();
            poruszenieGracz();
            if (gracz.czasRespawnu>=1)
            {
                c='0';
                gracz.czasRespawnu-=1;
            }
            if (c==char(27))
            {
                wGrze=false;
            }
            if ((gracz.stracil_zycie==true) || (c=='r'))
            {
                for (int i=0; i<=4; i++)
                {
                    gotoxy(gracz.x,gracz.y);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
                    cout<<char(24);
                    Sleep(150);
                    gotoxy(gracz.x,gracz.y);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
                    cout<<char(24);
                    Sleep(150);
                }
                if (c=='r')
                    {
                        gracz.zycia-=1;
                    }
                gracz.czasRespawnu=20;
                restartPoziomu();
            }
            if (gracz.zycia<=0)
            {
                wGrze=false;
            }
            gotoxy(0,0);
            Sleep(odswierzanie);
            licznikPrzejsc+=1;
            if (licznikPrzejsc>2000000)
            {
                licznikPrzejsc=0;
            }
            if (nrPocisk>350)
            {
                nrPocisk=0;
            }
            if(bossZycie<=0)
            {
                wGrze=false;
            }
        }
        if ((wyjscie==false)&&(bossZycie>0))
        {
            system("CLS");
            gotoxy(52,20);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
            cout<<"GAME OVER";
            gotoxy(44,23);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            cout<<"Press ESC to go back to menu";
            while (c!=char(27))
            {
                c=getch();
            }
            menu();
        }
        if (bossZycie<=0)
        {
            tworzBossaPokonany();
            system("CLS");
            gotoxy(52,20);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
            cout<<"YOU WON!";
            gotoxy(43,23);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            cout<<"Press ESC to go back to menu";
            while (c!=char(27))
            {
                c=getch();
            }
            menu();
        }
    }
    return 0;
}
