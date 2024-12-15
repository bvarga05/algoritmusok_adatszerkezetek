# Feladat magyarázat - Alphacode


## Program elemzése
1. **Bemenet:** 
   - A program ismételten beolvassa a bemeneti számjegyeket

        ```c++
        cin >> input
        ```
    - Minden karakterláncot feldolgoz, és kiszámolja, hogy hány lehetséges dekódolása van, amíg nem talál egy *„0”* bemenetet, amely leállítja a programot.
2. **Dekódolási logika** (a ***count_decodings()*** függvényben megvalósítva):
   - A ***count_decodings()*** függvény egy ***s*** karakterláncot vesz fel, és kiszámítja a dekódolási módok számát.
3. **Dinamikus programozás:**
   - A megoldás dinamikus programozást (DP) használ a dekódolások számának hatékony kiszámításához.
   - Inicializálunk egy ***dp*** tömböt, ahol a ***dp[i]*** tárolja az ***s*** karakterlánc első ***i*** karaktereinek dekódolásának számos módját.
4. **Alapeset:**
   - ***dp[0] = 1:*** Egy üres karakterlánc pontosan 1 módon dekódolható (triviálisan).
   - ***dp[1] = 1:*** Ha az első karakter nem nulla, akkor 1 módja van a dekódolásnak (egy betűnek felel meg).
5. **Ismétlődés:** A karakterlánc minden i pozíciójához két lehetőséget ellenőrizünk:
   - **Egyjegyű dekódolás:**
     - Ha az ***s[i-1]*** (a karakterlánc ***i-1*** pozíciójában lévő karakter) nem *'0'*, akkor dekódolhatjuk egyetlen betűként (pl. '1' = 'A', '2' = 'B' ', ..., '9' = 'én'). Hozzáadjuk az első ***i-1*** karakterek dekódolásának számos módját (***dp[i-1]***).
     - ***dp[i] += dp[i - 1]***, ha ***s[i-1] != '0'***.
   - **Kétjegyű dekódolás:**
     - Ha az utolsó két számjegy (azaz ***s[i-2]*** és ***s[i-1]***) 10 és 26 közötti számot alkot (beleértve), akkor ez egy betűt jelenthet ('10' = 'J', '11) ' = 'K', ..., '26' = 'Z'). Ha érvényes, hozzáadjuk az első ***i-2*** karakterek dekódolásának módjait (***dp[i-2]***).
     - ***dp[i] += dp[i - 2]***, ha a kétjegyű szám 10 és 26 között van.
6. **Visszaküldés eredménye:**
   - A karakterlánc feldolgozása után a ***dp[n]*** tárolja a dekódolások teljes számát.
