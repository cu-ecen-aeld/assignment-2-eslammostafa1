TARGET := writer.c
OUTPUT := writer
OUTPUT_CROSS := writer_cross

all: 
	gcc ${TARGET} -o ${OUTPUT} 

cross:
	aarch64-none-linux-gnu-gcc ${TARGET} -o ${OUTPUT_CROSS}

run:
	./${OUTPUT} $(ARGS)

clean:
	rm -f ${OUTPUT} 
	rm -f ${OUTPUT_CROSS} 