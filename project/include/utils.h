#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_
#include <unistd.h>

#include <stdio.h>

struct masterRecord {
    int number;
    char name[20];
    char surname[20];
    char addres[30];
    char tel_number[15];
    double indebtedness;
    double credit_limit;
    double cash_payments;};

typedef struct masterRecord Data;

#define origin "record.dat"
#define filename "transaction.dat"
#define b_record "blackrecord.dat"

#endif  //  PROJECT_INCLUDE_UTILS_H_"
