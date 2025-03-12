#include <iostream>
#include <cmath>

class electricField
{
    private:
        double *eX;
        double *eY;
        double *eZ;
    public:
        electricField(double *eX, double *eY, double *eZ)
        {
            this->eX = eX;
            this->eY = eY;
            this->eZ = eZ;
        }

        ~electricField()
        {
            delete eX;
            delete eY;
            delete eZ;
        }

        double getEx()
        {
            return *eX;
        }

        double getEy()
        {
            return *eY;
        }

        double getEz()
        {
            return *eZ;
        }

        void setEx(double value)
        {
            *eX = value;
        }

        void setEy(double value)
        {
            *eY = value;
        }

        void setEz(double value)
        {
            *eZ = value;
        }
};

class magneticField
{
    private:
        double *bX;
        double *bY;
        double *bZ;
    public:
        magneticField(double *bX, double *bY, double *bZ)
        {
            this->bX = bX;
            this->bY = bY;
            this->bZ = bZ;
        }
        ~magneticField()
        {
            delete bX;
            delete bY;
            delete bZ;
        }

        double getBx()
        {
            return *bX;
        }

        double getBy()
        {
            return *bY;
        }

        double getBz()
        {
            return *bZ;
        }

        void setBx(double value)
        {
            *bX = value;
        }

        void setBy(double value)
        {
            *bY = value;
        }

        void setBz(double value)
        {
            *bZ = value;
        }
};

double calculateMagnitude(double x, double y, double z)
{
    return std::sqrt(x * x + y * y + z * z);
}

double innerProduct(double x1, double y1, double z1, double x2, double y2, double z2)
{
    return x1 * x2 + y1 * y2 + z1 * z2;
}

int main(int argc, char const *argv[])
{
    double ex = 1.0, ey = 2.0, ez = 3.0;
    double bx = 4.0, by = 5.0, bz = 6.0;

    electricField eField(&ex, &ey, &ez);
    magneticField mField(&bx, &by, &bz);

    std::cout << "Electric Field Magnitude: " << calculateMagnitude(eField.getEx(), eField.getEy(), eField.getEz()) << std::endl;
    std::cout << "Magnetic Field Magnitude: " << calculateMagnitude(mField.getBx(), mField.getBy(), mField.getBz()) << std::endl;
    std::cout << "Inner Product: " << innerProduct(eField.getEx(), eField.getEy(), eField.getEz(), mField.getBx(), mField.getBy(), mField.getBz()) << std::endl;

    return 0;
}
