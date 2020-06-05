#include "robot.hpp"
int* renderImageCore(){
	takePicture();
    SavePPMFile("i0.ppm",cameraView);
    int imageSize = cameraView.height * cameraView.width;
	int  pixels[imageSize]; //note: i reliase that there is a better way to set a list length to the value of a varible but i cant remeber it, so please do update this
	
    // for pixel in image
		//get the pixel:
		//if white put 1 in the array at the index of that pixel
		//otherwise put 0 in that index
	//should return the list of 1s and 0s
	return pixels;
}
