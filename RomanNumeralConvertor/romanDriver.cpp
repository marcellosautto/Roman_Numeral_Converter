#include "roman.h"

int main()
{
	roman *romanConv = new roman(); //create pointer to roman class
	while (romanConv->mainLoop()) //while mainLoop returns true, create a new instance of the roman class
		romanConv = new roman();

}