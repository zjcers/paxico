#include <sys/stat.h>
int main()
{
	return !(umask(02) == 02);
}
