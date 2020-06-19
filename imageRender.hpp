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

struct RedLines{
	int redRow=0;
	int leftSide=0;
	int rightSide=0;
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

RedLines renderImageChallenge(){
	int checkRow = 70; //the row which is checked
	int redRow = 0; //varible stores the size of red line
	/* for each col, check if the 'checkrow' row is red. if so, start counting/increase the number of red pixels in that row */
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

	int leftSide=0; //size of left red border
	bool checking = false; //when true, the border has been found
	/* for columns from  */
	for(int col=0; col<cameraView.width; col++){
	for(int row=0; row<cameraView.height; row++){
		
		int redness = get_pixel(cameraView, row, col, 0);
			int nonRed = (get_pixel(cameraView, row, col, 1)+get_pixel(cameraView, row, col, 2))/2;
			if(redness>nonRed*1.05 & !checking){
				checking = true;
			}
			if(redness>nonRed*1.05 & checking){
				leftSide++;
			}
			else{
				checking = false;
				break;
			}
	}
}
int rightSide=0;

checking = false;
	for(int col=cameraView.width-1; col>0; col--){
	for(int row=0; row<cameraView.height; row++){
		
		int redness = get_pixel(cameraView, row, col, 0);
			int nonRed = (get_pixel(cameraView, row, col, 1)+get_pixel(cameraView, row, col, 2))/2;
			if(redness>nonRed*1.05 & !checking){
				checking =true;
			}
			if(redness>nonRed*1.05 & checking){
				rightSide++;
			}
			else{
				checking=false;
				break;
			}
	}
}

	std::cout<<"left"<<leftSide<<" right="<<rightSide<<" redrow="<<redRow<<std::endl;
	int checkRight = cameraView.width-1;
	RedLines lines;
	lines.redRow = redRow;
	lines.rightSide = rightSide;
	lines.leftSide = leftSide;
	return lines;

}
