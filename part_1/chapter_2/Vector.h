/* Prog consists of many separately developed parts.
 * Must clearly define interactions between those parts.
 */

/* declaration, the interface */

class Vector {
    public:
        Vector(int s);
        double& operator[](int i);
        int size() const; /* const suffix means "can be applied to const objects" */
    private:
        double* elem;
        int sz;
};

