#include "imageRender.hpp"
#include "speedDecider.hpp"
int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
    while(1){
		setMotorCore(renderImageCore());  
        usleep(10000);
  } //while

} // main
