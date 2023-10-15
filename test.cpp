#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int c;
    Node *child[58];
    Node()
    {
        c = 0;
        for (int i = 0; i < 58; ++i)
            child[i] = 0;
    }
};
void Trie_insert(string st, Node *root)
{
    for (int i = 0; i < st.size(); ++i)
    {
        int r = st[i] - 'A';
        if (root->child[r] == NULL)
        {
            root->child[r] = new Node;
        }
        root = root->child[r];
    }
    root->c++;
}
int Trie_search(Node *root, string st, int k = 0)
{
    Node *u = root;
    if (u == NULL)
        return 0;
    if (k == st.size())
        return u->c;
    int r = st[k] - 'A';
    Trie_search(u->child[r], st, ++k);
}
void print_trie(Node *u, string st = "")
{
    if (u->c > 0)
    {
        for (int i = 0; i < u->c; ++i)
            cout << st << endl;
    }
    for (int i = 0; i < 58; ++i)
    {
        if (u->child[i] != NULL)
        {
            char ch = i + 'A';
            print_trie(u->child[i], st + ch);
        }
    }
}
void printRevTRIE(Node *u, string st = "")
{
    for (int i = 57; i >= 0; --i)
    {
        if (u->child[i] != NULL)
        {
            char ch = i + 'A';
            printRevTRIE(u->child[i], st + ch);
        }
    }
    if (u->c > 0)
    {
        for (int i = 0; i < u->c; ++i)
            cout << st << endl;
    }
}
void printDup(Node *u, string st = "")
{
    if (u->c > 1)
    {
        cout << st << endl;
    }
    for (int i = 0; i < 58; ++i)
    {
        if (u->child[i] != NULL)
        {
            char ch = i + 'A';
            printDup(u->child[i], st + ch);
        }
    }
}
bool isLeaf(Node *u)
{
    for (int i = 0; i < 58; ++i)
    {
        if (u->child[i] != NULL)
            return false;
    }
    return true;
}
bool isJunc(Node *u)
{
    int c = 0;
    for (int i = 0; i < 58; ++i)
    {
        if (u->child[i] != NULL)
            c++;
    }
    if (c > 1 or u->c > 0)
        return true;
    return false;
}
void delEdge(Node *u, char c, int d)
{
    if (!d)
        return;
    int r = c - 'A';
    Node *n = u->child[r];
    u->child[r] = NULL;
    delete n;
}
int delTrie(Node *u, string s, int k = 0)
{
    if (u == NULL)
        return 0;
    if (k == s.size())
    {
        if (u->c == 0)
            return 0;
        u->c--;
        return 0;
    }
    int r = s[k] - 'A';
    int d = delTrie(u, s, ++k);
    int j = 0;
    if (isJunc(u))
        j = 1;
    delEdge(u, s[k], d);
    if (j)
        d = 0;
    return d;
}
Node *findptr(string s, Node *root)
{
    Node *u = root;
    for (int k = 0; k < s.size(); k++)
    {
        int r = s[k] - 65;
        u = u->child[r];
    }
    return u;
}
int main()
{
    Node *root = new Node();
    while (1)
    {
        cout << "1. Insert    2. Search    3. Delete   4. Lexicographical Sorting  5. Display Strings  6. Reverse Sort 7. Print String Appears more than 1. 8. Print String with a specific prefix. 9. End" << endl
             << endl;
        int choice;
        string x;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Insert String: ";
            cin >> x;
            Trie_insert(x, root);
            cout << x << " is inserted in the trie" << endl;
        }
        else if (choice == 2)
        {
            cout << "Enter string to search: ";
            cin >> x;
            if (Trie_search(root, x) > 0)
                cout << x << " FOUND " << endl;
            else
                cout << x << " NOT FOUND " << endl;
        }
        else if (choice == 3)
        {
            cout << "Enter string to delete: ";
            cin >> x;
            delTrie(root, x, 0);
        }
        else if (choice == 4)
        {
            print_trie(root);
        }
        else if (choice == 5)
        {
            print_trie(root);
        }
        else if (choice == 6)
        {
            printRevTRIE(root);
        }
        else if (choice == 7)
        {
            printDup(root);
        }
        else if (choice == 8)
        {
            cout << "Enter the Prefix" << endl;
            cin >> x;
            Node *u = findptr(x, root);
            print_trie(u, x);
        }
        else if (choice == 9)
        {
            break;
        }
        else
        {
            cout << "Invalid Choice" << endl;
            break;
        }
        cout << endl;
    }
}
/*inputs:

1 MIST
1 MIT
1 CSE
1 CSE
1 CE
1 MISTCSE
1 ME
1 EECE
1 ABC
1 ABC
1 AB

*/
