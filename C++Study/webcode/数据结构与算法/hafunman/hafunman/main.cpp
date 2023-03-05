#include <iostream>
#include "han.h"
#include "Status.h"
using namespace std;


int main()
{
	HuffmanTree H;
	int n;
	n = 8;
	createmanTree(H, n);
	bianma(H, n);
	return 0;
}
