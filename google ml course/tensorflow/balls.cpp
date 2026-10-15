#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

/*
    Author(s) : Brian Zhou, Keshav Ramanujan, Asher Chen, Kevin Liu
    Course : CSCE 1040.400 Fall 2026
    Instructor : Dr. Amar Maharjan
    Date : 09/18/2026
    Description : This program implements student grade system. The program displays a menu of several operations and prompts users to enter a selection to
    1) Display list of students' information
    2) Add new student
    3) Update existing student
    4) Print statistics of students' exam scores
    5) Exit program
    Tasks :
    Lorem Ipsum:
    1) add and update students' information, menu logic
    2) Display student information
    Velit Esse:
    1) Design document
    2) print statistics of exams
*/

int main(){
    cout << fixed << setprecision(2);
    cout << "+----------------------------------------------------------+" << '\n';
    cout << "|\tComputer Science and Engineering\t|" << '\n';
    cout << "|\tCSCE 1040 - Computer Science I\t|" << '\n';
    cout << "|\tStudent1 Brian Zhou bxz0001 brianzhou@my.unt.edu\t" << '\n';
    cout << "|\tStudent2 Keshav Ramanuja kr1789 keshavramanuja@my.unt.edu\t" << '\n';
    cout << "|\tStudent3 Kevin Liu kxl0009 kevinliu4@my.unt.edu\t|" << '\n';
    cout << "|\tStudent3 Asher Chen EUID3 euid3@my.unt.edu\t|" << '\n';
    cout << "+----------------------------------------------------------+" << '\n' << '\n' << '\n';

    //chosen item in menu
    int op = -1;  

    //initializing student id, first name, last name, scores vectors
    vector<long> studentID;
    vector<string> firstName;
    vector<string> lastName;
    vector<vector<float>> scores; 

    // repeated manu loop until user chooses 5
    while(op != 5){
        
        //menu
        cout << '\n';
        cout << "+-----------------------More----------------------+" << '\n';
        cout << "| 1. Display list of students' information        |" << '\n';
        cout << "| 2. Add student information                      |" << '\n';
        cout << "| 3. Update student's information                 |" << '\n';
        cout << "| 4. Print statistics of students' exam scores    |" << '\n';
        cout << "| 5. Exit program                                 |" << '\n';
        cout << "***************************************************" << '\n';

        cin >> op;
        if(op == 1){
            if(!studentID.size())
                cout << "Empty list of students." << '\n';
            else{
                cout << "*********************** Students Information ***********************" << '\n';
                cout << "Id      First name      Last name       Exam1       Exam2      Exam3" << '\n';
                cout << "--------------------------------------------------------------------" << '\n';
                for(int i = 0; i < studentID.size(); i++)
                    cout << studentID[i] << '\t' << firstName[i] << '\t' << lastName[i] << '\t' << scores[i][0] << '\t' << scores[i][1] << '\t' << scores[i][2] << '\n';
            }
        }
        else if(op == 2){
            int id; string n; float ex1, ex2, ex3;
            cout << "Enter students information" << '\n';
            cout << "ID: " << '\n';
            cin >> id; studentID.push_back(id);
            cout << "First Name: " << '\n';
            cin.ignore();
            getline(cin, n); firstName.push_back(n);
            cout << "Last Name: " << '\n';
            getline(cin, n); lastName.push_back(n);
            cout << "Exam 1: " << '\n';
            cin >> ex1;
            cout << "Exam 2: " << '\n';
            cin >> ex2;
            cout << "Exam 3: " << '\n';
            cin >> ex3;
            scores.push_back({ex1, ex2, ex3});
            cout << "New student with " << *studentID.rbegin() << " added." << '\n';
        }
        else if(op == 3){
            if(!studentID.size())
                cout << "Empty list of students." << '\n';
            else {
                cout << "Please enter student's ID:" << '\n';
                int id; cin >> id;
                int j = 0;
                while(j < studentID.size() && studentID[j] != id)
                    j++;
                
                if(j == studentID.size())
                    cout << "Student with id " << id << " not found." << '\n';
                else{
                    string n; float ex;
                    cout << "Update student's information:" << '\n';
                    cout << "Id " << id << '\n'; 
                    cout << "First name: " << '\n';
                    cin.ignore();
                    getline(cin, n);
                    firstName[j] = n;
                    cout << "Last name: " << '\n';
                    getline(cin, n);
                    lastName[j] = n;
                    cout << "Exam 1 score:" << '\n';
                    cin >> ex; scores[j][0] = ex;
                    cout << "Exam 2 score:" << '\n';
                    cin >> ex; scores[j][1] = ex;
                    cout << "Exam 3 score:" << '\n';
                    cin >> ex; scores[j][2] = ex;
                    cout << "Student's information with id " << id << " updated." << '\n';
                }
            }
        }
        else if(op == 4)
        {
            if(studentID.empty()) {
                cout << "Empty list of students.\n";
            } 
            else {
                cout << "\n** Students Exam Statistics **\n";
                cout << "Name\t\t\tMean\t\tMinimum\t\tMaximum\n";
                cout << "--------------------------------------------------------------------------\n";

                cout << fixed << setprecision(2);
            }

            
            for(int i = 0; i < studentID.size(); i++) 
            {
                float low = 1e9;
                for(int j = 0; j < 3; j++)
                {
                    if(scores[i][j] < low)
                    {
                        low = scores[i][j];
                    }
                }
                float high = -1e9;
                for(int j = 0; j < 3; j++)
                {
                    if(scores[i][j] > high)
                    {
                        high = scores[i][j];
                    }
                }
                float mean = (scores[i][0] + scores[i][1] + scores[i][2]) / 3;
                string fullName = firstName[i] + " " + lastName[i];

                cout << left << setw(24) << fullName
                     << right << fixed << setprecision(2)
                     << setw(12) << mean
                     << setw(12) << low
                     << setw(12) << high << '\n';
            }
        }
        else if (op == 5) {
            cout << "Thank you for using this program. Goodbye!\n";
        }
        else
        {
            cout << "Invalid selection. Please enter choice 1-5.\n";
        }
    }
}