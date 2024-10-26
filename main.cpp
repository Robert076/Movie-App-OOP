#include "Tests.hpp"
#include <crtdbg.h>

int main()
{
	Tests tests;
	tests.testTutorial();
	tests.testDynamicArray();
	tests.testRepository();
	tests.testServices();
	UI ui;
	ui.run();
	_CrtDumpMemoryLeaks();
	return 0;
}