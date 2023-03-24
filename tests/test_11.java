public class BubbleSortExample {  
    void bubbleSort(int arr[], int n) {  
        int temp = 0;  
         for(int i=0; i < n; i++){  
                 for(int j=1; j < (n-i); j++){  
                          if(arr[j-1] > arr[j]){  
                                 //swap elements  
                                 temp = arr[j-1];  
                                 arr[j-1] = arr[j];  
                                 arr[j] = temp;  
                         }  
                          
                 }  
         }  
         return;
    }  
    public void main(String args[]) {  
                int arr[] ={3,60,35,2,45,320,5};  
                int n = 7;
                System.out.println("Array Before Bubble Sort");  
                for(int i=0; i < n; i++){  
                        System.out.println(arr[i] + " ");  
                }  
                System.out.println("");  
                  
                bubbleSort(arr, n);//sorting array elements using bubble sort  
                 
                System.out.println("Array After Bubble Sort");  
                for(int i=0; i < n; i++){  
                        System.out.println(arr[i] + " ");  
                }  
   
        }  
}  