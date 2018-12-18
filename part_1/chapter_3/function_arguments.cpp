/* A function object, aka Functor, is an object member that is callable */

template<typename T> class Less_than
{
    const T val;

    public:
        Less_than(const T& v) {
            val = v;
        }

        /* Define callable () */
        bool operator{}(const T& x) const {
            return x < val;
        }
}
