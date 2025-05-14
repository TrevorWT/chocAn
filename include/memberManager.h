#pragma once

#include "inputValidation.h"
#include "main.h"
#include "member.h"

void addMember(map<string, Member> &members);
void loadMembersFromCSV(const string &filename, map<string, Member> &members);
void validateMember(map<string, Member> &members);
void showAllMembers(const std::map<std::string, Member> &members);
void changeMemberAccess(map<string, Member> &members);
void deleteMember(map<string, Member> &members);
void rebuildCSV(const map<string, Member> &members);
void updateMemberInfo(map<string, Member> &members, int choice, Member &m);
