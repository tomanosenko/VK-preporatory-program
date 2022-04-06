
#ifndef PROJECT_INCLUDE_DATA_STRUCT_H_
#define PROJECT_INCLUDE_DATA_STRUCT_H_

#define SIZE_NAME 20
#define SIZE_SURNAME 20
#define SIZE_ADDRES 30
#define SIZE_TEL_NUMBER 15

typedef struct masterRecord {
    int number;
    char name[SIZE_NAME];
    char surname[SIZE_SURNAME];
    char addres[SIZE_ADDRES];
    char tel_number[SIZE_TEL_NUMBER];
    double indebtedness;
    double credit_limit;
    double cash_payments;
    } Data;

#endif  // PROJECT_INCLUDE_DATA_STRUCT_H_
