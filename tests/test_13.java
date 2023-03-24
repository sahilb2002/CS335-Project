public class test_13 { //static error
    public static int add(int a, int b){
        return a+b;
    }

    public void main(){
        int a=7;
        int b=10;
        static int c = add(a, b)
        return;
    }
    
}
