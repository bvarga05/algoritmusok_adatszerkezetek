# Feladat magyarázat - Pouring Water

## Kulcsfogalmak
**1. Ellenőrizzük, hogy meg lehet-e valósítani:**
  - Csak akkor lehet ***c*** litert mérni két ***a*** és ***b*** űrtartalmú kannával, ha:
  
      1. ***c <= max(a, b)*** (Nem mérhetsz többet, mint a nagyobb kancsó kapacitása).
      2. ***c % gcd(a, b) == 0*** (A ***c*** térfogatnak ***a*** és ***b*** legnagyobb közös osztójának többszörösének kell lennie).
   
 - Ha ezen feltételek bármelyike ​​nem teljesít, a válasz ***-1***.
  
**2. Rekurzív keresés:**

- A probléma állapottér-keresésként modellezhető, ahol az állapotot a két kancsóban (***current_a*** és ***current_b***) lévő víz mennyiségével ábrázoljuk.
- Bármely adott állapotból átválthat egy másik állapotba az alábbi műveletek egyikével:

  1. Töltse meg bármelyik kancsót a maximális kapacitásig.
  2. Ürítse ki teljesen bármelyik kancsót.
  3. Öntsön vizet egyik kancsóból a másikba, amíg az egyik kancsó ki nem ürül, vagy a másik megtelik.

**3. Memoizáció:**

  - A rekurzív függvény egy térképet (***memo***) használ az adott állapot eléréséhez szükséges lépések minimális számának tárolására (***current_a***, ***current_b***), hogy elkerülje a redundáns számításokat.

## A program lépései

**1. lépés: Bevitel és megvalósíthatósági ellenőrzés**

  - Minden tesztesethez:
    - Olvassa le a két kancsó (***a*** és ***b***) kapacitását és a céltérfogatot ***c***.
    - Ellenőrizze, hogy ***c*** megvalósítható-e a feltételekkel:
      - ***c <= max(a, b)***.
      - ***c % gcd(a, b) == 0***.
    - Ha nem kivitelezhető, a kimenet ***-1***.
  
**2. lépés: Rekurzív függvény a lépések kereséséhez**

A ***find_steps*** rekurzív függvény a következőket hajtja végre:

  **1. Alapeset:**
  - Ha bármelyik kancsó pontosan ***c*** litert tartalmaz (***current_a == c*** vagy ***current_b == c***), akkor adjon vissza ***0***-t (nincs szükség további lépésekre).
  
  **2. Memoizáció:**
  - Ha az aktuális állapotot (***current_a***, ***current_b***) már meglátogatta, adja vissza a tárolt eredményt, hogy elkerülje az újraszámítást.

  **3. Próbáljon ki minden lehetséges műveletet:**
  - Az aktuális állapothoz (***current_a***, ***current_b***) próbálja meg rekurzívan mind a hat lehetséges műveletet:
    1. Töltse meg az első kancsót (***current_a = a***).
    2. Töltse meg a második kancsót (***current_b = b***).
    3. Ürítse ki az első kancsót (***current_a = 0***).
    4. Ürítse ki a második kancsót (***current_b = 0***).
    5. Öntsön vizet az első kancsóból a másodikba, amíg az egyik ki nem ürül vagy megtelik.
    6. Öntsön vizet a második kancsóból az első kancsóba, amíg az egyik ki nem ürül vagy megtelik.
  - Minden érvényes művelethez számítsa ki az eredményül kapott állapotot, és keresse meg rekurzív módon az állapot minimális lépéseit.

  **4. Kövesse nyomon a minimális lépéseket:**
  - Miután megvizsgálta az összes lehetséges műveletet, frissítse a ***memo*** táblázatot az aktuális állapot minimális számú lépésével.
  - Ha egyetlen érvényes átmenet sem vezet megoldáshoz, jelölje az aktuális állapotot ***-1***-nek.

**3. lépés: Az eredmény visszaküldése**

  - Minden teszteset eredménye a ***find_steps(a, b, c, 0, 0, memo)*** által visszaadott érték:
    - Kezdve úgy, hogy mindkét kancsó üres (***current_a = 0***, ***current_b = 0***).