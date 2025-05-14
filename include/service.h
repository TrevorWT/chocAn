#pragma once

#include "main.h"

class Service {
public:
  Service();
  // Service(const string& id, const string& name);

private:
  int serviceDate; // MM-DD-YYYY
  int dataReceived; // MM-DD-YYYY HH:MM:SS
  string memberName;
  string memberID;
  int serviceCode; // 6 digits
  float fee; // up to $999.99
  int totalConsultations;
  float feeThisWeek;

};