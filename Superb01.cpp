#include "c:\borlandc\include\conio.h"
#include "c:\borlandc\include\stdlib.h"
#include "c:\borlandc\include\string.h"
#include "c:\borlandc\include\dos.h"


const Liczba_kart = 53;
char s[10];
unsigned char Talia[53][2] = {
  {54,1},{54,2},{54,3},{54,4},{54,5},{54,6},{54,7},{54,8},{54,9},{54,10},{54,11},{54,12},{54,13},
  {14,1},{14,2},{14,3},{14,4},{14,5},{14,6},{14,7},{14,8},{14,9},{14,10},{14,11},{14,12},{14,13},
  {10,1},{10,2},{10,3},{10,4},{10,5},{10,6},{10,7},{10,8},{10,9},{10,10},{10,11},{10,12},{10,13},
  {12,1},{12,2},{12,3},{12,4},{12,5},{12,6},{12,7},{12,8},{12,9},{12,10},{12,11},{12,12},{12,13},
  {7,15}};
unsigned char Reka[5][2];
char Stawka;
unsigned long Kredyt;
unsigned int wygrana;
unsigned char Mini_bonus;
char Koniec = 0;
char keys,keya;
char Ostatnio_wymiana;
char Stopien_wygranej;
char Wygrana_stawka;
char Gramy_dalej;

extern "C" {
  extern void far Czysc_ekran (char k);
  extern void far Wypisz (char *s,char k,unsigned int x,unsigned int y);
  extern void far Rysuj_kule (unsigned int x,unsigned int y,char k,char ka);
  };

void Pierwszy_ekran();
void Drugi_ekran();

void Czysc_bufor() {
  delay(200);
  Jeszcze3 : _asm {mov ah,11h; int 16h; jz Dalej3; mov ah,10h; int 16h; jmp Jeszcze3;};
  Dalej3 :;
  };

void Start() {
  _asm {mov ax,13h; int 10h};
  _asm {mov ah,10h; mov al,01h; mov bh,1; int 10h};
  _asm {mov ah,11h; mov al,23h; mov bl,2; int 10h};
  Czysc_ekran(0);
  Stawka = 1;
  Kredyt = 50;
  Mini_bonus = 0;
  Ostatnio_wymiana = 1;
  for (char i=0; i<5; i++)
    Reka[i][1] = 0;
  };

void Wypisz_stawki() {
  for (char i=0; i<9; i++)
    Wypisz("ллллл",1,114,i*9);
  Wypisz("лл",1,26,190);
  ltoa(long(600*Stawka),s,10);
  Wypisz(s,15,114+((5-strlen(s))*8),0);
  ltoa(long(300*Stawka),s,10);
  Wypisz(s,15,114+((5-strlen(s))*8),9);
  ltoa(long(80*Stawka),s,10);
  Wypisz(s,15,114+((5-strlen(s))*8),18);
  ltoa(long(40*Stawka),s,10);
  Wypisz(s,15,114+((5-strlen(s))*8),27);
  ltoa(long(12*Stawka),s,10);
  Wypisz(s,15,114+((5-strlen(s))*8),36);
  ltoa(long(9*Stawka),s,10);
  Wypisz(s,15,114+((5-strlen(s))*8),45);
  ltoa(long(7*Stawka),s,10);
  Wypisz(s,15,114+((5-strlen(s))*8),54);
  ltoa(long(5*Stawka),s,10);
  Wypisz(s,15,114+((5-strlen(s))*8),63);
  ltoa(long(3*Stawka),s,10);
  Wypisz(s,15,114+((5-strlen(s))*8),72);
  ltoa(long(Stawka),s,10);
  Wypisz(s,14,26+((2-strlen(s))*4),190);
  };

void Wypisz_hold () {
  for (char i=0; i<5; i++)
    Wypisz("лллл",1,16+i*64,105);
  for (i=0; i<5; i++)
    if (Reka[i][1]) Wypisz("HOLD",14,16+i*64,105);
  };

void Wypisz_minibonus () {
  if (Mini_bonus >= 100) {
    Kredyt += 100;
    Mini_bonus -= 100; };
  Wypisz("ллл",1,130,86);
  ltoa(long(Mini_bonus),s,10);
  Wypisz(s,10,114+((5-strlen(s))*8),86);
  };

