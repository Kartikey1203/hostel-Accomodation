#include <iostream>
#include <vector>
using namespace std;

class Student
{
public:
    string name;
    int rollNo;

    Student(string n, int r) : name(n), rollNo(r) {}
};

class Hostel
{
private:
    int bed;
    vector<Student> ve;

public:
    Hostel()
    {
        bed = 0;
    }

    bool bedStatus()
    {
        if (bed < 3)
        {
            bed++;
            return true;
        }
        return false;
    }

    void add(string n, int r)
    {
        Student student(n, r);
        ve.push_back(student);
        allocation();
    }

    void allocation()
    {
        if (bedStatus())
        {
            cout << "You have allocated bed in hostel" << endl
                 << endl;
        }
        else
        {
            cout << "Hostel is full" << endl
                 << endl;
        }
    }

    void remove()
    {
        int rn;
        cout << "Enter roll no for remove student: ";
        cin >> rn;
        for (int i = 0; i < ve.size(); i++)
        {
            if (rn == ve[i].rollNo)
            {
                cout << "Name: " << ve[i].name << endl;
                cout << "RollNo: " << rn << endl;
                ve.erase(ve.begin() + i);
                cout << "Student is removed from hostel" << endl
                     << endl;
            }
        }
    }

    void display()
    {
        for (int i = 0; i < ve.size(); i++)
        {
            cout << i + 1 << "> Name: " << ve[i].name << endl;
            cout << "RollNo: " << ve[i].rollNo << endl
                 << endl;
        }
    }
};

int main()
{
    string n;
    int r;
    Hostel hostel;
    cout << "Students Hostel" << endl;
    cout << "----------------" << endl
         << endl;
    while (true)
    {
        cout << "Enter '1' for add student" << endl;
        cout << "Enter '2' for remove student from hostel" << endl;
        cout << "Enter '3' for display students of hostel" << endl;
        cout << "Enter '0' for exit from program" << endl;
        int choice;
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter Name: ";
            cin >> n;
            cout << "Enter Roll No: ";
            cin >> r;
            hostel.add(n, r);
        }
        else if (choice == 2)
        {
            hostel.remove();
        }
        else if (choice == 3)
        {
            hostel.display();
        }
        else if (choice == 0)
        {
            exit(0);
        }
        else
        {
            cout << "Invalid input" << endl
                 << endl;
        }
    }
}
