#pragma once

#include "main.h"

class Provider {
public:
  Provider();
  Provider(const string& id, const string& name);

private:
  string provID; // 9 digits
  string provName; // 25 char max
  string provStreet;
  string provCity;
  string provState;
  int provZip;
  bool suspended = false;

};