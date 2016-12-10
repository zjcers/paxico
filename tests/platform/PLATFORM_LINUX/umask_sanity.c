#include <sys/stat.h>
int main()
{
	return !(umask(0660) == 0660);
}