void Wypisz_kredyt () {
  Wypisz("лллл",1,267,190);
  ltoa((unsigned int)(Kredyt),s,10);
  Wypisz(s,14,263+((5-strlen(s))*4),190);
  };

void Wypisz_wygrana () {
  Wypisz("ROYAL COLOR",15,0,9);
  Wypisz("STRAIGHT COLOR",15,0,18);
  Wypisz("4 OF A KIND",15,0,27);
  Wypisz("FULL HOUSE",15,0,36);
  Wypisz("COLOR",15,0,45);
  Wypisz("STRAIGHT",15,0,54);
  Wypisz("3 OF A KIND",15,0,63);
  Wypisz("2 PAIRS",15,0,72);
  switch (Stopien_wygranej) {
    case 2 : Wypisz("2 PAIRS",14,0,72); break;
    case 3 : Wypisz("3 OF A KIND",14,0,63); break;
    case 4 : Wypisz("STRAIGHT",14,0,54); break;
    case 5 : Wypisz("COLOR",14,0,45); break;
    case 6 : Wypisz("FULL HOUSE",14,0,36); break;
    case 7 : Wypisz("4 OF A KIND",14,0,27); break;
    case 8 : Wypisz("STRAIGHT COLOR",14,0,18); break;
    case 9 : Wypisz("ROYAL COLOR",14,0,9); break;
    case 10 : Wypisz("5 OF A KIND",14,0,0); break;
    };
  };

void Wylosuj_reke() {
  char n,a,b,zle=0;
  unsigned int gen;
  _asm {mov al,00h; out 43h,al; in al,40h; mov al,ah; in al,40h; xchg al,ah; mov gen,ax;};
  srand(gen);
  for (char i=0; i<5; i++) {
    if (Reka[i][1] == 0) {
    do {
      n = rand() % Liczba_kart;
      zle = 0;
      for (char j=0; j<5; j++)
	if (Reka[j][0] == n) zle = 1;
      } while (zle == 1);
      Reka[i][0] = n;  };
    };
  };

void Rysuj_reke() {
  for (char i=0; i<5; i++)
    if (!Reka[i][1]) Rysuj_kule(30+(i*64),145,1,16);
  for (i=0; i<5; i++)
    if (!Reka[i][1]) {
      Rysuj_kule(30+(i*64),145,Talia[Reka[i][0]][0],Talia[Reka[i][0]][1]);
      sound(20);
      delay(100);
      nosound();
      delay(300);};
  };

