
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "file_utils.h"

enum ACTIONS { ENTER_DATA_CLIENT = 1, ENTER_DATA_TRANSACTION, UPDATE_BASE, EXIT = -1 };

int main(void) {
	int choice = 0;	
	void masterWrite(FILE *ofPTR, Data Client);
	void transaction_write(FILE *ofPTR, Data transfer);
	void update_record(FILE  *ofPTR_2, FILE *blackrecord, Data client_data, Data transfer)                    ;
	FILE *Ptr, *Ptr_2, *Ptr_3;
	Data client_data, transfer;
	printf("%s", "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n");
		while (scanf("%d", &choice) != EXIT) {
			switch(choice) {
				case ENTER_DATA_CLIENT:
					Ptr = fopen(origin, "r+"); 
					if(Ptr == NULL) {
						puts("Not acess");	
					} else {
						masterWrite(Ptr, client_data);	
						fclose(Ptr);
					}
					break;
				case ENTER_DATA_TRANSACTION:
					Ptr = fopen(origin, "r+");
						if(Ptr == NULL) {
							puts("Not acess");	
						} else {
							transactionWrite(Ptr, transfer);
							fclose(Ptr);
						}
					break;	
				case UPDATE_BASE:
					//Ptr = fopen(origin, "r");
					Ptr_2 = fopen(filename, "r");
					Ptr_3 = fopen(b_record, "w");	
					if(	Ptr == NULL || Ptr_2 == NULL || Ptr_3 == NULL) {
						puts("exit");
					} else {
						update_record(Ptr_2 , Ptr_3, client_data, transfer);
						free(Ptr);
						fclose(Ptr);
						fclose(Ptr_2);	
						fclose(Ptr_3);
					}
					break;
					default:
						puts("error");
					break;
				}
		printf("%s", "please enter action\n1 enter data client:\n2 enter data transaction:\n3 update base\n" );
	}
    return 0;	
}
