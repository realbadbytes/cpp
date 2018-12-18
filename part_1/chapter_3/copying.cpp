
class Vector {

    private:

        double *elem;
        int size;

    public:

        Vector(int s);
        ~Vector() {
            delete[] elem;
        }

        /* copy constructor */
        Vector(const Vector& a)
        {
            /* create a new area of memory for the new object's elem array */
            elem = new double[a.size];
            size = a.size;

            /* copy elements */
            for (int i = 0; i != size; i++) {
                elem[i] = a.elem[i];
            }
        }

        /* copy assignment */
        Vector& operator=(const Vector& a);

        double& operator[](int i);
        const double& operator[](int i) const;

        int size() const;

};
