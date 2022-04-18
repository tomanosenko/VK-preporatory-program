
#include "scans.h"
#include "data_struct.h"

int get_data_record(Person *data) {
    return(scanf("%d%20s%20s%30s%15s%lf%lf%lf",
    &data->number,
    data->name,
    data->surname,
    data->addres,
    data->tel_number,
    &data->indebtedness,
    &data->credit_limit,
    &data->cash_payments));
}


int get_data_file(FILE *filename, Person *data) {
    return(fscanf(filename, "%d%20s%20s%30s%15s%lf%lf%lf",
    &data->number,
    data->name,
    data->surname,
    data->addres,
    data->tel_number,
    &data->indebtedness,
    &data->credit_limit,
    &data->cash_payments));
}

