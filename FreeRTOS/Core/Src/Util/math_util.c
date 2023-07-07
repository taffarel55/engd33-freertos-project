#include "math_util.h"

int randomInt(int min, int max) {
    // Gerar um número inteiro aleatório dentro do intervalo (min, max)
    int randomInt = min + rand() % (max - min + 1);

    return randomInt;
}
