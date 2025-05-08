/*assignment 3 (assignment 2 including changed required in assignment 3) 
Objective 
Extend the University Management System by implementing inheritance hierarchies 
and establishing relationships between classes. 
Requirements 
Part A: Inheritance 
1. Create a proper inheritance hierarchy: 
o Make Student and Professor inherit from Person 
o Create UndergraduateStudent and GraduateStudent classes that 
inherit from Student 
o Create AssistantProfessor, AssociateProfessor, and FullProfessor 
classes that inherit from Professor 
2. Implement appropriate constructors that call parent constructors. 
3. Override methods in derived classes: 
o Override displayDetails() in all derived classes 
o Override calculatePayment() to reflect different payment structures 
4. Add appropriate attributes to derived classes: 
o UndergraduateStudent: major, minor, expected graduation date 
o GraduateStudent: research topic, advisor, thesis title 
o Professor subclasses: different attributes related to tenure, publishing 
requirements, etc. 
Part B: Composition and Aggregation 
1. Implement relationships between classes: 
o Department contains multiple Professor objects (composition) 
o Course has one Professor as the instructor (aggregation) 
o Student can be enrolled in multiple Course objects (aggregation) 
o GraduateStudent has a Professor as an advisor (aggregation) 
2. Create a University class that: 
o Contains multiple Department objects 
o Provides methods to add/remove departments 
o Can retrieve professors and courses across all departments 
3. Implement a Classroom class and establish a relationship with Course. 
4. Create a Schedule class that manages time slots for courses and classrooms. 
Part C: Method Overriding and Extension 
1. Override the calculatePayment() method in all Professor subclasses to 
account for: 
o Base salary 
o Years of service 
o Academic rank 
o Research grants 
2. Add methods to GraduateStudent to track teaching and research 
assistantships. 
3. Implement method overriding for any other appropriate methods in your 
inheritance hierarchy.
*/
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
class Professor:public Person{
    public:
   string spec;
   string hiredate;
   int salary;
   
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
  return 10000;
   }
   // destructor
   ~Professor(){
    cout<<"Destructor called for Professor with specialization: "<<spec<<endl;
}
};
class Department{
    public:
    string named;
    string location;
    double budget;
    vector<Professor> professors;
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

    void addProfessor(const Professor& prof) {
        professors.push_back(prof);
    }
    void displaydep(){
        cout<<"name of department:"<<named<<endl<<"location:"<<location<<endl<<"budget:"<<budget<<endl;
        if (!professors.empty()) {
            cout << "Professors:" << endl;
            for (const auto& prof : professors) {
                cout << " - " << prof.name << ", Specialization: " << prof.spec << endl;}
            }

    }
    //destructor
    ~Department(){
        cout<<"Destructor called for Department:"<<named<<endl;
    }
};
class Course{
    public:
    string code;
    string title;
    long long credit;
    string description;
    Professor* instructor; 
    public:
    //default condtructor
    Course(){
        code="0";
        title="unknown";
        credit=0;
        description="unknown";
        instructor = nullptr;
    }
    //parameterized constructor
    Course(string co,string t,long long cr,string d,Professor* instr = nullptr){
        code=co;
        title=t;
        setCredit(cr);
        description=d;
        instructor=instr;
    }
    //setter function
    void inputcourse(string co,string t,long long cr,string d,Professor* instr = nullptr){
        code=co;
        title=t;
        setCredit(cr);
        description=d;
        instructor=instr;
    }
    void setCredit(long long cr){
        if(cr>0){
            credit=cr;}
        else 
        cout<<"Credit must be positive!"<<endl;
    }
    
    void displaycourse(){
        cout<<"code:"<<code<<endl<<"title:"<<title<<endl<<"credit:"<<credit<<endl<<"description:"<<description<<endl;
        if(instructor!=nullptr){
            cout<<"Instructor:"<<instructor->name<<endl;
        } else{
            cout<<"Instructor: None"<<endl;
        }
    }
    // destructor
    ~Course(){
        cout<<"Destructor called for Course: "<<code<<endl;
    }
    string getCode() {
        return code;
    }
};
class Student:public Person{
    protected:
    string edate;
    string program;
    double gpa;
    vector<Course*> enrolledCourses; // Aggregation: Student enrolled in multiple courses
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
    void enrollInCourse(Course* course) {
        enrolledCourses.push_back(course);
    }
    
