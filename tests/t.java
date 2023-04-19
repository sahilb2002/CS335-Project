public class A{
    public int a;
}
public class B{
    int func(){
        int a = 2;
        int b = 1;
        int c = b+a;
        // int d = (b+1)*c + (a/b)%23 + a;
        int e = (a<b)>>6 & !(c<a);
    }
    // int func(){
    //     int a,b;
    //     a = (a+b) + ((a+b) + ((a+b) + ((a+b) + ((a+b) + ((a+b) + ((a+b) + ((a+b))))))));
    // }
    // int foo(int bc, int ab){
    //     return bc+ab;
    // }
    // int main(){
    //     A a = new A();
    //     return 0;
    // }
}