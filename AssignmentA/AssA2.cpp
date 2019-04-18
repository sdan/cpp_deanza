/*
Surya Dantuluri
CIS 22B
Spring 2019
Assignment A
Problem A2
Executes several string exercises using getline, find, at, find_last_of,
erase, and append functions.
*/
#import <iostream>
#import <string>
using namespace std;
void exercises();


int main()
{
	exercises();
	return 0;
}

/* ******************** exercises ******************** 
Reads string, appends string, finds characters in string, finds first 
'h' character in string, changes first 'h' in string to 'J' and finds
last 'l' in string. Also erases characters following the last 'l' character.
*/
void exercises()
{
	string string1;
	cout<<"Enter a string: ";
	getline(cin, string1);
	cout<<"Exercise 1\n"<<string1<<"\n";

	string string2 = string1;
	string2 += " sleepy heads";
	cout<<"Exercise 2\n"<<string2<<endl;

	string string3 = "bellow cello fellow hello mellow Novello Othello pillow Rollo solo yellow";
	int firstH = string3.find("h");
	cout<<"Exercise 3\n"<<firstH<<"\n";

	string string4 = "";
	string4 = string3;
	string4.at(firstH) = 'J';
	cout<<"Exercise 4\n"<<string4<<"\n";

	string string5 = string3;
	int lastl = string5.find_last_of("l");
	cout<<"Exercise 5\n"<<lastl<<"\n";

	string string6 = string3;
	string6.erase(lastl+1);
	cout<<"Exercise 6\n"<<string6<<"\n";

}

/* Execution results 

Enter a string: Good morning
Exercise 1
Good morning
Exercise 2
Good morning sleepy heads
Exercise 3
20
Exercise 4
bellow cello fellow Jello mellow Novello Othello pillow Rollo solo yellow
Exercise 5
70
Exercise 6
bellow cello fellow hello mellow Novello Othello pillow Rollo solo yell

*/







