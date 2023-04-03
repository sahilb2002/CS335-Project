public class test_16 {
    float add(int a, float b){
        return a+b;
    }
    void main(){
        int a=10;
        float b = 10.6;
        
        float c = a+b;

        int k = c>0?1:0;

        System.out.println(c);
        float d = add(a, k);
        return;
    }
}
