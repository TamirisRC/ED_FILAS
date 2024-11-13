#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct Node {
    char name[50];
    struct Node *prev;
    struct Node *next;
} Node;

Node* createNode(const char* name) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node* indexList[ALPHABET_SIZE] = { NULL };

int getIndex(const char* name) {
    char firstLetter = name[0];
    if (firstLetter >= 'A' && firstLetter <= 'Z') {
        return firstLetter - 'A';
    } else if (firstLetter >= 'a' && firstLetter <= 'z') {
        return firstLetter - 'a';
    }
    return -1; 
}

void addName(const char* name) {
    int index = getIndex(name);
    if (index == -1) return; 
    
    Node *newNode = createNode(name);
    if (indexList[index] == NULL) {
        indexList[index] = newNode;
        return;
    }
    
    Node *current = indexList[index];
    Node *prev = NULL;
    
    while (current != NULL && strcmp(current->name, name) < 0) {
        prev = current;
        current = current->next;
    }
    
    if (prev == NULL) {
        newNode->next = indexList[index];
        indexList[index]->prev = newNode;
        indexList[index] = newNode;
    } else {
        newNode->next = current;
        newNode->prev = prev;
        prev->next = newNode;
        if (current != NULL) {
            current->prev = newNode;
        }
    }
}

int searchName(const char* name) {
    int index = getIndex(name);
    if (index == -1) return 0;
    
    Node *current = indexList[index];
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) return 1;
        current = current->next;
    }
    return 0;
}

void removeName(const char* name) {
    int index = getIndex(name);
    if (index == -1) return;
    
    Node *current = indexList[index];
    
    while (current != NULL && strcmp(current->name, name) != 0) {
        current = current->next;
    }
    
    if (current == NULL) return;
    
    if (current->prev != NULL) current->prev->next = current->next;
    else indexList[index] = current->next;
    
    if (current->next != NULL) current->next->prev = current->prev;
    
    free(current);
}

int isEmpty() {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (indexList[i] != NULL) return 0;
    }
    return 1;
}

int countNames() {
    int count = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        Node *current = indexList[i];
        while (current != NULL) {
            count++;
            current = current->next;
        }
    }
    return count;
}

void printNames() {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        Node *current = indexList[i];
        if (current != NULL) {
            printf("Letra %c:\n", 'A' + i);
            while (current != NULL) {
                printf("  %s\n", current->name);
                current = current->next;
            }
        }
    }
}

int main() {
    addName("Amanda");
    addName("Ana");
    addName("Aline");
    addName("Carlos");
    addName("Bia");
    addName("Cosmos");

    printf("Nomes na estrutura:\n");
    printNames();
    
    printf("\nNúmero total de nomes: %d\n", countNames());
    printf("\nEstrutura está vazia? %s\n", isEmpty() ? "Sim" : "Não");
    
    printf("\nBuscando o nome 'Ana': %s\n", searchName("Ana") ? "Encontrado" : "Não encontrado");
    printf("Buscando o nome 'Zuleika': %s\n", searchName("Zuleika") ? "Encontrado" : "Não encontrado");
    
    removeName("Ana");
    printf("\nNomes na estrutura após remover 'Ana':\n");
    printNames();
    
    return 0;
}
