#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MIN_LENGTH 4
#define MAX_LENGTH 20

char gerarCaractereAleatorio(int tipo) {
    if (tipo == 0) {
        return 'A' + (rand() % 26);  // Letra maiúscula
    } else if (tipo == 1) {
        return 'a' + (rand() % 26);  // Letra minúscula
    } else {
        return '0' + (rand() % 10);   // Dígito
    }
}

void gerarSenha(int comprimento, char* senha) {
    int i;
    int hasUpper = 0, hasLower = 0, hasDigit = 0;

    for (i = 0; i < comprimento; i++) {
        int tipo = rand() % 3;
        senha[i] = gerarCaractereAleatorio(tipo);
        
        // Marcar se pelo menos um de cada tipo foi gerado
        if (isupper(senha[i])) hasUpper = 1;
        if (islower(senha[i])) hasLower = 1;
        if (isdigit(senha[i])) hasDigit = 1;
    }

    // Garantir que a senha contém pelo menos um de cada tipo
    if (!hasUpper) senha[0] = gerarCaractereAleatorio(0);
    if (!hasLower) senha[1] = gerarCaractereAleatorio(1);
    if (!hasDigit) senha[2] = gerarCaractereAleatorio(2);

    senha[comprimento] = '\0'; // Finalizar string
}

int main() {
    int comprimento;
    char senha[MAX_LENGTH + 1];

    srand(time(NULL));

    printf("Digite o comprimento da senha (entre %d e %d): ", MIN_LENGTH, MAX_LENGTH);
    if (scanf("%d", &comprimento) != 1 || comprimento < MIN_LENGTH || comprimento > MAX_LENGTH) {
        printf("Comprimento inválido. Por favor, tente novamente.\n");
        return 1;
    }

    gerarSenha(comprimento, senha);
    printf("Senha gerada: %s\n", senha);

    return 0;
}