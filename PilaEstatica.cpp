/*
PILA ESTATICA
ANGEL GABRIEL RODRIGUEZ MARTINEZ
*/

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
const int TAM = 10;

class Empleado {
public:
    std::string clave;
    std::string nombre;
    std::string domicilio;
    float sueldo;
    std::string reportaA;

    Empleado(string nom, string clv, string dom, float sue, string gfe) {
        nombre = nom;
        clave = clv;
        domicilio = dom;
        sueldo = sue;
        reportaA = gfe;
    }

    Empleado() {}

    friend std::ostream& operator<<(std::ostream& o, Empleado& wrk) {
        o << "\t\nClave de empleado: " << wrk.clave << "\t\nNombre: " << wrk.nombre << "\t\nDomicilio: " << wrk.domicilio << "\t\nSueldo: $" << wrk.sueldo << "\t\nSe reporta con: " << wrk.reportaA << "\n" << std::endl;
        return o;
    }

    bool operator ==(Empleado& emp) {
        return ((clave == emp.clave) && (nombre == emp.nombre) && (domicilio == emp.domicilio) && (sueldo == emp.sueldo) && (reportaA == emp.reportaA));
    }

    bool operator !=(Empleado& emp) {
        return ((clave != emp.clave) && (nombre != emp.nombre) && (domicilio != emp.domicilio) && (sueldo != emp.sueldo) && (reportaA == emp.reportaA));
    }

    Empleado operator+(const Empleado& sum) const {
        Empleado resultado(nombre + sum.nombre, clave + sum.clave, domicilio + sum.domicilio, sueldo + sum.sueldo, reportaA + sum.reportaA);
        return resultado;
    }

    bool operator<(const Empleado& menq) const {
        return sueldo < menq.sueldo;
    }

    bool operator>(const Empleado& mayq) const {
        return sueldo > mayq.sueldo;
    }
};

class Pila {
private:
    Empleado datos[TAM];
    int last;
public:
    Pila() :last(-1) {}
    bool vacia()const {
        if (last == -1)
            return true;
        return false;
    }
    bool llena()const {
        if (last == TAM - 1)
            return true;
        return false;
    }
    int inserta(Empleado elem, int pos) {
        int i = last + 1;
        while (i > pos) {
            datos[i] = datos[i - 1];
            i--;
        }
        datos[pos] = elem;
        last++;
        return 1;
    }

    bool elimina(int pos) {
        int i = pos;
        while (i < last) {
            datos[i] = datos[i + 1];
            i++;
        }
        last--;
        return false;
    }

    int ultimo()const {
        return last;
    }

    void push(Empleado emp)
    {
        inserta(emp, ultimo() + 1);
    }
    void pop()
    {
        elimina(ultimo());
    }
    Empleado& top()
    {
        return datos[last];
    }

    friend std::ostream& operator <<(std::ostream& out, Pila& L) {
        int i = 0;
        std::cout << "\n";
        while (i <= L.ultimo()) {
            out << L.datos[i];
            i++;
        }
        return out;
    };
};


int main()
{
    Pila pila1;
    Empleado x;
    int opc = -1, pos = -2, nEmps = 0;

    while (1) {
        system("cls");
        std::cout << "\t\tPILA ESTATICA DE EMPLEADOS\n\tEscoge una de las siguientes opciones:\n1. Push\n2. Pop\n3. Top\n4. SALIR";
        std::cout << "\n\tIngresa tu opcion: ";std::cin >> opc;cin.ignore();

        switch (opc) {
        case 1:system("cls");
            if (pila1.llena()) {
                std::cout << "ERROR DE INSERCION: La pila esta llena\n";system("PAUSE");break;
            }
            else {
                std::cout << "\tAGREGAR EMPLEADO:\nIngresa la clave del empleado: ";getline(cin, x.clave);
                std::cout << "Ingresa el nombre del empleado: ";getline(cin, x.nombre);
                std::cout << "Ingresa el domicilio del empleado: ";getline(cin, x.domicilio);
                std::cout << "Ingresa el sueldo del empleado: ";std::cin >> x.sueldo;cin.ignore();
                std::cout << "Ingresa a quien se reporta el empleado: ";getline(cin, x.reportaA);
                pila1.push(x);nEmps++;
            }
            cout << "Empleado registrado con exito" << endl;
            system("PAUSE");
            break;

        case 2:system("cls");
            if (pila1.vacia()) {
                std::cout << "ERROR DE ELMINACION: La lista esta vacia\n";system("PAUSE");break;
            }
            else {
                std::cout << "\tELIMINAR EMPLEADO:\n";
                pila1.pop();cout << "Eliminacion exitosa" << endl;
            }
            system("PAUSE");
            break;

        case 3:system("cls");
            if (pila1.vacia()) {
                std::cout << "ERROR DE MUESTRA: La lista esta vacia\n";system("PAUSE");break;
            }
            else {
                std::cout << "\tMOSTRAR EMPLEADO:\n";
                std::cout << pila1.top();
            }
            system("PAUSE");
            break;

        case 4:exit(0);break;

        default: std::cout << "Ingresa una opcion valida";system("PAUSE");
        }
    }
    return 0;
}