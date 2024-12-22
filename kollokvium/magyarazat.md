# Feladat magyarázat - Assignments

## Kulcsötlet: Dinamikus programozás Bitmaskkal
A probléma bitmaszk DP megközelítést használ. Íme a bontás:

- ***dp[student][mask]***:
  - ***student***: Azon tanulók száma, akikhez eddig témakört rendeltek.
  - ***mask***: Olyan bitmaszk, ahol minden bit azt jelzi, hogy egy téma hozzá van-e rendelve vagy sem. Például:
    - Ha a ***mask = 0101*** (binárisan), ez azt jelenti:
      - A 0. témakör hozzá van rendelve.
      - Az 1. témakör nincs hozzárendelve.
      - A 2. témakör hozzá van rendelve.
      - A 3. téma nincs hozzárendelve.

- Ez az állapot azt mutatja meg, hogy hány érvényes feladat létezik, ha az adott hallgatónál vagyunk, és az aktuális témafeladatokat mask képviseli.

- **Átmenet**:
  - Adott tanulóhoz próbáljon hozzárendelni minden neki tetsző témát (ahol a preferenciamátrix értéke ***1***).
  - Ha a téma nincs hozzárendelve (a bitmaszk segítségével ellenőrizve), akkor rekurzív módon számítsa ki, hogy a fennmaradó tanulók hány módon végezhetik el a feladatokat.
- **Alapeset**:
  - Ha minden tanulóhoz hozzárendeltek a témákat (***student == n***), akkor 1-et adunk vissza, mert ez egy érvényes feladat.
- **Memoizáció**:
  - Tárolja az egyes állapotok eredményeit (tanuló, maszk), hogy elkerülje a felesleges számításokat.

## Kód áttekintése
### Bemeneti elemzés

Minden tesztesethez:
```c++
int n;
cin >> n;
vector<int>> preferences(n, vector<int>(n));

for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
        cin >> preferences[i][j];
    }
}
```
- Beolvassa a tanulók számát (***n***) és preferenciáik mátrixát (***preferences***).

### DP inicializálás
```c++
memset(dp, -1, sizeof(dp));
```
- Töröli az új teszteset DP-táblázatát. A táblázat az állapotok (***student, mask***) eredményeit tárolja.

### Rekurzív függvény
```c++
long long count_assignments(int student, int n, int mask, const vector<vector<int>>& preferences) {
    if (student == n) return 1;
    if (dp[student][mask] != -1) return dp[student][mask];
```

- Ha az összes tanulóhoz hozzárendeltek témákat, adjon 1-et, mert ez érvényes feladat.
- Ha ennek az állapotnak az eredménye (***student, mask***) már ki van számítva, adja vissza.

### Átmeneti logika
```c++
long long ways = 0;
for (int topic = 0; topic < n; ++topic) {
    if (preferences[student][topic] == 1 && !(mask & (1 << topic))) {
        ways += count_assigments(student + 1, n, mask | (1 << topic), preferences);
    }  
}
return dp[student][mask] = ways;
```
- Bejárja az összes témakört (0-tól n-1-ig) az aktuális tanulóhoz:
  1. Ellenőrzi, hogy a tanulónak tetszik-e a téma (***preferences[student][topic] == 1***).
  2. Ellenőrzi, hogy a téma nincs-e hozzárendelve (***!(mask & (1 << topic))***).
  3. Ha mindkét feltétel igaz:
     - Hozzárendeli a témát a tanulóhoz (frissíti a bitmaszkot).
     - Ismétlés a következő diáknál.
     - Adja hozzá az eredményt a módok (***ways***) teljes számához.
- Gyorsítótárazza az eredményt az aktuális állapothoz a ***dp[student][mask]*** fájlban.

## Fő függvény
```c++
cout << count_assignments(0, n, 0, preferences) << endl;
```
- Kezdje a 0. tanulótól anélkül, hogy téma lett volna hozzárendelve (***mask = 0***).

### Hogyan működik a bitmaszk

- A bitmaszk egy egész szám, ahol minden bit egy témát jelöl.
- Például a maszk = 1010 (bináris) azt jelenti:
  1. téma: Nincs hozzárendelve.
  2. téma: Hozzárendelve.
  3. téma: Nincs hozzárendelve.
  4. téma: Hozzárendelve.

- Ellenőrzi, hogy van-e téma hozzárendelve:
  - Használja a ***mask & (1 << topic)***. Ha ez 0, a téma nincs hozzárendelve.
- Téma hozzárendelése:
  - Használja a ***mask | (1 << topic)*** a téma hozzárendeltként való megjelöléséhez.
