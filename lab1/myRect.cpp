#include "myRect.h"

void Rect::normalize() {
    int t;
    if (m_left > m_right) {
        t = m_left;
        m_left = m_right;
        m_right = t;
    }
    if (m_top > m_bottom) {
        t = m_top;
        m_top = m_bottom;
        m_bottom = t;
    }
}

Rect::Rect() {
    this->m_left = 0;
    this->m_right = 0;
    this->m_top = 0;
    this->m_bottom = 0;
}

Rect::Rect(const Rect &rect) {
    m_left = rect.m_left;
    m_right = rect.m_right;
    m_top = rect.m_top;
    m_bottom = rect.m_bottom;
}

Rect::Rect(int m_left, int m_right, int m_top, int m_bottom) {
    this->m_left = m_left;
    this->m_right = m_right;
    this->m_top = m_top;
    this->m_bottom = m_bottom;
    normalize();
}

Rect::~Rect() {
    cout << "stop" << endl;
}

void Rect::InflateRect(int l, int r, int t, int b) {
    this->m_left -= l;
    this->m_right += r;
    this->m_top -= t;
    this->m_right += r;
    normalize();
}

void Rect::InflateRect(int decrease, int increase) {
    this->m_left -= decrease;
    this->m_right += increase;
    this->m_top -= decrease;
    this->m_right += increase;
}

void Rect::SetAll(int m_left, int m_right, int m_top, int m_bottom) {
    this->m_left = m_left;
    this->m_right = m_right;
    this->m_top = m_top;
    this->m_bottom = m_bottom;
    normalize();
}

void Rect::GetAll(int &l, int &r, int &t, int &b) const {
    l = this->m_left;
    r = this->m_right;
    t = this->m_top;
    b = this->m_bottom;
}

void Rect::BoundingRect(Rect rect) {
    if (this->m_left > rect.m_left) {
        this->m_left = rect.m_left;
    }
    if (this->m_right < rect.m_right) {
        this->m_right = rect.m_right;
    }
    if (this->m_top > rect.m_top) {
        this->m_top = rect.m_top;
    }
    if (this->m_bottom < rect.m_bottom) {
        this->m_bottom = rect.m_bottom;
    }
}

Rect BoundingRect(Rect rect1, Rect rect2) {
    Rect res(rect1);
    res.BoundingRect(rect2);
    return res;
}

Rect BoundingRect2(const Rect &rect1, const Rect &rect2) {
    Rect res(rect1);
    res.BoundingRect(rect2);
    return res;
}
