#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "main_module.h"

#define filename1 "Test_config.dat"
#define filename2  "Test_config.dat.gold"

void test_write_to_file() {
    Data expected_data = {1, "Toma", "Nos", "Addres", "88005553535", 90, 165, 28};
    FILE *Test = fopen(filename1, "w+");
    FILE *Gold = fopen(filename2, "w+");
    if ((Test == NULL) || (Gold == NULL)) {
        puts("Not access");
    } else {
        write_to_file(Gold, expected_data);
        Data got_data;
        scanf("%d%20s%20s%30s%15s%lf%lf%lf",
        &got_data.number,
        got_data.name,
        got_data.surname,
        got_data.addres,
        got_data.tel_number,
        &got_data.indebtedness,
        &got_data.credit_limit,
        &got_data.cash_payments);
        write_to_file(Test, got_data);
        fclose(Gold);
        read_from_file(Test, expected_data);
        fclose(Test);
    }
}

void write_to_file(FILE *Ptr, Data writing_data) {
    fprintf(Ptr, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
    writing_data.number,
    writing_data.name,
    writing_data.surname,
    writing_data.addres,
    writing_data.tel_number,
    writing_data.indebtedness,
    writing_data.credit_limit,
    writing_data.cash_payments);
}

void read_from_file(FILE *Ptr, Data compare_base) {
    Data data;
    fscanf(Ptr, "%d%20s%20s%30s%15s%lf%lf%lf",
    &data.number,
    data.name,
    data.surname,
    data.addres,
    data.tel_number,
    &data.indebtedness,
    &data.credit_limit,
    &data.cash_payments);
    if (((data.number == compare_base.number) &&
        (data.name == compare_base.name) &&
        (data.surname == compare_base.surname) &&
        (data.addres == compare_base.addres) &&
        (data.indebtedness == compare_base.indebtedness) &&
        (data.credit_limit == compare_base.credit_limit) &&
        (data.cash_payments == compare_base.cash_payments)) != 0) {
        printf("%s", "Succeed\n");
    }
    printf("%s", "Error\n");
}

