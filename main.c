#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "liste.h"


float calculatorScor(int r){
    int l=5; 
    float q=0.15;

    //formula
    float scor = (q * pow((2-q),r))/(pow(2,l) + pow((2-q),l)*(q-1));
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

int main(int argc, char *argv[]){

	FILE * in = fopen(argv[1], "r");
	FILE * graf = fopen(argv[2], "w"); /* Se afișează matricea de adicenta. */	
	FILE * scor = fopen(argv[3], "w"); /* Se afișează scorurile. */

    Node *head=NULL;
    readFile(&head, in);     //voi stoca in float scorurile initiale, din fisier

    //ptc1
    Graph *g=create();      //creaza graf
    scoreboard(&head, &g);  //populate mtrice
    printGraph(g, graf);    //print matrice

    fclose(in);
    fclose(graf);
    fclose(scor);
    return 0;
}