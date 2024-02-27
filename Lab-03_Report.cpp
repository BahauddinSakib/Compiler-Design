#include <iostream>
using namespace std;

bool isValid(string str)
{
    int n;
    //= str.length();

    if (!((str[0] >= 'a' && str[0] <= 'z')
        || (str[0] >= 'A' && str[0] <= 'Z')
        || str[0] == '_'))
        return false;

    for (int i = 1; i < n; i++)
    {
        if (!((str[i] >= 'a' && str[i] <= 'z')
            || (str[i] >= 'A' && str[i] <= 'Z')
            || (str[i] >= '0' && str[i] <= '9')
            || str[i] == '_'))
            return false;
    }

    return true;
}

int main()
{
    string str;
    cout << "Enter your input string: ";
    cin >> str;

    bool hasNumber = false;

    for (char ch : str)
    {
        if (isdigit(ch))
        {
            hasNumber = true;
            break;
        }
    }

    if (isValid(str))
    {
        cout << "1" << endl;
        cout << "Valid Identifier";
    }
    else
    {
        cout << "0" << endl;
        cout << "Invalid Identifier";

        if (hasNumber)
        {
            cout << endl;
            cout << "Input contains a number" << endl << endl;
        }

        for (char ch : str)
        {
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                cout << endl;
                cout << "There is an Arithmetic Operator in the input" << endl;
                break;
            }
        }

        for (char ch : str)
        {
            if (ch == '@' || ch == '#' || ch == '$' || ch == ',')
            {
                cout << endl;
                cout << "There is a special character in the input" << endl;
                break;
            }
        }
    }

    return 0;
}
