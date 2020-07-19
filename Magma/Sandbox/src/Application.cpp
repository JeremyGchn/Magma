#include <stdlib.h>

namespace Magma {

	__declspec(dllimport) void Print();

}

void main() {

	Magma::Print();
	system("pause");
}