#include <iostream>

using namespace std;

    class MyList{
        int x,count_;
        MyList *First, *Last, *Next, *Prev; //указатели на предыдущий и следующий элементы
    public:
        MyList(): First(NULL),Last(NULL){};
        void add(int);
        void show();
        void del();
        ~MyList();
    };

   void MyList::add(int x){
        MyList *temp = new MyList;//создание вспомогательного указателя
        temp->x = x;
        temp->Next = NULL;
        if (!First){
            temp->Prev = NULL;
            First = temp;//первый элемент является последним при вытаскивании данных из стека
            Last = First;//последний элемент является первым
        } else {
            temp->Prev = Last;
            Last->Next = temp;
            Last = temp;
        }
    }

    void MyList::show(){
        MyList *t = First;
        while (t){
            cout << t->x << " ";
            t = t->Next;
        }
        cout << endl;
    }

    void MyList::del(){
            MyList *temp = Last;
            Last = Last->Prev;
            Last->Next = NULL;
            delete temp;
            return;
    }
//деструктор
    MyList::~MyList(){
        while (First){
            Last=First->Next;
            delete First;
            First=Last;
        }
    }


int main()
{
    MyList lst;
    cout << "Choose a number to work with the stack: " << endl;
    while(true) {
        cout << "1 - add element to stack" << endl;
        cout << "2 - delete element" << endl;
        cout << "3 - exit" << endl;
        string s;
        cin >> s;
        if(s == "1") {
            int newelem;
            cout << "Enter new element: ";
            cin >> newelem;
            lst.add(newelem);
            lst.show();
        }
        else if(s == "2") {
            lst.del();
            lst.show();
        }
        else if(s == "3") {
            return 0;
        }
        else
        cout << "Error" << endl;
    }
    return 0;
}
