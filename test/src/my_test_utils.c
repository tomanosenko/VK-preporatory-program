
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main_module.h"
#define filename1 "Test_config.dat"

void read_from_file(FILE *File_ptr, Data compare_base);
void write_to_file(FILE *File_ptr, Data writing_data);
int is_equal(double a_compare, double b_compare);
void test_write_to_file() {
Data expected_data = {1, "Toma", "Nosenko", "Addres", "88005553535", 90, 165, 28};
FILE *Test = fopen(filename1, "w+");
if (Test == NULL) {
    puts("Not acess");
    return;
} else {
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
        write_to_file(Test,got_data);
        fclose(Test);
        Test = fopen(filename1, "r+");
        read_from_file(Test, expected_data);
}
fclose(Test);
}
void write_to_file(FILE *File_ptr, Data writing_data) {
    fprintf(File_ptr, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
    writing_data.number,
    writing_data.name,
    writing_data.surname,
    writing_data.addres,
    writing_data.tel_number,
    writing_data.indebtedness,
    writing_data.credit_limit,
    writing_data.cash_payments);
    if (fprintf(File_ptr, "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
    writing_data.number,
    writing_data.name,
    writing_data.surname,
    writing_data.addres,
    writing_data.tel_number,
    writing_data.indebtedness,
    writing_data.credit_limit,
    writing_data.cash_payments) < 0)
    perror("error");
}
void read_from_file(FILE *File_ptr, Data compare_base) {
    Data data;
    fscanf(File_ptr, "%d%20s%20s%30s%15s%lf%lf%lf",
    &data.number,
    data.name,
    data.surname,
    data.addres,
    data.tel_number,
    &data.indebtedness,
    &data.credit_limit,
    &data.cash_payments);
    if (fscanf(File_ptr, "%d%20s%20s%30s%15s%lf%lf%lf",
        &data.number,
        data.name,
        data.surname,
        data.addres,
        data.tel_number,
        &data.indebtedness,
        &data.credit_limit,
        &data.cash_payments) == -1) {
        perror("error");
        return;
    }
    if (
    ((data.number != compare_base.number) +
    strncmp(data.name, compare_base.name, 20) +  
    strncmp(data.surname, compare_base.surname, 20) +
    strncmp(data.addres, compare_base.addres, 30) +
    is_equal(data.indebtedness, compare_base.indebtedness) +
    is_equal(data.credit_limit, compare_base.credit_limit) +
    is_equal(data.cash_payments, compare_base.cash_payments)) == 0) {
    printf("%s", "Succeed\n");
    return;
    }
printf("%s", "Error\n");
