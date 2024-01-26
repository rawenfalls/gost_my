#include <stdio.h>
#include <gmp.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 70 // Замените это значением, соответствующим максимальной длине вашего массива

typedef struct {
    uint32_t data[MAX_LENGTH];
    int dataLength;
} BigInteger;

void genRandomBits(BigInteger* number, int bits);

int main() {
    srand(time(NULL)); // Инициализация генератора случайных чисел

    BigInteger number;
    genRandomBits(&number, 256); // Пример генерации случайных битов (256 бит)

    // Ваш код для работы с сгенерированным числом

    return 0;
}

void genRandomBits(BigInteger* number, int bits) {
    int dwords = bits >> 5;
    int remBits = bits & 0x1F;

    if (remBits != 0)
        dwords++;

    if (dwords > MAX_LENGTH)
        exit(EXIT_FAILURE);

    for (int i = 0; i < dwords; i++)
        number->data[i] = (uint32_t)(rand() * 0x100000000);

    for (int i = dwords; i < MAX_LENGTH; i++)
        number->data[i] = 0;

    if (remBits != 0) {
        uint32_t mask = (uint32_t)(0x01U << (remBits - 1));
        number->data[dwords - 1] |= mask;

        mask = (uint32_t)(0xFFFFFFFFU >> (32 - remBits));
        number->data[dwords - 1] &= mask;
    } else
        number->data[dwords - 1] |= 0x80000000U;

    number->dataLength = dwords;

    if (number->dataLength == 0)
        number->dataLength = 1;
}


unsigned char* fromHexStringToByte(const char* input) {
    size_t inputLength = strlen(input);
    size_t dataLength = inputLength / 2;

    // Выделение памяти под массив байт
    unsigned char* data = (unsigned char*)malloc(strlen(input) / 2);

    if (data == NULL) {
        // Обработка ошибки выделения памяти
        fprintf(stderr, "Не удалось выделить память.\n");
        exit(EXIT_FAILURE);
    }
        
    char hexByte[3];  // Два символа на байт и один символ на завершающий нуль

    for (size_t i = 0; i < dataLength; i++) {
        // Копирование двух символов из строки в hexByte
        strncpy(hexByte, input + i * 2, 2);
        hexByte[2] = '\0';  // Добавление завершающего нуля

        // Преобразование строки в число и сохранение в массиве байт
        data[i] = (unsigned char)strtol(hexByte, NULL, 16);
    }

    return data;
}

mpz_t genPrivateKey(int BitSize)
{
    mpz_t num;
    mpz_init(num);
    do
    {
        num = ();
        genRandomBits(BitSize, new Random());
    } while ((num < 0) || (num > n));
    return num;
}

int main()
{
    mpz_t p, a, b , XG, n, d;

    mpz_init(p);
    mpz_init(a);
    mpz_init(b);
    mpz_init(XG);
    mpz_init(n);
    mpz_init(d);

    mpz_set_str(p,"6277101735386680763835789423207666416083908700390324961279",10);
    mpz_set_str(a,"-3",10);
    mpz_set_str(b,"64210519e59c80e70fa7e9ab72243049feb8deecc146b9b1",16);
    //mpz_set_str(XG,"",10);
    mpz_set_str(n,"ffffffffffffffffffffffff99def836146bc9b1b4d22831",16);
    unsigned char* XG = fromHexStringToByte("03188da80eb03090f67cbf20eb43a18800f4ff0afd82ff1012");


}