/*  Sean Yee and Surya Dantuluri
    CIS 22B Spring 2019
    Laboratory Assignment C
    Problem C2
    In Problem C2 we will add constructors to the Car class.
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

        Car(string reportingmark,string kind,string destination,bool load,int carnumber)
        {
            setup(reportingmark,kind,destination,load,carnumber);
        }

        Car(const Car&)
        {
            setup(reportingmark,kind,destination,load,carnumber);
        }
        ~Car(){}
        void setup(string reportingmark,string kind,string destination,bool load,int carnumber);
        void output();
};

Car::Car()
{
    cout << setw(16) << left << "Reportingmark:" << "" << endl;
    cout << setw(16) << left << "Carnumber:" << "0" << endl;
    cout << setw(16) << left << "Kind:" << "other" << endl;
    cout << setw(16) << left << "loaded:" << "false" << endl;
    cout << setw(16) << left << "Destination:" << "None" << endl;
}

void input(string &reportingmark,int&carnumber,string&kind,bool&load,string&destination);

/**********main**********
Making car instances given set parameters and determining output
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
    car2 = car1;
    car2.output();

    cout << endl << endl << "--------------------------" << endl << "CAR 3" << endl << endl;
    Car Car3;
    cout << endl << endl;


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
    cout << setw(16) << left << "Reportingmark: " << Car::reportingmark << endl;
    cout << setw(16) << left << "Car number: " << Car::carnumber << endl;
    cout << setw(16) << left << "Kind: " << Car::kind << endl;
    cout << setw(16) << left << "Loaded: " << boolalpha << Car::load << endl;
    cout << setw(16) << left << "Destination: " << Car::destination;
}

/*Executive Result:
Reportingmark :SP
Carnumber :34567
Kind (business, maintenance, or other) :business
Loaded (true/false):true
Destination :Salt Lake City


--------------------------
CAR 1

Reportingmark: 	SP
Car number:    	34567
Kind:          	business
Loaded:        	true
Destination:    	Salt Lake City

--------------------------
CAR 2

Reportingmark:  	SP
Car number:     	34567
Kind:           	business
Loaded:         	true
Destination:    	Salt Lake City

--------------------------
CAR 3

Reportingmark:
Carnumber:      	0
Kind:           	other
loaded:         	false
Destination:    	None



Process returned 0 (0x0)   execution time : 12.976 s
*/

