import IO;
public class MyBinarySearch {

    public int binarySearch(int inputArr[8], int len, int key) {
        int start = 0,mid;
        int end = len - 1;
        while (start <= end) {
            mid = (start + end) / 2;
            if (key == inputArr[mid]) {
                return mid;
            }
            if (key < inputArr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
}