
#include "utils.h"
#include "scans.h"
#include "print.h"
#include "stdlib.h"

void update_transaction_data(const char *inf, const char *filename, const char *data) {
    Person transfer;
    FILE *record_ptr = fopen(inf, "r");
    if (record_ptr == NULL) {
        puts("Not acess");
    }
    FILE *transact_ptr = fopen(filename, "r");
    if (transact_ptr == NULL) {
        puts("Not acess");
    }
    FILE *transact_record_ptr = fopen(data, "a+");
    if (transact_record_ptr == NULL) {
        puts("Not acess");
    }
    Person *client_data = malloc(sizeof(Person));
    if (!client_data) {
        free(client_data);
        puts("Not acess");
    } else {
        while (get_data_file(record_ptr, client_data) > 0) {
            while (fscanf(transact_ptr, "%d %lf", &transfer.number, &transfer.cash_payments) != -1) {
                if ((client_data->number == transfer.number) && (transfer.cash_payments != 0)) {
                    client_data->credit_limit += transfer.cash_payments;
               }
           }
        fprintf_update_transaction(transact_record_ptr, *client_data);
        rewind(transact_ptr);
        }
    free(client_data);
    }
         if (EOF) {
             fclose(record_ptr);
             fclose(transact_ptr);
             fclose(transact_record_ptr);
         }
}
