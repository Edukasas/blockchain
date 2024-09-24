#include "Commons.h"
#include "functions.h"
#include <chrono>
#include <vector>

int main()
{
    compareStringPairsBitLevel("test_files/similarPairs/file.txt");
    compareStringPairsHexLevel("test_files/similarPairs/file.txt");
    // compareStringPairs("test_files/randomPairs/file.txt");
    // std::vector<double> rez(10, 0), names(10, 0);
    // for (int j = 0; j < 5; j++){
    // int num = 1;
    // for (int i = 0; i < 10; i++){
    // string input, hexInputString, hashValue;
    // int decimal;
    // bool option, checker;
    // ifstream file;
    // // cout<<"0 - input from file, 1 - input by hand"<<endl;
    // // cin >> option;
    // option = 0;
    // if (cin.fail())
    // {
    //     cin.clear();
    //     cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    //     throw invalid_argument("Invalid input. Please enter 0 or 1.");
    // }
    // else{
    //     // cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    //     if(option==0){
    //         // cout << "File name: ";
    //         // cin >> input;
    //         file.open("./test_files/konstitucija.txt");
    //         if (!file) {
    //             cerr << "Error: File cannot be opened or does not exist." << endl;
    //         }
    //         else{
    //         auto start = std::chrono::high_resolution_clock::now();
    //         hashValue = Hash(readLinesFromFile("./test_files/konstitucija.txt", num));
    //         auto end = std::chrono::high_resolution_clock::now();
    //         std::chrono::duration<double> duration = end - start;
    //         // cout << "File hash: " << hashValue << " " << num << " " << duration.count() << endl;
    //         rez[i] += duration.count();
    //         names[i] = num;
    //         file.close();
    //         num *= 2;
    //         }
    //     }
    //     else if(option == 1){
    //         cout<<"Value you want to hash: ";
    //         getline(cin, input);
    //         hashValue = Hash(input);
    //     }
    // }
    // }
    // }
    // for(int i = 0; i < 10; i++){
    //     cout<<setw(10)<<rez[i]/5<<" "<<names[i]<<endl;
    // }
}
