#include "Commons.h"
#include "functions.h"

int main()
{
    string input, hexInputString, hashValue;
    int decimal;
    bool option, checker;
    ifstream file;
    cout<<"0 - input from file, 1 - input by hand"<<endl;
    cin >> option;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        throw invalid_argument("Invalid input. Please enter 0 or 1.");
    }
    else{
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        if(option==0){
            cout << "File name: " << endl;
            cin >> input;

            file.open(input);
            if (!file) {
                cerr << "Error: File cannot be opened or does not exist." << endl;
            }
            else{
            hashValue = Hash(readFromFile(input));
            cout << "File hash: " << hashValue << endl;
            }
        }
        else if(option == 1){
            getline(cin, input);
            hashValue = Hash(input);
        }
    }
    cout << "Hash: " << hashValue << endl;
}
