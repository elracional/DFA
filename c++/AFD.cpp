#include <iostream>

using namespace std;
/// variables globales 
string c;  // cadena a validar
int cont;  // contador
bool aceptado;
void q2();
void q1()
    {
         if(cont<c.size())
        {
            if(c[cont]=='a')//  Nos valida si la posici�n donde est� es igual a "a". Si as� es, no pasar� al siguiente estado, ya que no cumpli� la expresi�n regular. Ya que solamente puede ir una a
            {
                aceptado=false;
            }
            else
            {
                if(c[cont]=='b')//  Nos valida si la posici�n donde est� es igual a "b". Si as� es, pasar� al siguiente estado, ya que cumpli� la expresi�n regular. Y aumentamos el contador
                {
                    cont++;
                    q2();
                
                }
                else// Claramente si es diferente de a, no ser� una cadena valida, ya que no cumple con la expresi�n regular
                {
                    aceptado=false;
                }
            }
        }
         else
        {
           aceptado=true;
        }
    }

void q2()
    {
        if(cont<c.size())
        {
            if(c[cont]=='a')//  Nos valida si la posici�n donde est� es igual a "a". Si as� es, no pasar� al siguiente estado, ya que no cumpli� la expresi�n regular. Ya que solamente puede ir una a y es al principio
            {
                aceptado=false;
                
            }
            else
            {
                if(c[cont]=='b')//  Nos valida si la posici�n donde est� es igual a "b". Si as� es, pasar� al siguiente estado(en este caso regresar� al estado q1), ya que cumpli� la expresi�n regular. Y aumentamos el contador
                {
                    cont++;
                    q1();
                }
                else
                {
                    aceptado=false;
                }
            }
        }
        else
        {
            aceptado=true;
        }
        
    }  

void q0()//Estado q0. Primero nos confirma si el tama�o del contador es menor que el arreglo de caracteres y la precencia de landa o vacio ya que no son validos
    {
	    if(c.size()==0 || c=="" || c==" "){
    	  aceptado=false;	
		}else {            
        if(cont<c.size())
        {
            if(c[cont]=='a')//  Nos valida si la posici�n donde est� es igual a "a". Si as� es, pasar� al siguiente estado, ya que cumpli� la expresi�n regular. Y aumentamos el contador
            {
                cont++;
                q1();
            }
            else// Claramente si es diferente de a, no ser� una cadena valida, ya que no cumple con la expresi�n regular
            {
                aceptado=false;
            }
        }
        else
        {
            aceptado=true;
        }
}
    }
void inicio()// Metodo donde igualamos nuestro contador a 0 y llamamos a nuestro estado inicial del aut�mata
    {
        cont = 0;
        q0();
    }

int main() {
  cout<<"==> Programa que valida E(r) = a (bb*)*  <=="<<endl;	
  cout << "\tIngrese una cadena: ";
  getline(cin,c);
  cout <<"\tLa cadena ingresada es: "<<c<<endl;
  cout<<"\t-> ";
  inicio();
  if(aceptado==true){
  	cout<<"Cadena Valida"<<endl;
  }else{
  	cout<<"Cadena no valida"<<endl;
  }
}
