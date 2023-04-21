public class B{
    public static int Fib(int n){
        if(n<=1){
            return n;
        }
        else{
            return Fib(n-1) + Fib(n-2);
        }
    }

    public static void main(String args[]) {
        int n=0;
        
        System.out.println(Fib(n));
        return;
    }
}