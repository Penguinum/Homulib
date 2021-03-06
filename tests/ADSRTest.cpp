#include <iostream>
#include <ADSR.h>

using namespace std;

int main() {
    homu::SampleRate = 10000;
    homu::ADSR adsr;

    adsr.setAttack(0);
    adsr.setDecay(0);
    adsr.setSustain(1);
    adsr.setRelease(0);
    adsr.start();
    for (int i = 0; i < 1000; ++i) {
        double s = adsr.tick();
        if (i >= 500) {
            adsr.stopSustain();
        }
        if (s > 1 || s < -1) {
            cerr << "Warning: s = " << s << endl;
        }
        cout << s << endl;
    }

    adsr.setAttack(0.1);
    adsr.setDecay(0.2);
    adsr.setSustain(0.7);
    adsr.setRelease(0.3);
    adsr.start();
    while (true) {
        if (adsr.secondsPlayed() >= 0.5) { adsr.stopSustain(); }
        if (adsr.finished()) { break; }
        double s = adsr.tick();
        if (s > 1 || s < -1) {
            cerr << "Warning: s = " << s << endl;
        }
        cout << s << endl;
    }

    adsr.setAttack(0.1);
    adsr.setDecay(0.2);
    adsr.setSustain(0.7);
    adsr.setRelease(0.3);
    adsr.start();
    while (true) {
        if (adsr.secondsPlayed() >= 0.05) { adsr.stopSustain(); }
        if (adsr.finished()) { break; }
        double s = adsr.tick();
        if (s > 1 || s < -1) {
            cerr << "Warning: s = " << s << endl;
        }
        cout << s << endl;
    }
    return 0;
}

