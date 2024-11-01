#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LENGTH 4
#define MAX_LENGTH 20

char gerarCaractereAleatorio() {
    int tipo = rand() % 3;
    if (tipo == 0) {
        return 'A' + (rand() % 26);  
    } else if (tipo == 1) {
        return 'a' + (rand() % 26); 
    } else {
        return '0' + (rand() % 10); 
    }
}

void gerarSenha(int comprimento, char* senha) {
    for (int i = 0; i < comprimento; i++) {
        senha[i] = gerarCaractereAleatorio();
    }
    senha[comprimento] = '\0';
}

int main() {
    int comprimento;
    char senha[MAX_LENGTH + 1];

    srand(time(NULL));

    printf("Digite o comprimento da senha (entre %d e %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &comprimento);

    if (comprimento < MIN_LENGTH || comprimento > MAX_LENGTH) {
        printf("Comprimento inválido. Por favor, tente novamente.\n");
        return 1;
    }

    gerarSenha(comprimento, senha);
    printf("Senha gerada: %s\n", senha);

    return 0;
}