#ifndef VECTOR2_H
#define VECTOR2_H


class Vector2
{
    public:
        Vector2();
        Vector2(double x, double y);
        virtual ~Vector2();

        double y;
        double x;

        void normalize();
        double lenght();
        Vector2 distanceTo(Vector2 vect);
        Vector2 vectorTo(Vector2 vect);

    protected:

    private:
};

#endif // VECTOR2_H
