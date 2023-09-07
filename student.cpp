#include<iostream>
#include<fstream>

using namespace std;
int ID;
class Student
{
    public:
    int id;
    string name;
    int age;
    string stream;

    void addStudent()
    {
        cout << "Enter Student name" << endl;
        cin.get();
        getline(cin, name);
        cout << "Enter Student age" << endl;
        cin >> age;
        cout << "Enter Student stream" << endl;
        cin.get();
        getline(cin, stream);
        ID++;

        ofstream fout;
        fout.open("C:/Users/Babloo/Desktop/Practice/C++/Student/student.txt",ios::app);
        fout <<"\n" <<ID;
        fout << "\n" << name;
        fout << "\n" << age;
        fout << "\n" << stream;

        fout.close();

        cout << "Record Added successfully"<<endl;

        fout.open("C:/Users/Babloo/Desktop/Practice/C++/Student/id.txt", ios::app);
        fout<<"\n" << ID;
        fout.close();

    }
    void printAllStudent()
    {
        ifstream fin;
        fin.open("C:/Users/Babloo/Desktop/Practice/C++/Student/student.txt");
        Student s;
        while(!fin.eof())
        {
            fin>>s.id;
            fin.ignore();
            getline(fin, s.name);
            fin>>s.age;
            fin.ignore();
            getline(fin,s.stream);

        cout << "\n" << "Id: " << s.id;
        cout << "\n" << "Name: " << s.name;
        cout << "\n" << "Age: " << s.age;
        cout << "\n" << "Stream: " << s.stream;
        }
        fin.close();

    }
    void deleteStudent(int idx)
    {
        ifstream fin;
        ofstream fout;
        fin.open("C:/Users/Babloo/Desktop/Practice/C++/Student/student.txt");
        fout.open("C:/Users/Babloo/Desktop/Practice/C++/Student/temp.txt",ios::app);
        Student s;
        while(!fin.eof()){
            fin>>s.id;
            fin.ignore();
            getline(fin, s.name);
            fin>>s.age;
            fin.ignore();
            getline(fin,s.stream);
            if(idx != s.id){
                fout <<"\n" <<s.id;
                fout << "\n" << s.name;
                fout << "\n" << s.age;
                fout << "\n" << s.stream;
            }
        }
        fin.close();
        fout.close();
        remove("C:/Users/Babloo/Desktop/Practice/C++/Student/student.txt");
        rename("C:/Users/Babloo/Desktop/Practice/C++/Student/temp.txt", "C:/Users/Babloo/Desktop/Practice/C++/Student/student.txt");

    }
    void searchStudent(int idx)
    {
        ifstream fin;
        fin.open("C:/Users/Babloo/Desktop/Practice/C++/Student/student.txt");
        Student s;
        while(!fin.eof()){
            fin>>s.id;
            fin.ignore();
            getline(fin, s.name);
            fin>>s.age;
            fin.ignore();
            getline(fin, s.stream);

    if(idx == s.id){
        cout << "\nId = " << s.id;
        cout << "\nName = " << s.name;
        cout << "\nAge = " << s.age;
        cout << "\nStream = " << s.stream;
            }else{
                cout << "Invalid Id" << endl;
            }
        }
        fin.close();
}
    void updateStudent(int idx)
    {

        deleteStudent(idx);
        Student s;
        ofstream fout;
        fout.open("C:/Users/Babloo/Desktop/Practice/C++/Student/student.txt", ios::app);
        s.id = idx;
        cout << "\nEnter Name = ";
        cin.get();
        getline(cin,s.name);
        cout << "\nEnter Age = ";
        cin >> s.age;
        cout << "\nEnter Stream = ";
        cin.get();
        getline(cin, s.stream);
        fout << "\n" << s.id;
        fout << "\n" << s.name;
        fout << "\n" << s.age;
        fout << "\n" << s.stream;

        fout.close();
        cout << "\nRecord Updated Successfully";
    }
};
int main(){
    system("color 30");
    Student s;
    int choice;
    int idx;
    ifstream fin;
    fin.open("C:/Users/Babloo/Desktop/Practice/C++/Student/id.txt", ios::app);
    if(!fin)
    {
        cout << "*************************************************************************************************"<<endl;
        cout << "\t\t\t\t\tFile not found\t\t\t\t\t" << endl;
        cout << "*************************************************************************************************"<<endl;
    } else{
       while(!fin.eof()){
        fin>>ID;
       }
    }
    fin.close();
    while(true)
    {
        cout << "\t\t\t\t_______________________________________________________________________________";
        cout << "\n\t\t\t\t\t\t-----------Welcome to Student Dairy-------------"<<endl;
        cout << "\t\t\t\t_______________________________________________________________________________\t\t"<<endl;
        cout << "\n\t\t\t\t**********************************************************************\t\t\t\t";
        cout <<"\n";
        cout << "\t\t\t\t\t\t\t 1) Add Student\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\t\t\t\t\t 2) Print all Students\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\t\t\t\t\t 3) Search a Student\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\t\t\t\t\t 4) Update a Student\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\t\t\t\t\t 5) Delete a Student\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\t\t\t\t\t 6) Exit\t\t\t\t\t\t\t" << endl;
        cout << "\n\t\t\t\t************************************************************************\t\t\t\t";
        cout << "\n\n\n";
        cout << "\t\t\t\t\t\t\tEnter Your Choice\t";;
        // cout << "\t\t\t\t\t\t\t\t";
        cin >> choice;
        switch (choice)
        {
        case 1:
            s.addStudent();
            break;

        case 2:
            s.printAllStudent();
            break;

        case 3:
           cout << "\t\t\t\t\t\t\tEnter Student Id\t\t\t\t\t\t\t" << endl;
            cin >> idx;
            s.searchStudent(idx);
            break;

        case 4:
            cout <<"\t\t\t\t\t\t\tEnter Student Id\t\t\t\t\t\t\t"<< endl;
            cin >> idx;
            s.updateStudent(idx);
            break;

        case 5:
            cout << "\t\t\t\t\t\t\tEnter Student Id\t\t\t\t\t\t\t" << endl;
            cin >> idx;
            s.deleteStudent(idx);
            break;

        case 6:
        cout << "\t\t\t\t\t\t\t You Exits\t\t\t\t\t\t\t" << endl;
        exit(0);
        default:
            return 0;
        }
    }
    return 0;
}
