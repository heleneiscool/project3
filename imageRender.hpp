#include "robot.hpp"

int* renderImageCore(){

	takePicture();

    SavePPMFile("i0.ppm",cameraView);

    int imageSize = cameraView.height * cameraView.width;

	int*  pixels = new int[imageSize]; 
//scan horizontal array and then divide all by 2 and if pix > 200 then its white and then change motor speed. if n of array is >200 on right side then lower speed vRight

	
	OpenPPMFile("i0.ppm", cameraView);
    // for pixel in image

		//get the pixel:
		int curPix; //current pixel get_pixel( ImagePPM image,int row,int col, int color)
		for(int col = 0; col < cameraView.width; col++){
			for(int row = 0; row < cameraView.height; row++){
				curPix = get_pixel(cameraView, row, col, 3);
				if(curPix > 200) {
					pixels[row*col] = 1;
				}else {
					pixels[row*col] = 0;
				}	
				
			}
		}
		std::cout<<pixels<<endl;

		//if white put 1 in the array at the index of that pixel

		//otherwise put 0 in that index

	//should return the list of 1s and 0s

	return pixels;

}
