# BÉRLET – Rent Your Airplane and Make Money
#rendezés #dinamikus programozás #bináris keresés

"ABEAS Corp." egy nagyon kicsi cég, amely egyetlen repülőgép tulajdonosa. Az ABEAS Corp ügyfelei olyan nagy légitársaságok, amelyek bérbeadják a repülőgépet, hogy alkalmi többletkapacitást alkalmazzanak.

Az ügyfelek olyan bérleti megbízásokat küldenek, amelyek egy időintervallumból és egy olyan árból állnak, amelyet az ügyfél az adott időszakban a repülőgép bérletéért fizetni hajlandó. Minden ügyfél megrendelése előre ismert. Természetesen nem minden megrendelés fogadható el, és néhány rendelést vissza kell utasítani. Eugene LAWLER, az ABEAS Corp tudományos vezérigazgató-helyettese szeretné maximalizálni a vállalat profitját.

Megkérjük, hogy számítson ki egy optimális megoldást.

## Példa

Vegyük például azt az esetet, amikor a cégnek 4 megrendelése van:

1. rendelés (kezdési időpont 0, időtartam 5, ár 10)
2. rendelés (kezdési időpont 3, időtartam 7, ár 8)
3. rendelés (kezdési időpont 5, időtartam 9, ár 7)
4. rendelés (kezdési időpont 6, időtartam 9, ár 8)

Az optimális megoldás a 2. és 3. sorrend csökkenésében áll, és az erősítés 10+8 = 18.
Vegye figyelembe, hogy az 1. és 3. rendelésből készült megoldás megvalósítható (a repülőgépet megszakítás nélkül béreljük 0-tól 14-ig), de nem optimális.

## Bemenet

A bemenet első sora egy **T ≤ 30** számot tartalmaz, amely a követendő tesztesetek számát jelzi. Minden teszteset első sora tartalmazza az n megrendelések számát (**n ≤ 10000**). A következő **n** sorban a parancsok vannak megadva. Minden megbízást 3 egész érték ír le: A megbízás kezdő időpontja **st** (**0 ≤ st < 1000000**), a megbízás **d** időtartama (**0 < d < 1000000**), és a **p** ár (**0 < p < 100000**) a az ügyfél kész kifizetni ezt a rendelést.

## Kimenet

Ki kell számolnia az optimális megoldást. A programnak minden tesztesethez fel kell írnia a légitársaságok által fizetett teljes árat.

[feladat link](https://www.spoj.com/problems/RENT/)