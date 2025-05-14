#include "member.h"

Member::Member() {}

Member::Member(const string &id, const string &name)
    : memID(id), memName(name), suspended(false) {}
string Member::getID() const { return memID; }

string Member::getName() const { return memName; }

string Member::getStreet() const { return memStreet; }

string Member::getCity() const { return memCity; }

string Member::getState() const { return memState; }

string Member::getZip() const { return memZip; }

bool Member::isSuspended() const { return suspended; }

void Member::setName(const string &name) { memName = name; }

void Member::setID(const string &id) { memID = id; }

void Member::setStreet(const string &street) { memStreet = street; }

void Member::setCity(const string &city) { memCity = city; }

void Member::setState(const string &state) { memState = state; }

void Member::setZip(const string &zip) { memZip = zip; }

void Member::setSuspended(bool status) { suspended = status; }



