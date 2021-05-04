#include<iostream>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};

node* find(node* tree, int x) {
    if (tree == NULL) {
        return NULL;
    }

    else if (x < tree->val) {
        return find(tree->left, x);
    }

    else if (x > tree->val) {
        return find(tree->right, x);
    }

    else {
        return tree;
    }
}

node* add(int x, node* tree) {
    if (find(tree, x) != NULL) {
        cout << "Drzewo nie moze posiadac duplikatow!" << endl;
        return NULL;
    }

    if (tree == NULL) {
        tree = new node;
        tree->val = x;
        tree->left = NULL;
        tree->right = NULL;
    }

    else if (x < tree->val) {
        tree->left = add(x, tree->left);
    }

    else if (x > tree->val) {
        tree->right = add(x, tree->right);
    }

    return tree;
}

node* min(node* tree) {
    if (tree == NULL) {
        return NULL;
    }

    else if (tree->left == NULL) {
        return tree;
    }

    else {
        return min(tree->left);
    }
}

node* remove(int x, node* tree) {
    node* mini;

    if (tree == NULL) {
        return NULL;
    }

    else if (x < tree->val) {
        tree->left = remove(x, tree->left);
    }

    else if (x > tree->val) {
        tree->right = remove(x, tree->right);
    }

    else if (tree->left != NULL && tree->right != NULL) {
        mini = min(tree->right);
        tree->val = mini->val;
        tree->right = remove(tree->val, tree->right);
    }

    else {

        if (tree->left == NULL) {
            tree = tree->right;
        }

        else if (tree->right == NULL) {
            tree = tree->left;
        }

    }

    mini = NULL;
    delete mini;

    return tree;
}

void print(node* tree, int space) {
    if (tree == NULL) {
        return;
    }

    space += 8;

    print(tree->right, space);

    cout << endl;
    for (int i = 8; i < space; i++) {
        cout << ' ';
    }
    cout << tree->val << endl;

    print(tree->left, space);

}

int main() {
    node* first;
    first = NULL;
    while (true) {
        cout << endl;
        cout << "1) Dodaj element do drzewa" << endl;
        cout << "2) Usun element z drzewa" << endl;
        cout << "3) Wyswietl drzewo" << endl;
        cout << "Podaj opcje menu: ";
        int opt;
        cin >> opt;
        switch (opt) {
        case 1:
            cout << "Podaj wartosc do dodania: ";
            int x;
            cin >> x;
            first = add(x, first);
            break;
        case 2:
            cout << "Podaj wartosc do usuniecia: ";
            int y;
            cin >> y;
            first = remove(y, first);
            break;
        case 3:
            print(first, 0);
            break;
        default:
            cout << "Bledny wybor!" << endl;
            break;
        }
    }
    return 0;
}
