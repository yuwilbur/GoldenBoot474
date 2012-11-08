/*This code determines the serial communication
*/
void serialEvent(){
        CheckforE();
}

void CheckforE(){
        if(Serial.available() > 0){
         
           if( Serial.peek() == 'E'){
                
                 while(Serial.available()){
                   Serial.read();                   
                 }
                 state = 0;
                 enc1_Count=0;
                 enc2_Count=0;
                 Reset();
                 poslist =0;
                 poslistFlag = 1;
                 path.clear();
                 _path.clear();
                 Serial.write('1');
           }
        }
}

void ReadInput(){
                
                enc1_Count =0;
                enc2_Count =0;
                //Reset();
                
                if(Serial.peek() == 'G'){
                        Serial.println("Grabbing the ball ");
                        while(Serial.available()){
		                Serial.read();
			}
                        CatchtheBall();
                }
                          
                 else if(Serial.peek() == 'K'){
                        Serial.println("Kicking the ball ");
                        while(Serial.available()){
		                Serial.read();
			}
                        KicktheBall();
                }
                
		else if(Serial.peek() == 'R'){
			state = MOVE;
			while(Serial.available()){
				Serial.read();
			}

			Serial.println("hello");
			Serial.println( _path[0][0]);
			Serial.println( _path[0][1]);
			Serial.println( _path[1][0]);
			Serial.println( _path[1][1]);
			Serial.println(_path.size());
		}

                else if (Serial.peek() == 'I'){
                        Serial.println("Reading the input values ");
                        while(Serial.available()){
		                Serial.read();
			}

		if((Serial.available() == 5) && (input2done == 1 )){
			char bytes1[6];
			bytes1[0] = Serial.read();  
			bytes1[1] = Serial.read();
			bytes1[2] = Serial.read();
			bytes1[3] = Serial.read();
			bytes1[4] = Serial.read();
                        bytes1[5] = '\0';
                         CheckGarbbage(bytes1);
			pos_1 = atoi(bytes1);
			path.clear();
			path.push_back(pos_1);
			//abspos_1 = abs(pos_1-8);

			Serial.print('\n');
			Serial.print(enc1_Count);
			Serial.print('\t');
			Serial.print(enc2_Count);
			Serial.print('\n');

			Serial.print("pos_1 = ");
			Serial.print(pos_1, DEC);
			Serial.println();
			input1done =1;
			input2done=0;
			//    enc1_Count = 0;
			//    enc2_Count = 0;
		}
		if((Serial.available() == 5) && (input1done == 1)){
			char bytes2[6];
			bytes2[0] = Serial.read();  
			bytes2[1] = Serial.read();
			bytes2[2] = Serial.read();
			bytes2[3] = Serial.read();
			bytes2[4] = Serial.read();
			bytes2[5] = '\0';
                         CheckGarbbage(bytes2);
			pos_2 = atoi(bytes2);
			path.push_back(pos_2);
			_path.push_back(path);
			//abspos_2 = abs(pos_2-8);
			Serial.print("pos_2 = ");
			Serial.print(pos_2, DEC);
			//  Serial.print(path[0]);
			//  Serial.print(path[1]);
			Serial.println();
			//state = 1;
			input1done = 0;
			input2done = 1;
			Serial.print(state,DEC );
			Serial.println();
		}   
	}  

         else 
          Reset();
}

void CheckGarbbage(char value[6])
{int i; 
   for(i=0; i<5; ++i)
    {
      if (
          (value[i] == 0) ||
          (value[i] == 1) ||
          (value[i] == 2) ||
          (value[i] == 3) ||
          (value[i] == 4) ||
          (value[i] == 5) ||
          (value[i] == 6) ||
          (value[i] == 7) ||
          (value[i] == 8) ||
          (value[i] == 9) ||
          (value[i] == '-') 
          )
           {}
        else
         Reset(); 
      
    }
}
