#include <stdio.h>
#include <stdlib.h>

#define random \
    (rand()%50)

void _swapRows(int *row1, int *row2, int size){
    int *el1=row1;
    int *el2=row2;
    for(int i=0; i<size; i++){
        int temp = *el2;
        *el2 = *el1;
        *el1 = temp;
        el1++;
        el2++;
    }
}

void _swapColumns(int *col1, int *col2, int size){
    int *el1=col1;
    int *el2=col2;
    for(int i=0; i<size; i++){
        int temp = *el2;
        *el2 = *el1;
        *el1 = temp;
        el1+=size;
        el2+=size;
    }
}

void printArray(int *arr, int size){
    for(int i=1; i<=size*size; i++){
        printf("%d\t", arr[i-1]);
    	if(i%size == 0){
            printf("\n");
        }
    }
}

void check_sequence(int *arr, int size){
    int prev_el = *(arr+size-1);
    for(int k=size-1; k>=0; k--){
        if(*(arr+k+k*size)>prev_el){
            printf("Sequence is not decreasing.\n");
            return;
        }
    }
    printf("Sequence is decreasing.\n");
}

int main(){
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    int array[size*size];

    for(int i=0; i<size*size; i++){
        array[i] = random;
    }
    printf("\n\n");
    printArray(array, size);
    
    for(int max_rows=1; max_rows<=size; max_rows++){
        int largest = 0;
        int r=size-1, c=0;
   	    for(int i=0; i<=size-max_rows; i++){
	        for(int j=max_rows-1; j<size; j++){
	            if(*(array+i+j*size)>largest){
	                largest=*(array+i+j*size);
	                c=i;
	                r=j;
	            }
	        }
	    }
		printf("\nLargest = %d, row = %d, col = %d max = %d\n", largest, r, c, max_rows); 

		_swapRows((array+r*size), (array+(max_rows-1)*size), size);
		_swapColumns((array+c), (array+(size-max_rows)), size);
		printArray(array, size);   
 	}
 	
 	printf("\n");
 	check_sequence(array, size);
 	scanf("%d", &size);
}
