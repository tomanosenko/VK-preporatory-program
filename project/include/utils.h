#ifndef GITHUB_GIT_TEST_HW_PROJECT_INCLUDE_FILE_UTILS_H_
#define GITHUB_GIT_TEST_HW_PROJECT_INCLUDE_FILE_UTILS_H_
#include <unistd.h>
#include <stdio.h>

#define p_information "record.dat"
#define transaction "transaction.dat"
#define n_transaction "blackrecord.dat"

#define SIZE_NAME 20
#define SIZE_SURNAME 20
#define SIZE_ADDRES 30
#define SIZE_TEL_NUMBER 15

struct masterRecord {
    int number;
    char name[SIZE_NAME];
    char surname[SIZE_SURNAME];
    char addres[SIZE_ADDRES];
    char tel_number[SIZE_TEL_NUMBER];
    double indebtedness;
    double credit_limit;
    double cash_payments;};

typedef struct masterRecord Data;

#endif  //  GITHUB_GIT_TEST_HW_PROJECT_INCLUDE_FILE_UTILS_H_
