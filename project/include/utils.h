#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_

#include <unistd.h>
#include <stdio.h>

#define origin "record.dat"
#define filename "transaction.dat"
#define b_record "blackrecord.dat"

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

#endif  //  PROJECT_INCLUDE_UTILS_H_"
