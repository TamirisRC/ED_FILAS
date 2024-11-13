#include <stdio.h>
#include <stdbool.h>
#define MAX 5 

typedef int Object; 

typedef struct {
    Object items[MAX];
    int frente;
    int final;
    int tamanho;
} Fila;

void criaFila(Fila *f) {
    f->frente = MAX - 1;
    f->final = MAX - 1;
    f->tamanho = 0;
}

bool estaVazia(Fila *f) {
    return f->tamanho == 0;
}

bool estaCheia(Fila *f) {
    return f->tamanho == MAX;
}

void enfileira(Fila *f, Object obj) {
    if (estaCheia(f)) {
        printf("Erro: Fila cheia.\n");
        return;
    }
    f->final = (f->final + 1) % MAX;
    f->items[f->final] = obj;
    f->tamanho++;
}

Object desenfileira(Fila *f) {
    if (estaVazia(f)) {
        printf("Erro: Fila vazia.\n");
        return -1;
    }
    f->frente = (f->frente + 1) % MAX;
    Object obj = f->items[f->frente];
    f->tamanho--;
    return obj;
}

Object cabeca(Fila *f) {
    if (estaVazia(f)) {
        printf("Erro: Fila vazia.\n");
        return -1;
    }
    return f->items[(f->frente + 1) % MAX];
}

Object cauda(Fila *f) {
    if (estaVazia(f)) {
        printf("Erro: Fila vazia.\n");
        return -1;
    }
    return f->items[f->final];
}

void mostraFila(Fila *f) {
    if (estaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    int i = (f->frente + 1) % MAX;
    printf("Fila: ");
    for (int count = 0; count < f->tamanho; count++) {
        printf("%d ", f->items[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

bool pesquisa(Fila *f, Object obj) {
    if (estaVazia(f)) return false;
    
    int i = (f->frente + 1) % MAX;
    for (int count = 0; count < f->tamanho; count++) {
        if (f->items[i] == obj) return true;
        i = (i + 1) % MAX;
    }
    return false;
}

int tamanho(Fila *f) {
    return f->tamanho;
}

int main() {
    Fila f;
    criaFila(&f);

    enfileira(&f, 10);
    enfileira(&f, 20);
    enfileira(&f, 30);
    mostraFila(&f);
    
    printf("Desenfileirando: %d\n", desenfileira(&f));
    mostraFila(&f);
    
    printf("Cabeça da fila: %d\n", cabeca(&f));
    printf("Cauda da fila: %d\n", cauda(&f));
    
    enfileira(&f, 40);
    enfileira(&f, 50);
    enfileira(&f, 60); 
    mostraFila(&f);
    
    printf("Pesquisando o elemento 30: %s\n", pesquisa(&f, 30) ? "Encontrado" : "Não encontrado");
    printf("Tamanho da fila: %d\n", tamanho(&f));
    
    return 0;
}
