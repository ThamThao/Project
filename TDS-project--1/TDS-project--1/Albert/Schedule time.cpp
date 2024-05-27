/*#include <iostream>
#include <ctime>
#include <array>
#include <string>
#include <fstream>

using namespace std;

struct Appointment {
    string petName;
    string ownerName;
    bool isBooked = false;
};

int main() {
    // Create a 2D array for the schedule
    // Each day has 3 sections
    array<array<Appointment, 3>, 31> schedule;

    // Get the current system time
    time_t now = time(0);
    tm *ltm = localtime(&now);

    // Get the current month (0-11)
    int currentMonth = ltm->tm_mon;

    // Get the current year
    int currentYear = 1900 + ltm->tm_year;

    // Array of month names
    string monthNames[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // Example of booking an appointment
    // Only allow booking in the current month
    if (currentMonth == ltm->tm_mon) {
        schedule[0][0].petName = "Fluffy";
        schedule[0][0].ownerName = "John Doe";
        schedule[0][0].isBooked = true;
    }

    // Open a file to write the schedule
    // The file name is the current month and year
    ofstream scheduleFile(monthNames[currentMonth] + "_" + to_string(currentYear) + ".txt");

    // Write the schedule to the file
    for (int day = 0; day < 31; ++day) {
        for (int section = 0; section < 3; ++section) {
            scheduleFile << "Day " << day + 1 << ", Section " << section + 1 << ": ";
            if (schedule[day][section].isBooked) {
                scheduleFile << schedule[day][section].petName << " (" << schedule[day][section].ownerName << ")";
            } else {
                scheduleFile << "Free";
            }
            scheduleFile << endl;
        }
    }

    // Close the file
    scheduleFile.close();

    return 0;
}*/



#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

// Define the structure for a section
struct Section {
    string petName;
    string ownerName;
    bool isBooked;
};

// Define the structure for a node in the linked list
struct Node {
    Section sections[3];
    Node* next;
};

// Function to add a new node to the linked list
Node* addNode(Node* head, Section sections[3]) {
    Node* newNode = new Node;
    for (int i = 0; i < 3; i++) {
        newNode->sections[i] = sections[i];
    }
    newNode->next = head;
    return newNode;
}

int main() {
    // Get the current date and time
    time_t now = time(0);
    tm* ltm = localtime(&now);

    // Get the current month
    int currentMonth = ltm->tm_mon;

    // Get the current year
    int currentYear = 1900 + ltm->tm_year;

    // Array of month names
    string monthNames[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // Get the number of days in the current month
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (currentYear % 4 == 0 && (currentYear % 100 != 0 || currentYear % 400 == 0)) {
        daysInMonth[1] = 29; // Leap year
    }
    int days = daysInMonth[currentMonth];

    // Create a linked list for the schedule
    Node* schedule = nullptr;

    // Initialize the schedule with a node for each day
    for (int i = 0; i < days; i++) {
        Section sections[3] = {
            {"", "", false},
            {"", "", false},
            {"", "", false}
        };
        schedule = addNode(schedule, sections);
    }

    // Example of booking an appointment
    // Only allow booking in the current month
    if (currentMonth == ltm->tm_mon) {
        Node* temp = schedule;
        for (int i = 0; i < days; i++) {
            if (i == 0) { // Book the first day as an example
                temp->sections[0].petName = "Fluffy";
                temp->sections[0].ownerName = "John Doe";
                temp->sections[0].isBooked = true;
            }
            temp = temp->next;
        }
    }

    // Open a file to write the schedule
    // The file name is the current month and year
    ofstream scheduleFile(monthNames[currentMonth] + "_" + to_string(currentYear) + ".txt");

    // Write the schedule to the file
    Node* temp = schedule;
    int day = 1;
    while (temp != nullptr) {
        for (int i = 0; i < 3; i++) {
            scheduleFile << "Day " << day << ", Section " << i+1 << ": ";
            if (temp->sections[i].isBooked) {
                scheduleFile << temp->sections[i].petName << " (" << temp->sections[i].ownerName << ")";
            } else {
                scheduleFile << "Free";
            }
            scheduleFile << endl;
        }
        temp = temp->next;
        day++;
    }

    // Close the file
    scheduleFile.close();

    return 0;
}
/*// Get the day of the week for the first day of the current month
tm firstDay = *ltm;
firstDay.tm_mday = 1;
mktime(&firstDay);
int firstDayOfWeek = firstDay.tm_wday;

// Initialize the schedule with a node for each day
for (int i = 0; i < days; i++) {
    // Skip Sundays
    if ((firstDayOfWeek + i) % 7 != 0) {
        Section sections[3] = {
            {"", "", false},
            {"", "", false},
            {"", "", false}
        };
        schedule = addNode(schedule, sections);
    }
} check sunday cuz sunday close*/