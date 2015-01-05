#include <iostream>
#include "../src/SinewaveGenerator.h"

using namespace std;

int main() {
    homu::SinewaveGenerator gen(10000);
    gen.start(100);
    for (int i = 0; i < 10000; ++i) {
        float s = gen.nextSample();
        if (s > 1 || s < -1) {
            cerr << "Warning: s = " << s << endl;
        }
        cout << s << endl;
    }
    return 0;
}
