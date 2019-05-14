/*  Sean Yee and Surya Dantuluri
    CIS 22B Spring 2019
    Laboratory Assignment C
    Problem C3
    In Problem C3 we will add an operator== friend function for the Car class.
*/

#include <iostream>
#include<string>
#include <iomanip>

using namespace std;

class Car
{
private:
    string reportingmark;
    int carnumber;
    string kind;
    bool load;
    string destination;

public:
    Car();
    Car(string reportingmark, string kind, string destination, bool load,int carnumber)
    {
        setup(reportingmark,kind,destination,load,carnumber);
    }
    Car(const Car &copy)
    {
        reportingmark=copy.reportingmark;
        kind=copy.kind;
        destination=copy.destination;
        load=copy.load;
        carnumber=copy.carnumber;
    }
    ~Car()
    {};

    friend bool operator == (const Car &car1,const Car &car2);

    void setup(string reportingmark,string kind,string destination,bool load,int carnumber);
    void output();
};

Car::Car()
{
   reportingmark = "";
   carnumber = 0;
   kind = "other";
   load = false;
   destination= "NONE";
}

void input(string &reportingmark,int&carnumber,string&kind,bool&load,string&destination);

/**********main**********
Making car instances and determining output
*************************/
int main()
{
    string reportingmark,kind,destination;
    bool load;
    int carnumber;
    input(reportingmark,carnumber,kind,load,destination);
    cout << endl << endl << "--------------------------" << endl << "CAR 1" << endl << endl;
    Car car1(reportingmark,kind,destination,load,carnumber);
    car1.output();
    cout << endl << endl << "--------------------------" << endl << "CAR 2" << endl << endl;
    Car car2(car1);
    car2.output();
    cout << endl << endl << "--------------------------" << endl << "CAR 3" << endl << endl;
    Car Car3;
    Car3.output();
    cout << endl << endl;
    if (car1==car2)
    {
        cout << "car1 is the same car as car2\n";
    }
    else
    {
        cout << "car1 is not the same car as car2\n";
    }
    if (car2==Car3)
    {
        cout << "car2 is the same car as car3\n";
    }
    else
    {
        cout << "car2 is not the same car as car3\n";
    }

    return 0;
}

/**********input**********
Takes the reportingMark, carNumber, kind, loaded, and destination
 *************************/
void input(string &reportingmark,int&carnumber,string&kind,bool&load,string&destination)
{
    cout << "Reportingmark :";
    cin >> reportingmark;
    if(reportingmark.length()<2||reportingmark.length()>4)
    {
        cout << "Error";
    }
    else
    {
        cout << "Carnumber :";
    }
    cin >> carnumber;

    cout << "Kind (business, maintenance, or other) :";
    cin >> kind;
    while (kind != "business" && kind != "maintenance" && kind != "other")
    {
       cout << "Options for Kind are: business, maintenance, or other." << endl;
       cout << "Please enter Kind (business, maintenance, or other): ";
       cin >> kind;
    }

    cout << "Loaded (true/false):";
    cin >> boolalpha >> load;
    if(load == false)
    {
        cout << "Please input a Destination (if none, type NONE): ";
        getline(cin,destination);
    }
    else (load == true);
    {
        cin.ignore();
        cout << "Destination :";
        getline(cin,destination);
    }
}

/**********setup**********
Puts the data into the data structure
 *************************/
void Car::setup(string reportingmark,string kind,string destination,bool load,int carnumber)
{
   Car::reportingmark=reportingmark;
   Car::kind=kind;
   Car::load=load;
   Car::destination=destination;
   Car::carnumber=carnumber;
}

/**********output**********
Prints the member data in a neat format
 *************************/
void Car::output()
{
    cout << setw(16) << left << "Reportingmark :" << Car::reportingmark << endl;
    cout << setw(16) << left << "Car number :" << Car::carnumber << endl;
    cout << setw(16) << left << "Kind :" << Car::kind << endl;
    cout << setw(16) << left << "Loaded :" << boolalpha << Car::load << endl;
    cout << setw(16) << left << "Destination :" << Car::destination << endl;
}

/**********bool operator == **********
The two objects are equivalent if they have the same reportingMark and number
(do not look at the kind, loaded, and destination fields).
 *************************/
bool operator ==(const Car &a, const Car &b)
{
    if((a.reportingmark == b.reportingmark)&&(a.carnumber == b.carnumber))
        return true;
    else
        return false;
}
/* Executive Result:

Reportingmark :SP
Carnumber :34567
Kind (business, maintenance, or other) :business
Loaded (true/false):true
Destination :Salt Lake City


--------------------------
CAR 1

Reportingmark : 	SP
Car number :    	34567
Kind :          	business
Loaded :        	true
Destination :   	Salt Lake City


--------------------------
CAR 2

Reportingmark : 	SP
Car number :    	34567
Kind :         	business
Loaded :        	true
Destination :   	Salt Lake City


--------------------------
CAR 3

Reportingmark :
Car number :    	0
Kind :         	other
Loaded :       	false
Destination :   	NONE


car1 is the same car as car2
car2 is not the same car as car3
*/

