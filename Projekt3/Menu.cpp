#include "Rooms.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Helpers.h"
#include "Menu.h"
#include "Error.h"
#pragma warning(disable: 4996)

void displayMenu(Room* roomList) {
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add element to the beginning\n");
        printf("2. Add element to the end\n");
        printf("3. Show list\n");
        printf("4. Count added elements\n");
        printf("5. Remove from beginning\n");
        printf("6. Remove from end\n");
        printf("7. Clean room\n");
        printf("8. Write rooms to file\n");
        printf("9. Read rooms from file\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            int day, month, year, roomNumber;
            char cleanerName[50], hotelName[20];
            
            printf("Enter room details:\n");
            printf("Day: "); 
            if (scanf("%d", &day) != 1 || getchar() != '\n') { throwError(4); };
            printf("Month: ");
            if (scanf("%d", &month) != 1 || getchar() != '\n') { throwError(4); };
            printf("Year: ");
            if (scanf("%d", &year) != 1 || getchar() != '\n') { throwError(4); };
            printf("Room Number: ");
            if (scanf("%d", &roomNumber) != 1 || getchar() != '\n') { throwError(4); };
            printf("Cleaner Name: ");
            if (scanf("%49s", cleanerName) != 1 || getchar() != '\n') { throwError(4); };
            printf("Hotel Name: ");
            if (scanf("%19s", hotelName) != 1 || getchar() != '\n') { throwError(4); };
            validateDate(day, month, year);
            roomList = addRoomToBeginning(roomList, day, month, year, roomNumber, cleanerName, hotelName);
            
            break;
        }
        case 2: {
            int day, month, year, roomNumber;
            char cleanerName[50], hotelName[20];

            printf("Enter room details:\n");
            printf("Day: ");
            if (scanf("%d", &day) != 1 || getchar() != '\n') { throwError(4); };
            printf("Month: ");
            if (scanf("%d", &month) != 1 || getchar() != '\n') { throwError(4); };
            printf("Year: ");
            if (scanf("%d", &year) != 1 || getchar() != '\n') { throwError(4); };
            printf("Room Number: ");
            if (scanf("%d", &roomNumber) != 1 || getchar() != '\n') { throwError(4); };
            printf("Cleaner Name: ");
            if (scanf("%49s", cleanerName) != 1 || getchar() != '\n') { throwError(4); };
            printf("Hotel Name: ");
            if (scanf("%19s", hotelName) != 1 || getchar() != '\n') { throwError(4); };
            validateDate(day, month, year);
            roomList = addRoomToEnd(roomList, day, month, year, roomNumber, cleanerName, hotelName);
            break;
        }
        case 3:
            displayRoomList(roomList);
            break;
        case 4:
            printf("Number of elements in the list: %d\n", countElements(roomList));
            break;
        case 5:
            roomList = removeFromBeginning(roomList);
            break;
        case 6:
            roomList = removeFromEnd(roomList);
            break;
        case 7: {
            int roomNumber;
            char hotelName[20];
            printf("Enter the room number to clean: ");
            if (scanf("%d", &roomNumber) != 1 || getchar() != '\n') { throwError(4); };
            printf("Enter the hotel name: ");
            if (scanf("%19s", hotelName) != 1 || getchar() != '\n') { throwError(4); };

            roomList = cleanRoom(roomList, roomNumber, hotelName);
            break;
        }
        case 8:
            writeRoomsToFile(roomList);
            break;
        case 9:
            roomList = readRoomsFromFile();
            break;
        case 10:
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 8.\n");
        }

    } while (choice != 10);
}