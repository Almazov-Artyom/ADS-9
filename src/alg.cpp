// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    BST<std::string> bst;
    std::ifstream file(filename);
    std::string a;
    while (!file.eof()) {
        char c = file.get();
        if (c >= 65 && c <= 90) {
            c += 32;
            a += c;
            continue;
        }
        if (c >= 97 && c <= 122) {
            a += c;
        } else {
            if (!a.empty()) {
                bst.add(a);
            }
            a.clear();
        }

    }
    bst.add(a);
    file.close();
    return bst;
}
