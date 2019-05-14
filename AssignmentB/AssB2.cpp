/*
Surya Dantuluri
CIS 22B
Spring 2019
Assignment A
Problem B2
Uses class to contain methods needed to modify variables.
*/
#import <iostream>
#import <string>
#import <cmath>
using namespace std;

const double PI = 3.14159265358979323846;

/* ******************** Cone ********************
 Create Cone class that has private and public access
 specifiers for data members.
 */
class Cone 
{
	private:
	double height;
	double radius;

	public:
    
    /* ******************** setUp ********************
     Sets variable of struct's values from the user inputted values.
     */
	void setUp(double &h, double &r)
	{
		height = h;
		radius = r;
	}

    /* ******************** getVolume ********************
     Returns volume of the ptr pointer which points to Cone struct.
     It uses the volume formula and the variables of the pointer.
     */
	double getVolume()
	{
		return PI*pow(radius, 2.0)*(height)/3;
	}
    
    /* ******************** output ********************
     Outputs heights, radius, and volume of a pointer named ptr,
     */
	void output(Cone *ptr)
	{
		double volume = getVolume();
		cout<<"Height: "<<height<<"\n"<<"Radius: "<<radius<<"\n"<<"Volume: "<<volume<<"\n";
	}


};

void input(double &, double &);

/* ******************** main ********************
 Intializes Cone pointer variable and calls input, setup, and output functions.
 Also deletes the Cone pointer.
 */
int main()
{
	Cone *ptr;
	double height, radius;
	ptr = new Cone;
	input(height,radius);
	ptr->setUp(height,radius);
	ptr->output(ptr);
	delete ptr;

	return 0;

}

/* ******************** input ********************
 Asks user for height and radius.3
 */
void input(double &height,double &radius)
{
	cout<<"Enter height: ";
	cin>>height;
	cout<<"Enter radius: ";
	cin>>radius;
	cout<<"\n";
}





