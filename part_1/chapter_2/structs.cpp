struct Vector {
    int sz;
    double *elem;
}

Vector v;

void vector_init(Vector &v, int s)
{
    v.elem = new double[s];
    v.sz = s;
}
