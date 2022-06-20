void writeAlloc(int customerToApplyCommand, int numberOfResources, int commandValues[]);
void writeDeniedUnSt(int customerToApplyCommand, int numberOfResources, int commandValues[]);
void writeNotEnoughRes(int customerToApplyCommand, int numberOfResources, int commandValues[], int availableResources[]);
void writeExceedMaxAllocation(int customerToApplyCommand, int numberOfResources, int commandValues[]);
void writeRelease(int customerToApplyCommand, int numberOfResources, int commandValues[]);
void printTable(int numberOfResources, int numberOfCustomers, int **maxResourcesOfCustomers, int **allocatedResources, int **need, int *availableResources);
void writeDenniedRelease(int customerToApplyCommand, int numberOfResources, int commandValues[]);