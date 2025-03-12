#include <iostream>
#include <cmath>

class electricField
{
    private:
        double eX;
        double eY;
        double eZ;
    public:
        electricField(){};

        electricField(double ex, double ey, double ez)
        {
            eX = ex;
            eY = ey;
            eZ = ez;
        }

        ~electricField()
        {
            std::cout << "Deconstructor was called" << std::endl;
        }

        double getEx()
        {
            return eX;
        }

        double getEy()
        {
            return eY;
        }

        double getEz()
        {
            return eZ;
        }

        void setEx(double ex)
        {
            eX = ex;
        }

        void setEy(double ey)
        {
            eY = ey;
        }

        void setEz(double ez)
        {
            eZ = ez;
        }

        double calculateMagnitude()
        {
            return std::sqrt(eX * eX + eY * eY + eZ * eZ);
        }

        double innerProduct()
        {
            return eX * eX + eY * eY + eZ * eZ;
        }
};

class magneticField
{
    private:
        double bX;
        double bY;
        double bZ;
    public:
        magneticField(){};

        magneticField(double bx, double by, double bz)
        {
            bX = bx;
            bY = by;
            bZ = bz;
        }
        ~magneticField()
        {
            std::cout << "Deconstructor was called" << std::endl;
        }

        double getBx()
        {
            return bX;
        }

        double getBy()
        {
            return bY;
        }

        double getBz()
        {
            return bZ;
        }

        void setBx(double bx)
        {
            bX = bx;
        }

        void setBy(double by)
        {
            bY = by;
        }

        void setBz(double bz)
        {
            bZ = bz;
        }

        double calculateMagnitude()
        {
            return std::sqrt(bX * bX + bY * bY + bZ * bZ);
        }

        void unitVector()
        {
            double mg = sqrt(bX * bX + bY * bY + bZ * bZ);
            double m1 = bX / mg;
            double m2 = bY / mg;
            double m3 = bZ / mg;

            std::cout << " Unit vector is: " << m1 << ", " << m2 << ", " << m3 << std::endl;
        }
};







int main(int argc, char const *argv[])
{
    double ex = 1.0, ey = 2.0, ez = 3.0;
    double bx = 4.0, by = 5.0, bz = 6.0;

    electricField eFieldDefault;
    electricField eFieldComponent(ex, ey, ez);
    magneticField mFieldDefault;
    magneticField mFieldComponent(bx, by, bz);

    std::cout << "Magnatude with default electric field: " << eFieldDefault.calculateMagnitude() << std::endl;
    std::cout << "Magnatude with parameterized electric field: " << eFieldComponent.calculateMagnitude() << std::endl;
    std::cout << "Magnatude with default magnetic field: " << mFieldDefault.calculateMagnitude() << std::endl;
    std::cout << "Magnatude with parameterized magnetic field: " << mFieldComponent.calculateMagnitude() << std::endl;

    eFieldComponent.setEx(4);
    eFieldComponent.setEy(5);
    eFieldComponent.setEz(6);

    mFieldComponent.setBx(7);
    mFieldComponent.setBx(8);
    mFieldComponent.setBx(9);

    std::cout << "New magnatude for electric field: " << eFieldComponent.calculateMagnitude() << std::endl;
    std::cout << "New magnatude for magnetic field: " << mFieldComponent.calculateMagnitude() << std::endl;
    std::cout << "********************************\n";
    std::cout << "Inner product of electric field: " << eFieldComponent.innerProduct() << std::endl;
    
    mFieldComponent.unitVector();

    return 0;
}
