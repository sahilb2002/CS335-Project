// public class A{
//     int a;
//     void foo(int t){
//         a=t;
//     }
//     int red(){
//         return a;
//     }
// }
public class B{
    public int a;
    public static void main(String args[]) {

        int arr[1000];
        // int a2[10000];

        // B obj = new B();
        // obj.a = 1;
        for(int i=0;i<10;i++){
            arr[i] = i;
        }
        int a  =2;
        arr[4] = 4;
        arr[2] = 2;
        arr[3] = 3;
        arr[1] = 1;
        arr[0] = 1;

        // int t = arr[4]*arr[2]*arr[1]+arr[3]/arr[0];
        // // int t = arr[4];
        // System.out.println(t);
        System.out.println(arr[4]*arr[2]*arr[1]+arr[3]/arr[0]);

        // for(int i=0;i<999;i++){
        //     arr[i+1] = i+arr[i];
        // }
        // for(int i=0;i<1000;i++){
        //     System.out.println(arr[i]);
        // }
        // int t = arr[4];
        // System.out.println(t);

        return;
    }
}