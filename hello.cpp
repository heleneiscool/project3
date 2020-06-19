#include "robot.hpp"
/*****Line reading, values for lines from image*****/
struct LineReading{
	double leftLine=0;
	double leftPosition=0;
	double rightLine=0;
	double rightPosition=0;
	double topLine=0;
	double topPosition=0;
	double bottomLine=0;
	double bottomPosition=0;
};

LineReading renderImageCompletion(){
	LineReading reading;
			for(int row=0; row<cameraView.height; row++){
				for(int col=0; col<cameraView.width; col++){
					int brightness = get_pixel(cameraView, row, col, 3);
					bool isWhite = brightness>=250; //includes black so that the car hits the flag in the end
					if(isWhite){
					if(col == 0){                                
						reading.leftPosition += row;
						reading.leftLine++;
					}
					else if(col == cameraView.width-1){
						
				 reading.rightPosition += row;
				 reading.rightLine++;
					}
					if(row == 0){
						
					reading.topPosition += col;
				 reading.topLine++;
						}
						else if(row==cameraView.height-1){
							
							reading.bottomPosition += col;
							reading.bottomLine++;
						}
				}
				}
			}
	return reading;
}

void renderImageChallenge(){
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
	int checkRow = 80;
	int redRow = 0;
	for(int col=0; col<cameraView.width; col++){
		int redness = get_pixel(cameraView, redRow, col, 0);
			int nonRed = (get_pixel(cameraView, redRow, col, 1)+get_pixel(cameraView, redRow, col, 2))/2;
			if(redness>nonRed*1.05){
				redRow++;
			}
			else{
				break;
			}
	}

	int leftSide=0;
	bool checking = true;
	for(int col=0; col<cameraView.width & checking; col++){
	for(int row=0; row<cameraView.height; row++){
		
		int redness = get_pixel(cameraView, row, col, 0);
			int nonRed = (get_pixel(cameraView, row, col, 1)+get_pixel(cameraView, row, col, 2))/2;
			if(redness>nonRed*1.05){
				leftSide++;
			}
			else{
				checking = false;
				break;
			}
	}
}
int rightSide=0;

checking = true;
	for(int col=cameraView.width-1; col>0 & checking; col--){
	for(int row=0; row<cameraView.height; row++){
		
		int redness = get_pixel(cameraView, row, col, 0);
			int nonRed = (get_pixel(cameraView, row, col, 1)+get_pixel(cameraView, row, col, 2))/2;
			if(redness>nonRed*1.05){
				rightSide++;
			}
			else{
				checking=false;
				break;
			}
	}
}
	if(redRow>cameraView.width*0.8){
		setMotors(60,20); 
	}
	else if(rightSide==0){
		setMotors(60,20);
	}
	else{
		int difference = leftSide-rightSide;
		setMotors(40+difference, 40-difference);
	}
	int checkRight = cameraView.width-1;
}
}
