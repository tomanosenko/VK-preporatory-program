
#include <stdio.h>
#include "utils.h"
#include "print.h"

void transaction_write(const char *inf) {
    Person transfer;
    FILE *transaction_ptr = fopen(inf, "r+");
    if (transaction_ptr == NULL) {
        puts("Not acess");
    }
    print_data_transact_fields();
    while (scanf("%d %lf", &transfer.number, &transfer.cash_payments) != -1) {
        fprintf(transaction_ptr, "%-3d%-6.2f\n",
        transfer.number,
        transfer.cash_payments);
        print_data_transact_fields();
    }
    if (EOF) {
        fclose(transaction_ptr);
    }
}

