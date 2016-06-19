const int boton1 = 2; // número del pin para el botón
const int boton2 = 3;
const int botonSubmit = 4;

const int led1 = 12;  // número del pin del LED
const int led2 = 13;

int estadoBoton1 = 0;  // estado del botón (0 ó LOW es apagado y 1 ó HIGH es encendido)
int estadoBoton2 = 0;
int estadoBotonSubmit = 0;

int contadorBotonSubmit = 0;
bool flagBotonSubmit = false;

int primerPassword()
{

	if(estadoBoton1 == HIGH && estadoBoton2 == HIGH)
		return 1;
	else
		return 0;
}

void setup() {
	Serial.begin(9600);

	// Se identifica el pin 13 como salida
 	pinMode(led1, OUTPUT);     
 	pinMode(led2, OUTPUT);    
 	// Se identifica el pin 2 como entrada
 	pinMode(boton1, INPUT);  
 	pinMode(boton2, INPUT);  
 	pinMode(botonSubmit, INPUT);     
}

void loop(){
	if(!flagBotonSubmit){

		// Leemos si el botón en pin2 está abierto o cerrado
		estadoBoton1 = digitalRead(boton1);
		estadoBoton2 = digitalRead(boton2);
		estadoBotonSubmit = digitalRead(botonSubmit);

		if(estadoBotonSubmit == HIGH)
		{
			contadorBotonSubmit++;
			if(primerPassword() == 1)
			{
				digitalWrite(led1, HIGH); 
				flagBotonSubmit == true;
			}
			else {
		   		// Si no es asi, se apaga
		   		digitalWrite(led1, LOW);
          		flagBotonSubmit == false;  
			}

			if(led1 == HIGH && contadorBotonSubmit > 1){
				digitalWrite(led1, LOW);
				delay(500);
				digitalWrite(led1, HIGH);
				delay(500);
				digitalWrite(led1, LOW);

				contadorBotonSubmit = 0;
			}
		}
		
		
	/*
	 	if (estadoBoton1 == HIGH) {     
	   		digitalWrite(led1, HIGH);  
	 	} 
	 	else {
	   		digitalWrite(led1, LOW); 
	 	}
	 */
	}

}
