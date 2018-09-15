/* André de Souza Ferreira

Código-Resposta do desafio */

# include <stdio.h>
# include <stdlib.h>

typedef struct No {
    int info;
    struct No *esquerda;
    struct No *direita;
    struct No *raiz;
    }node;

node *criarArvore(int num) {

    node *root;
    root = malloc(sizeof(node));
    root -> direita = NULL;
    root -> esquerda = NULL;
    root -> info = num;
    
    return(root);

}

node *inserirArvore(int num, node *arvore) {
    if (arvore == NULL)
        return(criarArvore(num));
    if (num < arvore -> info) {
        arvore -> esquerda = inserirArvore(num, arvore -> esquerda);
        arvore -> esquerda -> raiz = arvore;
    } else if (num > arvore -> info) {
        arvore -> direita = inserirArvore(num, arvore -> direita);
        arvore -> direita -> raiz = arvore;
    }

    return(arvore);
}

void EmOrdem(node *x) {
    if (x != NULL) {
        EmOrdem(x -> esquerda);
        printf(" %d", x -> info);
        EmOrdem(x -> direita);
    }
}

void PreOrdem(node *x) {
    if (x != NULL) {
        printf(" %d", x -> info);
        PreOrdem(x -> esquerda);
        PreOrdem(x -> direita);
    }
}

void PosOrdem(node *x) {
    if (x != NULL) {
        PosOrdem(x -> esquerda);
        PosOrdem(x -> direita);
        printf(" %d", x -> info);
    }
}


int main() {

    // Lendo os casos de teste //
    int C, i, N, j, num;
    scanf("%d", &C);

    node *raiz = NULL;

    for (i = 1; i <= C; i++) {

        // Lendo a quantidade de números para montar a árvore //
        scanf("%d", &N);

        node *temp = raiz;
        raiz = NULL;
        free(temp);

        // Digitando os números //
                
        for (j = 1; j <= N; j++) {
            scanf("%d", &num);
            raiz = inserirArvore(num, raiz);
        }

        // Imprimindo os Números //
        printf("Case %d:\n", i);
        printf("Pre.:");
        PreOrdem(raiz);
        printf("\n");
        printf("In..:");
        EmOrdem(raiz);
        printf("\n");
        printf("Post:");
        PosOrdem(raiz);
        printf("\n\n");
           
    }

    return 0;
}