# blockchain-pratybos2

## veikimas

prat2.cpp realizuoti 3 testavimo atvejai parodantys sukurto blockchain funkcionalumą
programa veikia tik su  įvesties failais pavadinimu transactions.txt ir vartotojai.txt
testavimo atvejai vykdomi įvedus užduoties kodą (1, 2 arba 3)
testavimo atvėjai:
1. Pirmos užduoties metu pridedami du blokai į blockchain ir išvedami duomeys, taip pat galima pasirinkti pamatyt bloką sudarančias visas transakcijas įvedant "y'
2. Antros užduoties metu pavaizduojamas "decentralizuotos" blokų kasimas, kurio metu varžosi "kasėjai", kuris pirmas ras nonce, radus nonce pavaizduojami bloko duomenys ir kas iškasė
3. Trečios užduoties metu į blockchain pridedami blokai tol kol nelieka transakcijų. Kai visi blokai sudėti galima pasirinkti pamatyti informaciją apie bet kurį blockchain priklausantį bloką ir jo transakcijos
## Kita informacija


1. vieno bloko generavimas užtrunka nuo 0.25 s. iki 0.4 s.
2. visom hashavimo funkcijom naudojama Pirmam darba sukurta myHash() funkcija
3. kad blokas būtų įdėtas į blockchain jo hash kodas turi prasidėt su 4 nuliais
4. į bloką transakcijos pasirenkamos atsitiktinai

### pavyzdys kaip atrodo block informacija

block hash: 00009eb4d30f6e7f28eb6beea467cf4f3eb79535e9d94a36b7e7909fc158cd58

Prev hash: 0000d4af6ce5cb3810606de0a93df442c511bda312d06b4cd3a3c9cc08510e5d

version: 0.1

timestamp: 689363087.000000

merkle hash: b87dd82606f12e7dc67a47e4f9110d215aa1c2ba46224b634c1f28f98d6e4451

nonce: 28036

difficulty: 4

number of transactions: 100


### pavyzdys kaip atrodo transakcijos informacija

transactionId: 1f065a8779930728089e1a368f06b133d2e8739f5eb3c59394928a9faf079bd2

sender: vartotojas873

resever: vartotojas615

amount: 90800


