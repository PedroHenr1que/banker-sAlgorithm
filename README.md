# Bankers Algorithm
> This is a project for a college subject, Software Infrastructure (Operating System).

> This is the proposed implementation of the book Operating System Concepts, P-45. It was implemented in C and have some modifications proposed by the professor, the NUMBER_OF_CUSTOMERS and the NUMBER_OF_RESOURCES are not fixed. The NUMBER_OF_CUSTOMERS is the amount of lines in the customer.txt, that also have the maximum amount of resources for each customer, the NUMBER_OF_RESOURCES is defined by how many numbers are passed through command line, that also will be the amount of each resource. Another modification is that the commands are read from a file, the commands.txt.


## Observations
- It was implemented on **MacOs**;
- Its was tested in MacOs and Linux.
- It was implemented in multiple archives, we will take a look at each one of them.
<br/>

## archiveHandler.c
It contains multiple functions to write in the file that have the result of the program, the name of the archive outputted it result.txt.
<br/>

## customerHandler.c
Its has two functions, "getNumberOfCustomers()" that is responsible for get the number os customers, and "getMaximumDemandResources()" that has the purpose to get the maximum demanded resources for each customer.
<br/>

## main.c
Here contains all the logic for the Banker's Algorithm.