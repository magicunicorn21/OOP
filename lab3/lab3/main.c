#include "UI.h"

int main(int argc, char* argv[]) {
	magicStock stock = createMagicStock();
	RuneCaller runeCaller = createRuneCaller(&stock);
	RuneView runeView = createRuneView(&runeCaller);
	runRune(&runeView);
}