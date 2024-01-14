#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Error.h"
#include "Rooms.h"
#pragma warning(disable: 4996)

void validateDate(int day, int month, int year) {
    // Check if month is valid
    if (month < 1 || month > 12) {
         throwError(1);
    }

    // Check if day is valid
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        // Months with 31 days
        if (!(day >= 1 && day <= 31)) {
             throwError(1);
        }
        break;
    case 4: case 6: case 9: case 11:
        // Months with 30 days
        if (!(day >= 1 && day <= 30)) {
             throwError(1);
        }
        break;
    case 2:
        // February
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            // Leap year (29 days in February)
            if (!(day >= 1 && day <= 29)) {
               throwError(1);
            }
        }
        else {
            // Non-leap year (28 days in February)
            if (!(day >= 1 && day <= 28)) {
                throwError(1);
            }
            
        }
        break;
    }
}

//void writeRoomsToFile(Room* head) {
//    FILE* file = fopen("rooms.bin", "wb");
//    if (file == NULL) {
//        fprintf(stderr, "Error opening file for writing\n");
//        return;
//    }
//
//    Room* current = head;
//    while (current != NULL) {
//        fwrite(current, sizeof(Room), 1, file);
//        current = current->next;
//    }
//
//    fclose(file);
//}
