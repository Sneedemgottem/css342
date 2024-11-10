#include <iostream>
#include <string>
using std::string;
#include "list342.h"

int main() {
    string the = "the";
    string fox = "fox";
    string jumped = "jumped";
    string jumped2 = "jumped";
    string high = "high";
    string the2 = "the";

    List342<string> list;
    list.Insert(&the);
    list.Insert(&fox);
    list.Insert(&jumped);
    list.Insert(&high);
    list.Insert(&jumped2);
    list.Insert(&the);
    list.Insert(&fox);

    list.PrintList();

    return 0;
}