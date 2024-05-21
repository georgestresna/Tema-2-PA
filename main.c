#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "liste.h"


float calculatorScor(int r){
    int l=6; 
    float q=0.15;
    //formula
    float scor = (q * pow((2-q),r))/(pow(2,l) + (pow((2-q),l)*(q-1)));
    return scor;
}

void readFile(Node**head, FILE *in){
    Team vec;
    char buffer[100];

    for(int i=0; i<32; i++){
        fscanf(in, "%f", &(vec.teamScore));
        fgets(buffer, sizeof(buffer), in);
        buffer[strlen(buffer)-1] = '\0';
        strcpy(vec.name, buffer);
        vec.pos=i + 1;
        addAtEnd(head, vec);
    }
}

void scoreboard(Node**head, Graph**g){
    Node*headCopy=*head;
    Node*copy2=*head;

    while((*head)->next){          //cat timp nu este o singura echipa ramasa in lista, itereaza
        while(headCopy->next){
            //printf("%s vs %s\n",headCopy->echipa.name, headCopy->next->echipa.name);
            if((headCopy->echipa.teamScore > (headCopy->next)->echipa.teamScore) || ((headCopy->echipa.teamScore == (headCopy->next)->echipa.teamScore) && strcmp(headCopy->echipa.name, (headCopy->next)->echipa.name) > 0)) {
                (*g)->a[(headCopy->next)->echipa.pos-1][headCopy->echipa.pos-1]=1;
                Node*aux=headCopy->next;
                headCopy->next=aux->next;
                free(aux);
            }
            else if((headCopy->echipa.teamScore < (headCopy->next)->echipa.teamScore) || ((headCopy->echipa.teamScore == (headCopy->next)->echipa.teamScore) && strcmp(headCopy->echipa.name, (headCopy->next)->echipa.name) < 0)) {
                (*g)->a[headCopy->echipa.pos-1][(headCopy->next)->echipa.pos-1]=1;
                if(headCopy == *head) {
                    *head=headCopy->next; 
                    free(headCopy);
                    headCopy=*head;
                    copy2=*head;
                }
                else{
                    copy2->next=headCopy->next;
                    Node*aux=headCopy;
                    headCopy=headCopy->next;
                    free(aux);
                }
            }
            copy2=headCopy;
            headCopy=headCopy->next;
            if(headCopy == NULL) break;
        }
        //headCopy=head;
        //while(headCopy){printf("%s->", headCopy->echipa.name); headCopy=headCopy->next;}
        headCopy=*head;
        copy2=*head;
        //printf("\n");
    }
}

void listCopy(Node*head, Node**headRank){
    while(head){
        addAtEnd(headRank, head->echipa);
        head=head->next;
    }
}

void listEvaluate(Node**headRank, Graph*g){
    Node*headCopy=*headRank;
    for(int i=0; i<32; i++){
        int count=0;        //nr de victorii
        for(int j=0; j<32; j++){
            if(g->a[j][i] == 1) count++;
        }
        headCopy->echipa.teamScore=count;
        headCopy=headCopy->next;
    }
}

void listOutput(Node*headRank, FILE*scor){
    for(int i=0; i<6; i++){     //caut echipele cu i winuri
        Node*headCopy=headRank;
        float scorCurent=calculatorScor(i);     //scor pt i winuri
        while(headCopy){
            if((int)headCopy->echipa.teamScore == i)    //daca o echipa are i winuri, atunci
                fprintf(scor, "%.4f%s\n", scorCurent, headCopy->echipa.name);
            headCopy=headCopy->next;
        }
    }
}

void freeList(Node* head){
   Node* tmp;
   while (head != NULL){
       tmp = head;
       head = head->next;
       free(tmp);
    }
}

int main(int argc, char *argv[]){

	FILE * in = fopen(argv[1], "r");
	FILE * graf = fopen(argv[2], "w"); /* Se afișează matricea de adicenta. */	
	FILE * scor = fopen(argv[3], "w"); /* Se afișează scorurile. */

    Node *head=NULL;
    readFile(&head, in);     //voi stoca in float scorurile initiale, din fisier
    Node *headRank=NULL; 
    listCopy(head, &headRank);  //copie la lista pt punctul 2

    //pct1
    Graph *g=create();      //creaza graf
    scoreboard(&head, &g);  //populare matrice
    printGraph(g, graf);    //print matrice

    float headScore=calculatorScor(0);  //pana la 5 i, inclusiv

    //pct2, lucrez cu headRank
    listEvaluate(&headRank, g);     //am schimbat float-urile cu pct fin
    listOutput(headRank, scor);
    //while(headRank){printf("%.4f %s\n", headRank->echipa.teamScore, headRank->echipa.name); headRank=headRank->next;}

    //eliberare memorie
    free(head);             //prima lista, ramane doar castigatorul
    freeList(headRank);     //a doua lista, intreaga
    for(int i = 0; i < 32; i++)      //matricea de adiacenta a grafului
        free(g->a[i]);
    free(g->a);
    free(g);                //graful

    fclose(in);
    fclose(graf);
    fclose(scor);
    return 0;
}