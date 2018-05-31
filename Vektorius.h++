#ifndef DARBAS4_VEKTORIUS_H
#define DARBAS4_VEKTORIUS_H

template<class T>
class Vector{
    /// Elementų skaičius
    int size_;
    /// Maksimalus galimas elementų skaičius
    int maxsize;
    /// Pointeris, kur bus saugomas vektorius
    T* array;
    /// Priskiria naują atmintį
    void AllocateNew();
public:
    typedef T * iterator;
    /// Konstruktoriai
    Vector();
    Vector(int);
    Vector(initializer_list<T>);
    /// Kopijavimo konstruktorius
    Vector(const Vector&);
    /// Destruktorius
    ~Vector();
    /// push_back funkcija
    void push_back(const T&);
    /// Vektoriaus dydžio funkcija
    int size();
    /// Operatoriaus [] funkcija
    T operator[](int);
    /// Lokacijos funkcija
    int at(T&);
    /// Sunaikina paskutinį elementą
    void pop_back();
    /// push_back funkcija su operatoriumi
    Vector& operator+=(const T&);
    /// Palygina
    Vector& operator =(const Vector&);
};

#endif //DARBAS4_VEKTORIUS_H
