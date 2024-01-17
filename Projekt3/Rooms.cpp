#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Helpers.h"
#include "Error.h"
#include "Status.h"
#include "Rooms.h"
#pragma warning(disable: 4996)


Room* initializeRoomList() {
    return NULL;
}


Room* addRoomToBeginning(Room* head, int day, int month, int year, int roomNumber, const char* cleanerName, const char* hotelName) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    if (newRoom == NULL) {
         throwError(3);
    }

    newRoom->day = day;
    newRoom->month = month;
    newRoom->year = year;
    newRoom->roomNumber = roomNumber;
    newRoom->cleaningStatus = DIRTY;
    strcpy(newRoom->cleanerName, cleanerName);
    strcpy(newRoom->hotelName, hotelName);
    newRoom->next = head;

    return newRoom;
}


Room* addRoomToEnd(Room* head, int day, int month, int year, int roomNumber, const char* cleanerName, const char* hotelName) {
    Room* newRoom= (Room*)malloc(sizeof(Room));
    if (newRoom == NULL) {
         throwError(3);
    }
    newRoom->day = day;
    newRoom->month = month;
    newRoom->year = year;
    newRoom->roomNumber = roomNumber;
    newRoom->cleaningStatus = DIRTY;
    strcpy(newRoom->cleanerName, cleanerName);
    strcpy(newRoom->hotelName, hotelName);
    newRoom->next = NULL;

    if (head == NULL) {
        return newRoom;
    }

    Room* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newRoom;

    return head;
}

Room* removeFromBeginning(Room* head) {
    if (head == NULL) {
        printf("List is empty. There is nothing to remove. \n");
        return NULL;
    }

    Room* newHead = head->next;
    free(head);

    return newHead;
}


Room* removeFromEnd(Room* head) {
    if (head == NULL) {
        printf("List is empty. There is nothing to remove. \n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    Room* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;

    return head;
}

Room* cleanRoom(Room* head, int roomNumber, const char* hotelName) {
    Room* current = head;

    int is_found = 0;
    while (current != NULL) {
        if (current->roomNumber == roomNumber && strcmp(current->hotelName, hotelName) == 0) {
            // Found the room in the specified hotel, update cleaning status
            current->cleaningStatus = CLEANED;
            printf("Room %d in %s has been cleaned.\n", roomNumber, hotelName);
            is_found = 1;
            break;
        }
        current = current->next;
    }
    if (!is_found) {
        printf("Room %d in %s not found.\n", roomNumber, hotelName);
    }

    return head;
}

int countElements(Room* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}   

void displayRoomList(Room* head) {
    printf("Room List:\n");
    while (head != NULL) {
        if (head->cleaningStatus == DIRTY) {
            printf("Date: %d-%02d-%02d, Room Number: %d, Status: dirty, Cleaner: %s, Hotel: %s \n",
                head->year, head->month, head->day, head->roomNumber, head->cleanerName, head->hotelName);
        }
        else {
            printf("Date: %d-%02d-%02d, Room Number: %d, Status: cleaned, Cleaner: %s, Hotel: %s \n",
                head->year, head->month, head->day, head->roomNumber, head->cleanerName, head->hotelName);
        }
        head = head->next;
    }
}

 void writeRoomsToFile(Room* head) {
    FILE* file = fopen("rooms.txt", "w");
    if (file == NULL) {
        throwError(2);
    }

    Room* current = head;
    while (current != NULL) {
        if (head->cleaningStatus == DIRTY) {
            fprintf(file, "%d %d %d %d %s %s %s\n",
                current->day, current->month, current->year,
                current->roomNumber, cleaningStatusToString(current->cleaningStatus),
                current->cleanerName, current->hotelName);
        }
        else {
            fprintf(file, "%d %d %d %d %s %s %s\n",
                current->day, current->month, current->year,
                current->roomNumber, cleaningStatusToString(current->cleaningStatus),
                current->cleanerName, current->hotelName);
        }
        current = current->next;
    }

    fclose(file);
}

 Room* readRoomsFromFile() {
     FILE* file = fopen("rooms.txt", "r");
     if (file == NULL) {
         throwError(2);
     }

     Room* head = NULL;
     Room* current = NULL;

     while (1) {
         Room* newRoom = (Room*)malloc(sizeof(Room));
         if (newRoom == NULL) {
             fclose(file);
             throwError(3);
         }

         char tmpCleaningStatus[8];


         int result = fscanf(file, "%d %d %d %d %s %49s %19s", 
             &newRoom->day, &newRoom->month, &newRoom->year,
             &newRoom->roomNumber, &tmpCleaningStatus,
             newRoom->cleanerName, newRoom->hotelName);

         newRoom->cleaningStatus= stringToCleaningStatus(tmpCleaningStatus);

         if (result != 7) {
             free(newRoom);
             break;  // END OF FILE
         }

         newRoom->next = NULL;         

         if (head == NULL) {
             head = newRoom;
             current = head;
         }
         else {
             current->next = newRoom;
             current = newRoom;
         }
     }

     fclose(file);
     return head;
 }

void freeRoomList(Room* head) {
    while (head != NULL) {
        Room* temp = head;
        head = head->next;
        free(temp);
    }
}
