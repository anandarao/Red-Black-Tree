// Driver Program for Red Black Tree

#include <bits/stdc++.h>
#include "RBTree.h"
using namespace std;

int main() {
    int data;
    RBTree rbTree1, rbTree2;

    cin >> data;
    while (data != 0)
    {
        rbTree1.insert(data);
        cin >> data;
    }

    cin >> data;
    while (data != 0)
    {
        rbTree2.insert(data);
        cin >> data;
    }
    
    return 0;
}