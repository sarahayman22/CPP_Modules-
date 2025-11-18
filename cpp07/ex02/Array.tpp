
template <typename T>
Array<T>::Array() : elements(NULL), _size(0) {
}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other) : elements(NULL), _size(0) {
    if (other._size > 0) {
        this->elements = new T[other._size]();
        this->_size = other._size;
        for (unsigned int i = 0; i < this->_size; i++) {
            this->elements[i] = other.elements[i];
        }
    }
}

template <typename T>
Array<T>::~Array() {
    if (this->elements)
        delete[] this->elements;
}


template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs) {
    if (this != &rhs) {
        if (this->elements)
            delete[] this->elements;
        
        this->_size = rhs._size;
        this->elements = NULL;

        if (this->_size > 0) {
            this->elements = new T[this->_size]();
            for (unsigned int i = 0; i < this->_size; i++) {
                this->elements[i] = rhs.elements[i];
            }
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= this->_size)
        throw OutOfBoundsException();
    return this->elements[index];
}
template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= this->_size)
        throw OutOfBoundsException();
    return this->elements[index];
}

template <typename T>
unsigned int Array<T>:: size() const {
    return this->_size;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
    return "Index is out of bounds";
}