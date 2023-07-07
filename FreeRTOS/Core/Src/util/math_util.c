#include "math_util.h"

int randomInt(int min, int max) {
    // Gerar um número inteiro aleatório entre 0 e RAND_MAX
    int randomInt = (int) (rand() % 256);

    return randomInt;
}