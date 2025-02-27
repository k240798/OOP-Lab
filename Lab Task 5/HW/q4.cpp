#include <iostream>
#include <string>
using namespace std;

class Blend {
public:
    void blendJuice() {
        cout << "Blending juice..." << endl;
        long long counter = 0;
        for (int i = 0; i < 500000000; ++i) { 
            counter += i;
            if (i % 100000000 == 0) {
                cout << "Blending... " << (i / 100000000) + 1 << " steps completed\n";
            }
        }
        cout << "Juice blended successfully!\n";
    }
};

class Grind {
public:
    void grindJuice() {
        cout << "Grinding juice..." << endl;
        long long counter = 0;
        for (int i = 0; i < 700000000; ++i) { 
            counter += i;
            if (i % 140000000 == 0) {
                cout << "Grinding... " << (i / 140000000) + 1 << " steps completed\n";
            }
        }
        cout << "Juice ground successfully!\n";
    }
};

class JuiceMaker {
private:
    Blend blender;
    Grind grinder;

public:
    void blendJuice() {
        blender.blendJuice();
    }

    void grindJuice() {
        grinder.grindJuice();
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <blend/grind>\n";
        return 1;
    }

    string command = argv[1];
    JuiceMaker juiceMaker;

    if (command == "blend") {
        juiceMaker.blendJuice();
    } else if (command == "grind") {
        juiceMaker.grindJuice();
    } else {
        cerr << "Invalid command. Use 'blend' or 'grind'.\n";
        return 1;
    }

    return 0;
}
