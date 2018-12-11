/* something assumed to be true about a class is an invariant. 
 * "elem points to an array of sz doubles" 
 * constructors must establish invariants
 * this is very important because:
 * - makes us understand exactly what we want
 * - forces us to be specific
 */

Vector::Vector(int s)
{
    if (s < 0) {
        throw length_error{"Vector constructor size"};
    }
    elem = new double[s];
    sz = s;
}


/* Using the constructor: */
void test()
{
    try {
        Vector v(-27);
    }
    catch (std::length_error) {
        // ...
    }
    catch (std:bad_alloc) {
        // couldnt get heap space
    }
}
