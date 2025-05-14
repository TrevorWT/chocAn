#include "member.h"
#include "memberManager.h"
#include "terminalInterface.h"
#include <iostream>

int main() {

  map<string, Member> members;

  loadMembersFromCSV("data/members.csv", members);
  runTerminal(members);

  return 0;
}
