/*Objective 
Establish the foundation of the University Management System by implementing 
classes, objects, encapsulation, and polymorphism. 
Requirements 
Part A: Classes and Objects 
1. Create the following classes with appropriate attributes: 
o Person (with attributes: name, age, ID, contact information) 
o Student (with attributes: enrollment date, program, GPA) 
o Professor (with attributes: department, specialization, hire date) 
o Course (with attributes: code, title, credits, description) 
o Department (with attributes: name, location, budget) 
2. Implement constructors, destructors, and basic getter/setter methods for each 
class. 
3. Create a test program that instantiates at least two objects of each class. 
Part B: Encapsulation 
1. Refactor all classes to make attributes private. 
2. Implement public getter and setter methods with proper validation: 
o Age should be positive and reasonable 
o GPA should be between 0.0 and 4.0 
o Course credits should be positive 
o Names should not be empty 
3. Create these encapsulated classes: 
o GradeBook: Manages grades for a course (stores student IDs and their 
grades) 
o EnrollmentManager: Handles student enrollment in courses (tracks 
which students are in which courses) 
4. Implement methods in these classes that encapsulate complex operations: 
o GradeBook: calculateAverageGrade(), getHighestGrade(), 
getFailingStudents() 
o EnrollmentManager: enrollStudent(), dropStudent(), 
getEnrollmentCount() 
Part C: Polymorphism 
1. Add a displayDetails() method to the Person class. 
2. Override the displayDetails() method in both Student and Professor classes. 
3. Implement a calculatePayment() method in Person and override it in 
appropriate subclasses. 
4. Create a test function that accepts a Person pointer/reference and calls these 
polymorphic methods. 
5. Create an array of Person pointers containing both Student and Professor 
objects, and demonstrate polymorphic behavior by iterating through the array.*/

#include<iostream>
#include<vector>
using namespace std;
class Person{
    public:
    string name;
    int age;
    string id;
    long long contact;
    public:
    //parameterized constructor
    Person(string n,int a,string i,long long c){
        setName(n);
        setAge(a);
        id=i;
        contact=c;
    }
    //default constructor
    Person(){
        name="unknown";
        age=0;
        id="0";
        contact=0;
    }
    //setter function
    void inputperson(string n,int a,string i,long long c){
        setName(n);
        setAge(a);       
        id=i;
        contact=c;

    }
    //Age should be +ve or reasonable
    void setAge(int a){
        if(a>0&&a<100){
            age=a;}
        else 
        cout<<"Invalid age!"<<endl;
    }
    //name should not be empty
    void setName(string n){
        if(!n.empty()){
        name=n;}
        else 
        cout<<"Name cannot be empty!"<<endl;
    }
    
    void displayDetails(){
        cout<<"Name:"<<name<<endl<<"age:"<<age<<endl<<"ID:"<<id<<endl<<"contact no:"<<contact<<endl;
    }
    // Virtual function to calculate payment (will be overridden in subclasses)
    virtual double calculatePayment(){
        return 0.0; // Base class doesn't have a payment, returns 0.
    }

    //destructor 
    ~Person(){
        cout<<"Destructor called for Person:"<<name<<endl;
    }
};
class Department{
    private:
    string named;
    string location;
    double budget;
    public:
    //default constructor
    Department(){
        named="unknown";
        location="unknown";
        budget=0;
    }
    //parameterized constructor
    Department(string n,string l,double b){
        named=n;
        location=l;
        budget=b;
    }
    //setter function
    void inputdepartment(string n,string l,double b){
        named=n;
        location=l;
        budget=b;
    }
    void displaydep(){
        cout<<"name of department:"<<named<<endl<<"location:"<<location<<endl<<"budget:"<<budget<<endl;
    }
    //destructor
    ~Department(){
        cout<<"Destructor called for Department:"<<named<<endl;
    }
};
class Student:public Person{
    private:
    string edate;
    string program;
    double gpa;
    public:
    //parameterized constructor
    Student(string e,string p,double g){
        edate=e;
        program=p;
        setGPA(g);
    }
    
    //default constructor
    Student() : Person() {
        edate="0";
        program="unknown";
        gpa=0.0;
    }
    //setter function
    void inputstudent(string n,int a,string i,long long c,string e,string p,double g){
        name=n;
        age=a;
        id=i;
        contact=c;
        edate=e;
        program=p;
        setGPA(g);
    }
    void setGPA(double g){
        if(g>=0.0&&g<=4.0){
            gpa=g;}
        else 
        cout<<"Invalid GPA!"<<endl;
    }
    
