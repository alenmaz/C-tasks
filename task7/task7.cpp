#include "SLList.h"


void printSLList(const SLList* list)
{
    cout << "List: " << endl;
    if (list == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }
    SLList* current = const_cast<SLList*>(list);
    while (current != NULL)
    {
        cout << current->getData() << endl;
        current = current->next();
    }
}

int getRandNum(const int minVal, const int maxVal)
{
    return (rand() % (maxVal - minVal + 1)) + minVal;
}

SLList* makeSLList(int size)
{
    SLList* head = SLList::beginList(getRandNum(0, 5));
    SLList* tmp = head;
    for (int i = 0; i < size - 1; i++)
        tmp = tmp->addElement(getRandNum(0, 5));
    return head;
}

void deleteDuplicates(const SLList* list)
{
    if (list == NULL)
        return;
    SLList* tmp;
    SLList* current = const_cast<SLList*>(list);
    while (current != NULL)
    {
        SLList* other = current;
        while (other->hasNext())
        {
            if (other->next()->getData() == current->getData())
            {
                tmp = other->next()->next();
                other->removeNext();
                other->addElement(tmp);
            }
            else
                other = other->next();
        }
        current = current->next();
    }
}

SLList* findElement(SLList* head, int k, int& i)
{
    if (head == NULL || k <= 0)
        return NULL;
    SLList* node = findElement(head->next(), k, i);
    i = i + 1;
    if (i == k)
        return head;
    return node;
}

int main()
{
    const int n = 10;
    int i = 0;

    SLList* list = makeSLList(n);
    printSLList(list);

    deleteDuplicates(list);
    printSLList(list);

    int k = 0;
    cout << "Enter k: ";
    cin >> k;
    SLList* k_elem = findElement(list, k, i);
    if (k_elem == NULL)
        cout << "no such element" << endl;
    else
        cout << endl << "k element from end: " << k_elem->getData() << endl;

    delete list;
}
