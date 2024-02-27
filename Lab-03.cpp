#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isValid(string str)
{
    int n = str.length();

    if (!((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z') || str[0] == '_'))
        return false;

    for (int i = 1; i < n; i++) {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9') || str[i] == '_'))
            return false;
    }

    return true;
}

int main() {
    ifstream inputFile("input.txt");

   // if (!inputFile.is_open()) {
        //cout << "Error opening file: input.txt" << endl;
        //return 1;
   // }

    string givenInput;
    cout << "Enter your input string: ";
    cin >> givenInput;

    string line;
    bool found = false;

    while (getline(inputFile, line)) {
        if (line.find(givenInput) < line.length()) {
            found = true;
            break;
        }
    }

    inputFile.close();

    if (found) {
        cout << "Keyword found in the file." << endl;

        if (isValid(givenInput))
        {
            cout<< "1" << endl;
            cout << "Invalid identifier" << endl;

        }
        else
            {
            cout << "0" << endl;
            cout << "Valid identifier" << endl;


            bool hasNumber = false;
            for (char ch : givenInput)
            {
                if (isdigit(ch)) {
                    hasNumber = true;
                    cout << "Input contains a number" << endl;
                    break;
                }
            }


            for (char ch : givenInput)
            {
                if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch=='%')
                {
                    cout << "There is an Arithmetic Operator in the input" << endl;
                    break;
                }
            }


            for (char ch : givenInput)
            {
                if (ch == '@' || ch == '#' || ch == '$' || ch == ',' || ch==';') {
                    cout << "There is a special character in the input" << endl;
                    break;
                }
            }
        }
    }
    else
        {
         cout << "Keyword not found in the file." << endl;


        if (isValid(givenInput))
        {
            cout << "1" << endl;
            cout << "Valid identifier" << endl;

        } else {
            cout << "0" << endl;
            cout << "Invalid identifier" << endl;

            bool hasNumber = false;
            for (char ch : givenInput)
            {
                if (isdigit(ch)) {
                    hasNumber = true;
                    cout << "Input contains a number" << endl;
                    break;
                }
            }

            for (char ch : givenInput)
                {
                if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch=='%') {
                    cout << "There is an Arithmetic Operator in the input" << endl;
                    break;
                }
            }

            for (char ch : givenInput)
                {
                if (ch == '@' || ch == '#' || ch == '$' || ch == ',' || ch == ';') {
                    cout << "There is a special character in the input" << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
