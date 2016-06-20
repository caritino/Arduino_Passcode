const int boton1 = 2; // número del pin para el botón
const int boton2 = 3;
const int botonSubmit = 4;

const int led1 = 12;  // número del pin del LED
const int led2 = 13;

int estadoBoton1 = 0;  // estado del botón (0 ó LOW es apagado y 1 ó HIGH es encendido)
int estadoBoton2 = 0;
int estadoBotonSubmit = 0;

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
		estadoBoton1 = digitalRead(boton1);
		estadoBoton2 = digitalRead(boton2);
		estadoBotonSubmit = digitalRead(botonSubmit);

		if(estadoBotonSubmit == HIGH)
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
}
