#include "terminalInterface.h"

int showMainMenu() {
  cout << "\n=== Main Menu ===\n"
       << "1) Validate Member\n"
       << "2) Add Member\n"
       << "3) Show All Members\n"
       << "4) Change Member Access\n"
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
    case 0:
      rebuildCSV(members);
      cout << "Goodbye!\n";
      return;
    default:
      cout << "Invalid choice\n";
    }
  }
}