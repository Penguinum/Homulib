#include <iostream>
#include "../src/Sinewave.h"

using namespace std;

int main() {
    homu::SampleRate = 10000;
    homu::Sinewave gen;
    gen.start(100);
    for (int i = 0; i < 10000; ++i) {
        double s = gen.nextSample();
        if (s > 1 || s < -1) {
            cerr << "Warning: s = " << s << endl;
        }
        cout << s << endl;
    }
    return 0;
}