void Sprawdz_wygrana () {
  char i,j,kolory[4]={0,0,0,0},Reka2[5][2] = {{0,9},{0,9},{0,9},{0,9},{0,9}}, Reka3[5][2] = {{0,9},{0,9},{0,9},{0,9},{0,9}}, Reka4[5];
  char powtorzenia[7]={0,0,0,0,0,0,0},kolor[7]={0,0,0,0,0,0,0};
  char Liczba_jok=0,Dostepne_jok;

  for (i=0; i<5; i++)
    for (j=0; j<5; j++)
      if ((Talia[Reka[j][0]][1]>Reka2[i][0])&(Reka2[0][1]!=j)&(Reka2[1][1]!=j)&(Reka2[2][1]!=j)&(Reka2[3][1]!=j)) {
	Reka2[i][0] = Talia[Reka[j][0]][1];
	Reka2[i][1] = j; };
  for (i=0; i<5; i++)
    if (Talia[Reka[i][0]][1]==1) Talia[Reka[i][0]][1] = 14;
  for (i=0; i<5; i++)
    for (j=0; j<5; j++)
      if ((Talia[Reka[j][0]][1]>Reka3[i][0])&(Reka3[0][1]!=j)&(Reka3[1][1]!=j)&(Reka3[2][1]!=j)&(Reka3[3][1]!=j)) {
	Reka3[i][0] = Talia[Reka[j][0]][1];
	Reka3[i][1] = j; };
  for (i=0; i<5; i++)
    if (Talia[Reka[i][0]][1]==14) Talia[Reka[i][0]][1] = 1;
  for (i=0; i<5; i++)
    if (Talia[Reka[i][0]][1]==15) Liczba_jok += 1;

  if (Reka3[Liczba_jok][0]>10) powtorzenia[1]=Reka3[Liczba_jok][0];
  for (i=Liczba_jok; i<5; i++)
    for (j=i+1; j<5; j++)
      if (Reka3[i][0] == Reka3[j][0])
	powtorzenia[1] = Reka3[i][0];
  for (i=0; i<5; i++)
    Reka4[i] = Talia[Reka[i][0]][1];
  if (powtorzenia[1] == 14) powtorzenia[1]=1;
  for (i=0; i<5; i++)
    if (Reka4[i]==15) Reka4[i] = powtorzenia[1];
  for (i=0; i<5; i++)
    for (j=i+1; j<5; j++)
      if (Reka4[i] == Reka4[j]) {
	powtorzenia[0] += 1;
	powtorzenia[1] = Reka4[i];
	powtorzenia[i+2] = 1;
	powtorzenia[j+2] = 1;};

  for (i=0; i<4; i++) {
    for (j=0; j<5; j++)
      if ((Talia[Reka[j][0]][0]==Talia[0+i*13][0])|(Talia[Reka[j][0]][1]==15)) kolory[i] += 1;
    if (kolory[i]>kolor[0]) {kolor[0] = kolory[i];
      kolor[1] = i; };
    };
    for (i=0; i<5; i++)
      if ((Talia[Reka[i][0]][0]==Talia[0+kolor[1]*13][0])|(Talia[Reka[i][0]][1]==15)) kolor[i+2] = 1;

  char sekwens[7]={0,0,0,0,0,0,0};
  char sekw[14]={0,0,0,0,0,0,0,0,0,0,0,0,0,0},sekw2[5]={0,0,0,0,0};
  char Ile_zliczen;
  for (i=0; i<5; i++)
    if (Talia[Reka[i][0]][1]!=15) {
      if (Talia[Reka[i][0]][1]!=1) sekw[Talia[Reka[i][0]][1]-1] = i+1;
      else {sekw[0] = i+1; sekw[13] = i+1;};
      };
  for (i=0; i<10; i++) {
    Ile_zliczen = 0;
    for (j=0; j<5; j++)
      sekw2[j] = 0;
    for (j=0; j<5; j++)
      if (sekw[i+j]) {
	Ile_zliczen += 1;
	sekw2[sekw[i+j]-1] = 1;
	};
    if (Ile_zliczen+Liczba_jok >= sekwens[0]) {
      sekwens[0] = Ile_zliczen+Liczba_jok;
      sekwens[1] = j+5;
      sekwens[2] = sekw2[0]; sekwens[3] = sekw2[1]; sekwens[4] = sekw2[2];
      sekwens[5] = sekw2[3]; sekwens[6] = sekw2[4];
      };
    };

  Stopien_wygranej=0;
  if (powtorzenia[0]==1) {
    for (i=0; i<5; i++)
      if (powtorzenia[i+2])
	if ((Talia[Reka[i][0]][1]==1)|(Talia[Reka[i][0]][1]>10)) Stopien_wygranej = 1;
    if (!Ostatnio_wymiana)
      for (i=0; i<5; i++)
	if (powtorzenia[i+2]) Reka[i][1]=1;
	  else Reka[i][1]=0;
     };

  if (sekwens[0]==4) {
    if (!Ostatnio_wymiana)
      for (i=0; i<5; i++)
	if (sekwens[i+2]) Reka[i][1]=1;
	  else Reka[i][1]=0;
    };
  if (kolor[0]==4) {
    if (!Ostatnio_wymiana)
      for (i=0; i<5; i++)
	if (kolor[i+2]) Reka[i][1]=1;
	  else Reka[i][1]=0;
     };

  if (powtorzenia[0]==2) {
    Stopien_wygranej = 2;
    if (!Ostatnio_wymiana)
      for (i=0; i<5; i++)
	if (powtorzenia[i+2]) Reka[i][1]=1;
	  else Reka[i][1]=0;
     };
  if (powtorzenia[0]==3) {
    Stopien_wygranej = 3;
    if (!Ostatnio_wymiana)
      for (i=0; i<5; i++)
	if (powtorzenia[i+2]) Reka[i][1]=1;
	  else Reka[i][1]=0;
     };
  if (sekwens[0]==5) {
    Stopien_wygranej = 4;
    if (!Ostatnio_wymiana)
      for (i=0; i<5; i++)
	if (sekwens[i+2]) Reka[i][1]=1;
	  else Reka[i][1]=0;
    };
  if (kolor[0]==5) {
    Stopien_wygranej = 5;
    if (!Ostatnio_wymiana)
      for (i=0; i<5; i++)
	if (kolor[i+2]) Reka[i][1]=1;
	  else Reka[i][1]=0;
     };
  if (powtorzenia[0]==4) {
    Stopien_wygranej = 6;
    if (!Ostatnio_wymiana)
      for (i=0; i<5; i++)
	if (powtorzenia[i+2]) Reka[i][1]=1;
	  else Reka[i][1]=0;
     };
  if (powtorzenia[0]==6) {
    Stopien_wygranej = 7;
    if (!Ostatnio_wymiana)
      for (i=0; i<5; i++)
	if (powtorzenia[i+2]) Reka[i][1]=1;
	  else Reka[i][1]=0;
     };
  if ((kolor[0]==5)&(sekwens[0]==5)) {
    Stopien_wygranej = 8;
    if (!Ostatnio_wymiana)
      for (i=0; i<5; i++)
	if (kolor[i+2]) Reka[i][1]=1;
	  else Reka[i][1]=0;
    };
  if ((kolor[0]==5)&(sekwens[0]==5)&(sekwens[1]==14)) {
    Stopien_wygranej = 9;
    if (!Ostatnio_wymiana)
      for (i=0; i<5; i++)
	if (kolor[i+2]) Reka[i][1]=1;
	  else Reka[i][1]=0;
    };
  if (powtorzenia[0]==10) {
    Stopien_wygranej = 10;
    if (!Ostatnio_wymiana)
      for (i=0; i<5; i++)
	if (powtorzenia[i+2]) Reka[i][1]=1;
	  else Reka[i][1]=0;
    };

    if (!Ostatnio_wymiana)
      for (i=0; i<5; i++)
	if (Talia[Reka[i][0]][1]==15) Reka[i][1] = 1;

    Wypisz_wygrana();
  };

