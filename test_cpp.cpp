#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

#include "Card.h"

using namespace std;

int main(){
	card c;
	c.initialise(10, 'K', 'H');
	c.display();
	return 0;
}