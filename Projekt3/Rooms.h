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
    int roomNumber;
    CleaningStatus cleaningStatus;
    char cleanerName[50];
    char hotelName[20];
    struct Room* next;
} Room;


Room* initializeRoomList();

Room* addRoomToBeginning(Room* head, int day, int month, int year, int roomNumber, const char* cleanerName, const char* hotelName);

Room* addRoomToEnd(Room * head, int day, int month, int year, int roomNumber, const char* cleanerName, const char* hotelName);

int countElements(Room* head);

Room* removeFromBeginning(Room* head);

Room* removeFromEnd(Room* head);

void displayRoomList(Room* head);

Room* cleanRoom(Room* head, int roomNumber, const char* hotelName);

void freeRoomList(Room* head);

void writeRoomsToFile(Room* head);

Room* readRoomsFromFile();

#endif