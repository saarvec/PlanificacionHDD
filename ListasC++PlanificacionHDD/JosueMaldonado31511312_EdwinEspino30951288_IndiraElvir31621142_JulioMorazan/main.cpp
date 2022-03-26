#include <QCoreApplication>
#include <vector>
#include <typeinfo>
#include <Pila.h>
#include <Cola.h>
#include <unistd.h>
using std::cin;
using std::endl;
using std::string;
using std::vector;

char Menu(){
    char Op;
    cout<<"\n\t\t*****Bienvenido*****\n"
        <<"A.-> LOOK.\n"
        <<"B.-> Desencolar.\n"
        <<"C.-> Insertar al Final.\n"
        <<"D.-> Eliminar del Frente.\n"
        <<"E.-> Eliminar del Penultimo.\n"
        <<"F.-> Eliminar del Final.\n"
        <<"G.-> Salir.\n"
        <<"La opción elegida es: ";
    cin.get(Op);
    cin.ignore();
    Op = toupper(Op);
    if(Op<'A' || Op>'G'){
        cout<<"\nLa opción Ingresada es Incorrecta!!!\n"
            <<"Favor Vuelva a Intentarlo!!!\n";
        Op = Menu();
    }
    return Op;
}

template< typename T >
void probarLista( Lista< T > &lista, const string &nombreTipo ){
    cout << "Prueba de una Lista de valores tipo " << nombreTipo << "\n";
    T valor; // almacena el valor de entrada
    char Op, lee;
    vector<T> A = {166,69,24,60,82,1,31,104};
    for(int i=0; i<8; i++){
        cout<< A[i]<<"\t";
    }
    T Ini = 50, tmp, Pos;
    char Dir = '0';//0 - Bajada, 1 - Subida
    bool Hay = true;
    do{ // realiza las acciones seleccionadas por el usuario
        Op = Menu();
        switch ( Op ){
        case 'A':

            while( Hay ){

                Hay = false;
                tmp = 199;
                for(int i=0; i<A.size(); i++){
                    if (Dir == '0'){
                        if( A[i] < Ini )  {
                            //cout<<"Entro\n";

                            if( (Ini - A[i]) < tmp){
                                //cout<<(Ini - A[i])<<"\n";
                                tmp = Ini - A[i];
                                Pos = i;
                                Hay = true;
                            }
                        }
                    }else if (Dir == '1'){
                        if( A[i] > Ini){

                        }
                    }
                }
                if( Hay ){
                    Ini = Pos;
                    lista.insertarAlFinal(A[Pos]);
                    cout<< A[Pos]<<"\t";
                    A.erase(A.begin()+Pos);
                    lista.imprimir();
                }
            }

            break;
        /*case 'B':
            cola.Desencolar(valor);
            cout<<"Se Proceso:\n";
            cout<<valor->getCodigo()<<"|"<<valor->getDireccion()<<"|"
                <<valor->getColor()<<"|"<<valor->getNivel()<<"|"
                <<valor->getHabitacion()<<"|"<<valor->getBanio()<<"|"
                <<valor->getParqueo()<<"|"<<valor->getPrecio()<<"|\n";
            cola.imprimir();
            sleep(1);
            lista.insertarEnPenultimo(valor);
            break;
        case 'C':
            cout<<"Ingrese la Letra o Símbolo deseado: ";
            cin.get(valor);
            cin.ignore();
            objetoLista.insertarAlFinal( valor );
            objetoLista.imprimir();
            sleep(1);
            break;
        case 'D':
            if ( lista.eliminarDelFrente( valor ) )
                cout << valor << " se elimino de la lista\n";
            lista.imprimir();
            break;
        case 'E':
            if ( lista.eliminarDelPenultimo( valor ) )
                cout << valor << " se elimino de la lista\n";
            lista.imprimir();
            break;
        case 'F':
            if ( lista.eliminarDelFinal( valor ) )
                cout << valor << " se elimino de la lista\n";
            lista.imprimir();
            break;*/
        case 'G':
             cout << "Gracias por su Visita!!!\n"
                  << "Le Esperamos Pronto!!!\n\n";
        }
    } while ( Op != 'G' );
} // fin de la función probarLista

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // prueba Lista de valores int
    Lista< int > lista;
    probarLista( lista,"Bloques HDD" );
    return 0;
}