    void displayDetails(){
        Person::displayDetails();  // Calls the base class displayDetails
         cout<<"enrollment date:"<<edate<<endl<<"program:"<<program<<endl<<"gpa:"<<gpa<<endl;
    }
    double calculatePayment() override {
        // Assuming payment is based on a stipend for the student
        return 500.0; // Example stipend
    }
    // destructor
    ~Student(){
        cout<<"Destructor called for Student in program:"<<program<<endl;
    }
};
class Professor:public Person{
   string spec;
   string hiredate;
   int salary;
   public:
   //default constructor
   Professor():Person()
   {
    spec="0";
    hiredate="0";
    salary=0;
   }
   Professor(string n,int a,string i,long long c,string s,string h,int sal)
    {
     name=n;
     age=a;
     id=i;
     contact=c;
     spec=s;
     hiredate=h;
     salary=sal;
    }
    //setter function
    void inputprofessor(string n,int a,string i,long long c,string s,string h,int sal){
        name=n;
        age=a;
        id=i;
        contact=c;
        spec=s;
        hiredate=h;
        salary=sal;
    }

   void displayDetails(){
    Person::displayDetails();
    cout<<"specialisation:"<<spec<<endl<<"hire date:"<<hiredate<<endl;
   }
   double calculatePayment() override {
    // Assuming the professor's payment is based on salary
    return salary;
   }
   // destructor
   ~Professor(){
    cout<<"Destructor called for Professor with specialization: "<<spec<<endl;
}
};
class Course{
    string code;
    string title;
    long long credit;
    string description;
    public:
    //default condtructor
    Course(){
        code="0";
        title="unknown";
        credit=0;
        description="unknown";
    }
    //parameterized constructor
    Course(string co,string t,long long cr,string d){
        code=co;
        title=t;
        setCredit(cr);
        description=d;
    }
    //setter function
    void inputcourse(string co,string t,long long cr,string d){
        code=co;
        title=t;
        setCredit(cr);
        description=d;
    }
    void setCredit(long long cr){
        if(cr>0){
            credit=cr;}
        else 
        cout<<"Credit must be positive!"<<endl;
    }
    
    void displaycourse(){
        cout<<"code:"<<code<<endl<<"title:"<<title<<endl<<"credit:"<<credit<<endl<<"description:"<<description<<endl;
    }
    // destructor
    ~Course(){
        cout<<"Destructor called for Course: "<<code<<endl;
    }
};
class GradeBook {
    private:
        string courseCode;
        vector<string>studentIDs;
        vector<double>grades;
    
    public:
       //parameterized constructor
        GradeBook(string courseCode) : courseCode(courseCode) {}
    
        void addGrade(string studentID,double grade) {
            if (grade>=0.0&&grade<=4.0){
                studentIDs.push_back(studentID);
                grades.push_back(grade);
            } 
            else {
                cout<<"Invalid grade!. Grade must be between 0.0 and 4.0."<<endl;
            }
        }
    
        void displayGrades(){
            cout<<"Grades for course: "<<courseCode<<endl;
            for(size_t i=0;i<studentIDs.size();i++){
                cout<<"Student ID: "<<studentIDs[i]<<"Grade: "<<grades[i]<<endl;
            }
        }
    
        double getGrade(string studentID) {
            for (size_t i=0;i<studentIDs.size();i++){
                if(studentIDs[i]==studentID){
                    return grades[i];
                }
            }
            cout<<"Grade not found for student "<<studentID<<endl;
            return -1.0;
        }
        double calculateAverageGrade() {
            if (grades.empty()) return 0.0;
            double sum = 0.0;
            for (double grade : grades) {   
                sum += grade;
            }
            return sum / grades.size();
        }
    
        double getHighestGrade() {
            if (grades.empty()) return -1.0;
            double highest = grades[0];
            for (double grade : grades) {
                if (grade > highest) highest = grade;
            }
            return highest;
        }
    
