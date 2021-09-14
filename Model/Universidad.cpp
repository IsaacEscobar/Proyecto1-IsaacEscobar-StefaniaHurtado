#include "Universidad.h"

Universidad::Universidad()
{
    this->asistentes[10] = Asistente("I", 10);
    this->directores[10] = Director("M", 10);
    this->directores[11] = Director("J", 11);
    this->jurados[10] = Jurado("K", 10);
    this->jurados[11] = Jurado("L", 11);
}

// void Universidad::mostrarReportes()
// {
//     return mostrarReportes;
// }

void Universidad::crearAsistente()
{
    int numDocumento;
    string nombre;
    bool existeDocumento = true;
    cout << "Ingrese su nombre: ";
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    getline(cin, nombre);
    do 
    {
        cout << "Ingrese su No. de documento: ";
        cin >> numDocumento;
        if (this->asistentes.find(numDocumento) != this->asistentes.end())
	    {
            existeDocumento = true;
            cout << "Documento existente, indique otro.\n";
	    }
	    else
	    {
		    existeDocumento = false;
	    }
    } while(existeDocumento);
    Asistente nuevoAsistente;
    nuevoAsistente.setNombre(nombre);
    nuevoAsistente.setDocumento(numDocumento);
    asistentes[numDocumento] = nuevoAsistente;
    cout << nuevoAsistente.getNombre() << " con documento No." << nuevoAsistente.getDocumento() << 
    " ha sido agregado.\n";
}

void Universidad::crearJurado()
{
    int numDocumento;
    string nombre;
    bool existeDocumento = true;
    cout << "Ingrese su nombre: ";
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    getline(cin, nombre);
    do 
    {
        cout << "Ingrese su No. de documento: ";
        cin >> numDocumento;
        if (this->jurados.find(numDocumento) != this->jurados.end())
	    {
            existeDocumento = true;
            cout << "Documento existente, indique otro.\n";
	    }
	    else
	    {
		    existeDocumento = false;
	    }
    } while(existeDocumento);
    Jurado nuevoJurado;
    nuevoJurado.setNombre(nombre);
    nuevoJurado.setDocumento(numDocumento);
    jurados[numDocumento] = nuevoJurado;
    cout << nuevoJurado.getNombre() << " con documento No." << nuevoJurado.getDocumento() << 
    " ha sido agregado.\n";
}

void Universidad::crearDirector()
{
    int numDocumento;
    string nombre;
    bool existeDocumento = true;
    cout << "Ingrese su nombre: ";
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    getline(cin, nombre);
    do 
    {
        cout << "Ingrese su No. de documento: ";
        cin >> numDocumento;
        if (this->directores.find(numDocumento) != this->directores.end())
	    {
            existeDocumento = true;
            cout << "Documento existente, indique otro.\n";
	    }
	    else
	    {
		    existeDocumento = false;
	    }
    } while(existeDocumento);
    Director nuevoDirector;
    nuevoDirector.setNombre(nombre);
    nuevoDirector.setDocumento(numDocumento);
    directores[numDocumento] = nuevoDirector;
    cout << nuevoDirector.getNombre() << " con documento No." << nuevoDirector.getDocumento() << 
    " ha sido agregado.\n";
}

void Universidad::verificarJurados(Acta* nuevaActa)
{
    int docJurado1, docJurado2;
    bool docJurado1Existe = false, docJurado2Existe = false;
    do
        {
            cout << "Ingrese el documento del jurado 1:\n";
            cin >> docJurado1;
            if(this->jurados.find(docJurado1) != this->jurados.end())
            {
                docJurado1Existe = true;
                do
                {
                    cout << "Ingrese el documento del jurado 2:\n";
                    cin >> docJurado2;
                    if(this->jurados.find(docJurado2) != this->jurados.end())
                    {
                        docJurado2Existe = true;
                        nuevaActa->getJurados()[0] = jurados[docJurado1].getNombre();
                        nuevaActa->getJurados()[1] = to_string(jurados[docJurado1].getDocumento());
                        nuevaActa->getJurados()[2] = jurados[docJurado2].getNombre();
                        nuevaActa->getJurados()[3] = to_string(jurados[docJurado2].getDocumento());
                    }
                    else
                    {
                        docJurado2Existe = false;
                        cout << "El jurado no se encuentra registrado.";
                    }
                } while(!docJurado2Existe);
            }
            else
            {  
                docJurado1Existe = false;
                cout << "El jurado no se encuentra registrado.";
            }
        } while(!docJurado1Existe); 
}

