#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data1, Node *next_1, Node *prev_1)
    {
        data = data1;
        next = next_1;
        prev = prev_1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node *converArray2LL(vector<int> arr)
{

    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {

        Node *temp = new Node(arr[i], nullptr, mover);
        mover->next = temp;
        mover = mover->next;
    }

    return head;
}

void print_LL(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

Node *deleteHead(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *temp = head;

    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;

    return head;
}

Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *prev = temp->prev;

    temp->prev = nullptr;
    prev->next = nullptr;

    delete temp;

    return head;
}

Node *deleteKthElem(Node *head, int k)
{
    if (head == NULL)
        return NULL;

    // now go to the kth node

    int count = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        count++;
        if (count == k)
        {
            break;
        }

        temp = temp->next;
    }

    Node *prev = temp->prev;
    Node *next = temp->next;

    if (prev == NULL && next == NULL)
    {
        return NULL;
    }

    else if (prev == NULL)
    {
        deleteHead(head);
    }

    else if (next == NULL)
    {
        return deleteTail(head);
    }

    prev->next = next;
    next->prev = prev;

    temp->next = nullptr;
    temp->prev = nullptr;

    return head;
}

void deleteGivenNode(Node *node)
{

    Node *prev = node->prev;
    Node *next = node->next;

    if (next == NULL)
    {
        prev->next = nullptr;
        node->prev = nullptr;
        delete node;
    }
    // not needed because k node won't be at the beginning
    //  if(prev == NULL){
    //      next->prev = nullptr;
    //      node->next = nullptr;

    //     delete node;
    // }

    prev->next = next;
    next->prev = prev;

    node->prev = nullptr;
    node->next = nullptr;

    delete node;
}

int main()
{
    vector<int> arr = {12, 5, 6, 7};

    Node *head = converArray2LL(arr);
    print_LL(head);

    // head = deleteHead(head);

    // print_LL(head);

    // head = deleteTail(head);

    // print_LL(head);

    // head = deleteKthElem(head, 3);
    // print_LL(head);

    deleteGivenNode(head->next);
    print_LL(head);
    return 0;
}