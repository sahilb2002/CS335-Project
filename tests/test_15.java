public class test15 {  // error: variable a is already defined in method main(int)
    void main(){
        int a=10;
        long b=20;
        //int a = a+b;
        int c = a<b?a:b;
        for(int i=0; i<10; i++){
            int k = a+b;
        }
        return;
    }
}
