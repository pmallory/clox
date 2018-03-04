#include "chunk.h"
#include "common.h"
#include "debug.h"

int main(int argc, const char* argv[]) {
	//Supress gcc warnings
	(void)argc;
	(void)argv;

	Chunk chunk;
	initChunk(&chunk);

    int constant = addConstant(&chunk, 43.42);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);

	writeChunk(&chunk, OP_RETURN, 1);
	disassembleChunk(&chunk, "test chunk");
	freeChunk(&chunk);
	return 0;
}
