PUBLIC _Czysc_ekran  ;czysci ekran na kolor <k>
PUBLIC _Wypisz       ;wypisuje ciag znakow <s> kolor <k> <x>,<y>
PUBLIC _Rysuj_kule   ;rysuje kule o kolorze <k> w <x>,<y>

.386
ASSUME CS:KOD

KOD SEGMENT PUBLIC USE16
Start:
_Rysuj_kule PROC FAR
  push eax
  push bx
  push cx
  push di
  push bp

  mov bp,sp
  mov ax,0A000h
  mov gs,ax
  mov ax,ss:[bp+18]
  sub ax,30
  mov bx,320
  mul bx
  add ax,ss:[bp+16]
  sub ax,30
  mov di,ax
  mov ah,ss:[bp+20]
  mov al,ah
  shl eax,16
  mov ah,ss:[bp+20]
  mov al,ah
  mov cx,0
  mov cl,ss:[bp+22]

  push eax
  cmp cl,13
  ja Rysuj_srodek
  mov eax,0f0f0f0fh
  Rysuj_srodek:
  IRP bp, <3200,3520,3840,4160,4480,4800,5120,5440,5760,6080,6400,6720,7040,7360,7680,8000,8320,8640,8960,9280,9600,9920,10240,10560,10880,11200,11520,11840,12160,12480,12800,13120,13440,13760,14080,14400,14720,15040,15360,15680>
    IRP bx, <8,12,16,20,24,28,32,36,40,44,48>
      mov gs:[bx+di+bp], eax
      ENDM
    ENDM
  IRP bp, <3200,3520,3840,4160,4480,4800,5120,5440,5760,6080,6400,6720,7040,7360,7680,8000,8320,8640,8960,9280,9600,9920,10240,10560,10880,11200,11520,11840,12160,12480,12800,13120,13440,13760,14080,14400,14720,15040,15360,15680>
    mov gs:[di+bp+52], ax
    ENDM
  IRP bp, <2240,2560,2880,16000,16320,16640>
    IRP bx, <20,24,28,32,36,40>
      mov gs:[bx+di+bp], eax
      ENDM
    ENDM
  pop eax

  IRP bx, <26,30,342,346,350,354,659,663,667,671,675,679,977,981,985,989,993,997,1001,1295,1299,1303,1307,1311,1315,1319,1323,1613,1617,1621,1625,1629,1633,1637,1641,1645,1932,1936,1940,1944,1948,1952,1956,1960,1964,2251,2255,2259,2277,2281,2285,2570,2574,2578,2600,2604,2608,2889,2893,2922,2926,3208,3212,3244,3248,3527,3531,3565,3569,3846,3850,3886,3890,4166,4170,4207,4211,4485,4489,4528,4532,4805,4809,4849,4853,5124,5128,5170,5174,5444,5491,5763,5767,5811,5815,6083,6132,6402,6406,6452,6456,6722,6773,7042,7093,7361,7365,7413,7417,7681,7734,8001,8054,8321,8374,8641,8694,8961,9014,9281,9334>
    mov gs:[bx+di],eax
    ENDM
  IRP bx, <34,358,1968,2263,2289,2897,2898,2930,2931,3216,3252,3535,3573,3854,3894,4173,4214,4492,4535,5448,5449,5495,5496,6087,6088,6136,6137,6726,6727,6777,6778,7046,7047,7097,7098,7685,7686,7738,7739,8005,8006,8058,8059,8325,8326,8378,8379,8645,8646,8698,8699,8965,8966,9018,9019,9285,9286,9338,9339>
    mov gs:[bx+di],ax
    ENDM
  IRP bx, <18906,18910,18582,18586,18590,18594,18259,18263,18267,18271,18275,18279,17937,17941,17945,17949,17953,17957,17961,17615,17619,17623,17627,17631,17635,17639,17643,17293,17297,17301,17305,17309,17313,17317,17321,17325,16972,16976,16980,16984,16988,16992,16996,17000,17004,16651,16655,16659,16677,16681,16685,16330,16334,16338,16360,16364,16368,16009,16013,16042,16046,15688,15692,15724,15728,15367,15371,15405,15409,15046,15050,15086,15090,14726,14730,14767,14771,14405,14409,14448,14452,14085,14089,14129,14133,13764,13768,13810,13814,13444,13491,13123,13127,13171,13175,12803,12852,12482,12486,12532,12536,12162,12213,11842,11893,11521,11525,11573,11577,11201,11254,10881,10934,10561,10614,10241,10294,9921,9974,9601,9654>
    mov gs:[bx+di],eax
    ENDM
  IRP bx, <18914,18598,17008,16663,16689,16017,16018,16050,16051,15696,15732,15375,15413,15054,15094,14733,14774,14412,14455,13448,13449,13495,13496,12807,12808,12856,12857,12166,12167,12217,12218,11846,11847,11897,11898,11205,11206,11258,11259,10885,10886,10938,10939,10565,10566,10618,10619,10245,10246,10298,10299,9925,9926,9978,9979,9605,9606,9658,9659>
    mov gs:[bx+di],ax
    ENDM

  ;rysowanie karty
  add di,5136
  mov bp,0

  dec cx
  jcxz Rysuj_A
  jmp Moze_2
  Rysuj_A:
  IRP bx,<,,14,15,,14,15,,14,15,,15,16,,15,16,,15,16,,15,16,,16,17,,16,17,,16,17,,16,17,,17,18,,17,18,,17,18,,17,18,,18,19,,18,19,,10,12,14,16,18,19,,18,19,,19,20,,19,20,,19,20,,19,20,,19,20,,7,8,18,20,21,,5,7,9,10,16,18,20,22,23>
    IFNB <bx>
    mov gs:[bx+di+bp], WORD PTR 0h
    ENDIF
    IFB <bx>
    add bp,320
    ENDIF
    ENDM
  IRP bx,<15,335,1613,1933,2253,2573,2892,3212,3532,3852,4171,4491,4811,5131,5450,5770,6410,6729,7049,7369,7688,8008>
    mov gs:[di+bx],BYTE PTR 0
    ENDM
  jmp Koniec_rysowania_kuli

  Moze_2:
  dec cx
  jcxz Rysuj_2
  jmp Moze_3
  Rysuj_2:
  IRP bx,<11,13,15,17,18,,9,19,20,,20,21,,8,21,22,,7,9,21,22,,7,9,21,22,,8,21,22,,21,22,,21,22,,21,21,,19,21,,18,19,,17,18,,15,16,,13,14,,11,12,,10,,9,,8,,8,,7,,7,,7,,7,9,11,12,,7,9,11,13,15,17,19,21,22,,6,7,12,14,16,18,20,22,,6,14,16,18,20,21,,6,16,18,20>
    IFNB <bx>
    mov gs:[bx+di+bp], WORD PTR 0h
    ENDIF
    IFB <bx>
    add bp,320
    ENDIF
    ENDM
  IRP bx,<648>
    mov gs:[di+bx],BYTE PTR 0
    ENDM
  jmp Koniec_rysowania_kuli

  Moze_3:
  dec cx
  jcxz Rysuj_3
  jmp Moze_4
  Rysuj_3:
  IRP bx, <10,12,14,16,17,,8,18,19,,19,20,,7,20,21,,6,8,20,21,,6,8,20,21,,7,20,21,,20,21,,20,21,,18,20,,15,17,18,,18,19,,19,21,,20,21,,21,22,,21,22,,21,22,,21,22,,21,22,,21,22,,21,22,,7,21,22,,6,8,21,22,,6,8,21,22,,7,20,21,,19,20,,8,18,19,,10,12,14,16,17>
    IFNB <bx>
    mov gs:[bx+di+bp], WORD PTR 0h
    ENDIF
    IFB <bx>
    add bp,320
    ENDIF
    ENDM
  IRP bx,<647,8007>
    mov gs:[di+bx],BYTE PTR 0
    ENDM
  jmp Koniec_rysowania_kuli

  Moze_4:
  dec cx
  jcxz Rysuj_4
  jmp Moze_5
  Rysuj_4:
  IRP bx,<,18,,18,,17,18,,16,18,,17,18,,17,18,,17,18,,17,18,,17,18,,17,18,,17,18,,17,18,,17,18,,17,18,,17,18,,17,18,,17,18,,17,18,,6,8,10,12,14,16,18,20,21,,17,18,,17,18,,17,18,,17,18,,17,18,,17,18,,16,18,19,,14,16,18,20,21>
    IFNB <bx>
    mov gs:[bx+di+bp], WORD PTR 0h
    ENDIF
    IFB <bx>
    add bp,320
    ENDIF
    ENDM
  IRP bx,<1615,1935,2254,2573,2893,3212,3531,3851,4170,4489,4809,5128,5447,5767>
    mov gs:[di+bx],BYTE PTR 0
    ENDM
  jmp Koniec_rysowania_kuli

  Moze_5:
  dec cx
  jcxz Rysuj_5
  jmp Moze_6
  Rysuj_5:
  IRP bx,<8,10,12,14,16,18,20,22,,8,10,12,14,16,18,20,,7,9,11,13,15,17,,,,,,,10,12,14,16,18,,8,19,,6,20,,20,21,,21,22,,21,22,,21,22,,21,22,,21,22,,21,22,,21,22,,21,22,,7,21,22,,6,8,21,22,,6,8,21,22,,7,20,21,,20,,8,19,,10,12,14,16,18>
    IFNB <bx>
    mov gs:[bx+di+bp], WORD PTR 0h
    ENDIF
    IFB <bx>
    add bp,320
    ENDIF
    ENDM
  IRP bx,<967,1287,1607,1927,2247,2567,2886,3526,3206,3846,7687>
    mov gs:[di+bx],BYTE PTR 0
    ENDM
  jmp Koniec_rysowania_kuli

  Moze_6:
  dec cx
  jcxz Rysuj_6
  jmp Moze_7
  Rysuj_6:
  IRP bx,<14,16,18,,12,20,,11,,10,21,,9,10,20,22,,9,20,22,,8,9,21,,8,9,,8,9,,7,8,12,14,16,17,,7,8,17,18,,7,9,18,19,,7,9,19,20,,7,9,19,20,,7,8,20,,7,8,20,21,,7,8,20,21,,7,8,20,21,,7,8,20,21,,7,8,20,21,,7,8,20,21,,8,20,,8,9,19,20,,8,9,19,20,,9,19,,9,10,18,19,,10,11,17,18,,12,14,16>
    IFNB <bx>
    mov gs:[bx+di+bp], WORD PTR 0h
    ENDIF
    IFB <bx>
    add bp,320
    ENDIF
    ENDM
  IRP bx,<662,3211>
    mov gs:[di+bx],BYTE PTR 0
    ENDM
  jmp Koniec_rysowania_kuli

  Moze_7:
  dec cx
  jcxz Rysuj_7
  jmp Moze_8
  Rysuj_7:
  IRP bx,<9,11,,8,10,12,13,,6,8,10,12,14,15,20,21,,6,15,17,19,,,,,,18,,17,,16,,15,16,,15,,14,15,,14,15,,13,14,,13,14,,12,14,,12,14,,12,13,,12,13,,12,13,,12,13,,12,13,,12,13,,12,13,,12,13>
    IFNB <bx>
    mov gs:[bx+di+bp], WORD PTR 0h
    ENDIF
    IFB <bx>
    add bp,320
    ENDIF
    ENDM
  IRP bx,<6,22,326,342,982,1286,1302,1606,1621,1941,2260,2579>
    mov gs:[di+bx],BYTE PTR 0
    ENDM
  jmp Koniec_rysowania_kuli

  Moze_8:
  dec cx
  jcxz Rysuj_8
  jmp Moze_9
  Rysuj_8:
  IRP bx,<11,13,15,16,,10,17,,9,18,,8,9,18,19,,7,8,19,20,,7,8,19,20,,7,8,19,20,,7,8,19,20,,7,8,19,20,,8,9,18,19,,8,9,18,19,,10,12,14,16,17,,8,9,18,19,,7,8,19,20,,7,20,,6,7,20,21,,6,7,20,21,,6,7,20,21,,6,7,20,21,,6,7,20,21,,6,7,20,21,,6,7,20,21,,6,7,20,21,,7,20,,7,8,19,20,,8,19,,8,9,18,19,,9,11,13,15,17,18>
    IFNB <bx>
    mov gs:[bx+di+bp], WORD PTR 0h
    ENDIF
    IFB <bx>
    add bp,320
    ENDIF
    ENDM
  jmp Koniec_rysowania_kuli

  Moze_9:
  dec cx
  jcxz Rysuj_9
  jmp Moze_10
  Rysuj_9:
  IRP bx,<12,14,16,,10,11,17,18,,9,10,18,19,,9,19,,8,9,19,20,,8,9,19,20,,8,20,,7,8,20,21,,7,8,20,21,,7,8,20,21,,7,8,20,21,,7,8,20,21,,7,8,20,21,,7,8,20,21,,8,20,21,,8,9,19,21,,8,9,19,21,,9,10,19,21,,10,11,20,21,,11,13,15,16,20,21,,20,,19,20,,7,19,20,,6,8,19,,6,8,18,19,,7,18,,17,,8,16,,10,12,14>
    IFNB <bx>
    mov gs:[bx+di+bp], WORD PTR 0h
    ENDIF
    IFB <bx>
    add bp,320
    ENDIF
    ENDM
  IRP bx,<5778,8327>
    mov gs:[di+bx],BYTE PTR 0
    ENDM
  jmp Koniec_rysowania_kuli

  Moze_10:
  dec cx
  jcxz Rysuj_10
  jmp Moze_J
  Rysuj_10:
  IRP bx,<16,18,20,22,,5,14,15,23,24,,4,5,13,14,24,25,,2,4,5,13,14,24,25,,4,5,13,25,,4,5,12,13,25,26,,4,5,12,13,25,26,,4,5,12,13,25,26,,4,5,12,26,,4,5,11,12,26,27,,4,5,11,12,26,27,,4,5,11,12,26,27,,4,5,11,12,26,27,,4,5,11,12,26,27,,4,5,11,12,26,27,,4,5,11,12,26,27,,4,5,11,12,26,27,,4,5,11,12,26,27,,4,5,11,12,26,27,,4,5,12,26,,4,5,12,13,25,26,,4,5,12,13,25,26,,4,5,12,13,25,26,,4,5,13,25,,4,5,13,14,24,25,,4,5,13,14,24,25,,3,5,6,14,15,23,24,,1,3,5,7,8,16,18,20,22>
    IFNB <bx>
    mov gs:[bx+di+bp], WORD PTR 0h
    ENDIF
    IFB <bx>
    add bp,320
    ENDIF
    ENDM
  IRP bx,<6,1281>
    mov gs:[di+bx],BYTE PTR 0
    ENDM
  jmp Koniec_rysowania_kuli

  Moze_J:
  dec cx
  jcxz Rysuj_J
  jmp Moze_D
  Rysuj_J:
  IRP bx,<14,16,18,20,21,,16,18,19,,17,18,,17,18,,17,18,,17,18,,17,18,,17,18,,17,18,,17,18,,17,18,,17,18,,17,18,,17,18,,17,18,,17,18,,17,18,,17,18,,17,18,,17,18,,8,17,18,,7,9,17,18,,7,9,17,18,,8,17,,16,17,,9,16,17,,11,13,15>
    IFNB <bx>
    mov gs:[bx+di+bp], WORD PTR 0h
    ENDIF
    IFB <bx>
    add bp,320
    ENDIF
    ENDM
  IRP bx,<7688>
    mov gs:[di+bx],BYTE PTR 0
    ENDM
  jmp Koniec_rysowania_kuli

  Moze_D:
  dec cx
  jcxz Rysuj_D
  jmp Moze_K
  Rysuj_D:
  IRP bx,<6,8,10,12,14,16,,8,10,11,17,18,,9,10,19,,9,10,19,20,,9,10,20,21,,9,10,20,21,,9,10,21,,9,10,21,22,,9,10,21,22,,9,10,21,22,,9,10,21,22,,9,10,21,22,,9,10,21,22,,9,10,21,22,,9,10,21,22,,9,10,21,22,,9,10,21,22,,9,10,21,22,,9,10,21,22,,9,10,21,22,,9,10,21,22,,9,10,21,,9,10,20,21,,9,10,20,21,,9,10,19,20,,9,10,18,19,,8,10,11,17,18,,6,8,10,12,14,16>
    IFNB <bx>
    mov gs:[bx+di+bp], WORD PTR 0h
    ENDIF
    IFB <bx>
    add bp,320
    ENDIF
    ENDM
  jmp Koniec_rysowania_kuli

  Moze_K:
  dec cx
  jcxz Rysuj_K
  jmp Moze_Joker
  Rysuj_K:
  IRP bx,<3,5,7,9,10,19,21,23,24,,5,7,8,21,22,,6,7,,6,7,,6,7,,6,7,,6,7,,6,7,,6,7,,6,7,,6,7,13,,6,7,12,14,,6,7,11,13,14,,6,7,14,15,,6,8,14,15,,6,7,15,16,,6,7,16,17,,6,7,16,17,,6,7,17,18,,6,7,17,18,,6,7,18,19,,6,7,18,19,,6,7,18,19,,6,7,19,20,,6,7,19,20,,6,7,20,21,,6,7,20,21,,5,7,8,19,21,22,,3,5,7,9,10,17,19,21,23,24>
    IFNB <bx>
    mov gs:[bx+di+bp], WORD PTR 0h
    ENDIF
    IFB <bx>
    add bp,320
    ENDIF
    ENDM
  IRP bx,<661,980,1299,1618,1937,2256,2575,2894,4170,>
    mov gs:[di+bx],BYTE PTR 0
    ENDM
  jmp Koniec_rysowania_kuli

  Moze_Joker:
  dec cx
  dec cx
  jcxz Rysuj_Joker
  jmp Koniec_rysowania_kuli
  Rysuj_Joker:
  IRP bx,<15,16,17,18,19,,14,20,21,,13,22,,13,23,,7,8,9,10,12,22,24,,6,11,21,25,26,,5,27,,4,27,,3,28,,3,28,,2,7,24,29,,2,5,6,8,23,25,26,29,,2,4,8,23,27,29,,2,4,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,27,29,,1,4,8,23,27,30,,1,2,3,7,24,28,29,30,,1,3,7,24,28,30,,0,4,7,24,27,31,,1,3,7,24,28,30,,2,7,24,29,,8,23,,8,23,,8,23,,9,22,,9,22,,10,21,,11,20,,12,13,14,15,16,17,18,19,,14,17,,14,17>
    IFNB <bx>
    mov gs:[bx+di+bp], BYTE PTR 0h
    ENDIF
    IFB <bx>
    add bp,320
    ENDIF
    ENDM
   mov bp,0
  IRP bx,<,15,17,18,,14,16,18,20,,14,16,18,20,21,,13,15,17,19,20,,7,9,12,14,16,18,19,22,23,,6,8,10,12,14,16,18,20,22,24,25,,5,7,9,11,13,15,17,19,21,23,25,,4,6,8,10,12,14,16,18,20,22,24,26,,4,6,8,10,12,14,16,18,20,22,24,26,,3,5,8,10,12,14,16,18,20,22,25,27,,3,9,11,13,15,17,19,21,27,,9,11,13,15,17,19,21,,,2,28>
    IFNB <bx>
    mov gs:[bx+di+bp], WORD PTR 0c0ch
    ENDIF
    IFB <bx>
    add bp,320
    ENDIF
    ENDM
  mov bp,1280;
  IRP bx,<23,,,,,,,,3,28,,3,28,,3,28>
    IFNB <bx>
    mov gs:[bx+di+bp], BYTE PTR 0ch
    ENDIF
    IFB <bx>
    add bp,320
    ENDIF
    ENDM
  mov bp,5120;
  IRP bx,<2,29,,1,2,3,28,29,30,,2,29>
    IFNB <bx>
    mov gs:[bx+di+bp], BYTE PTR 0eh
    ENDIF
    IFB <bx>
    add bp,320
    ENDIF
    ENDM
  mov bp,4480
  IRP bx,<9,11,13,15,17,19,21,,8,10,12,14,16,18,20,22,,8,10,12,14,16,18,20,22,,8,10,12,14,16,18,20,22,,8,10,12,14,16,18,20,22,,8,10,12,14,16,18,20,22,,9,11,13,15,17,19,21,,9,11,13,15,17,19,21,,9,11,13,15,17,19,21,,10,12,14,16,18,20,,10,12,14,16,18,20,,11,13,15,17,19,,12,14,16,18,,,15,,15>
    IFNB <bx>
    mov gs:[bx+di+bp], WORD PTR 0e0eh
    ENDIF
    IFB <bx>
    add bp,320
    ENDIF
    ENDM
  mov bp,4800
  IRP bx,<11,12,13,20,19,18,,10,14,21,17,,10,14,21,17,,10,14,21,17,,11,12,13,20,19,18>
    IFNB <bx>
    mov gs:[bx+di+bp], BYTE PTR 00h
    ENDIF
    IFB <bx>
    add bp,320
    ENDIF
    ENDM
  mov bp,5120
  IRP bx,<11,12,13,20,19,18,,11,13,20,18,,11,12,13,20,19,18>
    IFNB <bx>
    mov gs:[bx+di+bp], BYTE PTR 0fh
    ENDIF
    IFB <bx>
    add bp,320
    ENDIF
    ENDM
    mov gs:[di+5440+12],BYTE PTR 01h;
    mov gs:[di+5440+19],BYTE PTR 01h;
  mov bp,6720;
  IRP bx,<12,19,,11,13,14,15,16,17,20,18,,11,20,,12,19,,13,14,15,16,17,18>
    IFNB <bx>
    mov gs:[bx+di+bp], BYTE PTR 00h
    ENDIF
    IFB <bx>
    add bp,320
    ENDIF
    ENDM
  mov bp,7040;
  IRP bx,<12,19,,12,13,14,15,16,17,18,19,,13,14,15,16,17,18>
    IFNB <bx>
    mov gs:[bx+di+bp], BYTE PTR 0fh
    ENDIF
    IFB <bx>
    add bp,320
    ENDIF
    ENDM

  Koniec_rysowania_kuli:

  pop bp
  pop di
  pop cx
  pop bx
  pop eax
  ret
