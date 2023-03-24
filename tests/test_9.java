public class Final{ //error: cannot assign a value to final variable a
    void main(){
        final int a = 10;

        int b=10;
        int c = a+b;
        a = b+c;
        return;
    }
}