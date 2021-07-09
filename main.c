#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>

typedef struct HashTable {
    char *status;
    char *key;
} HashTable;

HashTable *createHashTable() {
    HashTable *newTb = malloc(26*sizeof(HashTable));
    for(int i = 0; i<26; i++)
    {
        newTb[i].status = "never used";
        newTb[i].key = "";
    }
    return newTb;
}

void insert(HashTable *tb, char *key){
    char hash;
    for (int i = 0; i< 10; i++)
    {
        if(key[i+1] == 0){
            hash = key[i];
            break;
        }
    }
    hash-='a';
    while(strcmp(tb[hash].status,"occupied")==0){
        hash++;
    }
    tb[hash].key = key;
    tb[hash].status = "occupied";
 
}

char const *search(HashTable tb[26], char *key){
    char hash;
    for(int i =0; i<10; i++)
    {
        if(key[i+1] == 0){
            hash=key[i];
            break;
        }
    }
    hash -= 'a';
    while(strcmp(tb[hash].key,key) != 0)
    {
        hash++;
    }
    if(strcmp(tb[hash].status,"occupied")==0)
    {
        return tb[hash].key;
    }

    return NULL;
}

void del(HashTable tb[26], char *key)
{
    char hash;
    for(int i =0; i<10; i++)
    {
        if(key[i+1] == 0){
            hash=key[i];
            break;
        }
    }
    hash -='a';
    while(strcmp(tb[hash].key, key) != 0)
    {
        hash++;
    }
    tb[hash].status="tombstone";
}

char **separateInputs(char* buffer, int *inputsSize)
{
    char *start = buffer, *end;
    int count = 1;
    for(char *ch = buffer; *ch != 0;  ch++)
    {
        if(*ch == ' '){
            count++;
            *ch = '\n';
        }
    }
    *inputsSize = count;
    char **inputs = calloc(count, sizeof(char*));
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
    size_t buffsize = 100;
    printf("Example input:\nAapple Aorange Dapple Astrawberry\nExpected output:\n orange strawberry\n");
    scanf("%[^\n]%*c", b);
    int inputSize;
    char **inputs = separateInputs(b, &inputSize);
    processInputs(tb, inputs, inputSize);
    printTb(tb);

    free(inputs);
    free(tb);
    return 0;
}
