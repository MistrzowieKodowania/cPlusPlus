#include "image.h" // do��czam bibliotek� i klas� image

int main()
{	
	Image* image = new Image("lena.bmp");
	image->to_gray(AVERAGE); // zamiana obrazka na monochromatyczny
	image->print("lena-gray.bmp");  // zapisanie na dysku
	
	delete image;
	return 0;
}
