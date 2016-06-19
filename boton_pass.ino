const int boton1 = 2; // número del pin para el botón
const int boton2 = 3;
const int botonSubmit = 4;

const int led1 = 12;  // número del pin del LED
const int led2 = 13;

int estadoBoton1 = 0;  // estado del botón (0 ó LOW es apagado y 1 ó HIGH es encendido)
int estadoBoton2 = 0;
int estadoBotonSubmit = 0;

int contadorBoton1 = 0;
int contadorBoton2 = 0;

int primerPassword()
{
	int passBoton1 = 1;
	int passBoton2 = 1;

	if(contadorBoton1 == passBoton1 && contadorBoton2 == passBoton2)
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
	delay(1000);
  Serial.println("Inicio");
	Serial.print("Presiones del boton1: ");
	Serial.println(contadorBoton1);
	Serial.print("Presiones del boton2: ");
	Serial.println(contadorBoton2);

	// Leemos si el botón en pin2 está abierto o cerrado
	estadoBoton1 = digitalRead(boton1);
	estadoBoton2 = digitalRead(boton2);
	estadoBotonSubmit = digitalRead(botonSubmit);

	if(estadoBotonSubmit == LOW)
	{
		if(estadoBoton1 == HIGH)
		{
			contadorBoton1++;
		}
		if(estadoBoton2 == HIGH)
		{
			contadorBoton2++;
		}
	}
	else
	{
		if(primerPassword() == 1)
		{
			digitalWrite(led1, HIGH); 
		}
		else {
	   		// Si no es asi, se apaga
	   		digitalWrite(led1, LOW); 
 		}
	}
	delay(1000);
	Serial.println("Final");
	Serial.print("Presiones del boton1: ");
	Serial.println(contadorBoton1);
	Serial.print("Presiones del boton2: ");
	Serial.println(contadorBoton2);
	
/*
 	if (estadoBoton1 == HIGH) {     
   		digitalWrite(led1, HIGH);  
 	} 
 	else {
   		digitalWrite(led1, LOW); 
 	}
 */
}

