#include "methods.h"

int main(int argc, char** argv)
{
	char* read_file_path = argv[1];
	char* write_file_path = argv[2];
	
	FILE* fp;
	fp = fopen(read_file_path, "r");
	FILE* fw;
	fw = fopen(write_file_path, "at+");

	analyzer(fp, fw);

	return 0;
}