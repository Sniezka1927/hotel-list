#ifndef ROOMS_H
#define ROOMS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Status.h"

typedef struct Room {
    int day;
    int month;
    int year;
    int room_number;
    CleaningStatus cleaning_status;
    char cleaner_name[50];
    char hotel_name[20];
    struct Room* next;
} Room;


Room* initializeRoomList();

Room* addRoomToBeginning(Room* head, int day, int month, int year, int room_number, const char* cleaner_name, const char* hotel_name);

Room* addRoomToEnd(Room * head, int day, int month, int year, int room_number, const char* cleaner_name, const char* hotel_name);

int countElements(Room* head);

Room* removeFromBeginning(Room* head);

Room* removeFromEnd(Room* head);

void displayRoomList(Room* head);

Room* cleanRoom(Room* head, int roomNumber, const char* hotelName);

void freeRoomList(Room* head);

void writeRoomsToFile(Room* head);

#endif