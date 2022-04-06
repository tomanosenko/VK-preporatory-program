
#include "utils.h"

void transaction_write(FILE *of_p_inf) {
    Data transfer;
    printf("%s\n%s\n",
        "1 Number account: ",
         "2 Client cash payments: ");
    while (scanf("%d %lf", &transfer.number, &transfer.cash_payments)!= -1) {
        fprintf(of_p_inf, "%-3d%-6.2f\n", transfer.number, transfer.cash_payments);
        printf("%s\n%s\n",
        "1 Number account:",
        "2 Client cash payments: ");
    }
}

