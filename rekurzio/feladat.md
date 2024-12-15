# POUR1 – Pouring Water
#gcd #rekurzió

Adott két edény, amelyek közül az egyik **a** liter, a másik pedig **b** liter vizet tud befogadni, határozza meg a lépések számát pontosan **c** liter víz előállításához az egyik edényben.

Kezdetben mindkét edény üres. A következő műveletek „lépésnek” számítanak:

- edény kiürítése,
- edény megtöltése,
- vizet önteni egyik edényből a másikba anélkül, hogy kiömlne, amíg az egyik edény meg nem telik vagy ki nem ürül.

## Bemenet

Egy **t** egész szám, **1 <= t <= 100**, amely a tesztesetek számát jelöli, majd **t** bemeneti adathalmaz követi, amelyek mindegyike három, 40000-nél nem nagyobb pozitív egész számból áll (**a, b, c**), külön sorban megadva.

## Kimenet

Minden bemeneti adatkészlethez adja ki a minimális lépésszámot, amely a **c** liter megszerzéséhez szükséges, vagy -1, ha ez lehetetlen.

[feladat link](https://www.spoj.com/problems/POUR1/)