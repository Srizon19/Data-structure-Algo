#include <bits/stdc++.h>

using namespace std;

class node
{

public:
    int data;
    node *next;

public:
    node(int data1, node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

node *conversionToLL(vector<int> &arr)
{
    node *head = new node(arr[0]);
    node *mover = head; // this mover initially points to head and traverse the list
    for (int i = 1; i < arr.size(); i++)
    {
        node *temp = new node(arr[i]);

        mover->next = temp;

        mover = temp;
    }

    return head;
}

int lengthOfLL(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

bool checkIfExists(node *head, int data)
{

    node *temp = head;

    while (temp)
    {
        if (temp->data == data)
        {
            return true;
        }

        temp = temp->next;
    }

    return false;
}

node *removeHead(node *head)
{
    if (head == NULL)
        return head;
    node *temp = head;

    head = head->next;

    delete temp;

    return head;
}

void print_LL(node *head)
{

    node *temp = head;
    while (temp)
    {

        cout << temp->data << " ";

        temp = temp->next;
    }

    cout << endl;
}

node *removeTail(node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    node *temp = head;

    // I need to reach out the second last node and then change the next value

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;

    temp->next = nullptr;

    return head;
}

node *removeKthElem(node *head, int k)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    if (k == 1)
    {
        return removeHead(head);
    }

    int count = 1;
    node *temp = head;
    node *prev = NULL;

    while (temp != NULL && count < k)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        // k is greater than the length of the list, return the unchanged head
        return head;
    }

    // Remove the kth element
    if (prev != NULL && temp != NULL)
    {
        prev->next = temp->next;
        delete temp;
    }

    return head;
}
node *removebyValue(node *head, int val)
{
    if (head == NULL)
        return head;

    if (head->data == val)
    {
        node *temp = head;
        head = head->next;

        delete temp;
        return head;
    }

    node *temp = head;
    node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == val)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}

node *insertAtHead(node *head, int data)
{
    node *newNode = new node(data);
    node *temp = head;

    newNode->next = temp;

    return newNode;
}

node *insertAtTail(node *head, int data)
{
    if (head == NULL)
        return new node(data);

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    node *newNode = new node(data);
    temp->next = newNode;

    return head;
}

int main()
{
    vector<int> arr = {10000, 2, 4, 5, 6};

    // Create a linked list from this array
    node *result_LL = conversionToLL(arr);
    cout << result_LL->data << endl;

    // Traverse the linked list
    node *temp = result_LL;

    cout << "len of LL: " << lengthOfLL(result_LL) << endl;
    cout << "check 10000 exists or not: " << checkIfExists(result_LL, 100000) << endl;

    // Remove the head
    node *head = removeHead(result_LL);
    print_LL(head);

    // Remove the tail from the updated list
    head = removeTail(head);
    print_LL(head);

    // Remove the 2nd element from the updated list
    head = removeKthElem(head, 2);
    print_LL(head);

    head = removebyValue(head, 5);

    print_LL(head);

    head = insertAtHead(head, 23);

    cout << "inserting at head: " << endl;
    print_LL(head);

    head = insertAtTail(head, 290);

    cout << "inserting at tail: " << endl;
    print_LL(head);

    return 0;
}
