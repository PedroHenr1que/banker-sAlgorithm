CC = gcc
dirLibs = libs/
OBJECTS = $(shell find Libs -name '*.o')

all: customersHandler.o banker

banker:  main.c 
	
	$(CC) $< -o $@ $(OBJECTS) -lpthread


customersHandler.o: $(dirLibs)customer/customersHandler.c

	$(CC) -c $< -o $(dirLibs)customer/$@

.PHONY: clean

clean:	
	find Libs -name '*.o' -type f -delete 
	rm banker