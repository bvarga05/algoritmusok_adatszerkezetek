# Feladat magyarázat - Ada and Branches


## Probléma áttekintése
1. **Bemeneti struktúra:**
   - ***N*** csomópont és ***M*** él, mindegyik élnek súlya van.
   - ***Q*** lekérdezések, ahol minden lekérdezés a következőket adja meg:
     - Csomóponti ***node***.
     - Egy küszöbsúlyú ***weight***.
     - A feladat a ***node***-ot tartalmazó összekapcsolt komponens méretének meghatározása az összes súlynál nagyobb vagy azzal egyenlő ***weight*** sulyú él hozzáadása után.

2. **Kimenet:**
   - Minden lekérdezéshez adja ki a csomópontot tartalmazó csatlakoztatott összetevő méretét.

## Program magyarázata
**1. lépés: DSU (Disjoint Set Union) a csatlakoztatott komponensekhez**
A DSU (vagy Union-Find) adatstruktúra hatékonyan kezeli és egyesíti a csatlakoztatott összetevőket:

   - ***find(x)***:
     - Megkeresi az ***x***-et tartalmazó halmaz képviselőjét (root).
     - Útvonal-tömörítést használ a jövőbeli lekérdezések felgyorsítására azáltal, hogy közvetlenül összekapcsolja a csomópontokat a gyökérrel.
   - ***unite(x,y)***:
     - Összevonja az ***x***-et és ***y***-t tartalmazó halmazokat (ha különböző halmazokban vannak).
     - Méret szerinti egyesítést használ a kisebb fának a nagyobb fához való rögzítéséhez, csökkentve a kapott fa magasságát.
   - ***get_size(x)***:
     - Az x-et tartalmazó csatlakoztatott összetevő méretét adja vissza.

**2. lépés: Bemeneti elemzés**
   - Élek (***M***): Minden élnek ***w*** súlya van, és két ***u*** és ***v*** csomópontot köt össze.
   - Lekérdezések (***Q***): Minden lekérdezés a következőket adja meg:
     - Csomóponti ***node***.
     - Küszöbsúly (***weight***) az élek szűréséhez.
     - Az index (***index***) tárolja, hogy az eredményeket a megfelelő sorrendben lehessen kiadni.

**3. lépés: Súly szerinti rendezés**

Mind az élek, mind a lekérdezések súly szerint csökkenő sorrendben vannak rendezve:

   - Ez lehetővé teszi először a legnehezebb élek és a legmagasabb küszöb lekérdezések feldolgozását.
   - A rendezés biztosítja, hogy a lekérdezések megválaszolása közben hatékonyan adjuk hozzá az éleket csökkenő súlyozási 
    sorrendben.

**4. lépés: A lekérdezések feldolgozása**

   - Iteráljon a rendezett lekérdezéseken keresztül.
   - Minden lekérdezéshez:
     - Adjon hozzá minden olyan élt, amelynek súlya ≥ lekérdezési súly, DSU használatával. Ez biztosítja, hogy a grafikon dinamikusan növekszik, kielégítve az aktuális küszöböt.
     - Élek hozzáadása után határozza meg a lekérdezett csomópontot tartalmazó csatlakoztatott komponens méretét a DSU segítségével (***get_size(node)***).

**5. lépés: Kimeneti eredmények**

   - Az összes lekérdezés feldolgozása után adja ki az eredményeket az eredeti lekérdezések sorrendjében.