#pragma once

#include <iostream>
//#define stop __asm nop

using namespace std;

class Rect {
    int m_left, m_right, m_top, m_bottom;

    void normalize();

public:
    Rect();

    Rect(const Rect &rect);

    Rect(int m_left, int m_right, int m_top, int m_bottom);

    ~Rect();

    void InflateRect(int l, int r, int t, int b);

    void InflateRect(int decrease = 1, int increase = 1);

    void SetAll(int l, int r, int t, int b);

    void GetAll(int &l, int &r, int &t, int &b) const;

    void BoundingRect(Rect rect);
};

Rect BoundingRect(Rect rect1, Rect rect2);

Rect BoundingRect2(const Rect &rect1, const Rect &rect2);
