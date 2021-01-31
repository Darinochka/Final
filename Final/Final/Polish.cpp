#include <vector>
#include <list>
#include <map>
#include <string>

using namespace std;


vector <char> Polish(const string& function){
    bool neg, key = true;
    int length;
    vector <char> output;
    list <char> stack;
    map <char, int> op = {  {'^', 3},
                                    {'*', 2}, 
                                    {'/', 2},
                                    {'+', 1}, 
                                    {'-', 1}};
    for (char word : function) {
         if (isdigit(word) || word == 'x' || (word == '-' && neg)) {
             if (key) {
                 output.push_back(word);
                 key = false;
             } else {
                 output[output.size()-1] += word;
             }
         } else {
             key = true;
             if (word == '(') {
                neg = true;
                stack.push_back(word);
             } else if (word == ')') {
                neg = false;
                while (stack.back() != '(') {
                    output.push_back(stack.back());
                    stack.pop_back();
                }
                stack.pop_back();
             } else {
                 if (stack.empty()) {}
                 else {
                     while (stack.size() - 1 >= 0 && op[stack.back()] >= op[word]){
                         output.push_back(stack.back());
                         stack.pop_back();
                     }
                 }
                 stack.push_back(word);
             }
         }
    }

    for (int i = 0; i < stack.size(); i++) {
        output.push_back(stack.back());
        stack.pop_back();
    }
    return output;
}