#ifndef LAB1_BOCHKA_H
#define LAB1_BOCHKA_H


class Bochka {
    double h2o;
    double c2h5oh;

public:
    Bochka();

    Bochka(double volume, double concentration);

    double GetVolume();

    void Pereliv(Bochka &to, double volume);

    double GetConcentration();
};


#endif //LAB1_BOCHKA_H