void Universidad::verificarDirectores(Acta* nuevaActa)
{
    int docDirector1, docDirector2;
    bool docDirector1Existe = false, docDirector2Existe = false;
    do
        {
            cout << "Ingrese el documento del director:\n";
            cin >> docDirector1;
            if(this->directores.find(docDirector1) != this->directores.end())
            {
                docDirector1Existe = true;
                do
                {
                    cout << "Ingrese el documento del codirector, o 0 si no desea codirector:\n";
                    cin >> docDirector2;
                    if(docDirector2 != 0)
                    {
                        if(this->directores.find(docDirector2) != this->directores.end())
                        {
                            docDirector2Existe = true;
                            nuevaActa->getDirectores()[0] = directores[docDirector1].getNombre();
                            nuevaActa->getDirectores()[1] = to_string(directores[docDirector1].getDocumento());
                            nuevaActa->getDirectores()[2] = directores[docDirector2].getNombre();
                            nuevaActa->getDirectores()[3] = to_string(directores[docDirector2].getDocumento());
                        }
                        else
                        {
                            docDirector1Existe = false;
                            cout << "El director no se encuentra registrado.";
                        }
                    }
                    else
                    {
                        docDirector2Existe = true;
                        nuevaActa->getDirectores()[0] = directores[docDirector1].getNombre();
                        nuevaActa->getDirectores()[1] = to_string(directores[docDirector1].getDocumento());
                        nuevaActa->getDirectores()[2] = "";
                        nuevaActa->getDirectores()[3] = "";
                    }
                } while(!docDirector2Existe);
            }
            else
            {  
                docDirector1Existe = false;
                cout << "El director no se encuentra registrado.";
            }
        } while(!docDirector1Existe); 
}

void Universidad::generarActa(Asistente* asistente)
{
    int numeroTrabajo;
    Acta nuevaActa;
    bool existeActaPorNum = true;
    do
    { 
        cout << "Digite el numero del trabajo:\n";
        cin >> numeroTrabajo;
        nuevaActa.setNumeroTrabajo(numeroTrabajo);
        if(this->actas.find(numeroTrabajo) != this->actas.end())
        {
            existeActaPorNum = true;
            cout << "Numero de acta existente, use otro.\n";
        }
        else
        {
            existeActaPorNum = false;
            asistente->generarActa(numeroTrabajo, &nuevaActa);
            for(map<int, Jurado>::iterator pJurado = jurados.begin(); pJurado != jurados.end();
             pJurado++)
            {
                Jurado juradoActual = pJurado->second;
                cout << juradoActual.getNombre() << " - " << juradoActual.getDocumento() << "\n";
            }
            verificarJurados(&nuevaActa);
            for(map<int, Director>::iterator pDirector = directores.begin(); pDirector != directores.end();
             pDirector++)
            {
                Director directorActual = pDirector->second;
                cout << directorActual.getNombre() << " - " << directorActual.getDocumento() << "\n";
            }
            verificarDirectores(&nuevaActa);
        }
    } while(existeActaPorNum);
    actas[numeroTrabajo] = nuevaActa;
}

void Universidad::mostrarInfoActa()
{
    int opcionUsuario;
    bool existeActaPorNum = false;
    cout << "Digite el numero del acta a revisar:\n";
    cin >> opcionUsuario;
    do
    {
        if(this->actas.find(opcionUsuario) != this->actas.end())
        {
            existeActaPorNum = true;
            actas[opcionUsuario].mostrarActa();
        }
        else
        {
            existeActaPorNum = false;
            cout << "Numero de acta inexistente, use otro.\n";
        }
    } while(!existeActaPorNum);
}

void Universidad::menuAsistente(Asistente* asistente)
{
    int opcionUsuario;
    do
    {
        cout << "1. Crear un acta.\n";
        cout << "2. Ver historicos de actas.\n";
        cout << "0. Volver.\n";
        cout << "Digite el numero: ";
        cin >> opcionUsuario;
        switch(opcionUsuario)
        {
            case 1:
                generarActa(asistente);
                break;
            case 2:
                asistente->mostrarNumActasPoseidas();
                mostrarInfoActa();
                break;
            case 0:
                break;
            default: cout << "Opcion no contemplada, intentelo de nuevo\n";
                break;
        }
    } while(opcionUsuario != 0);
}

