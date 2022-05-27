#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

typedef struct HashTable {
    char const *status;
    char const *key;
} HashTable;

int returnHash(HashTable *tb,char *key)
{
    int hash = 0;
    for (int i = 0; i< 10; i++)
    {
        if(key[i+1] == 0){
            hash = key[i];
            break;
        }
    }
    hash -= 'a';
    return hash;
}

HashTable *createHashTable() {
    HashTable *newTb = (HashTable *)malloc(26*sizeof(HashTable));
    for(int i = 0; i<26; i++)
    {
        newTb[i].status = "never used";
        newTb[i].key = "";
    }
    return newTb;
}

int search(HashTable *tb, char *key){
    int hash = returnHash(tb, key);
    if(hash < 0 || hash >= 26)
    {
        return -1;
    }
    while(hash < 26 && strcmp(tb[hash].status,"never used") != 0 )
    {
        if(strcmp(tb[hash].key, key) == 0)
        {
            return hash;
        }
        hash++;
    }
    return -1;

}

void insert(HashTable *tb, char *key){
    int hash=returnHash(tb, key);
    if(hash < 0 || hash >=26 )
    {
        return;
    }
    while (strcmp(tb[hash].status, "occupied") == 0){
        hash ++;
    }
    tb[hash].status = "occupied";
    tb[hash].key = key;
}


void del(HashTable *tb, char *key)
{
    int hash = search(tb, key);
    if(hash < 0 || hash >=26)
    {
        return;
    }
    while(strcmp(tb[hash].status, "never used") && hash < 26)
    {
        if(strcmp(tb[hash].key,key) == 0 && strcmp(tb[hash].status, "tombstone")!=0)
        {
            tb[hash].status="tombstone";
            return;
        }
        hash++;
    }
}

char **separateInputs(char* buffer, int *inputsSize)
{
    int count = 1;
    for(char *ch = buffer; *ch != 0;  ch++)
    {
        if(*ch == ' '){
            count++;
            *ch = '\n';
        }
    }
    *inputsSize = count;
    char **inputs = (char **)calloc(count, sizeof(char*));
    inputs[0] = strtok(buffer, "\n");
    for(int i = 1; i<count; i++)
    {
        inputs[i] = strtok(NULL, "\n");
    }

    return inputs;
}

void runCommand(HashTable *tb, char cmd, char *input)
{
    switch (cmd)
    {
    case 'A':
        insert(tb, input);
        break;
    case 'D':
        del(tb, input);
        break;
    default:
        break;
    }
}

void processInputs(HashTable *tb, char **inputs, int inputSize)
{
    for(int i = 0; i<inputSize ;i++)
    {
        runCommand(tb, inputs[i][0], &inputs[i][1]);
    }
}

void printTb(HashTable *tb)
{
    for(int i = 0; i<26; i++)
    {
        if(strcmp(tb[i].status, "occupied") == 0)
        {
            printf("%s ",tb[i].key);
        }
    }
}


int main(int argc, char** argv)  {
    HashTable *tb = createHashTable();
    char buffer[100];
    char *b = buffer;
    // size_t buffsize = 100;
    printf("Example input:\nAapple Aorange Aapple Dapple Dapple\nExpected output:\norange\n");
    scanf("%[^\n]%*c", b);
    int inputSize;
    char **inputs = separateInputs(b, &inputSize);
    processInputs(tb, inputs, inputSize);
    printTb(tb);

    free(inputs);
    free(tb);
    return 0;
}
