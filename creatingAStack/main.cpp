#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "stackType .h"

using namespace std;


int main()
{
    double GPA;
    double highestGPA;
    string name;

    stackType<string> stack(100);

    ifstream infile;
    infile.open("GPA.txt");

    if (!infile)
        {
            cout << " THe file does not exist " << " Get wrecked" << endl;

        }

    cout << fixed << showpoint;
    cout << setprecision(2);

    infile >> GPA >> name;

    highestGPA = GPA;

    while (infile)
     {
        if (GPA > highestGPA)
            {
                stack.initStack();

                if (!stack.isFull())
                    {
                        stack.push(name);
                    }
                highestGPA = GPA;

            }
        else if (GPA == highestGPA)
            {
                if (!stack.isFull())
                    {
                        stack.push(name);
                    }
                else
                    {
                        cout << "Stack is full" << endl;
                    }
            }

        infile >> GPA >> name;

     }


     cout << "Highest GPA = " << highestGPA << endl;

     cout << "ALl students with the highest GPA are as follows: " << endl;

     while (!stack.isEmpty())
        {
            cout << stack.top() << endl;
            stack.pop();
        }
    return 0;
}
