#include <stdio.h>
#include "file_utils.h"

void update_record(FILE *ofPTR_1, FILE  *ofPTR_2, FILE *updatedrecord) {
    Data client_data, transfer;
    while (
        fscanf( ofPTR_1, "%d%10s%10s%10s%10s%lf%lf%lf",
                &client_data.number,
                client_data.name,
                client_data.surname,
                client_data.addres,
                client_data.tel_number,
                &client_data.indebtedness,
                &client_data.credit_limit,
                &client_data.cash_payments) != -1 ) {
            while (fscanf(ofPTR_2 , "%d %lf",  &transfer.number , &transfer.cash_payments) !=  -1 ) {
                if ((client_data.number == transfer.number) && (transfer.cash_payments) != 0) {
                    client_data.credit_limit += transfer.cash_payments;
                }
            }
            fprintf(updatedrecord , "%-12d%-11s%-11s%-16s%20s%12.2f%12.2f%12.2f\n",
                    client_data.number,
                    client_data.name,
                    client_data.surname,
                    client_data.addres,
                    client_data.tel_number,
                    client_data.indebtedness,
                    client_data.credit_limit,
                    client_data.cash_payments);
            rewind(ofPTR_2);
            rewind(updatedrecord);
    }
}
