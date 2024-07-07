#include <iostream>

using namespace std;

class Transport
{
    public:
        virtual void getInfo() = 0;

    protected:
        string transportName;
        int maxSpeed;
        int numberOfWheels;
        int numberOfPassengers;
};

class Motorcycle : public Transport
{
    public:
        Motorcycle()
        {
            this->transportName = "Мотоцикл";
            this->maxSpeed = 150;
            this->numberOfWheels = 2;
            this->numberOfPassengers = 1;
        }

        void getInfo()
        {
            cout << "Наименование транспорта: " << this->transportName << endl;
            cout << "Максимальная скорость: " << this->maxSpeed << "км/ч" << endl;
            cout << "Количество колёс: " << this->numberOfWheels << endl;
            cout << "Количество пассажиров: " << this->numberOfPassengers << endl << endl;
        }
};

class Scooter : public Transport
{
    public:
        Scooter()
        {
            this->transportName = "Самокат";
            this->maxSpeed = 20;
            this->numberOfWheels = 2;
        }

        void getInfo()
        {
            cout << "Наименование транспорта: " << this->transportName << endl;
            cout << "Максимальная скорость: " << this->maxSpeed << "км/ч" << endl;
            cout << "Количество колёс: " << this->numberOfWheels << endl << endl;
        }
};

class Car : public Transport
{
    public:
        Car()
        {
            this->transportName = "Автомобиль";
            this->maxSpeed = 200;
            this->numberOfWheels = 4;
            this->numberOfPassengers = 4;
        }

        void getInfo()
        {
            cout << "Наименование транспорта: " << this->transportName << endl;
            cout << "Максимальная скорость: " << this->maxSpeed << "км/ч" << endl;
            cout << "Количество колёс: " << this->numberOfWheels << endl;
            cout << "Количество пассажиров: " << this->numberOfPassengers << endl << endl;
        }
};

class Factory
{
    public:
        virtual Transport* createTransport() = 0;
};

class MotorcycleFactory : public Factory
{
    public:
        Transport* createTransport()
        {
            return new Motorcycle;
        }
};

class ScooterFactory : public Factory
{
    public:
        Transport* createTransport()
        {
            return new Scooter;
        }
};

class CarFactory : public Factory
{
    public:
        Transport* createTransport()
        {
            return new Car;
        }
};
