#include <fstream>
#include <unordered_map>
using namespace std;

int main() {
    ifstream input("../io/example.in");
    if (!input) {
        cerr << "Could not open file example.in";
        return 1;
    }

    int K;
    input >> K;

    unordered_map<char, int> value;
    while (K--) {
        char key;
        input >> key;
        input >> value[key];
    }

    string A, B;
    input >> A;
    input >> B;

    input.close();

    return 0;
}