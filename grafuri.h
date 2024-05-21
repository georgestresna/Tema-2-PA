typedef struct Team{
    int pos;
    char name[100];
    float teamScore;
}Team;

typedef struct{
    int V;
    int E;
    int **a; 
}Graph;

Graph *create();
void printGraph(Graph *g, FILE*graf);