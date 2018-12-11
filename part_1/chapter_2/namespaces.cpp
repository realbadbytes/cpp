/* 
 * namespace: mechanism for expressing that some declarations belong together.
 * names shouldnt clash with other names.
 *
 * In this example, we create a class named complex. We need a separate namespace
 * because complex already exists in the standard namespace.
 */


namespace My_code
{
    class complex { /*...*/ }
    complex sqrt(complex);
    // ...
    int main();
}


int My_code::main()
{
    complex z {1, 2};
    auto z1 = sqrt(z);
    std::cout << "{" << z2.real() << "," << z2.imag() << "}\n";
    // ...
}


int main()
{
    return My_code::main();
}
