#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <cctype>
#include <map>

using namespace std;

vector <char> Polish(const string& function);

int main() {
    string function, command;
    vector <char> polishNotation;
    cout << "This program will convert your function to reverse Polish notation, draw a tree," <<
        "and write its data to a file. To get started, write 'start'.\n" <<
        "For more information write 'about'\n";
    cin >> command;
    if (command == "start") {
        cout << "Please, input your function here: ";
        cin >> function;
        polishNotation = Polish(function);
        for (auto word : polishNotation) {
            cout << word << " ";
        }
    }
    else if (command == "about") {
        //о возможностях и ограничениях программы
    }
}