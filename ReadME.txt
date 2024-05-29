# Simulare Turneu - Tema 2

Tema 2 presupune simularea unui turneu/campionat, unde tabela de scor este implementată cu ajutorul unui graf orientat. Fiecare muchie reprezintă un meci purtat între 2 jucători, adică vârfurile grafului. 
Acest proces se repetă, iar graful va avea un număr de etape. 

Tema 2 presupune administrarea meciurilor astfel încât din 32 de echipe din runda 1 vor rămâne 16 în runda 2, 8 în runda 3, 4 în runda 4, 2 în runda a 5-a, adică finala. Altfel spus, sunt 2^5 echipe, din care una singură rămâne câștigătoare.

## Cerințe

Tema conține 2 puncte:
1. Simularea turneului, descrisă mai sus.
2. Calcularea unui scor bazat pe numărul de victorii și importanța în turneu a echipei inamice. Fiecare echipă va primi un scor, chiar și cele care nu au câștigat niciun meci. 
După distribuirea punctelor se face un podium, output-ul fiind în fișierul `scor`.

## Implementare

Programul conține un fișier `main.c`, la care se atașează `liste.c` și `grafuri.c`, care conțin funcțiile standard pentru manipularea listelor și respectiv grafurilor. Legătura dintre fișierele `.c` este realizată prin headere.

Implementarea folosește o rezolvare cu o listă simplu înlănțuită pentru a forma graful și clasamentul. Lista se parcurge cu un loop while in interiorul unui altuia, până rămâne un singur jucător, "head"-ul listei. 
While-ul din interior efectueaza eliminarile dintr-o runa, iar cel exterior repeta operatia pana cand se afla castigatorul, realizându-se astfel un turneu eliminatoriu pe nivele.

Programul contine comentarii descriptive in linia de cod, iar funcția `main` a programului conține în mare parte apeluri către funcții externe.

## Progresul Proiectului

Progresul proiectului poate fi urmărit pe GitHub, unde au fost încărcate 3 commit-uri de-a lungul întocmirii programului.

### Dificultti intampinate

1. Asemanator temei 1, cand 2 echipe dintr-un meci au scoruri egale, echipa castigatoare va fi cea luata descrescator in functie de nume, si nu crescator asa cum spune cerinta.
2. La punctul 2 al temei, checker-ul a fost conceput sa compare scorul obtinut de echipe pentru o runda in plus decat ar fi in mod normal.
