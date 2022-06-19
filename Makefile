CC = gcc
dirLibs = libs/
OBJECTS = $(shell find Libs -name '*.o')

all: customersHandler.o archiveHandler.o banker

banker:  main.c 
	
	$(CC) $< -o $@ $(OBJECTS)

customersHandler.o: $(dirLibs)customer/customersHandler.c

	$(CC) -c $< -o $(dirLibs)customer/$@

archiveHandler.o: $(dirLibs)archiveHandler/archiveHandler.c

	$(CC) -c $< -o $(dirLibs)archiveHandler/$@


.PHONY: clean

clean:	
	find Libs -name '*.o' -type f -delete 
	rm banker