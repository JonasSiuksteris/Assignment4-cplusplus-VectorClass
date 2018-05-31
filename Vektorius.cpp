template<class T>
Vector<T>::Vector()
{
    maxsize = 16;
    array = new T[maxsize];
    size_ = 0;
}

template<class T>
Vector<T>::Vector(int i)
{
    maxsize = i;
    array = new T[maxsize];
    size_ = 0;
}

template <typename T>
Vector<T>::Vector(initializer_list<T> list) : size_{list.size()}, maxsize{list.size()}, array{new T[maxsize]} {
    copy(list.begin(), list.end(), array);
}


template<class T>
Vector<T>::Vector(const Vector& v)
{

    maxsize = v.maxsize;
    size_ = v.size_;
    array = new T[maxsize];
    for(int i = 0; i < v.size_; i++)
        array[i] = v.array[i];

}

template<class T>
Vector<T>::~Vector()
{
    delete[] array;
}

template<class T>
void Vector<T>::push_back(const T& i)
{
    if(size_+1>maxsize)
        AllocateNew();
    array[size_] = i;
    size_++;
}

template<class T>
T Vector<T>::operator [](int i)
{
    return array[i];
}

template<class T>
int Vector<T>::at(T& i)
{
    if(i<size_)
        return array[i];
    throw 10;
}

template<class T>
void Vector<T>::AllocateNew()
{
    maxsize = size_ * 2;
    T* tmp = new T[maxsize];
    for(int i = 0; i < size_; i++)
        tmp[i] = array[i];
    delete[] array;
    array = tmp;
}

template<class T>
int Vector<T>::size()
{
    return size_;
}

template<class T>
Vector<T>& Vector<T>::operator+=(const T& i)
{
    this->push_back(i);
    return *this;

}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector& v)
{
    if(this!= &v) /// Jei tai tas pats vektorius, tai įvyks negražių dalykų
    {
        maxsize = v.maxsize;
        size_ = v.size_;
        delete[] array;
        array = new T[maxsize];
        for(int i = 0; i < v.size_; i++)
            array[i] = v.array[i];
    }
    return *this;
}

template<typename T>
void Vector<T>::pop_back()
{
    --size_;
    delete &array[size_];
}
