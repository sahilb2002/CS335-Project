public class test{
    int foo(int a){
        if(a==0)
        return 1;
        return a+foo(a-1);
    }
    public void main(){
        int a = foo(2);
        for(int i=0;i<10;i++){
            a = a+1;
            System.out.println(a);
        }
    }
}