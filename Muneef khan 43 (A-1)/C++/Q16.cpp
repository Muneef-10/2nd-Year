/*Q-16) Create a hotel room booking system where each room has attributes like room number, type (single/double), price, and availability status. 
The program should:
• Use a class Room to store room details.
• Use a pointer to a Room object to dynamically manage room records.
• Allow users to book a room, cancel a booking, and view available rooms.
• Ensure that a room cannot be double-booked.
• Display a summary of all rooms, including their booking status.*/

#include <iostream>
#include <string>
using namespace std;

class Room {
private:
    int roomNumber;
    string type;
    double price;
    bool isAvailable;

public:
    Room(int num, string t, double p) : roomNumber(num), type(t), price(p), isAvailable(true) {}

    bool bookRoom() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Room " << roomNumber << " has been successfully booked." << endl;
            return true;
        } else {
            cout << "Room " << roomNumber << " is already booked!" << endl;
            return false;
        }
    }
    bool cancelBooking() {
        if (!isAvailable) {
            isAvailable = true;
            cout << "Booking for Room " << roomNumber << " has been canceled." << endl;
            return true;
        } else {
            cout << "Room " << roomNumber << " is not booked yet!" << endl;
            return false;
        }
    }
    void displayRoom() const {
        cout << "Room Number: " << roomNumber
                  << ", Type: " << type
                  << ", Price: $" << price
                  << ", Availability: " << (isAvailable ? "Available" : "Booked") << endl;
    }
    bool isRoomAvailable() const {
        return isAvailable;
    }
};
void displayAvailableRooms(Room** rooms, int numRooms) {
    bool found = false;
    for (int i = 0; i < numRooms; ++i) {
        if (rooms[i]->isRoomAvailable()) {
            rooms[i]->displayRoom();
            found = true;
        }
    }
    if (!found) {
        cout << "No rooms available at the moment." << endl;
    }
}

int main() {
    const int numRooms = 5;
    Room* rooms[numRooms] = {
                                new Room(101, "Single", 50.0),
                                new Room(102, "Double", 80.0),
                                new Room(103, "Single", 55.0),
                                new Room(104, "Double", 85.0),
                                new Room(105, "Single", 60.0) };

    int choice, roomNumber;

    while (true) {
        cout << "\n--- Hotel Room Booking System ---" << endl;
        cout << "1. Book a room" << endl;
        cout << "2. Cancel booking" << endl;
        cout << "3. View available rooms" << endl;
        cout << "4. View all room details" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter room number to book: ";
                cin >> roomNumber;
                if (roomNumber >= 101 && roomNumber <= 105) {
                    rooms[roomNumber - 101]->bookRoom();
                } else {
                    cout << "Invalid room number!" << endl;
                }
                break;

            case 2:
                cout << "Enter room number to cancel booking: ";
                cin >> roomNumber;
                if (roomNumber >= 101 && roomNumber <= 105) {
                    rooms[roomNumber - 101]->cancelBooking();
                } else {
                    cout << "Invalid room number!" << endl;
                }
                break;

            case 3:
                cout << "\nAvailable Rooms:\n";
                displayAvailableRooms(rooms, numRooms);
                break;

            case 4:
                cout << "\nAll Room Details:\n";
                for (int i = 0; i < numRooms; ++i) {
                    rooms[i]->displayRoom();
                }
                break;

            case 5:
                cout << "Exiting the system..." << endl;
                for (int i = 0; i < numRooms; ++i) {
                    delete rooms[i]; 
                }
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    cout<<endl<<"*************************************************************"<<endl;
    cout<<"Program Prepared & Executes by:Muneef Khan, Class Roll no.: 43"<<endl;
    cout<<"*************************************************************"<<endl;
}
