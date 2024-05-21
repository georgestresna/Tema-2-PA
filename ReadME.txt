Tema 2 presupune simularea unui turneu/ campionat, tabela de scor fiind implementta cu ajutoarul unui graf orienat. fiecare muchie reprezinta un meci purtat intre 2 jucatori, adica varfurile grafului.
Acest proces se repeta, iar graful va avea un numar de etape. Tema 2 presupune administrarea meciurilor, astfel incat din 32 de echipe din runda 1 vor ramane 16 in runda 2, 8 in runda 3, 4 in runda 4, 2 in runda a 5-a, adica finala.
Altfel spus sunt 2^5 echipe, din care una singura ramane castigatoare.
Tema contine 2 puncte, primul este discutat deasupra. Cea de-a doua cerinta calculeaza un scor bazat pe numarul de castiguri si importanta in turneu a echipei inamice. 
Fiecare echipa va primi un scor, chiar si cele care nu au castigat niciun meci.
Dupa dupa distribuirea puncelor se face un podium, output-ul din fisierul scor.

Programul contine un fisier main.c la care se ataseaza liste.c si grafuri.c, ce contin functiile standard pentru manipularea listelor si respectiv grafurilor.
Legatura dintre fisierele .c o fac header-urile.

Am implementt o rezolvare cu o lista simplu inlantuita pentru a forma graful si clasamentul.
Lista se parcurge pana ramane un singur jucator, "head"-ul listei.
Pana atunci, lista se itereaza si pierzatorul este eliminat din lista, astfel si realizeaza acest turneu eliminatoriu pe nivele.
Programul are comentrii pe cod, iar functia main a programului contine in mare parte apeluri catre functii exterioare.
Progresul Proiectului poate fi urmarit pe Github, fiind incarcate 2 commit-uri dealungul intocmirii programului.