    void displayDetails(){
        Person::displayDetails();  // Calls the base class displayDetails
         cout<<"enrollment date:"<<edate<<endl<<"program:"<<program<<endl<<"gpa:"<<gpa<<endl;
         if (!enrolledCourses.empty()) {
            cout << "Enrolled courses:" << endl;
            for (auto c : enrolledCourses) {
                cout << " - " << c->getCode() << " (" << c->title << ")" << endl;
            }
        }
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
    class Undergraduate:public Student{
        string majordate;
        string minordate;
        string graduationdate;
      //default constructor
      Undergraduate():Student(){
        majordate="0";
        minordate="0";
        graduationdate="0";
      }
    //parameterized constructor
      Undergraduate(string edta,string programe,double gpa,string majordate,string minordate,string graduationdate)
      :Student(edta,program,gpa),majordate(majordate),minordate(minordate),graduationdate(graduationdate)
      {}
      void displayDetails(){
        Student::displayDetails();
        cout<<"major date:"<<majordate<<endl<<"minor date:"<<minordate<<endl<<"expected graduation date:"<<graduationdate<<endl;
      }
      double calculatePayment() override {
        // Assuming payment is based on a stipend for the student
        return 1000.0; // Example stipend
    }
    };
    class Graduate:public Student{
        string researchtopic;
        string advisor;
        string thesistitle;
        Professor* advis; // Aggregation: Graduate student has a Professor advisor
        bool hasTeachingAssistantship; // Track if the student has a teaching assistantship
        bool hasResearchAssistantship; // Track if the student has a research assistantship    

     public:
     //default constructor
     Graduate():Student(){
        researchtopic="0";
        advisor="0";
        thesistitle="0";
        advisor = nullptr;
        hasTeachingAssistantship = false; // Default to no TA
        hasResearchAssistantship = false; // Default to no RA
     }
     //parameterized constructor
     Graduate(string edta, string programe, double gpa, string resarchtopic, string advisor, string thesistitle, Professor* adv, bool ta = false, bool ra = false)
     : Student(edta, programe, gpa), researchtopic(resarchtopic), advisor(advisor), thesistitle(thesistitle), advis(adv), hasTeachingAssistantship(ta), hasResearchAssistantship(ra) {}

       void displayDetails() {
        Student::displayDetails();
        cout<<"total research topic:"<<researchtopic<<endl<<"Advisor:"<<(advis?advis->name:"None")<<endl<<"thesis title:"<<thesistitle<<endl;
       }
       double calculatePayment() override {
        double payment = 1500.0; // Base stipend for graduate students
        if (hasTeachingAssistantship) {
            payment += 500.0; // Additional payment for TA
        }
        if (hasResearchAssistantship) {
            payment += 700.0; // Additional payment for RA
        }
        return payment;
       }
    };
    class Assistantprofessor:public Professor{
        private:
       int requiredPublications;
       int completedPublications;
       double basesalary;
       int yearofservice;
       string academicrank;
       int researchgrants;
       public:
      //default constructor
      Assistantprofessor():Professor(){
         requiredPublications=0;
         completedPublications=0;
      }
      //parameterized constructor
      Assistantprofessor(string s,string h,int sal,int reqpub,int comppub){
        spec=s;
        hiredate=h;
        salary=sal;
        requiredPublications=reqpub;
       completedPublications=comppub;
       
      }
      void diaplayDetailes(){
        Professor::displayDetails();
        cout<<"required Publications:"<<requiredPublications<<endl<<"completed Publications"<<completedPublications<<endl;
      }
      
     double calculatePayment() override {
        // Base payment calculation logic
        double payment = basesalary;
        
        // Example: Adding a bonus based on years of service
        payment += yearofservice * 100;

        // Example: Adjusting based on academic rank
            payment += 5000;
        
        // Research grant adjustment
        payment += researchgrants * 0.1;

        return payment;
    }
    };
    class Associateprofessor:public Professor{
        bool hasTenure;
       int studentsMentored;
       double basesalary;
       int yearofservice;
       string academicrank;
       int researchgrants;
       public:
      //default constructor
      Associateprofessor():Professor(){
        hasTenure=0;
        studentsMentored=0;
      }
      //parameterized constructor
      Associateprofessor(string s,string h,int sal,bool hasten,int sm){
        spec=s;
        hiredate=h;
        salary=sal;
        hasTenure=hasten;
        studentsMentored=sm;
    }
    void displayDetails(){
       Professor::displayDetails();
       cout<<hasTenure<<" has tenure."<<endl<<"Total students mentored:"<<studentsMentored<<endl;
    }
        
        double calculatePayment() override {
        // Base payment calculation logic
        double payment = basesalary;
        
        // Example: Adding a bonus based on years of service
        payment += yearofservice * 100;

        // Example: Adjusting based on academic rank
        payment += 8000;
        
        // Research grant adjustment
        payment += researchgrants * 0.1;

        return payment;
    }
    
    };
    class Fullprofessor:public Professor{
        int researchGrants;
        string leadershipRole;
        double basesalary;
       int yearofservice;
       string academicrank;
       int researchgrants;
       //default constructor
      Fullprofessor():Professor(){
        researchGrants=0;
        leadershipRole="unknowm";
      }
      //parameterized constructor
      Fullprofessor(string s,string h,int sal,int resgr,string leadrole){
        spec=s;
        hiredate=h;
        salary=sal;
        researchGrants=resgr;
        leadershipRole=leadrole;
      }
      void displayDetails(){
        Professor::displayDetails();
        cout<<"total research grants:"<<researchGrants<<endl<<"leadership role:"<<leadershipRole<<endl;
      }
      double calculatePayment() override {
        // Base payment calculation logic
        double payment = basesalary;
        
        // Example: Adding a bonus based on years of service
        payment += yearofservice * 100;

        // Example: Adjusting based on academic rank
        payment += 10000;
        
        // Research grant adjustment
        payment += researchgrants * 0.1;

        return payment;
    }
    };
    class University{
        string names;
        vector<Department>departments;
        public:
    University(const string& universityName) : names(universityName) {}

    void addDepartment(const Department& department) {
        departments.push_back(department);
    }

    void removeDepartment(const std::string& departmentName) {
        for (auto it = departments.begin(); it != departments.end(); ++it) {
            if (it->named == departmentName) {
                departments.erase(it);
                break;
            }
        }
    }
    vector<Professor> getAllProfessors() const {
        vector<Professor> professors;
        for ( auto& department: departments) {
            // Assuming each Department has a method getProfessors()
            // professors.insert(professors.end(), department.getProfessors().begin(), department.getProfessors().end());
        }
        return professors;
    }

    vector<Course> getAllCourses() const {
        vector<Course> courses;
        for (const auto& department : departments) {
            // Assuming each Department has a method getCourses()
            // courses.insert(courses.end(), department.getCourses().begin(), department.getCourses().end());
        }
        return courses;
    }

    void displayUniversityInfo() const {
        cout<<"University: "<<names<<endl;
        for (const auto& department : departments) {
            cout<<"Department:"<<department.named<<endl;
            cout<<"Location:"<<department.location<<endl;
            cout<<"Budget:"<< department.budget<<endl;
        }
    }
    };
    class Classroom {
        public:
            string roomNumber;
            int capacity;
            vector<Course> courses;
        
        public:
            Classroom(const string& roomNum,int cap):roomNumber(roomNum),capacity(cap) {}
        
            void addCourse(const Course& course) {
                courses.push_back(course);
            }
        
             void displayClassroomInfo() const {
                cout<<"Room: "<<roomNumber<<", Capacity: "<<capacity<<endl;
                cout<<"Courses in this room: "<<endl;
               for(auto& course:courses){
                cout<<"code:"<<course.code<<endl;
                cout<<"title:"<<course.title<<endl;
                cout<<"credit:"<<course.credit<<endl;
                cout<<"description:"<<course.description<<endl;

               }
            }
        };
        class Schedule {
        private:
        class TimeSlot {
            public:
                string time;
                Course course;
                Classroom classroom;
            
            public:
                TimeSlot(const string& t, const Course& c, const Classroom& cl)
                    : time(t), course(c), classroom(cl) {}
            
                string getTime() const { return time; }
                Course getCourse() const { return course; }
                Classroom getClassroom() const { return classroom; }
            };
            
            vector<TimeSlot> timeSlots;
        public:
        void addTimeSlot(const string& time, const Course& course, const Classroom& classroom) {
                    timeSlots.push_back({time, course, classroom});
                }
            
         void displaySchedule() const {
        cout << "Schedule: " <<endl;
        for (const auto& slot : timeSlots) {
        cout<<"Time: "<< slot.time <<endl;
        cout<<"Course: "<< slot.course.title << " (" << slot.course.code<< ")"<<endl;
        cout<<"Room: "<< slot.classroom.roomNumber <<endl;
        
                  }
                }
            };
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
     // Create Professors
    /* Professor prof1("John Smith", 45, "P001", 1234567890, "AI/ML", "2010-08-01", 80000);
     Professor prof2("Jane Doe", 50, "P002", 9876543210, "Data Science", "2008-05-15", 90000);
     // Create Department and add Professors
     Department dep("Computer Science", "2nd Floor", 2500000);
     dep.addProfessor(prof1);
     dep.addProfessor(prof2);
     // Display Department details and Professors
     dep.displaydep();
 
     cout << endl;
    // Create Courses with Professors as instructors
    Course course1("CS101", "Intro to Programming", 4, "Learn the basics of programming.",&prof1);
    Course course2("CS201", "Data Structures", 3, "Study of data",&prof2);*/
    
    // Create a Graduate student
    Professor* advisor = new Professor("Dr. Smith", 45, "P001", 1234567890, "AI/ML", "2010-08-01", 80000);
    Graduate gradStudent("1/02/2025", "Computer Science", 3.8, "Machine Learning", "Dr. Smith", "Deep Learning Thesis", advisor, true, false);

    // Display details
    gradStudent.displayDetails();
    // Calculate payment
    cout << "Payment: " << gradStudent.calculatePayment() << endl;
    // Clean up
    delete advisor;

   return 0;
}
