
#include <stdio.h>
#include "utils.h"
#include "file_openers.h"
#include "print.h"

void transaction_write(const char *inf) {
    Person transfer;
    FILE *transaction_ptr = file_opener_read_plus(inf);
    print_data_transact_fields();
    while (scanf("%d %lf", &transfer.number, &transfer.cash_payments) != -1) {
        fprintf(transaction_ptr, "%-3d%-6.2f\n",
        transfer.number,
        transfer.cash_payments);
        print_data_transact_fields();
    }
    fclose(transaction_ptr);
}