void Universidad::ingresarComoAsistente()
{
    int numDocumento;
    cout << "Asistentes en lista:\n";
    for(map<int, Asistente>::iterator pAsistente = asistentes.begin(); pAsistente != asistentes.end();
     pAsistente++)
    {
        Asistente asistenteActual = pAsistente->second;
        cout << asistenteActual.getNombre() << " - " << asistenteActual.getDocumento() << "\n";
    }
    cout << "Ingrese su documento: ";
    cin >> numDocumento;
    for(map<int, Asistente>::iterator pAsistente = asistentes.begin(); pAsistente != asistentes.end();
     pAsistente++)
    {
        Asistente asistenteActual = pAsistente->second;
        if(asistenteActual.getDocumento() == numDocumento)
        {
            menuAsistente(&asistenteActual);
        }
    }
}

void Universidad::menuJurado(Jurado* jurado)
{
    int opcionUsuario;
    do
    {
        cout << "1. Evaluar acta.\n";
        cout << "2. Exportar acta.\n";
        cout << "0. Volver.\n";
        cout << "Digite el numero: ";
        cin >> opcionUsuario;
        switch(opcionUsuario)
        {
            case 1:
                jurado->calificarActa(actas[0]);
                break;
            case 2:
                jurado->exportarActa(actas[0]);
                
                break;
            case 0:
                break;
            default: cout << "Opcion no contemplada, intentelo de nuevo\n";
                break;
        }
    } while(opcionUsuario != 0);
}


void Universidad::ingresarComoJurado()
{
    int numDocumento;
    cout << "Jurados en lista:\n";

    for(map<int, Jurado>::iterator pJurado = jurados.begin(); pJurado != jurados.end();
     pJurado++)
    {
        Jurado juradoActual = pJurado->second;
        cout << juradoActual.getNombre() << " - " << juradoActual.getDocumento() << "\n";
    }
    cout << "Ingrese su documento: ";
    cin >> numDocumento;
    for(map<int, Jurado>::iterator pJurado = jurados.begin(); pJurado != jurados.end();
     pJurado++)
    {
        Jurado juradoActual = pJurado->second;
        if(juradoActual.getDocumento() == numDocumento)
        {
            menuJurado(&juradoActual);
        }
    }
}

void Universidad::numActasDirector(Director* director)
{
    int opcionUsuario;
    bool existeActaPorNum = false;
    for(map<int, Acta>::iterator pActa = actas.begin(); pActa != actas.end(); pActa++)
    {
        Acta actaActual = pActa->second;
        if(stoi(actaActual.getDirectores()[1]) == director->getDocumento() || 
           stoi(actaActual.getDirectores()[3]) == director->getDocumento())
        {
            cout << "Acta No." << actaActual.getNumeroTrabajo() << "\n";
        }
    }
    do
    {
        cout << "Ingrese el numero del acta:\n";
        cin >> opcionUsuario;
        if(this->actas.find(opcionUsuario) != this->actas.end())
        {
            existeActaPorNum = true;
            actas[opcionUsuario].mostrarActa();
        }
        else
        {
            existeActaPorNum = false;
            cout << "Numero de acta inexistente, use otro.\n";
        }
    } while(!existeActaPorNum);
}

void Universidad::menuDirector(Director* director)
{
    int opcionUsuario;
    do
    {
        cout << "1. Modificar criterios.\n";
        cout << "2. Anadir criterio.\n";
        cout << "0. Volver.\n";
        cout << "Digite el numero: ";
        cin >> opcionUsuario;
        switch(opcionUsuario)
        {
            case 1:
                director->modificarCriterio(actas[0]);
                break;
            case 2:
                director->crearCriterio(actas[0]);
                break;
            case 0:
                break;
            default: cout << "Opcion no contemplada, intentelo de nuevo\n";
                break;
        }
    } while(opcionUsuario != 0);
}

void Universidad::ingresarComoDirector()
{
    int numDocumento;
    cout << "Directores en lista:\n";

    for(map<int, Director>::iterator pDirector = directores.begin(); pDirector != directores.end();
     pDirector++)
    {
        Director directorActual = pDirector->second;
        cout << directorActual.getNombre() << " - " << directorActual.getDocumento() << "\n";
    }
    cout << "Ingrese su documento: ";
    cin >> numDocumento;
    for(map<int, Director>::iterator pDirector = directores.begin(); pDirector != directores.end();
     pDirector++)
    {
        Director directorActual = pDirector->second;
        if(directorActual.getDocumento() == numDocumento)
        {
            menuDirector(&directorActual);
        }
    }
}