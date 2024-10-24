#include <robo_hardware2.h> 
#include <Servo.h>

//este é o codigo do robo carcaça

//-----PINOS PARA LIGAR MOTORES-----//
//Motor1:
//pino1 PWM_RODA_DIREITA 	6
//pino2 SENTIDO_RODA_DIREITA 	7
//
//Motor2:
//pino1 PWM_RODA_ESQUERDA 	5
//pino2 SENTIDO_RODA_ESQUERDA	4
//-----PINOS PARA LIGAR MOTORES-----//

//-----PINOS PARA SENSORES REFLETANCIA-----//
//SENSOR_LINHA_MAIS_ESQUERDO	    A3
//SENSOR_LINHA_ESQUERDO			    A2
//SENSOR_LINHA_DIREITO			    A1	
//SENSOR_LINHA_MAIS_DIREITO			A0	
//-----PINOS PARA SENSORES REFLETANCIA-----//

#define DIVISOR_BRANCO_PRETO 50

#define VELOCIDADE_FRENTE 25

#define VELOCIDADE_TRAS -40



float valorSensorDir;
float valorSensorEsq;
float valorSensorMaisEsq;
float valorSensorMaisDir;
void setup(){
	robo.configurar();
}

void loop(){
  valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq();
	valorSensorEsq = robo.lerSensorLinhaEsq(); //Le o valor do sensor esquerdo e coloca dentro da variavel valor_sensor_esq
	valorSensorDir = robo.lerSensorLinhaDir(); //Le o valor do sensor direito e coloca dentro da variavel valor_sensor_dir
  valorSensorMaisDir = robo.lerSensorLinhaMaisDir();

  //Branco: valorSensor > divisor
  //Preto:  valorSensor < divisor
  
	//bbbb
	if(valorSensorMaisDir > DIVISOR_BRANCO_PRETO && valorSensorDir > DIVISOR_BRANCO_PRETO && valorSensorEsq > DIVISOR_BRANCO_PRETO && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO){
		robo.acionarMotores(VELOCIDADE_FRENTE,VELOCIDADE_FRENTE);	//Para frente
	}
	//pppb
	else if (valorSensorMaisDir < DIVISOR_BRANCO_PRETO && valorSensorDir < DIVISOR_BRANCO_PRETO && valorSensorEsq < DIVISOR_BRANCO_PRETO && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO){
		robo.acionarMotores(VELOCIDADE_TRAS,VELOCIDADE_FRENTE);	//Para a esquerda
	}
	//bbpb
	else if (valorSensorMaisDir > DIVISOR_BRANCO_PRETO && valorSensorDir > DIVISOR_BRANCO_PRETO && valorSensorEsq < DIVISOR_BRANCO_PRETO && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO){
		robo.acionarMotores(VELOCIDADE_FRENTE,VELOCIDADE_TRAS);	//Para a esquerda
	}
  //bbpp
	else if (valorSensorMaisDir > DIVISOR_BRANCO_PRETO && valorSensorDir > DIVISOR_BRANCO_PRETO && valorSensorEsq < DIVISOR_BRANCO_PRETO && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO){
		robo.acionarMotores(VELOCIDADE_FRENTE,VELOCIDADE_TRAS); //Para a esquerda
	}
  //bpbb
  else if (valorSensorMaisDir > DIVISOR_BRANCO_PRETO && valorSensorDir > DIVISOR_BRANCO_PRETO && valorSensorEsq < DIVISOR_BRANCO_PRETO && valorSensorMaisEsq < DIVISOR_BRANCO_PRETO){
    robo.acionarMotores(VELOCIDADE_TRAS,VELOCIDADE_FRENTE); //Para a direita
  }
  //bppp
  else if (valorSensorMaisDir > DIVISOR_BRANCO_PRETO && valorSensorDir < DIVISOR_BRANCO_PRETO && valorSensorEsq < DIVISOR_BRANCO_PRETO && valorSensorMaisEsq < DIVISOR_BRANCO_PRETO){
    robo.acionarMotores(VELOCIDADE_FRENTE,VELOCIDADE_TRAS); //Para a esquerda
  }
  //pbbb
  else if (valorSensorMaisDir < DIVISOR_BRANCO_PRETO && valorSensorDir > DIVISOR_BRANCO_PRETO && valorSensorEsq > DIVISOR_BRANCO_PRETO && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO){
    robo.acionarMotores(VELOCIDADE_TRAS,VELOCIDADE_FRENTE); //Para a direita
  }
  //pbbp
  else if (valorSensorMaisDir < DIVISOR_BRANCO_PRETO && valorSensorDir > DIVISOR_BRANCO_PRETO && valorSensorEsq > DIVISOR_BRANCO_PRETO && valorSensorMaisEsq < DIVISOR_BRANCO_PRETO){
    robo.acionarMotores(VELOCIDADE_FRENTE,VELOCIDADE_FRENTE); //Para frente
  }
  //pbpp
  else if (valorSensorMaisDir < DIVISOR_BRANCO_PRETO && valorSensorDir > DIVISOR_BRANCO_PRETO && valorSensorEsq < DIVISOR_BRANCO_PRETO && valorSensorMaisEsq < DIVISOR_BRANCO_PRETO){
    robo.acionarMotores(VELOCIDADE_FRENTE,VELOCIDADE_TRAS); //Para a esquerda
  }
  //ppbb
  else if (valorSensorMaisDir < DIVISOR_BRANCO_PRETO && valorSensorDir < DIVISOR_BRANCO_PRETO && valorSensorEsq > DIVISOR_BRANCO_PRETO && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO){
    robo.acionarMotores(VELOCIDADE_TRAS,VELOCIDADE_FRENTE); //Para a direita
  }
  //ppbp
  else if (valorSensorMaisDir < DIVISOR_BRANCO_PRETO && valorSensorDir < DIVISOR_BRANCO_PRETO && valorSensorEsq > DIVISOR_BRANCO_PRETO && valorSensorMaisEsq < DIVISOR_BRANCO_PRETO){
    robo.acionarMotores(VELOCIDADE_TRAS,VELOCIDADE_FRENTE); //Para a direita
  }
  //pppb
  else if (valorSensorMaisDir < DIVISOR_BRANCO_PRETO && valorSensorDir < DIVISOR_BRANCO_PRETO && valorSensorEsq < DIVISOR_BRANCO_PRETO && valorSensorMaisEsq > DIVISOR_BRANCO_PRETO){
    robo.acionarMotores(VELOCIDADE_TRAS,VELOCIDADE_FRENTE); //Para a direita
  }
  //pppp
  else if (valorSensorMaisDir < DIVISOR_BRANCO_PRETO && valorSensorDir < DIVISOR_BRANCO_PRETO && valorSensorEsq < DIVISOR_BRANCO_PRETO && valorSensorMaisEsq < DIVISOR_BRANCO_PRETO){
    robo.acionarMotores(VELOCIDADE_TRAS,VELOCIDADE_TRAS); //Para tras
  }

}
