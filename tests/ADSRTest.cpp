#include <iostream>
#include "../src/ADSR.h"

using namespace std;

int main() {
    homu::ADSR adsr(10000);

    adsr.setAttack(0);
    adsr.setDecay(0);
    adsr.setSustain(1);
    adsr.setRelease(0);
    adsr.start();
    for (int i = 0; i < 10000; ++i) {
        float s = adsr.nextSample();
        if (i >= 5000) {
            adsr.stopSustain();
        }
        if (s > 1 || s < -1) {
            cerr << "Warning: s = " << s << endl;
        }
        cout << s << endl;
    }
    return 0;
}

