

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Human {
    string name;
    int age;
    int weight;
    int id;    
public:
    static int ind;

    Human(string name, int age, int weight) {
        this->weight = weight;
        this->name = name;
        this->age = age;
        id = ++ind;
    }

    void SetName(string temp) {
        name = temp;
    }
    void SetAge(int temp) {
        age = temp;
    } 
    void SetWeight(int temp) {
        weight = temp;
    }

    void MinusId() {
        id-=1;
    }


    void print() {
        cout << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Weight: " << weight << endl;
    }

    static void MinusInd() {
        ind--;

    }
  
};
int Human::ind = 0;


void prt(vector<Human>& vc) {
    for (int i = 0; i < vc.size(); i++) {
        vc[i].print();
    }
}



void ad(vector<Human>& vc) {
    int age;
    string name;
    int weight;
    cout << "Enter name: " << endl;
    cin >> name;
    cout << "Enter age: " << endl;
    cin >> age;
    cout << "Enter weight: " << endl;
    cin >> weight;
    vc.push_back(Human(name, age, weight));
}

void del(vector<Human>& vc) {
    int choice;

    prt(vc);
    cout << "Type index of what person you want to delete: " << endl;
    cin >> choice;
    choice--;
    if (choice < vc.size()&&choice>=0) vc.erase(vc.begin() + choice);
    else {
        cout << "Wrong number" << endl;
        return;
    }
    Human::MinusInd();
    for (int i = choice; i < vc.size(); i++) {
        vc[i].MinusId();
    }
}


void edit(vector<Human>& vc) {
    int choice;
    prt(vc);
    cout << "Type index of what person you want to edit: " << endl;
    cin >> choice;
    choice--;
    if (choice >= vc.size()||choice<0) 
    {
        cout << "Wrong number" << endl;
        return;
    }

    else {
        cout << "What do you want to edit?" << endl;
        cout << "Name" << endl;
        cout << "Age" << endl;
        cout << "Weight" << endl;
        cout << "All" << endl;
        string temp;
        cin >> temp;
        if (temp == "name") {
            cout << "New name: ";
            cin >> temp;
            vc[choice].SetName(temp);
        }
        else  if (temp == "age") {
            cout << "New age: ";
            int ag;
            cin >> ag;
            vc[choice].SetAge(ag);
        }
        else  if (temp == "weight") {
            cout << "New weight: ";
            int wh;
            cin >> wh;
            vc[choice].SetWeight(wh);
        }
        else  if (temp == "all") {
            cout << "New name: ";
            cin >> temp;
            vc[choice].SetName(temp);
            cout << "New age: ";
            int ag;
            cin >> ag;
            vc[choice].SetAge(ag);
            cout << "New weight: ";
            int wh;
            cin >> wh;
            vc[choice].SetWeight(wh);
        }
        else cout << "Wrong number" << endl;

    }
}



int choice() {
    vector<Human>vc;
    while (true) {
        int x;
        cout <<endl<< "Current users:" <<Human::ind<< endl;
        cout << "Choose what you want:" << endl;
        cout << "1)Create person" << endl;
        cout << "2)Delete person" << endl;
        cout << "3)Edit person" << endl;
        cout << "4)See all" << endl;
        cout << "5)Exit" << endl;
        cin >> x;
        switch (x)
        {
        case 1:
            ad(vc);
            break;
        case 2:
            del(vc);
            break;
        case 3:
            edit(vc);
            break;
        case 4:
            prt(vc);
            break;
        case 5:
            return 0;
            break;

        default:
            cout << "Wrong choice" << endl;
        }
    }
}




