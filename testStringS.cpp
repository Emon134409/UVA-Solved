#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    string s("Somewhere down the road");
    istringstream iss(s);

    while (iss)
    {
        string sub;
        iss >> sub;
        cout << "Substring: " << sub << endl;
    }
}
