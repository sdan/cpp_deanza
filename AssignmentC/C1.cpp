/*  Sean Yee and Surya Dantuluri 
    CIS 22B Spring 2019
    Laboratory Assignment C
    Problem C1
    In Problem C1 we will start building the Car class.
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
        void setup(string reportingmark,int carnumber,bool load,string kind,string destination);
        void output();
};

void input(string &reportingmark,int&carnumber,string&kind,bool&load,string&destination);

/**********main**********
Makes pointer pointing to Car object and uses parameters to point data to Car object
*************************/
int main()
{
    Car *prt;
    prt=new Car;

    string reportingmark;
    bool load;
    int carNumber;
    string kind;
    string destination;

    input(reportingmark,carNumber,kind,load,destination);
    prt->setup(reportingmark,carNumber,load,kind,destination);
    cout << endl << endl << "--------------------------------------" << endl <<endl;

    prt->output();
    delete prt;

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

