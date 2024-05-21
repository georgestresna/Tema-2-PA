#include "grafuri.h"

struct Node{
    Team echipa;
    struct Node *next;
};
typedef struct Node Node;

void addAtBeginning(Node **head, Team v);
void addAtEnd(Node** head, Team v);