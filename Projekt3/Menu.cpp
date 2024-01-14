#include "Rooms.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Helpers.h"
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
            int day, month, year, room_number;
            char cleaner_name[50], hotel_name[20];
            
            printf("Enter room details:\n");
            printf("Day: "); scanf("%d", &day);
            printf("Month: "); scanf("%d", &month);
            printf("Year: "); scanf("%d", &year);
            printf("Room Number: "); scanf("%d", &room_number);
            printf("Cleaner Name: "); scanf("%49s", cleaner_name);
            printf("Hotel Name: "); scanf("%19s", hotel_name);
            validateDate(day, month, year);
            roomList = addRoomToBeginning(roomList, day, month, year, room_number, cleaner_name, hotel_name);
            
            break;
        }
        case 2: {
            int day, month, year, room_number;
            char cleaner_name[50], hotel_name[20];

            printf("Enter room details:\n");
            printf("Day: "); scanf("%d", &day);
            printf("Month: "); scanf("%d", &month);
            printf("Year: "); scanf("%d", &year);
            printf("Room Number: "); scanf("%d", &room_number);
            printf("Cleaner Name: "); scanf("%49s", cleaner_name);
            printf("Hotel Name: "); scanf("%19s", hotel_name);
            printf("Received hotel name %s \n \n \n", hotel_name);
            validateDate(day, month, year);
            roomList = addRoomToEnd(roomList, day, month, year, room_number, cleaner_name, hotel_name);
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
            scanf("%d", &roomNumber);
            printf("Enter the hotel name: ");
            scanf("%19s", hotelName);
            roomList = cleanRoom(roomList, roomNumber, hotelName);
            break;
        }
        case 8:
            // writeRoomsToFile(roomList);
            break;
        case 9:
            break;
        case 10:
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 8.\n");
        }

    } while (choice != 10);
}