void Wyplac_wygrana() {
  if (Stopien_wygranej==1) {
    Mini_bonus += Stawka;
    Wypisz_minibonus();
  };
  if (Stopien_wygranej>1) {
    Drugi_ekran();
    Czysc_ekran(1);
    Wypisz("AUTOMAT",14,212,30);
    Wypisz("ZRECZNOSCIOWY",14,188,38);
    Wypisz("5 OF A KIND",15,0,0);
    Wypisz("ROYAL COLOR",15,0,9);
    Wypisz("STRAIGHT COLOR",15,0,18);
    Wypisz("4 OF A KIND",15,0,27);
    Wypisz("FULL HOUSE",15,0,36);
    Wypisz("COLOR",15,0,45);
    Wypisz("STRAIGHT",15,0,54);
    Wypisz("3 OF A KIND",15,0,63);
    Wypisz("2 PAIRS",15,0,72);
    Wypisz("MINI BONUS ",10,0,86);
    Wypisz("STAWKA",14,10,181);
    Wypisz("KREDYT",14,259,181);
    Wypisz_stawki();
    Wypisz_minibonus();
    Wypisz_hold();
    Wypisz_kredyt();
    for (char i=0; i<5; i++)
      Rysuj_kule(30+(i*64),145,Talia[Reka[i][0]][0],Talia[Reka[i][0]][1]);
    };
//  Stopien_wygranej = 0;  

//  switch (Stopien_wygranej) {
//    case 10 : Kredyt += Stawka*600; break;
//    case 9 : Kredyt += Stawka*300; break;
//    case 8 : Kredyt += Stawka*80; break;
//    case 7 : Kredyt += Stawka*40; break;
//    case 6 : Kredyt += Stawka*12; break;
//    case 5 : Kredyt += Stawka*9; break;
//    case 4 : Kredyt += Stawka*7; break;
//    case 3 : Kredyt += Stawka*5; break;
//    case 2 : Kredyt += Stawka*3; break;
//    case 1 : Mini_bonus += Stawka; Wypisz_minibonus(); break;
//    };
//  Wypisz_kredyt();
  };

