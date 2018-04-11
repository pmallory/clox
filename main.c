#include "chunk.h"
#include "common.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char* argv[]) {
	//Supress gcc warnings
	(void)argc;
	(void)argv;

    initVM();

	Chunk chunk;
	initChunk(&chunk);

    int constant = addConstant(&chunk, 43.42);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant, 1);
    int constant2 = addConstant(&chunk, 7);
    writeChunk(&chunk, OP_CONSTANT, 1);
    writeChunk(&chunk, constant2, 1);


  writeChunk(&chunk, OP_ADD, 123);

  constant = addConstant(&chunk, 5.6);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, constant, 123);

  writeChunk(&chunk, OP_DIVIDE, 123);

    writeChunk(&chunk, OP_NEGATE, 1);

    writeChunk(&chunk, OP_ADD, 1);

	writeChunk(&chunk, OP_RETURN, 1);
	//disassembleChunk(&chunk, "test chunk");

    interpret(&chunk);

    freeVM();
	freeChunk(&chunk);
	return 0;
}
