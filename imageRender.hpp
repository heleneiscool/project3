#include "robot.hpp"
int** renderImageCore(){ //2 asterix to return 2d array
	takePicture();
    SavePPMFile("i0.ppm",cameraView);
    int imageSize = cameraView.height * cameraView.width; //array that holds arrays
	int  pixels[cameraView.height][cameraView.width]; //note: i reliase that there is a better way to set a list length to the value of a varible but i cant remeber it, so please do update this
	
	OpenPPMFile("i0.ppm");
    // for pixel in image 
		//get the pixel:
	Pixel curPix; // current pixel
	for(int col = 0; col < cameraView.width; col ++){
	for ( int row = 0; row < camera.View.height; row++){
		curPix = get_pixel(row, col, 3); //will get the 3 values of rgb
		if(curPix > 200) //if its basically white
		pixels[row][col]= 1; // will go through entire image one pixel at a time, put value in curpix
		else 
			pixels[row][col]= 0;
		       
		
	}
	}
		//if white put 1 in the array at the index of that pixel
		//otherwise put 0 in that index
	//should return the list of 1s and 0s
	return pixels;
}
