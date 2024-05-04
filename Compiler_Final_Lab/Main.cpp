#include<bits/stdc++.h>

using namespace std;

///Validity check
bool isValidIdentifier(const string& str, string& reason)
 {
    if (str.empty())
    {
        reason = "Empty identifier";
        return false;
    }


    ifstream keywordFile("Keyword.txt");
    if (!keywordFile.is_open())
    {
        reason = "Error opening Keyword file";
        return false;
    }

    string keyword;
    bool isKeyword = false;
    while (keywordFile >> keyword)
    {
        if (str == keyword)
        {
            isKeyword = true;
            break;
        }
    }

    keywordFile.close();

    if (isKeyword)
    {
        reason = "Found in Keyword file";
        return false;
    }

    if (!(isalpha(str[0]) || str[0] == '_'))
    {
        reason = "Contains Invalid character";
        return false;
    }

    for (char ch : str)
    {
        if (!(isalnum(ch) || ch == '_'))
        {
            reason = "Must start with a letter or underscore";
            return false;
        }
    }

    return true;
}

///Keyword check

bool isKeyword(const string& input)
{
    ifstream file("Keyword.txt");
    if (!file.is_open())
    {
        cout << "Error opening Keyword file" << endl;
        return false;
    }

    string keyword;
    while (file >> keyword)
    {
        if (keyword == input)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}
///Punctuation check

bool isPunctuation(const string& input)
{
    ifstream file("Punctuation.txt");
    if (!file.is_open())
    {
        cout << "Error opening Punctuation file" << endl;
        return false;
    }

    string line;
    while (getline(file, line))
        {
            if (line.find(input) != string::npos)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}
///Operator check

bool isOperator(const string& input)
{
    ifstream file("Operator.txt");
    if (!file.is_open())
    {
        cout << "Error opening Operator file" << endl;
        return false;
    }

    string line;
    while (getline(file, line))
    {
        if (line.find(input) != string::npos)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}
///Predefined check

bool isPredefined(const string& input)
{
    ifstream file("Predefined.txt");

    if (!file.is_open())
    {
        cout << "Error opening Predefined file" << endl;
        return false;
    }

    string predefined;
    while (file >> predefined)
    {
        if (predefined == input)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}
///Header check

bool isHeader(const string& input)
{
    ifstream file("Header.txt");

    if (!file.is_open())
    {
        cout << "Error opening Header file" << endl;
        return false;
    }

    string header;
    while (getline(file, header))
    {
        if (input == header)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}
///Namespace check

bool isUsing(string input)
{
    ifstream file("Namespace.txt");
    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        return false;
    }

    string line;
    do
    {
        if (line.find(input) < line.length())
        {
            file.close();
            return true;
        }
    } while (getline(file, line));

    file.close();
    return false;
}

///Constant check

bool isConstant(const string& input)
{
    if (all_of(input.begin(), input.end(), ::isdigit))
    {
        return true;
    }

    if (input.size() >= 2 && input.front() == '"' && input.back() == '"')
    {
        return true;
    }

    if (input.size() == 3 && input.front() == '\'' && input.back() == '\'')
    {
        return true;
    }

    return false;
}
///comment check

bool isCommented(const string& word)
{
    return word.find("//") == 0 || (word.find("/*") != string::npos && word.find("*/") != string::npos && word.find("/*") < word.find("*/"));
}

int main()
{
    cout << "Enter the name of the text file: ";
    string filename;
    getline(cin, filename);

    ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        cout << "Error: Unable to open file " << filename << endl;
        return 1;
    }

    string line;
    int lineNumber = 1;
    int totalTokens = 0;

    while (getline(inputFile, line))
        {
        istringstream iss(line);
        string value;
        vector<string> solution;

        while (iss >> value)
            {
            totalTokens++;
            if (value == "#include")
             {
                if (iss >> value)
                {
                    solution.push_back("Header file: " + value);
                }
                else
                {
                    solution.push_back("Invalid token: #include");
                }
            }
                else if (isKeyword(value))
            {
                solution.push_back("Keyword: " + value);
            }
                else if (isPunctuation(value))
            {
                solution.push_back("Punctuation: " + value);
            }
                else if (isOperator(value))
            {
                solution.push_back("Operator: " + value);
            }
                else if (isPredefined(value))
            {
                solution.push_back("Predefined: " + value);
            }
                else if (isCommented(value))
            {
                solution.push_back("Commented: " + value);
            }
                else if (isHeader(value))
            {
                solution.push_back("Header file: " + value);
            }
                else if (isConstant(value))
            {
                solution.push_back("Constant: " + value);
            }
                else
            {
                string reason;

                  if (isValidIdentifier(value, reason))
                {
                    solution.push_back("Identifier: " + value);
                }

                  else if (isUsing(value))
                {
                    solution.push_back("Namespace declaration: " + value);
                }
                  else
                {
                    solution.push_back("Invalid identifier (" + reason + "): " + value);
                }
            }
        }

        cout << "Line Number " << lineNumber << ": ";

        for (const string& result : solution)
        {
            cout << result << " , ";
        }
        cout << endl;

        lineNumber++;
    }

    inputFile.close();

    cout << endl;
    cout << "Total Tokens Counts: " << totalTokens << endl;

    return 0;
}
