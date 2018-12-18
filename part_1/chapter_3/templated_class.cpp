/* Allow for parameterization of class */

template<typename T> class Vector {

    private:
        T* elem;
        int size;

    public:
        Vector(int s);
        T& operator[](int i);
        const T& operator[](int i) const;
}

/* This way, a vector can be a container for any type, represented by T in the implementati0n */
/* Templates are resolved at compile time, so there is no performance overhead at runtime */
