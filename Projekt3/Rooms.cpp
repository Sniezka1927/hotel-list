#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Helpers.h"
#pragma warning(disable: 4996)

typedef struct Room {
    int day;
    int month;
    int year;
    int room_number;
    char cleaning_status[20];  // Status ("clean", "dirty")
    char cleaner_name[50];
    char hotel_name[20];
    struct Room* next;
} Room;


Room* initializeRoomList() {
    return NULL;
}


Room* addRoomToBeginning(Room* head, int day, int month, int year, int room_number, const char* cleaning_status, const char* cleaner_name, const char* hotel_name) {
    Room* newRoom = (Room*)malloc(sizeof(Room));
    if (newRoom == NULL) {
        // should be 3
         throwError(3);
    }

    newRoom->day = day;
    newRoom->month = month;
    newRoom->year = year;
    newRoom->room_number = room_number;
    strcpy(newRoom->cleaning_status, cleaning_status);
    strcpy(newRoom->cleaner_name, cleaner_name);
    strcpy(newRoom->hotel_name, hotel_name);
    newRoom->next = head;

    return newRoom;
}


Room* addRoomToEnd(Room* head, int day, int month, int year, int room_number, const char* cleaning_status, const char* cleaner_name, const char* hotel_name) {
    Room* newRoom= (Room*)malloc(sizeof(Room));
    if (newRoom == NULL) {
         // throwError(3);
    }
    newRoom->day = day;
    newRoom->month = month;
    newRoom->year = year;
    newRoom->room_number = room_number;
    strcpy(newRoom->cleaning_status, cleaning_status);
    strcpy(newRoom->cleaner_name, cleaner_name);
    strcpy(newRoom->hotel_name, hotel_name);
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
        if (current->room_number == roomNumber && strcmp(current->hotel_name, hotelName) == 0) {
            // Found the room in the specified hotel, update cleaning status
            strcpy(current->cleaning_status, "cleaned");
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
        printf("Date: %d-%02d-%02d, Room Number: %d, Status: %s, Cleaner: %s, Hotel: %s \n",
            head->year, head->month, head->day, head->room_number, head->cleaning_status, head->cleaner_name, head->hotel_name);
        head = head->next;
    }
}

void freeRoomList(Room* head) {
    while (head != NULL) {
        Room* temp = head;
        head = head->next;
        free(temp);
    }
}
