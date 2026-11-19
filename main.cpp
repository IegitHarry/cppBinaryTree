#include <iostream>
#include <fstream>

using namespace std;

int deleteOpr = 0;

struct tree {
    int number;
    struct tree *lPointer, *rPointer;
};

void insertTree(tree *&t, int number) {
    if (t == NULL) {
        tree *newEntry = new struct tree;
        newEntry->number = number;
        newEntry->lPointer = NULL;
        newEntry->rPointer = NULL;
        t = newEntry;
        return;
    }
    if (number > t->number)
        insertTree(t->rPointer, number);
    else
        insertTree(t->lPointer, number);
}
void displayTree(tree *t) {
    if (t == NULL)
        return;
    displayTree(t->lPointer);
    cout << t->number << " ";
    displayTree(t->rPointer);
}
void deleteTree(tree *t) {
    if (t == NULL)
        return;
    deleteTree(t->lPointer);
    deleteTree(t->rPointer);
    delete t;
    deleteOpr++;
}
int main() {
    struct tree *t = NULL;
    t = new struct tree;
    t->lPointer = NULL;
    t->rPointer = NULL;

    ifstream file("values.txt");
    file >> t->number;

    int value;
    while (file >> value) {
        insertTree(t, value);
    }
    file.close();

    displayTree(t);
    cout << endl;

    deleteTree(t);
    cout << "Deleted: " << deleteOpr << "\n";

    return 0;
}
