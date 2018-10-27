#include "Bochka.h"

Bochka::Bochka() {
    h2o = 0;
    c2h5oh = 0;
}

Bochka::Bochka(double volume, double concentration) {
    h2o = volume * (1 - concentration);
    c2h5oh = volume * concentration;
}

double Bochka::GetVolume() {
    return h2o + c2h5oh;
}

void Bochka::Pereliv(Bochka &to, double volume) {
    double h2oMove = volume * h2o / (h2o + c2h5oh);
    double c2h5ohMove = volume * c2h5oh / (h2o + c2h5oh);

    this->h2o -= h2oMove;
    this->c2h5oh -= c2h5ohMove;

    to.h2o += h2oMove;
    to.c2h5oh += c2h5ohMove;
}

double Bochka::GetConcentration() {
    return c2h5oh / (h2o + c2h5oh);
}