void Klawisze1() {
  keys = 0;
  keya = 0;
  Czysc_bufor();
  Jeszcze : _asm {mov ah,11h; int 16h; jz Pustak; mov ah,10h; int 16h; jmp Jeszcze; };
  Pustak : _asm {mov ah,11h; int 16h; jz Pustak; mov ah,11h; int 16h; mov keys,ah; mov keya,al;};
  switch (keys) {
    case 15 : {
      if (Stawka >= Kredyt) {
	if ((Reka[0][1])&(Reka[1][1])&(Reka[2][1])&(Reka[3][1])&(Reka[4][1])&(!Ostatnio_wymiana)) {
	  Stawka = 1;
	  Ostatnio_wymiana = 1;
	  Sprawdz_wygrana();
	  Wyplac_wygrana();
	  Reka[0][1]=0;Reka[1][1]=0;Reka[2][1]=0;Reka[3][1]=0;Reka[4][1]=0;
	  Wypisz_hold();
	  Wypisz_stawki();
	  break;};
	Stawka=1;
	Wypisz_stawki();
	break;};
      if (Stawka<5) {Stawka += 1; Wypisz_stawki(); break;};
      if ((Stawka>4)&(Stawka<40)&(Stawka+5<=Kredyt))
	{Stawka += 5;
	Wypisz_stawki();
	break;};
      if ((Stawka==40)&(Reka[0][1])&(Reka[1][1])&(Reka[2][1])&(Reka[3][1])&(Reka[4][1])&(!Ostatnio_wymiana)) {
	Stawka = 1;
	Ostatnio_wymiana = 1;
	Sprawdz_wygrana();
	Wyplac_wygrana();
	Reka[0][1]=0;Reka[1][1]=0;Reka[2][1]=0;Reka[3][1]=0;Reka[4][1]=0;
	Wypisz_hold();
	Wypisz_stawki();
	break;};
      Stawka = 1;
      Wypisz_stawki();
      break;
      };
    case 1 : Koniec = 1; break;
    case 28 : {
      if ((Reka[0][1])&(Reka[1][1])&(Reka[2][1])&(Reka[3][1])&(Reka[4][1])&(!Ostatnio_wymiana)) {
	Ostatnio_wymiana = 1;
	Sprawdz_wygrana();
	Wyplac_wygrana();
	Reka[0][1]=0;Reka[1][1]=0;Reka[2][1]=0;Reka[3][1]=0;Reka[4][1]=0;
	Wypisz_hold();
	break; };
      if ((!Reka[0][1])|(!Reka[1][1])|(!Reka[2][1])|(!Reka[3][1])|(!Reka[4][1])) {
	if ((Wygrana_stawka!=Stawka)&((Reka[0][1])|(Reka[1][1])|(Reka[2][1])|(Reka[3][1])|(Reka[4][1]))) {
	  Reka[0][1]=0;Reka[1][1]=0;Reka[2][1]=0;Reka[3][1]=0;Reka[4][1]=0;
	  Wypisz_hold();
	  };
	Wylosuj_reke();
	Stopien_wygranej = 0;
	Wypisz_wygrana();
	Rysuj_reke();
	Kredyt -= Stawka;
	Ostatnio_wymiana = 0;
	if ((Reka[0][1])|(Reka[1][1])|(Reka[2][1])|(Reka[3][1])|(Reka[4][1])) {Ostatnio_wymiana = 1;
	  Reka[0][1] = 0;
	  Reka[1][1] = 0;
	  Reka[2][1] = 0;
	  Reka[3][1] = 0;
	  Reka[4][1] = 0; };
	Sprawdz_wygrana();
	if (Ostatnio_wymiana)
	  Wyplac_wygrana();
	if (Kredyt == 0) Koniec = 1;
	if (Stawka>Kredyt) {Stawka = 1; Wypisz_stawki();};
	Wypisz_kredyt();
	Wypisz_hold();
	Wygrana_stawka=Stawka;
	break;};
      };
    case 16 : if (!Ostatnio_wymiana) {Reka[0][1] = !Reka[0][1];
      Wypisz_hold();
      break;};
    case 17 : if (!Ostatnio_wymiana) {Reka[1][1] = !Reka[1][1];
      Wypisz_hold();
      break;};
    case 18 : if (!Ostatnio_wymiana) {Reka[2][1] = !Reka[2][1];
      Wypisz_hold();
      break;};
    case 19 : if (!Ostatnio_wymiana) {Reka[3][1] = !Reka[3][1];
      Wypisz_hold();
      break;};
    case 20 : if (!Ostatnio_wymiana) {Reka[4][1] = !Reka[4][1];
      Wypisz_hold();
      break;};
    };
  };

