// CS4303 Programming Language Concepts
// Lab exercise - Scanner
//
// Name Anh Dang 
//
// A simple lexical analyzer for C/C++-style variable declarations.
// The grammar for the declarations is as follows:
//
// <declaration> 	::= 	<type>  <var> ’;’ | <type> <var> ’=’ <number> ’;’
// <type> 		::= 	int | float
// <var> 		::= 	A | B | C | D | E
// <number> 	::= 	<integer> | <float>
// <integer> 	::= 	<integer> <digit> | <digit>
// <digit> 		::= 	0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
// <float> 		::= 	<integer> ‘.’ <integer>
// 
// The task of this exercise is to write a lexical analyzer (or 
// scanner) for the tokens used in the above grammar. The following
// is the regular expression that defines the tokens:
//
//		= | ; | int | float | A | B | C | D | E | [0-9]+ | [0-9]+\.[0-9]+
//
// The program will read a declaration from the keyboard, and the
// scanner you design should recognize and print out all tokens
// included in the input. For example, given the following declaration:
//
//		int A = 123;
//
// your program should print:
//
// int
// A
// =
// 123
// ;
//
// Make sure your program print out the token one per line in the order 
// they appear in the input. Once an erroneous token is encountered, your
// scanner should print out an error message and stopped scanning. For
// example, given the following input:
//
//		int A = 0#;
//
// your program should print:
//
// int
// A
// =
// 0
// #: Error: Unrecognizable token
//
// Note that tokens may NOT be separated by spaces. For example, the above
// input:
//
//		int A = 123;
//
// does not have a space to separate 123 and ;. Also, the following inputs
// are also legal and generate the same output:
//
//		int A=123;
//		intA=123;
// 
// However, a whole token cannot be separated by spaces. For example, the
// following input will cause 12 and 3 to be regarded as two distinct tokens.
//
//		int A = 12 3;
//
// The ouput will look like:
// int
// A
// =
// 12
// 3
// ;
//
// Also note that the scanner doesn't check for syntactic errors. Therefore the
// above input is legal to this program.
//
// Other sample input:
//		float B;
//		float C=0.2;
//		short D;
//		float F;
//
// The last two sample inputs should generate errors because "short" and "F" are
// not acceptable tokens.
//
// Important!!! Save your GetToken program. We are going to use it in future 
// labs.


#include <iostream>
#include <string>

using namespace std;

string GetToken();
void error(int);

int type_int = 0;// count i,n,t
int type_float = 0;// count f,l,o,a,t
string digit = "";// store digit in string
bool semicolon = false;// does statement have ';'
bool isFloat = false;// is the variable float
bool isInt = false;// is the variable int

int main() {
	string token;

	cout << "Please enter a declaration in format "
		<< "<type> <variable> [= number];" << endl;

	token = GetToken();

	cout << "The following are the tokens in the input:" << endl;
	

	while (token != "") {
		

		//output when token is not space
		if (token == " ")
		{
			token = GetToken();
		}
		if (token != " ")
			cout << token << endl;

		token = GetToken();


		//outout digit then semicolon
		if (token == ";")
		{
			if (digit != "")
				cout << digit << endl;

			cout << ";" << endl;
			token = "";
		}
	}

	cout << "Done!" << endl;
	system("pause");
	return 0;
}

string GetToken() {

	string token;
	char ch;
	cin.get(ch);

	token = " ";// init token to space

	//check if int
	if (ch == 'i')
		type_int++;
	if (ch == 'n')
		type_int++;
	if (ch == 't')
		type_int++;
	if (type_int == 3)
	{
		token = "int";
		isInt = true;
	}
		
	//check if float
	if (ch == 'f')
		type_float++;
	if (ch == 'l')
		type_float++;
	if (ch == 'o')
		type_float++;
	if (ch == 'a')
		type_float++;
	if (ch == 't')
		type_float++;
	if (type_float == 5)
	{
		token = "float";
		isFloat = true;
	}

	//check for A | B | C | D | E | ' ' | = 
	if (ch == ' ')
		token = " ";
	if (ch == 'A')
		token = "A";
	if (ch == 'B')
		token = "B";
	if (ch == 'C')
		token = "C";
	if (ch == 'D')
		token = "D";
	if (ch == 'E')
		token = "E";
	if (ch == '=')
		token = "=";

	//check for digits
	if (ch == '0')
	{
		digit = digit + "0";
		token = " ";
	}
	if (ch == '1')
	{
		digit = digit + "1";
		token = " ";
	}
	if (ch == '2')
	{
		digit = digit + "2";
		token = " ";
	}
	if (ch == '3')
	{
		digit = digit + "3";
		token = " ";
	}
	if (ch == '4')
	{
		digit = digit + "4";
		token = " ";
	}
	if (ch == '5')
	{
		digit = digit + "5";
		token = " ";
	}
	if (ch == '6')
	{
		digit = digit + "6";
		token = " ";
	}
	if (ch == '7')
	{
		digit = digit + "7";
		token = " ";
	}
	if (ch == '8')
	{
		digit = digit + "8";
		token = " ";
	}
	if (ch == '9')
	{
		digit = digit + "9";
		token = " ";
	}
	//only allow decimal in float dataType
	if (ch == '.')
	{
		if (isFloat == false)
			cout << "Error: Decimals need to be float dataType" << endl;

		if (isFloat == true)
		{
			digit = digit + ".";
			token = " ";
		}
	}
	//check for semicolon errors
	if (ch == ';')
	{
		token = ";";
		semicolon = true;
	}
	//check for input chars errors
	if (ch != ' ' &&
		ch != 'i' &&
		ch != 'n' &&
		ch != 't' &&
		ch != 'f' &&
		ch != 'l' &&
		ch != 'o' &&
		ch != 'a' &&
		ch != 'A' &&
		ch != 'B' &&
		ch != 'C' &&
		ch != 'D' &&
		ch != 'E' &&
		ch != '0' &&
		ch != '1' &&
		ch != '2' &&
		ch != '3' &&
		ch != '4' &&
		ch != '5' &&
		ch != '6' &&
		ch != '7' &&
		ch != '8' &&
		ch != '9' &&
		ch != '.' &&
		ch != '=' &&
		ch != ';' )
		cout << ch << ": Error: Unrecognizable token" << endl;


	return token;
}