        void getFailingStudents() {
            cout << "Failing Students (Grade < 2.0):" << endl;
            for (size_t i = 0; i < studentIDs.size(); i++) {
                if (grades[i] < 2.0) {
                    cout << "Student ID: " << studentIDs[i] << " Grade: " << grades[i] << endl;
                }
            }
        }
    };
    
    class EnrollmentManager {
    private:
        vector<string> courseCodes;
        vector<vector<string>> enrolledStudents;
    
    public:
        void enrollStudent(string courseCode, string studentID) {
            for (size_t i = 0; i < courseCodes.size(); i++) {
                if (courseCodes[i] == courseCode) {
                    enrolledStudents[i].push_back(studentID);
                    return;
                }
            }
            courseCodes.push_back(courseCode);
            enrolledStudents.push_back({studentID});
        }
        void dropStudent(string courseCode, string studentID) {
            for (size_t i = 0; i < courseCodes.size(); i++) {
                if (courseCodes[i] == courseCode) {
                    vector<string>& students = enrolledStudents[i];
                    size_t newSize = students.size();
                    for (size_t j = 0; j < newSize; ++j) {
                        if (students[j] == studentID) {
                            cout << "Student " << studentID << " dropped from course " << courseCode << endl;
                            for (size_t k = j; k < newSize - 1; ++k) {
                                students[k] = students[k + 1];
                            }
                            newSize--;
                            students.pop_back();
                            return;
                        }
                    }
                }
            }
            cout << "Student or course not found." << endl;
        }
        void displayEnrollments(string courseCode) {
            for (size_t i = 0; i < courseCodes.size(); i++) {
                if (courseCodes[i] == courseCode) {
                    cout << "Enrollments for course: " << courseCode << endl;
                    for (const string& studentID : enrolledStudents[i]) {
                        cout << "Student ID: " << studentID << endl;
                    }
                    return;
                }
            }
            cout << "No enrollments for this course." << endl;
        }
        int getEnrollmentCount(string courseCode) {
            for (size_t i = 0; i < courseCodes.size(); i++) {
                if (courseCodes[i] == courseCode) {
                    return enrolledStudents[i].size();
                }
            }
            return 0;
        }
    };
    //polymorphism
       // Test function that accepts a Person pointer and calls polymorphic method
    void testPersonPayment(Person* person) {
    cout << "Payment: " << person->calculatePayment() << endl;
    }
    // Function to demonstrate polymorphic behavior with array of Person pointers
    void demonstratePolymorphism(Person* persons[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Payment for person " << i + 1 << ": " << persons[i]->calculatePayment() << endl;
    }
    
    }

int main(){
    Person p1;
    Person p2;
    p1.inputperson("",18,"24csu214",99343468201);
    p1.displayDetails();
    p2.inputperson("tanisha",18,"24csu",8700732768);
    p2.displayDetails();
    cout<<endl;
    Student s1;
    Student s2;
    s1.inputstudent("tanisha",18,"24csu214",9959758201,"12/03/2024","btech",4);
    s1.displayDetails();
    s2.inputstudent("tanu",17,"24csu215",9950600000,"14/03/2025","bba",5);
    s2.displayDetails();
    cout<<endl;
    Professor pr1;
    Professor pr2;
    pr1.inputprofessor("tanisha",35,"24tec45",943583475,"ai/ml","21/03/2024",10000);
    pr1.displayDetails();
    pr2.inputprofessor("tanu",32,"24tec75",94465785,"data science","25/03/2025",30000);
    pr2.displayDetails();
    cout<<endl;
    Course c1;
    Course c2;
    c1.inputcourse("XYZ","abc",5,"abcd");
    c1.displaycourse();
    c2.inputcourse("ABC","xyz",4,"ab");
    c2.displaycourse();
    cout<<endl;
    Department d1;
    Department d2;
    d1.inputdepartment("cse","first floor",5000000);
    d1.displaydep();
    d2.inputdepartment("cse","second floor",30000);
    d2.displaydep();

    // Create EnrollmentManager and GradeBook objects
     EnrollmentManager em;
     GradeBook gb("CS101");
 
     // Enroll students
     em.enrollStudent("CS101", "24CSU101");
     em.enrollStudent("CS101", "24CSU102");
     em.enrollStudent("CS101", "24CSU103");
 
     // Display enrollments
     cout << "Enrollment for CS101:" << endl;
     em.displayEnrollments("CS101");
     cout << "Enrollment Count: " << em.getEnrollmentCount("CS101") << endl;
 
     // Drop a student
     em.dropStudent("CS101", "24CSU102");
     cout << "Updated Enrollment for CS101:" << endl;
     em.displayEnrollments("CS101");
 
     // Add grades
     gb.addGrade("24CSU101", 3.5);
     gb.addGrade("24CSU102", 1.8);
     gb.addGrade("24CSU103", 4.0);
 
     // Display grades
     cout << "Grades for CS101:" << endl;
     gb.displayGrades();
 
     // Calculate average grade
     cout << "Average Grade: " << gb.calculateAverageGrade() << endl;
 
     // Get highest grade
     cout << "Highest Grade: " << gb.getHighestGrade() << endl;
 
     // Display failing students
     gb.getFailingStudents();

     // Test the polymorphic behavior
    cout << "Testing with Person pointer (Base class):" << endl;
    testPersonPayment(&p1);  // Should return 0.0 for Person
    testPersonPayment(&p2);  // Should return 0.0 for Person

    cout << "\nTesting with Student pointer:" << endl;
    testPersonPayment(&s1);  // Should return 500.0 for Student
    testPersonPayment(&s2);  // Should return 500.0 for Student

    cout << "\nTesting with Professor pointer:" << endl;
    testPersonPayment(&pr1); // Should return 8000.0 for Professor
    testPersonPayment(&pr2); // Should return 10000.0 for Professor

    Person* persons[4];
    persons[0] = &s1;
    persons[1] = &s2;
    persons[2] = &pr1;
    persons[3] = &pr2;

    // Demonstrate polymorphic behavior
    demonstratePolymorphism(persons, 4);
   return 0;
}
