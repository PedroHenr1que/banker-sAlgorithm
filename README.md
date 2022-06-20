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
<br/>

## customerHandler.c
Its has two functions, "getNumberOfCustomers()" that is responsible for get the number os customers, and "getMaximumDemandResources()" that has the purpose to get the maximum demanded resources for each customer.
<br/>
<br/>

## errorHandler.c
This archive has functions to verify if all the files necessary for the program execution are in the right format, if they exists and can be open.
<br/>
<br/>

## main.c
Here contains all the logic for the Banker's Algorithm.
<br/>
<br/>

## How to download, compile and run the program.
1. **Downlaod**
```bash
        $ git clone https://github.com/PedroHenr1que/banker-sAlgorithm.git
        $ cd banker-sAlgorithm
```
<br/>

2. **Complie**

```bash
        $ make
```
It's going to generate a executable called "banker".
<br/>
<br/>

3. **Run**

The format to execute the program is the one below:
```
        ./banker X Y ... n
```
> (X Y ... n) are the resources and how many of each of them.

> note that you are passing the resources through command line, so it's possible to pass how many you want, the number will be amount of each resource the system will have.

> In the end of the program you should see a file, result.txt, that is the result of the program.

* Example, to pass 3 resources with the amount of 10 5 7 respectively:
```
        ./banker 10 5 7
```

* **Obs:**

The files commands.txt and customer.txt must have the same amount of resources that are being passed through the command line.
<br/>
<br/>

## How to clean the compiled archives
Just run the following command.
```bash
        $ make clean
```
