# Feladat magyarázat - Rent Your Airplane and Make Money

## Probléma áttekintése
***T***-próbaeseteket kap. Minden tesztesethez:

1. ***n*** rendelés van. Minden rendelés leírása:
   - Kezdés időpontja (***start***).
   - Időtartam (***duration***) (a befejezési idő kiszámítására szolgál).
   - Profit (***price***).

2. Maximalizálni kell a nyereséget a nem átfedő rendelések egy részének kiválasztásával.

## A program lépései

**1. lépés: Bemenet elemzése**
   - Olvassa el a ***T*** tesztesetek számát.
   - Minden tesztesethez:
     - Olvassa el a megrendelések számát ***n***.
     - Minden egyes rendelésnél számítsa ki a befejezési időt ***start + duration***.
  
**2. lépés: Rendezések rendezése befejezési idő szerint**

   - Rendezi a sorrendet a végidejük szerinti növekvő sorrendbe.
     - Ez biztosítja, hogy először a korábbi rendeléseket tudjuk figyelembe venni, miközben ellenőrizzük az átfedő rendeléseket.

**3. lépés: Dinamikus programozási táblázat**

   - Dinamikus-programozási (***dp***) táblát használ, ahol ***dp[i]*** az első ***i*** rendelések figyelembevételével elérhető maximális profitot jelöli.

**4. lépés: Bináris keresés a nem ütköző sorrendre**

   - Minden egyes ***i*** rendelésnél határozza meg, hogy a beszámítás nagyobb nyereséget eredményez-e:

     **1. Tartalmazza az aktuális rendelést:**
        - Adja hozzá az aktuális rendelés nyereségét (***orders[i].price***).
        - Használja a bináris keresést a legutóbbi megbízás megkereséséhez, amely az aktuális rendelés kezdete előtt ér véget.
        - Hozzáadja a legutóbbi, nem ütköző megbízás nyereségét (***dp[find_last_non_conflicting(i)]***).

     **2. Az aktuális sorrend kizárása:**
        - Vegyük az eddigi maximális profitot (***dp[i-1]***).
  
     **3. Frissíti a ***dp[i]***-t a két lehetőség közül a maximumra.**
   
**5. lépés: Visszaadja a maximális nyereséget**

   - Az összes megrendelés feldolgozása után a dinamikus-programozási tábla utolsó értéke (***dp[n-1]***) tartalmazza a teszteset maximális nyereségét.

  