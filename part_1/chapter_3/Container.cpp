
/* Example of a virtual / abstract class with pure virtual functions */

class Container
{
    public:
        virtual double& operator[](int) = 0;
        virtual int size() const = 0;
        virtual ~Container() {}
}

