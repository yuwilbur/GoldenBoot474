
/*
This sections contains the functions used to activate the Linear actuator ---- TESTED IT WORKS !!!!!
*/
// Variable definition 
#define LOW 0
#define HIGH 1
#define PWM_MAX 255
#define RETRACT 72
#define EXTEND 1023

//Function Declaration
void Actuator_Activate();
void Actuator_Deactivate();
void Actuator_Read();

//Function Definition
void Actuator_Deactivate() //Pushes the rod out  
{
  digitalWrite(actuator_pin1, HIGH);
  digitalWrite(actuator_pin2, LOW);
}

void Actuator_Activate() //Pulls the rod in 
{
  digitalWrite(actuator_pin1, LOW);
  digitalWrite(actuator_pin2, HIGH);
  
}

void Actuator_Read() //Reads the rod value when it's out or in
{
  actuator_length = analogRead(actuator_input);
 // log1('\n');
 // log1("Actuator value analog : ");
 // log1(actuator_length);
}

void ActuatorControl(int length)
{            
           digitalWrite(actuator_enable, HIGH); 
           Actuator_Read();
           if(actuator_length < length)
            {
              /*   while(actuator_length < length)
                 {
                  CheckforE();
                  //logln("Current length : idle state  ");
                  //log1(actuator_length);
                  Actuator_Activate();
                  Actuator_Read();
                 }*/
            }
            else
            {
                while (actuator_length > length )
                {
                 //logln("Current length :  ");
                 // log1(actuator_length); 
                 CheckforE();
                 Actuator_Deactivate(); 
                 Actuator_Read(); 
                }
            }
            digitalWrite(actuator_enable, LOW);
}
            
/*
//LOOP --DELETE after testing
void loop ()
{ char c;
  if(Serial.available() > 0)
  {c=Serial.read();
   if (c == 'a')
    {Actuator_Activate();
    // delay(2500);
    log1('\n');
   // log1(c);
    log1("Eject");
    log1("After activation ");
    Actuator_Read();
    }
  
   
  if (c == 'e')
  {Actuator_Deactivate();
  log1('\n');
    //log1(c);
    log1("Retract");
 //     delay(2500);
    log1('\n');
  log1("After de-activation ");
 Actuator_Read();
   }
 
  }
  
//  Serial.write(1);
 // Serial.write("DONE");
  
}
*/