_Rysuj_kule ENDP

_Czysc_ekran PROC FAR
  push ax
  push es
  push cx
  push di
  push bp
  mov ax,0A000h
  mov es,ax
  mov cx,32000
  mov bp,sp
  mov al,ss:[bp+14]
  mov ah,al
  mov di,0
  cld
  rep stosw
  pop bp
  pop di
  pop cx
  pop es
  pop ax
  ret
_Czysc_ekran ENDP

_Wypisz PROC FAR
  push ax
  push bx
  push cx
  push dx
  push es
  push bp
  push si
  push di
  mov ax,0A000h
  mov gs,ax
  mov bp,sp
  mov si, WORD PTR ss:[bp+20]      ;poczatkowe polozenie lancucha
  mov ah,35h
  mov al,43h
  int 21h                      ;pozycja matryc znakow
  mov ax, WORD PTR ss:[bp+26]  ;obliczanie offsetu x,y
  mov cx,320
  mul cx
  add ax, WORD PTR ss:[bp+24]
  mov cx,ax                    ;przesuniecie w bp
  mov ah, BYTE PTR ss:[bp+22]  ;w dx kolory
  mov bp,cx
  dec bp
  Nastepny_Znak:
    xor ch,ch
    mov cl,ds:[si]
    cmp cl,0                   ;ciag konczy sie 0
    jne Znak_OK
    jmp Koniec_Write
    Znak_OK:
    shl cx,3                 ;znajduje polozenie w tablicy matryc
    mov di,cx
    mov cx,8
    Znak_y:
      mov al,es:[bx+di]
      mov dx,8
      Znak_x:
	inc bp
	cmp dx,0
	je Koniec_Znak_x
	dec dx
	bt ax,dx
	jnc Znak_x
	mov gs:[bp],ah
	jmp Znak_x
      Koniec_Znak_x:
      add bp,311
      inc di
      dec cx
      jnz Znak_y
    sub bp,2552
    inc si
    jmp Nastepny_Znak
  Koniec_Write:
  pop di
  pop si
  pop bp
  pop es
  pop dx
  pop cx
  pop bx
  pop ax
  ret
_Wypisz ENDP

KOD ENDS
END Start