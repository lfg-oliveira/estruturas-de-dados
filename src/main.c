#include "linkedlist.h"
int main(){
    Node *inicio = NULL;
    insereNoComeco(&inicio, 0);
    insereEm(&inicio, 2, 2);
    insereEm(&inicio, 1, 1);
    for(Node *tmp= inicio; tmp !=  NULL; tmp=tmp->prox){
        printf("%d --->", tmp->valor);
    }
    printf("==\n");
    return 0;
}