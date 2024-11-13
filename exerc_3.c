#include <stdio.h>
#include <stdbool.h>
#define MAX 10 

typedef int Object;

typedef struct {
    Object data[MAX];
    int topoA;
    int topoB;
} PilhasCompartilhadas;


void criaPilha(PilhasCompartilhadas *p) {
    p->topoA = -1; 
    p->topoB = MAX;
}


bool vaziaA(PilhasCompartilhadas *p) {
    return p->topoA == -1;
}

bool vaziaB(PilhasCompartilhadas *p) {
    return p->topoB == MAX;
}

bool cheiaA(PilhasCompartilhadas *p) {
    return p->topoA + 1 == p->topoB;
}


bool cheiaB(PilhasCompartilhadas *p) {
    return p->topoB - 1 == p->topoA;
}

void empilhaA(PilhasCompartilhadas *p, Object obj) {
    if (cheiaA(p)) {
        printf("Erro: Pilha A cheia.\n");
        return;
    }
    p->data[++(p->topoA)] = obj;
}

void empilhaB(PilhasCompartilhadas *p, Object obj) {
    if (cheiaB(p)) {
        printf("Erro: Pilha B cheia.\n");
        return;
    }
    p->data[--(p->topoB)] = obj;
}

Object desempilhaA(PilhasCompartilhadas *p) {
    if (vaziaA(p)) {
        printf("Erro: Pilha A vazia.\n");
        return -1;
    }
    return p->data[(p->topoA)--];
}

Object desempilhaB(PilhasCompartilhadas *p) {
    if (vaziaB(p)) {
        printf("Erro: Pilha B vazia.\n");
        return -1;
    }
    return p->data[(p->topoB)++];
}

Object topoA(PilhasCompartilhadas *p) {
    if (vaziaA(p)) {
        printf("Erro: Pilha A vazia.\n");
        return -1;
    }
    return p->data[p->topoA];
}

Object topoB(PilhasCompartilhadas *p) {
    if (vaziaB(p)) {
        printf("Erro: Pilha B vazia.\n");
        return -1;
    }
    return p->data[p->topoB];
}

void mostrarPilhaA(PilhasCompartilhadas *p) {
    if (vaziaA(p)) {
        printf("Pilha A está vazia.\n");
        return;
    }
    printf("Pilha A: ");
    for (int i = 0; i <= p->topoA; i++) {
        printf("%d ", p->data[i]);
    }
    printf("\n");
}

void mostrarPilhaB(PilhasCompartilhadas *p) {
    if (vaziaB(p)) {
        printf("Pilha B está vazia.\n");
        return;
    }
    printf("Pilha B: ");
    for (int i = MAX - 1; i >= p->topoB; i--) {
        printf("%d ", p->data[i]);
    }
    printf("\n");
}

int tamanhoA(PilhasCompartilhadas *p) {
    return p->topoA + 1;
}

int tamanhoB(PilhasCompartilhadas *p) {
    return MAX - p->topoB;
}

int main() {
    PilhasCompartilhadas pilhas;
    criaPilha(&pilhas);

    empilhaA(&pilhas, 1);
    empilhaA(&pilhas, 2);
    empilhaB(&pilhas, 3);
    empilhaB(&pilhas, 4);

    mostrarPilhaA(&pilhas);
    mostrarPilhaB(&pilhas);

    printf("Topo da pilha A: %d\n", topoA(&pilhas));
    printf("Topo da pilha B: %d\n", topoB(&pilhas));

    printf("Desempilhando da pilha A: %d\n", desempilhaA(&pilhas));
    printf("Desempilhando da pilha B: %d\n", desempilhaB(&pilhas));

    mostrarPilhaA(&pilhas);
    mostrarPilhaB(&pilhas);

    printf("Tamanho da pilha A: %d\n", tamanhoA(&pilhas));
    printf("Tamanho da pilha B: %d\n", tamanhoB(&pilhas));

    return 0;
}
