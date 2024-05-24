#include <iostream>

using namespace std;

bool puste(int front, int rear)
{
    return front == rear;
}

bool przepelnienie(int len, int size)
{
    return len == size;
}

void dodaj(int arr[], int size, int& rear, int element, int& len)
{
    if (przepelnienie(len, size))
    {
        cout << "Kolejka jest pelna!" << endl;
        return;
    }

    arr[rear] = element;
    rear = (rear + 1) % size;
    len++;
}

void odejmij(int rear, int& front, int size, int& len)
{
    if (puste(front, rear))
    {
        cout << "Kolejka jest pusta!" << endl;
    }

    front = (front + 1) % size;
    len--;
}

void wyswietl(int arr[], int front, int rear, int len)
{
    if (puste(front, rear))
    {
        cout << "Kolejka jest pusta!" << endl;
    }
    int index;
    for (int i = 0; i < len; i++)
    {
        index = front + i;
        if(front+i >= 5)  index = front+i-5;
        cout << arr[index] << " ";
    }
    cout << endl;
}


int main()
{
    int arr[5];
    int front = 0;
    int rear = 0;
    int wybor;
    int wlaczone = 1;
    int element;
    int size = 5;
    int len = 0;

    while(wlaczone)
    {
        cout << "1. Dodaj element do kolejki." << endl <<
        "2. Zwolnij element z kolejki." << endl <<
        "3. Wyswietl elementy." << endl <<
        "--------------------------------------\n\n\n";
        cin >> wybor;
        switch (wybor) {
            case 1:
                cout << "Podaj element" << endl;
                cin >> element;
                dodaj(arr, size, rear, element, len);
                break;
            case 2:
                odejmij(rear, front, size, len);
                break;
            case 3:
                wyswietl(arr, front, rear, len);
                break;
            case 0:
                wlaczone = 0;
                break;
            default:
                cout << "Error" << endl;
                wlaczone = 0;
        }
    }
    return 0;
}
