CC = gcc
dirLibs = libs/
OBJECTS = $(shell find libs -name '*.o')

all: errorHandler.o customersHandler.o archiveHandler.o banker

banker:  main.c 
	
	$(CC) $< -o $@ $(OBJECTS)

customersHandler.o: $(dirLibs)customer/customersHandler.c

	$(CC) -c $< -o $(dirLibs)customer/$@

archiveHandler.o: $(dirLibs)archiveHandler/archiveHandler.c

	$(CC) -c $< -o $(dirLibs)archiveHandler/$@

errorHandler.o: $(dirLibs)errorHandler/errorHandler.c

	$(CC) -c $< -o $(dirLibs)errorHandler/$@

.PHONY: clean

clean:	
	find libs -name '*.o' -type f -delete 
	rm banker	