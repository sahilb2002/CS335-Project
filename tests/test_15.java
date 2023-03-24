public class test15 {  // error: variable a is already defined in method main(int)
    void main(){
        int a=10;
        int b=20;
        int a = a+b;
        return;
    }
}
