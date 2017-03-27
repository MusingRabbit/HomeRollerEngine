#include <iostream>
#include "Launcher.h"

using namespace std;

int main(int argc, char* args[]) {
	Engine::Launcher runtime;

	runtime.Initialise("Test Display", 800, 600);
	runtime.Start();

	return 0;
}