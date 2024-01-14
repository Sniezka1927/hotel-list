
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)
#include "Rooms.h"
#include "Menu.h"
#include "Helpers.h"


int main() {
    Room* roomList = initializeRoomList();

    displayMenu(roomList);
 
    freeRoomList(roomList);

    return 0;
}
