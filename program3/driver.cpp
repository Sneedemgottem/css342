#include <iostream>
#include <string>
using std::string;
#include "list342.h"
#include "child.h"

int main() {
  List342<Child> list;
  list.BuildList("children.txt");
  list.PrintList();
}