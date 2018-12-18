/* A classical user-defined type example */

class Complex
{
    double re;
    double im;

    public:

        /* Constructors */
        Complex(double r, double i) {
            re = r;
            im = i;
        }

        Complex(double r) {
            re = r;
            im = 0;
        }

        Complex() {
            re = 0;
            im = 0;
        }

        /* Accessors and mutators
         * const indicates that we will not modify the object for which they are called on
         */
        double real() const {
            return re;
        }

        void real(double d) {
            re = f;
        }

        double imag() const {
            return im;
        }

        void imag(double d) {
            im = d;
        }

        
        /* Operator definitions */
        Complex& operator+=(Complex z) {
            re += z.re;
            im += z.im;
            return *this;
        }

        Complex& operator-=(Complex z) {
            re -= z.re;
            im -= z.im;
            return *this;
        }


        /* Destructor */
        ~Complex() {
            // cleanup if stuff is on the heap
        }
}

















