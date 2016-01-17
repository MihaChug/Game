#include "app.h"
#include <memory>

int main()
{
	unique_ptr<App> app = make_unique<App>();
	return 0;
}