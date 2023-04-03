public class test15 {  // error: array index is not integer
    int foo(){
        // no return statement gives warning.
        int a;
    }
    int main(){
        int arr[] = new int[10];
        arr[1.1] = 0;
    }
}