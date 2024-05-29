#include <iostream>
#include <stack>
#include <string>
using namespace std;
// *********************************
// * Author: Gokhan Unal           *
// * Date: 3/5/2024                *
// * Description: This function    *
// * doesn't store any characters  *
// * besides paranthesis types.    *
// * Parameters: string expression *
// * Returns: bool ? true : false  *
// *********************************
bool balanced_paranteheses(string expr)
{
	stack<char> temp;
	//for each char in string expression
	for (char c : expr)
	{
		//left paranthesis check and if so push it onto the themp stack<char>
		if( c == '(' || c == '{' || c == '[' ){
			temp.push(c);
		}
		//right paranthesis processesing
		else if ( c == ')' || c == '}' || c == ']' )
		{
			//if empty after a right paranthesis, return false
			if(temp.empty()) { return false; }
			//now save the top to a char defined in this scope
			char top = temp.top();
			//now pop from the temp stack <char>
			temp.pop();
			//now, check the matching ) ( 
			if ( c == ')' && top != '(' || c == '}' && top != '{' || c == ']' && top != '[') 
			{
				return false;
			}
		}		
	}//for loop curly bracket END
	//if it is empty at this point, it is a balanced paranthesis expression
	return temp.empty();
}//function end

//simple main function for practice purpose only
int main() {
    string expr = "(( 3 + 5 )) "; 
    if (balanced_paranteheses(expr)) 
    {
        cout << "Balanced parentheses";
    }
    else 
    {
        cout << "Unbalanced parentheses";
    }
    return 0;
}
