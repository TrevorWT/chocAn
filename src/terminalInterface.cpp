#include "terminalInterface.h"

int showMainMenu() {
    cout << "\n=== Main Menu ===\n"
         << "1) Validate Member\n"
         << "2) Add Member\n"
         << "3) Show All Members\n"
         << "4) Change Member Access\n"
         << "5) Update Member Information\n"
         << "6) Delete Member\n"
         << "0) Exit\n"
         << "Select an option: ";
    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

void runTerminal(map<string, Member> &members) {
    while (true) {
        switch (showMainMenu()) {
        case 1:
            validateMember(members);
            break;
        case 2:
            addMember(members);
            break;
        case 3:
            showAllMembers(members);
            break;
        case 4:
            changeMemberAccess(members);
            break;
        case 5:
            updateInfoTerminal(members);
            break;
        case 6:
            deleteMember(members);
            break;
        case 0:
            rebuildCSV(members);
            cout << "Goodbye!\n";
            return;
        default:
            cout << "Invalid choice\n";
        }
    }
}

void updateInfoTerminal(map<string, Member> &members) {
    cout << "Update Member Information\n";
    string id = getValidatedInput(9, 9, "numbers", false, "ID");
    auto it = members.find(id);
    if (it == members.end()) {
        cout << "Member not found\n";
        return;
    }
    Member &m = it->second;

    cout << "Current information:\n"
         << "ID:         " << m.getID() << '\n'
         << "Name:       " << m.getName() << '\n'
         << "Street:     " << m.getStreet() << '\n'
         << "City:       " << m.getCity() << '\n'
         << "State:      " << m.getState() << '\n'
         << "ZIP:        " << m.getZip() << '\n';

    cout << "what information would you like to update?\n"
         << "1) Name\n"
         << "2) Street\n"
         << "3) City\n"
         << "4) State\n"
         << "5) Zip\n"
         << "6) All\n"
         << "0) Cancel\n"
         << "Select an option: ";

    int choice = getValidatedInt(0, 6, "input");
    if (choice == 0) {
        cout << "Update cancelled.\n";
        return;
    }

    updateMemberInfo(members, choice, m);
}