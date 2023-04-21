public class test_13 { //static error
    int c;
    public static int add(int a, int b){
        c = 0;
        return a+b;
    }

    public static void main(String args[]){
        int a=7;
        int b=10;
        static int c = add(a, b);
        return;
    }
    
}
