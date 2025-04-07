#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() 
{ int numDomestic, numWild;

cout << "Enter the number of domestic animals: ";
cin >> numDomestic;
vector<string> domestic(numDomestic);

cout << "Enter names of domestic animals:\n";
for (auto &animal : domestic) {
    cout << "  Domestic animal: ";
    cin >> animal;
}

cout << "Enter the number of wild animals: ";
cin >> numWild;
vector<string> wild(numWild);

cout << "Enter names of wild animals:\n";
for (auto &animal : wild) {
    cout << "  Wild animal: ";
    cin >> animal;
}

cout << "\nAll animals:\n";
for (const auto &animal : domestic) {
    cout << "Domestic: " << animal << "\n";
}
for (const auto &animal : wild) {
    cout << "Wild: " << animal << "\n";
}

return 0;

}
