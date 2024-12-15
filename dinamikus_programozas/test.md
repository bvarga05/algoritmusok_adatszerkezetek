# Teszt dokumentáció

A teszt az **Alphacode** feladathoz készült, hogy megkönnyítse a program ellenőrzését. A tesztesetek a *tests* mappában hoztam létre. Ebben a mappában bemeneti értékek és elvárt kimeneti értékek vannak. Ezek alapján történik az összehasonlítás. A tesztelni kivánt program egy darab bemeneti fáljt fog kapni, mivel a program a *0* értékig fut, így elég, ha az az egy fájl 10 sor tesztet tartalmaz.

## Használata
1. első lépésben ellenőrizzük, hogy le tudjuk-e futtatni a tesztet, ezt az *ls -l* parancsal megnézhetjük, ha van futtatási jogosultágunk hozzá, akkor kérem hagyja ki a 2. utasítást
2. *chmod u+x test_acode.sh* paranccsal engedélyt adunk a felhasználónak
3. futtatása a bash script-et a terminálban
4. **parancs:** *./test_acode.sh*

## Működése
- *C_PROGRAM:* tárolja a lefordított kódot
- *PROGRAM:* változó magát a forráskódot
- *TEST_DIR:* pedig azt a könyvtárat ahol a tesztek vannak
- ezután megtörténik a forráskód fordítása 
- a program egy *for* ciklusban végig megy az összes teszteseten
- *diff* paranccsal összehasonlítja a *test_expected.txt*-t (az elvárt kimeneti eredmény) és a *test_actual.txt*-t (tényleges kimeneti eredmény)
- helyes végeredmény esetén: **Passed** kiírást, amennyiben a teszt hibásan futott le akkor **Failed** lesz a kimenet a terminálban. Az utóbbi esetben kiírja, hogy mi(k) volt(ak) a külömbség(ek).
- a ciklus végén az *test_actual.txt*-t törli a teszt