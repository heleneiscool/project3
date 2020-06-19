void setMotorCompletion(LineReading reading){
		
		double vLeft = 40.0;
		double vRight = 40.0;
		const double v_go = 40.0;
		const double kp = 1; //how far the error is from the error line, the constant turning SCALE 
        double dv = 0;
        double delta = 20;
        if(reading.rightLine>0){
			//go right if there is a line to the right
			 double row = reading.rightPosition/reading.rightLine;
			 delta = (row/cameraView.height)*(15);
			vLeft = vLeft + 5+delta;
			 vRight = vRight- 5-delta;
			}
		else if(reading.topLine==0 && reading.bottomLine>0 && reading.leftLine==0){
			vLeft=-40;
			vRight =0;
		
		}
         else if(reading.topLine>0){
			 //go foward if no line to the right but there is one foward
			 double col = reading.topPosition/reading.topLine;
			 double difference = cameraView.width/2 - col;
			 double delta = 30*(difference/cameraView.width);
			 vLeft -= delta;
			 vRight += delta;
		 }
		 else if(reading.leftLine>0){
			 //go left if there is no line ahead or to right
			 double row = reading.leftPosition/reading.leftLine;
			 delta = (row/cameraView.height)*15;
			vLeft = vLeft - 5-delta;
			 vRight = vRight+ 5+delta;
			}
		else{
			vLeft =-40;
			vRight =-40;
		}		

    std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;

	setMotors(vLeft,vRight);   
     //usleep(10000);
     std::cout<<std::endl<<"left:"<<reading.leftPosition/(1+reading.leftLine)<<" right:"<<reading.rightPosition/(1+reading.rightLine)<<" top:"<<reading.topPosition/(1+reading.topLine)<<" bottom:"<<reading.bottomPosition/(1+reading.bottomLine)<<std::endl;    // Prints the average

}

void setMotorChallenge(RedLines border){
	LineReading checkIfWhite = renderImageCompletion();
	if(checkIfWhite.topLine>0){
		//go foward if no line to the right but there is one foward
		double col = checkIfWhite.topPosition/checkIfWhite.topLine;
		double difference = cameraView.width/2 - col;
		double delta = 30*(difference/cameraView.width);
		double vLeft =40- delta;
		double vRight =40+ delta;
		setMotors(vLeft,vRight);  
	}
	else{
		if(border.redRow>cameraView.width*0.8){
		setMotors(50,10); 
	}
	else if(border.rightSide==0){
		setMotors(60,20);
	}
	else{
		int difference = border.leftSide-border.rightSide;
		setMotors(40, 40);
	}
}
}