void Pierwszy_ekran() {
  Czysc_ekran(1);
  Wypisz("AUTOMAT",14,212,30);
  Wypisz("ZRECZNOSCIOWY",14,188,38);
  Wypisz("5 OF A KIND",15,0,0);
  Wypisz("ROYAL COLOR",15,0,9);
  Wypisz("STRAIGHT COLOR",15,0,18);
  Wypisz("4 OF A KIND",15,0,27);
  Wypisz("FULL HOUSE",15,0,36);
  Wypisz("COLOR",15,0,45);
  Wypisz("STRAIGHT",15,0,54);
  Wypisz("3 OF A KIND",15,0,63);
  Wypisz("2 PAIRS",15,0,72);
  Wypisz("MINI BONUS ",10,0,86);
  Wypisz("STAWKA",14,10,181);
  Wypisz("KREDYT",14,259,181);
  Wypisz_stawki();
  Wypisz_minibonus();
  Wypisz_hold();
  Wypisz_kredyt();
  while (!Koniec) {
    Klawisze1();
    };
  };

void Wypisz_wygrana2 () {
  Wypisz("ллллл",1,186,95);
  ltoa(long(wygrana),s,10);
  Wypisz(s,12,186,95);
  };

void Klawisze2() {
  keys = 0;
  keya = 0;
  char n;
  sound(200);
  delay(100);
  sound(400);
  delay(100);
  sound(800);
  delay(300);
  nosound();
  Czysc_bufor();
  while ((keys!=28)&(keys!=16)&(keys!=17)) {
   // Jeszcze2 : _asm {mov ah,11h; int 16h; jz Pustak2; mov ah,10h; int 16h; jmp Jeszcze2;};
   // Pustak2 : _asm {mov ah,11h; int 16h; mov keys,ah; mov keya,al;};
    n = rand() % Liczba_kart;
    Rysuj_kule(60,60,Talia[n][0],Talia[n][1]);
    delay(20);
    _asm {mov ah,11h; int 16h; jz Nic; mov ah,10h; int 16h; mov keys,ah; mov keya,al;};
    Nic:;
    };
  if (keys!=28) {
    if (((keys==16)&&(n<=25))||((keys==17)&&(n>=26))||(n==52)) {wygrana *= 2;}
      else {wygrana=0; Gramy_dalej=0;};
    }
    else {Gramy_dalej=0;};
  Wypisz_wygrana2();
  };

void Drugi_ekran() {
  unsigned int gen;
  _asm {mov al,00h; out 43h,al; in al,40h; mov al,ah; in al,40h; xchg al,ah; mov gen,ax;};
  srand(gen);
  Czysc_ekran(1);
  for (char i=0; i<5; i++)
    Rysuj_kule(30+(i*64),145,Talia[Reka[i][0]][0],Talia[Reka[i][0]][1]);
  switch (Stopien_wygranej) {
    case 2 : Wypisz("2 PAIRS",12,125,80); wygrana=3*Stawka; break;
    case 3 : Wypisz("3 OF A KIND",12,125,80); wygrana=5*Stawka; break;
    case 4 : Wypisz("STRAIGHT",12,125,80); wygrana=7*Stawka; break;
    case 5 : Wypisz("COLOR",12,125,80); wygrana=9*Stawka; break;
    case 6 : Wypisz("FULL HOUSE",12,125,80); wygrana=12*Stawka; break;
    case 7 : Wypisz("4 OF A KIND",12,125,80); wygrana=40*Stawka; break;
    case 8 : Wypisz("STRAIGHT COLOR",12,125,80); wygrana=80*Stawka; break;
    case 9 : Wypisz("ROYAL COLOR",12,125,80); wygrana=300*Stawka; break;
    case 10 : Wypisz("5 OF A KIND",12,125,80); wygrana=600*Stawka; break;
    };
  Wypisz("KREDYT",14,259,181);
  Wypisz_kredyt();
  Wypisz("WYGRANA",12,125,95);
  Wypisz_wygrana2();
  Gramy_dalej=1;
  while (Gramy_dalej==1) {
    Klawisze2(); }
  Kredyt += wygrana;
  };

void main() {
  Start();
  Pierwszy_ekran();
  }