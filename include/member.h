#pragma once

#include "main.h"

class Member {
public:
  Member();
  Member(const string& id, const string& name);

  string getID() const;
  string getName() const;
  string getStreet() const;
  string getCity() const;
  string getState() const;
  string getZip() const;


  bool isSuspended() const;
  void setName(const string& name);
  void setID(const string& id);
  void setStreet(const string& street);
  void setCity(const string& city);
  void setState(const string& state);
  void setZip(const string& zip);
  void setSuspended(bool status);

  void addMember(map<string,Member>& members);
private:
  string memID;
  string memName;
  string memStreet {""};
  string memCity {""};
  string memState {""};
  string memZip {};
  bool suspended = false;

};